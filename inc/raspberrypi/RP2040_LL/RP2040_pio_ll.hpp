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
#ifndef RP2040_PIO_LL_HPP
#define RP2040_PIO_LL_HPP

namespace libmcull::pio {
namespace hardware = libmcuhw::pio;
/**
 * @brief
 * @tparam pio_address
 */
template <libmcu::PioBaseAddress const& pio_address>
struct Pio : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Pio* GetPeripheral() {
    return reinterpret_cast<hardware::Pio*>(pio_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pio_address_ = pio_address; /*!< peripheral address */
};
}  // namespace libmcull::pio
#endif