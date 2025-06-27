/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_i2c_int_ll.hpp
 * @brief LPC84X series Interrupt driven I2C low level interface class and definitions
 */
#ifndef LPC84X_I2C_INT_LL_HPP
#define LPC84X_I2C_INT_LL_HPP

namespace libmcull::i2c {
namespace hardware = libmcuhw::i2c;
/**
 * @brief
 * @tparam i2c_address
 */
template <libmcu::I2cBaseAddress i2c_address>
struct I2cInterrupt : libmcull::AsyncI2cBase {
  /**
   * @brief Initialize I2C master
   * @todo need to take into account the sampling periods of SCL SDA
   * @tparam clock_config clock configuration
   * @param bit_rate requested bit rate
   * @param timeout clocks to timeout
   * @return std::uint32_t actual bit rate
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate, std::uint32_t timeout) {
    /*
    we multiply by 20 as by default MSTTIME divides the timing by 2 and I2C peripheral needs 10 clocks for something.
    This is not described in the datasheet but the calculation does match their example.
    */
    std::uint32_t peripheralFrequency = getInputClockFreq<clock_config>();
    std::uint32_t divider = peripheralFrequency / (bit_rate * 20);
    GetPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    GetPeripheral()->CLKDIV = divider + 1;
    GetPeripheral()->CFG = hardware::CFG::MSTEN;
    return peripheralFrequency / divider / 20;
  }
  /**
   * @brief Transmit data to I2C device
   * @param address I2C device to transmit to
   * @param transmit_buffer Data to transmit
   */
  constexpr void Transmit(const libmcull::I2cDeviceAddress address, const std::span<const std::uint8_t> transmit_buffer) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      goto stop;
    for (const std::uint8_t &data : transmit_buffer) {
      GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
        ;
      if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
        break;
    }
  stop:
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Receive data from I2C device
   * @param address I2C device to receive from
   * @param receive_buffer place to put received data, needs to be at least size 1!
   */
  constexpr void Receive(const libmcull::I2cDeviceAddress address, std::span<std::uint8_t> receive_buffer) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address | 0x01;  // set read bit in Address
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_RXRDY)
      goto stop;
    receive_buffer[0] = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
    for (std::uint8_t &data : receive_buffer.subspan(1)) {
      GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
        ;
      if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_RXRDY)
        break;
      data = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
    }
  stop:
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Starts a transmit operation and transmits a block of data
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param transmit_buffer Buffer of data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcull::I2cDeviceAddress address,
                                                const std::span<const std::uint8_t> transmit_buffer) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    masterWait();
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libmcu::Results::kError;
    for (const std::uint8_t &data : transmit_buffer) {
      GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      masterWait();
      if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
        return libmcu::Results::kError;
    }
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Starts a transmit operation and writes a single byte
   * Leaves the I2C bus open after the transmission
   * @param address I2C address
   * @param data Byte to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcull::I2cDeviceAddress address, const std::uint8_t data) {
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    GetPeripheral()->MSTDAT = slave_address;
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    masterWait();
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libmcu::Results::kError;
    GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
    masterWait();
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libmcu::Results::kError;
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param transmit_buffer Data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(const std::span<const std::uint8_t> transmit_buffer) {
    for (const std::uint8_t &data : transmit_buffer) {
      GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
      GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
      masterWait();
      if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
        return libmcu::Results::kError;
    }
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Transmits more I2C data to the open I2C bus
   * Leaves the I2C bus open
   * @param data Data to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(const std::uint8_t data) {
    GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(data);
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
    masterWait();
    if ((GetPeripheral()->STAT & hardware::STAT::MSTSTATE_MASK) != hardware::STAT::MSTSTATE_TXRDY)
      return libmcu::Results::kError;
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Stops I2C master
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StopMaster() {
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
    masterWait();
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void masterWait() {
    // @todo add timeout
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t getInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((i2c_address_ == libmcuhw::kI2c0Address) && (clock_config.peripheral == libmcuhw::clock::PeriSelect::I2C0))
      return clock_config.getFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c1Address) && (clock_config.peripheral == libmcuhw::clock::PeriSelect::I2C1))
      return clock_config.getFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c2Address) && (clock_config.peripheral == libmcuhw::clock::PeriSelect::I2C2))
      return clock_config.getFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c3Address) && (clock_config.peripheral == libmcuhw::clock::PeriSelect::I2C3))
      return clock_config.getFrequency();
    else
      static_assert(false, "Clock config and peripherals unknown or not matching!");
    return 0;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to i2c registers
   */
  constexpr static hardware::I2c *GetPeripheral() {
    return reinterpret_cast<hardware::I2c *>(i2c_address_);
  }

 private:
  static constexpr libmcu::HwAddressType i2c_address_ = i2c_address; /*!< peripheral address */
};
}  // namespace libmcull::i2c
#endif