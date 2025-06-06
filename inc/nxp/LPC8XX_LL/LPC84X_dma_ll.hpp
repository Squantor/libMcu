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

namespace libmcull::dma {

namespace hardware = libmcuhw::dma;

using DescriptorTable = std::array<hardware::DmaDescriptor, hardware::kChannelCount>;

/**
 * @brief DMA channels
 */
enum class SoftwareDescriptors : std::size_t {
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
 * @brief DMA peripheral request input mapping to channels
 */
enum class HardwareDescriptors : std::uint32_t {
  kUSART0_RX_DMA = hardware::kUSART0_RX_DMA, /*!< USART0 RX DMA request input */
  kUSART0_TX_DMA = hardware::kUSART0_TX_DMA, /*!< USART0 TX DMA request input */
  kUSART1_RX_DMA = hardware::kUSART1_RX_DMA, /*!< USART1 RX DMA request input */
  kUSART1_TX_DMA = hardware::kUSART1_TX_DMA, /*!< USART1 TX DMA request input */
  kUSART2_RX_DMA = hardware::kUSART2_RX_DMA, /*!< USART2 RX DMA request input */
  kUSART2_TX_DMA = hardware::kUSART2_TX_DMA, /*!< USART2 TX DMA request input */
  kUSART3_RX_DMA = hardware::kUSART3_RX_DMA, /*!< USART3 RX DMA request input */
  kUSART3_TX_DMA = hardware::kUSART3_TX_DMA, /*!< USART3 TX DMA request input */
  kUSART4_RX_DMA = hardware::kUSART4_RX_DMA, /*!< USART4 RX DMA request input */
  kUSART4_TX_DMA = hardware::kUSART4_TX_DMA, /*!< USART4 TX DMA request input */
  kSPI0_RX_DMA = hardware::kSPI0_RX_DMA,     /*!< SPI0 RX DMA request input */
  kSPI0_TX_DMA = hardware::kSPI0_TX_DMA,     /*!< SPI0 TX DMA request input */
  kSPI1_RX_DMA = hardware::kSPI1_RX_DMA,     /*!< SPI1 RX DMA request input */
  kSPI1_TX_DMA = hardware::kSPI1_TX_DMA,     /*!< SPI1 TX DMA request input */
  kI2C0_SLV_DMA = hardware::kI2C0_SLV_DMA,   /*!< I2C0 slave DMA request input */
  kI2C0_MST_DMA = hardware::kI2C0_MST_DMA,   /*!< I2C0 master DMA request input */
  kI2C1_SLV_DMA = hardware::kI2C1_SLV_DMA,   /*!< I2C1 slave DMA request input */
  kI2C1_MST_DMA = hardware::kI2C1_MST_DMA,   /*!< I2C1 master DMA request input */
  kI2C2_SLV_DMA = hardware::kI2C2_SLV_DMA,   /*!< I2C2 slave DMA request input */
  kI2C2_MST_DMA = hardware::kI2C2_MST_DMA,   /*!< I2C2 master DMA request input */
  kI2C3_SLV_DMA = hardware::kI2C3_SLV_DMA,   /*!< I2C3 slave DMA request input */
  kI2C3_MST_DMA = hardware::kI2C3_MST_DMA,   /*!< I2C3 master DMA request input */
  kDAC0_DMAREQ = hardware::kDAC0_DMAREQ,     /*!< DAC0 DMA request input */
  kDAC1_DMAREQ = hardware::kDAC1_DMAREQ,     /*!< DAC1 DMA request input */
  kCAPT_DMA = hardware::kCAPT_DMA,           /*!< Capture DMA request input */
};

/**
 * @brief DMA burst sizes
 */
enum class BurstSizes : std::uint32_t {
  k1 = hardware::CFG::kBURSTSIZE_1,      /*!< Burst size of 1 */
  k2 = hardware::CFG::kBURSTSIZE_2,      /*!< Burst size of 2 */
  k4 = hardware::CFG::kBURSTSIZE_4,      /*!< Burst size of 4 */
  k8 = hardware::CFG::kBURSTSIZE_8,      /*!< Burst size of 8 */
  k16 = hardware::CFG::kBURSTSIZE_16,    /*!< Burst size of 16 */
  k32 = hardware::CFG::kBURSTSIZE_32,    /*!< Burst size of 32 */
  k64 = hardware::CFG::kBURSTSIZE_64,    /*!< Burst size of 64 */
  k128 = hardware::CFG::kBURSTSIZE_128,  /*!< Burst size of 128 */
  k256 = hardware::CFG::kBURSTSIZE_256,  /*!< Burst size of 256 */
  k512 = hardware::CFG::kBURSTSIZE_512,  /*!< Burst size of 512 */
  k1024 = hardware::CFG::kBURSTSIZE_1024 /*!< Burst size of 1024 */
};

/**
 * @brief DMA trigger configurations
 */
enum class TriggerConfigs : std::uint32_t {
  /*!< No trigger configuration */
  kNone = 0u,
  /*!< Falling edge trigger */
  kFallingEdge = hardware::CFG::kHWTRIGEN,
  /*!< Rising edge trigger */
  kRisingEdge = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGPOL,
  /*!< Low level trigger */
  kLowLevel = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGTYPE,
  /*!< High level trigger */
  kHighLevel = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGTYPE | hardware::CFG::kTRIGPOL,
  /*!< Falling edge trigger with burst transfer enabled */
  kFallingEdgeBurst = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGBURST,
  /*!< Rising edge trigger with burst transfer enabled */
  kRisingEdgeBurst = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGBURST | hardware::CFG::kTRIGPOL,
  /*!< Low level trigger with burst transfer enabled */
  kLowLevelBurst = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGBURST | hardware::CFG::kTRIGTYPE,
  /*!< High level trigger with burst transfer enabled */
  kHighLevelBurst = hardware::CFG::kHWTRIGEN | hardware::CFG::kTRIGBURST | hardware::CFG::kTRIGTYPE | hardware::CFG::kTRIGPOL
};
/**
 * @brief DMA channel priorities
 */
enum class ChannelPrios : std::uint32_t {
  kHighest = hardware::CFG::kCHPRIO_0,
  k0 = hardware::CFG::kCHPRIO_0,
  k1 = hardware::CFG::kCHPRIO_1,
  k2 = hardware::CFG::kCHPRIO_2,
  k3 = hardware::CFG::kCHPRIO_3,
  k4 = hardware::CFG::kCHPRIO_4,
  k5 = hardware::CFG::kCHPRIO_5,
  k6 = hardware::CFG::kCHPRIO_6,
  k7 = hardware::CFG::kCHPRIO_7,
  kLowest = hardware::CFG::kCHPRIO_7,
};
/**
 * @brief interrupt flag set options
 */
enum class InterruptFlags : std::uint32_t {
  kNone = 0u,
  kSetA = hardware::XFERCFG::kSETINTA,
  kSetB = hardware::XFERCFG::kSETINTB,
  kSetAB = hardware::XFERCFG::kSETINTA | hardware::XFERCFG::kSETINTB,
};
/**
 * @brief Transfer bit widths
 */
enum class TransferSizes : std::uint32_t {
  k8Bit = hardware::XFERCFG::kWIDTH_8BIT,
  k16Bit = hardware::XFERCFG::kWIDTH_16BIT,
  k32Bit = hardware::XFERCFG::kWIDTH_32BIT,
};
/**
 * @brief Source increments
 */
enum class SrcIncrements : std::uint32_t {
  k0 = hardware::XFERCFG::kSRCINC_NONE,
  k1 = hardware::XFERCFG::kSRCINC_1xWIDTH,
  k2 = hardware::XFERCFG::kSRCINC_2xWIDTH,
  k4 = hardware::XFERCFG::kSRCINC_4xWIDTH
};
/**
 * @brief Destination increments
 */
enum class DstIncrements : std::uint32_t {
  k0 = hardware::XFERCFG::kDSTINC_NONE,
  k1 = hardware::XFERCFG::kDSTINC_1xWIDTH,
  k2 = hardware::XFERCFG::kDSTINC_2xWIDTH,
  k4 = hardware::XFERCFG::kDSTINC_4xWIDTH
};

/**
 * @brief DMA low level interface class
 * @tparam dmaAddress_ address of the Input multiplexer peripheral
 */
template <libmcu::DmaBaseAddress dma_address>
struct Dma : libmcu::PeripheralBase {
  constexpr void Init() {
    descriptors_.fill({0, 0, 0, nullptr});
    DmaPeripheral()->SRAMBASE = reinterpret_cast<std::uint32_t>(descriptors_.data());
    DmaPeripheral()->CTRL = hardware::CTRL::kENABLE;
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param software_channel DMA channel to configure
   * @param sourceEnd source end address
   * @param destinationEnd destination end address
   * @param nextDescriptor pointer to next descriptor
   */
  constexpr void ConfigureChanDescr(SoftwareDescriptors software_channel, void *sourceEnd, void *destinationEnd,
                                    hardware::DmaDescriptor *nextDescriptor) {
    ConfigureChanDescr(static_cast<std::size_t>(software_channel), reinterpret_cast<std::uint32_t>(sourceEnd),
                       reinterpret_cast<std::uint32_t>(destinationEnd), nextDescriptor);
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param hardware_channel hardware DMA channel to configure
   * @param source_end source end address
   * @param dest_end destination end address
   * @param next_descriptor pointer to next descriptor
   */
  constexpr void ConfigureChanDescr(HardwareDescriptors hardware_channel, std::uint32_t source_end_address, void *dest_end,
                                    hardware::DmaDescriptor *next_descriptor) {
    ConfigureChanDescr(static_cast<std::size_t>(hardware_channel), source_end_address, reinterpret_cast<std::uint32_t>(dest_end),
                       next_descriptor);
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param hardware_channel hardware DMA channel to configure
   * @param source_end source end address
   * @param dest_end destination end address
   * @param next_descriptor pointer to next descriptor
   */
  constexpr void ConfigureChanDescr(HardwareDescriptors hardware_channel, void *source_end, std::uint32_t dest_end_address,
                                    hardware::DmaDescriptor *next_descriptor) {
    ConfigureChanDescr(static_cast<std::size_t>(hardware_channel), reinterpret_cast<std::uint32_t>(source_end),
                       reinterpret_cast<std::uint32_t>(dest_end_address), next_descriptor);
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param hardware_channel hardware DMA channel to configure
   * @param source_end source end address
   * @param dest_end destination end address
   * @param next_descriptor pointer to next descriptor
   */
  constexpr void ConfigureChanDescr(HardwareDescriptors hardware_channel, void *source_end, void *dest_end,
                                    hardware::DmaDescriptor *next_descriptor) {
    ConfigureChanDescr(static_cast<std::size_t>(hardware_channel), reinterpret_cast<std::uint32_t>(source_end),
                       reinterpret_cast<std::uint32_t>(dest_end), next_descriptor);
  }
  /**
   * @brief Configures a DMA channel descriptor
   * @param index DMA channel index to configure
   * @param sourceEnd source end address
   * @param destinationEnd destination end address
   * @param nextDescriptor pointer to next descriptor
   */
  constexpr void ConfigureChanDescr(std::size_t index, std::uint32_t source_end_address, std::uint32_t dest_end_address,
                                    hardware::DmaDescriptor *nextDescriptor) {
    descriptors_[index].source_end_address = source_end_address;
    descriptors_[index].destination_end_address = dest_end_address;
    if (nextDescriptor == nullptr)
      descriptors_[index].next_descriptor = reinterpret_cast<hardware::DmaDescriptor *>(0);
    else
      descriptors_[index].next_descriptor = nextDescriptor;
  }
  /**
   * @brief Configure a DMA channel
   * @param software_channel DMA channel to configure
   * @param trigger_config Trigger configuration, none is used for memory to memory
   * @param burst_size burst size per trigger
   * @param src_burst_wrap source burst wrapping enabled
   * @param dest_burst_wrap destination burst wrapping enabled
   * @param prio channel priority
   */
  constexpr void ConfigureChannel(SoftwareDescriptors software_channel, TriggerConfigs trigger_config, BurstSizes burst_size,
                                  bool src_burst_wrap, bool dest_burst_wrap, ChannelPrios prio) {
    std::size_t index = static_cast<std::size_t>(software_channel);
    std::uint32_t cfg_register = static_cast<std::uint32_t>(trigger_config) | static_cast<std::uint32_t>(burst_size);

    if (src_burst_wrap)
      cfg_register |= hardware::CFG::kSRCBURSTWRAP;
    if (dest_burst_wrap)
      cfg_register |= hardware::CFG::kDSTBURSTWRAP;
    cfg_register |= static_cast<std::uint32_t>(prio);

    DmaPeripheral()->CHANNEL[index].CFG = cfg_register;
  }
  /**
   * @brief Configure a DMA channel
   * @param hardware_channel hardware DMA channel to configure
   * @param trigger_config Trigger configuration, none is used for memory to memory
   * @param burst_size burst size per trigger
   * @param src_burst_wrap source burst wrapping enabled
   * @param dest_burst_wrap destination burst wrapping enabled
   * @param prio channel priority
   * @bug The priority value is not written correctly to the register, MSB is missing, writing 7 results in 3
   */
  constexpr void ConfigureChannel(HardwareDescriptors hardware_channel, TriggerConfigs trigger_config, BurstSizes burst_size,
                                  bool src_burst_wrap, bool dest_burst_wrap, ChannelPrios prio) {
    std::size_t index = static_cast<std::size_t>(hardware_channel);
    std::uint32_t cfg_register =
      static_cast<std::uint32_t>(trigger_config) | static_cast<std::uint32_t>(burst_size) | hardware::CFG::kPERIPHREQEN;

    if (src_burst_wrap)
      cfg_register |= hardware::CFG::kSRCBURSTWRAP;
    if (dest_burst_wrap)
      cfg_register |= hardware::CFG::kDSTBURSTWRAP;
    cfg_register |= static_cast<std::uint32_t>(prio);

    DmaPeripheral()->CHANNEL[index].CFG = cfg_register;
  }
  /**
   * @brief Configure dma channel transfer
   * @param software_channel DMA channel to configure
   * @param reload reload after description has been exhausted
   * @param clear_trig_exhaust clear trigger after descriptor is exhausted
   * @param int_flags what interrupt flags to set when descriptor is exhausted
   * @param bits bits per transfer
   * @param src_inc source increment
   * @param dst_inc destination increment
   * @param count amount of transfers to execute
   */
  constexpr void ConfigureTransfer(SoftwareDescriptors software_channel, bool reload, bool clear_trig_exhaust,
                                   InterruptFlags int_flags, TransferSizes bits, SrcIncrements src_inc, DstIncrements dst_inc,
                                   std::size_t count) {
    std::size_t index = static_cast<std::size_t>(software_channel);
    std::uint32_t xfercfg_register = hardware::XFERCFG::XFERCOUNT(count) | hardware::XFERCFG::kSWTRIG;

    if (reload)
      xfercfg_register |= hardware::XFERCFG::kRELOAD_MASK;
    if (clear_trig_exhaust)
      xfercfg_register |= hardware::XFERCFG::kCLRTRIG;
    xfercfg_register |= static_cast<std::uint32_t>(int_flags);
    xfercfg_register |= static_cast<std::uint32_t>(bits);
    xfercfg_register |= static_cast<std::uint32_t>(src_inc);
    xfercfg_register |= static_cast<std::uint32_t>(dst_inc);

    DmaPeripheral()->CHANNEL[index].XFERCFG = xfercfg_register;
  }
  /**
   * @brief Configure dma channel transfer
   * @param hardware_channel DMA channel to configure
   * @param reload reload after description has been exhausted
   * @param clear_trig_exhaust clear trigger after descriptor is exhausted
   * @param int_flags what interrupt flags to set when descriptor is exhausted
   * @param bits bits per transfer
   * @param src_inc source increment
   * @param dst_inc destination increment
   * @param count amount of transfers to execute
   */
  constexpr void ConfigureTransfer(HardwareDescriptors hardware_channel, bool reload, bool clear_trig_exhaust,
                                   InterruptFlags int_flags, TransferSizes bits, SrcIncrements src_inc, DstIncrements dst_inc,
                                   std::size_t count) {
    std::size_t index = static_cast<std::size_t>(hardware_channel);
    std::uint32_t xfercfg_register = hardware::XFERCFG::XFERCOUNT(count);

    if (reload)
      xfercfg_register |= hardware::XFERCFG::kRELOAD_MASK;
    if (clear_trig_exhaust)
      xfercfg_register |= hardware::XFERCFG::kCLRTRIG;
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
  constexpr void ValidateChannel(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->SETVALID = hardware::SETVALID::SV_MASK(channel_value);
  }
  /**
   * @brief Validate channel configuration
   * @param channel Hardware DMA channel to validate
   */
  constexpr void ValidateChannel(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->SETVALID = hardware::SETVALID::SV_MASK(channel_value);
  }
  /**
   * @brief Set channel trigger
   * @param channel DMA channel to trigger
   */
  constexpr void SetChannelTrigger(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->SETTRIG = hardware::SETTRIG::TRIG_MASK(channel_value);
  }
  /**
   * @brief Set channel trigger
   * @param channel Hardware DMA channel to trigger
   */
  constexpr void SetChannelTrigger(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->SETTRIG = hardware::SETTRIG::TRIG_MASK(channel_value);
  }
  /**
   * @brief Enable channel
   * @param channel DMA channel to enable
   */
  constexpr void EnableChannel(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->ENABLESET = hardware::ENABLESET::ENA(channel_value);
  }
  /**
   * @brief Enable channel
   * @param channel Hardware DMA channel to enable
   */
  constexpr void EnableChannel(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    DmaPeripheral()->ENABLESET = hardware::ENABLESET::ENA(channel_value);
  }
  /**
   * @brief Is the current channel active
   * @param channel DMA channel to check
   */
  constexpr bool IsChannelActive(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::ACTIVE::ACT_MASK(channel_value) & DmaPeripheral()->ACTIVE) != 0;
  }
  /**
   * @brief Is the current channel active
   * @param channel Hardware DMA channel to check
   */
  constexpr bool IsChannelActive(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::ACTIVE::ACT_MASK(channel_value) & DmaPeripheral()->ACTIVE) != 0;
  }
  /**
   * @brief Is the current channel busy
   * @param channel DMA channel to check
   */
  constexpr bool IsChannelBusy(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::kBusy::BSY_MASK(channel_value) & DmaPeripheral()->kBusy) != 0;
  }
  /**
   * @brief Is the current channel busy
   * @param channel Hardware DMA channel to check
   */
  constexpr bool IsChannelBusy(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::kBusy::BSY_MASK(channel_value) & DmaPeripheral()->kBusy) != 0;
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
  constexpr static hardware::Dma *DmaPeripheral() {
    return reinterpret_cast<hardware::Dma *>(dmaAddress_);
  }

  static constexpr libmcu::HwAddressType dmaAddress_ = dma_address; /*!< peripheral address */
  alignas(512) DescriptorTable descriptors_;
};

}  // namespace libmcull::dma

#endif