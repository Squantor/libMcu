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
 * @tparam crc_address
 */
template <libmcu::CrcBaseAddress crc_address_param>
struct Crc : libmcull::LowLevelBase {
  /**
   * @brief get registers from peripheral
   * @return return pointer to CRC registers
   */
  static constexpr libmcuhw::crc::Crc *get_peripheral() {
    return reinterpret_cast<libmcuhw::crc::Crc *>(crc_address);
  }

 private:
  static constexpr libmcu::HwAddressType crc_address = crc_address_param; /*!< peripheral address */
};
}  // namespace libmcull::crc
#endif