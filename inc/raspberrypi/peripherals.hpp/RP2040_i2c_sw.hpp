/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 I2C software interface
 */
#ifndef RP2040_I2C_SW_HPP
#define RP2040_I2C_SW_HPP

namespace libMcuLL {
namespace sw {
namespace i2c {
template <libMcuLL::i2cBaseAddress const& i2cAddress_>
struct i2c : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::i2c::peripheral* i2cPeripheral() {
    return reinterpret_cast<hw::i2c::peripheral*>(i2cAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType i2cAddress = i2cAddress_; /**< peripheral address */
};
}  // namespace i2c
}  // namespace sw
}  // namespace libMcuLL
#endif