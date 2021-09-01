/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series State configurable timer registers, defines and functions.
 */
#ifndef LPC84X_SCT_H
#define LPC84X_SCT_H

/** SCT - Register Layout Typedef */
typedef volatile struct SCT_Struct {
    uint32_t CONFIG;                    /**< SCT configuration register, offset: 0x0 */
    union {                             /* offset: 0x4 */
        struct {                        /* offset: 0x4 */
            uint16_t CTRLL;             /**< SCT_CTRLL register, offset: 0x4 */
            uint16_t CTRLH;             /**< SCT_CTRLH register, offset: 0x6 */
        } CTRL_ACCESS16BIT;
        uint32_t CTRL;                  /**< SCT control register, offset: 0x4 */
    };
    union {                             /* offset: 0x8 */
        struct {                        /* offset: 0x8 */
            int16_t LIMITL;             /**< SCT_LIMITL register, offset: 0x8 */
            uint16_t LIMITH;            /**< SCT_LIMITH register, offset: 0xA */
        } LIMIT_ACCESS16BIT;
        uint32_t LIMIT;                 /**< SCT limit event select register, offset: 0x8 */
    };
    union {                             /* offset: 0xC */
        struct {                        /* offset: 0xC */
            uint16_t HALTL;             /**< SCT_HALTL register, offset: 0xC */
            uint16_t HALTH;             /**< SCT_HALTH register, offset: 0xE */
        } HALT_ACCESS16BIT;
        uint32_t HALT;                  /**< SCT halt event select register, offset: 0xC */
    };
    union {                             /* offset: 0x10 */
        struct {                        /* offset: 0x10 */
            uint16_t STOPL;             /**< SCT_STOPL register, offset: 0x10 */
            uint16_t STOPH;             /**< SCT_STOPH register, offset: 0x12 */
        } STOP_ACCESS16BIT;
        uint32_t STOP;                  /**< SCT stop event select register, offset: 0x10 */
    };
    union {                             /* offset: 0x14 */
        struct {                        /* offset: 0x14 */
            uint16_t STARTL;            /**< SCT_STARTL register, offset: 0x14 */
            uint16_t STARTH;            /**< SCT_STARTH register, offset: 0x16 */
        } START_ACCESS16BIT;
        uint32_t START;                 /**< SCT start event select register, offset: 0x14 */
    };
    uint8_t RESERVED_0[40];
    union {                             /* offset: 0x40 */
        struct {                        /* offset: 0x40 */
            uint16_t COUNTL;            /**< SCT_COUNTL register, offset: 0x40 */
            uint16_t COUNTH;            /**< SCT_COUNTH register, offset: 0x42 */
        } COUNT_ACCESS16BIT;
        uint32_t COUNT;                 /**< SCT counter register, offset: 0x40 */
    };
    union {                             /* offset: 0x44 */
        struct {                        /* offset: 0x44 */
            uint16_t STATEL;            /**< SCT_STATEL register, offset: 0x44 */
            uint16_t STATEH;            /**< SCT_STATEH register, offset: 0x46 */
        } STATE_ACCESS16BIT;
        uint32_t STATE;                 /**< SCT state register, offset: 0x44 */
    };
    uint32_t INPUT;                     /**< SCT input register, offset: 0x48 */
    union {                             /* offset: 0x4C */
        struct {                        /* offset: 0x4C */
            uint16_t REGMODEL;          /**< SCT_REGMODEL register, offset: 0x4C */
            uint16_t REGMODEH;          /**< SCT_REGMODEH register, offset: 0x4E */
        } REGMODE_ACCESS16BIT;
        uint32_t REGMODE;               /**< SCT match/capture mode register, offset: 0x4C */
    };
    uint32_t OUTPUT;                    /**< SCT output register, offset: 0x50 */
    uint32_t OUTPUTDIRCTRL;             /**< SCT output counter direction control register, offset: 0x54 */
    uint32_t RES;                       /**< SCT conflict resolution register, offset: 0x58 */
    uint32_t DMAREQ0;                   /**< SCT DMA request 0 register, offset: 0x5C */
    uint32_t DMAREQ1;                   /**< SCT DMA request 1 register, offset: 0x60 */
    uint8_t RESERVED_1[140];
    uint32_t EVEN;                      /**< SCT event interrupt enable register, offset: 0xF0 */
    uint32_t EVFLAG;                    /**< SCT event flag register, offset: 0xF4 */
    uint32_t CONEN;                     /**< SCT conflict interrupt enable register, offset: 0xF8 */
    uint32_t CONFLAG;                   /**< SCT conflict flag register, offset: 0xFC */
    union {                             /* offset: 0x100 */
        union {                         /* offset: 0x100, array step: 0x4 */
            struct {                    /* offset: 0x100, array step: 0x4 */
                uint16_t CAPL;          /**< SCT_CAPL register, array offset: 0x100, array step: 0x4 */
                uint16_t CAPH;          /**< SCT_CAPH register, array offset: 0x102, array step: 0x4 */
            } CAP_ACCESS16BIT[8];
            uint32_t CAP[8];            /**< SCT capture register of capture channel, array offset: 0x100, array step: 0x4 */
        };
        union {                         /* offset: 0x100, array step: 0x4 */
            struct {                    /* offset: 0x100, array step: 0x4 */
                uint16_t MATCHL;        /**< SCT_MATCHL register, array offset: 0x100, array step: 0x4 */
                uint16_t MATCHH;        /**< SCT_MATCHH register, array offset: 0x102, array step: 0x4 */
            } MATCH_ACCESS16BIT[8];
            uint32_t MATCH[8];          /**< SCT match value register of match channels, array offset: 0x100, array step: 0x4 */
        };
    };
    uint8_t RESERVED_2[224];
    union {                             /* offset: 0x200 */
        union {                         /* offset: 0x200, array step: 0x4 */
            struct {                    /* offset: 0x200, array step: 0x4 */
                uint16_t CAPCTRLL;      /**< SCT_CAPCTRLL register, array offset: 0x200, array step: 0x4 */
                uint16_t CAPCTRLH;      /**< SCT_CAPCTRLH register, array offset: 0x202, array step: 0x4 */
            } CAPCTRL_ACCESS16BIT[8];
            uint32_t CAPCTRL[8];        /**< SCT capture control register, array offset: 0x200, array step: 0x4 */
        };
    union {                             /* offset: 0x200, array step: 0x4 */
        struct {                        /* offset: 0x200, array step: 0x4 */
            uint16_t MATCHRELL;         /**< SCT_MATCHRELL register, array offset: 0x200, array step: 0x4 */
            uint16_t MATCHRELH;         /**< SCT_MATCHRELH register, array offset: 0x202, array step: 0x4 */
        } MATCHREL_ACCESS16BIT[8];
        uint32_t MATCHREL[8];           /**< SCT match reload value register, array offset: 0x200, array step: 0x4 */
        };
    };
    uint8_t RESERVED_3[224];
    struct {                            /* offset: 0x300, array step: 0x8 */
        uint32_t STATE;                 /**< SCT event state register 0, array offset: 0x300, array step: 0x8 */
        uint32_t CTRL;                  /**< SCT event control register 0, array offset: 0x304, array step: 0x8 */
    } EV[8];
    uint8_t RESERVED_4[448];
    struct {                            /* offset: 0x500, array step: 0x8 */
        uint32_t SET;                   /**< SCT output 0 set register, array offset: 0x500, array step: 0x8 */
        uint32_t CLR;                   /**< SCT output 0 clear register, array offset: 0x504, array step: 0x8 */
    } OUT[7];
} SCT_Type;

