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
   * @brief Setup nvic
   *
   * Nothing to setup here
   */
  constexpr void init() {}

  /**
   * @brief enable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void enable(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = static_cast<std::uint32_t>(number) >> 5;
      std::uint32_t bitIndex = static_cast<std::uint32_t>(number) & 0x1F;
      peripheral()->ISER[index] = ISER::SETENA(bitIndex);
    }
  }

  /**
   * @brief disable interrupt in nvic
   *
   * @param interrupt interrupt number
   */
  constexpr void disable(libMcuLL::hw::interrupts interrupt) {
    std::int32_t number = static_cast<std::uint32_t>(interrupt);
    if (number >= 0) {
      std::uint32_t index = static_cast<std::uint32_t>(number) >> 5;
      std::uint32_t bitIndex = static_cast<std::uint32_t>(number) & 0x1F;
      peripheral()->ICER[index] = ICER::CLRENA(bitIndex);
    }
  }

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace nvic
}  // namespace sw
}  // namespace libMcuLL

#endif