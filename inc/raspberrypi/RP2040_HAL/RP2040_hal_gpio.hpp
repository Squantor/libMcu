/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 gpio HAL
 */
#ifndef RP2040_HAL_GPIO
#define RP2040_HAL_GPIO

namespace libMcuHal::gpio {

enum class pullModes : std::uint32_t {
  NONE = 0,                             /**< No pullup modes */
  PULLUP = libMcuHw::pads::GPIO::PUE,   /**< Pullup */
  PULLDOWN = libMcuHw::pads::GPIO::PDE, /**< Pulldown */
  KEEPER = 0,                           /**< No bus keeper on RP2040 */
};

template <libMcu::padsBank0BaseAddress const& padsBank0Address_, libMcu::ioBank0BaseAddress const& gpioBank0Address_,
          libMcu::sioBaseAddress const& sioAddress_>
struct gpio : libMcuHal::halGpioBase {
  /**
   * @brief Initialize the gpio HAL
   */
  void initialize() {}
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void output(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_OE_SET = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_HI_OE_SET = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Set gpio pin to input mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void input(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_OE_CLR = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_HI_OE_CLR = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Set gpio pin to high
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void high(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_HI_OUT_SET = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Set gpio pin to low
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void low(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_HI_OUT_CLR = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Toggle gpio pin
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void toggle(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_XOR = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      sioPeripheral()->GPIO_HI_OUT_XOR = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Set the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @param setting pin state, 0 for low, 1 for high
   */
  template <typename PIN>
  constexpr void set(PIN& pin, std::uint32_t setting) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      if (setting)
        sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
      else
        sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      if (setting)
        sioPeripheral()->GPIO_HI_OUT_SET = pin.pinMask;
      else
        sioPeripheral()->GPIO_HI_OUT_CLR = pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief Get the gpio pin state
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   * @return std::uint32_t pin state, 0 for low, non zero for high
   */
  template <typename PIN>
  constexpr std::uint32_t get(PIN& pin) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      return sioPeripheral()->GPIO_IN & pin.pinMask;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      return sioPeripheral()->GPIO_HI_IN & pin.pinMask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief setup pin
   *
   * @tparam T pin template parameter type
   * @param pull pull mode
   */
  template <typename T>
  void pullmode(T& pin, pullModes pull) {
    if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      uint32_t setting = padsBank0Peripheral()->GPIO[pin.pinIndex] & ~(libMcuHw::pads::GPIO::PDE | libMcuHw::pads::GPIO::PUE);
      setting = setting | static_cast<std::uint32_t>(pull);
      padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
    } else if constexpr (pin.port == libMcuHw::IOports::PORT0) {
      static_assert(pin.port == libMcuHw::IOports::QSPI, "Does not support QSPI pins yet");
    } else {
      static_assert("Unknown port!");
    }
  }

 private:
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
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::sio::sio* sioPeripheral() {
    return reinterpret_cast<libMcuHw::sio::sio*>(sioAddress + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::sio::sio* sioPeripheralSet() {
    return reinterpret_cast<libMcuHw::sio::sio*>(sioAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::sio::sio* sioPeripheralClear() {
    return reinterpret_cast<libMcuHw::sio::sio*>(sioAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::sio::sio* sioPeripheralToggle() {
    return reinterpret_cast<libMcuHw::sio::sio*>(sioAddress + libMcuHw::peripheralOffsetXor);
  }

  static constexpr libMcu::hwAddressType padsBank0Address = padsBank0Address_; /**< pads bank 0 peripheral address */
  static constexpr libMcu::hwAddressType sioAddress = sioAddress_;             /**< SIO peripheral address*/
};
}  // namespace libMcuHal::gpio

#endif