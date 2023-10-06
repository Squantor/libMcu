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
template <libMcuLL::I2CbaseAddress address_>
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
  /**
   * @brief Write data to I2C device
   *
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  void write(libMcuLL::i2cDeviceAddress address, const std::span<uint8_t> transmitBuffer) {
    uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    peripheral()->MSTDAT = i2cAddress;
    peripheral()->MSTCTL = MSTCTL::MSTSTART;
    while (!(peripheral()->STAT & STAT::MSTPENDING))
      ;
    if ((peripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_TXRDY)
      goto stop;
    for (const uint8_t &data : transmitBuffer) {
      peripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      peripheral()->MSTCTL = MSTCTL::MSTCONTINUE;
      while (!(peripheral()->STAT & STAT::MSTPENDING))
        ;
    }
  stop:
    peripheral()->MSTCTL = MSTCTL::MSTSTOP;
    while (!(peripheral()->STAT & STAT::MSTPENDING))
      ;
  }
};
}  // namespace i2c
}  // namespace sw
}  // namespace libMcuLL

#endif