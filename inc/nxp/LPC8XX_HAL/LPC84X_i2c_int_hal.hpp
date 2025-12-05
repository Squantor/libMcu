/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_i2csync_pol.hpp
 * @brief LPC840 series I2C HAL interrupt mode
 */
#ifndef LPC84X_HAL_I2C_INT_HAL_HPP
#define LPC84X_HAL_I2C_INT_HAL_HPP

#include "LPC84X_i2c_common_hal.hpp"

namespace libmcuhal::i2c {
/**
 * @brief I2C HAL driver interrupt mode
 * @tparam ll_i2c_async pointer to a LPC84X low level I2C interface
 * @tparam max_transactions maximum number of outstanding transactions
 * @todo see if you can prevent element copying from the ringbuffer
 */
template <libmcull::DerivedFromAsyncI2c auto& ll_i2c_async, std::size_t max_transactions = 8>
struct I2cInterrupt : public libmcuhal::AsyncI2cBase {
  /**
   * @brief Setup I2C
   * @tparam &clock_config clock configuration to use
   * @param bit_rate Bit rate value
   * @param timeout I2C timeout
   * @return actual baud rate
   */
  template <const libmcuhw::clock::PeriClockConfig& clock_config>
  constexpr std::uint32_t Init(std::uint32_t bit_rate, std::uint32_t timeout) {
    return ll_i2c_async.template InitMaster<clock_config>(bit_rate, timeout);
  }
  /**
   * @brief Get the I2C interrupt peripheral current status
   * @return current status
   */
  constexpr libmcu::Results GetStatus() {
    return static_cast<libmcu::Results>(state);
  }
  /**
   * @brief Transmit data to I2C device

   * @param address I2C device to transmit to
   * @param transmit_buffer Data to transmit
   * @param transaction_type Transaction type
   * @todo turn into transaction
   */
  constexpr libmcu::Results Transmit(const libmcu::I2cDeviceAddress address, const std::span<const std::uint8_t> transmit_buffer,
                                     AsyncInterface* callback = nullptr) {
    return AddTransaction(
      I2cTransaction{TransactionType::SingleWrite, address, transmit_buffer, std::span<std::uint8_t>(), callback});
  }
  /**
   * @brief Receive data from I2C device

   * @param address I2C device to receive from
   * @param receive_buffer place to put received data, needs to be at least size 1!
   * @todo turn into transaction
   */
  constexpr libmcu::Results Receive(const libmcu::I2cDeviceAddress address, std::span<std::uint8_t> receive_buffer,
                                    AsyncInterface* callback = nullptr) {
    return AddTransaction(
      I2cTransaction{TransactionType::SingleRead, address, std::span<std::uint8_t>(), receive_buffer, callback});
  }
  /**
   * @brief Start a master transmit
   * Opens the I2C bus state and transmit a block of data

   * @param address I2C device to transmit to
   * @param transmit_buffer Data bytes to transmit after address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcu::I2cDeviceAddress address,
                                                const std::span<const std::uint8_t> transmit_buffer,
                                                AsyncInterface* callback = nullptr) {
    return AddTransaction(
      I2cTransaction{TransactionType::StartWrite, address, transmit_buffer, std::span<std::uint8_t>(), callback});
  }
  /**
   * @brief Start a master transmit
   * Opens the I2C bus state

   * @param address I2C device to transmit to
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(const libmcu::I2cDeviceAddress address, AsyncInterface* callback = nullptr) {
    return AddTransaction(
      I2cTransaction{TransactionType::StartWrite, address, std::span<std::uint8_t>(), std::span<std::uint8_t>(), callback});
  }
  /**
   * @brief Continue a master transmit
   * Continues a master transmit with a block of data

   * @param transmit_buffer Data bytes to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(const std::span<const std::uint8_t> transmit_buffer,
                                                   AsyncInterface* callback = nullptr) {
    return AddTransaction(I2cTransaction{TransactionType::ContinueWrite, 0, transmit_buffer, std::span<std::uint8_t>(), callback});
  }
  // @todo read and continue read operations here
  /**
   * @brief Stop a master transmit
   * @todo add variants where you can pass a buffer to transmit/receive

   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StopMasterTransmit(const std::span<const std::uint8_t> transmit_buffer,
                                               AsyncInterface* callback = nullptr) {
    return AddTransaction(I2cTransaction{TransactionType::StopWrite, 0, transmit_buffer, std::span<std::uint8_t>(), callback});
  }
  /**
   * @brief Start a master receive
   * Opens the I2C bus state and receive a block of data
   * @param address I2C device to receive to
   * @param receive_buffer Data bytes to receive after address
   * @param callback Callback when completed
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterReceive(const libmcu::I2cDeviceAddress address, std::span<std::uint8_t> receive_buffer,
                                               AsyncInterface* callback = nullptr) {
    return AddTransaction(I2cTransaction{TransactionType::StartRead, address, std::span<std::uint8_t>(), receive_buffer, callback});
  }
  /**
   * @brief Start a master receive
   * Opens the I2C bus state
   * @param address I2C device to receive to
   * @param callback Callback when completed
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterReceive(const libmcu::I2cDeviceAddress address, AsyncInterface* callback = nullptr) {
    return AddTransaction(
      I2cTransaction{TransactionType::StartRead, address, std::span<std::uint8_t>(), std::span<std::uint8_t>(), callback});
  }
  /**
   * @brief Continue a master receive
   * Continues a master receive with a block of data
   * @param receive_buffer Data bytes to receive
   * @param callback Callback when completed
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterReceive(std::span<std::uint8_t> receive_buffer, AsyncInterface* callback = nullptr) {
    return AddTransaction(I2cTransaction{TransactionType::ContinueRead, 0, std::span<std::uint8_t>(), receive_buffer, callback});
  }
  /**
   * @brief Stop a master receive
   * @param receive_buffer Data bytes to receive
   * @param callback Callback when completed
   * @todo add variants where you can pass a buffer to transmit/receive
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StopMasterReceive(std::span<std::uint8_t> receive_buffer, AsyncInterface* callback = nullptr) {
    return AddTransaction(I2cTransaction{TransactionType::StopRead, 0, std::span<std::uint8_t>(), receive_buffer, callback});
  }
  /**
   * @brief
   * @param transaction
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results AddTransaction(I2cTransaction transaction) {
    if (!transactions.PushFront(transaction))
      return libmcu::Results::Full;
    else
      return libmcu::Results::NoError;
  }
  /**
   * @brief Continue operating any in-progress I2C operation
   * This should be periodically called to continue an in-progress I2C operation
   */
  constexpr void Progress() {
    if (state == libmcu::States::Idle && !transactions.IsEmpty()) {
      // we are idle but have elements in the queue
      Callback();  // call the callback so we start processing the queue
    }
    ll_i2c_async.Progress();
  }
  /**
   * @brief Callback method
   * Called from Progress when we are idle, otherwise from the LL driver when a transaction is complete
   */
  constexpr void Callback() {
    if (state == libmcu::States::Idle) {
      state = libmcu::States::Busy;
    } else {
      // We where busy so we got callback from I2C LL driver, handle transaction callback
      if (current_transaction.asyncInterface != nullptr) {
        current_transaction.asyncInterface->Callback();
      }
    }
    // Do we have any transactions left?
    if (!transactions.IsEmpty()) {
      // Process next element
      I2cTransaction element;
      transactions.PopBack(element);
      switch (element.type) {
        case TransactionType::SingleWrite:
          ll_i2c_async.Transmit(element.address, element.transmit_data, this);
          break;
        case TransactionType::StartWrite:
          ll_i2c_async.StartMasterTransmit(element.address, element.transmit_data, this);
          break;
        case TransactionType::ContinueWrite:
          ll_i2c_async.ContinueMasterTransmit(element.transmit_data, this);
          break;
        case TransactionType::StopWrite:
          ll_i2c_async.StopMasterTransmit(element.transmit_data, this);
          break;
        case TransactionType::SingleRead:
          ll_i2c_async.Receive(element.address, element.receive_data, this);
          break;
        case TransactionType::StartRead:
          ll_i2c_async.StartMasterReceive(element.address, element.receive_data, this);
          break;
        case TransactionType::ContinueRead:
          ll_i2c_async.ContinueMasterReceive(element.receive_data, this);
          break;
        case TransactionType::StopRead:
          ll_i2c_async.StopMasterReceive(element.receive_data, this);
          break;
        case TransactionType::EmptyEntry:
          [[fallthrough]];
        default:
          // do nothing, but should not happen!
          break;
      }
      current_transaction = element;
    } else {
      // No switch to idle
      state = libmcu::States::Idle;
    }
  }

 private:
  libmcu::States state = libmcu::States::Idle;
  libmcu::RingBuffer<I2cTransaction, max_transactions> transactions;
  I2cTransaction current_transaction;
};

}  // namespace libmcuhal::i2c

#endif