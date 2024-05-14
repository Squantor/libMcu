/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Driver for a 3 to 8 multiplexer, usable for 74138's 4051's and such
 */
#ifndef MUX3TO8_HPP
#define MUX3TO8_HPP

namespace libMcuDriver::mux {

using namespace libMcuHal;
/**
 * @brief 3to8 multiplexer driver
 *
 * @tparam &gpioHal object reference to a GPIO Hal object
 * @tparam notEnablePinType trait template type for the not enable pin
 * @tparam a0PinType trait template type for A0 pin
 * @tparam a1PinType trait template type for A1 pin
 * @tparam a2PinType trait template type for A2 pin
 */
template <auto &gpioHal, typename notEnablePinType, typename a0PinType, typename a1PinType, typename a2PinType>
struct mux3to8 {
  /**
   * @brief setup gpio pins to outputs and default to disabled multiplexer
   */
  void initialize() {
    gpioHal.high(notEnablePin);
    gpioHal.output(notEnablePin);
    gpioHal.output(a0Pin);
    gpioHal.output(a1Pin);
    gpioHal.output(a2Pin);
  }

  /**
   * @brief setup multiplexer
   *
   * @param enable enable or disable
   * @param value which value to multiplex
   */
  void set(bool enable, std::uint32_t value) {
    if (value & 0x01)
      gpioHal.high(a0Pin);
    else
      gpioHal.low(a0Pin);
    if (value & 0x02)
      gpioHal.high(a1Pin);
    else
      gpioHal.low(a1Pin);
    if (value & 0x04)
      gpioHal.high(a2Pin);
    else
      gpioHal.low(a2Pin);
    if (enable)
      gpioHal.low(notEnablePin);
    else
      gpioHal.high(notEnablePin);
  }

 private:
  static constexpr notEnablePinType notEnablePin{};
  static constexpr a0PinType a0Pin{};
  static constexpr a1PinType a1Pin{};
  static constexpr a2PinType a2Pin{};

  // add constraints here
  using halType = std::remove_reference<decltype(gpioHal)>::type;
  static_assert(std::is_base_of<libMcuHal::halGpioBase, halType>::value, "gpioPeripheral is not derived from halGpioBase");
  static_assert(std::is_base_of<libMcu::pinBase, notEnablePinType>::value, "notEnablePinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a0PinType>::value, "a0PinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a1PinType>::value, "a1PinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a2PinType>::value, "a2PinType is not derived from pinBase");
};
}  // namespace libMcuDriver::mux

#endif