/* Reserved bits masks for registers */

#define SCT_LIMIT_RESERVED              (~(0x3f|(0x3f<<16))
#define SCT_HALT_RESERVED               (~(0x3f|(0x3f<<16))
#define SCT_STOP_RESERVED               (~(0x3f|(0x3f<<16))
#define SCT_START_RESERVED              (~(0x3f|(0x3f<<16))
#define SCT_STATE_RESERVED              (~(0x1f|(0x1f<<16))
#define SCT_INPUT_RESERVED              (~(0xf|(0xf<<16))
#define SCT_REGMODE_RESERVED            (~(0x1f|(0x1f<<16))
#define SCT_OUTPUT_RESERVED             (~0xf)
#define SCT_OUTPUTDIRCTRL_RESERVED      (~0xff)
#define SCT_RES_RESERVED                (~0xff)
#define SCT_EVEN_RESERVED               (~0x3f)
#define SCT_EVFLAG_RESERVED             (~0x3f)
#define SCT_CONEN_RESERVED              (~0xf)
#define SCT_CONFLAG_RESERVED            (~(0xf|(3u<<30)))
#define SCT_CAPCTRL_RESERVED            (~(0x3f|(0x3f<<16)))
#define SCT_EVn_STATE_RESERVED          (~3)
#define SCT_EVn_CTRL_RESERVED           (0xff800000)
#define SCT_OUTn_SET_RESERVED           (~0x3f)
#define SCT_OUTn_CLR_RESERVED           (~0x3f)

