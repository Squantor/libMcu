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
// template <auto &gpioPeripheral, auto &notEnablePin, auto &A0Pin>
template <auto &gpioPeripheral, typename notEnablePinType, typename a0PinType, typename a1PinType, typename a2PinType>
struct mux3to8 {
  /**
   * @brief
   *
   */
  void initialize() {
    gpioPeripheral.high(notEnablePin);
    gpioPeripheral.output(notEnablePin);
    gpioPeripheral.output(a0Pin);
    gpioPeripheral.output(a1Pin);
    gpioPeripheral.output(a2Pin);
  }

  /**
   * @brief
   *
   * @param enable
   * @param value
   */
  void set(bool enable, std::uint32_t value) {
    if (value & 0x01)
      gpioPeripheral.high(a0Pin);
    else
      gpioPeripheral.low(a0Pin);
    if (value & 0x02)
      gpioPeripheral.high(a1Pin);
    else
      gpioPeripheral.low(a1Pin);
    if (value & 0x04)
      gpioPeripheral.high(a2Pin);
    else
      gpioPeripheral.low(a2Pin);
    if (enable)
      gpioPeripheral.low(notEnablePin);
    else
      gpioPeripheral.high(notEnablePin);
  }

 private:
  static constexpr notEnablePinType notEnablePin{};
  static constexpr a0PinType a0Pin{};
  static constexpr a1PinType a1Pin{};
  static constexpr a2PinType a2Pin{};

  // add constraints here
  using peripheralType = std::remove_reference<decltype(gpioPeripheral)>::type;
  static_assert(std::is_base_of<libMcuHal::halGpioBase, peripheralType>::value, "gpioPeripheral is not derived from halGpioBase");
  static_assert(std::is_base_of<libMcu::pinBase, notEnablePinType>::value, "notEnablePinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a0PinType>::value, "a0PinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a1PinType>::value, "a1PinType is not derived from pinBase");
  static_assert(std::is_base_of<libMcu::pinBase, a2PinType>::value, "a2PinType is not derived from pinBase");
};
}  // namespace libMcuDriver::mux

#endif