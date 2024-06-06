/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 UART register interface
 */
#ifndef RP2040_UART_HW_HPP
#define RP2040_UART_HW_HPP

namespace libMcuLL::hw::uart {
/**
 * @brief UART register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t UARTDR;         /**< Data Register */
  volatile std::uint32_t UARTRSR;        /**< Receive Status Register/Error Clear Register */
  volatile std::uint32_t reserved0[4];   /**< reserved */
  volatile std::uint32_t UARTFR;         /**< Flag Register */
  volatile std::uint32_t reserved1[1];   /**< reserved */
  volatile std::uint32_t UARTILPR;       /**< IrDA Low-Power Counter Register */
  volatile std::uint32_t UARTIBRD;       /**< Integer Baud Rate Register */
  volatile std::uint32_t UARTFBRD;       /**< Fractional Baud Rate Register */
  volatile std::uint32_t UARTLCR_H;      /**< Line Control Register */
  volatile std::uint32_t UARTCR;         /**< Control Register */
  volatile std::uint32_t UARTIFLS;       /**< Interrupt FIFO Level Select */
  volatile std::uint32_t UARTIMSC;       /**< Interrupt Mask Set/Clear */
  volatile std::uint32_t UARTRIS;        /**< Raw Interrupt Status */
  volatile std::uint32_t UARTMIS;        /**< Masked Interrupt Status */
  volatile std::uint32_t UARTICR;        /**< Interrupt Clear Register */
  volatile std::uint32_t UARTDMACR;      /**< DMA Control Register */
  volatile std::uint32_t reserved2[997]; /**< */
  volatile std::uint32_t UARTPERIPHID0;  /**< UARTPeriphID0 */
  volatile std::uint32_t UARTPERIPHID1;  /**< UARTPeriphID1 */
  volatile std::uint32_t UARTPERIPHID2;  /**< UARTPeriphID2 */
  volatile std::uint32_t UARTPERIPHID3;  /**< UARTPeriphID3 */
  volatile std::uint32_t UARTPCELLID0;   /**< UARTPCellID0 */
  volatile std::uint32_t UARTPCELLID1;   /**< UARTPCellID1 */
  volatile std::uint32_t UARTPCELLID2;   /**< UARTPCellID2 */
  volatile std::uint32_t UARTPCELLID3;   /**< UARTPCellID3 */
};
namespace UARTDR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0FFFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t OE_FLAG{1u << 11};           /**< RX FIFO overrun error */
constexpr inline std::uint32_t BE_FLAG{1u << 10};           /**< Break error */
constexpr inline std::uint32_t PE_FLAG{1u << 9};            /**< Parity error */
constexpr inline std::uint32_t FE_FLAG{1u << 8};            /**< Framing error */
constexpr inline std::uint32_t ERROR_MASK{0xFu << 8};       /**< Mask for all the error flags*/
constexpr inline std::uint32_t DATA_MASK{0xFFu << 0};       /**< Mask for data byte */
/**
 * @brief Format DATA field to UARTDR register
 * @param character character byte to format
 * @return DATA field formatted to UARTDR register
 */
constexpr inline std::uint32_t DATA(std::uint32_t character) {
  return character << 0;
}
}  // namespace UARTDR
namespace UARTRSR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'000Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t OE_FLAG{1u << 3};            /**< RX FIFO overrun error */
constexpr inline std::uint32_t BE_FLAG{1u << 2};            /**< Break error */
constexpr inline std::uint32_t PE_FLAG{1u << 1};            /**< Parity error */
constexpr inline std::uint32_t FE_FLAG{1u << 0};            /**< Framing error */
}  // namespace UARTRSR
namespace UARTFR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t RI_FLAG{1u << 8};            /**< Ring indicator */
constexpr inline std::uint32_t TXFE_FLAG{1u << 7};          /**< TX FIFO empty */
constexpr inline std::uint32_t RXFF_FLAG{1u << 6};          /**< RX FIFO full */
constexpr inline std::uint32_t TXFF_FLAG{1u << 5};          /**< TX FIFO full */
constexpr inline std::uint32_t RXFE_FLAG{1u << 4};          /**< RX FIFO empty */
constexpr inline std::uint32_t BUSY_FLAG{1u << 3};          /**< Busy */
constexpr inline std::uint32_t DCD_FLAG{1u << 2};           /**< Data carrier detect */
constexpr inline std::uint32_t DSR_FLAG{1u << 1};           /**< Data set ready */
constexpr inline std::uint32_t CTS_FLAG{1u << 0};           /**< Clear to send */
}  // namespace UARTFR
namespace UARTILPR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTILPR
namespace UARTIBRD {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTIBRD
namespace UARTFBRD {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTFBRD
namespace UARTLCR_H {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t SPS{1u << 7};                /**< Stick parity select */
constexpr inline std::uint32_t WLEN_8{3u << 5};             /**< 8 bit word length */
constexpr inline std::uint32_t WLEN_7{2u << 5};             /**< 7 bit word length */
constexpr inline std::uint32_t WLEN_6{1u << 5};             /**< 6 bit word length */
constexpr inline std::uint32_t WLEN_5{0u << 5};             /**< 5 bit word length */
constexpr inline std::uint32_t FEN{1u << 4};                /**< FIFO enable */
constexpr inline std::uint32_t STP2{1u << 3};               /**< Two stop bit select */
constexpr inline std::uint32_t EPS{1u << 2};                /**< Even parity select */
constexpr inline std::uint32_t PEN{1u << 1};                /**< Parity enable */
constexpr inline std::uint32_t BRK{1u << 0};                /**< Send break */
}  // namespace UARTLCR_H
namespace UARTCR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FF87u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t CTSEN{1u << 15};             /**< CTS hardware flow control enable */
constexpr inline std::uint32_t RTSEN{1u << 14};             /**< RTS hardware flow control enable */
constexpr inline std::uint32_t OUT2{1u << 13};              /**< complement UART OUT2 */
constexpr inline std::uint32_t OUT1{1u << 12};              /**< complement UART OUT1 */
constexpr inline std::uint32_t RTS{1u << 11};               /**< Request to send */
constexpr inline std::uint32_t DTR{1u << 10};               /**< Data transmit ready */
constexpr inline std::uint32_t RXE{1u << 9};                /**< Receive enable */
constexpr inline std::uint32_t TXE{1u << 8};                /**< Transmit enable */
constexpr inline std::uint32_t LBE{1u << 7};                /**< Loopback enable */
constexpr inline std::uint32_t SIRLP{1u << 2};              /**< SIR low power IrDA mode */
constexpr inline std::uint32_t SIREN{1u << 1};              /**< SIR enable */
constexpr inline std::uint32_t UARTEN{1u << 0};             /**< UART enable */
}  // namespace UARTCR
namespace UARTIFLS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTIFLS
namespace UARTIMSC {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTIMSC
namespace UARTRIS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTRIS
namespace UARTMIS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTMIS
namespace UARTICR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace UARTICR
namespace UARTDMACR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0007u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t DMAONERR{1u << 2};           /**< DMA on error */
constexpr inline std::uint32_t TXDMAE{1u << 1};             /**< Transmit DMA enable */
constexpr inline std::uint32_t RXDMAE{1u << 0};             /**< Receive DMA enable */
}  // namespace UARTDMACR
}  // namespace libMcuLL::hw::uart
#endif