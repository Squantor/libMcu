/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file ringbuffer.hpp
 * @brief Implements a generic ringbuffer class
 * @todo add doxygen documentation
 * @todo retool to use std::optional for the pop functions
 * @todo Add following functions, peekfront(), peekback(),
 * @todo peekfront(size_t count), peekback(size count)
 * @todo dropfront(size_t count), dropback(size_t count)
 */
#ifndef GENERAL_RINGBUFFER_HPP
#define GENERAL_RINGBUFFER_HPP

#include <array>
#include <cstdint>

namespace libmcu {

/**
 * @brief Generic ringbuffer
 * @tparam T Type to be used in the ringbuffer
 * @tparam N Amount of elements in the ringbuffer
 */
template <typename T, std::size_t size>
class RingBuffer {
 public:
  using iterator = typename std::array<T, size>::iterator;

  RingBuffer() {
    static_assert(size > 0, "ringbuffer size of zero is not allowed!");
    reset();
  }

  void reset() {
    front_ = data_.begin();
    back_ = data_.begin();
  }

  bool full() {
    return increment(front_) == back_;
  }

  bool empty() const {
    return front_ == back_;
  }

  /**
   * @brief returns fill level of the ringbuffer
   * @return amount of elements in ringbuffer
   */
  std::size_t level() {
    if (front_ > back_)
      return front_ - back_;
    if (back_ > front_)
      return size - (back_ - front_);
    else
      return 0;
  }

  bool pushBack(const T& p) {
    if (full())
      return false;
    auto temp = decrement(back_);
    back_ = temp;
    *back_ = p;
    return true;
  }

  bool pushFront(const T& p) {
    if (full())
      return false;
    auto temp = increment(front_);
    *front_ = p;
    front_ = temp;
    return true;
  }

  bool popBack(T& p) {
    if (empty())
      return false;
    auto temp = increment(back_);
    p = *back_;
    back_ = temp;
    return true;
  }

  bool popBack() {
    if (empty())
      return false;
    back_ = increment(back_);
    return true;
  }

  bool popFront(T& p) {
    if (empty())
      return false;
    auto temp = decrement(front_);
    p = *temp;
    front_ = temp;
    return true;
  }

  bool popFront(void) {
    if (empty())
      return false;
    front_ = decrement(front_);
    return true;
  }

 private:
  iterator decrement(const iterator p) {
    if (p == data_.begin())
      return data_.end() - 1;
    else
      return p - 1;
  }

  iterator increment(const iterator p) {
    if (p + 1 == data_.end())
      return data_.begin();
    else
      return p + 1;
  }

  iterator front_;               /*!< first element of the ringbuffer */
  iterator back_;                /*!< last element of the ringbuffer */
  std::array<T, size + 1> data_; /*!< ringbuffer data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
