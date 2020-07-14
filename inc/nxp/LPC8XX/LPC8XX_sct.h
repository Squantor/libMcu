/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/* 
LPC800 series state configurable timer registers, defines and functions.
*/
#ifndef LPC8XX_SCT_H
#define LPC8XX_SCT_H

// TODO put in MCU specific definitions?
#define CONFIG_SCT_nEV   (8)            /* Number of events */
#define CONFIG_SCT_nRG   (8)            /* Number of match/compare registers */
#define CONFIG_SCT_nOU   (6)            /* Number of outputs */

typedef struct {
    __IO uint32_t CONFIG;                /* configuration Register (offset (0x000) */
    union {
        __IO uint32_t CTRL_U;            /* control Register */
        struct {
            __IO uint16_t CTRL_L;
            __IO uint16_t CTRL_H;
        };
    };
    union {
        __IO uint32_t LIMIT_U;            /* limit Register */
        struct {
            __IO uint16_t LIMIT_L;        /* limit register for counter L */
            __IO uint16_t LIMIT_H;        /* limit register for counter H */
        };
    };

    union {
        __IO uint32_t HALT_U;            /* halt Register */
        struct {
            __IO uint16_t HALT_L;        /* halt register for counter L */
            __IO uint16_t HALT_H;        /* halt register for counter H */
        };
    };

    union {
        __IO uint32_t STOP_U;            /* stop Register */
        struct {
            __IO uint16_t STOP_L;        /* stop register for counter L */
            __IO uint16_t STOP_H;        /* stop register for counter H */
        };

    };

    union {
        __IO uint32_t START_U;            /* start Register */
        struct {
            __IO uint16_t START_L;        /* start register for counter L */
            __IO uint16_t START_H;        /* start register for counter H */
        };

    };

    uint32_t RESERVED1[10];                    /* 0x018 - 0x03C reserved */

    union {
        __IO uint32_t COUNT_U;            /* counter register (offset 0x040)*/
        struct {
            __IO uint16_t COUNT_L;        /* counter register for counter L */
            __IO uint16_t COUNT_H;        /* counter register for counter H */
        };
    };

    union {
        __IO uint32_t STATE_U;            /* State register */
        struct {
            __IO uint16_t STATE_L;        /* state register for counter L */
            __IO uint16_t STATE_H;        /* state register for counter H */
        };
    };

    __IO const  uint32_t INPUT;            /* input register */
    union {
        __IO uint32_t REGMODE_U;        /* RegMode register */
        struct {
            __IO uint16_t REGMODE_L;    /* match - capture registers mode register L */
            __IO uint16_t REGMODE_H;    /* match - capture registers mode register H */
        };
    };

    __IO uint32_t OUTPUT;                /* output register */
    __IO uint32_t OUTPUTDIRCTRL;        /* output counter direction Control Register */
    __IO uint32_t RES;                    /* conflict resolution register */
    __IO uint32_t DMAREQ0;                /* DMA0 Request Register */
    __IO uint32_t DMAREQ1;                /* DMA1 Request Register */

    uint32_t RESERVED2[35];                    /* 0x064 - 0x0EC reserved */

    __IO uint32_t EVEN;                    /* event enable register (offset 0x0F0)*/
    __IO uint32_t EVFLAG;                /* event flag register */
    __IO uint32_t CONEN;                /* conflict enable register */
    __IO uint32_t CONFLAG;                /* conflict flag register */
    union {
        __IO union {                    /* ... Match / Capture value */
            uint32_t U;                        /*  MATCH[i].U  Unified 32-bit register */
            struct {
                uint16_t L;                    /*  MATCH[i].L  Access to L value */
                uint16_t H;                    /*  MATCH[i].H  Access to H value */
            };
        } MATCH[CONFIG_SCT_nRG];

        __I union {
            uint32_t U;                        /*  CAP[i].U  Unified 32-bit register */
            struct {
                uint16_t L;                    /*  CAP[i].L  Access to L value */
                uint16_t H;                    /*  CAP[i].H  Access to H value */
            };
        } CAP[CONFIG_SCT_nRG];
    };

    uint32_t RESERVED3[56];                    /* 0x120 - 0x1FC reserved */

    union {
        __IO union {                    /* ...Match Reload / Capture Control value (offset 0x200) */
            uint32_t U;                        /*  MATCHREL[i].U  Unified 32-bit register */
            struct {
                uint16_t L;                    /*  MATCHREL[i].L  Access to L value */
                uint16_t H;                    /*  MATCHREL[i].H  Access to H value */
            };
        } MATCHREL[CONFIG_SCT_nRG];

        __IO union {
            uint32_t U;                        /*  CAPCTRL[i].U  Unified 32-bit register */
            struct {
                uint16_t L;                    /*  CAPCTRL[i].L  Access to L value */
                uint16_t H;                    /*  CAPCTRL[i].H  Access to H value */
            };
        } CAPCTRL[CONFIG_SCT_nRG];
    };

    uint32_t RESERVED4[56];                    /* 0x220 - 0x2FC reserved */

    __IO struct {                        /* EV[i].STATE / EV[i].CTRL (offset 0x300) */
        uint32_t STATE;                        /* Event State Register */
        uint32_t CTRL;                        /* Event Control Register */
    } EV[CONFIG_SCT_nEV];

    uint32_t RESERVED5[112];                /* 0x340 - 0x4FC reserved */

    __IO struct {                        /* OUT[i].SET / OUT[i].CLR  (offset 0x500) */
        uint32_t SET;                        /* Output n Set Register */
        uint32_t CLR;                        /* Output n Clear Register */
    } OUT[CONFIG_SCT_nOU];

} LPC_SCT_T;

