/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file STM32F0_gpio_hw.hpp
 * \brief STM32F0 GPIO register interface
 */
#ifndef STM32F0_GPIO_HW_HPP
#define STM32F0_GPIO_HW_HPP

namespace libMcuHw::gpio {
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
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace OTYPER {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace OSPEEDR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace PUPDR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace IDR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace ODR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace BSRR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace LCKR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace AFR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}
namespace BRR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFFu; /**< register mask for allowed bits */
}

}  // namespace libMcuHw::gpio
#endif