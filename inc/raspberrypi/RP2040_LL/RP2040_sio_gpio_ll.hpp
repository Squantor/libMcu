/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_sio_gpio_ll.hpp
 * @brief low level interface for the RP2040 SIO GPIO
 */
#ifndef RP2040_SIO_GPIO_LL_HPP
#define RP2040_SIO_GPIO_LL_HPP

namespace libmcull::sio_gpio {
namespace hardware = libmcuhw::sio;
/**
 * @brief
 * @tparam &sio_address
 */
template <libmcu::SioBaseAddress const &sio_address>
struct SioGpio : libmcull::GpioBase {
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetOutput(PIN &pin) {
    GetPeripheral()->GPIO_OE_SET = pin.pin_mask;
  }
  /**
   * @brief Set gpio pin to input mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetInput(PIN &pin) {
    GetPeripheral()->GPIO_OE_CLR = pin.pin_mask;
  }
  /**
   * @brief Set gpio pin to high
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetHigh(PIN &pin) {
    GetPeripheral()->GPIO_OUT_SET = pin.pin_mask;
  }
  /**
   * @brief Set gpio pin to low
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetLow(PIN &pin) {
    GetPeripheral()->GPIO_OUT_CLR = pin.pin_mask;
  }
  /**
   * @brief Toggle gpio pin
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void Toggle(PIN &pin) {
    GetPeripheral()->GPIO_OUT_XOR = pin.pin_mask;
  }
  /**
   * @brief Get the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, non zero for high
   */
  template <typename PIN>
  constexpr std::uint32_t GetLevel(PIN &pin) {
    return GetPeripheral()->GPIO_IN & pin.pin_mask;
  }
  /**
   * @brief Set the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, non zero for high
   */
  template <typename PIN>
  constexpr void SetLevel(PIN &pin, std::uint32_t setting) {
    if (setting)
      GetPeripheral()->GPIO_OUT_SET = pin.pin_mask;
    else
      GetPeripheral()->GPIO_OUT_CLR = pin.pin_mask;
  }
  /**
   * @brief get registers from peripheral for normal access
   * @return return pointer to peripheral
   */
  static hardware::Sio *GetPeripheral() {
    return reinterpret_cast<hardware::Sio *>(sio_address_ + libmcuhw::kPeripheralOffsetNormal);
  }

 private:
  static constexpr libmcu::HwAddressType sio_address_{sio_address}; /*!< peripheral address */
};
}  // namespace libmcull::sio_gpio
#endif