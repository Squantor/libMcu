/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series I2C functions
 */
#ifndef LPC81X_I2C_HPP
#define LPC81X_I2C_HPP

namespace libMcuLL {
namespace sw {
namespace i2c {
using namespace hw::i2c;
template <libMcuLL::I2Caddress address_>
struct i2c {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to i2c registers
   */
  static hw::i2c::peripheral *peripheral() {
    return reinterpret_cast<hw::i2c::peripheral *>(address);
  }

  /**
   * @brief Initialize I2C master
   *
   * @param bitRate requested bit rate
   * @return uint32_t actual bit rate
   */
  uint32_t initMaster(uint32_t bitRate) {
    uint32_t divider = CLOCK_AHB / bitRate;
    peripheral()->CLKDIV = divider + 1;
    peripheral()->CFG = CFG::MSTEN;
    return CLOCK_AHB / divider;
  }
};
}  // namespace i2c
}  // namespace sw
}  // namespace libMcuLL

#endif