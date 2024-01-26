/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick functions
 */
#ifndef SYSTICK_SW_HPP
#define SYSTICK_SW_HPP
namespace libMcuLL {
namespace sw {
namespace systick {
using namespace hw::systick;
template <libMcuLL::systickBaseAddress const& address_>
struct systick {
  /**
   * @brief Construct a new systick object
   *
   */
  systick() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hw::systick::peripheral* peripheral() {
    return reinterpret_cast<hw::systick::peripheral*>(address);
  }
  /**
   * @brief Setup systick
   */
  constexpr void init() {}

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace systick
}  // namespace sw
}  // namespace libMcuLL

#endif