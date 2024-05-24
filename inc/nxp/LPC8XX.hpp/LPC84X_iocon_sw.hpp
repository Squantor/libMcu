/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series IOCON functions
 */
#ifndef LPC84X_IOCON_HPP
#define LPC84X_IOCON_HPP

namespace libMcuLL::sw::iocon {
using namespace hw::iocon;

/**
 * @brief Pin pull modes
 *
 */
enum class pullModes : std::uint32_t {
  INACTIVE = PIO::INACTIVE, /**< No pullup/down */
  PULLDOWN = PIO::PULLDOWN, /**< Pulldown enabled */
  PULLUP = PIO::PULLUP,     /**< Pullup enabled */
  REPEATER = PIO::REPEATER, /**< Repeater mode */
};

/**
 * @brief pin filtering modes
 *
 */
enum class pinFiltering : std::uint32_t {
  BYPASS = PIO::BYPASS,   /**< Bypassed input filter */
  CYCLES1 = PIO::CYCLES1, /**< 1 clock cycle pulses are filtered */
  CYCLES2 = PIO::CYCLES2, /**< 2 clock cycle pulses are filtered */
  CYCLES3 = PIO::CYCLES3, /**< 3 clock cycle pulses are filtered */
};

/**
 * @brief Clock divider to use for filtering
 *
 * TODO, change this to a consteval function
 *
 */
enum class clockDivider : std::uint32_t {
  IOCONCLKDIV0 = PIO::IOCONCLKDIV0, /**< use IOCONCLKDIV0 in SYSCON */
  IOCONCLKDIV1 = PIO::IOCONCLKDIV1, /**< use IOCONCLKDIV1 in SYSCON */
  IOCONCLKDIV2 = PIO::IOCONCLKDIV2, /**< use IOCONCLKDIV2 in SYSCON */
  IOCONCLKDIV3 = PIO::IOCONCLKDIV3, /**< use IOCONCLKDIV3 in SYSCON */
  IOCONCLKDIV4 = PIO::IOCONCLKDIV4, /**< use IOCONCLKDIV4 in SYSCON */
  IOCONCLKDIV5 = PIO::IOCONCLKDIV5, /**< use IOCONCLKDIV5 in SYSCON */
  IOCONCLKDIV6 = PIO::IOCONCLKDIV6, /**< use IOCONCLKDIV6 in SYSCON */
};

/**
 * @brief I2C pin modes
 *
 */
enum class i2cmodes : std::uint32_t {
  I2C_STD = PIO::I2C_STD,   /**< standard/fast I2C mode */
  IO_STD = PIO::IO_STD,     /**< standard I/O functionality */
  I2C_FAST = PIO::I2C_FAST, /**< fast mode plus I2C */
};

template <libMcuLL::ioconBaseAddress ioconAddress_>
struct iocon : libMcuLL::peripheralBase {
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
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
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
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
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
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
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
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
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
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
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
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    ioconPeripheral()->PIO[pin.ioconIndex] = static_cast<std::uint32_t>(mode);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to iocon registers
   */
  static constexpr hw::iocon::peripheral *ioconPeripheral() {
    return reinterpret_cast<hw::iocon::peripheral *>(ioconAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType ioconAddress = ioconAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::iocon
#endif