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

namespace libMcuLL {
namespace sw {
namespace gpioBank0 {
template <libMcuLL::ioBank0BaseAddress const& gpioBank0Address_>
struct gpioBank0 : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0Peripheral() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(gpioBank0Address);
  }

 private:
  static constexpr libMcuLL::hwAddressType gpioBank0Address = gpioBank0Address_; /**< peripheral address */
};
}  // namespace gpioBank0
}  // namespace sw
}  // namespace libMcuLL
#endif