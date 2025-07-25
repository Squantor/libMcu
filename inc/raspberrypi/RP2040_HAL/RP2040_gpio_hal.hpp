/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_hal_gpio.hpp
 * @brief RP2040 GPIO HAL class
 */
#ifndef RP2040_GPIO_HAL_HPP
#define RP2040_GPIO_HAL_HPP

namespace libmcuhal::gpio {
namespace llpads = libmcull::pads;
namespace llgpio = libmcull::sio_gpio;
/**
 * @brief Gpio pull modes
 */
enum class PullModes : std::uint32_t {
  None = static_cast<std::uint32_t>(llpads::PullModes::None),         /*!< No pullup modes */
  PullUp = static_cast<std::uint32_t>(llpads::PullModes::PullUp),     /*!< Pullup */
  PullDown = static_cast<std::uint32_t>(llpads::PullModes::PullDown), /*!< Pulldown */
};
/**
 * @brief
 * @todo concepts for low level arguments
 * @tparam pads_lowlevel
 * @tparam gpio_lowlevel
 */
template <libmcull::DerivedFromPads auto& pads_lowlevel, libmcull::DerivedFromGpio auto& gpio_lowlevel>
struct Gpio : libmcuhal::GpioBase {
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
  constexpr void SetupInput(PIN& pin, PullModes pull_mode = PullModes::None) {
    gpio_lowlevel.SetInput(pin);
    pads_lowlevel.Setup(pin, static_cast<llpads::PullModes>(pull_mode));
  }
  /**
   * @brief Set gpio pin to output mode with defined level
   * @tparam PIN pin instance
   * @param pin pin instance
   * @param level output level, zero for low, non zero for high
   */
  template <typename PIN>
  constexpr void SetupOutput(PIN& pin, std::uint32_t level) {
    gpio_lowlevel.SetLevel(pin, level);
    gpio_lowlevel.SetOutput(pin);
  }
  /**
   * @brief Set gpio pin
   * @tparam PIN pin instance
   * @param pin pin instance
   * @param level output level, zero for low, non zero for high
   */
  template <typename PIN>
  constexpr void SetLevel(PIN& pin, std::uint32_t level) {
    gpio_lowlevel.SetLevel(pin, level);
  }
  /**
   * @brief Get gpio pin level
   * @tparam PIN pin instance
   * @param pin pin instance
   * @returns zero for low, non zero for high
   */
  template <typename PIN>
  constexpr std::uint32_t GetLevel(PIN& pin) {
    return gpio_lowlevel.GetLevel(pin);
  }

 private:
};
}  // namespace libmcuhal::gpio

#endif