/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_gpio_ll.hpp
 * @brief LPC810 series GPIO interface class and definitions
 */
#ifndef LPC81X_GPIO_HPP
#define LPC81X_GPIO_HPP

namespace libmcull::sw::gpio {
namespace hardware = libmcuhw::gpio;
/**
 * @brief LPC81X GPIO interface
 * @tparam &gpioAddress_
 */
template <libmcu::gpioBaseAddress gpio_address>
struct Gpio : libmcu::PeripheralBase {
  /**
   * @brief Set gpio pin to output mode
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   */
  template <typename Pin>
  constexpr void SetOutput(Pin &pin) {
    GetPeripheral()->DIR[pin.gpioPortIndex] = GetPeripheral()->DIR[pin.gpioPortIndex] | (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to input mode
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   */
  template <typename Pin>
  constexpr void SetInput(Pin &pin) {
    GetPeripheral()->DIR[pin.gpioPortIndex] = GetPeripheral()->DIR[pin.gpioPortIndex] & ~(1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to high
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   */
  template <typename Pin>
  constexpr void SetHigh(Pin &pin) {
    GetPeripheral()->SET[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Set gpio pin to low
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   */
  template <typename Pin>
  constexpr void SetLow(Pin &pin) {
    GetPeripheral()->CLR[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Toggle gpio pin
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   */
  template <typename Pin>
  constexpr void Toggle(Pin &pin) {
    GetPeripheral()->NOT[pin.gpioPortIndex] = (1 << pin.gpioPinIndex);
  }
  /**
   * @brief Get the gpio pin state
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, 1 for high
   */
  template <typename Pin>
  constexpr std::uint32_t GetState(Pin &pin) {
    return GetPeripheral()->W[pin.gpioPortIndex][pin.gpioPinIndex];
  }
  /**
   * @brief Set the gpio pin state
   * @tparam Pin pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename Pin>
  constexpr void SetState(Pin &pin, std::uint32_t setting) {
    GetPeripheral()->W[pin.gpioPortIndex][pin.gpioPinIndex] = setting;
  }
  /**
   * @brief Set gpio port direction
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   */
  template <typename Port>
  constexpr void SetPortDirection(Port &port, std::uint32_t setting) {
    GetPeripheral()->DIR[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Set gpio port direction
   * Set the gpio port direction in one go masked by a mask
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio port pin directions
   * @param mask gpio pins to ignore
   */
  template <typename Port>
  constexpr void SetPortDirection(Port &port, std::uint32_t setting, std::uint32_t mask) {
    GetPeripheral()->DIR[port.gpioPortIndex] = (GetPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }
  /**
   * @brief Setup gpio port at once
   * sets the gpio port pins in one go while adhering to the bit mask
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   * @param mask gpio pins that are unaffected
   */
  template <typename Port>
  constexpr void SetPort(Port &port, std::uint32_t setting, std::uint32_t mask) {
    GetPeripheral()->DIR[port.gpioPortIndex] = (GetPeripheral()->DIR[port.gpioPortIndex] & ~mask) | (setting & mask);
  }
  /**
   * @brief Setup gpio port at once
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio pins to setup
   */
  template <typename Port>
  constexpr void SetPort(Port &port, std::uint32_t setting) {
    GetPeripheral()->DIR[port.gpioPortIndex] = setting;
  }
  /**
   * @brief set gpio port pins to low
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio pins to set low, a 1 bit will set the corresponding gpio pin to low
   */
  template <typename Port>
  constexpr void SetPortLow(Port &port, std::uint32_t setting) {
    GetPeripheral()->CLR[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Set gpio port pins to high
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio pins to set high, a 1 bit will set the corresponding gpio pin to high
   */
  template <typename Port>
  constexpr void SetPortHigh(Port &port, std::uint32_t setting) {
    GetPeripheral()->SET[port.gpioPortIndex] = setting;
  }
  /**
   * @brief toggle gpio port pins
   * @tparam Port port instance
   * @param port reference to port instance
   * @param setting gpio pins to toggle, a 1 bit will toggle the corresponding pio pin
   */
  template <typename Port>
  constexpr void TogglePort(Port &port, std::uint32_t setting) {
    GetPeripheral()->NOT[port.gpioPortIndex] = setting;
  }
  /**
   * @brief Get gpio port pins state
   * @tparam Port port instance
   * @param port reference to port instance
   * @return std::uint32_t gpio pin state
   */
  template <typename Port>
  constexpr std::uint32_t GetPort(Port &port) {
    return static_cast<std::uint32_t>(GetPeripheral()->PIN[port.gpioPortIndex]);
  }
  /**
   * @brief Get gpio port pins state
   * @tparam Port port instance
   * @param port reference to port instance
   * @param mask gpio pins to ignore
   * @return std::uint32_t gpio pin state masked by mask
   */
  template <typename Port>
  constexpr std::uint32_t GetPort(Port &port, std::uint32_t mask) {
    return static_cast<std::uint32_t>(GetPeripheral()->PIN[port.gpioPortIndex]) & mask;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to gpio registers
   */
  constexpr libmcuhw::gpio::Gpio *GetPeripheral() {
    return reinterpret_cast<libmcuhw::gpio::Gpio *>(gpio_address_);
  }

 private:
  static constexpr libmcu::HwAddressType gpio_address_ = gpio_address; /*!< peripheral address */
};
}  // namespace libmcull::sw::gpio
#endif