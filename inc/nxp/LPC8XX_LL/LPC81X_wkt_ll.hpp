/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series wakeup timer functions
 */
#ifndef LPC81X_WKT_HPP
#define LPC81X_WKT_HPP

namespace libMcuLL::sw::wkt {
using namespace libMcuLL::hw::wkt;
template <libMcu::wktBaseAddress wktAddress_>
struct wkt {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to wkt registers
   */
  static hw::wkt::peripheral *wktPeripheral() {
    return reinterpret_cast<hw::wkt::peripheral *>(wktAddress);
  }

 private:
  static constexpr libMcu::hwAddressType wktAddress = wktAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::wkt
#endif