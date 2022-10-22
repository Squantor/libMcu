/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series State configurable timer registers, defines and functions.
 */
#ifndef LPC84X_SCT_H
#define LPC84X_SCT_H

#define CONFIG_SCT_nEV (8) /*!< Number of events */
#define CONFIG_SCT_nRG (8) /*!< Number of match/compare registers */
#define CONFIG_SCT_nOU (7) /*!< Number of outputs */

/** SCT - Register Layout Typedef */
typedef volatile struct SCT_Struct {
  uint32_t CONFIG; /**< SCT configuration register, offset: 0x0 */
  union {
    uint32_t CTRL; /*!< SCT control register*/
    struct {
      uint16_t CTRLL; /*!< SCT_CTRLL register*/
      uint16_t CTRLH; /*!< SCT_CTRLH register */
    };
  };
  union {
    uint32_t LIMIT; /* limit Register */
    struct {
      uint16_t LIMIT_L; /* limit register for counter L */
      uint16_t LIMIT_H; /* limit register for counter H */
    };
  };
  union {
    uint32_t HALT; /* halt Register */
    struct {
      uint16_t HALT_L; /* halt register for counter L */
      uint16_t HALT_H; /* halt register for counter H */
    };
  };
  union {
    uint32_t STOP; /* stop Register */
    struct {
      uint16_t STOP_L; /* stop register for counter L */
      uint16_t STOP_H; /* stop register for counter H */
    };
  };
  union {
    uint32_t START; /* start Register */
    struct {
      uint16_t START_L; /* start register for counter L */
      uint16_t START_H; /* start register for counter H */
    };
  };
  uint32_t RESERVED1[10]; /* 0x018 - 0x03C reserved */

  union {
    uint32_t COUNT; /* counter register (offset 0x040)*/
    struct {
      uint16_t COUNT_L; /* counter register for counter L */
      uint16_t COUNT_H; /* counter register for counter H */
    };
  };
  union {
    uint32_t STATE; /* State register */
    struct {
      uint16_t STATE_L; /* state register for counter L */
      uint16_t STATE_H; /* state register for counter H */
    };
  };
  const uint32_t INPUT; /* input register */
  union {
    uint32_t REGMODE; /* RegMode register */
    struct {
      uint16_t REGMODE_L; /* match - capture registers mode register L */
      uint16_t REGMODE_H; /* match - capture registers mode register H */
    };
  };
  uint32_t OUTPUT;        /* output register */
  uint32_t OUTPUTDIRCTRL; /* output counter direction Control Register */
  uint32_t RES;           /* conflict resolution register */
  uint32_t DMAREQ0;       /* DMA0 Request Register */
  uint32_t DMAREQ1;       /* DMA1 Request Register */

  uint32_t RESERVED2[35]; /* 0x064 - 0x0EC reserved */

  uint32_t EVEN;    /* event enable register (offset 0x0F0)*/
  uint32_t EVFLAG;  /* event flag register */
  uint32_t CONEN;   /* conflict enable register */
  uint32_t CONFLAG; /* conflict flag register */
  union {
    union {       /* ... Match / Capture value */
      uint32_t U; /*  MATCH[i].U  Unified 32-bit register */
      struct {
        uint16_t L; /*  MATCH[i].L  Access to L value */
        uint16_t H; /*  MATCH[i].H  Access to H value */
      };
    } MATCH[CONFIG_SCT_nRG];

    const union {
      uint32_t U; /*  CAP[i].U  Unified 32-bit register */
      struct {
        uint16_t L; /*  CAP[i].L  Access to L value */
        uint16_t H; /*  CAP[i].H  Access to H value */
      };
    } CAP[CONFIG_SCT_nRG];
  };

  uint32_t RESERVED3[56]; /* 0x120 - 0x1FC reserved */

  union {
    union {       /* ...Match Reload / Capture Control value (offset 0x200) */
      uint32_t U; /*  MATCHREL[i].U  Unified 32-bit register */
      struct {
        uint16_t L; /*  MATCHREL[i].L  Access to L value */
        uint16_t H; /*  MATCHREL[i].H  Access to H value */
      };
    } MATCHREL[CONFIG_SCT_nRG];

    union {
      uint32_t U; /*  CAPCTRL[i].U  Unified 32-bit register */
      struct {
        uint16_t L; /*  CAPCTRL[i].L  Access to L value */
        uint16_t H; /*  CAPCTRL[i].H  Access to H value */
      };
    } CAPCTRL[CONFIG_SCT_nRG];
  };

  uint32_t RESERVED4[56]; /* 0x220 - 0x2FC reserved */

  struct {          /* EV[i].STATE / EV[i].CTRL (offset 0x300) */
    uint32_t STATE; /* Event State Register */
    uint32_t CTRL;  /* Event Control Register */
  } EV[CONFIG_SCT_nEV];

  uint32_t RESERVED5[112]; /* 0x340 - 0x4FC reserved */

  struct {        /* OUT[i].SET / OUT[i].CLR  (offset 0x500) */
    uint32_t SET; /* Output n Set Register */
    uint32_t CLR; /* Output n Clear Register */
  } OUT[CONFIG_SCT_nOU];
} SCT_Type;

