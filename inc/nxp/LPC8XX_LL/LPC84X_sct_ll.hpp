/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_sct_ll.hpp
 * @brief LPC84X series State configurable timer low level interface class
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
 * @brief Match indices
 */
enum class matcher : std::size_t {
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
 * @brief event indices
 */
enum class events : std::size_t {
  EVENT0 = 0, /*!< Event 0 */
  EVENT1 = 1, /*!< Event 1 */
  EVENT2 = 2, /*!< Event 2 */
  EVENT3 = 3, /*!< Event 3 */
  EVENT4 = 4, /*!< Event 4 */
  EVENT5 = 5, /*!< Event 5 */
  EVENT6 = 6, /*!< Event 6 */
  EVENT7 = 7, /*!< Event 7 */
};
/**
 * @brief SCT output indices
 */
enum class outputs : std::size_t {
  OUTPUT0 = 0, /*!< Output 0 */
  OUTPUT1 = 1, /*!< Output 1 */
  OUTPUT2 = 2, /*!< Output 2 */
  OUTPUT3 = 3, /*!< Output 3 */
  OUTPUT4 = 4, /*!< Output 4 */
  OUTPUT5 = 5, /*!< Output 5 */
  OUTPUT6 = 6, /*!< Output 6 */
};
namespace eventMasks {
constexpr inline std::uint32_t EVENT0{1u << 0}; /*!< Mask for event 0 */
constexpr inline std::uint32_t EVENT1{1u << 1}; /*!< Mask for event 1 */
constexpr inline std::uint32_t EVENT2{1u << 2}; /*!< Mask for event 2 */
constexpr inline std::uint32_t EVENT3{1u << 3}; /*!< Mask for event 3 */
constexpr inline std::uint32_t EVENT4{1u << 4}; /*!< Mask for event 4 */
constexpr inline std::uint32_t EVENT5{1u << 5}; /*!< Mask for event 5 */
constexpr inline std::uint32_t EVENT6{1u << 6}; /*!< Mask for event 6 */
constexpr inline std::uint32_t EVENT7{1u << 7}; /*!< Mask for event 7 */
}  // namespace eventMasks
namespace stateMasks {
constexpr inline std::uint32_t STATE0{1u << 0}; /*!< Mask for state 0 */
constexpr inline std::uint32_t STATE1{1u << 1}; /*!< Mask for state 1 */
constexpr inline std::uint32_t STATE2{1u << 2}; /*!< Mask for state 2 */
constexpr inline std::uint32_t STATE3{1u << 3}; /*!< Mask for state 3 */
constexpr inline std::uint32_t STATE4{1u << 4}; /*!< Mask for state 4 */
constexpr inline std::uint32_t STATE5{1u << 5}; /*!< Mask for state 5 */
constexpr inline std::uint32_t STATE6{1u << 6}; /*!< Mask for state 6 */
constexpr inline std::uint32_t STATE7{1u << 7}; /*!< Mask for state 7 */
}  // namespace stateMasks
/**
 * @brief I/O conditions for I/O events
 */
enum class ioEventConditions : std::size_t {
  LOW = hardware::EV_CTRL::IOCOND_LOW,   /*!< Low level I/O condition */
  RISE = hardware::EV_CTRL::IOCOND_RISE, /*!< Rising edge I/O condition */
  FALL = hardware::EV_CTRL::IOCOND_FALL, /*!< Falling edge I/O condition */
  HIGH = hardware::EV_CTRL::IOCOND_HIGH, /*!< High level I/O condition */
};
/**
 * @brief I/O and match event combinations
 */
enum class eventCombineModes : std::size_t {
  OR = hardware::EV_CTRL::COMBMODE_OR,       /*!< Match or I/O condition */
  MATCH = hardware::EV_CTRL::COMBMODE_MATCH, /*!< Match only condition */
  IO = hardware::EV_CTRL::COMBMODE_IO,       /*!< I/O only condition */
  AND = hardware::EV_CTRL::COMBMODE_AND,     /*!< Match and I/O condition */
};
/**
 * @brief Counting directions
 */
enum class eventCountingDirections : std::uint32_t {
  BIDI = hardware::EV_CTRL::DIRECTION_BIDI, /*!< event triggers in both counting directions */
  UP = hardware::EV_CTRL::DIRECTION_UP,     /*!< event triggers in up counting */
  DOWN = hardware::EV_CTRL::DIRECTION_DOWN, /*!< event triggers in down counting */
};
/**
 * @brief SCT low level interface class
 * @tparam sctAddress_ address of the SCT peripheral
 */
template <libmcu::sctBaseAddress sctAddress_>
struct sct : libmcu::PeripheralBase {
  constexpr static void init(counterMode mode, bool bidirectional = true, bool autolimit = true) {
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
   * @brief Configure what events can limit the counter
   * @param eventMask mask of events that can limit
   * @param counter counter to apply this to
   */
  constexpr static void setLimitEvents(std::uint32_t eventMask, subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->LIMIT = eventMask;
        break;
      case subCounter::LOWER:
        sctPeripheral()->LIMIT_ACCESS16BIT.LIMITL = eventMask;
        break;
      case subCounter::UPPER:
        sctPeripheral()->LIMIT_ACCESS16BIT.LIMITH = eventMask;
        break;
    }
  }
  constexpr static void setHaltEvents(std::uint32_t eventmask, subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->HALT = eventmask;
        break;
      case subCounter::LOWER:
        sctPeripheral()->HALT_ACCESS16BIT.HALTL = eventmask;
        break;
      case subCounter::UPPER:
        sctPeripheral()->HALT_ACCESS16BIT.HALTH = eventmask;
        break;
    }
  }
  constexpr static void setStopEvents(std::uint32_t eventmask, subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->STOP = eventmask;
        break;
      case subCounter::LOWER:
        sctPeripheral()->STOP_ACCESS16BIT.STOPL = eventmask;
        break;
      case subCounter::UPPER:
        sctPeripheral()->STOP_ACCESS16BIT.STOPH = eventmask;
        break;
    }
  }
  constexpr static void setStartEvents(std::uint32_t eventmask, subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->START = eventmask;
        break;
      case subCounter::LOWER:
        sctPeripheral()->START_ACCESS16BIT.STARTL = eventmask;
        break;
      case subCounter::UPPER:
        sctPeripheral()->START_ACCESS16BIT.STARTH = eventmask;
    }
  }
  constexpr static void setOutputSetEvents(outputs output, std::uint32_t eventmask) {
    std::size_t index = static_cast<std::size_t>(output);
    sctPeripheral()->OUT[index].SET = eventmask;
  }
  constexpr static void setOutputClearEvents(outputs output, std::uint32_t eventmask) {
    std::size_t index = static_cast<std::size_t>(output);
    sctPeripheral()->OUT[index].CLR = eventmask;
  }
  /**
   * @brief Start counter
   * @param counter counter to start
   */
  constexpr static void start(subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
      case subCounter::LOWER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL & ~hardware::CTRL::HALT_L;
        break;
      case subCounter::UPPER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL & ~hardware::CTRL::HALT_H;
        break;
    }
  }
  /**
   * @brief Halt counter
   * @param counter counter to halt
   */
  constexpr static void halt(subCounter counter = subCounter::UNITED) {
    switch (counter) {
      case subCounter::UNITED:
      case subCounter::LOWER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL | hardware::CTRL::HALT_L;
        break;
      case subCounter::UPPER:
        sctPeripheral()->CTRL = sctPeripheral()->CTRL | hardware::CTRL::HALT_H;
        break;
    }
  }
  /**
   * @brief Get counter value
   * @param counter counter to get value
   * @return current count
   */
  constexpr static std::uint32_t getCounter(subCounter counter = subCounter::UNITED) {
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
  constexpr static void setupMatch(matcher match, std::uint32_t value, subCounter counter = subCounter::UNITED) {
    std::uint32_t index = static_cast<std::uint32_t>(match);
    switch (counter) {
      case subCounter::UNITED:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << index);
        sctPeripheral()->MATCH[index] = value;
        sctPeripheral()->MATCHREL[index] = value;
        break;
      case subCounter::LOWER:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << index);
        sctPeripheral()->MATCH_ACCESS16BIT[index].MATCHL = static_cast<std::uint16_t>(value);
        sctPeripheral()->MATCHREL_ACCESS16BIT[index].MATCHRELL = static_cast<std::uint16_t>(value);
        break;
      case subCounter::UPPER:
        sctPeripheral()->REGMODE = sctPeripheral()->REGMODE & ~(1 << (index + 16));
        sctPeripheral()->MATCH_ACCESS16BIT[index].MATCHH = static_cast<std::uint16_t>(value);
        sctPeripheral()->MATCHREL_ACCESS16BIT[index].MATCHRELH = static_cast<std::uint16_t>(value);
        break;
    }
  }
  //! @todo simplified setupEvent for just match/compare events with no statechanges, useful for PWM setup
  /**
   * @brief Setup event register
   * @param event event to configure
   * @param stateMask state mask of states this event can occur
   * @param output if the i/o is an output
   * @param ioIndex what i/o to use
   * @param ioCondition i/o condition to use
   * @param combineMode how to combine i/o and match conditions
   * @param stateLoad if we load the state or add the state to state register
   * @param stateValue state value to load or add to state register when event occurs
   * @param matchGreater match exact or greater/less then match value
   * @param direction count direction the event can occur
   * @param counter what counter to associate this event to
   */
  constexpr static void setupEvent(events event, std::uint32_t stateMask, matcher match, bool output, std::uint32_t ioIndex,
                                   ioEventConditions ioCondition, eventCombineModes combineMode, bool stateLoad,
                                   std::uint32_t stateValue, bool matchGreater = true,
                                   eventCountingDirections direction = eventCountingDirections::BIDI,
                                   subCounter counter = subCounter::UNITED) {
    std::size_t index = static_cast<std::size_t>(event);
    std::uint32_t eventRegister = hardware::EV_CTRL::MATCHSESEL(static_cast<std::uint32_t>(match)) |
                                  hardware::EV_CTRL::IOSEL(ioIndex) | static_cast<std::uint32_t>(ioCondition) |
                                  static_cast<std::uint32_t>(combineMode) | hardware::EV_CTRL::STATEV(stateValue) |
                                  static_cast<std::uint32_t>(direction);
    switch (counter) {
      case subCounter::LOWER:
      case subCounter::UNITED:
        break;
      case subCounter::UPPER:
        eventRegister = eventRegister | hardware::EV_CTRL::HEVENT;
        break;
    }
    if (output)
      eventRegister = eventRegister | hardware::EV_CTRL::OUTSEL;
    if (stateLoad)
      eventRegister = eventRegister | hardware::EV_CTRL::STATELD;
    if (matchGreater)
      eventRegister = eventRegister | hardware::EV_CTRL::MATCHMEM;
    sctPeripheral()->EV[index].CTRL = eventRegister;
    sctPeripheral()->EV[index].STATE = stateMask;
  }

  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::sct *sctPeripheral() {
    return reinterpret_cast<hardware::sct *>(sctAddress);
  }

 private:
  static constexpr libmcu::hwAddressType sctAddress = sctAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::sct
#endif