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
  TIMER_U,    /**< 32 bit unified timer */
  TIMER_L,    /**< 16 bit lower timer */
  TIMER_H,    /**< 16 bit higher timer */
  TIMER_BOTH, /**< both 16 bit timers */
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
  constexpr static hw::sct::peripheral *regs() {
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
  constexpr void init(std::uint32_t prescale, countingMode countMode) {
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
  constexpr void init(std::uint32_t prescaleL, std::uint32_t prescaleH, countingMode countModeL, countingMode countModeH) {
    regs()->CONFIG = CONFIG::AUTOLIMIT_L | CONFIG::AUTOLIMIT_H;
    regs()->CTRL = CTRL::HALT_L | CTRL::CLRCTR_L | CTRL::PRE_L(prescaleL) | CTRL::HALT_H | CTRL::CLRCTR_H | CTRL::PRE_H(prescaleH);
    if (countModeL == BIDIRECTIONAL)
      regs()->CTRL = regs()->CTRL | CTRL::BIDIR_L;
    if (countModeH == BIDIRECTIONAL)
      regs()->CTRL = regs()->CTRL | CTRL::BIDIR_H;
  }

  // TODO: init(mode, prescale, inputpin)
  // TODO: init(mode, prescaleL, prescale H, inputpint)

  /**
   * @brief Starts the requested SCT sub timer
   *
   * Starts the timer by unhalting the timer block
   *
   * @param timer timer to start
   */
  constexpr void start(sctTimer timer) {
    switch (timer) {
    TIMER_U:
    TIMER_L:
      regs()->CTRL = regs()->CTRL & ~(CTRL::HALT_L);
      break;
    TIMER_H:
      regs()->CTRL = regs()->CTRL & ~(CTRL::HALT_H);
      break;
    TIMER_BOTH:
      regs()->CTRL = regs()->CTRL & ~(CTRL::HALT_L | CTRL::HALT_H);
      break;
    }
  }

  /**
   * @brief Halts the requested SCT sub timer
   *
   * Halts the timer block by setting the timer bit
   *
   * @param timer timer to halt
   */
  constexpr void halt(sctTimer timer) {
    switch (timer) {
    TIMER_U:
    TIMER_L:
      regs()->CTRL = regs()->CTRL | (CTRL::HALT_L);
      break;
    TIMER_H:
      regs()->CTRL = regs()->CTRL | (CTRL::HALT_H);
      break;
    TIMER_BOTH:
      regs()->CTRL = regs()->CTRL | (CTRL::HALT_L | CTRL::HALT_H);
      break;
    }
  }

  /**
   * @brief returns SCT counter register
   *
   * @param timer timer to get the count register from
   * @return current count value
   */
  constexpr std::uint32_t counter(sctTimer timer) {
    switch (timer) {
    TIMER_U:
    TIMER_BOTH:  // unusual request but lets just return both 16 bit timers
      return regs()->COUNT;
    TIMER_L:
      return static_cast<std::uint32_t>(regs()->COUNT_L);
    TIMER_H:
      return static_cast<std::uint32_t>(regs()->COUNT_H);
    }
  }
  // setupPwm(timer, matchRegister, matchValue, output)
  // setup match register
  // setup value
  // setup reload value
  // setup output trigger
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace sct
}  // namespace sw
}  // namespace libMcuLL

#endif