/*
 * Macro defines for SCT configuration register
 */
#define SCT_CONFIG_RESERVED             (0xFFF9E000)    /*!< Reserved bits of SCT config register */
#define SCT_CONFIG_16BIT_COUNTER        (0x0 << 0)      /*!< Operate as 2 16-bit counters */
#define SCT_CONFIG_32BIT_COUNTER        (0x1 << 0)      /*!< Operate as 1 32-bit counter */
#define SCT_CONFIG_CLKMODE_SYSTEM       (0x0 << 1)      /*!< System clock mode */
#define SCT_CONFIG_CLKMODE_SAMPLED      (0x1 << 1)      /*!< Sampled clock mode */
#define SCT_CONFIG_CLKMODE_INCLK        (0x2 << 1)      /*!< SCTimer/PWM input clock mode */
#define SCT_CONFIG_CLKMODE_ASYNC        (0x3 << 1)      /*!< Asynchronous clock mode */
typedef enum {
    SCT_CONFIG_CKSEL_RISE_IN0   = 0x0,  /*!< Rising edges on input0 */
    SCT_CONFIG_CKSEL_FALL_IN0   = 0x1,  /*!< Falling edges on input0 */
    SCT_CONFIG_CKSEL_RISE_IN1   = 0x0,  /*!< Rising edges on input1 */
    SCT_CONFIG_CKSEL_FALL_IN1   = 0x1,  /*!< Falling edges on input1 */
    SCT_CONFIG_CKSEL_RISE_IN2   = 0x0,  /*!< Rising edges on input2 */
    SCT_CONFIG_CKSEL_FALL_IN2   = 0x1,  /*!< Falling edges on input2 */
    SCT_CONFIG_CKSEL_RISE_IN3   = 0x0,  /*!< Rising edges on input3 */
    SCT_CONFIG_CKSEL_FALL_IN3   = 0x1,  /*!< Falling edges on input3 */
    SCT_CONFIG_CKSEL_RISE_IN4   = 0x0,  /*!< Rising edges on input4. Clock selected by SYSCON SCTCLKSEL */
    SCT_CONFIG_CKSEL_FALL_IN4   = 0x1,  /*!< Falling edges on input4. Clock selected by SYSCON SCTCLKSEL */
} SCT_CONFIG_CKSEL_Type;
#define SCT_CONFIG_CKSEL(clock)         ((clock) << 3)  /*!< input to select for the clock mode */
#define SCT_CONFIG_NORELOAD_U           (0x1 << 7)      /*!< Prevent match register reload */
#define SCT_CONFIG_NORELOAD_L           (0x1 << 7)      /*!< Prevent lower match register reload */
#define SCT_CONFIG_NORELOAD_H           (0x1 << 8)      /*!< Prevent upper match register reload */
#define SCT_CONFIG_INSYNC_IN0           (1u << 9)       /*!< Enable input synchronizer for input 0 */
#define SCT_CONFIG_INSYNC_IN1           (1u << 10)      /*!< Enable input synchronizer for input 1 */
#define SCT_CONFIG_INSYNC_IN2           (1u << 11)      /*!< Enable input synchronizer for input 2 */
#define SCT_CONFIG_INSYNC_IN3           (1u << 12)      /*!< Enable input synchronizer for input 3 */
#define SCT_CONFIG_AUTOLIMIT_U          (0x1 << 17)     /*!< Limits counter(unified) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_L          (0x1 << 17)     /*!< Limits counter(L) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_H          (0x1 << 18)     /*!< Limits counter(L) based on MATCH0 */

