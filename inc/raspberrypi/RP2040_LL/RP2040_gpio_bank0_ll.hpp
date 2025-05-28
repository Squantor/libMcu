/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_gpio_bank0_ll.hpp
 * @brief low level interface for the RP2040 GPIO bank 0
 */
#ifndef RP2040_GPIO_BANK0_SW_HPP
#define RP2040_GPIO_BANK0_SW_HPP

namespace libmcull::gpioBank0 {
template <libmcu::ioBank0BaseAddress const& gpioBank0Address_>
struct gpioBank0 : libmcu::PeripheralBase {
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
      libmcuhw::gpioBank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.functionSelect));
  }
  // TODO: Make setup method with overrides
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioBank0::gpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libmcuhw::gpioBank0::gpioBank0*>(ioBank0Address);
  }

 private:
  static constexpr libmcu::HwAddressType ioBank0Address = gpioBank0Address_; /*!< peripheral address */
};
}  // namespace libmcull::gpioBank0
#endif