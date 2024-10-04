/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series CRC functions
 */
#ifndef LPC81X_CRC_HPP
#define LPC81X_CRC_HPP

namespace libMcuLL::sw::crc {
using namespace hw::crc;
template <libMcu::crcBaseAddress crcAddress_>
struct crc : libMcu::peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  constexpr static hw::crc::peripheral *crcPeripheral() {
    return reinterpret_cast<hw::crc::peripheral *>(crcAddress_);
  }

 private:
  static constexpr libMcu::hwAddressType crcAddress = crcAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::crc
#endif