/*
 * Macro defines for SCT control register
 */
#define SCT_CTRL_RESERVED               (0xE000E000)    /*!< Reserved bits of SCT Control register */
#define SCT_CTRL_L_RESERVED             (0xE000)        /*!< Reserved bits of Lower SCT Control register */
#define SCT_CTRL_H_RESERVED             (0xE000)        /*!< Reserved bits of Higher SCT Control register */

#define SCT_CTRL_STOP_U                 (1 << 1)                /*!< Stop counter */
#define SCT_CTRL_STOP_L                 (1 << 1)                /*!< Stop low counter */
#define SCT_CTRL_HALT_U                 (1 << 2)                /*!< Halt counter */
#define SCT_CTRL_HALT_L                 (1 << 2)                /*!< Halt low counter */
#define SCT_CTRL_CLRCTR_U               (1 << 3)                /*!< Clear unified counter */
#define SCT_CTRL_CLRCTR_L               (1 << 3)                /*!< Clear low counter */
#define SCT_CTRL_BIDIR_U                (1 << 4)                /*!< Unified counter bidirectional counting */
#define SCT_CTRL_BIDIR_L                (1 << 4)                /*!< Low counter bidirectional counting */
#define SCT_CTRL_PRE_U(x)               (((x) & 0xFF) << 5)     /*!< Prescale clock for unified counter */
#define SCT_CTRL_PRE_L(x)               (((x) & 0xFF) << 5)     /*!< Prescale clock for low counter */

#define SCT_CTRL_STOP_H                 (1 << 17)               /*!< Stop high counter */
#define SCT_CTRL_HALT_H                 (1 << 18)               /*!< Halt high counter */
#define SCT_CTRL_CLRCTR_H               (1 << 19)               /*!< Clear high counter */
#define SCT_CTRL_BIDIR_H(x)             (((x) & 0x01) << 20)    /*!< High counter bidirectional counting */
#define SCT_CTRL_PRE_H(x)               (((x) & 0xFF) << 21)    /*!< Prescale clock for high counter */

/*
 * Defines for the SCT event control register
 */
#define SCT_EV_CTRL_MATCHSEL(x)     (((x) & 0x0F) << 0)
#define SCT_EV_CTRL_H_EVENT         (1 << 4)
#define SCT_EV_CTRL_INSEL           (0 << 5)
#define SCT_EV_CTRL_OUTSEL          (1 << 5)
#define SCT_EV_CTRL_IOSEL(x)        (((x) & 0x0F) << 6)
#define SCT_IOCOND_LOW              (0)
#define SCT_IOCOND_RISE             (1)
#define SCT_IOCOND_FALL             (2)
#define SCT_IOCOND_HIGH             (3)
#define SCT_EV_CTRL_IOCOND(x)       (((x) & 0x03) << 10)
#define SCT_COMBMODE_OR             (0)
#define SCT_COMBMODE_MATCH          (1)
#define SCT_COMBMODE_IO             (2)
#define SCT_COMBMODE_AND            (3)
#define SCT_EV_CTRL_COMBMODE(x)     (((x) & 0x03) << 12)
#define SCT_EV_CTRL_STATELD_ADD     (0 << 14)
#define SCT_EV_CTRL_STATELD_LOAD    (1 << 14)
#define SCT_EV_CTRL_STATEV(x)       (((x) & 0x1F) << 15)
#define SCT_EV_CTRL_MATCHMEM        (1<<20)
#define SCT_EV_CTRL_DIRECTION_IND   (0)
#define SCT_EV_CTRL_DIRECTION_UP    (1)
#define SCT_EV_CTRL_DIRECTION_DOWN  (2)
#define SCT_EV_CTRL_DIRECTION(x)    (((x) & 0x03) << 21)

