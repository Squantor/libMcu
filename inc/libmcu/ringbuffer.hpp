/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file ringbuffer.hpp
 * @brief Implements a generic ringbuffer class
 */
#ifndef LIBMCU_RINGBUFFER_HPP
#define LIBMCU_RINGBUFFER_HPP

namespace libmcu {

/**
 * @brief Generic ringbuffer
 * @tparam T Type to be used in the ringbuffer
 * @tparam N Amount of elements in the ringbuffer
 * @todo Add following functions, peekfront(), peekback(),
 * @todo peekfront(size_t count), peekback(size count)
 * @todo dropfront(size_t count), dropback(size_t count)
 * @todo add assertion policy parameter for overflow/underflow
 */
template <typename T, std::size_t size, Assert_concept assert_policy = Assert_default>
class Ring_buffer {
 public:
  /**
   * @brief Construct a new Ring Buffer object
   */
  Ring_buffer() {
    static_assert(size > 0, "ringbuffer size of zero is not allowed!");
    reset();
  }
  /**
   * @brief Resets the ringbuffer
   */
  void reset() {
    front = 0;
    back = 0;
  }
  /**
   * @brief Checks if the ringbuffer is full
   * @return true if ringbuffer is full
   * @return false if ringbuffer is not full
   */
  bool is_full() {
    return increment(front) == back;
  }
  /**
   * @brief Checks if the ringbuffer is empty
   * @return true if ringbuffer is empty
   * @return false if ringbuffer is not empty
   */
  bool is_empty() const {
    return front == back;
  }
  /**
   * @brief returns fill level of the ringbuffer
   * @return amount of elements in ringbuffer
   */
  std::size_t get_level() {
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
  bool push_back(const T& p) {
    if (is_full()) {
      assert_fail_if(true, "Ring_buffer.push_back: buffer is full");
      return false;
    }
    auto temp = decrement(back);
    back = temp;
    buffer[back] = p;
    return true;
  }
  /**
   * @brief Pushes a value to the front of the ringbuffer
   * @param p Element to push
   * @return true if push was successful
   * @return false if buffer was full
   */
  bool push_front(const T& p) {
    if (is_full()) {
      assert_fail_if(true, "Ring_buffer.push_front: buffer is full");
      return false;
    }
    auto temp = increment(front);
    buffer[front] = p;
    front = temp;
    return true;
  }
  /**
   * @brief Pops a value from the back of the ringbuffer
   * @param p Element to pop into
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool pop_back(T& p) {
    if (is_empty()) {
      assert_fail_if(true, "Ring_buffer.pop_back: buffer is empty");
      return false;
    }
    auto temp = increment(back);
    p = buffer[back];
    back = temp;
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool pop_back() {
    if (is_empty()) {
      assert_fail_if(true, "Ring_buffer.pop_back: buffer is empty");
      return false;
    }
    back = increment(back);
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @param p Element to pop into
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool pop_front(T& p) {
    if (is_empty()) {
      assert_fail_if(true, "Ring_buffer.pop_front: buffer is empty");
      return false;
    }
    auto temp = decrement(front);
    p = buffer[temp];
    front = temp;
    return true;
  }
  /**
   * @brief Pops a value from the front of the ringbuffer
   * @return true if pop was successful
   * @return false if buffer was empty
   */
  bool pop_front(void) {
    if (is_empty()) {
      assert_fail_if(true, "Ring_buffer.pop_front: buffer is empty");
      return false;
    }
    front = decrement(front);
    return true;
  }

 private:
  /**
   * @brief Asserts if a condition is true
   * @param cond Condition to check
   * @param msg Message to print
   */
  constexpr void assert_fail_if(bool cond, const char* msg) noexcept {
    if constexpr (assert_policy::enabled) {
      if (cond) {
        assert_policy::fail(msg);
      }
    }
  }
  /**
   * @brief Decrements the iterator
   * @param p iterator to decrement
   * @return decremented iterator taking care of wraparound
   */
  std::size_t decrement(std::size_t i) {
    if (i == 0)
      return buffer.size() - 1;
    else
      return i - 1;
  }
  /**
   * @brief Increments the iterator
   * @param p interator to increment
   * @return incremented iterator taking care of wraparound
   */
  std::size_t increment(std::size_t i) {
    if (i + 1 == buffer.size())
      return 0;
    else
      return i + 1;
  }

  std::size_t front;              /*!< first element of the ringbuffer */
  std::size_t back;               /*!< last element of the ringbuffer */
  std::array<T, size + 1> buffer; /*!< ringbuffer data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
