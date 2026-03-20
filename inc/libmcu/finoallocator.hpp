/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file finoallocator.hpp
 * @brief Implements a First In Never Out allocator
 * By never out means that it will get eventually overwritten, this saves on housekeeping
 * of what blocks to release in order
 */
#ifndef FINOALLOCATOR_HPP
#define FINOALLOCATOR_HPP

namespace libmcu {

/**
 * @brief First In Never Out allocation class
 * This will overwrite the older blocks, be careful and overprovision this allocator
 * @tparam T Type to be used in the Fino_allocator
 * @tparam N Amount of elements in the Fino_allocator
 */
template <typename T, std::size_t size>
class Fino_allocator {
 public:
  /**
   * @brief Construct a new Fifo Allocator object
   */
  Fino_allocator() {
    static_assert(size > 0, "allocator size of zero is not allowed!");
  }
  /**
   * @brief Get a block of memory while overwriting older blocks
   * @param block_size Size of the block
   * @return std::span<T> pointing to the block
   */
  std::span<T> request(std::size_t block_size) {
    std::size_t old_front;
    // wrapping check
    if (front + block_size <= buffer.size())
      old_front = front;
    else
      old_front = 0;
    front = old_front + block_size;
    return {buffer.data() + old_front, block_size};
  }

 private:
  std::size_t front;          /*!< first element of the allocator */
  std::array<T, size> buffer; /*!< allocator data */
};
}  // namespace libmcu

#endif
