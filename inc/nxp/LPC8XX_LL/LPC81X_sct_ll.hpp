/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_sct_sw.hpp
 * @brief LPC810 series State configurable timer interface class and definitions
 * @todo add unified/split timer support
 */
#ifndef LPC81X_SCT_LL_HPP
#define LPC81X_SCT_LL_HPP

namespace libmcull::sct {
namespace hardware = libmcuhw::sct;
/**
 * @brief Counting modes
 */
enum class CountingModes : std::uint32_t {
  Up,            /*!< counter only counts up */
  Bidirectional, /*!< bidirectional counting */
};
/**
 * @brief match register to use
 * Used as an index for match registers
 */
enum class Matches : std::uint32_t {
  Idx0 = 0, /*!< match 0 */
  Idx1 = 1, /*!< match 1 */
  Idx2 = 2, /*!< match 2 */
  Idx3 = 3, /*!< match 3 */
  Idx4 = 4, /*!< match 4 */
};
/**
 * @brief capture register to use
 * Used as an index for capture registers
 */
enum class Captures : std::uint32_t {
  Idx0 = 0, /*!< match 0 */
  Idx1 = 1, /*!< match 1 */
  Idx2 = 2, /*!< match 2 */
  Idx3 = 3, /*!< match 3 */
  Idx4 = 4, /*!< match 4 */
};
/**
 * @brief Event register to use
 * Used as an index for event registers
 */
enum class Events : std::uint32_t {
  Idx0 = 0, /*!< event 0 */
  Idx1 = 1, /*!< event 1 */
  Idx2 = 2, /*!< event 2 */
  Idx3 = 3, /*!< event 3 */
  Idx4 = 4, /*!< event 4 */
  Idx5 = 5, /*!< event 5 */
};
/**
 * @brief Output register to use
 * Used as an index for output registers
 */
enum class Outputs : std::uint32_t {
  Idx0 = 0, /*!< output 0 */
  Idx1 = 1, /*!< output 1 */
  Idx2 = 2, /*!< output 2 */
  Idx3 = 3, /*!< output 3 */
};
/**
 * @brief Input register to use
 * Used as an index for input registers
 */
enum class Inputs : std::uint32_t {
  Idx0 = 0, /*!< input 0 */
  Idx1 = 1, /*!< input 0 */
  Idx2 = 2, /*!< input 0 */
  Idx3 = 3, /*!< input 0 */
};
/**
 * @brief conditions that can be captured
 */
enum class CaptureConditions : std::uint32_t {
  Low = hardware::EV_CTRL::IOCOND_LOW,      /*!< Capture low levels */
  Rising = hardware::EV_CTRL::IOCOND_RISE,  /*!< Capture rising edges */
  Falling = hardware::EV_CTRL::IOCOND_FALL, /*!< Capture falling edges */
  High = hardware::EV_CTRL::IOCOND_HIGH,    /*!< Capture high levels */
};
/**
 * @brief State configurable timer low level interface
 * @tparam sct_address address of the SCT peripheral
 */
template <libmcu::SctBaseAddress sct_address>
struct Sct : libmcull::LowLevelBase {
  /**
   * @brief Setup SCT to unified 32 bit timer
   * Clock should be enabled before calling this method.
   * The single prescaler value selects the unified timer init.
   * Match 0 register is used as automatic limit for the clock.
   * @param prescale prescale for unified timer
   */
  constexpr void Init(std::uint32_t prescale, CountingModes counting_mode) {
    sctPeripheral()->CONFIG = hardware::CONFIG::UNIFY_ON | hardware::CONFIG::AUTOLIMIT_L;
    // TODO configure match 0 register as match register as we autolimit on match 0
    sctPeripheral()->COUNT = 0x00000000u;
    if (counting_mode == CountingModes::Bidirectional)
      sctPeripheral()->CTRL =
        hardware::CTRL::HALT_L | hardware::CTRL::CLRCTR_L | hardware::CTRL::PRE_L(prescale) | hardware::CTRL::BIDIR_L;
    else
      sctPeripheral()->CTRL = hardware::CTRL::HALT_L | hardware::CTRL::CLRCTR_L | hardware::CTRL::PRE_L(prescale);
  }
  // TODO: init(mode, prescale, inputpin)
  // TODO: init(mode, prescaleL, prescale H, inputpint)
  /**
   * @brief Starts the 32bit SCT
   */
  constexpr void Start() {
    sctPeripheral()->CTRL = sctPeripheral()->CTRL & ~(hardware::CTRL::HALT_L);
  }
  /**
   * @brief Halts the 32bit SCT
   */
  constexpr void Halt() {
    sctPeripheral()->CTRL = sctPeripheral()->CTRL | (hardware::CTRL::HALT_L);
  }
  /**
   * @brief returns SCT count value
   * @return current count value
   */
  constexpr std::uint32_t GetCount() {
    return sctPeripheral()->COUNT;
  }
  /**
   * @brief set SCT match register and match reload register
   * Call this function only when the SCT is stopped, writing to MATCH during running is disallowed
   * @param match match register to set
   * @param value value to put in match register
   */
  constexpr void SetMatch(Matches match, std::uint32_t value) {
    std::size_t match_index = static_cast<std::size_t>(match);
    sctPeripheral()->MATCH[match_index].U = value;
    sctPeripheral()->MATCHREL[match_index].U = value;
  }
  /**
   * @brief Set SCT match reload register
   * match reload is loaded into match when a match occurs
   * @param match match reload register to set
   * @param value value to put in match reload register
   */
  constexpr void SetReload(Matches match, std::uint32_t value) {
    std::size_t match_index = static_cast<std::size_t>(match);
    sctPeripheral()->MATCHREL[match_index].U = value;
  }
  /**
   * @brief get SCT capture register value
   *
   * @param capture capture register to get
   * @return value of the requested capture register
   */
  constexpr std::uint32_t GetCapture(Captures capture) {
    std::size_t capture_index = static_cast<std::size_t>(capture);
    return sctPeripheral()->CAP[capture_index].U;
  }
  /**
   * @brief return state of the SCT output
   * @param output which output to read
   * @return current output state
   */
  constexpr bool GetOutputState(Outputs output) {
    std::uint32_t outputRegister = sctPeripheral()->OUTPUT & (1 << static_cast<std::uint32_t>(output));
    if (outputRegister == 0u)
      return false;
    else
      return true;
  }
  /**
   * @brief Setup a SCT PWM channel
   * The PWM signal generated is perspective correct PWM, it is centered around the match 0 register value.
   * @param match match register to use, 0 is reserved as the end condition register
   * @param value match value to use, basically the PWM value
   * @param event which event is used for generating the PWM
   * @param output which output is used for generating the PWM
   * @param output_high is the initial state of the output high
   */
  constexpr void SetupPwm(Matches match, std::uint32_t value, Events event, Outputs output, bool output_high) {
    size_t match_index = static_cast<std::size_t>(match);
    size_t event_index = static_cast<std::size_t>(event);
    size_t output_index = static_cast<std::size_t>(output);
    sctPeripheral()->REGMODE = hardware::REGMODE::REGMOD_MAT(sctPeripheral()->REGMODE, match_index);
    sctPeripheral()->MATCH[match_index].U = value;
    sctPeripheral()->MATCHREL[match_index].U = value;
    sctPeripheral()->EV[event_index].CTRL = hardware::EV_CTRL::MATCHSEL(match_index) | hardware::EV_CTRL::OUTSEL |
                                            hardware::EV_CTRL::IOSEL(output_index) | hardware::EV_CTRL::COMBMODE_MATCH;
    sctPeripheral()->EV[event_index].STATE = hardware::EV_STATE::STATEMASK0 | hardware::EV_STATE::STATEMASK1;
    sctPeripheral()->OUTPUT = hardware::OUTPUT::OUT(sctPeripheral()->OUTPUT, output_index, output_high);
    sctPeripheral()->OUT[output_index].CLR = hardware::OUT_CLR::CLR(event_index);
    sctPeripheral()->OUT[output_index].SET = hardware::OUT_SET::SET(event_index);
    sctPeripheral()->RES = hardware::RES::RES(sctPeripheral()->RES, output_index, hardware::RES::TOGGLE);
  }
  /**
   * @brief Setup a SCT capture channel
   * @param match match register to use, 0 is reserved as the end condition register
   * @param event which event is used for generating the capture
   * @param input which input is captured
   * @param condition which condition to capture
   */
  constexpr void setupCapture(Captures capture, Events event, Inputs input, CaptureConditions condition) {
    size_t captureIndex = static_cast<std::size_t>(capture);
    size_t eventIndex = static_cast<std::size_t>(event);
    size_t inputIndex = static_cast<std::size_t>(input);
    sctPeripheral()->MATCH[captureIndex].U = 0u;  // clear capture register via the aliased match register
    sctPeripheral()->CONFIG =
      sctPeripheral()->CONFIG | hardware::CONFIG::INSYNC_INPUT(inputIndex);  // needs to be done for edge capture condition
    sctPeripheral()->REGMODE = hardware::REGMODE::REGMOD_CAP(sctPeripheral()->REGMODE, captureIndex);
    sctPeripheral()->CAPCTRL[captureIndex].U =
      hardware::CAPCTRL::CAPCON_L_SET(sctPeripheral()->CAPCTRL[captureIndex].U, eventIndex);
    sctPeripheral()->EV[eventIndex].CTRL = hardware::EV_CTRL::MATCHSEL(captureIndex) | hardware::EV_CTRL::INSEL |
                                           hardware::EV_CTRL::IOSEL(inputIndex) | static_cast<std::uint32_t>(condition) |
                                           hardware::EV_CTRL::COMBMODE_IO;
    sctPeripheral()->EV[eventIndex].STATE = hardware::EV_STATE::STATEMASK0 | hardware::EV_STATE::STATEMASK1;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to state configurable timer registers
   */
  constexpr static libmcuhw::sct::Sct *sctPeripheral() {
    return reinterpret_cast<libmcuhw::sct::Sct *>(sctAddress);
  }

 private:
  static constexpr libmcu::HwAddressType sctAddress = sct_address; /*!< peripheral address */
};
}  // namespace libmcull::sct
#endif