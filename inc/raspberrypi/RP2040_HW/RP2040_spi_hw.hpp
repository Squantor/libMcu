/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SPI register interface
 */
#ifndef RP2040_SPI_HW_HPP
#define RP2040_SPI_HW_HPP

namespace libMcuHw::spi {
/**
 * @brief SPI register definitions
 */
struct spi {
  volatile std::uint32_t SSPCR0;   /**< Control register 0 */
  volatile std::uint32_t SSPCR1;   /**< Control register 1 */
  volatile std::uint32_t SSPDR;    /**< Data register */
  volatile std::uint32_t SSPSR;    /**< Status register */
  volatile std::uint32_t SSPCPSR;  /**< Clock prescaler register */
  volatile std::uint32_t SSPIMSC;  /**< Interrupt mask set or clear register */
  volatile std::uint32_t SSPRIS;   /**< Raw interrupt status register */
  volatile std::uint32_t SSPMIS;   /**< Masked interrupt status register */
  volatile std::uint32_t SSPICR;   /**< Interrupt clear register */
  volatile std::uint32_t SSPDMACR; /**< DMA control register*/
  volatile std::uint32_t reserved0[1006];
  volatile std::uint32_t SSPPERIPID0; /**< Peripheral identification register 0 */
  volatile std::uint32_t SSPPERIPID1; /**< Peripheral identification register 1 */
  volatile std::uint32_t SSPPERIPID2; /**< Peripheral identification register 2 */
  volatile std::uint32_t SSPPERIPID3; /**< Peripheral identification register 3 */
  volatile std::uint32_t SSPPCELLID0; /**< PrimeCell identification register 0 */
  volatile std::uint32_t SSPPCELLID1; /**< PrimeCell identification register 1 */
  volatile std::uint32_t SSPPCELLID2; /**< PrimeCell identification register 2 */
  volatile std::uint32_t SSPPCELLID3; /**< PrimeCell identification register 3 */
};
namespace SSPCR0 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFFFu}; /**< Mask for allowed bits */

constexpr inline std::uint32_t SCR_MASK{0xFFu << 8}; /**< Mask for SCR */
/**
 * @brief Format SCR field to SSPCR0 register
 * @param rate Serial clock rate
 * @return SCR field formatted to SSPCR0 register
 */
constexpr inline std::uint32_t SCR(uint32_t rate) {
  return rate << 8;
}
constexpr inline std::uint32_t SPH{1u << 7};           /**< SSPCLKOUT phase for motorola format*/
constexpr inline std::uint32_t SPO{1u << 6};           /**< SSPCLKOUT polarity for motorola format*/
constexpr inline std::uint32_t FRF_MOTOROLA{0u << 4};  /**< Motorola Frame format */
constexpr inline std::uint32_t FRF_TI{1u << 4};        /**< TI Frame format */
constexpr inline std::uint32_t FRF_NATIONAL{2u << 4};  /**< National Microwire Frame format */
constexpr inline std::uint32_t FORMAT_MASK{0xFu << 4}; /**< Format mask */
constexpr inline std::uint32_t DSS_MASK{0xFu << 0};    /**< Data size mask */
constexpr inline std::uint32_t DSS_4BIT{3u << 0};      /**< 4 bit data */
constexpr inline std::uint32_t DSS_5BIT{4u << 0};      /**< 5 bit data */
constexpr inline std::uint32_t DSS_6BIT{5u << 0};      /**< 6 bit data */
constexpr inline std::uint32_t DSS_7BIT{6u << 0};      /**< 7 bit data */
constexpr inline std::uint32_t DSS_8BIT{7u << 0};      /**< 8 bit data */
constexpr inline std::uint32_t DSS_9BIT{8u << 0};      /**< 9 bit data */
constexpr inline std::uint32_t DSS_10BIT{9u << 0};     /**< 10 bit data */
constexpr inline std::uint32_t DSS_11BIT{10u << 0};    /**< 11 bit data */
constexpr inline std::uint32_t DSS_12BIT{11u << 0};    /**< 12 bit data */
constexpr inline std::uint32_t DSS_13BIT{12u << 0};    /**< 13 bit data */
constexpr inline std::uint32_t DSS_14BIT{13u << 0};    /**< 14 bit data */
constexpr inline std::uint32_t DSS_15BIT{14u << 0};    /**< 15 bit data */
constexpr inline std::uint32_t DSS_16BIT{15u << 0};    /**< 16 bit data */
/**
 * @brief Format DSS field to SSPCR0 register
 * @param bitSize amount of bits to transfer, values between 4 and 16 are valid
 * @return SCR field formatted to SSPCR0 register
 */
