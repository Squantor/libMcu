/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 GPIO bank0 software interface
 */
#ifndef RP2040_GPIO_BANK0_SW_HPP
#define RP2040_GPIO_BANK0_SW_HPP

namespace libMcuLL::gpioBank0 {
template <libMcu::ioBank0BaseAddress const& gpioBank0Address_>
struct gpioBank0 : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void setup(PIN& pin) {
    gpioBank0Peripheral()->GPIO[pin.pinIndex].CTRL =
      libMcuHw::gpioBank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.functionSelect));
  }
  // TODO: Make setup method with overrides
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(ioBank0Address);
  }

 private:
  static constexpr libMcu::hwAddressType ioBank0Address = gpioBank0Address_; /**< peripheral address */
};
}  // namespace libMcuLL::gpioBank0
#endif