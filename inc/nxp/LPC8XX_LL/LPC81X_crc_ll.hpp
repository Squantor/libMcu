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

namespace libmcull::sw::crc {
namespace hardware = libmcuhw::crc;

template <libmcu::crcBaseAddress crcAddress_>
struct crc : libmcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  constexpr static libmcuhw::crc::Crc *crcPeripheral() {
    return reinterpret_cast<libmcuhw::crc::Crc *>(crcAddress_);
  }

 private:
  static constexpr libmcu::hwAddressType crcAddress = crcAddress_; /*!< peripheral address */
};
}  // namespace libmcull::sw::crc
#endif