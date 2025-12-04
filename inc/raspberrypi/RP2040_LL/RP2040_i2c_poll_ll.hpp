/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_i2c_poll_ll.hpp
 * @brief Polled low level interface for the RP2040 I2C interface
 */
#ifndef RP2040_I2C_POLL_LL_HPP
#define RP2040_I2C_POLL_LL_HPP

namespace libmcull::i2c {
namespace hardware = libmcuhw::i2c;
/**
 * @brief I2C speed modes
 */
enum class I2cModes : std::uint32_t {
  Standard = hardware::IC_CON::SPEED_STD,
  Fast = hardware::IC_CON::SPEED_FAST,
  High = hardware::IC_CON::SPEED_HIGH,
};
/**
 * @brief
 * @tparam i2c_address
 */
template <libmcu::I2cBaseAddress const& i2c_address>
struct I2cPolled : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief setup I2C to master mode
   * Taken from raspberry Pi Pico SDK and adapted
   * @param mode speed mode
   * @param bitRate wanted bitrate
   * @return actual bitrate
   */
  constexpr std::uint32_t Setup(I2cModes mode, std::uint32_t bitRate) {
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ABORT;
    GetPeripheral()->IC_CON = hardware::IC_CON::MASTER_MODE | static_cast<std::uint32_t>(mode) | hardware::IC_CON::IC_RESTART_EN |
                              hardware::IC_CON::IC_SLAVE_DISABLE | hardware::IC_CON::TX_EMTPY_CTRL;
    GetPeripheral()->IC_TX_TL = 0;  // set watermarks to 1 to simplify handling
    GetPeripheral()->IC_RX_TL = 0;  // set watermarks to 1 to simplify handling
    GetPeripheral()->IC_DMA_CR = hardware::IC_DMA_CR::RDMAE | hardware::IC_DMA_CR::TDMAE;  // enable DMA, harmless without DMA

    // set baudrate, taken from pico SDK
    std::uint32_t frequencyInput = FREQ_PERI;
    // TODO there are some subtleties to I2C timing which we are completely ignoring here
    std::uint32_t period = (frequencyInput + bitRate / 2) / bitRate;
    std::uint32_t lcnt = period * 3 / 5;
    std::uint32_t hcnt = period - lcnt;

    // Per I2C-bus specification a device in standard or fast mode must
    // internally provide a hold time of at least 300ns for the SDA signal to
    // bridge the undefined region of the falling edge of SCL. A smaller hold
    // time of 120ns is used for fast mode plus.
    uint32_t sdaTxHoldCount;
    if (bitRate < 1000000) {
      // sdaTxHoldCount = frequencyInput [cycles/s] * 300ns * (1s / 1e9ns)
      // Reduce 300/1e9 to 3/1e7 to avoid numbers that don't fit in uint.
      // Add 1 to avoid division truncation.
      sdaTxHoldCount = ((frequencyInput * 3) / 10000000) + 1;
    } else {
      // sdaTxHoldCount = frequencyInput [cycles/s] * 120ns * (1s / 1e9ns)
      // Reduce 120/1e9 to 3/25e6 to avoid numbers that don't fit in uint.
      // Add 1 to avoid division truncation.
      sdaTxHoldCount = ((frequencyInput * 3) / 25000000) + 1;
    }

    // Always use "fast" mode (<= 400 kHz, works fine for standard mode too)
    GetPeripheral()->IC_FS_SCL_HCNT = hcnt;
    GetPeripheral()->IC_FS_SCL_LCNT = lcnt;
    GetPeripheral()->IC_FS_SPKLEN = lcnt < 16 ? 1 : lcnt / 16;

    GetPeripheral()->IC_SDA_HOLD = (GetPeripheral()->IC_SDA_HOLD & ~hardware::IC_SDA_HOLD::IC_SDA_TX_HOLD_MASK) |
                                   hardware::IC_SDA_HOLD::IC_SDA_TX_HOLD(sdaTxHoldCount);

    // enable
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ENABLE;
    return frequencyInput / period;
  }
  // TODO setup slave with slave address
  /**
   * @brief Write data to I2C device
   * @param address I2C device to write to
   * @param transmitBuffer data to send, should at least contain one byte!
   * @param maxTime maximum amount of iterations to wait between each I2C operation
   */
  constexpr libmcu::Results Write(libmcu::I2cDeviceAddress address, std::span<const std::uint8_t> transmitBuffer,
                                  std::uint32_t maxTime) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value);
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ABORT;
    GetPeripheral()->IC_TAR = i2cAddress;
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ENABLE;
    // write data in loop to DATA_CMD
    std::size_t index = 0;
    std::uint32_t timeout;
    std::uint32_t abortReason;
    for (; index < transmitBuffer.size(); index++) {
      if (index == transmitBuffer.size() - 1)  // special handling for last byte
        GetPeripheral()->IC_DATA_CMD = transmitBuffer[index] | hardware::IC_DATA_CMD::STOP;
      else
        GetPeripheral()->IC_DATA_CMD = transmitBuffer[index];
      // loop until timeout/abort/completed
      timeout = maxTime;
      do {
        abortReason = GetPeripheral()->IC_TX_ABRT_SOURCE;
        if (GetPeripheral()->IC_CLR_TX_ABRT)
          goto abort;
        if (!timeout--)
          goto timeout;
      } while (!(GetPeripheral()->IC_RAW_INTR_STAT & hardware::IC_RAW_INTR_STAT::TX_EMPTY));
    }
    return libmcu::Results::Done;
  // error handling
  timeout:
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ABORT;
    return libmcu::Results::Timeout;
  abort:
    // TODO change TX abort handling to be more like RX abort
    libmcu::Results result{libmcu::Results::Error};
    if (abortReason & hardware::IC_TX_ABRT_SOURCE::ABRT_7B_ADDR_NOACK)
      result = libmcu::Results::InvalidAddress;
    else if (abortReason & hardware::IC_TX_ABRT_SOURCE::ABRT_TXDATA_NOACK)
      result = libmcu::Results::TransferError;
    return result;
  }
  /**
   * @brief Read data from I2C device
   * abort handling is a bit different from transmit as it seems that some abort reasons are slower when readingc
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  constexpr libmcu::Results Read(libmcu::I2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer, std::uint32_t maxTime) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value);
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ABORT;
    GetPeripheral()->IC_TAR = i2cAddress;
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ENABLE;
    // read data in loop to DATA_CMD
    std::size_t index = 0;
    std::uint32_t timeout;
    std::uint32_t abortReason;
    for (; index < receiveBuffer.size(); index++) {
      if (index == receiveBuffer.size() - 1)  // special handling for last byte
        GetPeripheral()->IC_DATA_CMD = hardware::IC_DATA_CMD::STOP | hardware::IC_DATA_CMD::CMD_READ;
      else
        GetPeripheral()->IC_DATA_CMD = hardware::IC_DATA_CMD::CMD_READ;
      // loop until timeout/abort/completed
      timeout = maxTime;
      do {
        abortReason = GetPeripheral()->IC_TX_ABRT_SOURCE;
        // we check TX abort flag instead of tx abort register, otherwise we miss some tx abort reasons
        if (GetPeripheral()->IC_RAW_INTR_STAT & hardware::IC_RAW_INTR_STAT::TX_ABRT)
          goto abort;
        if (!timeout--)
          goto timeout;
      } while (!GetPeripheral()->IC_RXFLR);
      receiveBuffer[index] = GetPeripheral()->IC_DATA_CMD;
    }
    return libmcu::Results::Done;
  // error handling
  timeout:
    GetPeripheral()->IC_ENABLE = hardware::IC_ENABLE::ABORT;
    return libmcu::Results::Timeout;
  abort:
    libmcu::Results result{libmcu::Results::Error};
    if (abortReason & hardware::IC_TX_ABRT_SOURCE::ABRT_7B_ADDR_NOACK)
      result = libmcu::Results::InvalidAddress;
    GetPeripheral()->IC_CLR_TX_ABRT;
    return result;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hardware::I2c* GetPeripheral() {
    return reinterpret_cast<hardware::I2c*>(i2cAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::I2c* GetPeripheralSet() {
    return reinterpret_cast<hardware::I2c*>(i2cAddress + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::I2c* GetPeripheralClear() {
    return reinterpret_cast<hardware::I2c*>(i2cAddress + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::I2c* GetPeripheralXor() {
    return reinterpret_cast<hardware::I2c*>(i2cAddress + libmcuhw::PeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType i2cAddress = i2c_address; /*!< peripheral address */
};
}  // namespace libmcull::i2c
#endif