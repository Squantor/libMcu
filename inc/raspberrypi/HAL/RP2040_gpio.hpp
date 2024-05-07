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
using namespace libMcuLL;

enum class pullModes : std::uint32_t {
  NONE = 0,                       /**< No pullup modes */
  PULLUP = hw::pads::GPIO::PUE,   /**< Pullup */
  PULLDOWN = hw::pads::GPIO::PDE, /**< Pulldown */
  KEEPER = 0,                     /**< No bus keeper on RP2040 */
};

template <padsBank0BaseAddress const& padsBank0Address_, ioBank0BaseAddress const& gpioBank0Address_,
          sioBaseAddress const& sioAddress_>
struct gpio {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      sioPeripheral()->GPIO_OE_SET = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      sioPeripheral()->GPIO_OE_CLR = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      sioPeripheral()->GPIO_OUT_XOR = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      if (setting)
        sioPeripheral()->GPIO_OUT_SET = pin.pinMask;
      else
        sioPeripheral()->GPIO_OUT_CLR = pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      return sioPeripheral()->GPIO_IN & pin.pinMask;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
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
    if constexpr (pin.port == hw::IOports::PORT0) {
      uint32_t setting = padsBank0Peripheral()->GPIO[pin.pinIndex] & ~(hw::pads::GPIO::PDE | hw::pads::GPIO::PUE);
      setting = setting | static_cast<std::uint32_t>(pull);
      padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
    } else if constexpr (pin.port == hw::IOports::PORT0) {
      static_assert(pin.port == hw::IOports::QSPI, "Does not support QSPI pins yet");
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
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::sio::peripheral* sioPeripheral() {
    return reinterpret_cast<hw::sio::peripheral*>(sioAddress + libMcuLL::hw::peripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::sio::peripheral* sioPeripheralSet() {
    return reinterpret_cast<hw::sio::peripheral*>(sioAddress + libMcuLL::hw::peripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::sio::peripheral* sioPeripheralClear() {
    return reinterpret_cast<hw::sio::peripheral*>(sioAddress + libMcuLL::hw::peripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::sio::peripheral* sioPeripheralToggle() {
    return reinterpret_cast<hw::sio::peripheral*>(sioAddress + libMcuLL::hw::peripheralOffsetXor);
  }

  static constexpr hwAddressType padsBank0Address = padsBank0Address_; /**< pads bank 0 peripheral address */
  static constexpr hwAddressType sioAddress = sioAddress_;             /**< SIO peripheral address*/
};
}  // namespace libMcuHal::gpio

#endif