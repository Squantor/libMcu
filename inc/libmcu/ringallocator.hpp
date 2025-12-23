/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file ringallocator.hpp
 * @brief Implements a ring allocator
 */
#ifndef RINGALLOCATOR_HPP
#define RINGALLOCATOR_HPP

namespace libmcu {

/**
 * @brief Ring buffer that returns blocks
 * @tparam T Type to be used in the RingAllocator
 * @tparam N Amount of elements in the RingAllocator
 */
template <typename T, std::size_t size, AssertCallable Assert = NoAssert>
class RingAllocator {
 public:
  /**
   * @brief Construct a new Ring Buffer object
   */
  RingAllocator() {
    static_assert(size > 0, "ringbuffer size of zero is not allowed!");
    Reset();
  }
  /**
   * @brief Resets the ringbuffer
   */
  void Reset() {
    front = 0;
    back = 0;
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
      return buffer.size() - (back - front);
    else
      return 0;
  }
  /**
   * @brief Get a block of memory
   * @param block_size Size of the block
   * @return std::span<T> pointing to the block, returns an empty span if full
   */
  std::span<T> Request(std::size_t block_size) {
    std::size_t old_front;
    // wrapping check
    if (front + block_size <= buffer.size())
      old_front = front;
    else
      old_front = 0;
    if (TryIncrementFront(block_size))
      return {buffer.data() + old_front, block_size};
    else {
      AssertFailIf(true, "RingAllocator::Request: buffer is full");
      return {};
    }
  }
  /**
   * @brief Returns a block
   * We do zero checks here if the span is at all valid
   * @param block span to return
   */
  void Release(std::span<T> block) {
    AssertFailIf(buffer.data() + back != block.data(), "RingAllocator::Release: does not match back index");
    back = back + block.size();
  }

 private:
  /**
   * @brief
   * @param cond
   * @param msg
   */
  constexpr void AssertFailIf(bool cond, const char* msg) noexcept {
    if constexpr (!std::is_same_v<Assert, NoAssert>) {
      if (cond) {
        assert_function(msg);
      }
    }
  }
  /**
   * @brief Increments the index by one
   * @param p index to increment
   * @return incremented index taking care of wraparound
   */
  std::size_t Increment(const std::size_t index) {
    if (index + 1 == buffer.size())
      return 0;
    else
      return index + 1;
  }
  /**
   * @brief Tries to increment the index by a given block size
   * @param block_size Size of the increment
   * @return true Increment success
   * @return false Increment failed
   */
  bool TryIncrementFront(std::size_t block_size) {
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
  [[no_unique_address]] Assert assert_function{}; /*!< assertion function */
  std::size_t front;                              /*!< first element of the ringbuffer */
  std::size_t back;                               /*!< last element of the ringbuffer */
  std::array<T, size + 1> buffer;                 /*!< ringbuffer data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
