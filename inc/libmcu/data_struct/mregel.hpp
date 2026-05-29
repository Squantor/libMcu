/**
 *SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file mregel.hpp
 * @brief Mregel class definitions
 * @todo Add Justification enum to be used by Hex and Dec definitions and variants
 * @todo Add Hex definition that will add 0x prefix to the hex value
 * @todo Add Hex definition that will add h suffix to the hex value
 * @todo Add Dec definition that will limit the string size right justified
 * @todo Add Dec definition that will limit the string size left justified
 */
#ifndef LIBMCU_MREGEL_HPP
#define LIBMCU_MREGEL_HPP

namespace libmcu {

/**
 * @brief Defines a hex value, used to convert a hex value to a string
 */
struct Hex {
  std::uint32_t v; /*!< Hex value to convert */
};
/**
 * @brief Defines a decimal value, used to convert a decimal value to a string
 */
struct Dec {
  std::int32_t v; /*!< Decimal value to convert */
};
namespace detail {
const char hextab[] = "0123456789ABCDEF"; /*!< Hexadecimal digits table */
}
/**
 * @brief Class that provides a minimal string data store
 * @todo Let add methods return amount of characters added to string?
 */
class Mregel {
 public:
  /**
   * @brief Default empty constructor
   */
  Mregel() : mregel_data(std::span<char>()), mregel_data_size(0) {}
  /**
   * @brief Construct a new Mregel object with a non owning data store
   * @param data data store to use
   */
  Mregel(std::span<char> data) : mregel_data(data), mregel_data_size(0) {}
  // constructor for initializing the span
  /**
   * @brief Return size of Mregel
   * @return size in characters
   */
  constexpr std::size_t size() const noexcept {
    return mregel_data_size;
  }
  /**
   * @brief Return underlying size of Mregel
   * @return available space
   */
  constexpr std::size_t data_size() const noexcept {
    if (mregel_data.size() == 0) {
      return 0;
    }
    // subtract one to keep compatibility with C strings
    return mregel_data.size() - 1;
  }
  /**
   * @brief Return pointer to Mregel data store
   * @return char pointer to Mregel data store
   */
  constexpr char* data() const noexcept {
    return mregel_data.data();
  }
  /**
   * @brief Reset Mregel size
   */
  constexpr void reset() noexcept {
    mregel_data_size = 0;
  }
  /**
   * @brief Return pointer to Mregel data store formatted to a c string
   * @return pointer to c string
   */
  const char* c_str() const noexcept {
    for (size_t i = mregel_data_size; i < mregel_data.size(); i++) {
      mregel_data[i] = '\0';
    }
    return mregel_data.data();
  }
  /**
   * @brief Return Mregel as std::span
   * @return a span of characters
   */
  std::span<char> span() noexcept {
    if (mregel_data_size == 0)
      return std::span<char>();
    return std::span<char>(mregel_data.data(), mregel_data_size);
  }
  /**
   * @brief Add C string to Mregel
   * @note will copy up to mregel_data.size()
   * @param c_str C string
   */
  void add(const char* c_str) noexcept {
    while (*c_str != '\0' && mregel_data_size < mregel_data.size()) {
      mregel_data[mregel_data_size] = *c_str;
      mregel_data_size++;
      c_str++;
    }
  }
  /**
   * @brief Add character to Mregel
   * @param c Character to add
   */
  void add(char c) noexcept {
    if (mregel_data_size < mregel_data.size()) {
      mregel_data[mregel_data_size] = c;
      mregel_data_size++;
    }
  }
  /**
   * @brief Add a unsigned 32 bit integer to Mregel
   * @param n Value to convert and add
   */
  void add(std::uint32_t n) {
    add_num(10, n);
  }
  /**
   * @brief Add a hex value to Mregel
   * @param n Value to convert and add
   */
  void add(Hex n) {
    add_num(16, n.v);
  }
  /**
   * @brief Add a decimal value to Mregel
   * @param n Value to convert and add
   */
  void add(Dec n) {
    if (n.v < 0) {
      add('-');
      n.v = -n.v;
    }
    add_num(10, n.v);
  }
  /**
   * @brief Prints a variable number of arguments
   * @tparam Ts Types
   * @param t parameter to print
   */
  template <typename... Ts>
  void add(Ts... t) {
    (add(t), ...);
  }

 private:
  /**
   * @brief Converts an integer to a string and adds it to Mregel
   * @param base Base of the number
   * @param n Value to convert a and add
   */
  void add_num(const unsigned int base, const uintmax_t n) {
    // Determine the number of digits we need to print and the maximum divisor
    uintmax_t divisor = 1;
    unsigned int p = 0;
    for (uintmax_t i = n; i >= base; i /= base, p++, divisor *= base)
      /* Loop to determine size of number */;

    // Print from most-to-least significant digit
    for (unsigned int i = 0; i <= p; i++, divisor /= base)
      add(detail::hextab[(n / divisor) % base]);
  }
  std::span<char> mregel_data;
  std::size_t mregel_data_size;
};

}  // namespace libmcu
#endif