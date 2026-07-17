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
          libmcu::Assert_concept Assert = libmcu::Assert_default>
struct Eeprom_24xxx : public DriverBase, public libmcu::NonBlocking {
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results init() {
    state = libmcu::States::Initializing;
    address_buffer.fill(0);
    page_buffer.fill(0);
    i2c_hal.Transmit(i2c_address, address_buffer);
    i2c_hal.Receive(i2c_address, page_buffer, this);
    return libmcu::Results::NoError;
  }

  constexpr void test(void) {
    address_buffer[0] = 0;
    for (std::size_t i = 0; i < page_buffer.size(); i++) {
      page_buffer[i] = i;
    }
    i2c_hal.StartMasterTransmit(i2c_address, address_buffer);
    i2c_hal.StopMasterTransmit(page_buffer, this);
    state = libmcu::States::Busy;
  }

  constexpr void progress(void) final {}
  constexpr void callback(libmcu::Results) final {
    switch (state) {
      case libmcu::States::Initializing:
        state = libmcu::States::Idle;
        break;
      case libmcu::States::Busy:
        state = libmcu::States::Idle;
        break;

      default:
        break;
    }
  }
  libmcu::States state = libmcu::States::Initializing;  //< State of the driver
 private:
  std::array<std::uint8_t, config.address_size> address_buffer;                  //< Buffer for an address
  std::array<std::uint8_t, config.page_size + config.address_size> page_buffer;  //< Buffer for a page
};
}  // namespace libmcudrv::eeprom_24xxx

#endif