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

using DescriptorTable = std::array<hardware::DmaDescriptor, hardware::ChannelCount>;

/**
 * @brief DMA channels
 */
enum class SoftwareDescriptors : std::size_t {
  Channel0 = 0,
  Channel1 = 1,
  Channel2 = 2,
  Channel3 = 3,
  Channel4 = 4,
  Channel5 = 5,
  Channel6 = 6,
  Channel7 = 7,
  Channel8 = 8,
  Channel9 = 9,
  Channel10 = 10,
  Channel11 = 11,
  Channel12 = 12,
  Channel13 = 13,
  Channel14 = 14,
  Channel15 = 15,
  Channel16 = 16,
  Channel17 = 17,
  Channel18 = 18,
  Channel19 = 19,
  Channel20 = 20,
  Channel21 = 21,
  Channel22 = 22,
  Channel23 = 23,
  Channel24 = 24
};
/**
 * @brief DMA peripheral request input mapping to channels
 */
enum class HardwareDescriptors : std::uint32_t {
  Usart0RxDma = hardware::USART0_RX_DMA,  /*!< USART0 RX DMA request input */
  Usart0TxDma = hardware::USART0_TX_DMA,  /*!< USART0 TX DMA request input */
  Usart1RxDma = hardware::USART1_RX_DMA,  /*!< USART1 RX DMA request input */
  Usart1TxDma = hardware::USART1_TX_DMA,  /*!< USART1 TX DMA request input */
  Usart2RxDma = hardware::USART2_RX_DMA,  /*!< USART2 RX DMA request input */
  Usart2TxDma = hardware::USART2_TX_DMA,  /*!< USART2 TX DMA request input */
  Usart3RxDma = hardware::USART3_RX_DMA,  /*!< USART3 RX DMA request input */
  Usart3TxDma = hardware::USART3_TX_DMA,  /*!< USART3 TX DMA request input */
  Usart4RxDma = hardware::USART4_RX_DMA,  /*!< USART4 RX DMA request input */
  Usart4TxDma = hardware::USART4_TX_DMA,  /*!< USART4 TX DMA request input */
  Spi0RxDma = hardware::SPI0_RX_DMA,      /*!< SPI0 RX DMA request input */
  Spi0TxDma = hardware::SPI0_TX_DMA,      /*!< SPI0 TX DMA request input */
  Spi1RxDma = hardware::SPI1_RX_DMA,      /*!< SPI1 RX DMA request input */
  Spi1TxDma = hardware::SPI1_TX_DMA,      /*!< SPI1 TX DMA request input */
  I2c0SlaveDma = hardware::I2C0_SLV_DMA,  /*!< I2C0 slave DMA request input */
  I2c0MasterDma = hardware::I2C0_MST_DMA, /*!< I2C0 master DMA request input */
  I2c1SlaveDma = hardware::I2C1_SLV_DMA,  /*!< I2C1 slave DMA request input */
  I2c1MasterDma = hardware::I2C1_MST_DMA, /*!< I2C1 master DMA request input */
  I2c2SlaveDma = hardware::I2C2_SLV_DMA,  /*!< I2C2 slave DMA request input */
  I2c2MasterDma = hardware::I2C2_MST_DMA, /*!< I2C2 master DMA request input */
  I2c3SlaveDma = hardware::I2C3_SLV_DMA,  /*!< I2C3 slave DMA request input */
  I2c3MasterDma = hardware::I2C3_MST_DMA, /*!< I2C3 master DMA request input */
  Dac0DmaRequest = hardware::DAC0_DMAREQ, /*!< DAC0 DMA request input */
  Dac1DmaRequest = hardware::DAC1_DMAREQ, /*!< DAC1 DMA request input */
  CaptureDma = hardware::CAPT_DMA,        /*!< Capture DMA request input */
};

/**
 * @brief DMA burst sizes
 */
enum class BurstSizes : std::uint32_t {
  Burst1 = hardware::CFG::BURSTSIZE_1,      /*!< Burst size of 1 */
  Burst2 = hardware::CFG::BURSTSIZE_2,      /*!< Burst size of 2 */
  Burst4 = hardware::CFG::BURSTSIZE_4,      /*!< Burst size of 4 */
  Burst8 = hardware::CFG::BURSTSIZE_8,      /*!< Burst size of 8 */
  Burst16 = hardware::CFG::BURSTSIZE_16,    /*!< Burst size of 16 */
  Burst32 = hardware::CFG::BURSTSIZE_32,    /*!< Burst size of 32 */
  Burst64 = hardware::CFG::BURSTSIZE_64,    /*!< Burst size of 64 */
  Burst128 = hardware::CFG::BURSTSIZE_128,  /*!< Burst size of 128 */
  Burst256 = hardware::CFG::BURSTSIZE_256,  /*!< Burst size of 256 */
  Burst512 = hardware::CFG::BURSTSIZE_512,  /*!< Burst size of 512 */
  Burst1024 = hardware::CFG::BURSTSIZE_1024 /*!< Burst size of 1024 */
};

