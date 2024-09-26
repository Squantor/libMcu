/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 State Configurable Timer register interface
 */
#ifndef LPC84X_SCT_HW_HPP
#define LPC84X_SCT_HW_HPP

namespace libMcuLL::hw::sct {
/**
 * @brief SCT register definitions
 */
struct peripheral {
  volatile std::uint32_t CONFIG;    /**< SCT configuration register */
  union {                           /* */
    struct {                        /* */
      volatile std::uint16_t CTRLL; /**< SCT_CTRLL register */
      volatile std::uint16_t CTRLH; /**< SCT_CTRLH register */
    } CTRL_ACCESS16BIT;             /**< SCT control register split*/
    volatile std::uint32_t CTRL;    /**< SCT control register */
  }; /* */
  union {                            /* */
    struct {                         /* */
      volatile std::uint16_t LIMITL; /**< SCT_LIMITL register */
      volatile std::uint16_t LIMITH; /**< SCT_LIMITH register */
    } LIMIT_ACCESS16BIT;             /**< SCT limit event select register split */
    volatile std::uint32_t LIMIT;    /**< SCT limit event select register */
  }; /* */
  union {                           /* */
    struct {                        /* */
      volatile std::uint16_t HALTL; /**< SCT_HALTL register */
      volatile std::uint16_t HALTH; /**< SCT_HALTH register */
    } HALT_ACCESS16BIT;             /**< SCT halt event select register split */
    volatile std::uint32_t HALT;    /**< SCT halt event select register */
  }; /* */
  union {                           /* */
    struct {                        /* */
      volatile std::uint16_t STOPL; /**< SCT_STOPL register */
      volatile std::uint16_t STOPH; /**< SCT_STOPH register */
    } STOP_ACCESS16BIT;             /**< SCT stop event select register split */
    volatile std::uint32_t STOP;    /**< SCT stop event select register */
  }; /* */
  union {                            /* */
    struct {                         /* */
      volatile std::uint16_t STARTL; /**< SCT_STARTL register */
      volatile std::uint16_t STARTH; /**< SCT_STARTH register */
    } START_ACCESS16BIT;             /**< SCT start event select register split */
    volatile std::uint32_t START;    /**< SCT start event select register */
  }; /* */
  std::uint8_t RESERVED_0[40];       /**< Reserved */
  union {                            /* */
    struct {                         /* */
      volatile std::uint16_t COUNTL; /**< SCT_COUNTL register */
      volatile std::uint16_t COUNTH; /**< SCT_COUNTH register */
    } COUNT_ACCESS16BIT;             /**< SCT counter register split */
    volatile std::uint32_t COUNT;    /**< SCT counter register */
  }; /* */
  union {                            /* */
    struct {                         /* */
      volatile std::uint16_t STATEL; /**< SCT_STATEL register */
      volatile std::uint16_t STATEH; /**< SCT_STATEH register */
    } STATE_ACCESS16BIT;             /**< SCT state register */
    volatile std::uint32_t STATE;    /**< SCT state register */
  }; /* */
  volatile const std::uint32_t INPUT;  /**< SCT input register */
  union {                              /* */
    struct {                           /* */
      volatile std::uint16_t REGMODEL; /**< SCT_REGMODEL register */
      volatile std::uint16_t REGMODEH; /**< SCT_REGMODEH register */
    } REGMODE_ACCESS16BIT;             /**< SCT match/capture mode register */
    volatile std::uint32_t REGMODE;    /**< SCT match/capture mode register */
  }; /* */
  volatile std::uint32_t OUTPUT;        /**< SCT output register */
  volatile std::uint32_t OUTPUTDIRCTRL; /**< SCT output counter direction control register */
  volatile std::uint32_t RES;           /**< SCT conflict resolution register */
  volatile std::uint32_t DMAREQ0;       /**< SCT DMA request 0 register */
  volatile std::uint32_t DMAREQ1;       /**< SCT DMA request 1 register */
  std::uint8_t RESERVED_1[140];         /**< Reserved */
  volatile std::uint32_t EVEN;          /**< SCT event interrupt enable register */
  volatile std::uint32_t EVFLAG;        /**< SCT event flag register */
  volatile std::uint32_t CONEN;         /**< SCT conflict interrupt enable register */
  volatile std::uint32_t CONFLAG;       /**< SCT conflict flag register */
  union {                               /* */
    union {                             /* */
      struct {                          /* */
        volatile std::uint16_t CAPL;    /**< SCT_CAPL register */
        volatile std::uint16_t CAPH;    /**< SCT_CAPH register */
      } CAP_ACCESS16BIT[8];             /**< SCT capture register of capture channel */
      volatile std::uint32_t CAP[8];    /**< SCT capture register of capture channel */
    }; /* */
    union {                            /* */
      struct {                         /* */
        volatile std::uint16_t MATCHL; /**< SCT_MATCHL register */
        volatile std::uint16_t MATCHH; /**< SCT_MATCHH register */
      } MATCH_ACCESS16BIT[8];          /**< SCT match value register of match channels */
      volatile std::uint32_t MATCH[8]; /**< SCT match value register of match channels */
    }; /* */
  }; /* */
  std::uint8_t RESERVED_2[224];          /**< Reserved */
  union {                                /* */
    union {                              /* */
      struct {                           /* */
        volatile std::uint16_t CAPCTRLL; /**< SCT_CAPCTRLL register */
        volatile std::uint16_t CAPCTRLH; /**< SCT_CAPCTRLH register */
      } CAPCTRL_ACCESS16BIT[8];          /**< SCT capture control register */
      volatile std::uint32_t CAPCTRL[8]; /**< SCT capture control register */
    }; /* */
    union {                               /* */
      struct {                            /* */
        volatile std::uint16_t MATCHRELL; /**< SCT_MATCHRELL register */
        volatile std::uint16_t MATCHRELH; /**< SCT_MATCHRELH register */
      } MATCHREL_ACCESS16BIT[8];          /**< SCT match reload value register */
      volatile std::uint32_t MATCHREL[8]; /**< SCT match reload value register */
    }; /* */
  }; /* */
  std::uint8_t RESERVED_3[224];   /**< Reserved */
  struct {                        /* */
    volatile std::uint32_t STATE; /**< SCT event state register 0 */
    volatile std::uint32_t CTRL;  /**< SCT event control register 0 */
  } EV[8];                        /**< Event register */
  std::uint8_t RESERVED_4[448];   /**< Reserved */
  struct {                        /* */
    volatile std::uint32_t SET;   /**< SCT output 0 set register */
    volatile std::uint32_t CLR;   /**< SCT output 0 clear register */
  } OUT[7];                       /**< Output register  */
};
}  // namespace libMcuLL::hw::sct
#endif