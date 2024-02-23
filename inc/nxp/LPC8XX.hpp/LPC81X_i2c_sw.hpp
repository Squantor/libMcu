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
template <libMcuLL::I2CbaseAddress i2cAddress_>
struct i2c : libMcuLL::peripheralBase {
  /**
   * @brief Initialize I2C master
   *
   * @param bitRate requested bit rate
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  constexpr std::uint32_t initMaster(std::uint32_t bitRate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t divider = CLOCK_AHB / (bitRate * 20);
    i2cPeripheral()->TIMEOUT = TIMEOUT::TO(timeout);
    i2cPeripheral()->CLKDIV = divider + 1;
    i2cPeripheral()->CFG = CFG::MSTEN;
    return CLOCK_AHB / divider / 20;
  }
  /**
   * @brief Write data to I2C device
   *
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  constexpr void write(libMcuLL::i2cDeviceAddress address, const std::span<std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = MSTCTL::MSTSTART;
    while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t &data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = MSTCTL::MSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_TXRDY)
        break;
    }
  stop:
    i2cPeripheral()->MSTCTL = MSTCTL::MSTSTOP;
    while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
  }

  /**
   * @brief Read data from I2C device
   *
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  constexpr void read(libMcuLL::i2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress | 0x01;  // set read bit in Address
    i2cPeripheral()->MSTCTL = MSTCTL::MSTSTART;
    while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_RXRDY)
      goto stop;
    receiveBuffer[0] = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    for (std::uint8_t &data : receiveBuffer.subspan(1)) {
      i2cPeripheral()->MSTCTL = MSTCTL::MSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & STAT::MSTSTATE_MASK) != STAT::MSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    }
  stop:
    i2cPeripheral()->MSTCTL = MSTCTL::MSTSTOP;
    while (!(i2cPeripheral()->STAT & (STAT::MSTPENDING | STAT::EVENTTIMEOUT | STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to i2c registers
   */
  constexpr static hw::i2c::peripheral *i2cPeripheral() {
    return reinterpret_cast<hw::i2c::peripheral *>(i2cAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType i2cAddress = i2cAddress_; /**< peripheral address */
};
}  // namespace i2c
}  // namespace sw
}  // namespace libMcuLL

#endif