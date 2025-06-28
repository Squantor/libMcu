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
 * @todo error handling is lacking, need a centralized error handler and additional result codes
 * @todo claim and unclaim maybe need a handle number to ensure no double unclaims
 * @tparam i2c_address
 */
template <libmcu::I2cBaseAddress i2c_address>
struct I2cInterrupt : libmcull::AsyncI2cBase {
  /**
   * @brief Get the I2C interrupt peripheral current status
   * @return current status
   */
  constexpr libmcu::Results GetStatus() {
    return current_state_;
  }
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
    std::uint32_t peripheralFrequency = GetInputClockFreq<clock_config>();
    std::uint32_t divider = peripheralFrequency / (bit_rate * 20);
    GetPeripheral()->TIMEOUT = hardware::TIMEOUT::TO(timeout);
    GetPeripheral()->CLKDIV = divider + 1;
    GetPeripheral()->INTENCLR = hardware::INTENCLR::RESERVED_MASK;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTARBLOSSEN | hardware::INTENSET::MSTSTSTPERREN |
                                hardware::INTENSET::EVENTTIMEOUTEN | hardware::INTENSET::SCLTIMEOUTEN;
    GetPeripheral()->CFG = hardware::CFG::MSTEN;
    current_state_ = libmcu::Results::kIdle;
    return peripheralFrequency / divider / 20;
  }
  /**
   * @brief Claim the I2C interface
   * @return kClaimed when the claim has been successful, any other value indicates an error
   */
  constexpr libmcu::Results Claim(void) {
    if (current_state_ == libmcu::Results::kClaimed) {
      return libmcu::Results::kInUse;
    }
    if (current_state_ == libmcu::Results::kIdle) {
      current_state_ = libmcu::Results::kClaimed;
    }
    return current_state_;
  }
  /**
   * @brief Unclaim the I2C interface
   * @return kUnclaimed when the unclaim has been successful, any other value indicates an error
   */
  constexpr libmcu::Results Unclaim(void) {
    if (current_state_ == libmcu::Results::kClaimed) {
      current_state_ = libmcu::Results::kIdle;
      return libmcu::Results::kUnclaimed;
    }
    return current_state_;
  }
  /**
   * @brief Transmit data to I2C device
   * @param address I2C device to transmit to
   * @param transmit_buffer Data to transmit
   * @param transaction_type Transaction type
   */
  constexpr libmcu::Results Transmit(const libmcull::I2cDeviceAddress address, std::span<std::uint8_t> transmit_buffer,
                                     TransactionType transaction_type = TransactionType::kSingle) {
    if (current_state_ != libmcu::Results::kClaimed) {
      if (current_state_ == libmcu::Results::kBusyTransmit) {
        return libmcu::Results::kBusy;
      }
      return current_state_;
    }
    current_state_ = libmcu::Results::kBusyTransmit;
    transaction_type_ = transaction_type;
    std::uint32_t slave_address = static_cast<std::uint32_t>(address.value) << 1;
    buffer_index_ = 0;
    buffer_ = transmit_buffer;
    StartMasterTransmit(slave_address);
    return current_state_;
  }
  /**
   * @brief Receive data from I2C device
   * @param address I2C device to receive from
   * @param receive_buffer place to put received data, needs to be at least size 1!
   */
  constexpr libmcu::Results Receive(const libmcull::I2cDeviceAddress address, std::span<std::uint8_t> receive_buffer,
                                    TransactionType transaction_type = TransactionType::kSingle) {
    if (current_state_ != libmcu::Results::kClaimed) {
      if (current_state_ == libmcu::Results::kBusyReceive) {
        return libmcu::Results::kBusy;
      }
      return current_state_;
    }
    current_state_ = libmcu::Results::kBusyReceive;
    transaction_type_ = transaction_type;
    std::uint32_t slave_address = (static_cast<std::uint32_t>(address.value) << 1) | 0x01;  // set read bit in Address
    buffer_index_ = 0;
    buffer_ = receive_buffer;
    StartMasterTransmit(slave_address);
    return current_state_;
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
    if (StartMasterTransmit(slave_address) != libmcu::Results::kNoError)
      return libmcu::Results::kError;
    for (const std::uint8_t &data : transmit_buffer) {
      if (ContinueMasterTransmit(data) != libmcu::Results::kNoError)
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
    if (StartMasterTransmit(slave_address) != libmcu::Results::kNoError)
      return libmcu::Results::kError;
    if (ContinueMasterTransmit(data) != libmcu::Results::kNoError)
      return libmcu::Results::kError;
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Starts transmitting I2C data to a closed I2C bus
   * Opens the I2C bus state
   * @param address Address data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const std::uint32_t address) {
    GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(address);
    GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTART;
    GetPeripheral()->INTENSET = hardware::INTENSET::MSTPENDINGEN;
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
      if (ContinueMasterTransmit(data) != libmcu::Results::kNoError)
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
    MasterWait();
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
    MasterWait();
    return libmcu::Results::kNoError;
  }
  /**
   * @brief Waits until the master action has completed
   */
  constexpr void MasterWait() {
    // @todo add timeout
    while (!(GetPeripheral()->STAT & (hardware::STAT::MSTPENDING | hardware::STAT::EVENTTIMEOUT | hardware::STAT::SCLTIMEOUT)))
      ;
  }
  /**
   * @brief Interrupt handler for this I2C peripheral
   * @todo there might be contention issue on current_state_, better to have a separate state variable?
   */
  constexpr void InterruptHandler() {
    std::uint32_t status = GetPeripheral()->STAT & hardware::STAT::RESERVED_MASK;
    if (status & hardware::STAT::MSTPENDING) {
      std::uint32_t status_state = status & hardware::STAT::MSTSTATE_MASK;
      if ((status_state == hardware::STAT::MSTSTATE_TXRDY) || (status_state == hardware::STAT::MSTSTATE_RXRDY)) {
        // check if buffer is empty
        if (buffer_index_ == buffer_.size()) {
          if (transaction_type_ == TransactionType::kSingle) {
            // This was a single transfer, send master stop
            GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTSTOP;
          } else if (transaction_type_ == TransactionType::kMultiple) {
            // Multiple transfers, stop pending interrupt, it will be enabled when the next transfer starts
            GetPeripheral()->INTENCLR = hardware::INTENCLR::MSTPENDINGCLR;
            current_state_ = libmcu::Results::kWaitForNext;
          }
        } else {
          if (status_state == hardware::STAT::MSTSTATE_TXRDY) {
            // continue transmitting
            GetPeripheral()->MSTDAT = static_cast<std::uint32_t>(buffer_[buffer_index_++]);
            GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
          } else {
            // continue receiving
            buffer_[buffer_index_++] = static_cast<std::uint8_t>(GetPeripheral()->MSTDAT);
            GetPeripheral()->MSTCTL = hardware::MSTCTL::MSTCONTINUE;
          }
        }
      } else if (status_state == hardware::STAT::MSTSTATE_IDLE) {
        // we are idle, disable master pending interrupt and change internal state
        GetPeripheral()->INTENCLR = hardware::INTENCLR::MSTPENDINGCLR;
        current_state_ = libmcu::Results::kClaimed;
      } else {
        //! @todo handle NACK addres, NACK data states
      }
    } else {
      //! @todo handle MSTARBLOSS, MSTSTSTPERR, EVENTTIMEOUT, SCLTIMEOUT
    }
  }
  /**
   * @brief get the input clock of this I2C peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((i2c_address_ == libmcuhw::kI2c0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C0))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c1Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C1))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c2Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C2))
      return clock_config.GetFrequency();
    else if constexpr ((i2c_address_ == libmcuhw::kI2c3Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::I2C3))
      return clock_config.GetFrequency();
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
  volatile libmcu::Results current_state_;                           /*!< current state */
  libmcull::TransactionType transaction_type_;                       /*!< current transaction type */
  std::span<std::uint8_t> buffer_;                                   /*!< current buffer */
  std::size_t buffer_index_;                                         /*!< current buffer index */
};
}  // namespace libmcull::i2c
#endif