/* Reserved bits masks for registers */
#define SCT_CONFIG_RESERVED             0xfff80000
#define SCT_CTRL_RESERVED               ((7<<13)|(7u<<29))
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

#define SCT_CONFIG_16BIT_COUNTER        0x00000000                /* Operate as 2 16-bit counters */
#define SCT_CONFIG_32BIT_COUNTER        0x00000001                /* Operate as 1 32-bit counter */

#define SCT_CONFIG_CLKMODE_BUSCLK       (0x0 << 1)                /* Bus clock */
#define SCT_CONFIG_CLKMODE_SCTCLK       (0x1 << 1)                /* SCT clock */
#define SCT_CONFIG_CLKMODE_INCLK        (0x2 << 1)                /* Input clock selected in CLKSEL field */
#define SCT_CONFIG_CLKMODE_INEDGECLK    (0x3 << 1)                /* Input clock edge selected in CLKSEL field */

#define SCT_CONFIG_NORELOAD_U           (0x1 << 7)                /* Prevent match register reload */
#define SCT_CONFIG_NORELOAD_L           (0x1 << 7)                /* Prevent lower match register reload */
#define SCT_CONFIG_NORELOAD_H           (0x1 << 8)                /* Prevent upper match register reload */

#define SCT_CONFIG_AUTOLIMIT_U          (0x1 << 17)                /* Limits counter(unified) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_L          (0x1 << 17)                /* Limits counter(L) based on MATCH0 */
#define SCT_CONFIG_AUTOLIMIT_H          (0x1 << 18)                /* Limits counter(L) based on MATCH0 */

/*
 * Macro defines for SCT control register
 */
#define COUNTUP_TO_LIMIT_THEN_CLEAR_TO_ZERO     0                /* Direction for low or unified counter */
#define COUNTUP_TO LIMIT_THEN_COUNTDOWN_TO_ZERO 1

#define SCT_CTRL_STOP_L                 (1 << 1)                /* Stop low counter */
#define SCT_CTRL_HALT_L                 (1 << 2)                /* Halt low counter */
#define SCT_CTRL_CLRCTR_L               (1 << 3)                /* Clear low or unified counter */
#define SCT_CTRL_BIDIR_L(x)             (((x) & 0x01) << 4)        /* Bidirectional bit */
#define SCT_CTRL_PRE_L(x)               (((x) & 0xFF) << 5)        /* Prescale clock for low or unified counter */

#define COUNTUP_TO_LIMIT_THEN_CLEAR_TO_ZERO     0                /* Direction for high counter */
#define COUNTUP_TO LIMIT_THEN_COUNTDOWN_TO_ZERO 1
#define SCT_CTRL_STOP_H                 (1 << 17)                /* Stop high counter */
#define SCT_CTRL_HALT_H                 (1 << 18)                /* Halt high counter */
#define SCT_CTRL_CLRCTR_H               (1 << 19)                /* Clear high counter */
#define SCT_CTRL_BIDIR_H(x)             (((x) & 0x01) << 20)
#define SCT_CTRL_PRE_H(x)               (((x) & 0xFF) << 21)    /* Prescale clock for high counter */

/*
 * Macro defines for SCT Conflict resolution register
 */
#define SCT_RES_NOCHANGE                (0)
#define SCT_RES_SET_OUTPUT              (1)
#define SCT_RES_CLEAR_OUTPUT            (2)
#define SCT_RES_TOGGLE_OUTPUT           (3)

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
#define SCT_IOCODN_HIGH             (3)
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
 * SCT Event indexes enum, TODO: move to device specifics
 */
typedef enum SCT_EVENT_VAL {
    SCT_EVT_0_VAL  = 0,    /* Event 0 */
    SCT_EVT_1_VAL  = 1,    /* Event 1 */
    SCT_EVT_2_VAL  = 2,    /* Event 2 */
    SCT_EVT_3_VAL  = 3,    /* Event 3 */
    SCT_EVT_4_VAL  = 4,    /* Event 4 */
    SCT_EVT_5_VAL  = 5,    /* Event 4 */
} SCT_EVENT_VAL_T;

/**
 * SCT Event values enum, TODO: move to device specific sct definitions
 */
typedef enum SCT_EVENT {
    SCT_EVT_0_BIT  = (1 << 0),    /* Event 0 */
    SCT_EVT_1_BIT  = (1 << 1),    /* Event 1 */
    SCT_EVT_2_BIT  = (1 << 2),    /* Event 2 */
    SCT_EVT_3_BIT  = (1 << 3),    /* Event 3 */
    SCT_EVT_4_BIT  = (1 << 4),    /* Event 4 */
    SCT_EVT_5_BIT  = (1 << 5)     /* Event 5 */
} SCT_EVENT_T;

