/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file print.hpp
 * @brief printing functions and types
 */
#ifndef PRINT_HPP
#define PRINT_HPP

namespace libmcumid {
/**
 * @brief Defines a hex value, used by printing functions
 */
struct Hex {
  std::uint32_t v;
};
/**
 * @brief Defines a decimal value, used by printing functions
 */
struct Dec {
  std::int32_t v;
};
namespace detail {
const char hextab[] = "0123456789ABCDEF"; /*!< Hexadecimal digits table */
/**
 * @brief Prints a number in a given base
 * @tparam Emitter Lambda type to emit characters
 * @param base Base of the number
 * @param n Number
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void putint(const unsigned int base, const uintmax_t n, Emitter emit) {
  // Determine the number of digits we need to print and the maximum divisor
  uintmax_t divisor = 1;
  unsigned int p = 0;
  for (uintmax_t i = n; i >= base; i /= base, p++, divisor *= base)
    /* Loop to determine size of number */;

  // Print from most-to-least significant digit
  for (unsigned int i = 0; i <= p; i++, divisor /= base)
    emit(hextab[(n / divisor) % base]);
}
/**
 * @brief Prints a string
 * @tparam Emitter Lambda type to emit characters
 * @param s C string to print
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void print(const char* s, Emitter emit) {
  while (*s)
    emit(*s++);
}
/**
 * @brief Prints a string
 * @tparam Emitter Lambda type to emit characters
 * @param s Span to print
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void print(std::span<const char> s, Emitter emit) {
  for (const char c : s)
    emit(c);
}
/**
 * @brief Prints a unsigned 32 bit integer
 * @tparam Emitter Lambda type to emit characters
 * @param n Number to print
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void print(std::uint32_t n, Emitter emit) {
  putint(10, n, emit);
}
/**
 * @brief Prints a hex value
 * @tparam Emitter Lamda type to emit characters
 * @param n number to print
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void print(Hex n, Emitter emit) {
  putint(16, n.v, emit);
}
/**
 * @brief Prints a decimal value
 * @tparam Emitter Lambda type to emit characters
 * @param n number to print
 * @param emit Lambda to emit characters
 */
template <typename Emitter>
void print(Dec n, Emitter emit) {
  int32_t value{n.v};
  if (value < 0) {
    emit('-');
    value = -value;
  }
  putint(10, value, emit);
}
}  // namespace detail
/**
 * @brief Prints a variable number of arguments
 * @tparam Ts Types
 * @param t parameter to print
 */
template <typename... Ts>
void print(Ts... t) {
  (libmcumid::detail::print(t), ...);
}
}  // namespace libmcumid

#endif