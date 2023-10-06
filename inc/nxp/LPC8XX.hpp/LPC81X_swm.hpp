/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series SWM functions
 */
#ifndef LPC81X_SWM_HPP
#define LPC81X_SWM_HPP

namespace libMcuLL {
namespace sw {
namespace swm {
using namespace hw::swm;
template <libMcuLL::SWMbaseAddress address_>
struct swm {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to registers
   */
  static hw::swm::peripheral *regs() {
    return reinterpret_cast<hw::swm::peripheral *>(address);
  }

  /**
   * @brief set pin to a function
   *
   * @tparam PIN      pin to assign function
   * @tparam FUNC     function to assign to pin
   * @param pin       pin to assign function to
   * @param function  function to assign to pin
   */
  template <typename PIN, typename FUNC>
  constexpr void setup(PIN &pin, FUNC &function) {
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::MOVABLE) {
      // create a mask for resetting the pin setting
      constexpr uint32_t mask = ~(0xFF << function.shift);
      regs()->PINASSIGN[function.index] = (regs()->PINASSIGN[function.index] & mask) | (pin.pio << function.shift);
    }
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::FIXED) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      regs()->PINENABLE0 = regs()->PINENABLE0 & ~function.mask;
    }
  }

  template <typename PIN, typename FUNC>
  constexpr void clear([[maybe_unused]] PIN &pin, FUNC &function) {
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::MOVABLE) {
      // create a mask for unassigning pin setting
      constexpr uint32_t mask = (0xFF << function.shift);
      regs()->PINASSIGN[function.index] = (regs()->PINASSIGN[function.index] | mask);
    }
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::FIXED) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      regs()->PINENABLE0 = regs()->PINENABLE0 | function.mask;
    }
  }

  /**
   * @brief Enable fixed pins in one go
   *
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void enableFixedPins(uint32_t pinMask) {
    regs()->PINENABLE0 = regs()->PINENABLE0 & ~pinMask;
  }

  /**
   * @brief Disable fixed pins in one go
   *
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void disableFixedPins(uint32_t pinMask) {
    regs()->PINENABLE0 = regs()->PINENABLE0 | pinMask;
  }
};
}  // namespace swm
}  // namespace sw
}  // namespace libMcuLL

#endif