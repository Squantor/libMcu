/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_dma_hw.hpp
 * @brief LPC840 DMA register interface structure and definitions
 * @todo add struct for DMA descriptors
 */
#ifndef LPC84X_DMA_HW_HPP
#define LPC84X_DMA_HW_HPP

namespace libMcuHw::dma {
constexpr std::size_t channelCount = 25; /*!< DMA controller channel count */
struct dma_desc {
  volatile std::uint32_t RESERVED;     /*!< Reserved */
  volatile std::uint32_t SRC_DATA_END; /*!< Source data end address */
  volatile std::uint32_t DST_DATA_END; /*!< Destination data end address */
  volatile dma_desc *NEXT_DESC;        /*!< Next descriptor address */
};
/**
 * @brief DMA register definitions
 */
struct dma {
  volatile std::uint32_t CTRL;              /*!< DMA control */
  volatile const std::uint32_t INTSTAT;     /*!< Interrupt status */
  volatile std::uint32_t SRAMBASE;          /*!< SRAM address of the channel configuration table */
  std::uint8_t RESERVED_0[20];              /*!< Reserved */
  struct {                                  /*  */
    volatile std::uint32_t ENABLESET;       /*!< Channel Enable read and Set */
    std::uint8_t RESERVED_0[4];             /*!< Reserved */
    volatile const std::uint32_t ENABLECLR; /*!< Channel Enable Clear */
    std::uint8_t RESERVED_1[4];             /*!< Reserved */
    volatile std::uint32_t ACTIVE;          /*!< Channel Active status */
    std::uint8_t RESERVED_2[4];             /*!< Reserved */
    volatile std::uint32_t BUSY;            /*!< Channel Busy status */
    std::uint8_t RESERVED_3[4];             /*!< Reserved */
    volatile std::uint32_t ERRINT;          /*!< Error Interrupt status */
    std::uint8_t RESERVED_4[4];             /*!< Reserved */
    volatile std::uint32_t INTENSET;        /*!< Interrupt Enable read and Set */
    std::uint8_t RESERVED_5[4];             /*!< Reserved */
    volatile const std::uint32_t INTENCLR;  /*!< Interrupt Enable Clear */
    std::uint8_t RESERVED_6[4];             /*!< Reserved */
    volatile std::uint32_t INTA;            /*!< Interrupt A status */
    std::uint8_t RESERVED_7[4];             /*!< Reserved */
    volatile std::uint32_t INTB;            /*!< Interrupt B status */
    std::uint8_t RESERVED_8[4];             /*!< Reserved */
    volatile const std::uint32_t SETVALID;  /*!< Set ValidPending control bits */
    std::uint8_t RESERVED_9[4];             /*!< Reserved */
    volatile const std::uint32_t SETTRIG;   /*!< Set Trigger control bits */
    std::uint8_t RESERVED_10[4];            /*!< Reserved */
    volatile const std::uint32_t ABORT;     /*!< Channel Abort control */
  } COMMON[1];                              /*!< Common for all DMA channels */
  std::uint8_t RESERVED_1[900];             /*!< Reserved */
  struct {                                  /*  */
    volatile std::uint32_t CFG;             /*!< Configuration register for DMA channel */
    volatile std::uint32_t CTLSTAT;         /*!< Control and status register for DMA channel */
    volatile std::uint32_t XFERCFG;         /*!< Transfer configuration register for DMA channel */
    std::uint8_t RESERVED_0[4];             /*!< Reserved */
  } CHANNEL[25];                            /*!< Specific DMA channel  */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000001u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t ENABLE{1u << 0};            /*!< DMA channel controller is enabled */
}  // namespace CTRL
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000006u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t ACTIVEINT_MASK{1u << 1};    /*!< At least one interrupt is pending */
constexpr inline std::uint32_t ACTIVEERRINT_MASK{1u << 2}; /*!< At least one error interrupt is pending */
}  // namespace INTSTAT
namespace SRAMBASE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFE000u}; /*!< register mask for allowed bits */
/**
 * @brief Format address descriptor table offset
 * @param offset address bits 31:9 of the beginning of the DMA descriptor table
 * @return formatted data for SRAMBASE
 */
