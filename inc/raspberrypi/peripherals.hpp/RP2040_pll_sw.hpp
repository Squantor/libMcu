/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PLL software interface
 */
#ifndef RP2040_PLL_SW_HPP
#define RP2040_PLL_SW_HPP

namespace libMcuLL::sw::pll {
using namespace libMcuLL;
template <libMcuLL::pllBaseAddress const& pllAddress_>
struct pll : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  static inline uint32_t start(uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2, uint32_t timeout) {
    pllPeripheral()->PWR = hw::pll::PWR::VCOPD | hw::pll::PWR::POSTDIVPD | hw::pll::PWR::DSMPD | hw::pll::PWR::PD;
    pllPeripheral()->CS = hw::pll::CS::REFDIV(refDiv);
    pllPeripheral()->FBDIV_INT = fbDiv;
    pllPeripheral()->PRIM = hw::pll::PRIM::POSTDIV(postDiv1, postDiv2);
    pllPeripheralClear()->PWR = hw::pll::PWR::VCOPD | hw::pll::PWR::DSMPD | hw::pll::PWR::PD;

    while ((0 == (pllPeripheral()->CS & hw::pll::CS::LOCK_MASK)) && timeout > 0)
      timeout--;

    pllPeripheralClear()->PWR = hw::pll::PWR::POSTDIVPD;
    return timeout;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hw::pll::peripheral* pllPeripheral() {
    return reinterpret_cast<hw::pll::peripheral*>(pllAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::pll::peripheral* pllPeripheralSet() {
    return reinterpret_cast<hw::pll::peripheral*>(pllAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::pll::peripheral* pllPeripheralClear() {
    return reinterpret_cast<hw::pll::peripheral*>(pllAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::pll::peripheral* pllPeripheralXor() {
    return reinterpret_cast<hw::pll::peripheral*>(pllAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType pllAddress = pllAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::pll

#endif