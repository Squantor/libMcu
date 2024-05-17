/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 XOSC software interface
 */
#ifndef RP2040_XOSC_SW_HPP
#define RP2040_XOSC_SW_HPP

namespace libMcuLL ::sw::xosc {
using namespace libMcuLL;
template <libMcuLL::xoscBaseAddress const& xoscAddress_>
struct xosc : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief Starts the crystal oscillator
   *
   * Starts the crystal oscllator with the delay value with a given timeout value
   *
   * @param delay       delay value to set in XOSC
   * @param timeout     how many times to check if the status set
   * @return uint32_t   returns zero when timed out not zero of crystal oscillator is enabled
   */
  constexpr inline uint32_t start(uint32_t delay, uint32_t timeout) {
    uint32_t count = timeout;
    xoscPeripheral()->STARTUP = hw::xosc::STARTUP::DELAY(delay);
    xoscPeripheral()->CTRL = hw::xosc::CTRL::FREQ_15MHZ | hw::xosc::CTRL::ENABLE;
    while (0 == (xoscPeripheral()->STATUS & hw::xosc::STATUS::STABLE_MASK) && (count > 0))
      count--;
    return count;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::xosc::peripheral* xoscPeripheral() {
    return reinterpret_cast<hw::xosc::peripheral*>(xoscAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::xosc::peripheral* xoscPeripheralSet() {
    return reinterpret_cast<hw::xosc::peripheral*>(xoscAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::xosc::peripheral* xoscPeripheralClear() {
    return reinterpret_cast<hw::xosc::peripheral*>(xoscAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::xosc::peripheral* xoscPeripheralXor() {
    return reinterpret_cast<hw::xosc::peripheral*>(xoscAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType xoscAddress = xoscAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::xosc
#endif