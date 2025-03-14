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

namespace libMcuLL::sw::wwdt {
using namespace hw::wwdt;
template <libMcu::wwdtBaseAddress wwdtAddress_>
struct wwdt {
  static constexpr libMcu::hwAddressType wwdtAddress = wwdtAddress_; /*!< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to windowed watchdog registers
   */
  static hw::wwdt::wwdt *wwdtPeripheral() {
    return reinterpret_cast<hw::wwdt::wwdt *>(wwdtAddress);
  }
};
}  // namespace libMcuLL::sw::wwdt
#endif