/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file fifoallocator.hpp
 * @brief Implements a First In First Out allocator
 */
#ifndef LIBMCU_FIFOALLOCATOR_HPP
#define LIBMCU_FIFOALLOCATOR_HPP

namespace libmcu {

/**
 * @brief First In First Out allocation class
 * @tparam T Type to be used in the Fifo_allocator
 * @tparam N Amount of elements in the Fifo_allocator
 */
template <typename T, std::size_t size, Assert_concept assert_policy = Assert_default>
class Fifo_allocator {
 public:
  /**
   * @brief Construct a new Fifo Allocator object
   */
  Fifo_allocator() {
    static_assert(size > 0, "allocator size of zero is not allowed!");
    reset();
  }
  /**
   * @brief Resets the allocator
   */
  void reset() {
    front = 0;
    back = 0;
  }
  /**
   * @brief Checks if the allocator is full
   * @return true if allocator is full
   * @return false if allocator is not full
   */
  bool is_full() {
    return increment(front) == back;
  }
  /**
   * @brief Checks if the allocator is empty
   * @return true if allocator is empty
   * @return false if allocator is not empty
   */
  bool is_empty() const {
    return front == back;
  }
  /**
   * @brief returns fill level of the allocator
   * @return amount of elements in allocator
   */
  std::size_t get_level() {
    if (front > back)
      return front - back;
    if (back > front)
      return buffer.size() - (back - front);
    else
      return 0;
  }
  /**
   * @brief Get a block of memory
   * @param block_size Size of the block
   * @return std::span<T> pointing to the block, returns an empty span if full
   */
  std::span<T> request(std::size_t block_size) {
    std::size_t old_front;
    // wrapping check
    if (front + block_size <= buffer.size())
      old_front = front;
    else
      old_front = 0;
    if (try_increment_front(block_size))
      return {buffer.data() + old_front, block_size};
    else {
      assert_fail_if(true, "Fifo_allocator.request: buffer is full");
      return {};
    }
  }
  /**
   * @brief Returns a block
   * We do zero checks here if the span is at all valid
   * @param block span to return
   */
  void release(std::span<T> block) {
    assert_fail_if(buffer.data() + back != block.data(), "Fifo_allocator.release: does not match back index");
    back = back + block.size();
  }

 private:
  /**
   * @brief
   * @param cond
   * @param msg
   */
  constexpr void assert_fail_if(bool cond, const char* msg) noexcept {
    if constexpr (assert_policy::enabled) {
      if (cond) {
        assert_policy::fail(msg);
      }
    }
  }
  /**
   * @brief increments the index by one
   * @param p index to increment
   * @return incremented index taking care of wraparound
   */
  std::size_t increment(const std::size_t index) {
    if (index + 1 == buffer.size())
      return 0;
    else
      return index + 1;
  }
  /**
   * @brief Tries to increment the index by a given block size
   * @param block_size Size of the increment
   * @return true increment success
   * @return false increment failed
   */
  bool try_increment_front(std::size_t block_size) {
    std::size_t new_front = front + block_size;
    if (new_front > buffer.size()) {
      // Current block is so big that we wrap around, try again from beginning of buffer
      new_front = block_size;
      if (new_front > back)
        return false;
    }
    front = new_front;
    return true;
  }
  std::size_t front;              /*!< first element of the allocator */
  std::size_t back;               /*!< last element of the allocator */
  std::array<T, size + 1> buffer; /*!< allocator data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