/**
Definitions for the Match/Compare mode register
 */
#define SCT_REGMODE_MATCH   (0)
#define SCT_REGMODE_CAPTURE (1)
#define SCT_REGMODE_U(n,x)  ((x) << (n))
#define SCT_REGMODE_L(n,x)  ((x) << (n))
#define SCT_REGMODE_H(n,x)  ((x) << ((n) + 15))


/*
Definitions for the output conflict resolution register
 */
#define SCT_CONFLICTRES_NONE    (0)
#define SCT_CONFLICTRES_SET     (1)
#define SCT_CONFLICTRES_CLEAR   (2)
#define SCT_CONFLICTRES_TOGGLE  (3)
#define SCT_CONFLICTRES(n,x)    ((x) << ((n) * 2))

/*
Definitions for the output direction control register
*/
#define SCT_OUTPUTDIRCTRL_ANY   (0) /* Any, set and clear do not depend on counter */
#define SCT_OUTPUTDIRCTRL_L     (1) /* L counting down, set and clear are reversed when L is counting down */
#define SCT_OUTPUTDIRCTRL_H     (2) /* H counting down, set and clear are reversed when H is counting down */
#define SCT_OUTPUTDIRCTRL(n,x)  ((x) << ((n) * 2))  /* set output direction control for channel n */

/*
Definitions for the SCT output register
*/
#define SCT_OUTPUT_STATE(n,x)   ((x) << (n))

/**
 * SCT Match register values enum, TODO: move to device specifics
 */
typedef enum SCT_MATCH_REG {
    SCT_MATCH_0 = 0,    /* SCT Match register 0 */
    SCT_MATCH_1 = 1,    /* SCT Match register 1 */
    SCT_MATCH_2 = 2,    /* SCT Match register 2 */
    SCT_MATCH_3 = 3,    /* SCT Match register 3 */
    SCT_MATCH_4 = 4     /* SCT Match register 4 */
} SCT_MATCH_REG_T;

/**
 * SCT Capture register values enum, TODO: move to device specifics
 */
typedef enum SCT_CAPTURE_REG {
    SCT_CAPTURE_0 = 0,    /** SCT capture register 0 */
    SCT_CAPTURE_1 = 1,    /** SCT capture register 1 */
    SCT_CAPTURE_2 = 2,    /** SCT capture register 2 */
    SCT_CAPTURE_3 = 3,    /** SCT capture register 3 */
    SCT_CAPTURE_4 = 4     /** SCT capture register 4 */
} SCT_CAPTURE_REG_T;

/**
 * SCT Event indexes enum, TODO: move to device specifics
 */
typedef enum SCT_EVENT_VAL {
    SCT_EVENT_0_VAL  = 0,    /* Event 0 */
    SCT_EVENT_1_VAL  = 1,    /* Event 1 */
    SCT_EVENT_2_VAL  = 2,    /* Event 2 */
    SCT_EVENT_3_VAL  = 3,    /* Event 3 */
    SCT_EVENT_4_VAL  = 4,    /* Event 4 */
    SCT_EVENT_5_VAL  = 5,    /* Event 4 */
} SCT_EVENT_VAL_T;

/**
 * SCT Event values enum, TODO: move to device specific sct definitions
 */