typedef enum SCT_STATE_BIT {
    SCT_STATE_0_BIT = (1 << 0),
    SCT_STATE_1_BIT = (1 << 1),
} SCT_STATE_BIT_T;

typedef enum SCT_STATE_VALUE {
    SCT_STATE_0_VAL = 0,
    SCT_STATE_1_VAL = 1,
} SCT_STATE_VALUE_T;

typedef enum SCT_OUT_VALUE {
    SCT_OUT_0_VALUE = 0,
    SCT_OUT_1_VALUE = 1,
    SCT_OUT_2_VALUE = 2,
    SCT_OUT_3_VALUE = 3,
} SCT_OUT_VALUE_T;

static inline void SctConfig(LPC_SCT_T *pSCT, uint32_t value)
{
    pSCT->CONFIG = value;
}

static inline void SctSetLimitU(LPC_SCT_T *sct, uint32_t value)
{
    sct->LIMIT_U = value;
}

static inline void SctSetLimitL(LPC_SCT_T *sct, uint16_t value)
{
    sct->LIMIT_L = value;
}

static inline void SctSetLimitH(LPC_SCT_T *sct, uint16_t value)
{
    sct->LIMIT_H = value;
}

static inline void SctSetCount(LPC_SCT_T *pSCT, uint32_t count)
{
    pSCT->COUNT_U = count;
}

static inline void SctSetCountL(LPC_SCT_T *pSCT, uint16_t count)
{
    pSCT->COUNT_L = count;
}

static inline void SctSetCountH(LPC_SCT_T *pSCT, uint16_t count)
{
    pSCT->COUNT_H = count;
}

static inline void SctSetMatchCount(LPC_SCT_T *pSCT, SCT_MATCH_REG_T n, uint32_t value)
{
    pSCT->MATCH[n].U = value;
}

static inline void SctSetMatchReload(LPC_SCT_T *pSCT, SCT_MATCH_REG_T n, uint32_t value)
{
    pSCT->MATCHREL[n].U = value;
}

static inline void SctEnableEventInt(LPC_SCT_T *pSCT, SCT_EVENT_T evt)
{
    pSCT->EVEN = evt | (pSCT->EVEN & ~SCT_EVEN_RESERVED);
}

static inline void SctDisableEventInt(LPC_SCT_T *pSCT, SCT_EVENT_T evt)
{
    pSCT->EVEN &= ~(evt | SCT_EVEN_RESERVED);
}

static inline void SctSetEventInt(LPC_SCT_T *sct, uint32_t value)
{
    sct->EVEN = value;
}

static inline void SctClearEventFlag(LPC_SCT_T *pSCT, SCT_EVENT_T evt)
{
    // TODO, is this OR needed here? Writing a one will clear the bit
    pSCT->EVFLAG = evt | (pSCT->EVFLAG & ~SCT_EVFLAG_RESERVED);
}

static inline void SctSetControl(LPC_SCT_T *pSCT, uint32_t value)
{
    pSCT->CTRL_U = value | (pSCT->CTRL_U & ~SCT_CTRL_RESERVED);
}

static inline void SctClearControl(LPC_SCT_T *pSCT, uint32_t value)
{
    pSCT->CTRL_U &= ~(value | SCT_CTRL_RESERVED);
}

static inline void SctSetClrControl(LPC_SCT_T *pSCT, uint32_t value, bool ena)
{
    if(ena == true) 
        SctSetControl(pSCT, value);
    else
        SctClearControl(pSCT, value);
}

static inline void SctSetConflictResolution(LPC_SCT_T *pSCT, uint8_t outnum, uint8_t value)
{
    uint32_t tem;
    
    tem = pSCT->RES & ~((0x03 << (2 * outnum))|SCT_RES_RESERVED);
    pSCT->RES = tem | (value << (2 * outnum));
}

static inline void SctSetEventStateMask(LPC_SCT_T *sct, SCT_EVENT_VAL_T evt, uint32_t stateMask)
{
    sct->EV[evt].STATE = stateMask;
}

static inline void SctSetEventControl(LPC_SCT_T *sct, SCT_EVENT_VAL_T evt, uint32_t value)
{
    sct->EV[evt].CTRL = value;
}

static inline void SctSetOutputSet(LPC_SCT_T *sct, SCT_OUT_VALUE_T output, uint32_t value)
{
    sct->OUT[output].SET = value;
}

static inline void SctSetOutputClear(LPC_SCT_T *sct, SCT_OUT_VALUE_T output, uint32_t value)
{
    sct->OUT[output].CLR = value;
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
static inline void SctInit(LPC_SCT_T *pSCT)
{
    ClockEnablePeriphClock(SYSCTL_CLOCK_SCT);
    SysctlPeriphReset(RESET_SCT);
}

static inline void SctDeInit(LPC_SCT_T *pSCT)
{
    ClockDisablePeriphClock(SYSCTL_CLOCK_SCT);
}
#pragma GCC diagnostic pop

#endif