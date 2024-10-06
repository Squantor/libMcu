/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SIO register interface
 */
#ifndef RP2040_SIO_HW_HPP
#define RP2040_SIO_HW_HPP

namespace libMcuHw::sio {
/**
 * @brief SIO register definitions
 *
 */
struct peripheral {
  volatile const uint32_t CPUID;        /**< Processor core identifier */
  volatile const uint32_t GPIO_IN;      /**< Input value for GPIO pins */
  volatile uint32_t GPIO_HI_IN;         /**< Input value for QSPI pins */
  volatile uint32_t reserved0;          /**< Reserved */
  volatile uint32_t GPIO_OUT;           /**< GPIO output value */
  volatile uint32_t GPIO_OUT_SET;       /**< GPIO output value set */
  volatile uint32_t GPIO_OUT_CLR;       /**< GPIO output value clear */
  volatile uint32_t GPIO_OUT_XOR;       /**< GPIO output value XOR */
  volatile uint32_t GPIO_OE;            /**< GPIO output enable */
  volatile uint32_t GPIO_OE_SET;        /**< GPIO output enable set */
  volatile uint32_t GPIO_OE_CLR;        /**< GPIO output enable clear */
  volatile uint32_t GPIO_OE_XOR;        /**< GPIO output enable XOR */
  volatile uint32_t GPIO_HI_OUT;        /**< QSPI output value */
  volatile uint32_t GPIO_HI_OUT_SET;    /**< QSPI output value set */
  volatile uint32_t GPIO_HI_OUT_CLR;    /**< QSPI output value clear */
  volatile uint32_t GPIO_HI_OUT_XOR;    /**< QSPI output value XOR */
  volatile uint32_t GPIO_HI_OE;         /**< QSPI output enable */
  volatile uint32_t GPIO_HI_OE_SET;     /**< QSPI output enable set */
  volatile uint32_t GPIO_HI_OE_CLR;     /**< QSPI output enable clear */
  volatile uint32_t GPIO_HI_OE_XOR;     /**< QSPI output enable XOR */
  volatile uint32_t FIFO_ST;            /**< Status register for inter-core FIFOs (mailboxes). */
  volatile uint32_t FIFO_WR;            /**< Write access to this core’s TX FIFO */
  volatile uint32_t FIFO_RD;            /**< Read access to this core’s RX FIFO */
  volatile uint32_t SPINLOCK_ST;        /**< Spinlock state */
  volatile uint32_t DIV_UDIVIDEND;      /**< Divider unsigned dividend */
  volatile uint32_t DIV_UDIVISOR;       /**< Divider unsigned divisor */
  volatile uint32_t DIV_SDIVIDEND;      /**< Divider signed dividend */
  volatile uint32_t DIV_SDIVISOR;       /**< Divider signed divisor */
  volatile uint32_t DIV_QUOTIENT;       /**< Divider result quotient */
  volatile uint32_t DIV_REMAINDER;      /**< Divider result remainder */
  volatile uint32_t DIV_CSR;            /**< Control and status register for divider. */
  volatile uint32_t reserved1;          /**< Reserved */
  volatile uint32_t INTERP0_ACCUM0;     /**< Read/write access to accumulator 0 */
  volatile uint32_t INTERP0_ACCUM1;     /**< Read/write access to accumulator 1 */
  volatile uint32_t INTERP0_BASE0;      /**< Read/write access to BASE0 register */
  volatile uint32_t INTERP0_BASE1;      /**< Read/write access to BASE1 register */
  volatile uint32_t INTERP0_BASE2;      /**< Read/write access to BASE2 register */
  volatile uint32_t INTERP0_POP_LANE0;  /**< Read LANE0 result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP0_POP_LANE1;  /**< Read LANE1 result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP0_POP_FULL;   /**< Read FULL result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP0_PEEK_LANE0; /**< Read LANE0 result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP0_PEEK_LANE1; /**< Read LANE1 result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP0_PEEK_FULL;  /**< Read FULL result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP0_CTRL_LANE0; /**< Control register for lane 0 */
  volatile uint32_t INTERP0_CTRL_LANE1; /**< Control register for lane 1 */
  volatile uint32_t INTERP0_ACCUM0_ADD; /**< Values written here are atomically added to ACCUM0 */
  volatile uint32_t INTERP0_ACCUM1_ADD; /**< Values written here are atomically added to ACCUM1 */
  volatile uint32_t INTERP0_BASE_1AND0; /**< lower 16 bits to BASE0, upper to BASE1 simultaneously */
  volatile uint32_t INTERP1_ACCUM0;     /**< Read/write access to accumulator 0 */
  volatile uint32_t INTERP1_ACCUM1;     /**< Read/write access to accumulator 1 */
  volatile uint32_t INTERP1_BASE0;      /**< Read/write access to BASE0 register */
  volatile uint32_t INTERP1_BASE1;      /**< Read/write access to BASE1 register */
  volatile uint32_t INTERP1_BASE2;      /**< Read/write access to BASE2 register */
  volatile uint32_t INTERP1_POP_LANE0;  /**< Read LANE0 result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP1_POP_LANE1;  /**< Read LANE1 result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP1_POP_FULL;   /**< Read FULL result, simultaneously write to both accumulators (POP) */
  volatile uint32_t INTERP1_PEEK_LANE0; /**< Read LANE0 result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP1_PEEK_LANE1; /**< Read LANE1 result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP1_PEEK_FULL;  /**< Read FULL result, without altering any internal state (PEEK) */
  volatile uint32_t INTERP1_CTRL_LANE0; /**< Control register for lane 0 */
  volatile uint32_t INTERP1_CTRL_LANE1; /**< Control register for lane 1 */
  volatile uint32_t INTERP1_ACCUM0_ADD; /**< Values written here are atomically added to ACCUM0 */
  volatile uint32_t INTERP1_ACCUM1_ADD; /**< Values written here are atomically added to ACCUM1 */
  volatile uint32_t INTERP1_BASE_1AND0; /**< lower 16 bits to BASE0, upper to BASE1 simultaneously. */
  volatile uint32_t SPINLOCK[32];       /**< Spinlock registers */
};

namespace CPUID {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< mask for allowed bits */
}  // namespace CPUID
namespace GPIO_IN {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_IN
namespace GPIO_HI_IN {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_IN
namespace GPIO_OUT {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OUT
namespace GPIO_OUT_SET {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OUT_SET
namespace GPIO_OUT_CLR {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OUT_CLR
namespace GPIO_OUT_XOR {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OUT_XOR
namespace GPIO_OE {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OE
namespace GPIO_OE_SET {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OE_SET
namespace GPIO_OE_CLR {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OE_CLR
namespace GPIO_OE_XOR {
constexpr inline std::uint32_t RESERVED_MASK{0xC000'0000u}; /**< mask for allowed bits */
}  // namespace GPIO_OE_XOR
namespace GPIO_HI_OUT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OUT
namespace GPIO_HI_OUT_SET {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OUT_SET
namespace GPIO_HI_OUT_CLR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OUT_CLR
namespace GPIO_HI_OUT_XOR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OUT_XOR
namespace GPIO_HI_OE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OE
namespace GPIO_HI_OE_SET {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OE_SET
namespace GPIO_HI_OE_CLR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OE_CLR
namespace GPIO_HI_OE_XOR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFE0u}; /**< mask for allowed bits */
}  // namespace GPIO_HI_OE_XOR
}  // namespace libMcuHw::sio

#endif