typedef enum SCT_EVENT_BIT {
    SCT_EVENT_0_BIT  = (1 << 0),    /* Event 0 */
    SCT_EVENT_1_BIT  = (1 << 1),    /* Event 1 */
    SCT_EVENT_2_BIT  = (1 << 2),    /* Event 2 */
    SCT_EVENT_3_BIT  = (1 << 3),    /* Event 3 */
    SCT_EVENT_4_BIT  = (1 << 4),    /* Event 4 */
    SCT_EVENT_5_BIT  = (1 << 5)     /* Event 5 */
} SCT_EVENT_BIT_T;

typedef enum SCT_STATE_BIT {
    SCT_STATE_0_BIT = (1 << 0),
    SCT_STATE_1_BIT = (1 << 1),
} SCT_STATE_BIT_T;

typedef enum SCT_STATE_VALUE {
    SCT_STATE_0_VAL = 0,
    SCT_STATE_1_VAL = 1,
} SCT_STATE_VALUE_T;

typedef enum SCT_INPUT_VALUE {
    SCT_INPUT_0_VALUE = 0,
    SCT_INPUT_1_VALUE = 1,
    SCT_INPUT_2_VALUE = 2,
    SCT_INPUT_3_VALUE = 3,
} SCT_INPUT_VALUE_T;

typedef enum SCT_OUTPUT_VALUE {
    SCT_OUTPUT_0_VALUE = 0,
    SCT_OUTPUT_1_VALUE = 1,
    SCT_OUTPUT_2_VALUE = 2,
    SCT_OUTPUT_3_VALUE = 3,
} SCT_OUTPUT_VALUE_T;

static inline void SctConfig(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->CONFIG = value & ~SCT_CONFIG_RESERVED;
}

static inline void SctSetConfig(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->CONFIG = value | peripheral->CONFIG;
}

static inline void SctClearConfig(SCT_Type *peripheral, const uint32_t value)
{
    uint32_t configReg = peripheral->CONFIG & ~(value | SCT_CONFIG_RESERVED);
    peripheral->CONFIG = configReg;
}

static inline void SctControl(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->CTRL = value;
}

static inline void SctSetControl(SCT_Type *peripheral, const uint32_t value)
{
    uint32_t ctrlReg = peripheral->CTRL | value;
    peripheral->CTRL = ctrlReg;
}

static inline void SctClearControl(SCT_Type *peripheral, const uint32_t value)
{
    uint32_t ctrlReg = peripheral->CTRL & ~value;
    peripheral->CTRL = ctrlReg;
}

static inline void SctLimitU(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->LIMIT = value;
}

static inline void SctLimitL(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->LIMIT_ACCESS16BIT.LIMITL = value;
}

static inline void SctLimitH(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->LIMIT_ACCESS16BIT.LIMITH = value;
}

static inline void SctHaltU(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->HALT = value;
}

static inline void SctHaltL(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->HALT_ACCESS16BIT.HALTL = value;
}

static inline void SctHaltH(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->HALT_ACCESS16BIT.HALTH = value;
}

static inline void SctStopU(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->STOP = value;
}

static inline void SctStopL(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->STOP_ACCESS16BIT.STOPL = value;
}

static inline void SctStopH(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->STOP_ACCESS16BIT.STOPH = value;
}

static inline void SctStartU(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->START = value;
}

static inline void SctStartL(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->START_ACCESS16BIT.STARTL = value;
}

static inline void SctStartH(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->START_ACCESS16BIT.STARTH = value;
}

static inline void SctCountU(SCT_Type *peripheral, const uint32_t count)
{
    peripheral->COUNT = count;
}

static inline void SctCountL(SCT_Type *peripheral, const uint16_t count)
{
    peripheral->COUNT_ACCESS16BIT.COUNTL = count;
}

static inline void SctCountH(SCT_Type *peripheral, const uint16_t count)
{
    peripheral->COUNT_ACCESS16BIT.COUNTH = count;
}

