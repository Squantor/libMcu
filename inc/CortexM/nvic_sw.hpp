/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file nvic functions
 */
#ifndef NVIC_SW_HPP
#define NVIC_SW_HPP
namespace libMcuLL {
namespace sw {
namespace nvic {
using namespace hw::nvic;
template <libMcuLL::nvicBaseAddress const& address_>
struct nvic {
  /**
   * @brief Construct a new systick object
   *
   */
  nvic() {}

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hw::nvic::peripheral* peripheral() {
    return reinterpret_cast<hw::nvic::peripheral*>(address);
  }
  /**
   * @brief Setup systick
   */
  constexpr void init() {}

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace nvic
}  // namespace sw
}  // namespace libMcuLL

#endif