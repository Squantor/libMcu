/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series State configurable timer register interface
 */
#ifndef LPC81X_SCT_HW_HPP
#define LPC81X_SCT_HW_HPP

namespace libMcuLL {
namespace hw {
namespace sct {

static constexpr inline std::uint8_t inputCount = 4u;  /**< Number of inputs this SCT supports*/
static constexpr inline std::uint8_t outputCount = 4u; /**< Number of outputs this SCT supports */
static constexpr inline std::uint8_t matchCount = 5u;  /**< Number of match/compare registers */
static constexpr inline std::uint8_t eventCount = 6u;  /**< Number of events */
static constexpr inline std::uint8_t stateCount = 2u;  /**< Number of states*/

/**
 * @brief state configurable timer register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CONFIG; /**< configuration Register*/
  union {
    volatile std::uint32_t CTRL; /**< SCT control register*/
    struct {
      volatile std::uint16_t CTRLL; /**< SCT_CTRLL register*/
      volatile std::uint16_t CTRLH; /**< SCT_CTRLH register */
    };
  };
  union {
    volatile std::uint32_t LIMIT; /**< limit Register */
    struct {
      volatile std::uint16_t LIMIT_L; /**< limit register for counter L */
      volatile std::uint16_t LIMIT_H; /**< limit register for counter H */
    };
  };

  union {
    volatile std::uint32_t HALT; /**< halt Register */
    struct {
      volatile std::uint16_t HALT_L; /**< halt register for counter L */
      volatile std::uint16_t HALT_H; /**< halt register for counter H */
    };
  };

  union {
    volatile std::uint32_t STOP; /**< stop Register */
    struct {
      volatile std::uint16_t STOP_L; /**< stop register for counter L */
      volatile std::uint16_t STOP_H; /**< stop register for counter H */
    };
  };

  union {
    volatile std::uint32_t START; /**< start Register */
    struct {
      volatile std::uint16_t START_L; /**< start register for counter L */
      volatile std::uint16_t START_H; /**< start register for counter H */
    };
  };

  std::uint32_t RESERVED1[10]; /**< 0x018 - 0x03C reserved */

  union {
    volatile std::uint32_t COUNT; /**< counter register (offset 0x040)*/
    struct {
      volatile std::uint16_t COUNT_L; /**< counter register for counter L */
      volatile std::uint16_t COUNT_H; /**< counter register for counter H */
    };
  };

  union {
    volatile std::uint32_t STATE; /**< State register */
    struct {
      volatile std::uint16_t STATE_L; /**< state register for counter L */
      volatile std::uint16_t STATE_H; /**< state register for counter H */
    };
  };

  volatile const std::uint32_t INPUT; /**< input register */
  union {
    volatile std::uint32_t REGMODE; /**< RegMode register */
    struct {
      volatile std::uint16_t REGMODE_L; /**< match - capture registers mode register L */
      volatile std::uint16_t REGMODE_H; /**< match - capture registers mode register H */
    };
  };

  volatile std::uint32_t OUTPUT;        /**< output register */
  volatile std::uint32_t OUTPUTDIRCTRL; /**< output counter direction Control Register */
  volatile std::uint32_t RES;           /**< conflict resolution register */

  std::uint32_t RESERVED2[37]; /**< 0x05C - 0x0EC reserved */

  volatile std::uint32_t EVEN;    /**< event enable register (offset 0x0F0)*/
  volatile std::uint32_t EVFLAG;  /**< event flag register */
  volatile std::uint32_t CONEN;   /**< conflict enable register */
  volatile std::uint32_t CONFLAG; /**< conflict flag register */
  union {
    union {                     /**< ... Match / Capture value */
      volatile std::uint32_t U; /**<  MATCH[i].U  Unified 32-bit register */
      struct {
        volatile std::uint16_t L; /**<  MATCH[i].L  Access to L value */
        volatile std::uint16_t H; /**<  MATCH[i].H  Access to H value */
      };
    } MATCH[matchCount];

    const union {
      volatile std::uint32_t U; /**<  CAP[i].U  Unified 32-bit register */
      struct {
        volatile std::uint16_t L; /**<  CAP[i].L  Access to L value */
        volatile std::uint16_t H; /**<  CAP[i].H  Access to H value */
      };
    } CAP[matchCount];
  };

