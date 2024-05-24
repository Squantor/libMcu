/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series SWM functions
 */
#ifndef LPC84X_SWM_HPP
#define LPC84X_SWM_HPP

namespace libMcuLL::sw::swm {
using namespace hw::swm;
template <libMcuLL::SWMbaseAddress swmAddress_>
struct swm : libMcuLL::peripheralBase {
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
      constexpr std::uint32_t mask = ~(0xFFu << function.shift);
      swmPeripheral()->PINASSIGN[function.index] =
        (swmPeripheral()->PINASSIGN[function.index] & mask) | (pin.pio << function.shift);
    }
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::FIXED) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      swmPeripheral()->PINENABLE0 = swmPeripheral()->PINENABLE0 & ~function.mask;
    }
  }

  template <typename PIN, typename FUNC>
  constexpr void clear([[maybe_unused]] PIN &pin, FUNC &function) {
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::MOVABLE) {
      // create a mask for unassigning pin setting
      constexpr std::uint32_t mask = (0xFFu << function.shift);
      swmPeripheral()->PINASSIGN[function.index] = (swmPeripheral()->PINASSIGN[function.index] | mask);
    }
    if constexpr (FUNC::type == hw::swm::pinFunctionTypes::FIXED) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      swmPeripheral()->PINENABLE0 = swmPeripheral()->PINENABLE0 | function.mask;
    }
  }

  /**
   * @brief Enable fixed pins in one go
   *
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void enableFixedPins(std::uint32_t pinMask) {
    swmPeripheral()->PINENABLE0 = swmPeripheral()->PINENABLE0 & ~pinMask;
  }

  /**
   * @brief Disable fixed pins in one go
   *
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void disableFixedPins(std::uint32_t pinMask) {
    swmPeripheral()->PINENABLE0 = swmPeripheral()->PINENABLE0 | pinMask;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to registers
   */
  constexpr hw::swm::peripheral *swmPeripheral() {
    return reinterpret_cast<hw::swm::peripheral *>(swmAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType swmAddress = swmAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::swm
#endif