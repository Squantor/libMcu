/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series State configurable timer register interface
 */
#ifndef LPC81X_SCT_REGS_HPP
#define LPC81X_SCT_REGS_HPP

namespace registers {
namespace sct {

static constexpr inline uint8_t sctEventCount = 8u;  /**< Number of events */
static constexpr inline uint8_t sctMatchCount = 8u;  /**< Number of match/compare registers */
static constexpr inline uint8_t sctOutputCount = 6u; /**< Number of outputs */

/**
 * @brief state configurable timer register definitions
 *
 */
struct registers {
  volatile uint32_t CONFIG; /**< configuration Register*/
  union {
    volatile uint32_t CTRL; /**< SCT control register*/
    struct {
      volatile uint16_t CTRLL; /**< SCT_CTRLL register*/
      volatile uint16_t CTRLH; /**< SCT_CTRLH register */
    };
  };
  union {
    volatile uint32_t LIMIT; /**< limit Register */
    struct {
      volatile uint16_t LIMIT_L; /**< limit register for counter L */
      volatile uint16_t LIMIT_H; /**< limit register for counter H */
    };
  };

  union {
    volatile uint32_t HALT; /**< halt Register */
    struct {
      volatile uint16_t HALT_L; /**< halt register for counter L */
      volatile uint16_t HALT_H; /**< halt register for counter H */
    };
  };

  union {
    volatile uint32_t STOP; /**< stop Register */
    struct {
      volatile uint16_t STOP_L; /**< stop register for counter L */
      volatile uint16_t STOP_H; /**< stop register for counter H */
    };
  };

  union {
    volatile uint32_t START; /**< start Register */
    struct {
      volatile uint16_t START_L; /**< start register for counter L */
      volatile uint16_t START_H; /**< start register for counter H */
    };
  };

  uint32_t RESERVED1[10]; /**< 0x018 - 0x03C reserved */

  union {
    volatile uint32_t COUNT; /**< counter register (offset 0x040)*/
    struct {
      volatile uint16_t COUNT_L; /**< counter register for counter L */
      volatile uint16_t COUNT_H; /**< counter register for counter H */
    };
  };

  union {
    volatile uint32_t STATE; /**< State register */
    struct {
      volatile uint16_t STATE_L; /**< state register for counter L */
      volatile uint16_t STATE_H; /**< state register for counter H */
    };
  };

  volatile const uint32_t INPUT; /**< input register */
  union {
    volatile uint32_t REGMODE; /**< RegMode register */
    struct {
      volatile uint16_t REGMODE_L; /**< match - capture registers mode register L */
      volatile uint16_t REGMODE_H; /**< match - capture registers mode register H */
    };
  };

  volatile uint32_t OUTPUT;        /**< output register */
  volatile uint32_t OUTPUTDIRCTRL; /**< output counter direction Control Register */
  volatile uint32_t RES;           /**< conflict resolution register */

  uint32_t RESERVED2[37]; /**< 0x05C - 0x0EC reserved */

  volatile uint32_t EVEN;    /**< event enable register (offset 0x0F0)*/
  volatile uint32_t EVFLAG;  /**< event flag register */
  volatile uint32_t CONEN;   /**< conflict enable register */
  volatile uint32_t CONFLAG; /**< conflict flag register */
  union {
    union {                /**< ... Match / Capture value */
      volatile uint32_t U; /**<  MATCH[i].U  Unified 32-bit register */
      struct {
        volatile uint16_t L; /**<  MATCH[i].L  Access to L value */
        volatile uint16_t H; /**<  MATCH[i].H  Access to H value */
      };
    } MATCH[sctMatchCount];

    const union {
      volatile uint32_t U; /**<  CAP[i].U  Unified 32-bit register */
      struct {
        volatile uint16_t L; /**<  CAP[i].L  Access to L value */
        volatile uint16_t H; /**<  CAP[i].H  Access to H value */
      };
    } CAP[sctMatchCount];
  };

  uint32_t RESERVED3[56]; /**< 0x120 - 0x1FC reserved */

  union {
    union {                /**< ...Match Reload / Capture Control value (offset 0x200) */
      volatile uint32_t U; /**<  MATCHREL[i].U  Unified 32-bit register */
      struct {
        volatile uint16_t L; /**<  MATCHREL[i].L  Access to L value */
        volatile uint16_t H; /**<  MATCHREL[i].H  Access to H value */
      };
    } MATCHREL[sctMatchCount];

    union {
      volatile uint32_t U; /**<  CAPCTRL[i].U  Unified 32-bit register */
      struct {
        volatile uint16_t L; /**<  CAPCTRL[i].L  Access to L value */
        volatile uint16_t H; /**<  CAPCTRL[i].H  Access to H value */
      };
    } CAPCTRL[sctMatchCount];
  };

  uint32_t RESERVED4[56]; /**< 0x220 - 0x2FC reserved */

  struct {                   /**< EV[i].STATE / EV[i].CTRL (offset 0x300) */
    volatile uint32_t STATE; /**< Event State Register */
    volatile uint32_t CTRL;  /**< Event Control Register */
  } EV[sctEventCount];

  uint32_t RESERVED5[112]; /**< 0x340 - 0x4FC reserved */

  struct {                 /**< OUT[i].SET / OUT[i].CLR  (offset 0x500) */
    volatile uint32_t SET; /**< Output n Set Register */
    volatile uint32_t CLR; /**< Output n Clear Register */
  } OUT[sctOutputCount];
};

}  // namespace sct
}  // namespace registers

#endif