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
template <libMcuLL::CRCbaseAddress address_>
struct crc {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  static hw::crc::peripheral *peripheral() {
    return reinterpret_cast<hw::crc::peripheral *>(address_);
  }
};
}  // namespace crc
}  // namespace sw
}  // namespace libMcuLL

#endif