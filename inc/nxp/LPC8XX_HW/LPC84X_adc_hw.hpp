/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Analog to Digital converter register interface
 */
#ifndef LPC84X_ADC_HW_HPP
#define LPC84X_ADC_HW_HPP

namespace libMcuLL::hw::adc {
/**
 * @brief Analog to Digital converter register definitions
 */
struct peripheral {
  volatile std::uint32_t CTRL;              /**< ADC Control register */
  std::uint8_t RESERVED_0[4];               /**< Reserved */
  volatile std::uint32_t SEQ_CTRL[2];       /**< ADC Conversion Sequence-n control register */
  volatile const std::uint32_t SEQ_GDAT[2]; /**< ADC Sequence-n Global Data register */
  std::uint8_t RESERVED_1[8];               /**< Reserved */
  volatile const std::uint32_t DAT[12];     /**< ADC Channel N Data register */
  volatile std::uint32_t THR0_LOW;          /**< ADC Low Compare Threshold register 0 */
  volatile std::uint32_t THR1_LOW;          /**< ADC Low Compare Threshold register 1 */
  volatile std::uint32_t THR0_HIGH;         /**< ADC High Compare Threshold register 0 */
  volatile std::uint32_t THR1_HIGH;         /**< ADC High Compare Threshold register 1 */
  volatile std::uint32_t CHAN_THRSEL;       /**< ADC Channel-Threshold Select register */
  volatile std::uint32_t INTEN;             /**< ADC Interrupt Enable register */
  volatile std::uint32_t FLAGS;             /**< ADC Flags register */
  volatile std::uint32_t TRM;               /**< ADC Startup register */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x4000'05FFu}; /**< register mask for allowed bits */
/**
 * @brief Format clock divider value
 * @param divider ADC divider value
 * @return formatted data for CTRL register

 */
constexpr inline std::uint32_t CLKDIV(std::uint32_t divider) {
  return divider << 0;
}
constexpr inline std::uint32_t ASYNCMODE{0 << 8}; /**< */
}  // namespace CTRL
namespace SEQ_CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0C'7FFFu}; /**< register mask for allowed bits */
}
namespace SEQ_GDAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0F'FFF0u}; /**< register mask for allowed bits */
}
namespace DAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0F'FFF0u}; /**< register mask for allowed bits */
}
namespace THR0_LOW {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< register mask for allowed bits */
}
namespace THR1_LOW {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< register mask for allowed bits */
}
namespace THR0_HIGH {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< register mask for allowed bits */
}
namespace THR1_HIGH {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< register mask for allowed bits */
}
namespace CHAN_THRSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0FFFu}; /**< register mask for allowed bits */
}
namespace INTEN {
constexpr inline std::uint32_t RESERVED_MASK{0x07FF'FFFFu}; /**< register mask for allowed bits */
}
namespace FLAGS {
constexpr inline std::uint32_t RESERVED_MASK{0xF3FF'FFFFu}; /**< register mask for allowed bits */
}
namespace TRM {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0020u}; /**< register mask for allowed bits */
}
}  // namespace libMcuLL::hw::adc
#endif