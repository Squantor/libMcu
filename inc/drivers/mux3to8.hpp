/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file mux3to8.hpp
 * @brief 3 to 8 multiplexer driver, usable for 74138's 4051's and such
 */
#ifndef MUX3TO8_HPP
#define MUX3TO8_HPP

namespace libmcudrv::mux {

using namespace libmcuhal;
/**
 * @brief 3to8 multiplexer driver
 *
 * @tparam &gpio_hal object reference to a GPIO Hal object
 * @tparam notEnablePinType trait template type for the not enable pin
 * @tparam a0PinType trait template type for A0 pin
 * @tparam a1PinType trait template type for A1 pin
 * @tparam a2PinType trait template type for A2 pin
 */
template <libmcuhal::DerivedFromGpio auto &gpio_hal, libmcu::DerivedFromPin notEnablePinType, libmcu::DerivedFromPin a0PinType,
          libmcu::DerivedFromPin a1PinType, libmcu::DerivedFromPin a2PinType>
struct mux3to8 {
  /**
   * @brief setup gpio pins to outputs and default to disabled multiplexer
   */
  void initialize() {
    gpio_hal.SetupOutput(notEnablePin, 1);
    gpio_hal.SetupOutput(a0Pin, 0);
    gpio_hal.SetupOutput(a1Pin, 0);
    gpio_hal.SetupOutput(a2Pin, 0);
  }

  /**
   * @brief setup multiplexer
   * @param enable enable or disable
   * @param value which value to multiplex
   */
  void set(bool enable, std::uint32_t value) {
    gpio_hal.SetLevel(a0Pin, value & 0x01);
    gpio_hal.SetLevel(a1Pin, value & 0x02);
    gpio_hal.SetLevel(a2Pin, value & 0x04);
    gpio_hal.SetLevel(notEnablePin, enable ? 0 : 1);
  }

 private:
  static constexpr notEnablePinType notEnablePin{};
  static constexpr a0PinType a0Pin{};
  static constexpr a1PinType a1Pin{};
  static constexpr a2PinType a2Pin{};

  // add constraints here
  using halType = std::remove_reference<decltype(gpio_hal)>::type;
  static_assert(std::is_base_of<libmcuhal::GpioBase, halType>::value, "gpioPeripheral is not derived from HalGpioBase");
  static_assert(std::is_base_of<libmcu::PinBase, notEnablePinType>::value, "notEnablePinType is not derived from pinBase");
  static_assert(std::is_base_of<libmcu::PinBase, a0PinType>::value, "a0PinType is not derived from pinBase");
  static_assert(std::is_base_of<libmcu::PinBase, a1PinType>::value, "a1PinType is not derived from pinBase");
  static_assert(std::is_base_of<libmcu::PinBase, a2PinType>::value, "a2PinType is not derived from pinBase");
};
}  // namespace libmcudrv::mux

#endif