/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_i2c_ll.hpp
 * @brief LPC84X series I2C low level functions
 */
#ifndef LPC84X_I2C_LL_HPP
#define LPC84X_I2C_LL_HPP

namespace libmcull::i2c {
namespace hardware = libmcuhw::i2c;
/**
 * @brief
 * @tparam i2cAddress_
 */
template <libmcu::i2cBaseAddress i2cAddress_>
struct i2c : libmcu::PeripheralBase {
  /**
   * @brief Initialize I2C master
   * @todo need to take into account the sampling periods of SCL SDA
   * @tparam t_clockConfig clock configuration
   * @param bitRate requested bit rate
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  template <const libmcuhw::clock::periClockConfig &t_clockConfig>
  constexpr std::uint32_t initMaster(std::uint32_t bitRate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t peripheralFrequency = getInputClockFreq<t_clockConfig>();
    std::uint32_t divider = peripheralFrequency / (bitRate * 20);
    i2cPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    i2cPeripheral()->CLKDIV = divider + 1;
    i2cPeripheral()->CFG = hardware::CFG::kMSTEN;
    return peripheralFrequency / divider / 20;
  }
  /**
   * @brief Write data to I2C device
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  constexpr void write(const libmcu::i2cDeviceAddress address, const std::span<const std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t &data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
        break;
    }
  stop:
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTOP;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
  }
  /**
   * @brief Read data from I2C device
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  constexpr void read(const libmcu::i2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress | 0x01;  // set read bit in Address
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_RXRDY)
      goto stop;
    receiveBuffer[0] = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    for (std::uint8_t &data : receiveBuffer.subspan(1)) {
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    }
  stop:
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTOP;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
  }
  /**
   * @brief Starts writing a master transaction and writes a block of data
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param transmitBuffer Buffer of data to send
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results masterWriteStart(const libmcu::i2cDeviceAddress address,
                                             const std::span<const std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      return libmcu::Results::ERROR;
    for (const std::uint8_t &data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      masterWait();
      if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
        return libmcu::Results::ERROR;
    }
    return libmcu::Results::NO_ERROR;
  }
  /**
   * @brief Starts writing a master transaction and writes a single byte
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param data Byte to send
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results masterWriteStart(const libmcu::i2cDeviceAddress address, const std::uint8_t data) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTART;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      return libmcu::Results::ERROR;
    i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      return libmcu::Results::ERROR;
    return libmcu::Results::NO_ERROR;
  }
  /**
   * @brief writes more I2C data to the I2C bus
   * Leaves the I2C bus open
   * @param transmitBuffer Data to send
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results masterWriteContinue(const std::span<const std::uint8_t> transmitBuffer) {
    for (const std::uint8_t &data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
      masterWait();
      if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
        return libmcu::Results::ERROR;
    }
    return libmcu::Results::NO_ERROR;
  }
  /**
   * @brief Writes more I2C data to the I2C bus
   * Leaves the I2C bus open
   * @param data Data to send
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results masterWriteContinue(const std::uint8_t data) {
    i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTCONTINUE;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::kMSTSTATE_MASK) != hardware::STAT::kMSTSTATE_TXRDY)
      return libmcu::Results::ERROR;
    return libmcu::Results::NO_ERROR;
  }
  /**
   * @brief Stops I2C master transmission
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results masterStop() {
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::kMSTSTOP;
    masterWait();
    return libmcu::Results::NO_ERROR;
  }
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void masterWait() {
    // @todo add timeout
    while (!(i2cPeripheral()->STAT & (hardware::STAT::kMSTPENDING | hardware::STAT::kEVENTTIMEOUT | hardware::STAT::kSCLTIMEOUT)))
      ;
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::periClockConfig &t_clockConfig>
  constexpr std::uint32_t getInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((i2cAddress == libmcuhw::i2c0Address) && (t_clockConfig.peripheral == libmcuhw::clock::periSelect::I2C0))
      return t_clockConfig.getFrequency();
    else if constexpr ((i2cAddress == libmcuhw::i2c1Address) && (t_clockConfig.peripheral == libmcuhw::clock::periSelect::I2C1))
      return t_clockConfig.getFrequency();
    else if constexpr ((i2cAddress == libmcuhw::i2c2Address) && (t_clockConfig.peripheral == libmcuhw::clock::periSelect::I2C2))
      return t_clockConfig.getFrequency();
    else if constexpr ((i2cAddress == libmcuhw::i2c3Address) && (t_clockConfig.peripheral == libmcuhw::clock::periSelect::I2C3))
      return t_clockConfig.getFrequency();
    else
      static_assert(false, "Clock config and peripherals unknown or not matching!");
    return 0;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to i2c registers
   */
  constexpr static hardware::I2c *i2cPeripheral() {
    return reinterpret_cast<hardware::I2c *>(i2cAddress);
  }

 private:
  static constexpr libmcu::hwAddressType i2cAddress = i2cAddress_; /*!< peripheral address */
};
}  // namespace libmcull::i2c
#endif