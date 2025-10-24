/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_inmux_ll.hpp
 * @brief LPC84X series SCT input and DMA input multiplexer low level interface class
 */
#ifndef LPC84X_INMUX_LL_HPP
#define LPC84X_INMUX_LL_HPP

namespace libmcull::inmux {
namespace hardware = libmcuhw::inmux;

/**
 * @brief SCT0 input index
 */
enum class SctInputIndexes : std::size_t {
  Sct0Inmux0 = 0, /*!< input mux for SCT input 0 */
  Sct0Inmux1 = 1, /*!< input mux for SCT input 1 */
  Sct0Inmux2 = 2, /*!< input mux for SCT input 2 */
  Sct0Inmux3 = 3, /*!< input mux for SCT input 3 */
};
/**
 * @brief SCT0 input sources
 */
enum class SctInputSources : std::uint32_t {
  SctPin0 = hardware::SCT_INMUX::SCT_PIN0,             /*!< SCT input pin 0 */
  SctPin1 = hardware::SCT_INMUX::SCT_PIN1,             /*!< SCT input pin 1 */
  SctPin2 = hardware::SCT_INMUX::SCT_PIN2,             /*!< SCT input pin 2 */
  SctPin3 = hardware::SCT_INMUX::SCT_PIN3,             /*!< SCT input pin 3 */
  AdcThcmpIrq = hardware::SCT_INMUX::ADC_THCMP_IRQ,    /*!< ADC Threshold comparator interrupt */
  AcmpOut = hardware::SCT_INMUX::ACMP_O,               /*!< Analog comparator output */
  Timer0Match2 = hardware::SCT_INMUX::T0_MAT2,         /*!< Timer 0 Match 2 */
  GpioIntBMatch = hardware::SCT_INMUX::GPIOINT_BMATCH, /*!< GPIO interrupt B match */
  ArmTxEvent = hardware::SCT_INMUX::ARM_TXEV,          /*!< ARM core TXEV event */
  DebugHalted = hardware::SCT_INMUX::DEBUG_HALTED,     /*!< Debug halted? */
  None = 0xFF,                                         /*!< default */
};
/**
 * @brief DMA input multiplexer peripheral triggers
 */
enum class DmaPeriInputTriggers : std::uint32_t {
  AdcSeqAIrq = hardware::DMA_ITRIG_INMUX::ADC_SEQA_IRQ,         /*!< ADC sequence A interrupt */
  AdcSeqBIrq = hardware::DMA_ITRIG_INMUX::ADC_SEQB_IRQ,         /*!< ADC sequence B interrupt */
  SctDma0 = hardware::DMA_ITRIG_INMUX::SCT_DMA0_IRQ,            /*!< SCT DMA 0 interrupt */
  SctDma1 = hardware::DMA_ITRIG_INMUX::SCT_DMA1_IRQ,            /*!< SCT DMA 1 interrupt */
  AcmpO = hardware::DMA_ITRIG_INMUX::ACMP_O,                    /*!< ACMP output */
  PinInt4 = hardware::DMA_ITRIG_INMUX::PININT4,                 /*!< GPIO interrupt 4 */
  PinInt5 = hardware::DMA_ITRIG_INMUX::PININT5,                 /*!< GPIO interrupt 5 */
  PinInt6 = hardware::DMA_ITRIG_INMUX::PININT6,                 /*!< GPIO interrupt 6 */
  PinInt7 = hardware::DMA_ITRIG_INMUX::PININT7,                 /*!< GPIO interrupt 7 */
  Timer0DmaReqM0 = hardware::DMA_ITRIG_INMUX::T0_DMAREQ_M0,     /*!< Timer 0 DMA request 0 */
  Timer0DmaReqM1 = hardware::DMA_ITRIG_INMUX::T0_DMAREQ_M1,     /*!< Timer 0 DMA request 1 */
  DmaInmuxInmux0 = hardware::DMA_ITRIG_INMUX::DMA_INMUX_INMUX0, /*!< DMA trigger mux 0 */
  DmaInmuxInmux1 = hardware::DMA_ITRIG_INMUX::DMA_INMUX_INMUX1, /*!< DMA trigger mux 1 */
  None = 0xFF,                                                  /*!< default */
};

/**
 * @brief Input multiplexer low level interface class
 * @tparam inmuxAddress_ address of the Input multiplexer peripheral
 */
template <libmcu::InmuxBaseAddress in_mux_address>
struct InMux : libmcull::LowLevelBase {
  /**
   * @brief setup multiplexer input for SCT input
   * @param sctInput SCT input to configure
   * @param source source to connect the SCT input to
   */
  constexpr static void Setup(SctInputIndexes sctInput, SctInputSources source) {
    std::size_t index = static_cast<std::size_t>(sctInput);
    GetPeripheral()->SCT_INMUX[index] = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief Configure DMA input trigger
   * @param dma_channel DMA input channel to configure
   * @param trigger DMA hardware trigger channel
   */
  constexpr static void Setup(std::size_t dma_channel, DmaPeriInputTriggers trigger) {
    GetPeripheral()->DMA_ITRIG_INMUX[dma_channel] = static_cast<std::uint32_t>(trigger);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::InMux *GetPeripheral() {
    return reinterpret_cast<hardware::InMux *>(in_mux_address_);
  }

 private:
  static constexpr libmcu::HwAddressType in_mux_address_ = in_mux_address; /*!< peripheral address */
};
}  // namespace libmcull::inmux
#endif