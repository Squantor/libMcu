/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SIO GPIO software interface
 */
#ifndef RP2040_SIO_GPIO_SW_HPP
#define RP2040_SIO_GPIO_SW_HPP

namespace libMcuLL::sioGpio {
template <libMcu::sioBaseAddress const &sioAddress_>
struct sioGpio : libMcu::peripheralBase {
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void output(PIN &pin) {
    sioPeripheral()->GPIO_OE_SET = pin.pinMask;
  }
  /**
   * @brief Set gpio pin to input mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void input(PIN &pin) {
    sioPeripheral()->GPIO_OE_CLR = pin.pinMask;
  }
  /**
   * @brief Set gpio pin to high
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void high(PIN &pin) {
    sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
  }
  /**
   * @brief Set gpio pin to low
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void low(PIN &pin) {
    sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
  }
  /**
   * @brief Toggle gpio pin
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void toggle(PIN &pin) {
    sioPeripheral()->GPIO_OUT_XOR = pin.pinMask;
  }
  /**
   * @brief Get the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, non zero for high
   */
  template <typename PIN>
  constexpr std::uint32_t get(PIN &pin) {
    return sioPeripheral()->GPIO_IN & pin.pinMask;
  }
  /**
   * @brief Set the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  constexpr void set(PIN &pin, std::uint32_t setting) {
    if (setting)
      sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
    else
      sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
  }
  /**
   * @brief get registers from peripheral for normal access
   * @return return pointer to peripheral
   */
  static libMcuHw::sio::peripheral *sioPeripheral() {
    return reinterpret_cast<libMcuHw::sio::peripheral *>(sioAddress + libMcuHw::peripheralOffsetNormal);
  }

 private:
  static constexpr libMcu::hwAddressType sioAddress{sioAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sioGpio
#endif