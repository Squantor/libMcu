/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 USART register interface
 */
#ifndef LPC84X_USART_HW_HPP
#define LPC84X_USART_HW_HPP

namespace libMcuLL::hw::usart {
/**
 * @brief USART register definitions
 */
struct peripheral {
  volatile std::uint32_t CFG;             /**< USART Configuration register */
  volatile std::uint32_t CTL;             /**< USART Control register */
  volatile std::uint32_t STAT;            /**< USART Status register */
  volatile std::uint32_t INTENSET;        /**< Interrupt Enable read and Set register */
  volatile std::uint32_t INTENCLR;        /**< Interrupt Enable Clear register */
  volatile const std::uint32_t RXDAT;     /**< Receiver Data register */
  volatile const std::uint32_t RXDATSTAT; /**< Receiver Data with Status register */
  volatile std::uint32_t TXDAT;           /**< Transmit Data register */
  volatile std::uint32_t BRG;             /**< Baud Rate Generator register */
  volatile const std::uint32_t INTSTAT;   /**< Interrupt status register */
  volatile std::uint32_t OSR;             /**< Oversample selection register for asynchronous communication */
  volatile std::uint32_t ADDR;            /**< Address register for automatic address matching */
};
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0x00FC'DA7Du}; /**< register mask for allowed bits */
constexpr inline std::uint32_t ENABLE{1u << 0};             /**< Enable USART */
constexpr inline std::uint32_t DATALEN7BIT{0u << 2};        /**< 7 data bits */
constexpr inline std::uint32_t DATALEN8BIT{1u << 2};        /**< 8 data bits */
constexpr inline std::uint32_t DATALEN9BIT{2u << 2};        /**< 9 data bits */
constexpr inline std::uint32_t PARITY_NONE{0u << 4};        /**< No parity */
constexpr inline std::uint32_t PARITY_EVEN{2u << 4};        /**< Even parity */
constexpr inline std::uint32_t PARITY_ODD{3u << 4};         /**< Odd parity */
constexpr inline std::uint32_t STOPBIT1{0u << 6};           /**< 1 stop bits */
constexpr inline std::uint32_t STOPBIT2{1u << 6};           /*<< 2 stop bits */
constexpr inline std::uint32_t CTSEN{1u << 9};              /**< CTS enable */
constexpr inline std::uint32_t SYNCEN{1u << 11};            /**< Synchronous enable */
constexpr inline std::uint32_t CLKPOL{1u << 12};            /**< Rising edge sampling */
constexpr inline std::uint32_t SYNCMST{1u << 14};           /**< Synchronous master selected */
constexpr inline std::uint32_t LOOP{1u << 15};              /**< Loopback mode */
}  // namespace CFG
namespace CTL {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'0346u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t TXDIS{1u << 6};              /**< Disable transmitter */
constexpr inline std::uint32_t AUTOBAUD{1u << 16};          /**< Enable autobaud */
}  // namespace CTL
namespace STAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'FD7Fu}; /**< Register mask for allowed bits, Read only */
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
constexpr inline std::uint32_t ABERR{1u << 16};             /**< Autobaud error, write 1 clears */
}  // namespace STAT
namespace INTENSET {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'F96Du}; /**< Register mask for allowed bits */
constexpr inline std::uint32_t RXRDYEN{1u << 0};            /**< Data ready in RXDAT interrupt enable */
constexpr inline std::uint32_t TXRDYEN{1u << 2};            /**< TXDAT availble for write interrupt enable */
constexpr inline std::uint32_t TXIDLEEN{1u << 3};           /**< Transmitter idle interrupt enable*/
constexpr inline std::uint32_t DELTACTSEN{1u << 5};         /**< Change in CTS interrupt enable*/
constexpr inline std::uint32_t TXDISEN{1u << 6};            /**< Transmit fully disabled interrupt enable*/
constexpr inline std::uint32_t OVERRUNEN{1u << 8};          /**< Overrun error interrupt enable*/
constexpr inline std::uint32_t DELTARXBRKEN{1u << 11};      /**< Change in RX break condition interrupt enable*/
constexpr inline std::uint32_t STARTEN{1u << 12};           /**< Start bit detected interrupt enable*/
constexpr inline std::uint32_t FRAMERREN{1u << 13};         /**< Framing error interrupt enable*/
constexpr inline std::uint32_t PARITYERREN{1u << 14};       /**< Parity error interrupt enable*/
constexpr inline std::uint32_t RXNOISEEN{1u << 15};         /**< RX noise detected interrupt enable*/
constexpr inline std::uint32_t ABERREN{1u << 16};           /**< Autobaud error interrupt enable*/
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'F96Du}; /**< register mask for allowed bits */
constexpr inline std::uint32_t RXRDYCLR{1u << 0};           /**< Data ready in RXDAT interrupt clear */
constexpr inline std::uint32_t TXRDYCLR{1u << 2};           /**< TXDAT availble for write interrupt clear */
constexpr inline std::uint32_t TXIDLECLR{1u << 3};          /**< Transmitter idle interrupt clear */
constexpr inline std::uint32_t DELTACTSCLR{1u << 5};        /**< Change in CTS interrupt clear */
constexpr inline std::uint32_t TXDISINTCLR{1u << 6};        /**< Transmit fully disabled interrupt clear */
constexpr inline std::uint32_t OVERRUNCLR{1u << 8};         /**< Overrun error interrupt clear */
constexpr inline std::uint32_t DELTARXBRKCLR{1u << 11};     /**< Change in RX break condition interrupt clear */
constexpr inline std::uint32_t STARTCLR{1u << 12};          /**< Start bit detected interrupt clear */
constexpr inline std::uint32_t FRAMERRCLR{1u << 13};        /**< Framing error interrupt clear */
constexpr inline std::uint32_t PARITYERRCLR{1u << 14};      /**< Parity error interrupt clear */
constexpr inline std::uint32_t RXNOISECLR{1u << 15};        /**< RX noise detected interrupt clear */
constexpr inline std::uint32_t ABERRCLR{1u << 16};          /**< Autobaud error interrupt clear */
}  // namespace INTENCLR
namespace RXDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< register mask for allowed bits */
}  // namespace RXDAT
namespace RXDATSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'71FFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t DATA_MASK{0x0000'00FFu};     /**< register mask for received data */
constexpr inline std::uint32_t STAT_MASK{0x0000'7000u};     /**< register mask for status bits */
constexpr inline std::uint32_t FRAMEERR{1u << 13};          /**< Framing error status flag */
constexpr inline std::uint32_t PARITYERR{1u << 14};         /**< Parity error status flag */
constexpr inline std::uint32_t RXNOISE{1u << 15};           /**< Recieved noise flag */
}  // namespace RXDATSTAT
namespace TXDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'01FFu}; /**< register mask for allowed bits */
}  // namespace TXDAT
namespace BRG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace BRG
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'F96Du}; /**< register mask for allowed bits */
constexpr inline std::uint32_t RXRDY{1u << 0};              /**< Data ready in RXDAT interrupt */
constexpr inline std::uint32_t TXRDY{1u << 2};              /**< TXDAT availble for write interrupt */
constexpr inline std::uint32_t TXIDLE{1u << 3};             /**< Transmitter idle interrupt */
constexpr inline std::uint32_t DELTACTS{1u << 5};           /**< Change in CTS interrupt */
constexpr inline std::uint32_t TXDISINT{1u << 6};           /**< Transmit fully disabled interrupt */
constexpr inline std::uint32_t OVERRUNINT{1u << 8};         /**< Overrun error interrupt */
constexpr inline std::uint32_t DELTARXBRK{1u << 11};        /**< Change in RX break condition interrupt */
constexpr inline std::uint32_t START{1u << 12};             /**< Start bit detected interrupt */
constexpr inline std::uint32_t FRAMERRINT{1u << 13};        /**< Framing error interrupt */
constexpr inline std::uint32_t PARITYERRINT{1u << 14};      /**< Parity error interrupt */
constexpr inline std::uint32_t RXNOISEINT{1u << 15};        /**< RX noise detected interrupt */
constexpr inline std::uint32_t ABERR{1u << 16};             /**< Autobaud error interrupt */
}  // namespace INTSTAT
namespace OSR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace OSR
namespace ADDR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace ADDR
}  // namespace libMcuLL::hw::usart
#endif