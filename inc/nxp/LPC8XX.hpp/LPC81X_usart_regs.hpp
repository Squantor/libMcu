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

namespace registers {
namespace usart {

/**
 * @brief USART register definitions
 *
 */
struct registers {
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
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
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
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace RXDAT
namespace RXDATSTAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace RXDATSTAT
namespace TXDAT {
// TODO register definitions
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
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
}  // namespace registers

#endif