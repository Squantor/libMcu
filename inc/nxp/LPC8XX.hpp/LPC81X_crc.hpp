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

namespace instances {
namespace crc {
using namespace registers::crc;
template <libMcuLL::CRCaddress address_>
struct crc {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to CRC registers
   */
  static auto regs() {
    return reinterpret_cast<registers::crc::registers *>(address_);
  }
};
}  // namespace crc
}  // namespace instances

#endif