/* Reserved bits masks for registers */

#define SCT_LIMIT_RESERVED              (~(0x3f|(0x3f<<16))
#define SCT_HALT_RESERVED               (~(0x3f|(0x3f<<16))
#define SCT_STOP_RESERVED               (~(0x3f|(0x3f<<16))
#define SCT_START_RESERVED              (~(0x3f|(0x3f<<16))
#define SCT_STATE_RESERVED              (~(0x1f|(0x1f<<16))
#define SCT_INPUT_RESERVED              (~(0xf|(0xf<<16))
#define SCT_REGMODE_RESERVED            (~(0x1f|(0x1f<<16))
#define SCT_OUTPUT_RESERVED (~0xf)
#define SCT_OUTPUTDIRCTRL_RESERVED (~0xff)
#define SCT_RES_RESERVED (~0xff)
#define SCT_EVEN_RESERVED (~0x3f)
#define SCT_EVFLAG_RESERVED (~0x3f)
#define SCT_CONEN_RESERVED (~0xf)
#define SCT_CONFLAG_RESERVED (~(0xf | (3u << 30)))
#define SCT_CAPCTRL_RESERVED (~(0x3f | (0x3f << 16)))
#define SCT_EVn_STATE_RESERVED (~3)
#define SCT_EVn_CTRL_RESERVED (0xff800000)
#define SCT_OUTn_SET_RESERVED (~0x3f)
#define SCT_OUTn_CLR_RESERVED (~0x3f)

/*
 * Macro defines for SCT configuration register
 */
#define SCT_CONFIG_RESERVED (0xFFF9E000) /*!< Reserved bits of SCT config register */
#define SCT_CONFIG_16BIT_COUNTER               \
  (0x0 << 0) /*!< Operate as 2 16-bit counters \
              */
#define SCT_CONFIG_32BIT_COUNTER                                               \
  (0x1 << 0)                                  /*!< Operate as 1 32-bit counter \
                                               */
#define SCT_CONFIG_CLKMODE_SYSTEM (0x0 << 1)  /*!< System clock mode */
#define SCT_CONFIG_CLKMODE_SAMPLED (0x1 << 1) /*!< Sampled clock mode */
#define SCT_CONFIG_CLKMODE_INCLK                                              \
  (0x2 << 1)                                /*!< SCTimer/PWM input clock mode \
                                             */
