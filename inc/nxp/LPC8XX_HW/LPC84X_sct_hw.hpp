/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_sct_hw.hpp
 * @brief LPC840 series State Configurable Timer register interface and definitions
 */
#ifndef LPC84X_SCT_HW_HPP
#define LPC84X_SCT_HW_HPP

namespace libmcuhw::sct {
/**
 * @brief SCT register definitions
 */
struct sct {
  volatile std::uint32_t CONFIG; /*!< SCT configuration register */
  union {
    struct {
      volatile std::uint16_t CTRLL; /*!< SCT_CTRLL register */
      volatile std::uint16_t CTRLH; /*!< SCT_CTRLH register */
    } CTRL_ACCESS16BIT;             /*!< SCT control register split*/
    volatile std::uint32_t CTRL;    /*!< SCT control register */
  };
  union {
    struct {
      volatile std::uint16_t LIMITL; /*!< SCT_LIMITL register */
      volatile std::uint16_t LIMITH; /*!< SCT_LIMITH register */
    } LIMIT_ACCESS16BIT;             /*!< SCT limit event select register split */
    volatile std::uint32_t LIMIT;    /*!< SCT limit event select register */
  };
  union {
    struct {
      volatile std::uint16_t HALTL; /*!< SCT_HALTL register */
      volatile std::uint16_t HALTH; /*!< SCT_HALTH register */
    } HALT_ACCESS16BIT;             /*!< SCT halt event select register split */
    volatile std::uint32_t HALT;    /*!< SCT halt event select register */
  };
  union {
    struct {
      volatile std::uint16_t STOPL; /*!< SCT_STOPL register */
      volatile std::uint16_t STOPH; /*!< SCT_STOPH register */
    } STOP_ACCESS16BIT;             /*!< SCT stop event select register split */
    volatile std::uint32_t STOP;    /*!< SCT stop event select register */
  };
  union {
    struct {
      volatile std::uint16_t STARTL; /*!< SCT_STARTL register */
      volatile std::uint16_t STARTH; /*!< SCT_STARTH register */
    } START_ACCESS16BIT;             /*!< SCT start event select register split */
    volatile std::uint32_t START;    /*!< SCT start event select register */
  };
  std::uint8_t RESERVED_0[40]; /*!< Reserved */
  union {
    struct {
      volatile std::uint16_t COUNTL; /*!< SCT_COUNTL register */
      volatile std::uint16_t COUNTH; /*!< SCT_COUNTH register */
    } COUNT_ACCESS16BIT;             /*!< SCT counter register split */
    volatile std::uint32_t COUNT;    /*!< SCT counter register */
  };
  union {
    struct {
      volatile std::uint16_t STATEL; /*!< SCT_STATEL register */
      volatile std::uint16_t STATEH; /*!< SCT_STATEH register */
    } STATE_ACCESS16BIT;             /*!< SCT state register */
    volatile std::uint32_t STATE;    /*!< SCT state register */
  };
  volatile const std::uint32_t INPUT; /*!< SCT input register */
  union {
    struct {
      volatile std::uint16_t REGMODEL; /*!< SCT_REGMODEL register */
      volatile std::uint16_t REGMODEH; /*!< SCT_REGMODEH register */
    } REGMODE_ACCESS16BIT;             /*!< SCT match/capture mode register */
    volatile std::uint32_t REGMODE;    /*!< SCT match/capture mode register */
  };
  volatile std::uint32_t OUTPUT;        /*!< SCT output register */
  volatile std::uint32_t OUTPUTDIRCTRL; /*!< SCT output counter direction control register */
  volatile std::uint32_t RES;           /*!< SCT conflict resolution register */
  volatile std::uint32_t DMAREQ0;       /*!< SCT DMA request 0 register */
  volatile std::uint32_t DMAREQ1;       /*!< SCT DMA request 1 register */
  std::uint8_t RESERVED_1[140];         /*!< Reserved */
  volatile std::uint32_t EVEN;          /*!< SCT event interrupt enable register */
  volatile std::uint32_t EVFLAG;        /*!< SCT event flag register */
  volatile std::uint32_t CONEN;         /*!< SCT conflict interrupt enable register */
  volatile std::uint32_t CONFLAG;       /*!< SCT conflict flag register */
  union {
    union {
      struct {
        volatile std::uint16_t CAPL; /*!< SCT_CAPL register */
        volatile std::uint16_t CAPH; /*!< SCT_CAPH register */
      } CAP_ACCESS16BIT[8];          /*!< SCT capture register of capture channel */
      volatile std::uint32_t CAP[8]; /*!< SCT capture register of capture channel */
    };
    union {
      struct {
        volatile std::uint16_t MATCHL; /*!< SCT_MATCHL register */
        volatile std::uint16_t MATCHH; /*!< SCT_MATCHH register */
      } MATCH_ACCESS16BIT[8];          /*!< SCT match value register of match channels */
      volatile std::uint32_t MATCH[8]; /*!< SCT match value register of match channels */
    };
  };
  std::uint8_t RESERVED_2[224]; /*!< Reserved */
  union {
    union {
      struct {
        volatile std::uint16_t CAPCTRLL; /*!< SCT_CAPCTRLL register */
        volatile std::uint16_t CAPCTRLH; /*!< SCT_CAPCTRLH register */
      } CAPCTRL_ACCESS16BIT[8];          /*!< SCT capture control register */
      volatile std::uint32_t CAPCTRL[8]; /*!< SCT capture control register */
    };
    union {
      struct {
        volatile std::uint16_t MATCHRELL; /*!< SCT_MATCHRELL register */
        volatile std::uint16_t MATCHRELH; /*!< SCT_MATCHRELH register */
      } MATCHREL_ACCESS16BIT[8];          /*!< SCT match reload value register */
      volatile std::uint32_t MATCHREL[8]; /*!< SCT match reload value register */
    };
  };
  std::uint8_t RESERVED_3[224]; /*!< Reserved */
  struct {
    volatile std::uint32_t STATE; /*!< SCT event state register 0 */
    volatile std::uint32_t CTRL;  /*!< SCT event control register 0 */
  } EV[8];                        /*!< Event register */
  std::uint8_t RESERVED_4[448];   /*!< Reserved */
  struct {
    volatile std::uint32_t SET; /*!< SCT output 0 set register */
    volatile std::uint32_t CLR; /*!< SCT output 0 clear register */
  } OUT[7];                     /*!< Output register  */
};
namespace CONFIG {
constexpr inline std::uint32_t RESERVED_MASK{0x00061FFFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t UNIFY{1u << 0};             /*!< SCT operates as unified 32 bit counter */
constexpr inline std::uint32_t SYSCLKMODE{0u << 1};        /*!< System clock mode */
constexpr inline std::uint32_t SAMPLEDSYSCLKMODE{1u << 1}; /*!< Sampled SCT input clocking mode */
constexpr inline std::uint32_t SCTINPUTCLKMODE{2u << 1};   /*!< SCT input clock mode */
constexpr inline std::uint32_t ASYNCMODE{3u << 1};         /*!< SCT input asynchronous clock mode */
constexpr inline std::uint32_t CLKSEL_RISE_IN0{0u << 3};   /*!< clock is rising edges on input 0 */
constexpr inline std::uint32_t CLKSEL_FALL_IN0{1u << 3};   /*!< clock is falling edges on input 0 */
constexpr inline std::uint32_t CLKSEL_RISE_IN1{2u << 3};   /*!< clock is rising edges on input 1 */
constexpr inline std::uint32_t CLKSEL_FALL_IN1{3u << 3};   /*!< clock is falling edges on input 1 */
constexpr inline std::uint32_t CLKSEL_RISE_IN2{4u << 3};   /*!< clock is rising edges on input 2 */
constexpr inline std::uint32_t CLKSEL_FALL_IN2{5u << 3};   /*!< clock is falling edges on input 2 */
constexpr inline std::uint32_t CLKSEL_RISE_IN3{6u << 3};   /*!< clock is rising edges on input 3 */
constexpr inline std::uint32_t CLKSEL_FALL_IN3{7u << 3};   /*!< clock is falling edges on input 3 */
constexpr inline std::uint32_t CLKSEL_RISE_IN4{8u << 3};   /*!< clock is rising edges on input 4, syscon selected */
constexpr inline std::uint32_t CLKSEL_FALL_IN4{9u << 3};   /*!< clock is falling edges on input 4, syscon selected */
constexpr inline std::uint32_t NORELOAD_L{1u << 7};        /*!< prevent reload of lower/unified match registers */
constexpr inline std::uint32_t NORELOAD_H{1u << 8};        /*!< prevent reload of higher match registers */
constexpr inline std::uint32_t INSYNC_INPUT0{1u << 9};     /*!< input 0 is synchronized */
constexpr inline std::uint32_t INSYNC_INPUT1{1u << 10};    /*!< input 1 is synchronized */
constexpr inline std::uint32_t INSYNC_INPUT2{1u << 11};    /*!< input 2 is synchronized */
constexpr inline std::uint32_t INSYNC_INPUT3{1u << 12};    /*!< input 3 is synchronized */
constexpr inline std::uint32_t AUTOLIMIT_L{1u << 17};      /*!< low/united match 0 is limit for counter */
constexpr inline std::uint32_t AUTOLIMIT_H{1u << 18};      /*!< upper match 0 is limit for counter */
}  // namespace CONFIG
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x1FFF1FFFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t DOWN_L{1u << 0};            /*!< low/united counter is counting down */
constexpr inline std::uint32_t STOP_L{1u << 1};            /*!< low/united counter is stopped */
constexpr inline std::uint32_t HALT_L{1u << 2};            /*!< low/united counter is halted */
constexpr inline std::uint32_t CLRCTR_L{1u << 3};          /*!< clear counter low/united */
constexpr inline std::uint32_t BIDIR_L{1u << 4};           /*!< low/united counter is bidirectional */
/**
 * @brief Format low/united counter prescaler
 * @param prescale counter clock is SCT clock divided by prescale+1
 * @return formatted data for PRE_L
 */
constexpr inline std::uint32_t PRE_L(std::uint32_t prescale) {
  return prescale << 5;
}
constexpr inline std::uint32_t DOWN_H{1u << 16};   /*!< high counter is counting down */
constexpr inline std::uint32_t STOP_H{1u << 17};   /*!< high counter is stopped */
constexpr inline std::uint32_t HALT_H{1u << 18};   /*!< high counter is halted */
constexpr inline std::uint32_t CLRCTR_H{1u << 19}; /*!< clear counter high */
constexpr inline std::uint32_t BIDIR_H{1u << 20};  /*!< high counter is bidirectional */
/**
 * @brief Format high counter prescaler
 * @param prescale counter clock is SCT clock divided by prescale+1
 * @return formatted data for PRE_H
 */
constexpr inline std::uint32_t PRE_H(std::uint32_t prescale) {
  return prescale << 21;
}
}  // namespace CTRL
namespace LIMIT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace HALT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace STOP {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace START {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace COUNT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace STATE {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace INPUT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace REGMODE {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace OUTPUT {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace OUTPUTDIRCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace RES {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace DMAREQ0 {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace DMAREQ1 {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace EVEN {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace EVFLAG {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace CONEN {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace CONFLAG {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace MATCH {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace CAP {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace MATCHREL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace CAPCTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace EV_STATE {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace EV_CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x007FFFFFu}; /*!< register mask for allowed bits */
/**
 * @brief Format match register associated with this event
 * @param prescale counter clock is SCT clock divided by prescale+1
 * @return formatted data for EV_CTRL
 */
constexpr inline std::uint32_t MATCHSESEL(std::uint32_t match) {
  return match << 0;
}
constexpr inline std::uint32_t HEVENT{1u << 4}; /*!< Select high counter */
constexpr inline std::uint32_t OUTSEL{1u << 5}; /*!< Selects output from IOSEL */
/**
 * @brief Format input output selection field with index
 * @param inputOutput input/output to associate with this event
 * @return formatted data for EV_CTRL
 */
constexpr inline std::uint32_t IOSEL(std::uint32_t index) {
  return index << 6;
}
constexpr inline std::uint32_t IOCOND_LOW{0u << 10};     /*!< Low level I/O condition for event */
constexpr inline std::uint32_t IOCOND_RISE{1u << 10};    /*!< Rising edge I/O condition for event */
constexpr inline std::uint32_t IOCOND_FALL{2u << 10};    /*!< Falling edge I/O condition for event */
constexpr inline std::uint32_t IOCOND_HIGH{3u << 10};    /*!< High level I/O condition for event */
constexpr inline std::uint32_t COMBMODE_OR{0u << 12};    /*!< Match or I/O condition occurs */
constexpr inline std::uint32_t COMBMODE_MATCH{1u << 12}; /*!< Match only event */
constexpr inline std::uint32_t COMBMODE_IO{2u << 12};    /*!< I/O only event */
constexpr inline std::uint32_t COMBMODE_AND{3u << 12};   /*!< Match and I/O condition occurs */
constexpr inline std::uint32_t STATELD{1u << 14};        /*!< Load state instead of add state */
/**
 * @brief Format state field with state number
 * @param state state value to associate with this event
 * @return formatted data for EV_CTRL
 */
constexpr inline std::uint32_t STATEV(std::uint32_t state) {
  return state << 15;
}
constexpr inline std::uint32_t MATCHMEM{1u << 20};       /*!< Match is equal and above/equal below  */
constexpr inline std::uint32_t DIRECTION_BIDI{0u << 21}; /*!< event triggers in both counting directions */
constexpr inline std::uint32_t DIRECTION_UP{1u << 21};   /*!< event triggers in up counting */
constexpr inline std::uint32_t DIRECTION_DOWN{2u << 21}; /*!< event triggers in down counting */
}  // namespace EV_CTRL
namespace OUT_SET {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
namespace OUT_CLR {
constexpr inline std::uint32_t RESERVED_MASK{0x00000000u}; /*!< register mask for allowed bits */
}
}  // namespace libmcuhw::sct
#endif