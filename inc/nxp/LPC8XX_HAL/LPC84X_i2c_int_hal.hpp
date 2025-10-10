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
namespace lowlevel = libmcull::i2c;
template <libmcull::DerivedFromAsyncI2c auto& ll_i2c_async>
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
    async_handle_ = 0;
    return ll_i2c_async.template InitMaster<clock_config>(bit_rate, timeout);
  }
  /**
   * @brief Claim an the asynchronous interface
   * @param[out] handle for the claimed interface, set when claimed
   * @returns Claimed if successful
   * @returns for the rest see @ref libmcull::I2cInterrupt
   */
  libmcu::Results Claim(libmcu::AsyncHandle& handle) {
    libmcu::Results result = ll_i2c_async.Claim();
    if (result != libmcu::Results::Claimed)
      return result;
    handle = async_handle_;
    return result;
  }
  /**
   * @brief Release the asynchronous interface
   * @param handle for the interface to be released
   * @returns InUse if the interface is already in use by another claimant
   * @returns Unclaimed if the interface is not claimed
   * @returns for the rest see @ref libmcull::I2cInterrupt
   */
  libmcu::Results Unclaim(libmcu::AsyncHandle handle) {
    if (handle != async_handle_)
      return libmcu::Results::InUse;
    libmcu::Results result = ll_i2c_async.Unclaim();
    if (result != libmcu::Results::Unclaimed)
      return result;
    async_handle_ += 1;
    return result;
  }
  /**
   * @brief Get the I2C interrupt peripheral current status
   * @return current status
   */
  constexpr libmcu::Results GetStatus(libmcu::AsyncHandle handle) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.GetStatus();
  }
  /**
   * @brief Transmit data to I2C device
   * @param handle handle to use
   * @param address I2C device to transmit to
   * @param transmit_buffer Data to transmit
   * @param transaction_type Transaction type
   */
  constexpr libmcu::Results Transmit(libmcu::AsyncHandle handle, const libmcuhal::I2cDeviceAddress address,
                                     std::span<std::uint8_t> transmit_buffer,
                                     libmcu::TransactionType transaction_type = libmcu::TransactionType::Single) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.Transmit(address, transmit_buffer, transaction_type);
  }
  /**
   * @brief Receive data from I2C device
   * @param handle handle to use
   * @param address I2C device to receive from
   * @param receive_buffer place to put received data, needs to be at least size 1!
   */
  constexpr libmcu::Results Receive(libmcu::AsyncHandle handle, const libmcuhal::I2cDeviceAddress address,
                                    std::span<std::uint8_t> receive_buffer,
                                    libmcu::TransactionType transaction_type = libmcu::TransactionType::Single) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.Receive(address, receive_buffer, transaction_type);
  }
  /**
   * @brief Start a master transmit
   * Opens the I2C bus state and transmit a block of data
   * @param handle handle to use
   * @param address I2C device to transmit to
   * @param transmit_buffer Data bytes to transmit after address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(libmcu::AsyncHandle handle, const libmcuhal::I2cDeviceAddress address,
                                                const std::span<const std::uint8_t> transmit_buffer) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.StartMasterTransmit(address, transmit_buffer);
  }
  /**
   * @brief Start a master transmit
   * Opens the I2C bus state and transmits a single byte
   * @param handle handle to use
   * @param address I2C device to transmit to
   * @param data Data byte to transmit after address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(libmcu::AsyncHandle handle, const libmcuhal::I2cDeviceAddress address,
                                                std::uint8_t data) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.StartMasterTransmit(libmcull::I2cDeviceAddress{address.value}, data);
  }
  /**
   * @brief Start a master transmit
   * Opens the I2C bus state
   * @param handle handle to use
   * @param address I2C device to transmit to
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StartMasterTransmit(libmcu::AsyncHandle handle, const libmcuhal::I2cDeviceAddress address) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.StartMasterTransmit(address);
  }
  /**
   * @brief Continue a master transmit
   * Continues a master transmit with a block of data
   * @param handle handle to use
   * @param transmit_buffer Data bytes to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(libmcu::AsyncHandle handle,
                                                   const std::span<const std::uint8_t> transmit_buffer) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.ContinueMasterTransmit(transmit_buffer);
  }
  /**
   * @brief Continue a master transmit
   * Continues a master transmit with a single byte
   * @param handle handle to use
   * @param data Data byte to transmit
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results ContinueMasterTransmit(libmcu::AsyncHandle handle, std::uint8_t data) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.ContinueMasterTransmit(data);
  }
  /**
   * @brief Wait for a master operation to complete
   */
  constexpr void MasterWait() {
    ll_i2c_async.MasterWait();
  }
  /**
   * @brief Stop a master transmit
   * @param handle handle to use
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results StopMaster(libmcu::AsyncHandle handle) {
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    return ll_i2c_async.StopMaster();
  }
  // @todo read and continue read operations here
  /**
   * @brief Continue operating any in-progress I2C operation
   * This should be periodically called to continue an in-progress I2C operation
   */
  constexpr void Progress() {
    // @todo implement callback handling here for operation completion or error
  }

 private:
  libmcu::AsyncHandle async_handle_ = 0; /*!< Async handle to be passed to the claimant, incremented per claim/unclaim pair */
};

}  // namespace libmcuhal::i2c

#endif