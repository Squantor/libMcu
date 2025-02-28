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

using DescriptorTable = std::array<hardware::DmaDescriptor, hardware::kChannelCount>;

/**
 * @brief DMA channels
 */
enum class Descriptors : std::size_t {
  kChannel0 = 0,
  kChannel1 = 1,
  kChannel2 = 2,
  kChannel3 = 3,
  kChannel4 = 4,
  kChannel5 = 5,
  kChannel6 = 6,
  kChannel7 = 7,
  kChannel8 = 8,
  kChannel9 = 9,
  kChannel10 = 10,
  kChannel11 = 11,
  kChannel12 = 12,
  kChannel13 = 13,
  kChannel14 = 14,
  kChannel15 = 15,
  kChannel16 = 16,
  kChannel17 = 17,
  kChannel18 = 18,
  kChannel19 = 19,
  kChannel20 = 20,
  kChannel21 = 21,
  kChannel22 = 22,
  kChannel23 = 23,
  kChannel24 = 24
};

/**
 * @brief DMA burst sizes
 */
enum class BurstSizes : std::uint32_t {
  k1 = hardware::CFG::BURSTSIZE_1,
  k2 = hardware::CFG::BURSTSIZE_2,
  k4 = hardware::CFG::BURSTSIZE_4,
  k8 = hardware::CFG::BURSTSIZE_8,
  k16 = hardware::CFG::BURSTSIZE_16,
  k32 = hardware::CFG::BURSTSIZE_32,
  k64 = hardware::CFG::BURSTSIZE_64,
  k128 = hardware::CFG::BURSTSIZE_128,
  k256 = hardware::CFG::BURSTSIZE_256,
  k512 = hardware::CFG::BURSTSIZE_512,
  k1024 = hardware::CFG::BURSTSIZE_1024
};

/**
 * @brief DMA trigger configurations
 */
enum class TriggerConfigs : std::uint32_t {
  kNone = 0u,
  kFallingEdge = hardware::CFG::HWTRIGEN,
  kRisingEdge = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGPOL,
  kLowLevel = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGTYPE,
  kHighLevel = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGTYPE | hardware::CFG::TRIGPOL,
  kFallingEdgeBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST,
  kRisingEdgeBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGPOL,
  kLowLevelBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGTYPE,
  kHighLevelBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGTYPE | hardware::CFG::TRIGPOL
};
/**
 * @brief DMA channel priorities
 */
enum class ChannelPrios : std::uint32_t {
  kHighest = hardware::CFG::CHPRIO_0,
  k0 = hardware::CFG::CHPRIO_0,
  k1 = hardware::CFG::CHPRIO_1,
  k2 = hardware::CFG::CHPRIO_2,
  k3 = hardware::CFG::CHPRIO_3,
  k4 = hardware::CFG::CHPRIO_4,
  k5 = hardware::CFG::CHPRIO_5,
  k6 = hardware::CFG::CHPRIO_6,
  k7 = hardware::CFG::CHPRIO_7,
  kLowest = hardware::CFG::CHPRIO_7,
};
/**
 * @brief interrupt flag set options
 */
enum class InterruptFlags : std::uint32_t {
  kNone = 0u,
  kSetA = hardware::XFERCFG::SETINTA,
  kSetB = hardware::XFERCFG::SETINTB,
  kSetAB = hardware::XFERCFG::SETINTA | hardware::XFERCFG::SETINTB,
};
/**
 * @brief Transfer bit widths
 */
enum class TransferSizes : std::uint32_t {
  k8Bit = hardware::XFERCFG::WIDTH_8BIT,
  k16Bit = hardware::XFERCFG::WIDTH_16BIT,
  k32Bit = hardware::XFERCFG::WIDTH_32BIT,
};
/**
 * @brief Source increments
 */
enum class SrcIncrements : std::uint32_t {
  k0 = hardware::XFERCFG::SRCINC_NONE,
  k1 = hardware::XFERCFG::SRCINC_1xWIDTH,
  k2 = hardware::XFERCFG::SRCINC_2xWIDTH,
  k4 = hardware::XFERCFG::SRCINC_4xWIDTH
};
/**
 * @brief Destination increments
 */
enum class DstIncrements : std::uint32_t {
  k0 = hardware::XFERCFG::DSTINC_NONE,
  k1 = hardware::XFERCFG::DSTINC_1xWIDTH,
  k2 = hardware::XFERCFG::DSTINC_2xWIDTH,
  k4 = hardware::XFERCFG::DSTINC_4xWIDTH
};

/**
 * @brief DMA low level interface class
 * @tparam dmaAddress_ address of the Input multiplexer peripheral
 */