constexpr inline std::uint32_t OFFSET(std::uint32_t offset) {
  return (offset << 8);
}
}  // namespace SRAMBASE
namespace ENABLESET {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format enable flags
 * @param channel DMA channel to enable
 * @return formatted data for ENABLESET
 */
constexpr inline std::uint32_t ENA(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace ENABLESET
namespace ENABLECLR {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format disable flags
 * @param channel DMA channel to disable
 * @return formatted data for ENABLESET
 */
constexpr inline std::uint32_t CLR(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace ENABLECLR
namespace ACTIVE {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format active flags for DMA channels
 * @param channel DMA channel to check
 * @return formatted data for ACTIVE
 */
constexpr inline std::uint32_t ACT_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace ACTIVE
namespace BUSY {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format busy flags for DMA channels
 * @param channel DMA channel to check
 * @return formatted data for BUSY
 */
constexpr inline std::uint32_t BSY_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace BUSY
namespace ERRINT {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format interrupt error flags for DMA channels
 * @param channel DMA channel to check if an error interrupt occured
 * @return formatted data for ERRINT
 */
constexpr inline std::uint32_t ERR_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace ERRINT
namespace INTENSET {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format interrupt enable flags for DMA channels
 * @param channel DMA channel to enable interrupt
 * @return formatted data for INTENSET
 */
constexpr inline std::uint32_t INTEN_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format interrupt clear flags for DMA channels
 * @param channel DMA channel to disable interrupt
 * @return formatted data for INTENCLR
 */
constexpr inline std::uint32_t CLR_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace INTENCLR
namespace INTA {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format interrupt A status flags for DMA channels
 * @param channel DMA channel to check for interrupt A status
 * @return formatted data for INTA
 */
constexpr inline std::uint32_t IA_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace INTA
namespace INTB {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format interrupt B status flags for DMA channels
 * @param channel DMA channel to check for interrupt B status
 * @return formatted data for INTB
 */
constexpr inline std::uint32_t IB_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace INTB
namespace SETVALID {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format Config valid setting flags for DMA channels
 * @param channel DMA channel to set the config valid for
 * @return formatted data for SETVALID
 */
constexpr inline std::uint32_t SV_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace SETVALID
namespace SETTRIG {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format Set Trigger bit for DMA channels
 * @param channel DMA channel to set the trigger bit for
 * @return formatted data for SETTRIG
 */
constexpr inline std::uint32_t TRIG_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace SETTRIG
namespace ABORT {
constexpr inline std::uint32_t RESERVED_MASK{0x01FFFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format Set abort operation bit for DMA channels
 * @param channel DMA channel to abort
 * @return formatted data for ABORT
 */
constexpr inline std::uint32_t ABORTCTRL_MASK(std::uint32_t channel) {
  return (1u << channel);
}
}  // namespace ABORT
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0007CF73u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t PERIPHREQEN{1u << 0};       /*!< Peripheral request enable */
constexpr inline std::uint32_t HWTRIGEN{1u << 1};          /*!< Hardware trigger enable */
constexpr inline std::uint32_t TRIGPOL{1u << 4};           /*!< Trigger Polarity */
constexpr inline std::uint32_t TRIGTYPE{1u << 5};          /*!< Trigger Type */
constexpr inline std::uint32_t TRIGBURST{1u << 6};         /*!< Trigger Burst */
constexpr inline std::uint32_t BURSTSIZE_1{0u << 8};       /*!< Burst size 1 */
constexpr inline std::uint32_t BURSTSIZE_2{1u << 8};       /*!< Burst size 2 */
constexpr inline std::uint32_t BURSTSIZE_4{2u << 8};       /*!< Burst size 4 */
constexpr inline std::uint32_t BURSTSIZE_8{3u << 8};       /*!< Burst size 8 */
constexpr inline std::uint32_t BURSTSIZE_16{4u << 8};      /*!< Burst size 16 */
constexpr inline std::uint32_t BURSTSIZE_32{5u << 8};      /*!< Burst size 32 */
constexpr inline std::uint32_t BURSTSIZE_64{6u << 8};      /*!< Burst size 64 */
constexpr inline std::uint32_t BURSTSIZE_128{7u << 8};     /*!< Burst size 128 */
constexpr inline std::uint32_t BURSTSIZE_256{8u << 8};     /*!< Burst size 256 */
constexpr inline std::uint32_t BURSTSIZE_512{9u << 8};     /*!< Burst size 512 */
constexpr inline std::uint32_t BURSTSIZE_1024{10u << 8};   /*!< Burst size 1024 */
constexpr inline std::uint32_t SRCBURSTWRAP{1u << 14};     /*!< Source burst wrap */
constexpr inline std::uint32_t DSTBURSTWRAP{1u << 15};     /*!< Destination burst wrap */
constexpr inline std::uint32_t CHPRIO_0{0u << 16};         /*!< channel priority 0 (highest) */
constexpr inline std::uint32_t CHPRIO_1{1u << 16};         /*!< channel priority 1 */
constexpr inline std::uint32_t CHPRIO_2{2u << 16};         /*!< channel priority 2 */
constexpr inline std::uint32_t CHPRIO_3{3u << 16};         /*!< channel priority 3 */
constexpr inline std::uint32_t CHPRIO_4{4u << 16};         /*!< channel priority 4 */
constexpr inline std::uint32_t CHPRIO_5{5u << 16};         /*!< channel priority 5 */
constexpr inline std::uint32_t CHPRIO_6{6u << 16};         /*!< channel priority 6 */
constexpr inline std::uint32_t CHPRIO_7{7u << 16};         /*!< channel priority 7 (lowest) */
}  // namespace CFG
namespace CTLSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000005u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t VALIDPENDING{1u << 0};      /*!< Valid pending */
constexpr inline std::uint32_t TRIG{1u << 1};              /*!< Trigger set for this channel */
}  // namespace CTLSTAT
namespace XFERCFG {
constexpr inline std::uint32_t RESERVED_MASK{0x03FFF33Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t CFGVALID_MASK{1u << 0};     /*!< Configuration valid flag */
constexpr inline std::uint32_t RELOAD_MASK{1u << 1};       /*!< Channel control reload flag */
constexpr inline std::uint32_t SWTRIG{1u << 2};            /*!< Software trigger flag */
constexpr inline std::uint32_t CLRTRIG{1u << 3};           /*!< Clear trigger flag */
constexpr inline std::uint32_t SETINTA{1u << 4};           /*!< Set interrupt A flag */
constexpr inline std::uint32_t SETINTB{1u << 5};           /*!< Set interrupt B flag */
constexpr inline std::uint32_t WIDTH_8BIT{0u << 8};        /*!< Transfer width 8 bits */
constexpr inline std::uint32_t WIDTH_16BIT{1u << 8};       /*!< Transfer width 16 bits */
constexpr inline std::uint32_t WIDTH_32BIT{2u << 8};       /*!< Transfer width 32 bits */
constexpr inline std::uint32_t SRCINC_NONE{0u << 12};      /*!< No Source increment */
constexpr inline std::uint32_t SRCINC_1xWIDTH{1u << 12};   /*!< 1 source element increment */
constexpr inline std::uint32_t SRCINC_2xWIDTH(2u << 12);   /*!< 2 source elements increment */
constexpr inline std::uint32_t SRCINC_4xWIDTH(3u << 12);   /*!< 2 source elements increment */
constexpr inline std::uint32_t DSTINC_NONE{0u << 12};      /*!< No Source increment */
constexpr inline std::uint32_t DSTINC_1xWIDTH{1u << 12};   /*!< 1 source element increment */
constexpr inline std::uint32_t DSTINC_2xWIDTH(2u << 12);   /*!< 2 source elements increment */
constexpr inline std::uint32_t DSTINC_4xWIDTH(3u << 12);   /*!< 2 source elements increment */
/**
 * @brief Extract XFERCOUNT from XFERCFG register
 * @param hwRegister XFERCFG register value
 * @return constexpr std::size_t amount of bytes transferred
 */
constexpr inline std::size_t XFERCOUNT(std::uint32_t hwRegister) {
  return static_cast<std::size_t>(hwRegister >> 16);
}
}  // namespace XFERCFG
}  // namespace libMcuHw::dma
#endif