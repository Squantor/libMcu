/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series USART register interface
 */
#ifndef LPC81X_USART_REGS_HPP
#define LPC81X_USART_REGS_HPP

namespace libMcuLL::hw::usart {

/**
 * @brief USART register definitions
 */
struct usart {
  volatile std::uint32_t CFG;             /**< USART Configuration register. */
  volatile std::uint32_t CTL;             /**< USART Control register. */
  volatile std::uint32_t STAT;            /**< USART Status register. */
  volatile std::uint32_t INTENSET;        /**< Interrupt Enable read and Set register. */
  volatile std::uint32_t INTENCLR;        /**< Interrupt Enable Clear register. */
  volatile const std::uint32_t RXDAT;     /**< Receiver Data register. */
  volatile const std::uint32_t RXDATSTAT; /**< Receiver Data with Status register.  */
  volatile std::uint32_t TXDAT;           /**< Transmit Data register. */
  volatile std::uint32_t BRG;             /**< Baud Rate Generator register. */
  volatile const std::uint32_t INTSTAT;   /**< Interrupt status register. */
};
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'DA7Du}; /**< register mask for allowed bits */
constexpr inline std::uint32_t ENABLE{1u << 0};             /**< Enable USART */
constexpr inline std::uint32_t CTSEN{1u << 9};              /**< CTS enable */
constexpr inline std::uint32_t SYNCEN{1u << 11};            /**< Synchronous enable */
constexpr inline std::uint32_t CLKPOL{1u << 12};            /**< Rising edge sampling */
constexpr inline std::uint32_t SYNCMST{1u << 14};           /**< Synchronous master selected */
constexpr inline std::uint32_t LOOP{1u << 15};              /**< Loopback mode */
}  // namespace CFG
namespace CTL {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace CTL
namespace STAT {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FD7Fu}; /**< Register mask for allowed bits, Read only */
constexpr inline std::uint32_t RXRDY{1u << 0};              /**< Receiver ready flag, Read only */
constexpr inline std::uint32_t RXIDLE{1u << 1};             /**< Receiver idle, Read only */
constexpr inline std::uint32_t TXRDY{1u << 2};              /**< Transmitter ready, Read only  */
constexpr inline std::uint32_t TXIDLE{1u << 3};             /**< Transmitter idle, Read only */
constexpr inline std::uint32_t CTS{1u << 4};                /**< CTS signal state, Read only */
constexpr inline std::uint32_t DELTACTS{1u << 5};           /**< Change detected in CTS signal, write 1 clear */
constexpr inline std::uint32_t TXDISINT{1u << 6};           /**< Transmitter disabled confirmation, read only  */
constexpr inline std::uint32_t OVERRUNINT{1u << 8};         /**< Overrun error interrupt flag, write 1 clear */
constexpr inline std::uint32_t RXBRK{1u << 10};             /**< Received break, read only */
constexpr inline std::uint32_t DELTARXBRK{1u << 11};        /**< Change detected in receiver break, write 1 clear */
constexpr inline std::uint32_t START{1u << 12};             /**< Start condition detected, write 1 clear */
constexpr inline std::uint32_t FRAMERRINT{1u << 13};        /**< Frame error interrupt flag, write 1 clear */
constexpr inline std::uint32_t PARITYERRINT{1u << 14};      /**< Parity error interrupt flag, write 1 clear */
constexpr inline std::uint32_t RXNOISEINT{1u << 15};        /**< Recieved noise interrupt flag, write 1 clear*/
}  // namespace STAT
namespace INTENSET {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace INTENSET
namespace INTENCLR {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace INTENCLR
namespace RXDAT {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< register mask for allowed bits */
}  // namespace RXDAT
namespace RXDATSTAT {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'71FFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t DATA_MASK{0x0000'00FFu};     /**< register mask for received data */
constexpr inline std::uint32_t STAT_MASK{0x0000'7000u};     /**< register mask for status bits */
constexpr inline std::uint32_t FRAMEERR{1u << 13};          /**< Framing error status flag */
constexpr inline std::uint32_t PARITYERR{1u << 14};         /**< Parity error status flag */
constexpr inline std::uint32_t RXNOISE{1u << 15};           /**< Recieved noise flag */
}  // namespace RXDATSTAT
namespace TXDAT {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< register mask for allowed bits */
}  // namespace TXDAT
namespace BRG {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace BRG
namespace INTSTAT {
// TODO register definitions
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace INTSTAT
}  // namespace libMcuLL::hw::usart
#endif