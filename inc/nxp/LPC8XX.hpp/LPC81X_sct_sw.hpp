/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series State configurable timer software interface
 *
 * TODO: This class has a mix of unified and split timer functionality, split into two different classes. Lets now focus on unified
 * only and clean up all unified/split logic. keep this a 32 bit unified timer class only
 *
 */
#ifndef LPC81X_SCT_SW_HPP
#define LPC81X_SCT_SW_HPP

namespace libMcuLL {
namespace sw {
namespace sct {
using namespace hw::sct;

enum countingMode : std::uint32_t {
  UP,            /**< counter only counts up */
  BIDIRECTIONAL, /**< bidirectional counting */
};

/**
 * @brief match register to use
 *
 * Used as an index for match registers
 *
 */
enum matchNumber : std::uint32_t {
  MATCH_0 = 0, /**< match 0 */
  MATCH_1 = 1, /**< match 1 */
  MATCH_2 = 2, /**< match 2 */
  MATCH_3 = 3, /**< match 3 */
  MATCH_4 = 4, /**< match 4 */
};

/**
 * @brief capture register to use
 *
 * Used as an index for capture registers
 *
 */
enum captureNumber : std::uint32_t {
  CAPTURE_0 = 0, /**< match 0 */
  CAPTURE_1 = 1, /**< match 1 */
  CAPTURE_2 = 2, /**< match 2 */
  CAPTURE_3 = 3, /**< match 3 */
  CAPTURE_4 = 4, /**< match 4 */
};

/**
 * @brief Event register to use
 *
 * Used as an index for event registers
 *
 */
enum eventNumber : std::uint32_t {
  EVENT_0 = 0, /**< event 0 */
  EVENT_1 = 1, /**< event 1 */
  EVENT_2 = 2, /**< event 2 */
  EVENT_3 = 3, /**< event 3 */
  EVENT_4 = 4, /**< event 4 */
  EVENT_5 = 5, /**< event 5 */
};

/**
 * @brief Output register to use
 *
 * Used as an index for output registers
 *
 */
enum outputNumber : std::uint32_t {
  OUTPUT_0 = 0, /**< output 0 */
  OUTPUT_1 = 1, /**< output 1 */
  OUTPUT_2 = 2, /**< output 2 */
  OUTPUT_3 = 3, /**< output 3 */
};

/**
 * @brief Input register to use
 *
 * Used as an index for input registers
 *
 */
enum inputNumber : std::uint32_t {
  INPUT_0 = 0, /**< input 0 */
  INPUT_1 = 1, /**< input 0 */
  INPUT_2 = 2, /**< input 0 */
  INPUT_3 = 3, /**< input 0 */
};

/**
 * @brief conditions that can be captured
 *
 */
enum captureCondition : std::uint32_t {
  CAPTURE_LOW = EV_CTRL::IOCOND_LOW,   /**< Capture low levels */
  CAPTURE_RISE = EV_CTRL::IOCOND_RISE, /**< Capture rising edges */
  CAPTURE_FALL = EV_CTRL::IOCOND_FALL, /**< Capture falling edges */
  CAPTURE_HIGH = EV_CTRL::IOCOND_HIGH, /**< Capture high levels */
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
    // TODO configure match 0 register as match register as we autolimit on match 0
    regs()->COUNT = 0x00000000u;
    if (countMode == BIDIRECTIONAL)
      regs()->CTRL = CTRL::HALT_L | CTRL::CLRCTR_L | CTRL::PRE_L(prescale) | CTRL::BIDIR_L;
    else
      regs()->CTRL = CTRL::HALT_L | CTRL::CLRCTR_L | CTRL::PRE_L(prescale);
  }

  // TODO: init(mode, prescale, inputpin)
  // TODO: init(mode, prescaleL, prescale H, inputpint)

  /**
   * @brief Starts the 32bit SCT
   *
   */
  constexpr void start() {
    regs()->CTRL = regs()->CTRL & ~(CTRL::HALT_L);
  }

  /**
   * @brief Halts the 32bit SCT
   *
   */
  constexpr void halt() {
    regs()->CTRL = regs()->CTRL | (CTRL::HALT_L);
  }

  /**
   * @brief returns SCT count value
   *
   * @return current count value
   */
  constexpr std::uint32_t counter() {
    return regs()->COUNT;
  }

