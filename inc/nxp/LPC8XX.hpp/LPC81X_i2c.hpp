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
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  std::uint32_t initMaster(std::uint32_t bitRate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t divider = CLOCK_AHB / (bitRate * 20);
    peripheral()->TIMEOUT = TIMEOUT::TO(timeout);
    peripheral()->CLKDIV = divider + 1;
    peripheral()->CFG = CFG::MSTEN;
    return CLOCK_AHB / divider / 20;
  }
  /**
   * @brief Write data to I2C device
   *
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  void write(libMcuLL::i2cDeviceAddress address, const std::span<std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    peripheral()->MSTDAT = i2cAddress;
    peripheral()->MSTCTL = MSTCTL::MSTSTART;
    while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
    if ((peripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t &data : transmitBuffer) {
      peripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      peripheral()->MSTCTL = MSTCTL::MSTCONTINUE;
      while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
        ;
      if ((peripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_TXRDY)
        break;
    }
  stop:
    peripheral()->MSTCTL = MSTCTL::MSTSTOP;
    while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
  }

  /**
   * @brief Read data from I2C device
   *
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  void read(libMcuLL::i2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    peripheral()->MSTDAT = i2cAddress | 0x01;  // set read bit in Address
    peripheral()->MSTCTL = MSTCTL::MSTSTART;
    while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
    if ((peripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_RXRDY)
      goto stop;
    receiveBuffer[0] = static_cast<std::uint8_t>(peripheral()->MSTDAT);
    for (std::uint8_t &data : receiveBuffer.subspan(1)) {
      peripheral()->MSTCTL = MSTCTL::MSTCONTINUE;
      while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
        ;
      if ((peripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(peripheral()->MSTDAT);
    }
  stop:
    peripheral()->MSTCTL = MSTCTL::MSTSTOP;
    while (!(peripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
  }
};
}  // namespace i2c
}  // namespace sw
}  // namespace libMcuLL

#endif