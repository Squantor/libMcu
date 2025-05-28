/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pll_ll.hpp
 * @brief low level interface for the RP2040 PLL
 */
#ifndef RP2040_PLL_SW_HPP
#define RP2040_PLL_SW_HPP

namespace libmcull::pll {
namespace hardware = libmcuhw::pll;
/**
 * @brief
 * @tparam pllAddress_
 */
template <libmcu::pllBaseAddress const& pllAddress_>
struct pll : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  static inline uint32_t start(uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2, uint32_t timeout) {
    pllPeripheral()->PWR = hardware::PWR::VCOPD | hardware::PWR::POSTDIVPD | hardware::PWR::DSMPD | hardware::PWR::PD;
    pllPeripheral()->CS = hardware::CS::REFDIV(refDiv);
    pllPeripheral()->FBDIV_INT = fbDiv;
    pllPeripheral()->PRIM = hardware::PRIM::POSTDIV(postDiv1, postDiv2);
    pllPeripheralClear()->PWR = hardware::PWR::VCOPD | hardware::PWR::DSMPD | hardware::PWR::PD;

    while ((0 == (pllPeripheral()->CS & hardware::CS::LOCK_MASK)) && timeout > 0)
      timeout--;

    pllPeripheralClear()->PWR = hardware::PWR::POSTDIVPD;
    return timeout;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheral() {
    return reinterpret_cast<hardware::pll*>(pllAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheralSet() {
    return reinterpret_cast<hardware::pll*>(pllAddress + libmcuhw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheralClear() {
    return reinterpret_cast<hardware::pll*>(pllAddress + libmcuhw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheralXor() {
    return reinterpret_cast<hardware::pll*>(pllAddress + libmcuhw::peripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType pllAddress = pllAddress_; /*!< peripheral address */
};
}  // namespace libmcull::pll

#endif