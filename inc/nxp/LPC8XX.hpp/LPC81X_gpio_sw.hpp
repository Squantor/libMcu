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
template <libMcuLL::GPIObaseAddress const &gpioAddress_>
struct gpio {
  static constexpr libMcuLL::hwAddressType gpioAddress = gpioAddress_; /**< peripheral address */
  /**
   *
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static hw::gpio::peripheral *gpioPeripheral() {
    return reinterpret_cast<hw::gpio::peripheral *>(gpioAddress);
  }

  /**
   * @brief Set gpio pin to output mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void output(PIN &pin) {
    gpioPeripheral()->DIR[pin.gpioPortIndex] = gpioPeripheral()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to input mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void input(PIN &pin) {
    gpioPeripheral()->DIR[pin.gpioPortIndex] = gpioPeripheral()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to high
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void high(PIN &pin) {
    gpioPeripheral()->SET[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to low
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void low(PIN &pin) {
    gpioPeripheral()->CLR[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Toggle gpio pin
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  void toggle(PIN &pin) {
    gpioPeripheral()->NOT[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
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
    return gpioPeripheral()->W[pin.gpioPortIndex][pin.gpioPinIndex];
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
    gpioPeripheral()->W[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
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
    gpioPeripheral()->DIR[port.gpioPortIndex] = setting;
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
    gpioPeripheral()->DIR[port.gpioPortIndex] = (gpioPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
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
    gpioPeripheral()->DIR[port.gpioPortIndex] = (gpioPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
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
    gpioPeripheral()->DIR[port.gpioPortIndex] = setting;
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
    gpioPeripheral()->CLR[port.gpioPortIndex] = setting;
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
    gpioPeripheral()->SET[port.gpioPortIndex] = setting;
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
    gpioPeripheral()->NOT[port.gpioPortIndex] = setting;
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
    return static_cast<std::uint32_t>(gpioPeripheral()->PIN[port.gpioPortIndex]);
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
    return static_cast<std::uint32_t>(gpioPeripheral()->PIN[port.gpioPortIndex]) & mask;
  }
};
}  // namespace gpio
}  // namespace sw
}  // namespace libMcuLL

#endif