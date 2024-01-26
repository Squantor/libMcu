/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file nvic register interface
 */
#ifndef NVIC_HW_HPP
#define NVIC_HW_HPP
namespace libMcuLL {
namespace hw {
namespace nvic {
struct peripheral {
  volatile std::uint32_t ISER[1U]; /**< interrupt set enable register */
  std::uint32_t RESERVED0[31U];
  volatile std::uint32_t ICER[1U]; /**< interrupt clear enable register */
  std::uint32_t RESERVED1[31U];
  volatile std::uint32_t ISPR[1U]; /**< interrupt set pending register */
  std::uint32_t RESERVED2[31U];
  volatile std::uint32_t ICPR[1U]; /**< interrupt clear pending register */
  std::uint32_t RESERVED3[31U];
  std::uint32_t RESERVED4[64U];
  volatile std::uint32_t IP[8U]; /**< interrupt priority register */
};
namespace ISER {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace ICER {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace ISPR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace ICPR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}
namespace IP {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000000; /**< register mask for allowed bits */
}

}  // namespace nvic
}  // namespace hw
}  // namespace libMcuLL

#endif