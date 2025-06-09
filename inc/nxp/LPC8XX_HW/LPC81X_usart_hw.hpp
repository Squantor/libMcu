/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series USART
 */
#ifndef LPC81X_USART_HW_HPP
#define LPC81X_USART_HW_HPP

namespace libmcuhw::usart {

/**
 * @brief USART register definitions
 */
struct Usart {
  volatile std::uint32_t CFG;             /*!< USART Configuration register. */
  volatile std::uint32_t CTL;             /*!< USART Control register. */
  volatile std::uint32_t STAT;            /*!< USART Status register. */
  volatile std::uint32_t INTENSET;        /*!< Interrupt Enable read and Set register. */
  volatile std::uint32_t INTENCLR;        /*!< Interrupt Enable Clear register. */
  volatile const std::uint32_t RXDAT;     /*!< Receiver Data register. */
  volatile const std::uint32_t RXDATSTAT; /*!< Receiver Data with Status register.  */
  volatile std::uint32_t TXDAT;           /*!< Transmit Data register. */
  volatile std::uint32_t BRG;             /*!< Baud Rate Generator register. */
  volatile const std::uint32_t INTSTAT;   /*!< Interrupt status register. */
};
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'DA7Du}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kENABLE{1u << 0};            /*!< Enable USART */
constexpr inline std::uint32_t kDATALEN7BIT{0u << 2};       /*!< 7 data bits */
constexpr inline std::uint32_t kDATALEN8BIT{1u << 2};       /*!< 8 data bits */
constexpr inline std::uint32_t kDATALEN9BIT{2u << 2};       /*!< 9 data bits */
constexpr inline std::uint32_t kPARITY_NONE{0u << 4};       /*!< No parity */
constexpr inline std::uint32_t kPARITY_EVEN{2u << 4};       /*!< Even parity */
constexpr inline std::uint32_t kPARITY_ODD{3u << 4};        /*!< Odd parity */
constexpr inline std::uint32_t kSTOPBIT1{0u << 6};          /*!< 1 stop bits */
constexpr inline std::uint32_t kSTOPBIT2{1u << 6};          /*<< 2 stop bits */
constexpr inline std::uint32_t kCTSEN{1u << 9};             /*!< CTS enable */
constexpr inline std::uint32_t kSYNCEN{1u << 11};           /*!< Synchronous enable */
constexpr inline std::uint32_t kCLKPOL{1u << 12};           /*!< Rising edge sampling */
constexpr inline std::uint32_t kSYNCMST{1u << 14};          /*!< Synchronous master selected */
constexpr inline std::uint32_t kLOOP{1u << 15};             /*!< Loopback mode */
}  // namespace CFG
namespace CTL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /*!< register mask for allowed bits */
}  // namespace CTL
namespace STAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FD7Fu}; /*!< Register mask for allowed bits, Read only */
constexpr inline std::uint32_t kRXRDY{1u << 0};             /*!< Receiver ready flag, Read only */
constexpr inline std::uint32_t kRXIDLE{1u << 1};            /*!< Receiver idle, Read only */
constexpr inline std::uint32_t kTXRDY{1u << 2};             /*!< Transmitter ready, Read only  */
constexpr inline std::uint32_t kTXIDLE{1u << 3};            /*!< Transmitter idle, Read only */
constexpr inline std::uint32_t kCTS{1u << 4};               /*!< CTS signal state, Read only */
constexpr inline std::uint32_t kDELTACTS{1u << 5};          /*!< Change detected in CTS signal, write 1 clear */
constexpr inline std::uint32_t kTXDISINT{1u << 6};          /*!< Transmitter disabled confirmation, read only  */
constexpr inline std::uint32_t kOVERRUNINT{1u << 8};        /*!< Overrun error interrupt flag, write 1 clear */
constexpr inline std::uint32_t kRXBRK{1u << 10};            /*!< Received break, read only */
constexpr inline std::uint32_t kDELTARXBRK{1u << 11};       /*!< Change detected in receiver break, write 1 clear */
constexpr inline std::uint32_t kSTART{1u << 12};            /*!< Start condition detected, write 1 clear */
constexpr inline std::uint32_t kFRAMERRINT{1u << 13};       /*!< Frame error interrupt flag, write 1 clear */
constexpr inline std::uint32_t kPARITYERRINT{1u << 14};     /*!< Parity error interrupt flag, write 1 clear */
constexpr inline std::uint32_t kRXNOISEINT{1u << 15};       /*!< Recieved noise interrupt flag, write 1 clear*/
}  // namespace STAT
namespace INTENSET {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /*!< register mask for allowed bits */
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /*!< register mask for allowed bits */
}  // namespace INTENCLR
namespace RXDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /*!< register mask for allowed bits */
}  // namespace RXDAT
namespace RXDATSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'71FFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kDATA_MASK{0x0000'00FFu};    /*!< register mask for received data */
constexpr inline std::uint32_t kSTAT_MASK{0x0000'7000u};    /*!< register mask for status bits */
constexpr inline std::uint32_t kFRAMEERR{1u << 13};         /*!< Framing error status flag */
constexpr inline std::uint32_t kPARITYERR{1u << 14};        /*!< Parity error status flag */
constexpr inline std::uint32_t kRXNOISE{1u << 15};          /*!< Recieved noise flag */
}  // namespace RXDATSTAT
namespace TXDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /*!< register mask for allowed bits */
}  // namespace TXDAT
namespace BRG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /*!< register mask for allowed bits */
}  // namespace BRG
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /*!< register mask for allowed bits */
}  // namespace INTSTAT
}  // namespace libmcuhw::usart
#endif