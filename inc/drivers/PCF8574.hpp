/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file PCF8574.hpp
 * @brief driver for the PCF8574 I2C expander
 */
#ifndef PCF8574_HPP
#define PCF8574_HPP

#include "../libmcu/libmcudrv.hpp"

namespace libmcudrv::PCF8574 {

using PcfLambda = std::add_pointer<void(std::uint8_t)>::type; /*!< Base type for a PCF8574 lambda */

/**
 * @brief PCF8574 driver
 * @todo i2chal template parameter needs check with a concept
 * @tparam i2c_hal I2C hal to be used
 * @tparam i2c_address I2C address the port expander is connected to
 */
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address>
struct PCF8574 : public libmcu::NonBlocking {
  /**
   * @brief Initialize the port expander
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Init(PcfLambda lambda = nullptr) {
    pin_change_callback = lambda;
    previous_isr_counter = 0;
    isr_counter = 0;
    // read out port expander to clear the interrupt and update internal state
    i2c_hal.Receive(i2c_address, pin_state);
    return libmcu::Results::NoError;
  }
  /** @brief To be called from pin interrupt ISR
   */
  constexpr void Isr(void) {
    isr_counter = isr_counter + 1;
  }
  /** @brief Progress function
   */
  constexpr void progress(void) final {
    if (isr_counter != previous_isr_counter) {
      i2c_hal.Receive(i2c_address, pin_state, this);
      previous_isr_counter = isr_counter;
    }
  }
  /** @brief Callback used by I2C HAL
   */
  constexpr void callback(libmcu::Results result) final {
    if (result != libmcu::Results::NoError)
      return;
    if (pin_change_callback != nullptr)
      pin_change_callback(pin_state[0]);
  }
  /** @brief Register a callback
   * @param lambda lambda to register
   */
  constexpr void RegisterCallback(PcfLambda lambda) {
    pin_change_callback = lambda;
  }

 private:
  std::array<std::uint8_t, 1> pin_state;
  volatile uint8_t isr_counter; /*!< number of times the ISR has been called */
  uint8_t previous_isr_counter; /*!< number of times the ISR has been called */
  PcfLambda pin_change_callback = nullptr;
};
}  // namespace libmcudrv::PCF8574

#endif