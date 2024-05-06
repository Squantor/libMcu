/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pin HAL
 */
#ifndef RP2040_PINS
#define RP2040_PINS

namespace libMcuHal {
namespace pins {
using namespace libMcuLL;
enum class driveModes : std::uint32_t {
  DRIVE_2MA = hw::pads::GPIO::DRIVE_2MA,   /**< 2 milliampere drive strength */
  DRIVE_4MA = hw::pads::GPIO::DRIVE_4MA,   /**< 4 milliampere drive strength */
  DRIVE_8MA = hw::pads::GPIO::DRIVE_8MA,   /**< 8 milliampere drive strength */
  DRIVE_12MA = hw::pads::GPIO::DRIVE_12MA, /**< 12 milliampere drive strength */
};

enum class pullModes : std::uint32_t {
  NONE = 0,                       /**< No pullup modes */
  PULLUP = hw::pads::GPIO::PUE,   /**< Pullup */
  PULLDOWN = hw::pads::GPIO::PDE, /**< Pulldown */
  KEEPER = 0,                     /**< No bus keeper on RP2040 */
};

enum class speedModes : std::uint32_t {
  SLEW_SLOW = 0,                         /**< Slow slew rate */
  SLEW_MEDIUM = 0,                       /**< Medium slew rate */
  SLEW_FAST = hw::pads::GPIO::SLEWFAST,  /**< fast slew rate */
  SLEW_SUPER = hw::pads::GPIO::SLEWFAST, /**< super fast slew rate */
};

template <padsBank0BaseAddress const& padsBank0Address_, ioBank0BaseAddress const& gpioBank0Address_>
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      gpioBank0Peripheral()->GPIO[pin.pinIndex].CTRL = hw::gpioBank0::CTRL::FUNCSEL(static_cast<std::uint32_t>(pin.functionSelect));
      uint32_t setting = hw::pads::GPIO::IE | hw::pads::GPIO::DRIVE(static_cast<std::uint32_t>(drive)) |
                         static_cast<std::uint32_t>(pull) | static_cast<std::uint32_t>(slew);
      if (schmittOn)
        setting = setting | hw::pads::GPIO::SCHMITT;
      padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
    } else
      static_assert(pin.port == hw::IOports::QSPI, "Does not support QSPI pins yet");
  }
  /**
   * @brief resets pin to reset defaults
   *
   * @tparam T pin template parameter type
   * @param pin reference to pin
   */
  template <typename T>
  void reset(T& pin) {
    gpioBank0Peripheral()->GPIO[pin.pinIndex].CTRL = hw::gpioBank0::CTRL::DEFAULT;
    padsBank0Peripheral()->GPIO[pin.pinIndex] = hw::padsBank0::GPIO::DEFAULT;
  }

 private:
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0Peripheral() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(ioBank0Address + libMcuLL::hw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralSet() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(ioBank0Address + libMcuLL::hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralClear() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(ioBank0Address + libMcuLL::hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralToggle() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(ioBank0Address + libMcuLL::hw::peripheralOffsetXor);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::padsBank0::peripheral* padsBank0Peripheral() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address + libMcuLL::hw::peripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::padsBank0::peripheral* padsBank0PeripheralSet() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address + libMcuLL::hw::peripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::padsBank0::peripheral* padsBank0PeripheralClear() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address + libMcuLL::hw::peripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::padsBank0::peripheral* padsBank0PeripheralToggle() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address + libMcuLL::hw::peripheralOffsetXor);
  }

  static constexpr hwAddressType padsBank0Address = padsBank0Address_; /**< pads bank 0 peripheral address */
  static constexpr hwAddressType ioBank0Address = gpioBank0Address_;   /**< gpio bank 0 peripheral address */
};
}  // namespace pins
}  // namespace libMcuHal

#endif