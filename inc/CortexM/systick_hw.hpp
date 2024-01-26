/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick register interface
 */
#ifndef SYSTICK_HW_HPP
#define SYSTICK_HW_HPP
namespace libMcuLL {
namespace hw {
namespace systick {
struct peripheral {
  volatile std::uint32_t CTRL;        /**< systick control and status register */
  volatile std::uint32_t LOAD;        /**< systick reload value register */
  volatile std::uint32_t VAL;         /**< systick current value register */
  volatile const std::uint32_t CALIB; /**< systick calibration register */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace LOAD {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace VAL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace CALIB {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}

}  // namespace systick
}  // namespace hw
}  // namespace libMcuLL
#endif