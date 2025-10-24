/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_swm_ll.hpp
 * @brief LPC810 series SWM interface class and definitions
 */
#ifndef LPC81X_SWM_HPP
#define LPC81X_SWM_HPP

namespace libmcull::swm {
namespace hardware = libmcuhw::swm;
/**
 * @brief Switch matrix low level interface
 * @tparam swm_address
 */
template <libmcu::SwmBaseAddress swm_address>
struct Swm : libmcull::LowLevelBase {
  /**
   * @brief set pin to a function
   * @tparam Pin      pin to assign function
   * @tparam Func     function to assign to pin
   * @param pin       pin to assign function to
   * @param function  function to assign to pin
   */
  template <typename Pin, typename Func>
  constexpr void setup(Pin &pin, Func &function) {
    if constexpr (Func::type == libmcuhw::swm::pinFunctionTypes::Movable) {
      // create a mask for resetting the pin setting
      constexpr std::uint32_t mask = ~(0xFFu << function.shift);
      GetPeripheral()->PINASSIGN[function.index] =
        (GetPeripheral()->PINASSIGN[function.index] & mask) | (pin.pio << function.shift);
    }
    if constexpr (Func::type == libmcuhw::swm::pinFunctionTypes::Fixed) {
      static_assert(Pin::pio == Func::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 & ~function.mask;
    }
  }
  /**
   * @brief clear pin from a function
   * @todo implement as this seems strange you pass a pin function here while you should clear it
   * @tparam Pin pin to clear
   * @tparam Func
   * @param pin pin to clear function of
   * @param function strange that this needs to be passed? revisit
   */
  template <typename Pin, typename Func>
  constexpr void clear([[maybe_unused]] Pin &pin, Func &function) {
    if constexpr (Func::type == libmcuhw::swm::pinFunctionTypes::Movable) {
      // create a mask for unassigning pin setting
      constexpr std::uint32_t mask = (0xFFu << function.shift);
      GetPeripheral()->PINASSIGN[function.index] = (GetPeripheral()->PINASSIGN[function.index] | mask);
    }
    if constexpr (Func::type == libmcuhw::swm::pinFunctionTypes::Fixed) {
      static_assert(Pin::pio == Func::pio, "this function is not available on this pin!");
      GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 | function.mask;
    }
  }

  /**
   * @brief Enable fixed pins in one go
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void enableFixedPins(std::uint32_t pinMask) {
    GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 & ~pinMask;
  }

  /**
   * @brief Disable fixed pins in one go
   * @param pinMask bit pattern of fixed functions
   */
  constexpr void disableFixedPins(std::uint32_t pinMask) {
    GetPeripheral()->PINENABLE0 = GetPeripheral()->PINENABLE0 | pinMask;
  }

 private:
  /**
   * @brief get registers from peripheral
   * @return return pointer to registers
   */
  constexpr libmcuhw::swm::Swm *GetPeripheral() {
    return reinterpret_cast<libmcuhw::swm::Swm *>(swm_address_);
  }
  static constexpr libmcu::HwAddressType swm_address_ = swm_address; /*!< peripheral address */
};
}  // namespace libmcull::swm
#endif