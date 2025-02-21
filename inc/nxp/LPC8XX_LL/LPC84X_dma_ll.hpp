/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_dma_ll.hpp
 * @brief LPC84X series DMA low level functions
 */
#ifndef LPC84X_DMA_LL_HPP
#define LPC84X_DMA_LL_HPP

#include <array>

namespace libMcuLL::dma {
namespace hardware = libMcuHw::dma;

using dmaDescriptorTable = std::array<hardware::dma_desc, hardware::channelCount>;

/**
 * @brief DMA low level interface class
 * @tparam dmaAddress_ address of the Input multiplexer peripheral
 */
template <libMcu::dmaBaseAddress dmaAddress_>
struct dma : libMcu::peripheralBase {
  constexpr void init() {
    dmaPeripheral()->SRAMBASE = reinterpret_cast<std::uint32_t>(descriptorTable.data());
    dmaPeripheral()->CTRL = hardware::CTRL::ENABLE;
  }
  /**
   * @brief get descriptor table from peripheral
   * @return return pointer to descriptor table
   */
  constexpr dmaDescriptorTable &getDescriptorTable() {
    return descriptorTable;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral registers
   */
  constexpr static hardware::dma *dmaPeripheral() {
    return reinterpret_cast<hardware::dma *>(dmaAddress);
  }

 private:
  static constexpr libMcu::hwAddressType dmaAddress = dmaAddress_; /*!< peripheral address */
  alignas(512) dmaDescriptorTable descriptorTable;
};

}  // namespace libMcuLL::dma

#endif