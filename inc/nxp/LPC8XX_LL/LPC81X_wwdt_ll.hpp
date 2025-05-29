/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_wwdt_ll.hpp
 * @brief LPC810 series windowed watchdog interface class and definitions
 */
#ifndef LPC81X_WWDT_HPP
#define LPC81X_WWDT_HPP

namespace libmcull::wwdt {
using namespace libmcuhw::wwdt;
template <libmcu::WwdtBaseAddress wwdtAddress_>
struct Wwdt {
  static constexpr libmcu::HwAddressType wwdtAddress = wwdtAddress_; /*!< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to windowed watchdog registers
   */
  static libmcuhw::wwdt::Wwdt *wwdtPeripheral() {
    return reinterpret_cast<libmcuhw::wwdt::Wwdt *>(wwdtAddress);
  }
};
}  // namespace libmcull::wwdt
#endif