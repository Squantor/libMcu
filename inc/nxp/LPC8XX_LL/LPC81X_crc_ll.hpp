/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_crc_ll.hpp
 * @brief LPC810 series CRC interface class and definitions
 */
#ifndef LPC81X_CRC_HPP
#define LPC81X_CRC_HPP

namespace libMcuLL::sw::crc {
namespace hardware = hw::crc;

template <libmcu::crcBaseAddress crcAddress_>
struct crc : libmcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  constexpr static hw::crc::crc *crcPeripheral() {
    return reinterpret_cast<hw::crc::crc *>(crcAddress_);
  }

 private:
  static constexpr libmcu::hwAddressType crcAddress = crcAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::sw::crc
#endif