#define SCT_CONFIG_CLKMODE_ASYNC (0x3 << 1) /*!< Asynchronous clock mode */
typedef enum {
  SCT_CONFIG_CKSEL_RISE_IN0 = 0x0, /*!< Rising edges on input0 */
  SCT_CONFIG_CKSEL_FALL_IN0 = 0x1, /*!< Falling edges on input0 */
  SCT_CONFIG_CKSEL_RISE_IN1 = 0x0, /*!< Rising edges on input1 */
  SCT_CONFIG_CKSEL_FALL_IN1 = 0x1, /*!< Falling edges on input1 */
  SCT_CONFIG_CKSEL_RISE_IN2 = 0x0, /*!< Rising edges on input2 */
  SCT_CONFIG_CKSEL_FALL_IN2 = 0x1, /*!< Falling edges on input2 */
  SCT_CONFIG_CKSEL_RISE_IN3 = 0x0, /*!< Rising edges on input3 */
  SCT_CONFIG_CKSEL_FALL_IN3 = 0x1, /*!< Falling edges on input3 */
  SCT_CONFIG_CKSEL_RISE_IN4 = 0x0, /*!< Rising edges on input4. Clock selected by SYSCON SCTCLKSEL */
  SCT_CONFIG_CKSEL_FALL_IN4 = 0x1, /*!< Falling edges on input4. Clock selected by SYSCON SCTCLKSEL */
} SCT_CONFIG_CKSEL_Type;
#define SCT_CONFIG_CKSEL(clock) ((clock) << 3) /*!< input to select for the clock mode */
#define SCT_CONFIG_NORELOAD_U (0x1 << 7)       /*!< Prevent match register reload */
#define SCT_CONFIG_NORELOAD_L (0x1 << 7)       /*!< Prevent lower match register reload */
#define SCT_CONFIG_NORELOAD_H (0x1 << 8)       /*!< Prevent upper match register reload */
#define SCT_CONFIG_INSYNC_IN0 (1u << 9)        /*!< Enable input synchronizer for input 0 */
#define SCT_CONFIG_INSYNC_IN1 (1u << 10)       /*!< Enable input synchronizer for input 1 */
#define SCT_CONFIG_INSYNC_IN2 (1u << 11)       /*!< Enable input synchronizer for input 2 */
#define SCT_CONFIG_INSYNC_IN3 (1u << 12)       /*!< Enable input synchronizer for input 3 */
#define SCT_CONFIG_AUTOLIMIT_U (0x1 << 17)     /*!< Limits counter(unified) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_L (0x1 << 17)     /*!< Limits counter(L) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_H (0x1 << 18)     /*!< Limits counter(L) based on MATCH0 */

/*
 * Macro defines for SCT control register
 */
#define SCT_CTRL_RESERVED (0xE000E000) /*!< Reserved bits of SCT Control register */
#define SCT_CTRL_L_RESERVED (0xE000)   /*!< Reserved bits of Lower SCT Control register */
#define SCT_CTRL_H_RESERVED (0xE000)   /*!< Reserved bits of Higher SCT Control register */

#define SCT_CTRL_STOP_U (1 << 1)   /*!< Stop counter */
#define SCT_CTRL_STOP_L (1 << 1)   /*!< Stop low counter */
#define SCT_CTRL_HALT_U (1 << 2)   /*!< Halt counter */
#define SCT_CTRL_HALT_L (1 << 2)   /*!< Halt low counter */
#define SCT_CTRL_CLRCTR_U (1 << 3) /*!< Clear unified counter */
#define SCT_CTRL_CLRCTR_L (1 << 3) /*!< Clear low counter */
#define SCT_CTRL_BIDIR_U                                                                \
  (1 << 4)                                  /*!< Unified counter bidirectional counting \
                                             */
#define SCT_CTRL_BIDIR_L (1 << 4)           /*!< Low counter bidirectional counting */
#define SCT_CTRL_PRE_U(x) (((x)&0xFF) << 5) /*!< Prescale clock for unified counter */
#define SCT_CTRL_PRE_L(x) (((x)&0xFF) << 5) /*!< Prescale clock for low counter */

#define SCT_CTRL_STOP_H (1 << 17)            /*!< Stop high counter */
#define SCT_CTRL_HALT_H (1 << 18)            /*!< Halt high counter */
#define SCT_CTRL_CLRCTR_H (1 << 19)          /*!< Clear high counter */
#define SCT_CTRL_BIDIR_H (1 << 20)           /*!< High counter bidirectional counting */
#define SCT_CTRL_PRE_H(x) (((x)&0xFF) << 21) /*!< Prescale clock for high counter */

/*
 * Defines for the SCT event control register
 */
