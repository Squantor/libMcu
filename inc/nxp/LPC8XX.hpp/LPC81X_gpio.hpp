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

namespace libMcuLL {
namespace sw {
namespace gpio {
using namespace hw::gpio;
template <libMcuLL::GPIObaseAddress const &address_>
struct gpio {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   *
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static hw::gpio::peripheral *peripheral() {
    return reinterpret_cast<hw::gpio::peripheral *>(address);
  }

  /**
   * @brief Set gpio pin to output mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void output(PIN &pin) {
    peripheral()->DIR[pin.gpioPortIndex] = peripheral()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to input mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void input(PIN &pin) {
    peripheral()->DIR[pin.gpioPortIndex] = peripheral()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to high
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void high(PIN &pin) {
    peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = 0x01;
  }

  /**
   * @brief Set gpio pin to low
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void low(PIN &pin) {
    peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = 0x00;
  }

  /**
   * @brief Toggle gpio pin
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void toggle(PIN &pin) {
    peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = ~peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex];
  }

  /**
   * @brief Get the gpio pin state
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  std::uint32_t get(PIN &pin) {
    return static_cast<std::uint32_t>(peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex]);
  }

  /**
   * @brief Set the gpio pin state
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  void set(PIN &pin, std::uint32_t setting) {
    peripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
  }

  /**
   * @brief Set gpio port direction
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   */
  template <typename PORT>
  void portDirection(PORT &port, std::uint32_t setting) {
    peripheral()->DIR[port.gpioPortIndex] = setting;
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
  void portDirection(PORT &port, std::uint32_t setting, std::uint32_t mask) {
    peripheral()->DIR[port.gpioPortIndex] = (peripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
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
  void portSet(PORT &port, std::uint32_t setting, std::uint32_t mask) {
    peripheral()->DIR[port.gpioPortIndex] = (peripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }

  /**
   * @brief Setup gpio port at once
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   */
  template <typename PORT>
  void portSet(PORT &port, std::uint32_t setting) {
    peripheral()->DIR[port.gpioPortIndex] = setting;
  }

  /**
   * @brief set gpio port pins to low
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set low, a 1 bit will set the corresponding gpio pin to low
   */
  template <typename PORT>
  void portLow(PORT &port, std::uint32_t setting) {
    peripheral()->CLR[port.gpioPortIndex] = setting;
  }

  /**
   * @brief Set gpio port pins to high
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set high, a 1 bit will set the corresponding gpio pin to high
   */
  template <typename PORT>
  void portHigh(PORT &port, std::uint32_t setting) {
    peripheral()->SET[port.gpioPortIndex] = setting;
  }

  /**
   * @brief toggle gpio port pins
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to toggle, a 1 bit will toggle the corresponding pio pin
   */
  template <typename PORT>
  void portToggle(PORT &port, std::uint32_t setting) {
    peripheral()->NOT[port.gpioPortIndex] = setting;
  }

  /**
   * @brief Get gpio port pins state
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @return std::uint32_t gpio pin state
   */
  template <typename PORT>
  std::uint32_t portGet(PORT &port) {
    return static_cast<std::uint32_t>(peripheral()->PIN[port.gpioPortIndex]);
  }

  /**
   * @brief Get gpio port pins state
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param mask gpio pins to ignore
   * @return std::uint32_t gpio pin state masked by mask
   */
  template <typename PORT>
  std::uint32_t portGet(PORT &port, std::uint32_t mask) {
    return static_cast<std::uint32_t>(peripheral()->PIN[port.gpioPortIndex]) & mask;
  }
};
}  // namespace gpio
}  // namespace sw
}  // namespace libMcuLL

#endif