template <libMcu::dmaBaseAddress dmaAddress>
struct Dma : libMcu::PeripheralBase {
  constexpr void Init() {
    DmaPeripheral()->SRAMBASE = reinterpret_cast<std::uint32_t>(descriptors_.data());
    DmaPeripheral()->CTRL = hardware::CTRL::ENABLE;
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param channel DMA channel to configure
   * @param sourceEnd source end address
   * @param destinationEnd destination end address
   * @param nextDescriptor pointer to next descriptor
   */
  constexpr void configureChanDescr(Descriptors channel, void *sourceEnd, void *destinationEnd,
                                    hardware::DmaDescriptor *nextDescriptor) {
    std::size_t index = static_cast<std::size_t>(channel);
    descriptors_[index].source_end_address = reinterpret_cast<std::uint32_t>(sourceEnd);
    descriptors_[index].destination_end_address = reinterpret_cast<std::uint32_t>(destinationEnd);
    if (nextDescriptor == nullptr)
      descriptors_[index].next_descriptor = reinterpret_cast<hardware::DmaDescriptor *>(0);
    else
      descriptors_[index].next_descriptor = nextDescriptor;
  }
  /**
   * @brief Configure a DMA channel
   * @param channel DMA channel to configure
   * @param trigger_config Trigger configuration, none is used for memory to memory
   * @param burst_size burst size per trigger
   * @param src_burst_wrap source burst wrapping enabled
   * @param dest_burst_wrap destination burst wrapping enabled
   * @param prio channel priority
   */
  constexpr void configureChannel(Descriptors channel, TriggerConfigs trigger_config, BurstSizes burst_size, bool src_burst_wrap,
                                  bool dest_burst_wrap, ChannelPrios prio) {
    std::size_t index = static_cast<std::size_t>(channel);
    std::uint32_t cfg_register = static_cast<std::uint32_t>(trigger_config) | static_cast<std::uint32_t>(burst_size);

    if (src_burst_wrap)
      cfg_register |= hardware::CFG::SRCBURSTWRAP;
    if (dest_burst_wrap)
      cfg_register |= hardware::CFG::DSTBURSTWRAP;
    cfg_register |= static_cast<std::uint32_t>(prio);

    DmaPeripheral()->CHANNEL[index].CFG = cfg_register;
  }
  /**
   * @brief Configure dma channel transfer
   * @param channel DMA channel to configure
   * @param reload reload after description has been exhausted
   * @param clear_trig_exhaust clear trigger after descriptor is exhausted
   * @param int_flags what interrupt flags to set when descriptor is exhausted
   * @param bits bits per transfer
   * @param src_inc source increment
   * @param dst_inc destination increment
   * @param count amount of transfers to execute
   */
  constexpr void configureTransfer(Descriptors channel, bool reload, bool clear_trig_exhaust, InterruptFlags int_flags,
                                   TransferSizes bits, SrcIncrements src_inc, DstIncrements dst_inc, std::size_t count) {
    std::size_t index = static_cast<std::size_t>(channel);
    std::uint32_t xfercfg_register = hardware::XFERCFG::XFERCOUNT(count);

    if (reload)
      xfercfg_register |= hardware::XFERCFG::RELOAD_MASK;
    if (clear_trig_exhaust)
      xfercfg_register |= hardware::XFERCFG::CLRTRIG;
    xfercfg_register |= static_cast<std::uint32_t>(int_flags);
    xfercfg_register |= static_cast<std::uint32_t>(bits);
    xfercfg_register |= static_cast<std::uint32_t>(src_inc);
    xfercfg_register |= static_cast<std::uint32_t>(dst_inc);

    DmaPeripheral()->CHANNEL[index].XFERCFG = xfercfg_register;
  }
  /**
   * @brief Validate channel configuration
   * @param channel DMA channel to validate
   */
  constexpr void validateChannel(Descriptors channel) {
    std::size_t index = static_cast<std::size_t>(channel);
    uint32_t set_valid_register = DmaPeripheral()->SETVALID;
    set_valid_register |= hardware::SETVALID::SV_MASK(index);
    DmaPeripheral()->SETVALID = set_valid_register;
  }
  /**
   * @brief get descriptor table from peripheral
   * @return return pointer to descriptor table
   */
  constexpr DescriptorTable &GetDescriptorTable() {
    return descriptors_;
  }

 private:
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral registers
   */
  constexpr static hardware::dma *DmaPeripheral() {
    return reinterpret_cast<hardware::dma *>(dmaAddress_);
  }

  static constexpr libMcu::hwAddressType dmaAddress_ = dmaAddress; /*!< peripheral address */
  alignas(512) DescriptorTable descriptors_;
};

}  // namespace libMcuLL::dma

#endif