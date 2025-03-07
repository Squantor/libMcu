/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Input multiplexer register interface
 */
#ifndef LPC84X_INMUX_HW_HPP
#define LPC84X_INMUX_HW_HPP

namespace libMcuHw::inmux {
/**
 * @brief INMUX register definitions
 */
struct inmux {
  volatile std::uint32_t DMA_INMUX_INMUX[2];  /*!< DMA output trigger selection to become DMA trigger */
  std::uint8_t RESERVED_0[24];                /*!< Reserved */
  volatile std::uint32_t SCT_INMUX[4];        /*!< input select register for SCT */
  std::uint8_t RESERVED_1[16];                /*!< Reserved */
  volatile std::uint32_t DMA_ITRIG_INMUX[25]; /*!< Trigger select register for DMA channel */
};
namespace DMA_INMUX_INMUX {
constexpr inline std::uint32_t RESERVED_MASK{0x0000001Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t INP(std::uint32_t output_channel) {
  return output_channel;
}
}  // namespace DMA_INMUX_INMUX
namespace SCT_INMUX {
constexpr inline std::uint32_t RESERVED_MASK{0x0000000Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t SCT_PIN0{0u << 0};          /*!< SCT input 0 via switch matrix */
constexpr inline std::uint32_t SCT_PIN1{1u << 0};          /*!< SCT input 1 via switch matrix */
constexpr inline std::uint32_t SCT_PIN2{2u << 0};          /*!< SCT input 2 via switch matrix */
constexpr inline std::uint32_t SCT_PIN3{3u << 0};          /*!< SCT input 3 via switch matrix */
constexpr inline std::uint32_t ADC_THCMP_IRQ{4u << 0};     /*!< ADC threshold compare interrupt */
constexpr inline std::uint32_t ACMP_O{5u << 0};            /*!< ACMP output */
constexpr inline std::uint32_t T0_MAT2{6u << 0};           /*!< Timer 0 match 2 */
constexpr inline std::uint32_t GPIOINT_BMATCH{7u << 0};    /*!< GPIO input B match */
constexpr inline std::uint32_t ARM_TXEV{8u << 0};          /*!< ARM TX event */
constexpr inline std::uint32_t DEBUG_HALTED{9u << 0};      /*!< Debug halted */
}  // namespace SCT_INMUX
namespace DMA_ITRIG_INMUX {
constexpr inline std::uint32_t RESERVED_MASK{0x0000000Fu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t ADC_SEQA_IRQ{0u << 0};      /*!< ADC sequence A interrupt */
constexpr inline std::uint32_t ADC_SEQB_IRQ{1u << 0};      /*!< ADC sequence B interrupt */
constexpr inline std::uint32_t SCT_DMA0_IRQ{2u << 0};      /*!< SCT DMA 0 interrupt */
constexpr inline std::uint32_t SCT_DMA1_IRQ{3u << 0};      /*!< SCT DMA 1 interrupt */
constexpr inline std::uint32_t ACMP_O{4u << 0};            /*!< ACMP output */
constexpr inline std::uint32_t PININT4{5u << 0};           /*!< GPIO interrupt 4 */
constexpr inline std::uint32_t PININT5{6u << 0};           /*!< GPIO interrupt 5 */
constexpr inline std::uint32_t PININT6{7u << 0};           /*!< GPIO interrupt 6 */
constexpr inline std::uint32_t PININT7{8u << 0};           /*!< GPIO interrupt 7 */
constexpr inline std::uint32_t T0_DMAREQ_M0{9u << 0};      /*!< Timer 0 DMA request 0 */
constexpr inline std::uint32_t T0_DMAREQ_M1{10u << 0};     /*!< Timer 0 DMA request 1 */
constexpr inline std::uint32_t DMA_INMUX_INMUX0{11u << 0}; /*!< DMA trigger mux 0 */
constexpr inline std::uint32_t DMA_INMUX_INMUX1{12u << 0}; /*!< DMA trigger mux 1 */
}  // namespace DMA_ITRIG_INMUX
}  // namespace libMcuHw::inmux
#endif