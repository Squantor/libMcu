/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_hal_gpio.hpp
 * @brief HAL library for RP2040 GPIO
 */
#ifndef RP2040_HAL_GPIO
#define RP2040_HAL_GPIO

namespace libmcuhal::gpio {
namespace llpads = libmcull::pads;
namespace llgpio = libmcull::sio_gpio;
/**
 * @brief Gpio pull modes
 */
enum class PullModes : std::uint32_t {
  kNone = static_cast<std::uint32_t>(llpads::PullModes::kNone),         /*!< No pullup modes */
  kPullUp = static_cast<std::uint32_t>(llpads::PullModes::kPullUp),     /*!< Pullup */
  kPullDown = static_cast<std::uint32_t>(llpads::PullModes::kPullDown), /*!< Pulldown */
};
/**
 * @brief
 * @todo concepts for low level arguments
 * @tparam pads_lowlevel
 * @tparam gpio_lowlevel
 */
template <auto& pads_lowlevel, auto& gpio_lowlevel>
struct Gpio : libmcuhal::HalGpioBase {
  /**
   * @brief Initialize the gpio HAL
   */
  void Init() {}
  /**
   * @brief Set gpio pin to input mode with pullup or pulldown
   * @tparam PIN pin instance
   * @param pin pin instance
   * @param pull_mode pullup/down mode to use
   */
  template <typename PIN>
  constexpr void Setup(PIN& pin, PullModes pull_mode) {
    gpio_lowlevel.SetInput(pin);
    pads_lowlevel.Setup(pin, static_cast<llpads::PullModes>(pull_mode));
  }
  template <typename PIN>
  constexpr bool Get(PIN& pin) {
    return gpio_lowlevel.GetLevel(pin);
  }
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  /*   template <typename PIN>
    constexpr void SetOutput(PIN& pin) {
      if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
        GetSioPeripheral()->GPIO_OE_SET = pin.pin_mask;
      } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
        GetSioPeripheral()->GPIO_HI_OE_SET = pin.pin_mask;
      } else {
        static_assert("Unknown port!");
      }
    } */
 private:
};
}  // namespace libmcuhal::gpio

#endif