#define SCT_EV_CTRL_MATCHSEL(x) (((x)&0x0F) << 0)
#define SCT_EV_CTRL_H_EVENT (1 << 4)
#define SCT_EV_CTRL_L_EVENT (0 << 4)
#define SCT_EV_CTRL_INSEL (0 << 5)
#define SCT_EV_CTRL_OUTSEL (1 << 5)
#define SCT_EV_CTRL_IOSEL(x) (((x)&0x0F) << 6)
#define SCT_IOCOND_LOW (0)
#define SCT_IOCOND_RISE (1)
#define SCT_IOCOND_FALL (2)
#define SCT_IOCOND_HIGH (3)
#define SCT_EV_CTRL_IOCOND(x) (((x)&0x03) << 10)
#define SCT_COMBMODE_OR (0)
#define SCT_COMBMODE_MATCH (1)
#define SCT_COMBMODE_IO (2)
#define SCT_COMBMODE_AND (3)
#define SCT_EV_CTRL_COMBMODE(x) (((x)&0x03) << 12)
#define SCT_EV_CTRL_STATELD_ADD (0 << 14)
#define SCT_EV_CTRL_STATELD_LOAD (1 << 14)
#define SCT_EV_CTRL_STATEV(x) (((x)&0x1F) << 15)
#define SCT_EV_CTRL_MATCHMEM (1 << 20)
#define SCT_EV_CTRL_DIRECTION_IND (0)
#define SCT_EV_CTRL_DIRECTION_UP (1)
#define SCT_EV_CTRL_DIRECTION_DOWN (2)
#define SCT_EV_CTRL_DIRECTION(x) (((x)&0x03) << 21)

/**
Definitions for the Match/Compare mode register
 */
#define SCT_REGMODE_MATCH (0)
#define SCT_REGMODE_CAPTURE (1)
#define SCT_REGMODE_U(n, x) ((x) << (n))
#define SCT_REGMODE_L(n, x) ((x) << (n))
#define SCT_REGMODE_H(n, x) ((x) << ((n) + 15))

/*
Definitions for the output conflict resolution register
 */
#define SCT_CONFLICTRES_NONE (0)
#define SCT_CONFLICTRES_SET (1)
#define SCT_CONFLICTRES_CLEAR (2)
#define SCT_CONFLICTRES_TOGGLE (3)
#define SCT_CONFLICTRES(n, x) ((x) << ((n)*2))

/*
Definitions for the output direction control register
*/
#define SCT_OUTPUTDIRCTRL_ANY (0) /* Any, set and clear do not depend on counter */
#define SCT_OUTPUTDIRCTRL_L                                                  \
  (1) /* L counting down, set and clear are reversed when L is counting down \
       */
#define SCT_OUTPUTDIRCTRL_H                                                                                             \
  (2)                                            /* H counting down, set and clear are reversed when H is counting down \
                                                  */
#define SCT_OUTPUTDIRCTRL(n, x) ((x) << ((n)*2)) /* set output direction control for channel n */

/*
Definitions for the SCT output register
*/
#define SCT_OUTPUT_STATE(n, x) ((x) << (n))

/**
 * SCT Match register values enum, TODO: move to device specifics
 */
typedef enum SCT_MATCH_REG {
  SCT_MATCH_0 = 0, /* SCT Match register 0 */
  SCT_MATCH_1 = 1, /* SCT Match register 1 */
  SCT_MATCH_2 = 2, /* SCT Match register 2 */
  SCT_MATCH_3 = 3, /* SCT Match register 3 */
  SCT_MATCH_4 = 4, /* SCT Match register 4 */
  SCT_MATCH_5 = 5, /* SCT Match register 5 */
  SCT_MATCH_6 = 6, /* SCT Match register 6 */
  SCT_MATCH_7 = 7, /* SCT Match register 7 */
} SCT_MATCH_REG_T;

/**
 * SCT Capture register values enum, TODO: move to device specifics
 */
