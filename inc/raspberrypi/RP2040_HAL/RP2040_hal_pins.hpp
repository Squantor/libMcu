/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pin HAL
 */
#ifndef RP2040_HAL_PINS
#define RP2040_HAL_PINS

namespace libMcuHal {
namespace pins {
enum class driveModes : std::uint32_t {
  DRIVE_2MA = libMcuHw::pads::GPIO::DRIVE_2MA,   /**< 2 milliampere drive strength */
  DRIVE_4MA = libMcuHw::pads::GPIO::DRIVE_4MA,   /**< 4 milliampere drive strength */
  DRIVE_8MA = libMcuHw::pads::GPIO::DRIVE_8MA,   /**< 8 milliampere drive strength */
  DRIVE_12MA = libMcuHw::pads::GPIO::DRIVE_12MA, /**< 12 milliampere drive strength */
};

enum class pullModes : std::uint32_t {
  NONE = 0,                             /**< No pullup modes */
  PULLUP = libMcuHw::pads::GPIO::PUE,   /**< Pullup */
  PULLDOWN = libMcuHw::pads::GPIO::PDE, /**< Pulldown */
  KEEPER = 0,                           /**< No bus keeper on RP2040 */
};

enum class speedModes : std::uint32_t {
  SLEW_SLOW = 0,                               /**< Slow slew rate */
  SLEW_MEDIUM = 0,                             /**< Medium slew rate */
  SLEW_FAST = libMcuHw::pads::GPIO::SLEWFAST,  /**< fast slew rate */
  SLEW_SUPER = libMcuHw::pads::GPIO::SLEWFAST, /**< super fast slew rate */
};

template <libMcu::padsBank0BaseAddress const& padsBank0Address_, libMcu::ioBank0BaseAddress const& gpioBank0Address_>
struct pins {
  /**
   * @brief Initialize the pins HAL
   */
  void initialize() {}

  /**
   * @brief setup pin
   *
   * @tparam T pin template parameter type
   * @param pin reference to pin type
   * @param drive drive mode to use
   * @param pull pull mode
   * @param slew slew rate
   * @param schmittOn enable shmitt trigger input
   */
  template <typename T>
  void setup(T& pin, driveModes drive, pullModes pull, speedModes slew, bool schmittOn) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      gpioBank0Peripheral()->GPIO[pin.pinIndex].CTRL =
        libMcuHw::gpioBank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.functionSelect));
      uint32_t setting = libMcuHw::pads::GPIO::IE | libMcuHw::pads::GPIO::DRIVE(static_cast<std::uint32_t>(drive)) |
                         static_cast<std::uint32_t>(pull) | static_cast<std::uint32_t>(slew);
      if (schmittOn)
        setting = setting | libMcuHw::pads::GPIO::SCHMITT;
      padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
    } else
      static_assert(pin.port == libMcuHw::IOports::QSPI, "Does not support QSPI pins yet");
  }
  /**
   * @brief resets pin to reset defaults
   *
   * @tparam T pin template parameter type
   * @param pin reference to pin
   */
  template <typename T>
  void reset(T& pin) {
    gpioBank0Peripheral()->GPIO[pin.pinIndex].CTRL = libMcuHw::gpioBank0::CTRL::DEFAULT;
    padsBank0Peripheral()->GPIO[pin.pinIndex] = libMcuHw::padsBank0::GPIO::DEFAULT;
  }

 private:
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(ioBank0Address + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralSet() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(ioBank0Address + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralClear() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(ioBank0Address + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralToggle() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(ioBank0Address + libMcuHw::peripheralOffsetXor);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::padsBank0::padsBank0* padsBank0Peripheral() {
    return reinterpret_cast<libMcuHw::padsBank0::padsBank0*>(padsBank0Address + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::padsBank0::padsBank0* padsBank0PeripheralSet() {
    return reinterpret_cast<libMcuHw::padsBank0::padsBank0*>(padsBank0Address + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::padsBank0::padsBank0* padsBank0PeripheralClear() {
    return reinterpret_cast<libMcuHw::padsBank0::padsBank0*>(padsBank0Address + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::padsBank0::padsBank0* padsBank0PeripheralToggle() {
    return reinterpret_cast<libMcuHw::padsBank0::padsBank0*>(padsBank0Address + libMcuHw::peripheralOffsetXor);
  }

  static constexpr libMcu::hwAddressType padsBank0Address = padsBank0Address_; /**< pads bank 0 peripheral address */
  static constexpr libMcu::hwAddressType ioBank0Address = gpioBank0Address_;   /**< gpio bank 0 peripheral address */
};
}  // namespace pins
}  // namespace libMcuHal

#endif