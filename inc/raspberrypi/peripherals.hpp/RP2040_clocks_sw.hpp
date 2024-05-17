/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 clocks software interface
 */
#ifndef RP2040_CLOCKS_SW_HPP
#define RP2040_CLOCKS_SW_HPP

namespace libMcuLL::sw::clocks {
using namespace libMcuLL;
/**
 * @brief available clock generators
 */
enum class clockgenerators : std::uint32_t {
  GPOUT0 = hw::clocks::clockIndex::GPOUT0, /**< GPIO mux clock 0 */
  GPOUT1 = hw::clocks::clockIndex::GPOUT1, /**< GPIO mux clock 1 */
  GPOUT2 = hw::clocks::clockIndex::GPOUT2, /**< GPIO mux clock 2 */
  GPOUT3 = hw::clocks::clockIndex::GPOUT3, /**< GPIO mux clock 3 */
  REF = hw::clocks::clockIndex::REF,       /**< watchdog and timers reference clock */
  SYS = hw::clocks::clockIndex::SYS,       /**< processors, bus fabric, memory, memory map registers */
  PERI = hw::clocks::clockIndex::PERI,     /**< peripheral clock for UART and SPI */
  USB = hw::clocks::clockIndex::USB,       /**< USB clock */
  ADC = hw::clocks::clockIndex::ADC,       /**< ADC clock */
  RTC = hw::clocks::clockIndex::RTC,       /**< RTC clock */
};
/**
 * @brief available clock sources for gpout clock generators
 */
enum class gpoutSources : std::uint32_t {
  PLL_SYS = hw::clocks::CTRL::GPOUT_SRC_PLL_SYS,
  GPIN0 = hw::clocks::CTRL::GPOUT_SRC_GPIN0,
  GPIN1 = hw::clocks::CTRL::GPOUT_SRC_GPIN1,
  PLL_USB = hw::clocks::CTRL::GPOUT_SRC_PLL_USB,
  ROSC = hw::clocks::CTRL::GPOUT_SRC_ROSC,
  XOSC = hw::clocks::CTRL::GPOUT_SRC_XOSC,
  SYS = hw::clocks::CTRL::GPOUT_SRC_CLK_SYS,
  USB = hw::clocks::CTRL::GPOUT_SRC_CLK_USB,
  ADC = hw::clocks::CTRL::GPOUT_SRC_CLK_ADC,
  RTC = hw::clocks::CTRL::GPOUT_SRC_CLK_RTC,
  REF = hw::clocks::CTRL::GPOUT_SRC_CLK_REF,
};
template <libMcuLL::clocksBaseAddress const& clocksAddress_>
struct clocks : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief Setup gpio clock output
   * @param generator GPIO output clock source to set
   * @param source clock source to output
   * @param divisor divisor value, 0 means max division
   * @param fraction fractional value
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setupGpout(clockgenerators generator, gpoutSources source, std::uint32_t divisor, std::uint32_t fraction,
                            std::uint32_t delay) {
    std::uint32_t index = static_cast<std::uint32_t>(generator);
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor) | hw::clocks::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    clocksPeripheralClear()->CLK[index].CTRL = hw::clocks::CTRL::ENABLE;
    libMcu::delay(delay);
    // set multiplexer
    clocksPeripheral()->CLK[index].CTRL =
      (clocksPeripheral()->CLK[index].CTRL & ~hw::clocks::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    clocksPeripheralSet()->CLK[index].CTRL = hw::clocks::CTRL::ENABLE;
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief Clear clock resusitator
   */
  constexpr void clearResusitator() {
    clocksPeripheralSet()->CLK_SYS_RESUS_CTRL = hw::clocks::CLK_SYS_RESUS_CTRL::CLEAR;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheral() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralSet() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralClear() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralXor() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType clocksAddress = clocksAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::clocks
#endif