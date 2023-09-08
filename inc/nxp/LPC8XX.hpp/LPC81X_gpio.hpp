/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series GPIO functions
 */
#ifndef LPC81X_GPIO_HPP
#define LPC81X_GPIO_HPP

namespace instances {
namespace gpio {
using namespace registers::gpio;
template <uint32_t base>
struct gpio {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static auto regs() {
    return reinterpret_cast<registers::gpio::registers *>(base);
  }

  /**
   * @brief Set gpio pin to output mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void output(PIN &pin) {
    regs()->DIR[pin.gpioPortIndex] = regs()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to input mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void input(PIN &pin) {
    regs()->DIR[pin.gpioPortIndex] = regs()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to high
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void high(PIN &pin) {
    regs()->B[pin.gpioPortIndex][pin.gpioPinIndex] = 0x01;
  }

  /**
   * @brief Set gpio pin to low
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void low(PIN &pin) {
    regs()->B[pin.gpioPortIndex][pin.gpioPinIndex] = 0x00;
  }

  /**
   * @brief Toggle gpio pin
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void toggle(PIN &pin) {
    regs()->B[pin.gpioPortIndex][pin.gpioPinIndex] = ~regs()->B[pin.gpioPortIndex][pin.gpioPinIndex];
  }

  /**
   * @brief Get the gpio pin state
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return uint32_t pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  uint32_t get(PIN &pin) {
    return static_cast<uint32_t>(regs()->B[pin.gpioPortIndex][pin.gpioPinIndex]);
  }

  /**
   * @brief Set the gpio pin state
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  void set(PIN &pin, uint32_t setting) {
    regs()->B[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
  }

  /**
   * @brief Set gpio port direction
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   */
  template <typename PORT>
  void portDirection(PORT &port, uint32_t setting) {
    regs()->DIR[port.gpioPortIndex] = setting;
  }

  /**
   * @brief Set gpio port direction
   *
   * Set the gpio port direction in one go masked by a mask
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   * @param mask gpio pins to ignore
   */
  template <typename PORT>
  void portDirection(PORT &port, uint32_t setting, uint32_t mask) {
    regs()->DIR[port.gpioPortIndex] = (regs()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }

  /**
   * @brief Setup gpio port at once
   *
   * sets the gpio port pins in one go while adhering to the bit mask
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   * @param mask gpio pins that are unaffected
   */
  template <typename PORT>
  void portSet(PORT &port, uint32_t setting, uint32_t mask) {
    regs()->DIR[port.gpioPortIndex] = (regs()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }

  /**
   * @brief Setup gpio port at once
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   */
  template <typename PORT>
  void portSet(PORT &port, uint32_t setting) {
    regs()->DIR[port.gpioPortIndex] = setting;
  }

  /**
   * @brief set gpio port pins to low
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set low, a 1 bit will set the corresponding gpio pin to low
   */
  template <typename PORT>
  void portLow(PORT &port, uint32_t setting) {
    regs()->CLR[port.gpioPortIndex] = setting;
  }

  /**
   * @brief Set gpio port pins to high
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set high, a 1 bit will set the corresponding gpio pin to high
   */
  template <typename PORT>
  void portHigh(PORT &port, uint32_t setting) {
    regs()->SET[port.gpioPortIndex] = setting;
  }

  /**
   * @brief toggle gpio port pins
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to toggle, a 1 bit will toggle the corresponding pio pin
   */
  template <typename PORT>
  void portToggle(PORT &port, uint32_t setting) {
    regs()->NOT[port.gpioPortIndex] = setting;
  }

  /**
   * @brief Get gpio port pins state
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @return uint32_t gpio pin state
   */
  template <typename PORT>
  uint32_t portGet(PORT &port) {
    return static_cast<uint32_t>(regs()->PIN[port.gpioPortIndex]);
  }

  /**
   * @brief Get gpio port pins state
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param mask gpio pins to ignore
   * @return uint32_t gpio pin state masked by mask
   */
  template <typename PORT>
  uint32_t portGet(PORT &port, uint32_t mask) {
    return static_cast<uint32_t>(regs()->PIN[port.gpioPortIndex]) & mask;
  }
};
}  // namespace gpio
}  // namespace instances

#endif