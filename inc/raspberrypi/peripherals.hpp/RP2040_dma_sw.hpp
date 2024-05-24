/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 DMA software interface
 */
#ifndef RP2040_DMA_SW_HPP
#define RP2040_DMA_SW_HPP

namespace libMcuLL::sw::dma {
template <libMcuLL::dmaBaseAddress const& dmaAddress_>
struct dma : libMcuLL::peripheralBase {
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
  static hw::dma::peripheral* dmaPeripheral() {
    return reinterpret_cast<hw::dma::peripheral*>(dmaAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType dmaAddress = dmaAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::dma
#endif