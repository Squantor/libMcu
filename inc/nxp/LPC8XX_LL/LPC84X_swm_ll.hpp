/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_swm_ll.hpp
 * @brief LPC84X series SWM interface class and definitions
 */
#ifndef LPC84X_SWM_LL_HPP
#define LPC84X_SWM_LL_HPP

namespace libmcull::swm {
namespace hardware = libmcuhw::swm;
template <libmcu::SwmBaseAddress swm_address>
struct Swm : libmcull::PeripheralBase {
  /**
   * @brief set pin to a function
   * @tparam PIN      pin to assign function
   * @tparam FUNC     function to assign to pin
   * @param pin       pin to assign function to
   * @param function  function to assign to pin
   */
  template <typename PIN, typename FUNC>
  constexpr void Setup(PIN &pin, FUNC &function) {
    if constexpr (FUNC::type == hardware::pinFunctionTypes::kMovable) {
      // create a mask for resetting the pin setting
      constexpr std::uint32_t mask = ~(0xFFu << function.shift);
      GetPeripheral()->PINASSIGNS[function.index] =
        (GetPeripheral()->PINASSIGNS[function.index] & mask) | (pin.pio << function.shift);
    } else if constexpr (FUNC::type == hardware::pinFunctionTypes::kFixed0) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 & ~function.mask;
    } else if constexpr (FUNC::type == hardware::pinFunctionTypes::kFixed1) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE1 = GetPeripheral()->PINENABLE1 & ~function.mask;
    }
  }
  /**
   * @brief clear pin from a function
   * @tparam PIN pin to clear the function of
   * @tparam FUNC function to disconnect
   * @param pin
   * @param function
   */
  template <typename PIN, typename FUNC>
  constexpr void Clear([[maybe_unused]] PIN &pin, FUNC &function) {
    if constexpr (FUNC::type == hardware::pinFunctionTypes::kMovable) {
      // create a mask for unassigning pin setting
      constexpr std::uint32_t mask = (0xFFu << function.shift);
      GetPeripheral()->PINASSIGNS[function.index] = (GetPeripheral()->PINASSIGNS[function.index] | mask);
    } else if constexpr (FUNC::type == hardware::pinFunctionTypes::kFixed0) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 | function.mask;
    } else if constexpr (FUNC::type == hardware::pinFunctionTypes::kFixed1) {
      static_assert(PIN::pio == FUNC::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE1 = GetPeripheral()->PINENABLE1 | function.mask;
    }
  }
  /**
   * @brief Enable fixed pins in one go
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void EnableFixedPins(std::uint32_t pinMask) {
    GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 & ~pinMask;
  }
  /**
   * @brief Disable fixed pins in one go
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void DisableFixedPins(std::uint32_t pinMask) {
    GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 | pinMask;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to registers
   */
  constexpr hardware::Swm *GetPeripheral() {
    return reinterpret_cast<hardware::Swm *>(swm_address_);
  }

 private:
  static constexpr libmcu::HwAddressType swm_address_ = swm_address; /*!< peripheral address */
};
}  // namespace libmcull::swm
#endif