/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series windowed watchdog functions
 */
#ifndef LPC81X_WWDT_HPP
#define LPC81X_WWDT_HPP

namespace libMcuLL {
namespace sw {
namespace wwdt {
using namespace hw::wwdt;
template <libMcuLL::wwdtBaseAddress wwdtAddress_>
struct wwdt {
  static constexpr libMcuLL::hwAddressType wwdtAddress = wwdtAddress_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to windowed watchdog registers
   */
  static hw::wwdt::peripheral *wwdtPeripheral() {
    return reinterpret_cast<hw::wwdt::peripheral *>(wwdtAddress);
  }
};
}  // namespace wwdt
}  // namespace sw
}  // namespace libMcuLL

#endif