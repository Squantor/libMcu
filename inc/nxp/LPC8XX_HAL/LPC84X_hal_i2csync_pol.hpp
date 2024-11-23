/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_i2csync_pol.hpp
 * \file LPC840 series synchronous polling I2C HAL
 */
#ifndef LPC84X_HAL_I2CSYNC_POL_HPP
#define LPC84X_HAL_I2CSYNC_POL_HPP

#include "LPC84X_hal_i2c_common.hpp"

namespace libMcuHal::i2c {
namespace hardware = libMcuHw::i2c;
namespace nvic = libMcuHw::nvic;
/**
 * @brief asynchronous I2C HAL polling implementation
 * @tparam i2cBaseAddress_ i2c peripheral base address
 * @tparam nvicBaseAddress_ nvic peripheral base address
 * @tparam bufSize buffer size
 */
template <libMcu::i2cBaseAddress const& i2cBaseAddress_, std::size_t bufSize>
struct i2cSyncPol {
  /**
   * @brief Construct a new synchronous polling i2c
   */
  i2cSyncPol() {}
  /**
   * @brief Initialize I2C peripheral clocks
   * @tparam &t_clockConfig clock configuration for this peripheral
   * @param bitRate i2C bit rate
   * @param timeout clocks to timeout
   * @return actual bit rate
   */
  template <const libMcuHw::clock::periClockConfig& t_clockConfig>
  constexpr std::uint32_t init(std::uint32_t bitRate, std::uint32_t timeout) {
    txBufferIndex = rxBufferIndex = 0;
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t peripheralFrequency = getInputClockFreq<t_clockConfig>();
    std::uint32_t divider = peripheralFrequency / (bitRate * 20);
    i2cPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    i2cPeripheral()->CLKDIV = divider + 1;
    i2cPeripheral()->CFG = hardware::CFG::MSTEN;
    return peripheralFrequency / divider / 20;
  }
  constexpr libMcu::results addWriteData(std::uint8_t data) {
    if (txBufferIndex == txBuffer.size())
      return libMcu::results::FULL;
    txBuffer[txBufferIndex++] = data;
    return libMcu::results::NO_ERROR;
  }
  constexpr libMcu::results addWriteData(std::span<const std::uint8_t> buffer) {
    for (std::uint8_t element : buffer) {
      if (txBufferIndex == txBuffer.size())
        return libMcu::results::FULL;
      txBuffer[txBufferIndex++] = element;
    }
    return libMcu::results::NO_ERROR;
  }
  constexpr libMcu::results masterWrite(const libMcu::i2cDeviceAddress address) {
    return masterWrite(address, std::span<const std::uint8_t>(txBuffer.data(), txBufferIndex));
  }
  constexpr libMcu::results masterWrite(const libMcu::i2cDeviceAddress address,
                                        const std::span<const std::uint8_t> transmitBuffer) {
    libMcu::results result = libMcu::results::NO_ERROR;
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY) {
      result = libMcu::results::ERROR;
      goto stop;
    }
    for (const std::uint8_t& data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      masterWait();
      if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY) {
        result = libMcu::results::ERROR;
        goto stop;
      }
    }
  stop:
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    masterWait();
    txBufferIndex = 0;
    return result;
  }

 private:
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void masterWait() {
    // @todo add timeout
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t getInputClockFreq() {
    static_assert(config.peripheral == libMcuHw::clock::periSelect::I2C0);
    return config.getFrequency();
  }
  /**
   * @brief access i2c registers
   * @return return pointer to peripheral
   */
  static hardware::i2c* i2cPeripheral() {
    return reinterpret_cast<hardware::i2c*>(i2cBaseAddress);
  }

  static constexpr libMcu::hwAddressType i2cBaseAddress = i2cBaseAddress_; /**< UART peripheral address */
  std::size_t txBufferIndex;
  std::size_t rxBufferIndex;
  std::array<std::uint8_t, bufSize> txBuffer;
  std::array<std::uint8_t, bufSize> rxBuffer;
};

}  // namespace libMcuHal::i2c
#endif