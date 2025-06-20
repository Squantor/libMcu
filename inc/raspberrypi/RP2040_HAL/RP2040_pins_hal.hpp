/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_hal_pins.hpp
 * @brief RP2040 pins HAL class
 */
#ifndef RP2040_PINS_HAL_HPP
#define RP2040_PINS_HAL_HPP

namespace libmcuhal::pins {
namespace llpads = libmcull::pads;
/**
 * @brief
 */
enum class DriveModes : std::uint32_t {
  k2Ma = static_cast<std::uint32_t>(llpads::DriveModes::k2mA),   /*!< 2 milliampere drive strength */
  k4Ma = static_cast<std::uint32_t>(llpads::DriveModes::k4mA),   /*!< 4 milliampere drive strength */
  k8Ma = static_cast<std::uint32_t>(llpads::DriveModes::k8mA),   /*!< 8 milliampere drive strength */
  k12Ma = static_cast<std::uint32_t>(llpads::DriveModes::k12mA), /*!< 12 milliampere drive strength */
};
/**
 * @brief
 */
enum class PullModes : std::uint32_t {
  kNone = 0,                             /*!< No pullup modes */
  kPullUp = libmcuhw::pads::GPIO::PUE,   /*!< Pullup */
  kPullDown = libmcuhw::pads::GPIO::PDE, /*!< Pulldown */
  kKeeper = 0,                           /*!< No bus keeper on RP2040 */
};
/**
 * @brief
 */
enum class speedModes : std::uint32_t {
  KSlow = 0,                               /*!< Slow slew rate */
  kMedium = 0,                             /*!< Medium slew rate */
  kFast = libmcuhw::pads::GPIO::SLEWFAST,  /*!< fast slew rate */
  kSuper = libmcuhw::pads::GPIO::SLEWFAST, /*!< super fast slew rate */
};
/**
 * @brief
 * @tparam pads_bank0_address
 * @tparam gpio_bank0_address
 */
template <libmcu::PadsBank0BaseAddress const& pads_bank0_address, libmcu::IoBank0BaseAddress const& gpio_bank0_address>
struct Pins {
  /**
   * @brief Initialize the pins HAL
   */
  void Init() {}
  /**
   * @brief setup pin
   * @tparam T pin template parameter type
   * @param pin reference to pin type
   * @param drive drive mode to use
   * @param pull pull mode
   * @param slew slew rate
   * @param schmittOn enable shmitt trigger input
   */
  template <typename T>
  void Setup(T& pin, DriveModes drive, PullModes pull, speedModes slew, bool schmittOn) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      gpioBank0Peripheral()->GPIO[pin.pin_index].CTRL =
        libmcuhw::gpio_bank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.function_select));
      uint32_t setting = libmcuhw::pads::GPIO::IE | libmcuhw::pads::GPIO::DRIVE(static_cast<std::uint32_t>(drive)) |
                         static_cast<std::uint32_t>(pull) | static_cast<std::uint32_t>(slew);
      if (schmittOn)
        setting = setting | libmcuhw::pads::GPIO::SCHMITT;
      padsBank0Peripheral()->GPIO[pin.pin_index] = setting;
    } else
      static_assert(pin.port == libmcuhw::IoPorts::kQspi, "Does not support QSPI pins yet");
  }
  /**
   * @brief resets pin to reset defaults
   * @tparam T pin template parameter type
   * @param pin reference to pin
   */
  template <typename T>
  void Reset(T& pin) {
    gpioBank0Peripheral()->GPIO[pin.pin_index].CTRL = libmcuhw::gpio_bank0::CTRL::DEFAULT;
    padsBank0Peripheral()->GPIO[pin.pin_index] = libmcuhw::padsBank0::GPIO::DEFAULT;
  }

 private:
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralSet() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralClear() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralToggle() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::kPeripheralOffsetXor);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0Peripheral() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralSet() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralClear() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralToggle() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::kPeripheralOffsetXor);
  }

  static constexpr libmcu::HwAddressType padsBank0Address = pads_bank0_address; /*!< pads bank 0 peripheral address */
  static constexpr libmcu::HwAddressType ioBank0Address = gpio_bank0_address;   /*!< gpio bank 0 peripheral address */
};
}  // namespace libmcuhal::pins

#endif