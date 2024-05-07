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

template <padsBank0BaseAddress const& padsBank0Address_, ioBank0BaseAddress const& gpioBank0Address_,
          sioBaseAddress const& sioAddress_>
struct gpio {
  /**
   * @brief Initialize the gpio HAL
   */
  void initialize() {}

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
  static constexpr hwAddressType ioBank0Address = gpioBank0Address_;   /**< gpio bank 0 peripheral address */
  static constexpr hwAddressType sioAddress = sioAddress_;             /**< SIO peripheral address*/
};
}  // namespace libMcuHal::gpio

#endif