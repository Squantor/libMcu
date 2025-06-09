/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_dma_ll.hpp
 * @brief low level interface for the RP2040 DMA
 */
#ifndef RP2040_DMA_LL_HPP
#define RP2040_DMA_LL_HPP

namespace libmcull::dma {
namespace hardware = libmcuhw::dma;
/**
 * @brief
 * @tparam dma_address
 */
template <libmcu::DmaBaseAddress const& dma_address>
struct Dma : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hardware::Dma* GetPeripheral() {
    return reinterpret_cast<hardware::Dma*>(dma_address_);
  }

 private:
  static constexpr libmcu::HwAddressType dma_address_ = dma_address; /*!< peripheral address */
};
}  // namespace libmcull::dma
#endif