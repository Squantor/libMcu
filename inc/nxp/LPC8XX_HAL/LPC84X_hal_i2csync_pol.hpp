/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_i2csync_pol.hpp
 * \file LPC840 series synchronous polling I2C HAL
 */
#ifndef LPC84X_HAL_I2CSYNC_POL_HPP
#define LPC84X_HAL_I2CSYNC_POL_HPP

#include "LPC84X_hal_i2c_common.hpp"

namespace libMcuHal::i2c {
namespace hardware = libMcuHw::i2c;
namespace nvic = libMcuHw::nvic;
/**
 * @brief asynchronous I2C HAL polling implementation
 * @tparam i2cBaseAddress_ i2c peripheral base address
 * @tparam nvicBaseAddress_ nvic peripheral base address
 * @tparam bufSize buffer size
 */
template <libMcu::i2cBaseAddress const& i2cBaseAddress_, std::size_t bufSize>
struct i2cSyncPol {
  /**
   * @brief Construct a new synchronous polling i2c
   */
  i2cSyncPol() {}
  /**
   * @brief Initialize I2C peripheral clocks
   * @tparam &t_clockConfig clock configuration for this peripheral
   * @param bitRate i2C bit rate
   * @param timeout clocks to timeout
   * @return actual bit rate
   */
  template <const libMcuHw::clock::periClockConfig& t_clockConfig>
  constexpr std::uint32_t init(std::uint32_t bitRate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t peripheralFrequency = getInputClockFreq<t_clockConfig>();
    std::uint32_t divider = peripheralFrequency / (bitRate * 20);
    i2cPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    i2cPeripheral()->CLKDIV = divider + 1;
    i2cPeripheral()->CFG = hardware::CFG::MSTEN;
    return peripheralFrequency / divider / 20;
  }
  /**
   * @brief Write data to I2C device
   * @param address I2C device to write to
   * @param transmitBuffer data to send
   */
  constexpr void write(const libMcu::i2cDeviceAddress address, const std::span<const std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t& data : transmitBuffer) {
      i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
        break;
    }
  stop:
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Read data from I2C device
   * @param address I2C device to read from
   * @param receiveBuffer place to put read data, needs to be at least size 1!
   */
  constexpr void read(const libMcu::i2cDeviceAddress address, std::span<std::uint8_t> receiveBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress | 0x01;  // set read bit in Address
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_RXRDY)
      goto stop;
    receiveBuffer[0] = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    for (std::uint8_t& data : receiveBuffer.subspan(1)) {
      i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
        ;
      if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(i2cPeripheral()->MSTDAT);
    }
  stop:
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Starts writing a master transaction and writes a block of data
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param transmitBuffer Buffer of data to send
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results startMasterWrite(const libMcu::i2cDeviceAddress address,
                                             const std::span<const std::uint8_t> transmitBuffer) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libMcu::results::ERROR;
    return continueMasterWrite(transmitBuffer);
  }
  /**
   * @brief Starts writing a master transaction and writes a single byte
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param data Byte to send
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results startMasterWrite(const libMcu::i2cDeviceAddress address, const std::uint8_t data) {
    std::uint32_t i2cAddress = static_cast<std::uint32_t>(address.value) << 1;
    i2cPeripheral()->MSTDAT = i2cAddress;
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libMcu::results::ERROR;
    return continueMasterWrite(data);
  }
  /**
   * @brief writes more I2C data to the I2C bus
   * Leaves the I2C bus open
   * @param transmitBuffer Data to send
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results continueMasterWrite(const std::span<const std::uint8_t> transmitBuffer) {
    libMcu::results result = libMcu::results::NO_ERROR;
    for (const std::uint8_t& data : transmitBuffer) {
      result = continueMasterWrite(data);
      if (result != libMcu::results::NO_ERROR)
        return result;
    }
    return libMcu::results::NO_ERROR;
  }
  /**
   * @brief Writes more I2C data to the I2C bus
   * Leaves the I2C bus open
   * @param data Data to send
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results continueMasterWrite(const std::uint8_t data) {
    i2cPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
    masterWait();
    if ((i2cPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libMcu::results::ERROR;
    return libMcu::results::NO_ERROR;
  }
  /**
   * @brief Stops I2C master transmission
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results stopMaster() {
    i2cPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    masterWait();
    return libMcu::results::NO_ERROR;
  }

 private:
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void masterWait() {
    // @todo add timeout
    while (!(i2cPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t getInputClockFreq() {
    static_assert(config.peripheral == libMcuHw::clock::periSelect::I2C0);
    return config.getFrequency();
  }
  /**
   * @brief access i2c registers
   * @return return pointer to peripheral
   */
  static hardware::i2c* i2cPeripheral() {
    return reinterpret_cast<hardware::i2c*>(i2cBaseAddress);
  }

  static constexpr libMcu::hwAddressType i2cBaseAddress = i2cBaseAddress_; /**< I2C peripheral address */
};

}  // namespace libMcuHal::i2c
#endif