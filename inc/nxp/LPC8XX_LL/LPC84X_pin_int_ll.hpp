/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_pin_int_ll.hpp
 * @brief LPC840 series Pin interrupt interface class and definitions
 */
#ifndef LPC84X_PIN_INT_HPP
#define LPC84X_PIN_INT_HPP

namespace libmcull::pin_int {
namespace hardware = libmcuhw::pinint;
/**
 * @brief Interrupt pins indices
 */
enum class InterruptPins : std::uint32_t {
  PintSel0 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel0), /*!< PINTSEL0 */
  PintSel1 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel1), /*!< PINTSEL1 */
  PintSel2 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel2), /*!< PINTSEL2 */
  PintSel3 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel3), /*!< PINTSEL3 */
  PintSel4 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel4), /*!< PINTSEL4 */
  PintSel5 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel5), /*!< PINTSEL5 */
  PintSel6 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel6), /*!< PINTSEL6 */
  PintSel7 = static_cast<std::uint32_t>(hardware::InterruptPins::PintSel7), /*!< PINTSEL7 */
};
/**
 * @brief Edge sensitivity settings
 */
enum class EdgeSettings : std::uint32_t {
  Rising,  /*!< Rising edge */
  Falling, /*!< Falling edge */
  Both,    /*!< Both edges */
};
/**
 * @brief Level sensitivity settings
 * We have no both levels as that is strange
 */
enum class LevelSettings : std::uint32_t {
  Low,  /*<! Low level */
  High, /*!< High level */
};
/**
 * @brief Pin interrupt peripheral low level interface
 * @tparam pinint_address
 */
template <libmcu::PinintBaseAddress pinint_address>
struct Pinint : libmcull::PeripheralBase {
  /**
   * @brief Enable channel with edge sensitivity
   * @param channel channel to setup
   * @param edge edge sensitivity
   */
  constexpr static void EnableChannel(InterruptPins channel, EdgeSettings edge) {
    GetPeripheral()->CIENF = static_cast<std::uint32_t>(channel);
    GetPeripheral()->CIENR = static_cast<std::uint32_t>(channel);
    ClearChannel(channel);
    GetPeripheral()->ISEL = GetPeripheral()->ISEL & ~static_cast<std::uint32_t>(channel);
    switch (edge) {
      case EdgeSettings::Rising:
        GetPeripheral()->SIENR = static_cast<std::uint32_t>(channel);
        break;
      case EdgeSettings::Falling:
        GetPeripheral()->SIENF = static_cast<std::uint32_t>(channel);
        break;
      case EdgeSettings::Both:
        GetPeripheral()->SIENF = static_cast<std::uint32_t>(channel);
        GetPeripheral()->SIENR = static_cast<std::uint32_t>(channel);
        break;
    }
  }
  /**
   * @brief Clear channel interrupt
   * @param channel channel to clear
   */
  constexpr static void ClearChannel(InterruptPins channel) {
    GetPeripheral()->IST = static_cast<std::uint32_t>(channel);
  }
  /**
   * @brief Disable channel
   * @param channel channel to disable
   */
  constexpr static void DisableChannel(InterruptPins channel) {
    GetPeripheral()->CIENR = static_cast<std::uint32_t>(channel);
    GetPeripheral()->CIENF = static_cast<std::uint32_t>(channel);
  }
  /**
   * @brief get registers from peripheral
   * @return pointer to pin interrupt registers
   */
  constexpr static libmcuhw::pinint::Pinint *GetPeripheral() {
    return reinterpret_cast<libmcuhw::pinint::Pinint *>(pinint_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pinint_address_ = pinint_address; /*!< peripheral address */
};
}  // namespace libmcull::pin_int
#endif