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

namespace libMcuLL {
namespace hw {
namespace usart {

/**
 * @brief USART register definitions
 *
 */
struct peripheral {
  volatile uint32_t CFG;             /**< USART Configuration register. */
  volatile uint32_t CTL;             /**< USART Control register. */
  volatile uint32_t STAT;            /**< USART Status register. */
  volatile uint32_t INTENSET;        /**< Interrupt Enable read and Set register. */
  volatile uint32_t INTENCLR;        /**< Interrupt Enable Clear register. */
  volatile const uint32_t RXDAT;     /**< Receiver Data register. */
  volatile const uint32_t RXDATSTAT; /**< Receiver Data with Status register.  */
  volatile uint32_t TXDAT;           /**< Transmit Data register. */
  volatile uint32_t BRG;             /**< Baud Rate Generator register. */
  volatile const uint32_t INTSTAT;   /**< Interrupt status register. */
};

namespace CFG {
constexpr inline uint32_t MASK = 0x0000DA7D;   /**< register mask for allowed bits */
constexpr inline uint32_t ENABLE = (1 << 0);   /**< Enable USART */
constexpr inline uint32_t CTSEN = (1 << 9);    /**< CTS enable */
constexpr inline uint32_t SYNCEN = (1 << 11);  /**< Synchronous enable */
constexpr inline uint32_t CLKPOL = (1 << 12);  /**< Rising edge sampling */
constexpr inline uint32_t SYNCMST = (1 << 14); /**< Synchronous master selected */
constexpr inline uint32_t LOOP = (1 << 15);    /**< Loopback mode */
}  // namespace CFG
namespace CTL {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CTL
namespace STAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x0000FD7F;        /**< Register mask for allowed bits, Read only */
constexpr inline uint32_t RXRDY = (1 << 0);         /**< Receiver ready flag, Read only */
constexpr inline uint32_t RXIDLE = (1 << 1);        /**< Receiver idle, Read only */
constexpr inline uint32_t TXRDY = (1 << 2);         /**< Transmitter ready, Read only  */
constexpr inline uint32_t TXIDLE = (1 << 3);        /**< Transmitter idle, Read only */
constexpr inline uint32_t CTS = (1 << 4);           /**< CTS signal state, Read only */
constexpr inline uint32_t DELTACTS = (1 << 5);      /**< Change detected in CTS signal, write 1 clear */
constexpr inline uint32_t TXDISINT = (1 << 6);      /**< Transmitter disabled confirmation, read only  */
constexpr inline uint32_t OVERRUNINT = (1 << 8);    /**< Overrun error interrupt flag, write 1 clear */
constexpr inline uint32_t RXBRK = (1 << 10);        /**< Received break, read only */
constexpr inline uint32_t DELTARXBRK = (1 << 11);   /**< Change detected in receiver break, write 1 clear */
constexpr inline uint32_t START = (1 << 12);        /**< Start condition detected, write 1 clear */
constexpr inline uint32_t FRAMERRINT = (1 << 13);   /**< Frame error interrupt flag, write 1 clear */
constexpr inline uint32_t PARITYERRINT = (1 << 14); /**< Parity error interrupt flag, write 1 clear */
constexpr inline uint32_t RXNOISEINT = (1 << 15);   /**< Recieved noise interrupt flag, write 1 clear*/
}  // namespace STAT
namespace INTENSET {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTENSET
namespace INTENCLR {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTENCLR
namespace RXDAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x000001FF; /**< register mask for allowed bits */
}  // namespace RXDAT
namespace RXDATSTAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x000071FF;      /**< register mask for allowed bits */
constexpr inline uint32_t MASK_DATA = 0x000000FF; /**< register mask for received data */
constexpr inline uint32_t MASK_STAT = 0x00007000; /**< register mask for status bits */
constexpr inline uint32_t FRAMEERR = (1 << 13);   /**< Framing error status flag */
constexpr inline uint32_t PARITYERR = (1 << 14);  /**< Parity error status flag */
constexpr inline uint32_t RXNOISE = (1 << 15);    /**< Recieved noise flag */
}  // namespace RXDATSTAT
namespace TXDAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x000001FF; /**< register mask for allowed bits */
}  // namespace TXDAT
namespace BRG {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace BRG
namespace INTSTAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTSTAT

}  // namespace usart
}  // namespace hw
}  // namespace libMcuLL

#endif