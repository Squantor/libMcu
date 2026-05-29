/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file fidfoallocator.hpp
 * @brief Implements a First In Discontinuous First Out allocator
 *
 */
#ifndef LIBMCU_FIDFOALLOCATOR_HPP
#define LIBMCU_FIDFOALLOCATOR_HPP

namespace libmcu {

/**
 * @brief First In Discontinuous First Out allocation class
 * @tparam T Type to be used in the FidfoAllocator
 * @tparam N Amount of elements in the FidfoAllocator
 */
template <typename T, std::size_t size, Assert_concept assert_policy = Assert_default>
class Fidfo_allocator {
 public:
  /**
   * @brief Construct a new Fidfo Allocator object
   */
  Fidfo_allocator() : max_fill(0) {
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
      assert_fail_if(true, "Fidfo_allocator.request: buffer is full");
      return {};
    }
  }
  /**
   * @brief Returns a block
   * @todo change back index to new block
   * @todo check if block points to used space, otherwise we have an ordering issue
   * @param block span to return
   */
  void release(std::span<T> block) {
    assert_fail_if((block.data() < buffer.data()) || (block.data() + block.size() >= buffer.data() + buffer.size()),
                   "Fidfo_allocator.release: block does not belong to buffer");
    assert_fail_if(block.size() > get_level(), "Fidfo_allocator.release: block is too big");
    std::size_t new_back = (block.data() + block.size()) - buffer.data();
    if (back < front) {
      assert_fail_if(new_back > front || new_back <= back, "Fidfo_allocator.release: block does not belong to used space");
      back = new_back;
    } else if (front < back) {
      assert_fail_if(new_back > front && new_back <= back, "Fidfo_allocator.release: block does not belong to used space");
      back = new_back;
    } else
      assert_fail_if(true, "Fidfo_allocator.release: buffer is empty");
    back = new_back;
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
   * @brief Increments the index by one
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
   * @return true Increment success
   * @return false Increment failed
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
    std::size_t level = get_level();
    if (level > max_fill)
      max_fill = level;
    return true;
  }
  std::size_t front;              /*!< first element of the allocator */
  std::size_t back;               /*!< last element of the allocator */
  std::size_t max_fill;           /*!< maximum fill level of the allocator */
  std::array<T, size + 1> buffer; /*!< allocator data, one element is added as we need always one element free */
};
}  // namespace libmcu

#endif
