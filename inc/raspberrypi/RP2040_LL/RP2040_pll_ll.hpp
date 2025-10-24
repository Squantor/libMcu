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
#ifndef RP2040_PLL_LL_HPP
#define RP2040_PLL_LL_HPP

namespace libmcull::pll {
namespace hardware = libmcuhw::pll;
/**
 * @brief
 * @tparam pllAddress_
 */
template <libmcu::PllBaseAddress const& pll_address>
struct Pll : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  static inline uint32_t start(uint32_t refDiv, uint32_t fbDiv, uint32_t postDiv1, uint32_t postDiv2, uint32_t timeout) {
    GetPeripheral()->PWR = hardware::PWR::VCOPD | hardware::PWR::POSTDIVPD | hardware::PWR::DSMPD | hardware::PWR::PD;
    GetPeripheral()->CS = hardware::CS::REFDIV(refDiv);
    GetPeripheral()->FBDIV_INT = fbDiv;
    GetPeripheral()->PRIM = hardware::PRIM::POSTDIV(postDiv1, postDiv2);
    GetPeripheralClear()->PWR = hardware::PWR::VCOPD | hardware::PWR::DSMPD | hardware::PWR::PD;

    while ((0 == (GetPeripheral()->CS & hardware::CS::LOCK_MASK)) && timeout > 0)
      timeout--;

    GetPeripheralClear()->PWR = hardware::PWR::POSTDIVPD;
    return timeout;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Pll* GetPeripheral() {
    return reinterpret_cast<hardware::Pll*>(pll_address_);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Pll* GetPeripheralSet() {
    return reinterpret_cast<hardware::Pll*>(pll_address_ + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Pll* GetPeripheralClear() {
    return reinterpret_cast<hardware::Pll*>(pll_address_ + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Pll* GetPeripheralXor() {
    return reinterpret_cast<hardware::Pll*>(pll_address_ + libmcuhw::PeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType pll_address_ = pll_address; /*!< peripheral address */
};
}  // namespace libmcull::pll

#endif