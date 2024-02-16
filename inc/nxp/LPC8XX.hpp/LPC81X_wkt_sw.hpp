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

namespace libMcuLL {
namespace sw {
namespace wkt {
using namespace hw::wkt;
template <libMcuLL::WKTbaseAddress wktAddress_>
struct wkt {
  static constexpr libMcuLL::hwAddressType wktAddress = wktAddress_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to wkt registers
   */
  static hw::wkt::peripheral *wktPeripheral() {
    return reinterpret_cast<hw::wkt::peripheral *>(wktAddress);
  }
};
}  // namespace wkt
}  // namespace sw
}  // namespace libMcuLL

#endif