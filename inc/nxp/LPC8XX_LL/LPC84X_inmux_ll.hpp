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

namespace libMcuLL::inmux {
namespace hardware = libMcuHw::inmux;

/**
 * @brief SCT0 input index
 */
enum class sctInputIndexes : std::size_t {
  SCT0_INMUX0 = 0, /*!< input mux for SCT input 0 */
  SCT0_INMUX1 = 1, /*!< input mux for SCT input 1 */
  SCT0_INMUX2 = 2, /*!< input mux for SCT input 2 */
  SCT0_INMUX3 = 3, /*!< input mux for SCT input 3 */
};
/**
 * @brief SCT0 input sources
 */
enum class sctInputSources : std::uint32_t {
  SCT_PIN0 = 0,       /*!< SCT input pin 0 */
  SCT_PIN1 = 1,       /*!< SCT input pin 1 */
  SCT_PIN2 = 2,       /*!< SCT input pin 2 */
  SCT_PIN3 = 3,       /*!< SCT input pin 3 */
  ADC_THCMP_IRQ = 4,  /*!< ADC Threshold comparator interrupt */
  ACMP_O = 5,         /*!< Analog comparator output */
  T0_MAT2 = 6,        /*!< Timer 0 Match 2 */
  GPIOINT_BMATCH = 7, /*!< GPIO interrupt B match */
  ARM_TXEV = 8,       /*!< ARM core TXEV event */
  DEBUG_HALTED = 9,   /*!< Debug halted? */
  NONE = 0xFF,        /*!< default */
};
/**
 * @brief Input multiplexer low level interface class
 * @tparam inmuxAddress_ address of the Input multiplexer peripheral
 */
template <libMcu::inmuxBaseAddress inmuxAddress_>
struct inmux : libMcu::PeripheralBase {
  /**
   * @brief setup multiplexer input for SCT input
   * @param sctInput SCT input to configure
   * @param source source to connect the SCT input to
   */
  constexpr static void setup(sctInputIndexes sctInput, sctInputSources source) {
    std::size_t index = static_cast<std::size_t>(sctInput);
    inmuxPeripheral()->SCT_INMUX[index] = static_cast<std::uint32_t>(source);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::inmux *inmuxPeripheral() {
    return reinterpret_cast<hardware::inmux *>(inmuxAddress);
  }

 private:
  static constexpr libMcu::hwAddressType inmuxAddress = inmuxAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::inmux
#endif