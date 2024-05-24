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

namespace libMcuLL {
namespace sw {
namespace crc {
using namespace hw::crc;
template <libMcuLL::crcBaseAddress crcAddress_>
struct crc : libMcuLL::peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  constexpr static hw::crc::peripheral *crcPeripheral() {
    return reinterpret_cast<hw::crc::peripheral *>(crcAddress_);
  }

 private:
  static constexpr libMcuLL::hwAddressType crcAddress = crcAddress_; /**< peripheral address */
};
}  // namespace crc
}  // namespace sw
}  // namespace libMcuLL

#endif