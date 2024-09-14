/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series GPIO low level functions
 */
#ifndef LPC84X_GPIO_LL_HPP
#define LPC84X_GPIO_LL_HPP

namespace libMcu::ll::gpio {
namespace hardware = libMcu::hw::gpio;
template <libMcu::gpioBaseAddress const &gpioAddress_>
struct gpio : libMcu::peripheralBase {
  /**
   * @brief Set gpio pin to output mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void output(PIN &pin) {
    gpioPeripheral()->DIR[pin.gpioPortIndex] = gpioPeripheral()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to input mode
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void input(PIN &pin) {
    gpioPeripheral()->DIR[pin.gpioPortIndex] = gpioPeripheral()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to high
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void high(PIN &pin) {
    gpioPeripheral()->SET[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Set gpio pin to low
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void low(PIN &pin) {
    gpioPeripheral()->CLR[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }

  /**
   * @brief Toggle gpio pin
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void toggle(PIN &pin) {
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
  constexpr std::uint32_t get(PIN &pin) {
    return gpioPeripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex];
  }

  /**
   * @brief Set the gpio pin state
   *
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  constexpr void set(PIN &pin, std::uint32_t setting) {
    gpioPeripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
  }

  /**
   * @brief Set gpio port direction
   *
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   */
  template <typename PORT>
  constexpr void portDirection(PORT &port, std::uint32_t setting) {
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
  constexpr void portDirection(PORT &port, std::uint32_t setting, std::uint32_t mask) {
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
  constexpr void portSet(PORT &port, std::uint32_t setting, std::uint32_t mask) {
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
  constexpr void portSet(PORT &port, std::uint32_t setting) {
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
  constexpr void portLow(PORT &port, std::uint32_t setting) {
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
  constexpr void portHigh(PORT &port, std::uint32_t setting) {
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
  constexpr void portToggle(PORT &port, std::uint32_t setting) {
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
  constexpr std::uint32_t portGet(PORT &port) {
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
  constexpr std::uint32_t portGet(PORT &port, std::uint32_t mask) {
    return static_cast<std::uint32_t>(gpioPeripheral()->PIN[port.gpioPortIndex]) & mask;
  }
  /**
   *
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  constexpr hardware::peripheral *gpioPeripheral() {
    return reinterpret_cast<hardware::peripheral *>(gpioAddress);
  }

 private:
  static constexpr libMcu::hwAddressType gpioAddress = gpioAddress_; /**< peripheral address */
};
}  // namespace libMcu::ll::gpio
#endif