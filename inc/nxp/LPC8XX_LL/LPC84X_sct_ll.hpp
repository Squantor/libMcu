/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_sct_ll.hpp
 * @brief LPC84X series State configurable timer low level interface class
 * @todo rework needed as now it is copy of LPC81X
 */
#ifndef LPC84X_SCT_LL_HPP
#define LPC84X_SCT_LL_HPP

namespace libMcuLL::sct {
namespace hardware = libMcuHw::sct;

/**
 * @brief SCT subcounter select
 */
enum class subCounter : std::uint32_t {
  UNITED, /*!< Unified counter */
  UPPER,  /*!< Upper counter */
  LOWER,  /*!< Lower counter */
};
enum class counterMode : std::uint32_t {
  UNIFIED = hardware::CONFIG::UNIFY, /*!< 32 bit combined counter*/
  SPLIT = 0,                         /*!< split into two 16 bit counter */
};
/**
 * @brief Match registers
 */
enum class matcher : std::uint32_t {
  MATCH0 = 0, /*!< Match 0 register */
  MATCH1 = 1, /*!< Match 1 register */
  MATCH2 = 2, /*!< Match 2 register */
  MATCH3 = 3, /*!< Match 3 register */
  MATCH4 = 4, /*!< Match 4 register */
  MATCH5 = 5, /*!< Match 5 register */
  MATCH6 = 6, /*!< Match 6 register */
  MATCH7 = 7, /*!< Match 7 register */
};
/**
 * @brief SCT low level interface class
 * @tparam sctAddress_ address of the SCT peripheral
 */
template <libMcu::sctBaseAddress sctAddress_>
struct sct : libMcu::peripheralBase {
  constexpr void init(counterMode mode, bool bidirectional = true, bool autolimit = true) {
    std::uint32_t configRegister = static_cast<std::uint32_t>(mode);
    std::uint32_t ctrlRegister = hardware::CTRL::HALT_L | hardware::CTRL::HALT_H;
    sctPeripheral()->CTRL = ctrlRegister;
    sctPeripheral()->COUNT = 0;
    if (autolimit)
      configRegister |= hardware::CONFIG::AUTOLIMIT_L | hardware::CONFIG::AUTOLIMIT_H;
    if (bidirectional)
      ctrlRegister |= hardware::CTRL::BIDIR_L | hardware::CTRL::BIDIR_H;
    sctPeripheral()->CONFIG = configRegister;
    sctPeripheral()->CTRL = ctrlRegister;
  }
  /**
   * @brief Start counter
   * @param counter counter to start
   */
  constexpr void start(subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
      case subCounter::LOWER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL & ~hardware::CTRL::HALT_L;
        break;
      case subCounter::UPPER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL & ~hardware::CTRL::HALT_H;
    }
  }
  /**
   * @brief Halt counter
   * @param counter counter to halt
   */
  constexpr void halt(subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
      case subCounter::LOWER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL | hardware::CTRL::HALT_L;
        break;
      case subCounter::UPPER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL | hardware::CTRL::HALT_H;
    }
  }
  /**
   * @brief Get counter value
   * @param counter counter to get value
   * @return current count
   */
  constexpr std::uint32_t getCounter(subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
        return sctPeripheral()->COUNT;
        break;
      case subCounter::LOWER:
        return static_cast<std::uint32_t>(sctPeripheral()->COUNT_ACCESS16BIT.COUNTL);
        break;
      case subCounter::UPPER:
        return static_cast<std::uint32_t>(sctPeripheral()->COUNT_ACCESS16BIT.COUNTH);
    }
  }
  /**
   * @brief Setup match register
   * @param match matcher to setup
   * @param value value of the match register
   * @param counter counter the match register belangs to
   */
  constexpr void setupMatch(matcher match, std::uint32_t value, subCounter counter = subCounter::UNITED) {
    std::uint32_t index = static_cast<std::uint32_t>(match);
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << index);
        sctPeripheral()->MATCH[index] = value;
        sctPeripheral()->MATCHREL[index] = value;
        break;
      case subCounter::LOWER:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << index);
        sctPeripheral()->MATCH_ACCESS16BIT->MATCHL = static_cast<std::uint16_t>(value);
        sctPeripheral()->MATCHREL_ACCESS16BIT->MATCHRELL = static_cast<std::uint16_t>(value);
        break;
      case subCounter::UPPER:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << (index + 16));
        sctPeripheral()->MATCH_ACCESS16BIT->MATCHH = static_cast<std::uint16_t>(value);
        sctPeripheral()->MATCHREL_ACCESS16BIT->MATCHRELH = static_cast<std::uint16_t>(value);
        break;
    }
  }

  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::sct *sctPeripheral() {
    return reinterpret_cast<hardware::sct *>(sctAddress);
  }

 private:
  static constexpr libMcu::hwAddressType sctAddress = sctAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::sct
#endif