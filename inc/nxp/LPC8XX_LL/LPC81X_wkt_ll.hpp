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

namespace libmcull::wkt {
namespace hardware = libmcuhw::wkt;
/**
 * @brief
 * @tparam wkt_address
 */
template <libmcu::WktBaseAddress wkt_address>
struct Wkt {
  /**
   * @brief get registers from peripheral
   * @return return pointer to wkt registers
   */
  static libmcuhw::wkt::Wkt *GetPeripheral() {
    return reinterpret_cast<libmcuhw::wkt::Wkt *>(wkt_address_);
  }

 private:
  static constexpr libmcu::HwAddressType wkt_address_ = wkt_address; /*!< peripheral address */
};
}  // namespace libmcull::wkt
#endif