/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file ringbuffer.hpp
 * @brief Implements a generic ringbuffer class
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
 * @todo add doxygen documentation
 * @todo retool to use std::optional for the pop functions
 * @todo Add following functions, peekfront(), peekback(),
 * @todo peekfront(size_t count), peekback(size count)
 * @todo dropfront(size_t count), dropback(size_t count)
 * @todo change naming
 * @todo add assertion policy parameter for overflow/underflow
 */
template <typename T, std::size_t size>
class RingBuffer {
 public:
  using iterator = typename std::array<T, size>::iterator;
  /**
   * @brief Construct a new Ring Buffer object
   */
  RingBuffer() {
    static_assert(size > 0, "ringbuffer size of zero is not allowed!");
    Reset();
  }
  /**
   * @brief Resets the ringbuffer
   */
  void Reset() {
    front = buffer.begin();
    back = buffer.begin();
  }
  /**
   * @brief Checks if the ringbuffer is full
   * @return true if ringbuffer is full
   * @return false if ringbuffer is not full
   */
  bool IsFull() {
    return Increment(front) == back;
  }
  /**
   * @brief Checks if the ringbuffer is empty
   * @return true if ringbuffer is empty
   * @return false if ringbuffer is not empty
   */
  bool IsEmpty() const {
    return front == back;
  }
  /**
   * @brief returns fill level of the ringbuffer
   * @return amount of elements in ringbuffer
   */
  std::size_t GetLevel() {
    if (front > back)
      return front - back;
    if (back > front)
      return size - (back - front);
    else
      return 0;
  }
  /**
   * @brief Pushes a value to the back of the ringbuffer
   * @param p Element to push
   * @return true if push was successful
   * @return false if buffer was full
   */
  bool PushBack(const T& p) {
    if (IsFull())
      return false;
    auto temp = Decrement(back);
    back = temp;
    *back = p;
    return true;
  }
  /**
   * @brief Pushes a value to the front of the ringbuffer
   * @param p Element to push
   * @return true if push was successful
   * @return false if buffer was full
   */
  bool PushFront(const T& p) {
    if (IsFull())
      return false;
    auto temp = Increment(front);
    *front = p;
    front = temp;
    return true;
  }
  /**
   * @brief Pops a value from the back of the ringbuffer
   * @param p Element to pop into
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool PopBack(T& p) {
    if (IsEmpty())
      return false;
    auto temp = Increment(back);
    p = *back;
    back = temp;
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool PopBack() {
    if (IsEmpty())
      return false;
    back = Increment(back);
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @param p Element to pop into
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool PopFront(T& p) {
    if (IsEmpty())
      return false;
    auto temp = Decrement(front);
    p = *temp;
    front = temp;
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool PopFront(void) {
    if (IsEmpty())
      return false;
    front = Decrement(front);
    return true;
  }

 private:
  /**
   * @brief Decrements the iterator
   * @param p iterator to decrement
   * @return decremented iterator taking care of wraparound
   */
  iterator Decrement(const iterator p) {
    if (p == buffer.begin())
      return buffer.end() - 1;
    else
      return p - 1;
  }
  /**
   * @brief Increments the iterator
   * @param p interator to increment
   * @return incremented iterator taking care of wraparound
   */
  iterator Increment(const iterator p) {
    if (p + 1 == buffer.end())
      return buffer.begin();
    else
      return p + 1;
  }

  iterator front;                 /*!< first element of the ringbuffer */
  iterator back;                  /*!< last element of the ringbuffer */
  std::array<T, size + 1> buffer; /*!< ringbuffer data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
