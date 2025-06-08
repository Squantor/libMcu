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

namespace libmcull::sct {
namespace hardware = libmcuhw::sct;

/**
 * @brief SCT subcounter select
 */
enum class SubCounters : std::uint32_t {
  UNITED, /*!< Unified counter */
  UPPER,  /*!< Upper counter */
  LOWER,  /*!< Lower counter */
};
enum class CounterModes : std::uint32_t {
  UNIFIED = hardware::CONFIG::kUNIFY, /*!< 32 bit combined counter*/
  SPLIT = 0,                          /*!< split into two 16 bit counter */
};
/**
 * @brief Match indices
 */
enum class Matchers : std::size_t {
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
enum class Events : std::size_t {
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
enum class Outputs : std::size_t {
  OUTPUT0 = 0, /*!< Output 0 */
  OUTPUT1 = 1, /*!< Output 1 */
  OUTPUT2 = 2, /*!< Output 2 */
  OUTPUT3 = 3, /*!< Output 3 */
  OUTPUT4 = 4, /*!< Output 4 */
  OUTPUT5 = 5, /*!< Output 5 */
  OUTPUT6 = 6, /*!< Output 6 */
};
namespace event_masks {
constexpr inline std::uint32_t EVENT0{1u << 0}; /*!< Mask for event 0 */
constexpr inline std::uint32_t EVENT1{1u << 1}; /*!< Mask for event 1 */
constexpr inline std::uint32_t EVENT2{1u << 2}; /*!< Mask for event 2 */
constexpr inline std::uint32_t EVENT3{1u << 3}; /*!< Mask for event 3 */
constexpr inline std::uint32_t EVENT4{1u << 4}; /*!< Mask for event 4 */
constexpr inline std::uint32_t EVENT5{1u << 5}; /*!< Mask for event 5 */
constexpr inline std::uint32_t EVENT6{1u << 6}; /*!< Mask for event 6 */
constexpr inline std::uint32_t EVENT7{1u << 7}; /*!< Mask for event 7 */
}  // namespace event_masks
namespace state_masks {
constexpr inline std::uint32_t STATE0{1u << 0}; /*!< Mask for state 0 */
constexpr inline std::uint32_t STATE1{1u << 1}; /*!< Mask for state 1 */
constexpr inline std::uint32_t STATE2{1u << 2}; /*!< Mask for state 2 */
constexpr inline std::uint32_t STATE3{1u << 3}; /*!< Mask for state 3 */
constexpr inline std::uint32_t STATE4{1u << 4}; /*!< Mask for state 4 */
constexpr inline std::uint32_t STATE5{1u << 5}; /*!< Mask for state 5 */
constexpr inline std::uint32_t STATE6{1u << 6}; /*!< Mask for state 6 */
constexpr inline std::uint32_t STATE7{1u << 7}; /*!< Mask for state 7 */
}  // namespace state_masks
/**
 * @brief I/O conditions for I/O events
 */
enum class IoEventConditions : std::size_t {
  LOW = hardware::EV_CTRL::kIOCOND_LOW,   /*!< Low level I/O condition */
  RISE = hardware::EV_CTRL::kIOCOND_RISE, /*!< Rising edge I/O condition */
  FALL = hardware::EV_CTRL::kIOCOND_FALL, /*!< Falling edge I/O condition */
  HIGH = hardware::EV_CTRL::kIOCOND_HIGH, /*!< High level I/O condition */
};
/**
 * @brief I/O and match event combinations
 */
enum class EventCombineModes : std::size_t {
  OR = hardware::EV_CTRL::kCOMBMODE_OR,       /*!< Match or I/O condition */
  MATCH = hardware::EV_CTRL::kCOMBMODE_MATCH, /*!< Match only condition */
  IO = hardware::EV_CTRL::kCOMBMODE_IO,       /*!< I/O only condition */
  AND = hardware::EV_CTRL::kCOMBMODE_AND,     /*!< Match and I/O condition */
};
/**
 * @brief Counting directions
 */
enum class EventCountingDirections : std::uint32_t {
  BIDI = hardware::EV_CTRL::kDIRECTION_BIDI, /*!< event triggers in both counting directions */
  UP = hardware::EV_CTRL::kDIRECTION_UP,     /*!< event triggers in up counting */
  DOWN = hardware::EV_CTRL::kDIRECTION_DOWN, /*!< event triggers in down counting */
};
/**
 * @brief SCT low level interface class
 * @tparam sct_address address of the SCT peripheral
 * @todo some doxygen needs to be filled in
 */
template <libmcu::SctBaseAddress sct_address>
struct Sct : libmcull::PeripheralBase {
  constexpr static void Init(CounterModes mode, bool bidirectional = true, bool autolimit = true) {
    std::uint32_t configRegister = static_cast<std::uint32_t>(mode);
    std::uint32_t ctrlRegister = hardware::CTRL::kHALT_L | hardware::CTRL::kHALT_H;
    GetPeripheral()->CTRL = ctrlRegister;
    GetPeripheral()->COUNT = 0;
    if (autolimit)
      configRegister |= hardware::CONFIG::kAUTOLIMIT_L | hardware::CONFIG::kAUTOLIMIT_H;
    if (bidirectional)
      ctrlRegister |= hardware::CTRL::kBIDIR_L | hardware::CTRL::kBIDIR_H;
    GetPeripheral()->CONFIG = configRegister;
    GetPeripheral()->CTRL = ctrlRegister;
  }
  /**
   * @brief Configure what events can limit the counter
   * @param eventMask mask of events that can limit
   * @param counter counter to apply this to
   */
  constexpr static void SetLimitEvents(std::uint32_t eventMask, SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
        GetPeripheral()->LIMIT = eventMask;
        break;
      case SubCounters::LOWER:
        GetPeripheral()->LIMIT_ACCESS16BIT.LIMITL = eventMask;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->LIMIT_ACCESS16BIT.LIMITH = eventMask;
        break;
    }
  }
  /**
   * @brief Set the Halt Events object
   * @param eventmask
   * @param counter
   */
  constexpr static void SetHaltEvents(std::uint32_t eventmask, SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
        GetPeripheral()->HALT = eventmask;
        break;
      case SubCounters::LOWER:
        GetPeripheral()->HALT_ACCESS16BIT.HALTL = eventmask;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->HALT_ACCESS16BIT.HALTH = eventmask;
        break;
    }
  }
  /**
   * @brief Set the Stop Events object
   * @param eventmask
   * @param counter
   */
  constexpr static void SetStopEvents(std::uint32_t eventmask, SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
        GetPeripheral()->STOP = eventmask;
        break;
      case SubCounters::LOWER:
        GetPeripheral()->STOP_ACCESS16BIT.STOPL = eventmask;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->STOP_ACCESS16BIT.STOPH = eventmask;
        break;
    }
  }
  /**
   * @brief Set the Start Events object
   * @param eventmask
   * @param counter
   */
  constexpr static void SetStartEvents(std::uint32_t eventmask, SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
        GetPeripheral()->START = eventmask;
        break;
      case SubCounters::LOWER:
        GetPeripheral()->START_ACCESS16BIT.STARTL = eventmask;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->START_ACCESS16BIT.STARTH = eventmask;
    }
  }
  /**
   * @brief Set the Output Set Events object
   * @param output
   * @param eventmask
   */
  constexpr static void SetOutputSetEvents(Outputs output, std::uint32_t eventmask) {
    std::size_t index = static_cast<std::size_t>(output);
    GetPeripheral()->OUT[index].SET = eventmask;
  }
  /**
   * @brief Set the Output Clear Events object
   * @param output
   * @param eventmask
   */
  constexpr static void SetOutputClearEvents(Outputs output, std::uint32_t eventmask) {
    std::size_t index = static_cast<std::size_t>(output);
    GetPeripheral()->OUT[index].CLR = eventmask;
  }
  /**
   * @brief Start counter
   * @param counter counter to start
   */
  constexpr static void Start(SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
      case SubCounters::LOWER:
        GetPeripheral()->CTRL = GetPeripheral()->CTRL & ~hardware::CTRL::kHALT_L;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->CTRL = GetPeripheral()->CTRL & ~hardware::CTRL::kHALT_H;
        break;
    }
  }
  /**
   * @brief Halt counter
   * @param counter counter to halt
   */
  constexpr static void Halt(SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
      case SubCounters::LOWER:
        GetPeripheral()->CTRL = GetPeripheral()->CTRL | hardware::CTRL::kHALT_L;
        break;
      case SubCounters::UPPER:
        GetPeripheral()->CTRL = GetPeripheral()->CTRL | hardware::CTRL::kHALT_H;
        break;
    }
  }
  /**
   * @brief Get counter value
   * @param counter counter to get value
   * @return current count
   */
  constexpr static std::uint32_t GetCounter(SubCounters counter = SubCounters::UNITED) {
    switch (counter) {
      case SubCounters::UNITED:
        return GetPeripheral()->COUNT;
        break;
      case SubCounters::LOWER:
        return static_cast<std::uint32_t>(GetPeripheral()->COUNT_ACCESS16BIT.COUNTL);
        break;
      case SubCounters::UPPER:
        return static_cast<std::uint32_t>(GetPeripheral()->COUNT_ACCESS16BIT.COUNTH);
    }
  }
  /**
   * @brief Setup match register
   * @param match matcher to setup
   * @param value value of the match register
   * @param counter counter the match register belangs to
   */
  constexpr static void SetupMatch(Matchers match, std::uint32_t value, SubCounters counter = SubCounters::UNITED) {
    std::uint32_t index = static_cast<std::uint32_t>(match);
    switch (counter) {
      case SubCounters::UNITED:
        GetPeripheral()->REGMODE = GetPeripheral()->REGMODE & ~(1 << index);
        GetPeripheral()->MATCH[index] = value;
        GetPeripheral()->MATCHREL[index] = value;
        break;
      case SubCounters::LOWER:
        GetPeripheral()->REGMODE = GetPeripheral()->REGMODE & ~(1 << index);
        GetPeripheral()->MATCH_ACCESS16BIT[index].MATCHL = static_cast<std::uint16_t>(value);
        GetPeripheral()->MATCHREL_ACCESS16BIT[index].MATCHRELL = static_cast<std::uint16_t>(value);
        break;
      case SubCounters::UPPER:
        GetPeripheral()->REGMODE = GetPeripheral()->REGMODE & ~(1 << (index + 16));
        GetPeripheral()->MATCH_ACCESS16BIT[index].MATCHH = static_cast<std::uint16_t>(value);
        GetPeripheral()->MATCHREL_ACCESS16BIT[index].MATCHRELH = static_cast<std::uint16_t>(value);
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
  constexpr static void SetupEvent(Events event, std::uint32_t stateMask, Matchers match, bool output, std::uint32_t ioIndex,
                                   IoEventConditions ioCondition, EventCombineModes combineMode, bool stateLoad,
                                   std::uint32_t stateValue, bool matchGreater = true,
                                   EventCountingDirections direction = EventCountingDirections::BIDI,
                                   SubCounters counter = SubCounters::UNITED) {
    std::size_t index = static_cast<std::size_t>(event);
    std::uint32_t eventRegister = hardware::EV_CTRL::MATCHSESEL(static_cast<std::uint32_t>(match)) |
                                  hardware::EV_CTRL::IOSEL(ioIndex) | static_cast<std::uint32_t>(ioCondition) |
                                  static_cast<std::uint32_t>(combineMode) | hardware::EV_CTRL::STATEV(stateValue) |
                                  static_cast<std::uint32_t>(direction);
    switch (counter) {
      case SubCounters::LOWER:
      case SubCounters::UNITED:
        break;
      case SubCounters::UPPER:
        eventRegister = eventRegister | hardware::EV_CTRL::kHEVENT;
        break;
    }
    if (output)
      eventRegister = eventRegister | hardware::EV_CTRL::kOUTSEL;
    if (stateLoad)
      eventRegister = eventRegister | hardware::EV_CTRL::kSTATELD;
    if (matchGreater)
      eventRegister = eventRegister | hardware::EV_CTRL::kMATCHMEM;
    GetPeripheral()->EV[index].CTRL = eventRegister;
    GetPeripheral()->EV[index].STATE = stateMask;
  }

  /**
   * @brief get registers from peripheral
   * @return return pointer to state configurable timer registers
   */
  constexpr static hardware::Sct *GetPeripheral() {
    return reinterpret_cast<hardware::Sct *>(sct_address_);
  }

 private:
  static constexpr libmcu::HwAddressType sct_address_ = sct_address; /*!< peripheral address */
};
}  // namespace libmcull::sct
#endif