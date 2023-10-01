/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series IOCON functions
 */
#ifndef LPC81X_IOCON_HPP
#define LPC81X_IOCON_HPP

namespace libMcuLL {
namespace sw {
namespace iocon {
using namespace hw::iocon;
template <libMcuLL::IOCONaddress address_>
struct iocon {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to iocon registers
   */
  static hw::iocon::peripheral *peripheral() {
    return reinterpret_cast<hw::iocon::peripheral *>(address);
  }
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
  void setup(T &pin, pullModes mode, pinFiltering filter, clockDivider clock, uint32_t options) {
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    peripheral()->PIO[pin.ioconIndex] =
      static_cast<uint32_t>(mode) | static_cast<uint32_t>(filter) | static_cast<uint32_t>(clock) | options;
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
  void setup(T &pin, pullModes mode, uint32_t options) {
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    peripheral()->PIO[pin.ioconIndex] = static_cast<uint32_t>(mode) | options;
  }
  /**
   * @brief Setup normal IOCON pin
   *
   * @tparam T      normal iocon pin type
   * @param pin     instance of pin type to setup
   */
  template <typename T>
  void setup(T &pin, pullModes mode) {
    static_assert(pin.typeFlags == hw::pinTypeFlags::NORMAL, "only normal pins can use this setup function");
    peripheral()->PIO[pin.ioconIndex] = static_cast<uint32_t>(mode);
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
  void setup(T &pin, i2cmodes mode, pinFiltering filter, clockDivider clock, uint32_t options) {
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    peripheral()->PIO[pin.ioconIndex] =
      static_cast<uint32_t>(mode) | static_cast<uint32_t>(filter) | static_cast<uint32_t>(clock) | options;
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
  void setup(T &pin, i2cmodes mode, uint32_t options) {
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    peripheral()->PIO[pin.ioconIndex] = static_cast<uint32_t>(mode) | options;
  }
  /**
   * @brief Setup I2C IOCON pin
   *
   * @tparam T      i2c iocon pin type
   * @param pin     instance of pin type to setup
   * @param mode    I2C mode
   */
  template <typename T>
  void setup(T &pin, i2cmodes mode) {
    static_assert(pin.typeFlags & hw::pinTypeFlags::IOCON_I2C, "only I2C pins have a i2c mode setup");
    peripheral()->PIO[pin.ioconIndex] = static_cast<uint32_t>(mode);
  }
};
}  // namespace iocon
}  // namespace sw
}  // namespace libMcuLL

#endif