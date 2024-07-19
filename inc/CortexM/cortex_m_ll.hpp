/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file cortex m functions
 */
#ifndef CORTEX_M_LL_HPP
#define CORTEX_M_LL_HPP
namespace libMcu::ll {

/**
 * @brief No operation
 *
 * No Operation does nothing. This instruction can be used for code alignment purposes.
 *
 */
__attribute__((always_inline)) static inline void nop() {
  asm volatile inline("nop");
}

/**
 * @brief Waits for interrupt
 *
 * Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 *
 */
__attribute__((always_inline)) static inline void wfi() {
  asm volatile inline("wfi");
}

/**
 * @brief Wait for event
 *
 * Wait For Event is a hint instruction that permits the processor to enter a low-power state until one of a number of events
 * occurs.
 *
 */
__attribute__((always_inline)) static inline void wfe() {
  asm volatile inline("wfe");
}

/**
 * @brief Send event
 *
 * Send event is a hint instruction. It causes an event to be signaled to the CPU.
 *
 */
__attribute__((always_inline)) static inline void sev() {
  asm volatile inline("sev");
}

/**
 * @brief Instruction synchronisation barrier
 *
 * Instruction Synchronization Barrier flushes the pipeline in the processor, so that all instructions following the ISB are fetched
 * from cache or memory, after the instruction has been completed.
 *
 */
__attribute__((always_inline)) static inline void isb() {
  asm volatile inline("isb 0xF" ::: "memory");
}

/**
 * @brief Data synchronisation barrier
 *
 * Acts as a special kind of Data Memory Barrier. It completes when all explicit memory accesses before this instruction complete.
 *
 */
__attribute__((always_inline)) static inline void dsb() {
  asm volatile inline("dsb 0xF" ::: "memory");
}

/**
 * @brief Data memory barrier
 *
 * Ensures the apparent order of the explicit memory operations before and after the instruction, without ensuring their completion.
 *
 */
__attribute__((always_inline)) static inline void dmb() {
  asm volatile inline("dmb 0xF" ::: "memory");
}

/**
 * @brief Reverse byte order
 *
 * Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
 *
 * @param value Value to reverse
 * @return reversed value
 */
__attribute__((always_inline)) static inline std::uint32_t rev(std::uint32_t value) {
  return __builtin_bswap32(value);
}

/**
 * @brief Reverse byte order (16 bit)
 *
 * Reverses the byte order within each halfword of a word. For example, 0x1234 becomes 0x3412.
 *
 * @param value Value to reverse
 * @return Reversed value
 */
__attribute__((always_inline)) static inline std::uint16_t rev(std::uint16_t value) {
  std::uint32_t result;

  asm volatile inline("rev16 %0, %1" : "=l"(result) : "l"(value));
  return result;
}

/**
 * @brief Reverse byte order signed 16 bit
 *
 * @param Value Value to reverse
 * @return Reversed value
 */
__attribute__((always_inline)) static inline std::int16_t rev(std::int16_t value) {
  return static_cast<std::int16_t>(__builtin_bswap16(value));
}

/**
 * @brief Rotate right
 *
 * @param value Value to rotate
 * @param count Number of bits to rotate
 * @return rotated value
 */
__attribute__((always_inline)) static inline std::uint32_t ror(std::uint32_t value, std::uint32_t count) {
  count %= 32U;
  if (count == 0U) {
    return value;
  }
  return (value >> count) | (value << (32U - count));
}

/**
 * @brief Breakpoint
 *
 * Causes the processor to enter Debug state. Debug tools can use this to investigate system state when the instruction at a
 * particular address is reached.
 *
 * @param value is ignored by the processor. If required, a debugger can use it to store additional information about the
 * breakpoint.
 */
#define LIBMCULL_BKPT(value) __asm volatile("bkpt " #value)

}  // namespace libMcu::ll

#endif