static inline void SctRegisterModeU(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->REGMODE = value;
}

static inline void SctRegisterModeL(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->REGMODE_ACCESS16BIT.REGMODEL = value;
}

static inline void SctRegisterModeH(SCT_Type *peripheral, const uint16_t value)
{
    peripheral->REGMODE_ACCESS16BIT.REGMODEH = value;
}

static inline void SctMatchU(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint32_t value)
{
    peripheral->MATCH[n] = value;
}

static inline void SctMatchL(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint16_t value)
{
    peripheral->MATCH_ACCESS16BIT[n].MATCHL = value;
}

static inline void SctMatchH(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint16_t value)
{
    peripheral->MATCH_ACCESS16BIT[n].MATCHH = value;
}

static inline void SctCaptureU(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, uint32_t *value)
{
    *value = peripheral->CAP[n];
}

static inline void SctCaptureL(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, uint16_t *value)
{
    *value = peripheral->CAP_ACCESS16BIT[n].CAPL;
}

static inline void SctCaptureH(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, uint16_t *value)
{
    *value = peripheral->CAP_ACCESS16BIT[n].CAPH;
}

static inline void SctMatchReloadU(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint32_t value)
{
    peripheral->MATCHREL[n] = value;
}

static inline void SctMatchReloadL(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint16_t value)
{
    peripheral->MATCHREL_ACCESS16BIT[n].MATCHRELL = value;
}

static inline void SctMatchReloadH(SCT_Type *peripheral, const SCT_MATCH_REG_T n, const uint16_t value)
{
    peripheral->MATCHREL_ACCESS16BIT[n].MATCHRELH = value;
}

static inline void SctCaptureControlU(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, const uint32_t value)
{
    peripheral->CAPCTRL[n] = value;
}

static inline void SctCaptureControlL(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, const uint16_t value)
{
    peripheral->CAPCTRL_ACCESS16BIT[n].CAPCTRLL = value;
}

static inline void SctCaptureControlH(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n, const uint16_t value)
{
    peripheral->CAPCTRL_ACCESS16BIT[n].CAPCTRLH = value;
}

static inline void SctEventInt(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->EVEN = value & ~SCT_EVEN_RESERVED;
}

static inline void SctSetEventInt(SCT_Type *peripheral, const SCT_EVENT_BIT_T evt)
{
    peripheral->EVEN = evt | (peripheral->EVEN & ~SCT_EVEN_RESERVED);
}

static inline void SctClearEventInt(SCT_Type *peripheral, const SCT_EVENT_BIT_T evt)
{
    uint32_t evenRegister = peripheral->EVEN & ~(evt | SCT_EVEN_RESERVED);
    peripheral->EVEN = evenRegister;
}

static inline void SctClearEventFlag(SCT_Type *peripheral, const SCT_EVENT_BIT_T evt)
{
    peripheral->EVFLAG = evt;
}

static inline void SctConflictResolution(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->RES = value;
}

static inline void SctSetEventStateMask(SCT_Type *peripheral, const SCT_EVENT_VAL_T evt, const uint32_t stateMask)
{
    peripheral->EV[evt].STATE = stateMask;
}

static inline void SctSetEventControl(SCT_Type *peripheral, const SCT_EVENT_VAL_T evt, const uint32_t value)
{
    peripheral->EV[evt].CTRL = value;
}

static inline void SctOutputSet(SCT_Type *peripheral, const SCT_OUTPUT_VALUE_T output, const uint32_t value)
{
    peripheral->OUT[output].SET = value;
}

static inline void SctOutputClear(SCT_Type *peripheral, const SCT_OUTPUT_VALUE_T output, const uint32_t value)
{
    peripheral->OUT[output].CLR = value;
}

static inline void SctOutput(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->OUTPUT = value;
}

static inline void SctOutputDirCtrl(SCT_Type *peripheral, const uint32_t value)
{
    peripheral->OUTPUTDIRCTRL = value;
}

#endif
