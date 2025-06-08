/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_gpio_ll.hpp
 * @brief LPC84X series GPIO interface class and definitions
 */
#ifndef LPC84X_GPIO_LL_HPP
#define LPC84X_GPIO_LL_HPP

namespace libmcull::gpio {
namespace hardware = libmcuhw::gpio;
template <libmcu::GpioBaseAddress const &gpioAddress_>
struct Gpio : libmcull::PeripheralBase {
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetOutput(PIN &pin) {
    GetPeripheral()->DIR[pin.gpioPortIndex] = GetPeripheral()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to input mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetInput(PIN &pin) {
    GetPeripheral()->DIR[pin.gpioPortIndex] = GetPeripheral()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to high
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetHigh(PIN &pin) {
    GetPeripheral()->SET[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to low
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetLow(PIN &pin) {
    GetPeripheral()->CLR[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Toggle gpio pin
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void Toggle(PIN &pin) {
    GetPeripheral()->NOT[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Get the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  constexpr std::uint32_t GetState(PIN &pin) {
    return GetPeripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex];
  }
  /**
   * @brief Set the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  constexpr void SetState(PIN &pin, std::uint32_t setting) {
    GetPeripheral()->B[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
  }
  /**
   * @brief Set gpio port direction
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   */
  template <typename PORT>
  constexpr void SetPortDirection(PORT &port, std::uint32_t setting) {
    GetPeripheral()->DIR[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Set gpio port direction
   * Set the gpio port direction in one go masked by a mask
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   * @param mask gpio pins to ignore
   */
  template <typename PORT>
  constexpr void SetPortDirection(PORT &port, std::uint32_t setting, std::uint32_t mask) {
    GetPeripheral()->DIR[port.gpioPortIndex] = (GetPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }
  /**
   * @brief Setup gpio port at once
   * sets the gpio port pins in one go while adhering to the bit mask
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   * @param mask gpio pins that are unaffected
   */
  template <typename PORT>
  constexpr void SetPort(PORT &port, std::uint32_t setting, std::uint32_t mask) {
    GetPeripheral()->PIN[port.gpioPortIndex] = (GetPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }
  /**
   * @brief Setup gpio port at once
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   */
  template <typename PORT>
  constexpr void SetPort(PORT &port, std::uint32_t setting) {
    GetPeripheral()->PIN[port.gpioPortIndex] = setting;
  }
  /**
   * @brief set gpio port pins to low
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set low, a 1 bit will set the corresponding gpio pin to low
   */
  template <typename PORT>
  constexpr void SetPortLow(PORT &port, std::uint32_t setting) {
    GetPeripheral()->CLR[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Set gpio port pins to high
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to set high, a 1 bit will set the corresponding gpio pin to high
   */
  template <typename PORT>
  constexpr void SetPortHigh(PORT &port, std::uint32_t setting) {
    GetPeripheral()->SET[port.gpioPortIndex] = setting;
  }
  /**
   * @brief toggle gpio port pins
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param setting gpio pins to toggle, a 1 bit will toggle the corresponding pio pin
   */
  template <typename PORT>
  constexpr void TogglePort(PORT &port, std::uint32_t setting) {
    GetPeripheral()->NOT[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Get gpio port pins state
   * @tparam PORT port instance
   * @param port reference to port instance
   * @return std::uint32_t gpio pin state
   */
  template <typename PORT>
  constexpr std::uint32_t GetPortState(PORT &port) {
    return static_cast<std::uint32_t>(GetPeripheral()->PIN[port.gpioPortIndex]);
  }
  /**
   * @brief Get gpio port pins state
   * @tparam PORT port instance
   * @param port reference to port instance
   * @param mask gpio pins to ignore
   * @return std::uint32_t gpio pin state masked by mask
   */
  template <typename PORT>
  constexpr std::uint32_t GetPortState(PORT &port, std::uint32_t mask) {
    return static_cast<std::uint32_t>(GetPeripheral()->PIN[port.gpioPortIndex]) & mask;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to gpio registers
   */
  constexpr hardware::Gpio *GetPeripheral() {
    return reinterpret_cast<hardware::Gpio *>(gpioAddress);
  }

 private:
  static constexpr libmcu::HwAddressType gpioAddress = gpioAddress_; /*!< peripheral address */
};
}  // namespace libmcull::gpio
#endif