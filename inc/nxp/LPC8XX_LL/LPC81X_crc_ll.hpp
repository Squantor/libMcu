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

namespace libmcull::crc {
namespace hardware = libmcuhw::crc;
/**
 * @brief
 * @tparam crcAddress_
 */
template <libmcu::CrcBaseAddress crcAddress_>
struct Crc : libmcull::PeripheralBase {
  /**
   * @brief get registers from peripheral
   * @return return pointer to CRC registers
   */
  constexpr static libmcuhw::crc::Crc *crcPeripheral() {
    return reinterpret_cast<libmcuhw::crc::Crc *>(crcAddress_);
  }

 private:
  static constexpr libmcu::HwAddressType crcAddress = crcAddress_; /*!< peripheral address */
};
}  // namespace libmcull::crc
#endif