/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 I2C software interface
 */
#ifndef RP2040_I2C_SW_HPP
#define RP2040_I2C_SW_HPP

namespace libMcuLL::sw::i2c {
using namespace libMcuLL::hw::i2c;
/**
 * @brief I2C speed modes
 */
enum class i2cModes : std::uint32_t {
  STANDARD = hw::i2c::IC_CON::SPEED_STD,
  FAST = hw::i2c::IC_CON::SPEED_FAST,
  HIGH = hw::i2c::IC_CON::SPEED_HIGH,
};
template <libMcuLL::i2cBaseAddress const& i2cAddress_>
struct i2c : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}

  /**
   * @brief setup I2C to master mode
   * Taken from raspberry Pi Pico SDK and adapted
   * @param mode speed mode
   * @param bitRate wanted bitrate
   * @return actual bitrate
   */
  constexpr std::uint32_t setup(i2cModes mode, std::uint32_t bitRate) {
    i2cPeripheral()->IC_ENABLE = IC_ENABLE::ABORT;
    i2cPeripheral()->IC_CON = IC_CON::MASTER_MODE | static_cast<std::uint32_t>(mode) | IC_CON::IC_RESTART_EN |
                              IC_CON::IC_SLAVE_DISABLE | IC_CON::TX_EMTPY_CTRL;

    i2cPeripheral()->IC_TX_TL = 0;  // set watermarks to 1 to simplify handling
    i2cPeripheral()->IC_RX_TL = 0;  // set watermarks to 1 to simplify handling

    i2cPeripheral()->IC_DMA_CR = IC_DMA_CR::RDMAE | IC_DMA_CR::TDMAE;  // enable DMA, harmless without DMA

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
    i2cPeripheral()->IC_FS_SCL_HCNT = hcnt;
    i2cPeripheral()->IC_FS_SCL_LCNT = lcnt;
    i2cPeripheral()->IC_FS_SPKLEN = lcnt < 16 ? 1 : lcnt / 16;

    i2cPeripheral()->IC_SDA_HOLD =
      (i2cPeripheral()->IC_SDA_HOLD & ~IC_SDA_HOLD::IC_SDA_TX_HOLD_MASK) | IC_SDA_HOLD::IC_SDA_TX_HOLD(sdaTxHoldCount);

    // enable
    i2cPeripheral()->IC_ENABLE = IC_ENABLE::ENABLE;
    return frequencyInput / period;
  }
  // TODO setup slave with slave address
  /**
   * @brief Write data to I2C device
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  constexpr void write(libMcuLL::i2cDeviceAddress address, const std::span<std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->IC_ENABLE = IC_ENABLE::ABORT;
    i2cPeripheral()->IC_TAR = i2cAddress;
    i2cPeripheral()->IC_ENABLE = IC_ENABLE::ENABLE;
  }
  /**
   * @brief Read data from I2C device
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  constexpr void read(libMcuLL::i2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::i2c::peripheral* i2cPeripheral() {
    return reinterpret_cast<hw::i2c::peripheral*>(i2cAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::i2c::peripheral* i2cPeripheralSet() {
    return reinterpret_cast<hw::i2c::peripheral*>(i2cAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::i2c::peripheral* i2cPeripheralClear() {
    return reinterpret_cast<hw::i2c::peripheral*>(i2cAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::i2c::peripheral* i2cPeripheralXor() {
    return reinterpret_cast<hw::i2c::peripheral*>(i2cAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType i2cAddress = i2cAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::i2c
#endif