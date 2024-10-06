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
template <libMcu::pllBaseAddress const& pllAddress_>
struct pll : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  static inline uint32_t start(uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2, uint32_t timeout) {
    pllPeripheral()->PWR =
      libMcuHw::pll::PWR::VCOPD | libMcuHw::pll::PWR::POSTDIVPD | libMcuHw::pll::PWR::DSMPD | libMcuHw::pll::PWR::PD;
    pllPeripheral()->CS = libMcuHw::pll::CS::REFDIV(refDiv);
    pllPeripheral()->FBDIV_INT = fbDiv;
    pllPeripheral()->PRIM = libMcuHw::pll::PRIM::POSTDIV(postDiv1, postDiv2);
    pllPeripheralClear()->PWR = libMcuHw::pll::PWR::VCOPD | libMcuHw::pll::PWR::DSMPD | libMcuHw::pll::PWR::PD;

    while ((0 == (pllPeripheral()->CS & libMcuHw::pll::CS::LOCK_MASK)) && timeout > 0)
      timeout--;

    pllPeripheralClear()->PWR = libMcuHw::pll::PWR::POSTDIVPD;
    return timeout;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libMcuHw::pll::peripheral* pllPeripheral() {
    return reinterpret_cast<libMcuHw::pll::peripheral*>(pllAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static libMcuHw::pll::peripheral* pllPeripheralSet() {
    return reinterpret_cast<libMcuHw::pll::peripheral*>(pllAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static libMcuHw::pll::peripheral* pllPeripheralClear() {
    return reinterpret_cast<libMcuHw::pll::peripheral*>(pllAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static libMcuHw::pll::peripheral* pllPeripheralXor() {
    return reinterpret_cast<libMcuHw::pll::peripheral*>(pllAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType pllAddress = pllAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::pll

#endif