/**
 * @brief DMA trigger configurations
 */
enum class TriggerConfigs : std::uint32_t {
  /*!< No trigger configuration */
  None = 0u,
  /*!< Falling edge trigger */
  FallingEdge = hardware::CFG::HWTRIGEN,
  /*!< Rising edge trigger */
  RisingEdge = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGPOL,
  /*!< Low level trigger */
  LowLevel = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGTYPE,
  /*!< High level trigger */
  HighLevel = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGTYPE | hardware::CFG::TRIGPOL,
  /*!< Falling edge trigger with burst transfer enabled */
  FallingEdgeBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST,
  /*!< Rising edge trigger with burst transfer enabled */
  RisingEdgeBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGPOL,
  /*!< Low level trigger with burst transfer enabled */
  LowLevelBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGTYPE,
  /*!< High level trigger with burst transfer enabled */
  HighLevelBurst = hardware::CFG::HWTRIGEN | hardware::CFG::TRIGBURST | hardware::CFG::TRIGTYPE | hardware::CFG::TRIGPOL
};
/**
 * @brief DMA channel priorities
 */
enum class ChannelPrios : std::uint32_t {
  PrioHighest = hardware::CFG::CHPRIO_0,
  Prio0 = hardware::CFG::CHPRIO_0,
  Prio1 = hardware::CFG::CHPRIO_1,
  Prio2 = hardware::CFG::CHPRIO_2,
  Prio3 = hardware::CFG::CHPRIO_3,
  Prio4 = hardware::CFG::CHPRIO_4,
  Prio5 = hardware::CFG::CHPRIO_5,
  Prio6 = hardware::CFG::CHPRIO_6,
  Prio7 = hardware::CFG::CHPRIO_7,
  PrioLowest = hardware::CFG::CHPRIO_7,
};
/**
 * @brief interrupt flag set options
 */
enum class InterruptFlags : std::uint32_t {
  None = 0u,
  SetA = hardware::XFERCFG::SETINTA,
  SetB = hardware::XFERCFG::SETINTB,
  SetAB = hardware::XFERCFG::SETINTA | hardware::XFERCFG::SETINTB,
};
/**
 * @brief Transfer bit widths
 */
enum class TransferSizes : std::uint32_t {
  Size8Bit = hardware::XFERCFG::WIDTH_8BIT,
  Size16Bit = hardware::XFERCFG::WIDTH_16BIT,
  Size32Bit = hardware::XFERCFG::WIDTH_32BIT,
};
/**
 * @brief Source increments
 */
enum class SrcIncrements : std::uint32_t {
  Inc0 = hardware::XFERCFG::SRCINC_NONE,
  Inc1 = hardware::XFERCFG::SRCINC_1xWIDTH,
  Inc2 = hardware::XFERCFG::SRCINC_2xWIDTH,
  Inc4 = hardware::XFERCFG::SRCINC_4xWIDTH
};
/**
 * @brief Destination increments
 */
enum class DstIncrements : std::uint32_t {
  Inc0 = hardware::XFERCFG::DSTINC_NONE,
  Inc1 = hardware::XFERCFG::DSTINC_1xWIDTH,
  Inc2 = hardware::XFERCFG::DSTINC_2xWIDTH,
  Inc4 = hardware::XFERCFG::DSTINC_4xWIDTH
};

/**
 * @brief DMA low level interface class
 * @tparam dmaAddress_ address of the Input multiplexer peripheral
 */
