/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series IOCON  low level functions
 */
#ifndef LPC84X_IOCON_LL_HPP
#define LPC84X_IOCON_LL_HPP

namespace libMcuLL::iocon {
namespace hardware = libMcuLL::hw::iocon;

/**
 * @brief Pin pull modes
 *
 */
enum class pullModes : std::uint32_t {
  INACTIVE = hardware::PIO::INACTIVE, /**< No pullup/down */
  PULLDOWN = hardware::PIO::PULLDOWN, /**< Pulldown enabled */
  PULLUP = hardware::PIO::PULLUP,     /**< Pullup enabled */
  REPEATER = hardware::PIO::REPEATER, /**< Repeater mode */
};

/**
 * @brief pin filtering modes
 *
 */
enum class pinFiltering : std::uint32_t {
  BYPASS = hardware::PIO::BYPASS,   /**< Bypassed input filter */
  CYCLES1 = hardware::PIO::CYCLES1, /**< 1 clock cycle pulses are filtered */
  CYCLES2 = hardware::PIO::CYCLES2, /**< 2 clock cycle pulses are filtered */
  CYCLES3 = hardware::PIO::CYCLES3, /**< 3 clock cycle pulses are filtered */
};

/**
 * @brief Clock divider to use for filtering
 *
 * TODO, change this to a consteval function
 *
 */
enum class clockDivider : std::uint32_t {
  IOCONCLKDIV0 = hardware::PIO::IOCONCLKDIV0, /**< use IOCONCLKDIV0 in SYSCON */
  IOCONCLKDIV1 = hardware::PIO::IOCONCLKDIV1, /**< use IOCONCLKDIV1 in SYSCON */
  IOCONCLKDIV2 = hardware::PIO::IOCONCLKDIV2, /**< use IOCONCLKDIV2 in SYSCON */
  IOCONCLKDIV3 = hardware::PIO::IOCONCLKDIV3, /**< use IOCONCLKDIV3 in SYSCON */
  IOCONCLKDIV4 = hardware::PIO::IOCONCLKDIV4, /**< use IOCONCLKDIV4 in SYSCON */
  IOCONCLKDIV5 = hardware::PIO::IOCONCLKDIV5, /**< use IOCONCLKDIV5 in SYSCON */
  IOCONCLKDIV6 = hardware::PIO::IOCONCLKDIV6, /**< use IOCONCLKDIV6 in SYSCON */
};

/**
 * @brief I2C pin modes
 *
 */
enum class i2cmodes : std::uint32_t {
  I2C_STD = hardware::PIO::I2C_STD,   /**< standard/fast I2C mode */
  IO_STD = hardware::PIO::IO_STD,     /**< standard I/O functionality */
  I2C_FAST = hardware::PIO::I2C_FAST, /**< fast mode plus I2C */
};

template <libMcu::ioconBaseAddress ioconAddress_>
struct iocon : libMcu::peripheralBase {
  /**
   * @brief Setup normal IOCON pin
   *
   * @tparam T      normal iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    pullup mode
   * @param filter  glitch filter setting
   * @param clock   clock source for glitch filter
   * @param options additional single bit options to set
   */
  template <typename T>
  constexpr void setup(T &pin, pullModes mode, pinFiltering filter, clockDivider clock, std::uint32_t options) {
    static_assert(pin.typeFlags == libMcuLL::hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    ioconPeripheral()->PIO[pin.ioconIndex] =
      static_cast<std::uint32_t>(mode) | static_cast<std::uint32_t>(filter) | static_cast<std::uint32_t>(clock) | options;
  }
  /**
   * @brief Setup normal IOCON pin
   *
   * @tparam T      normal iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    pullup mode
   * @param options additional single bit options to set
   */
  template <typename T>
  constexpr void setup(T &pin, pullModes mode, std::uint32_t options) {
    static_assert(pin.typeFlags == libMcuLL::hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    ioconPeripheral()->PIO[pin.ioconIndex] = static_cast<std::uint32_t>(mode) | options;
  }
  /**
   * @brief Setup normal IOCON pin
   *
   * @tparam T      normal iocon pin type
   * @param pin     instance of pin type to setup
   */
  template <typename T>
  constexpr void setup(T &pin, pullModes mode) {
    static_assert(pin.typeFlags == libMcuLL::hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    ioconPeripheral()->PIO[pin.ioconIndex] = static_cast<std::uint32_t>(mode);
  }
  /**
   * @brief Setup I2C IOCON pin
   *
   * @tparam T      i2c iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    I2C mode
   * @param filter  glitch filter setting
   * @param clock   clock source for glitch filter
   * @param options additional single bit options to set
   */
  template <typename T>
  constexpr void setup(T &pin, i2cmodes mode, pinFiltering filter, clockDivider clock, std::uint32_t options) {
    static_assert(pin.typeFlags & libMcuLL::hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    ioconPeripheral()->PIO[pin.ioconIndex] =
      static_cast<std::uint32_t>(mode) | static_cast<std::uint32_t>(filter) | static_cast<std::uint32_t>(clock) | options;
  }
  /**
   * @brief Setup I2C IOCON pin
   *
   * @tparam T      i2c iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    I2C mode
   * @param options additional single bit options to set
   */
  template <typename T>
  constexpr void setup(T &pin, i2cmodes mode, std::uint32_t options) {
    static_assert(pin.typeFlags & libMcuLL::hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    ioconPeripheral()->PIO[pin.ioconIndex] = static_cast<std::uint32_t>(mode) | options;
  }
  /**
   * @brief Setup I2C IOCON pin
   *
   * @tparam T      i2c iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    I2C mode
   */
  template <typename T>
  constexpr void setup(T &pin, i2cmodes mode) {
    static_assert(pin.typeFlags & libMcuLL::hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    ioconPeripheral()->PIO[pin.ioconIndex] = static_cast<std::uint32_t>(mode);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to iocon registers
   */
  static constexpr hardware::peripheral *ioconPeripheral() {
    return reinterpret_cast<hardware::peripheral *>(ioconAddress);
  }

 private:
  static constexpr libMcu::hwAddressType ioconAddress = ioconAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::iocon
#endif