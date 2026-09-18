/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file 24xxx.hpp
 * @brief Driver for the 24XXX series I2C EEPROM
 */
#ifndef EEPROM_24XXX_HPP
#define EEPROM_24XXX_HPP

#include "../libmcu/libmcudrv.hpp"
#include "eeprom_24xxx/eeprom_24xxx_configs.hpp"

namespace libmcudrv::eeprom_24xxx {
namespace i2c = libmcuhal::i2c;
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address, auto &config,
          libmcu::Assert_concept assert_policy = libmcu::Assert_default>
struct Eeprom_24xxx : public DriverBase, public libmcu::NonBlocking {
  /**
   * @brief Initializes the driver and checks if the device is present
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results init() {
    state = libmcu::States::Initializing;
    // Set internal EEPROM read/write address to zero
    address_buffer[0] = 0;
    i2c_hal.Transmit(i2c_address, address_buffer, this);
    return libmcu::Results::NoError;
  }
  /**
   * @todo Reads data from the EEPROM
   */
  void read(std::size_t address, std::span<std::uint8_t> buffer, libmcu::NonBlocking *callback = nullptr) {
    address_buffer[0] = address;
    i2c_hal.Transmit(i2c_address, address_buffer);
    i2c_hal.Receive(i2c_address, buffer, callback);
  }
  /**
   * @todo Writes data to the EEPROM
   */
  void write(std::size_t address, std::span<const std::uint8_t> buffer, libmcu::NonBlocking *callback = nullptr) {
    address_buffer[0] = address;
    i2c_hal.StartMasterTransmit(i2c_address, address_buffer);
    i2c_hal.StopMasterTransmit(buffer, callback);
  }
  /**
   * @brief Progress function, not used
   */
  constexpr void progress(void) final {}
  /**
   * @brief Callback used by I2C HAL
   * @param result Transaction result
   */
  constexpr void callback(libmcu::Results result) final {
    switch (state) {
      case libmcu::States::Initializing:
      case libmcu::States::Busy:
        if (result == libmcu::Results::NoError) {
          state = libmcu::States::Idle;
        } else {
          assert_fail_if(false, "I2C HAL error");
          state = libmcu::States::ErrorFatal;
        }
        break;

      default:
        break;
    }
  }

  constexpr std::size_t size() const noexcept {
    return config.bytes;
  }

  constexpr std::size_t page_size() const noexcept {
    return config.page_size;
  }

  constexpr std::size_t page_count() const noexcept {
    return config.bytes / config.page_size;
  }

  libmcu::States state = libmcu::States::Initializing;  //< State of the driver
 private:
  /**
   * @brief Asserts if a condition is true
   * @param cond Condition to check
   * @param msg Message to print
   */
  constexpr void assert_fail_if(bool cond, const char *msg) noexcept {
    if constexpr (assert_policy::enabled) {
      if (cond) {
        assert_policy::fail(msg);
      }
    }
  }
  std::array<std::uint8_t, config.address_size> address_buffer;  //< Buffer for an address
};
}  // namespace libmcudrv::eeprom_24xxx

#endif