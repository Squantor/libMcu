/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_gpio_bank0_ll.hpp
 * @brief low level interface for the RP2040 GPIO bank 0
 */
#ifndef RP2040_GPIO_BANK0_LL_HPP
#define RP2040_GPIO_BANK0_LL_HPP

namespace libmcull::gpioBank0 {
namespace hardware = libmcuhw::gpio_bank0;
/**
 * @brief
 * @tparam gpio_bank0_address
 */
template <libmcu::IoBank0BaseAddress const& gpio_bank0_address>
struct GpioBank0 : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void Setup(PIN& pin) {
    GetPeripheral()->GPIO[pin.pin_index].CTRL =
      libmcuhw::gpio_bank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.function_select));
  }
  // TODO: Make setup method with overrides
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* GetPeripheral() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(gpio_bank0_address_);
  }

 private:
  static constexpr libmcu::HwAddressType gpio_bank0_address_ = gpio_bank0_address; /*!< peripheral address */
};
}  // namespace libmcull::gpioBank0
#endif