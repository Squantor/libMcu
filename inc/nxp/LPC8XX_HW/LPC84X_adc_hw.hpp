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

namespace libMcuHw::adc {
/**
 * @brief
 */
enum sequencers : std::size_t {
  SEQA = 0, /**< ADC sequencer A */
  SEQB = 1, /**< ADC sequencer B */
};
/**
 * @brief Analog to Digital converter register definitions
 */
struct adc {
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
constexpr inline std::uint32_t ASYNCMODE{1u << 8}; /**< Asynchronous mode */
constexpr inline std::uint32_t LPWRMODE{1u << 10}; /**< Low power ADC mode */
constexpr inline std::uint32_t CALMODE{1u << 30};  /**< Initiate ADC selfcalibration cycle */
}  // namespace CTRL
namespace SEQ_CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0C'7FFFu}; /**< Register mask for allowed bits */
/**
 * @brief Format channel value to CHANNELS bitfield
 * @param channel ADC channel to set in CHANNELS bitfield
 * @return formatted data for CHANNELS register
 */
constexpr inline std::uint32_t CHANNELS(std::uint32_t channel) {
  return 1u << channel;
}
constexpr inline std::uint32_t TRIG_NONE{0u << 12};          /**< No trigger */
constexpr inline std::uint32_t TRIG_PININT0_IRQ{1u << 12};   /**< GPIO_INT interrupt 0 */
constexpr inline std::uint32_t TRIG_PININT1_IRQ{2u << 12};   /**< GPIO_INT interrupt 1 */
constexpr inline std::uint32_t TRIG_SCT0_OUT3{3u << 12};     /**< SCT output 3 */
constexpr inline std::uint32_t TRIG_SCT0_OUT4{4u << 12};     /**< SCT output 4 */
constexpr inline std::uint32_t TRIG_T0_MAT3{5u << 12};       /**< CTIMER match 3 */
constexpr inline std::uint32_t TRIG_CMP0_OUT_ADC{6u << 12};  /**< Analog comparator output */
constexpr inline std::uint32_t TRIG_GPIO_INT_BMAT{7u << 12}; /**< GPIO_INT bmatch */
constexpr inline std::uint32_t TRIG_ARM_TXEV{8u << 12};      /**< ARM core TXEV event */
constexpr inline std::uint32_t TRIGPOL_NEG{0u << 18};        /**< Negative trigger polarity */
constexpr inline std::uint32_t TRIGPOL_POS{1u << 18};        /**< Positive trigger polarity */
constexpr inline std::uint32_t SYNCBYPASS{1u << 19};         /**< Bypass trigger synchronizer */
constexpr inline std::uint32_t START{1u << 26};              /**< Starts single conversion sequence */
constexpr inline std::uint32_t BURST{1u << 27};              /**< Continuous conversion sequence */
constexpr inline std::uint32_t SINGLESTEP{1u << 28};         /**< Stepped conversion squence */
constexpr inline std::uint32_t LOWPRIO{1u << 29};            /**< High priority over sequence B */
constexpr inline std::uint32_t MODE_CONV{0u << 30};          /**< interrupt/DMA after each conversion */
constexpr inline std::uint32_t MODE_SEQ{1u << 30};           /**< Interrupt/DMA after each sequence */
constexpr inline std::uint32_t SEQ_ENA{1u << 31};            /**< Enable sequence */
}  // namespace SEQ_CTRL
namespace SEQ_GDAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0F'FFF0u}; /**< Register mask for allowed bits */
constexpr inline std::uint32_t RESULT_MASK{0x0000'FFF0};
/**
 * @brief format SEQ_GDAT register to extract RESULT field
 * @param register SEQ_GDAT register
 * @return extracted RESULT field
 */
constexpr inline std::uint32_t RESULT(std::uint32_t data) {
  return (data & RESULT_MASK) >> 4;
}
/**
 * @brief format SEQ_GDAT register to extract CHN field
 * @param register SEQ_GDAT register
 * @return extracted CHN field
 */
constexpr inline std::uint32_t CHN(std::uint32_t data) {
  return data >> 26;
}
constexpr inline std::uint32_t OVERRUN_FLAG{1u << 30};   /**< Data overrun detected */
constexpr inline std::uint32_t DATAVALID_FLAG{1u << 31}; /**< Valid data available */
}  // namespace SEQ_GDAT
namespace DAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFC0F'FFF0u}; /**< Register mask for allowed bits */
constexpr inline std::uint32_t RESULT_MASK{0x0000'FFF0};
/**
 * @brief format SEQ_GDAT register to extract RESULT field
 * @param register SEQ_GDAT register
 * @return extracted RESULT field
 */
constexpr inline std::uint32_t RESULT(std::uint32_t data) {
  return (data & RESULT_MASK) >> 4;
}
/**
 * @brief format SEQ_GDAT register to extract CHN field
 * @param register SEQ_GDAT register
 * @return extracted CHN field
 */
constexpr inline std::uint32_t CHN(std::uint32_t data) {
  return data >> 26;
}
constexpr inline std::uint32_t OVERRUN_FLAG{1u << 30};   /**< Data overrun detected */
constexpr inline std::uint32_t DATAVALID_FLAG{1u << 31}; /**< Valid data available */
}  // namespace DAT
namespace THR0_LOW {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< Register mask for allowed bits */
}
namespace THR1_LOW {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< Register mask for allowed bits */
}
namespace THR0_HIGH {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< Register mask for allowed bits */
}
namespace THR1_HIGH {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'FFF0u}; /**< Register mask for allowed bits */
}
namespace CHAN_THRSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0FFFu}; /**< Register mask for allowed bits */
}
namespace INTEN {
constexpr inline std::uint32_t RESERVED_MASK{0x07FF'FFFFu}; /**< Register mask for allowed bits */
}
namespace FLAGS {
constexpr inline std::uint32_t RESERVED_MASK{0xF3FF'FFFFu}; /**< Register mask for allowed bits */
}
namespace TRM {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0020u}; /**< Register mask for allowed bits */
}
}  // namespace libMcuHw::adc
#endif