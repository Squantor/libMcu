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
  Current2Ma = static_cast<std::uint32_t>(llpads::DriveModes::Current2mA),   /*!< 2 milliampere drive strength */
  Current4Ma = static_cast<std::uint32_t>(llpads::DriveModes::Current4mA),   /*!< 4 milliampere drive strength */
  Current8Ma = static_cast<std::uint32_t>(llpads::DriveModes::Current8mA),   /*!< 8 milliampere drive strength */
  Current12Ma = static_cast<std::uint32_t>(llpads::DriveModes::Current12mA), /*!< 12 milliampere drive strength */
};
/**
 * @brief
 */
enum class PullModes : std::uint32_t {
  None = 0,                             /*!< No pullup modes */
  PullUp = libmcuhw::pads::GPIO::PUE,   /*!< Pullup */
  PullDown = libmcuhw::pads::GPIO::PDE, /*!< Pulldown */
  Keeper = 0,                           /*!< No bus keeper on RP2040 */
};
/**
 * @brief
 */
enum class speedModes : std::uint32_t {
  Slow = 0,                               /*!< Slow slew rate */
  Medium = 0,                             /*!< Medium slew rate */
  Fast = libmcuhw::pads::GPIO::SLEWFAST,  /*!< fast slew rate */
  Super = libmcuhw::pads::GPIO::SLEWFAST, /*!< super fast slew rate */
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
    if constexpr (pin.port == libmcuhw::IoPorts::Port0) {
      gpioBank0Peripheral()->GPIO[pin.pin_index].CTRL =
        libmcuhw::gpio_bank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.function_select));
      uint32_t setting = libmcuhw::pads::GPIO::IE | libmcuhw::pads::GPIO::DRIVE(static_cast<std::uint32_t>(drive)) |
                         static_cast<std::uint32_t>(pull) | static_cast<std::uint32_t>(slew);
      if (schmittOn)
        setting = setting | libmcuhw::pads::GPIO::SCHMITT;
      padsBank0Peripheral()->GPIO[pin.pin_index] = setting;
    } else
      static_assert(pin.port == libmcuhw::IoPorts::Qspi, "Does not support QSPI pins yet");
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
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::PeripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralSet() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralClear() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_bank0::GpioBank0* gpioBank0PeripheralToggle() {
    return reinterpret_cast<libmcuhw::gpio_bank0::GpioBank0*>(ioBank0Address + libmcuhw::PeripheralOffsetXor);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0Peripheral() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::PeripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralSet() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralClear() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* padsBank0PeripheralToggle() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(padsBank0Address + libmcuhw::PeripheralOffsetXor);
  }

  static constexpr libmcu::HwAddressType padsBank0Address = pads_bank0_address; /*!< pads bank 0 peripheral address */
  static constexpr libmcu::HwAddressType ioBank0Address = gpio_bank0_address;   /*!< gpio bank 0 peripheral address */
};
}  // namespace libmcuhal::pins

#endif