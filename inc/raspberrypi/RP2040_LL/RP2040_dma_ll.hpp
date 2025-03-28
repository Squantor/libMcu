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
#ifndef RP2040_DMA_SW_HPP
#define RP2040_DMA_SW_HPP

namespace libMcuLL::dma {
namespace hardware = libMcuHw::dma;
template <libMcu::dmaBaseAddress const& dmaAddress_>
struct Dma : libMcu::PeripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hardware::dma* dmaPeripheral() {
    return reinterpret_cast<hardware::dma*>(dmaAddress);
  }

 private:
  static constexpr libMcu::hwAddressType dmaAddress = dmaAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::dma
#endif