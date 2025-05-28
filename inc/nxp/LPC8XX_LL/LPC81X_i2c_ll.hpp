/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_i2c_ll.hpp
 * @brief LPC810 series I2C interface class and definitions
 */
#ifndef LPC81X_I2C_HPP
#define LPC81X_I2C_HPP

namespace libmcull::sw::i2c {
namespace hardware = libmcuhw::i2c;
/**
 * @brief I2C Low level interface
 * @tparam i2c_address peripheral address
 */
template <libmcu::I2cBaseAddress i2c_address>
struct I2c : libmcu::PeripheralBase {
  /**
   * @brief Initialize I2C master
   * @param bit_rate requested bit rate
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t divider = CLOCK_AHB / (bit_rate * 20);
    GetPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    GetPeripheral()->CLKDIV = divider + 1;
    GetPeripheral()->CFG = hardware::CFG::kMSTEN;
    return CLOCK_AHB / divider / 20;
  }
  /**
   * @brief Write data to I2C device
   * @param address I2C device to write to
   * @param transmit_buffer data to send
   */
  constexpr void Write(libmcu::i2cDeviceAddress address, const std::span<std::uint8_t> transmit_buffer) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
    if ((GetPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t &data : transmit_buffer) {
      GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
        ;
      if ((GetPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
        break;
    }
  stop:
    GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTOP;
    while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
  }
  /**
   * @brief Read data from I2C device
   * @param address I2C device to read from
   * @param receive_buffer place to put read data, needs to be at least size 1!
   */
  constexpr void Read(libmcu::i2cDeviceAddress address, std::span<std::uint8_t> receive_buffer) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address | 0x01;  // set read bit in Address
    GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
    if ((GetPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_RXRDY)
      goto stop;
    receive_buffer[0] = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
    for (std::uint8_t &data : receive_buffer.subspan(1)) {
      GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
        ;
      if ((GetPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
    }
  stop:
    GetPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTOP;
    while (!(GetPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to i2c registers
   */
  constexpr static libmcuhw::i2c::I2c *GetPeripheral() {
    return reinterpret_cast<libmcuhw::i2c::I2c *>(i2c_address_);
  }

 private:
  static constexpr libmcu::HwAddressType i2c_address_ = i2c_address; /*!< peripheral address */
};
}  // namespace libmcull::sw::i2c
#endif