  std::uint32_t RESERVED3[59]; /**< 0x114 - 0x1FC reserved */

  union {
    union {                     /**< ...Match Reload / Capture Control value (offset 0x200) */
      volatile std::uint32_t U; /**<  MATCHREL[i].U  Unified 32-bit register */
      struct {
        volatile std::uint16_t L; /**<  MATCHREL[i].L  Access to L value */
        volatile std::uint16_t H; /**<  MATCHREL[i].H  Access to H value */
      };
    } MATCHREL[matchCount];

    union {
      volatile std::uint32_t U; /**<  CAPCTRL[i].U  Unified 32-bit register */
      struct {
        volatile std::uint16_t L; /**<  CAPCTRL[i].L  Access to L value */
        volatile std::uint16_t H; /**<  CAPCTRL[i].H  Access to H value */
      };
    } CAPCTRL[matchCount];
  };

  std::uint32_t RESERVED4[59]; /**< 0x214 - 0x2FC reserved */

  struct {                        /**< EV[i].STATE / EV[i].CTRL (offset 0x300) */
    volatile std::uint32_t STATE; /**< Event State Register */
    volatile std::uint32_t CTRL;  /**< Event Control Register */
  } EV[eventCount];

  std::uint32_t RESERVED5[116]; /**< 0x330 - 0x4FC reserved */

