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

namespace libmcull::sw::wwdt {
using namespace libmcuhw::wwdt;
template <libmcu::wwdtBaseAddress wwdtAddress_>
struct wwdt {
  static constexpr libmcu::hwAddressType wwdtAddress = wwdtAddress_; /*!< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to windowed watchdog registers
   */
  static libmcuhw::wwdt::wwdt *wwdtPeripheral() {
    return reinterpret_cast<libmcuhw::wwdt::wwdt *>(wwdtAddress);
  }
};
}  // namespace libmcull::sw::wwdt
#endif