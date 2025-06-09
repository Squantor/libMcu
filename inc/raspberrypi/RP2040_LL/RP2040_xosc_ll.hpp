/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_xosc_ll.hpp
 * @brief low level interface for the RP2040 Crystal Oscillator
 */
#ifndef RP2040_XOSC_LL_HPP
#define RP2040_XOSC_LL_HPP

namespace libmcull::xosc {
namespace hardware = libmcuhw::xosc;
/**
 * @brief
 * @tparam xosc_address
 */
template <libmcu::XoscBaseAddress const& xosc_address>
struct Xosc : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void Init() {}
  /**
   * @brief Starts the crystal oscillator
   * Starts the crystal oscllator with the delay value with a given timeout value
   * @param delay       delay value to set in XOSC
   * @param timeout     how many times to check if the status set
   * @return uint32_t   returns zero when timed out not zero of crystal oscillator is enabled
   */
  constexpr inline uint32_t Start(uint32_t delay, uint32_t timeout) {
    uint32_t count = timeout;
    GetPeripheral()->STARTUP = hardware::STARTUP::DELAY(delay);
    GetPeripheral()->CTRL = hardware::CTRL::FREQ_15MHZ | hardware::CTRL::ENABLE;
    while (0 == (GetPeripheral()->STATUS & hardware::STATUS::STABLE_MASK) && (count > 0))
      count--;
    return count;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Xosc* GetPeripheral() {
    return reinterpret_cast<hardware::Xosc*>(xosc_address_);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Xosc* GetPeripheralSet() {
    return reinterpret_cast<hardware::Xosc*>(xosc_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Xosc* GetPeripheralClear() {
    return reinterpret_cast<hardware::Xosc*>(xosc_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Xosc* GetPeripheralXor() {
    return reinterpret_cast<hardware::Xosc*>(xosc_address_ + libmcuhw::kPeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType xosc_address_ = xosc_address; /*!< peripheral address */
};
}  // namespace libmcull::xosc
#endif