template <libmcu::DmaBaseAddress dma_address>
struct Dma : libmcull::PeripheralBase {
  constexpr void Init() {
    descriptors_.fill({0, 0, 0, nullptr});
    GetPeripheral()->SRAMBASE = reinterpret_cast<std::uint32_t>(descriptors_.data());
    GetPeripheral()->CTRL = hardware::CTRL::ENABLE;
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
      cfg_register |= hardware::CFG::SRCBURSTWRAP;
    if (dest_burst_wrap)
      cfg_register |= hardware::CFG::DSTBURSTWRAP;
    cfg_register |= static_cast<std::uint32_t>(prio);

    GetPeripheral()->CHANNEL[index].CFG = cfg_register;
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
      static_cast<std::uint32_t>(trigger_config) | static_cast<std::uint32_t>(burst_size) | hardware::CFG::PERIPHREQEN;

    if (src_burst_wrap)
      cfg_register |= hardware::CFG::SRCBURSTWRAP;
    if (dest_burst_wrap)
      cfg_register |= hardware::CFG::DSTBURSTWRAP;
    cfg_register |= static_cast<std::uint32_t>(prio);

    GetPeripheral()->CHANNEL[index].CFG = cfg_register;
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
    std::uint32_t xfercfg_register = hardware::XFERCFG::XFERCOUNT(count) | hardware::XFERCFG::SWTRIG;

    if (reload)
      xfercfg_register |= hardware::XFERCFG::RELOAD_MASK;
    if (clear_trig_exhaust)
      xfercfg_register |= hardware::XFERCFG::CLRTRIG;
    xfercfg_register |= static_cast<std::uint32_t>(int_flags);
    xfercfg_register |= static_cast<std::uint32_t>(bits);
    xfercfg_register |= static_cast<std::uint32_t>(src_inc);
    xfercfg_register |= static_cast<std::uint32_t>(dst_inc);

    GetPeripheral()->CHANNEL[index].XFERCFG = xfercfg_register;
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
      xfercfg_register |= hardware::XFERCFG::RELOAD_MASK;
    if (clear_trig_exhaust)
      xfercfg_register |= hardware::XFERCFG::CLRTRIG;
    xfercfg_register |= static_cast<std::uint32_t>(int_flags);
    xfercfg_register |= static_cast<std::uint32_t>(bits);
    xfercfg_register |= static_cast<std::uint32_t>(src_inc);
    xfercfg_register |= static_cast<std::uint32_t>(dst_inc);

    GetPeripheral()->CHANNEL[index].XFERCFG = xfercfg_register;
  }
  /**
   * @brief Validate channel configuration
   * @param channel DMA channel to validate
   */
  constexpr void ValidateChannel(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->SETVALID = hardware::SETVALID::SV_MASK(channel_value);
  }
  /**
   * @brief Validate channel configuration
   * @param channel Hardware DMA channel to validate
   */
  constexpr void ValidateChannel(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->SETVALID = hardware::SETVALID::SV_MASK(channel_value);
  }
  /**
   * @brief Set channel trigger
   * @param channel DMA channel to trigger
   */
  constexpr void SetChannelTrigger(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->SETTRIG = hardware::SETTRIG::TRIG_MASK(channel_value);
  }
  /**
   * @brief Set channel trigger
   * @param channel Hardware DMA channel to trigger
   */
  constexpr void SetChannelTrigger(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->SETTRIG = hardware::SETTRIG::TRIG_MASK(channel_value);
  }
  /**
   * @brief Enable channel
   * @param channel DMA channel to enable
   */
  constexpr void EnableChannel(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->ENABLESET = hardware::ENABLESET::ENA(channel_value);
  }
  /**
   * @brief Enable channel
   * @param channel Hardware DMA channel to enable
   */
  constexpr void EnableChannel(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    GetPeripheral()->ENABLESET = hardware::ENABLESET::ENA(channel_value);
  }
  /**
   * @brief Is the current channel active
   * @param channel DMA channel to check
   */
  constexpr bool IsChannelActive(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::ACTIVE::ACT_MASK(channel_value) & GetPeripheral()->ACTIVE) != 0;
  }
  /**
   * @brief Is the current channel active
   * @param channel Hardware DMA channel to check
   */
  constexpr bool IsChannelActive(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::ACTIVE::ACT_MASK(channel_value) & GetPeripheral()->ACTIVE) != 0;
  }
  /**
   * @brief Is the current channel busy
   * @param channel DMA channel to check
   */
  constexpr bool IsChannelBusy(SoftwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::BUSY::BSY_MASK(channel_value) & GetPeripheral()->BUSY) != 0;
  }
  /**
   * @brief Is the current channel busy
   * @param channel Hardware DMA channel to check
   */
  constexpr bool IsChannelBusy(HardwareDescriptors channel) {
    std::uint32_t channel_value = static_cast<std::uint32_t>(channel);
    return (hardware::BUSY::BSY_MASK(channel_value) & GetPeripheral()->BUSY) != 0;
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
  constexpr static hardware::Dma *GetPeripheral() {
    return reinterpret_cast<hardware::Dma *>(dmaAddress_);
  }

  static constexpr libmcu::HwAddressType dmaAddress_ = dma_address; /*!< peripheral address */
  alignas(512) DescriptorTable descriptors_;
};

}  // namespace libmcull::dma

#endif