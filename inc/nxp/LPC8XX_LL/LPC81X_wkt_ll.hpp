/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_wkt_ll.hpp
 * @brief LPC810 series wakeup timer interface class and definitions
 */
#ifndef LPC81X_WKT_HPP
#define LPC81X_WKT_HPP

namespace libmcull::sw::wkt {
using namespace libmcuhw::wkt;
template <libmcu::wktBaseAddress wktAddress_>
struct wkt {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to wkt registers
   */
  static libmcuhw::wkt::wkt *wktPeripheral() {
    return reinterpret_cast<libmcuhw::wkt::wkt *>(wktAddress);
  }

 private:
  static constexpr libmcu::hwAddressType wktAddress = wktAddress_; /*!< peripheral address */
};
}  // namespace libmcull::sw::wkt
#endif