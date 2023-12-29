/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series State configurable timer software interface
 */
#ifndef LPC81X_SCT_SW_HPP
#define LPC81X_SCT_SW_HPP

namespace libMcuLL {
namespace sw {
namespace sct {
using namespace hw::sct;

/**
 * @brief Which SCT mode to setup
 *
 */
enum sctMode : std::uint32_t {
  UNIFIED, /**< 32 bit single timer mode */
  SPLIT,   /**< 16 bit double timer mode */
};

enum countingMode : std::uint32_t {
  UP,            /**< counter only counts up */
  BIDIRECTIONAL, /**< bidirectional counting */
};

/**
 * @brief which timer to address
 *
 */
enum sctTimer : std::uint32_t {
  TIMER_U, /**< 32 bit unified timer */
  TIMER_L, /**< 16 bit lower timer */
  TIMER_H, /**< 16 bit higher timer */
};

template <libMcuLL::SCTbaseAddress address_>
struct sct {
  /**
   * @brief Construct a new sct object
   *
   */
  sct() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to state configurable timer registers
   */
  static hw::sct::peripheral *regs() {
    return reinterpret_cast<hw::sct::peripheral *>(address);
  }

  /**
   * @brief Setup SCT to unified 32 bit timer
   *
   * Clock should be enabled before calling this method.
   * The single prescaler value selects the unified timer init.
   * Match 0 register is used as automatic limit for the clock.
   *
   * @param prescale prescale for unified timer
   */
  void init(std::uint32_t prescale, countingMode countMode) {
    regs()->CONFIG = CONFIG::UNIFY_ON | CONFIG::AUTOLIMIT_L;
    if (countMode == BIDIRECTIONAL)
      regs()->CTRL = CTRL::HALT_L | CTRL::CLRCTR_L | CTRL::PRE_L(prescale) | CTRL::BIDIR_L;
    else
      regs()->CTRL = CTRL::HALT_L | CTRL::CLRCTR_L | CTRL::PRE_L(prescale);
  }

  /**
   * @brief Setup SCT to dual 16 bit timer
   *
   * Clock should be enabled before calling this method.
   * The single prescaler value selects the unified timer init.
   * Match 0 register is used as automatic limit for the clock.
   *
   * @param prescale prescale for unified timer
   */
  void init(std::uint32_t prescaleL, std::uint32_t prescaleH, countingMode countModeL, countingMode countModeH) {
    regs()->CONFIG = CONFIG::AUTOLIMIT_L | CONFIG::AUTOLIMIT_H;
    regs()->CTRL = CTRL::CLRCTR_L | CTRL::PRE_L(prescaleL) | CTRL::CLRCTR_L | CTRL::PRE_L(prescaleH);
    if (countModeL == BIDIRECTIONAL)
      regs()->CTRL |= CTRL::BIDIR_L;
    if (countModeH == BIDIRECTIONAL)
      regs()->CTRL |= CTRL::BIDIR_H;
  }
  // init(mode, prescale, inputpin)
  // init(mode, prescaleL, prescale H, inputpint)

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace sct
}  // namespace sw
}  // namespace libMcuLL

#endif