typedef enum SCT_CAPTURE_REG {
  SCT_CAPTURE_0 = 0, /** SCT capture register 0 */
  SCT_CAPTURE_1 = 1, /** SCT capture register 1 */
  SCT_CAPTURE_2 = 2, /** SCT capture register 2 */
  SCT_CAPTURE_3 = 3, /** SCT capture register 3 */
  SCT_CAPTURE_4 = 4, /** SCT capture register 4 */
  SCT_CAPTURE_5 = 5, /** SCT capture register 2 */
  SCT_CAPTURE_6 = 6, /** SCT capture register 3 */
  SCT_CAPTURE_7 = 7, /** SCT capture register 4 */
} SCT_CAPTURE_REG_T;

/**
 * SCT Event indexes enum, TODO: move to device specifics
 */
typedef enum SCT_EVENT_VAL {
  SCT_EVENT_0_VAL = 0, /* Event 0 */
  SCT_EVENT_1_VAL = 1, /* Event 1 */
  SCT_EVENT_2_VAL = 2, /* Event 2 */
  SCT_EVENT_3_VAL = 3, /* Event 3 */
  SCT_EVENT_4_VAL = 4, /* Event 4 */
  SCT_EVENT_5_VAL = 5, /* Event 5 */
  SCT_EVENT_6_VAL = 6, /* Event 6 */
  SCT_EVENT_7_VAL = 7, /* Event 7 */
} SCT_EVENT_VAL_T;

/**
 * SCT Event values enum, TODO: move to device specific sct definitions
 */
typedef enum SCT_EVENT_BIT {
  SCT_EVENT_0_BIT = (1 << 0), /* Event 0 */
  SCT_EVENT_1_BIT = (1 << 1), /* Event 1 */
  SCT_EVENT_2_BIT = (1 << 2), /* Event 2 */
  SCT_EVENT_3_BIT = (1 << 3), /* Event 3 */
  SCT_EVENT_4_BIT = (1 << 4), /* Event 4 */
  SCT_EVENT_5_BIT = (1 << 5), /* Event 5 */
  SCT_EVENT_6_BIT = (1 << 6), /* Event 6 */
  SCT_EVENT_7_BIT = (1 << 7), /* Event 7 */
} SCT_EVENT_BIT_T;

typedef enum SCT_STATE_BIT {
  SCT_STATE_0_BIT = (1 << 0),
  SCT_STATE_1_BIT = (1 << 1),
  SCT_STATE_2_BIT = (1 << 2),
  SCT_STATE_3_BIT = (1 << 3),
  SCT_STATE_4_BIT = (1 << 4),
  SCT_STATE_5_BIT = (1 << 5),
  SCT_STATE_6_BIT = (1 << 6),
  SCT_STATE_7_BIT = (1 << 7),
  SCT_STATE_ALL_BIT = (0xFF),
} SCT_STATE_BIT_T;

typedef enum SCT_STATE_VALUE {
  SCT_STATE_0_VAL = 0,
  SCT_STATE_1_VAL = 1,
  SCT_STATE_2_VAL = 2,
  SCT_STATE_3_VAL = 3,
  SCT_STATE_4_VAL = 4,
  SCT_STATE_5_VAL = 5,
  SCT_STATE_6_VAL = 6,
  SCT_STATE_7_VAL = 7,
} SCT_STATE_VALUE_T;

typedef enum SCT_INPUT_VALUE {
  SCT_INPUT_0_VALUE = 0,
  SCT_INPUT_1_VALUE = 1,
  SCT_INPUT_2_VALUE = 2,
  SCT_INPUT_3_VALUE = 3,
  SCT_INPUT_4_VALUE = 4,
} SCT_INPUT_VALUE_T;

typedef enum SCT_OUTPUT_VALUE {
  SCT_OUTPUT_0_VALUE = 0,
  SCT_OUTPUT_1_VALUE = 1,
  SCT_OUTPUT_2_VALUE = 2,
  SCT_OUTPUT_3_VALUE = 3,
  SCT_OUTPUT_4_VALUE = 4,
  SCT_OUTPUT_5_VALUE = 5,
  SCT_OUTPUT_6_VALUE = 6,
} SCT_OUTPUT_VALUE_T;

#include "nxp/LPC8XX/LPC8XX_sct.h"

#endif
