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

namespace libMcuLL::pll {
namespace hardware = libMcuHw::pll;
/**
 * @brief
 * @tparam pllAddress_
 */
template <libMcu::pllBaseAddress const& pllAddress_>
struct pll : libMcu::peripheralBase {
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
    return reinterpret_cast<hardware::pll*>(pllAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheralClear() {
    return reinterpret_cast<hardware::pll*>(pllAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::pll* pllPeripheralXor() {
    return reinterpret_cast<hardware::pll*>(pllAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType pllAddress = pllAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::pll

#endif