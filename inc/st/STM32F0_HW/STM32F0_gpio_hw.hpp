/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F0_gpio_hw.hpp
 * @brief Register structure and bit definitions for the STM32F0 GPIO
 */
#ifndef STM32F0_GPIO_HW_HPP
#define STM32F0_GPIO_HW_HPP

namespace libmcuhw::gpio {
/**
 * @brief gpio register definitions
 */
struct gpio {
  volatile std::uint32_t MODER;   /*!< port mode register */
  volatile std::uint32_t OTYPER;  /*!< port output type register */
  volatile std::uint32_t OSPEEDR; /*!< port output speed register */
  volatile std::uint32_t PUPDR;   /*!< port pull-up/pull-down register */
  volatile std::uint32_t IDR;     /*!< port input data register */
  volatile std::uint32_t ODR;     /*!< port output data register */
  volatile std::uint32_t BSRR;    /*!< port bit set/reset register */
  volatile std::uint32_t LCKR;    /*!< port configuration lock register  */
  volatile std::uint32_t AFR[2];  /*!< alternate function low register */
  volatile std::uint32_t BRR;     /*!< bit reset register */
};
namespace MODER {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace OTYPER {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace OSPEEDR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace PUPDR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace IDR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace ODR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace BSRR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace LCKR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}
namespace AFR {
constexpr inline std::uint32_t kRESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t AF0{0u << 0};                /*!< Alternate function 0 */
constexpr inline std::uint32_t AF1{1u << 0};                /*!< Alternate function 1 */
constexpr inline std::uint32_t AF2{2u << 0};                /*!< Alternate function 2 */
constexpr inline std::uint32_t AF3{3u << 0};                /*!< Alternate function 3 */
constexpr inline std::uint32_t AF4{4u << 0};                /*!< Alternate function 4 */
constexpr inline std::uint32_t AF5{5u << 0};                /*!< Alternate function 5 */
constexpr inline std::uint32_t AF6{6u << 0};                /*!< Alternate function 6 */
constexpr inline std::uint32_t AF7{7u << 0};                /*!< Alternate function 7 */
/**
 * @brief Returns the AFR index
 * @param pin pin number to find the AFR index of
 * @return AFR index
 */
constexpr inline std::uint32_t AFRINDEX(std::uint32_t pin) {
  return (pin / 8);
}
/**
 * @brief read modifies writes the AFR register with the requested function
 * @param input_reg AFR register to modify
 * @param pin pin number to modify
 * @param function function to set
 * @return modified AFR register
 */
constexpr inline std::uint32_t AFR_SET(std::uint32_t input_reg, std::uint32_t pin, std::uint32_t function) {
  std::uint32_t shift_factor = (pin % 8) * 4;
  input_reg &= ~(0xF << shift_factor);
  input_reg |= function << shift_factor;
  return input_reg;
}
}  // namespace AFR
namespace BRR {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFFFFFFu}; /*!< register mask for allowed bits */
}

}  // namespace libmcuhw::gpio
#endif