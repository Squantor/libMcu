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
typedef volatile  struct {
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

#endif
