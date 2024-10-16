/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 *\file ringbuffer.hpp
 *
 * Implements a ringbuffer class
 * TODO: add doxygen documentation
 * TODO: retool to use std::optional for the pop functions
 * TODO: Add following functions, peekfront(), peekback(),
 * TODO: peekfront(size_t count), peekback(size count)
 * TODO: dropfront(size_t count), dropback(size_t count)
 */
#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <array>
#include <cstdint>

namespace libMcu {
template <typename T, std::size_t N>
class RingBuffer {
 public:
  using iterator = typename std::array<T, N>::iterator;

  RingBuffer() {
    static_assert(N > 0, "ringbuffer size of zero is not allowed!");
    reset();
  }

  void reset() {
    front = data.begin();
    back = data.begin();
  }

  bool full() {
    return increment(front) == back;
  }

  bool empty() const {
    return front == back;
  }

  /**
   * @brief returns fill level of the ringbuffer
   * @return amount of elements in ringbuffer
   */
  std::size_t level() {
    if (front > back)
      return front - back;
    if (back > front)
      return N - (back - front);
    else
      return 0;
  }

  bool pushBack(const T& p) {
    if (full())
      return false;
    auto temp = decrement(back);
    back = temp;
    *back = p;
    return true;
  }

  bool pushFront(const T& p) {
    if (full())
      return false;
    auto temp = increment(front);
    *front = p;
    front = temp;
    return true;
  }

  bool popBack(T& p) {
    if (empty())
      return false;
    auto temp = increment(back);
    p = *back;
    back = temp;
    return true;
  }

  bool popBack() {
    if (empty())
      return false;
    back = increment(back);
    return true;
  }

  bool popFront(T& p) {
    if (empty())
      return false;
    auto temp = decrement(front);
    p = *temp;
    front = temp;
    return true;
  }

  bool popFront(void) {
    if (empty())
      return false;
    front = decrement(front);
    return true;
  }

 private:
  iterator decrement(const iterator p) {
    if (p == data.begin())
      return data.end() - 1;
    else
      return p - 1;
  }

  iterator increment(const iterator p) {
    if (p + 1 == data.end())
      return data.begin();
    else
      return p + 1;
  }

  iterator front;            /**< first element of the ringbuffer */
  iterator back;             /**< last element of the ringbuffer */
  std::array<T, N + 1> data; /**< ringbuffer data, one element is added as we need always one element free */
};
}  // namespace libMcu

#endif
