/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pio_ll.hpp
 * @brief low level interface for the RP2040 PIO
 */
#ifndef RP2040_PIO_SW_HPP
#define RP2040_PIO_SW_HPP

namespace libmcull::pio {
namespace hardware = libmcuhw::pio;
/**
 * @brief
 * @tparam pioAddress_
 */
template <libmcu::PioBaseAddress const& pioAddress_>
struct pio : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::pio* pioPeripheral() {
    return reinterpret_cast<hardware::pio*>(pioAddress);
  }

 private:
  static constexpr libmcu::HwAddressType pioAddress = pioAddress_; /*!< peripheral address */
};
}  // namespace libmcull::pio
#endif