  struct {                      /**< OUT[i].SET / OUT[i].CLR  (offset 0x500) */
    volatile std::uint32_t SET; /**< Output n Set Register */
    volatile std::uint32_t CLR; /**< Output n Clear Register */
  } OUT[outputCount];
};

namespace CONFIG {
constexpr inline std::uint32_t MASK = 0x0007FFFF;          /**< register mask for allowed bits */
constexpr inline std::uint32_t UNIFY_OFF = (0 << 0);       /**< SCT as two 16 bit timers  */
constexpr inline std::uint32_t UNIFY_ON = (1 << 0);        /**< SCT as single 32 bit timer */
constexpr inline std::uint32_t CLKMODE_BUS = (0 << 1);     /**< SCT clock is bus clock */
constexpr inline std::uint32_t CLKMODE_BUS_PRE = (1 << 1); /**< SCT clock is a SCT input synced to prescaled bus clock*/
constexpr inline std::uint32_t CLKMODE_INPUT = (2 << 1);   /**< SCT clock is a SCT input */
constexpr inline std::uint32_t CKSEL_0_RISING = (0 << 3);  /**< SCT clock input 0 rising edges */
constexpr inline std::uint32_t CKSEL_0_FALLING = (1 << 3); /**< SCT clock input 0 falling edges */
constexpr inline std::uint32_t CKSEL_1_RISING = (2 << 3);  /**< SCT clock input 1 rising edges */
constexpr inline std::uint32_t CKSEL_1_FALLING = (3 << 3); /**< SCT clock input 1 falling edges */
constexpr inline std::uint32_t CKSEL_2_RISING = (4 << 3);  /**< SCT clock input 2 rising edges */
constexpr inline std::uint32_t CKSEL_2_FALLING = (5 << 3); /**< SCT clock input 2 falling edges */
constexpr inline std::uint32_t CKSEL_3_RISING = (6 << 3);  /**< SCT clock input 3 rising edges */
constexpr inline std::uint32_t CKSEL_3_FALLING = (7 << 3); /**< SCT clock input 3 falling edges */
constexpr inline std::uint32_t NORELOAD_L = (1 << 7);      /**< prevents reload of lower match registers */
constexpr inline std::uint32_t NORELOAD_H = (1 << 8);      /**< prevents reload of higher match registers */
/**
 * @brief Format synchronization for input N
 *
 * @param inputBits bit 0 is input 0, bit 1 is input 1, bit 7 is input 7
 * @return formatted data for INSYNC
 */
constexpr inline std::uint32_t INSYNC(std::uint32_t inputBits) {
  return inputBits << 9;
}
constexpr inline std::uint32_t AUTOLIMIT_L = (1 << 17); /**< treats match 0 low register as the LIMIT condition */
constexpr inline std::uint32_t AUTOLIMIT_H = (1 << 18); /**< treats match 0 high register as the LIMIT condition */
}  // namespace CONFIG
namespace CTRL {
constexpr inline std::uint32_t MASK = 0x1FFF1FFF;   /**< register mask for allowed bits */
constexpr inline std::uint32_t DOWN_L = (1 << 0);   /**< low counter is counting down */
constexpr inline std::uint32_t STOP_L = (1 << 1);   /**< low counter is stopped */
constexpr inline std::uint32_t HALT_L = (1 << 2);   /**< low counter is halted */
constexpr inline std::uint32_t CLRCTR_L = (1 << 3); /**< clear counter low */
constexpr inline std::uint32_t BIDIR_L = (1 << 4);  /**< low counter is bidirectional */
/**
 * @brief Format low counter prescaler
 *
 * @param prescale counter clock is SCT clock divided by prescale+1
 * @return formatted data for PRE_L
 */
constexpr inline std::uint32_t PRE_L(std::uint32_t prescale) {
  return prescale << 5;
}
constexpr inline std::uint32_t DOWN_H = (1 << 16);   /**< high counter is counting down */
constexpr inline std::uint32_t STOP_H = (1 << 17);   /**< high counter is stopped */
constexpr inline std::uint32_t HALT_H = (1 << 18);   /**< high counter is halted */
constexpr inline std::uint32_t CLRCTR_H = (1 << 19); /**< clear counter high */
constexpr inline std::uint32_t BIDIR_H = (1 << 20);  /**< high counter is bidirectional */
/**
 * @brief Format high counter prescaler
 *
 * @param prescale counter clock is SCT clock divided by prescale+1
 * @return formatted data for PRE_H
 */
constexpr inline std::uint32_t PRE_H(std::uint32_t prescale) {
  return prescale << 21;
}
}  // namespace CTRL
namespace CTRL_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CTRL_L
namespace CTRL_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CTRL_H
namespace LIMIT {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace LIMIT
namespace LIMIT_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace LIMIT_L
namespace LIMIT_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace LIMIT_H
namespace HALT {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace HALT
namespace HALT_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace HALT_L
namespace HALT_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace HALT_H
namespace STOP {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace STOP
namespace STOP_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace STOP_L
namespace STOP_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace STOP_H
namespace START {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace START
namespace START_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace START_L
namespace START_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace START_H
namespace COUNT {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace COUNT
namespace COUNT_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace COUNT_L
namespace COUNT_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace COUNT_H
namespace STATE {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace STATE
namespace STATE_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace STATE_L
namespace STATE_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace STATE_H
namespace INPUT {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INPUT
namespace REGMODE {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace REGMODE
namespace REGMODE_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace REGMODE_L
namespace REGMODE_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace REGMODE_H
namespace OUTPUT {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace OUTPUT
namespace OUTPUTDIRCTRL {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace OUTPUTDIRCTRL
namespace RES {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace RES
namespace EVEN {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace EVEN
namespace EVFLAG {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace EVFLAG
namespace CONEN {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CONEN
namespace CONFLAG {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CONFLAG
namespace MATCH {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MATCH
namespace MATCH_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace MATCH_L
namespace MATCH_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace MATCH_H
namespace CAP {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CAP
namespace CAP_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CAP_L
namespace CAP_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CAP_H
namespace MATCHREL {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MATCHREL
namespace MATCHREL_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace MATCHREL_L
namespace MATCHREL_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace MATCHREL_H
namespace CAPCTRL {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CAPCTRL
namespace CAPCTRL_L {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CAPCTRL_L
namespace CAPCTRL_H {
constexpr inline std::uint16_t MASK = 0x0000; /**< register mask for allowed bits */
}  // namespace CAPCTRL_H
namespace EV_STATE {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace EV_STATE
namespace EV_CTRL {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace EV_CTRL
namespace OUT_SET {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace OUT_SET
namespace OUT_CLR {
constexpr inline std::uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace OUT_CLR

}  // namespace sct
}  // namespace hw
}  // namespace libMcuLL

#endif