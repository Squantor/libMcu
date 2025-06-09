/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F0_rcc_hw.hpp
 * @brief Register structure and bit definitions for the STM32F0 Reset and clock control
 */
#ifndef STM32F0_RCC_HW_HPP
#define STM32F0_RCC_HW_HPP

namespace libmcuhw::rcc {
/**
 * @brief rcc register definitions
 */
struct Rcc {
  volatile std::uint32_t CR;       /*!< clock control register */
  volatile std::uint32_t CFGR;     /*!< clock configuration register */
  volatile std::uint32_t CIR;      /*!< clock interrupt register */
  volatile std::uint32_t APB2RSTR; /*!< APB2 peripheral reset register */
  volatile std::uint32_t APB1RSTR; /*!< APB1 peripheral reset register */
  volatile std::uint32_t AHBENR;   /*!< AHB peripheral clock register */
  volatile std::uint32_t APB2ENR;  /*!< APB2 peripheral clock enable register */
  volatile std::uint32_t APB1ENR;  /*!< APB1 peripheral clock enable register */
  volatile std::uint32_t BDCR;     /*!< Backup domain control register */
  volatile std::uint32_t CSR;      /*!< clock control & status register */
  volatile std::uint32_t AHBRSTR;  /*!< AHB peripheral reset register */
  volatile std::uint32_t CFGR2;    /*!< clock configuration register 2 */
  volatile std::uint32_t CFGR3;    /*!< clock configuration register 3 */
  volatile std::uint32_t CR2;      /*!< clock control register 2 */
};
namespace CR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CFGR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CIR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace APB2RSTR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace APB1RSTR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace AHBENR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace APB2ENR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace APB1ENR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace BDCR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CSR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace AHBRSTR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CFGR2 {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CFGR3 {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CR2 {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}

}  // namespace libmcuhw::rcc
#endif