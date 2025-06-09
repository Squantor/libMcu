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
/**
 * @brief Gpio pull modes
 */
enum class PullModes : std::uint32_t {
  kNone = 0,                             /*!< No pullup modes */
  kPullUp = libmcuhw::pads::GPIO::PUE,   /*!< Pullup */
  kPullDown = libmcuhw::pads::GPIO::PDE, /*!< Pulldown */
  kKeeper = 0,                           /*!< No bus keeper on RP2040 */
};
/**
 * @brief
 * @tparam pads_bank0_address
 * @tparam gpio_bank0_address
 * @tparam sio_address
 */
template <libmcu::PadsBank0BaseAddress const& pads_bank0_address, libmcu::IoBank0BaseAddress const& gpio_bank0_address,
          libmcu::SioBaseAddress const& sio_address>
struct Gpio : libmcuhal::HalGpioBase {
  /**
   * @brief Initialize the gpio HAL
   */
  void Init() {}
  /**
   * @brief Set gpio pin to output mode
   * @tparam PIN pin instance
   * @param pin reference to pin instance
   */
  template <typename PIN>
  constexpr void SetOutput(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_OE_SET = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_HI_OE_SET = pin.pin_mask;
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
  constexpr void SetInput(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_OE_CLR = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_HI_OE_CLR = pin.pin_mask;
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
  constexpr void SetHigh(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_OUT_SET = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_HI_OUT_SET = pin.pin_mask;
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
  constexpr void SetLow(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_OUT_CLR = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_HI_OUT_CLR = pin.pin_mask;
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
  constexpr void Toggle(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_OUT_XOR = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      GetSioPeripheral()->GPIO_HI_OUT_XOR = pin.pin_mask;
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
  constexpr void SetPin(PIN& pin, std::uint32_t setting) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      if (setting)
        GetSioPeripheral()->GPIO_OUT_SET = pin.pin_mask;
      else
        GetSioPeripheral()->GPIO_OUT_CLR = pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      if (setting)
        GetSioPeripheral()->GPIO_HI_OUT_SET = pin.pin_mask;
      else
        GetSioPeripheral()->GPIO_HI_OUT_CLR = pin.pin_mask;
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
  constexpr std::uint32_t GetPin(PIN& pin) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      return GetSioPeripheral()->GPIO_IN & pin.pin_mask;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      return GetSioPeripheral()->GPIO_HI_IN & pin.pin_mask;
    } else {
      static_assert("Unknown port!");
    }
  }
  /**
   * @brief setup pin
   * @tparam T pin template parameter type
   * @param pull pull mode
   */
  template <typename T>
  void SetPullMode(T& pin, PullModes pull) {
    if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      uint32_t setting = GetBank0PadsPeripheral()->GPIO[pin.pin_index] & ~(libmcuhw::pads::GPIO::PDE | libmcuhw::pads::GPIO::PUE);
      setting = setting | static_cast<std::uint32_t>(pull);
      GetBank0PadsPeripheral()->GPIO[pin.pin_index] = setting;
    } else if constexpr (pin.port == libmcuhw::IoPorts::kPort0) {
      static_assert(pin.port == libmcuhw::IoPorts::kQspi, "Does not support QSPI pins yet");
    } else {
      static_assert("Unknown port!");
    }
  }

 private:
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* GetBank0PadsPeripheral() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(pads_bank0_address_ + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* GetBank0PadsPeripheralSet() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(pads_bank0_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* GetBank0PadsPeripheralClear() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(pads_bank0_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* GetBank0PadsPeripheralToggle() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(pads_bank0_address_ + libmcuhw::kPeripheralOffsetXor);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::sio::Sio* GetSioPeripheral() {
    return reinterpret_cast<libmcuhw::sio::Sio*>(sio_address_ + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief set registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::sio::Sio* GetSioPeripheralSet() {
    return reinterpret_cast<libmcuhw::sio::Sio*>(sio_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief clear registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::sio::Sio* GetSioPeripheralClear() {
    return reinterpret_cast<libmcuhw::sio::Sio*>(sio_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief toggle registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::sio::Sio* GetSioPeripheralToggle() {
    return reinterpret_cast<libmcuhw::sio::Sio*>(sio_address_ + libmcuhw::kPeripheralOffsetXor);
  }

  static constexpr libmcu::HwAddressType pads_bank0_address_ = pads_bank0_address; /*!< pads bank 0 peripheral address */
  static constexpr libmcu::HwAddressType sio_address_ = sio_address;               /*!< SIO peripheral address*/
};
}  // namespace libmcuhal::gpio

#endif