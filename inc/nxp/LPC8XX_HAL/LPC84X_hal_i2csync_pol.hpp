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

 private:
  /**
   * @brief access i2c registers
   * @return return pointer to peripheral
   */
  static hardware::i2c* i2cPeripheral() {
    return reinterpret_cast<hardware::i2c*>(i2cBaseAddress);
  }

  static constexpr libMcu::hwAddressType i2cBaseAddress = i2cBaseAddress_; /**< UART peripheral address */
  std::array<std::uint8_t, bufSize> txBuffer;
  std::array<std::uint8_t, bufSize> rxBuffer;
};

}  // namespace libMcuHal::i2c
#endif