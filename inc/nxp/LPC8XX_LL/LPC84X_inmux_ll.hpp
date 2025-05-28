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
enum class sctInputIndexes : std::size_t {
  kSct0Inmux0 = 0, /*!< input mux for SCT input 0 */
  kSct0Inmux1 = 1, /*!< input mux for SCT input 1 */
  kSct0Inmux2 = 2, /*!< input mux for SCT input 2 */
  kSct0Inmux3 = 3, /*!< input mux for SCT input 3 */
};
/**
 * @brief SCT0 input sources
 */
enum class sctInputSources : std::uint32_t {
  kSctPin0 = hardware::SCT_INMUX::kSCT_PIN0,             /*!< SCT input pin 0 */
  kSctPin1 = hardware::SCT_INMUX::kSCT_PIN1,             /*!< SCT input pin 1 */
  kSctPin2 = hardware::SCT_INMUX::kSCT_PIN2,             /*!< SCT input pin 2 */
  kSctPin3 = hardware::SCT_INMUX::kSCT_PIN3,             /*!< SCT input pin 3 */
  kAdcThcmpIrq = hardware::SCT_INMUX::kADC_THCMP_IRQ,    /*!< ADC Threshold comparator interrupt */
  kAcmpOut = hardware::SCT_INMUX::kACMP_O,               /*!< Analog comparator output */
  kTimer0Match2 = hardware::SCT_INMUX::kT0_MAT2,         /*!< Timer 0 Match 2 */
  kGpioIntBMatch = hardware::SCT_INMUX::kGPIOINT_BMATCH, /*!< GPIO interrupt B match */
  kArmTxEvent = hardware::SCT_INMUX::kARM_TXEV,          /*!< ARM core TXEV event */
  kDebugHalted = hardware::SCT_INMUX::kDEBUG_HALTED,     /*!< Debug halted? */
  kNone = 0xFF,                                          /*!< default */
};
/**
 * @brief DMA input multiplexer peripheral triggers
 */
enum class dmaPeriInputTriggers : std::uint32_t {
  kAdcSeqAIrq = hardware::DMA_ITRIG_INMUX::kADC_SEQA_IRQ,         /*!< ADC sequence A interrupt */
  kAdcSeqBIrq = hardware::DMA_ITRIG_INMUX::kADC_SEQB_IRQ,         /*!< ADC sequence B interrupt */
  kSctDma0 = hardware::DMA_ITRIG_INMUX::kSCT_DMA0_IRQ,            /*!< SCT DMA 0 interrupt */
  kSctDma1 = hardware::DMA_ITRIG_INMUX::kSCT_DMA1_IRQ,            /*!< SCT DMA 1 interrupt */
  KAcmpO = hardware::DMA_ITRIG_INMUX::kACMP_O,                    /*!< ACMP output */
  kPinInt4 = hardware::DMA_ITRIG_INMUX::kPININT4,                 /*!< GPIO interrupt 4 */
  kPinInt5 = hardware::DMA_ITRIG_INMUX::kPININT5,                 /*!< GPIO interrupt 5 */
  kPinInt6 = hardware::DMA_ITRIG_INMUX::kPININT6,                 /*!< GPIO interrupt 6 */
  kPinInt7 = hardware::DMA_ITRIG_INMUX::kPININT7,                 /*!< GPIO interrupt 7 */
  kTimer0DmaReqM0 = hardware::DMA_ITRIG_INMUX::kT0_DMAREQ_M0,     /*!< Timer 0 DMA request 0 */
  kTimer0DmaReqM1 = hardware::DMA_ITRIG_INMUX::kT0_DMAREQ_M1,     /*!< Timer 0 DMA request 1 */
  kDmaInmuxInmux0 = hardware::DMA_ITRIG_INMUX::kDMA_INMUX_INMUX0, /*!< DMA trigger mux 0 */
  kDmaInmuxInmux1 = hardware::DMA_ITRIG_INMUX::kDMA_INMUX_INMUX1, /*!< DMA trigger mux 1 */
  kNone = 0xFF,                                                   /*!< default */
};

/**
 * @brief Input multiplexer low level interface class
 * @tparam inmuxAddress_ address of the Input multiplexer peripheral
 */
template <libmcu::inmuxBaseAddress in_mux_address>
struct InMux : libmcu::PeripheralBase {
  /**
   * @brief setup multiplexer input for SCT input
   * @param sctInput SCT input to configure
   * @param source source to connect the SCT input to
   */
  constexpr static void Setup(sctInputIndexes sctInput, sctInputSources source) {
    std::size_t index = static_cast<std::size_t>(sctInput);
    InmuxPeripheral()->SCT_INMUX[index] = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief Configure DMA input trigger
   * @param dma_channel DMA input channel to configure
   * @param trigger DMA hardware trigger channel
   */
  constexpr static void Setup(std::size_t dma_channel, dmaPeriInputTriggers trigger) {
    InmuxPeripheral()->DMA_ITRIG_INMUX[dma_channel] = static_cast<std::uint32_t>(trigger);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::InMux *InmuxPeripheral() {
    return reinterpret_cast<hardware::InMux *>(in_mux_address_);
  }

 private:
  static constexpr libmcu::HwAddressType in_mux_address_ = in_mux_address; /*!< peripheral address */
};
}  // namespace libmcull::inmux
#endif