  /**
   * @brief set SCT match register and match reload register
   *
   * Call this function only when the SCT, writing to MATCH during running is disallowed
   *
   * @param match match register to set
   * @param value value to put in match register
   */
  void setMatch(matchNumber match, std::uint32_t value) {
    size_t matchIndex = static_cast<std::size_t>(match);
    regs()->MATCH[matchIndex].U = value;
    regs()->MATCHREL[matchIndex].U = value;
  }

  /**
   * @brief Set SCT match reload register
   *
   * match reload is loaded into match when a match occurs
   *
   * @param match match reload register to set
   * @param value value to put in match reload register
   */
  void setReload(matchNumber match, std::uint32_t value) {
    size_t matchIndex = static_cast<std::size_t>(match);
    regs()->MATCHREL[matchIndex].U = value;
  }

  /**
   * @brief get SCT capture register value
   *
   * @param capture capture register to get
   * @return value of the requested capture register
   */
  uint32_t getCapture(captureNumber capture) {
    size_t captureIndex = static_cast<std::size_t>(capture);
    return regs()->CAP[captureIndex].U;
  }

  /**
   * @brief return state of the SCT output
   *
   * @param output which output to read
   * @return current output state
   */
  bool output(outputNumber output) {
    uint32_t outputRegister = regs()->OUTPUT & (1 << output);
    if (outputRegister == 0)
      return false;
    else
      return true;
  }

  /**
   * @brief Setup a SCT PWM channel
   *
   * The PWM signal generated is perspective correct PWM, it is centered around the match 0 register value.
   *
   * @param match match register to use, 0 is reserved as the end condition register
   * @param value match value to use, basically the PWM value
   * @param event which event is used for generating the PWM
   * @param output which output is used for generating the PWM
   * @param outputHigh is the initial state of the output high
   */
  void setupPwm(matchNumber match, std::uint32_t value, eventNumber event, outputNumber output, bool outputHigh) {
    size_t matchIndex = static_cast<std::size_t>(match);
    size_t eventIndex = static_cast<std::size_t>(event);
    size_t outputIndex = static_cast<std::size_t>(output);
    regs()->REGMODE = REGMODE::REGMOD_MAT(regs()->REGMODE, matchIndex);
    regs()->MATCH[matchIndex].U = value;
    regs()->MATCHREL[matchIndex].U = value;
    regs()->EV[eventIndex].CTRL =
      EV_CTRL::MATCHSEL(matchIndex) | EV_CTRL::OUTSEL | EV_CTRL::IOSEL(outputIndex) | EV_CTRL::COMBMODE_MATCH;
    regs()->EV[eventIndex].STATE = EV_STATE::STATEMASK0 | EV_STATE::STATEMASK1;
    regs()->OUTPUT = OUTPUT::OUT(regs()->OUTPUT, outputIndex, outputHigh);
    regs()->OUT[outputIndex].CLR = OUT_CLR::CLR(eventIndex);
    regs()->OUT[outputIndex].SET = OUT_SET::SET(eventIndex);
    regs()->RES = RES::RES(regs()->RES, outputIndex, RES::TOGGLE);
  }

  /**
   * @brief Setup a SCT capture channel
   *
   * @param match match register to use, 0 is reserved as the end condition register
   * @param event which event is used for generating the capture
   * @param input which input is captured
   * @param condition which condition to capture
   */
  void setupCapture(captureNumber capture, eventNumber event, inputNumber input, captureCondition condition) {
    size_t captureIndex = static_cast<std::size_t>(capture);
    size_t eventIndex = static_cast<std::size_t>(event);
    size_t inputIndex = static_cast<std::size_t>(input);
    regs()->CONFIG = regs()->CONFIG | CONFIG::INSYNC_INPUT(inputIndex);  // needs to be done for edge capture condition
    regs()->REGMODE = REGMODE::REGMOD_CAP(regs()->REGMODE, captureIndex);
    regs()->CAPCTRL[captureIndex].U = CAPCTRL::CAPCON_L_SET(regs()->CAPCTRL[captureIndex].U, eventIndex);
    regs()->EV[eventIndex].CTRL = EV_CTRL::MATCHSEL(captureIndex) | EV_CTRL::INSEL | EV_CTRL::IOSEL(inputIndex) |
                                  static_cast<std::uint32_t>(condition) | EV_CTRL::COMBMODE_IO;
    regs()->EV[eventIndex].STATE = EV_STATE::STATEMASK0 | EV_STATE::STATEMASK1;
  }

  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
};
}  // namespace sct
}  // namespace sw
}  // namespace libMcuLL

#endif