constexpr inline std::uint32_t DSS(std::uint32_t bitSize) {
  return (bitSize - 1) << 0;
}
}  // namespace SSPCR0
namespace SSPCR1 {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'000Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t SOD{1u << 3};                /**< Slave mode output disable */
constexpr inline std::uint32_t MS{1u << 2};                 /**< Master or slave mode select */
constexpr inline std::uint32_t SSE{1u << 1};                /**< SPI enable */
constexpr inline std::uint32_t LBM{1u << 0};                /**< Loopback mode enable */
}  // namespace SSPCR1
namespace SSPDR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFFFu}; /**< Mask for allowed bits */
}  // namespace SSPDR
namespace SSPSR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'001Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t BSY_MASK{1u << 4};           /**< SSP busy flag */
constexpr inline std::uint32_t RFF_MASK{1u << 3};           /**< Receive FIFO full flag */
constexpr inline std::uint32_t RNE_MASK{1u << 2};           /**< Receive FIFO empty flag */
constexpr inline std::uint32_t TNF_MASK{1u << 1};           /**< Transmit FIFO not full flag */
constexpr inline std::uint32_t TFE_MASK{1u << 0};           /**< Transmit FIFO empty flag */
}  // namespace SSPSR
namespace SSPCPSR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
}  // namespace SSPCPSR
namespace SSPIMSC {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'000Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t TXIM{1u << 3};               /**< Transmit FIFO interrupt mask */
constexpr inline std::uint32_t RXIM{1u << 2};               /**< Receive FIFO interrupt mask */
constexpr inline std::uint32_t RTIM{1u << 1};               /**< Receive timeout interrupt mask */
constexpr inline std::uint32_t RORIM{1u << 0};              /**< Receive overrun interrupt mask */
}  // namespace SSPIMSC
namespace SSPRIS {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'000Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t TXRIS_MASK{1u << 3};         /**< Raw SSPTXINTR state */
constexpr inline std::uint32_t RXRIS_MASK{1u << 2};         /**< Raw SSPRXINTR state */
constexpr inline std::uint32_t RTRIS_MASK{1u << 1};         /**< Raw SSPRTINTR state */
constexpr inline std::uint32_t RORRIS_MASK{1u << 0};        /**< Raw SSPRORINTR state */
}  // namespace SSPRIS
namespace SSPMIS {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'000Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t TXMIS_MASK{1u << 3};         /**< masked SSPTXINTR state */
constexpr inline std::uint32_t RXMIS_MASK{1u << 2};         /**< masked SSPRXINTR state */
constexpr inline std::uint32_t RTMIS_MASK{1u << 1};         /**< masked SSPRTINTR state */
constexpr inline std::uint32_t RORMIS_MASK{1u << 0};        /**< masked SSPRORINTR state */
}  // namespace SSPMIS
namespace SSPICR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t RTIC{1u << 1};               /**< Clears SSPRTINTR */
constexpr inline std::uint32_t RORIC{1u << 0};              /**< Clears SSPRORINTR */
}  // namespace SSPICR
namespace SSPDMACR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t TXDMAE{1u << 1};             /**< Transmit DMA Enable */
constexpr inline std::uint32_t RXDMAE{1u << 0};             /**< Receive DMA Enable */
}  // namespace SSPDMACR
}  // namespace libMcuHw::spi
#endif