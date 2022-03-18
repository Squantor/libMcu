/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series state configurable timer registers, defines and functions.
*/
#ifndef LPC8XX_SCT_H
#define LPC8XX_SCT_H

static inline void SctConfig(SCT_Type *peripheral, const uint32_t value) {
  peripheral->CONFIG = value & ~SCT_CONFIG_RESERVED;
}

static inline void SctSetConfig(SCT_Type *peripheral, const uint32_t value) {
  peripheral->CONFIG = value | peripheral->CONFIG;
}

static inline void SctClearConfig(SCT_Type *peripheral, const uint32_t value) {
  uint32_t configReg = peripheral->CONFIG & ~(value | SCT_CONFIG_RESERVED);
  peripheral->CONFIG = configReg;
}

static inline void SctControl(SCT_Type *peripheral, const uint32_t value) {
  peripheral->CTRL = value;
}

static inline void SctSetControl(SCT_Type *peripheral, const uint32_t value) {
  uint32_t ctrlReg = peripheral->CTRL | value;
  peripheral->CTRL = ctrlReg;
}

static inline void SctClearControl(SCT_Type *peripheral, const uint32_t value) {
  uint32_t ctrlReg = peripheral->CTRL & ~value;
  peripheral->CTRL = ctrlReg;
}

static inline void SctLimitU(SCT_Type *peripheral, const uint32_t value) {
  peripheral->LIMIT = value;
}

static inline void SctLimitL(SCT_Type *peripheral, const uint16_t value) {
  peripheral->LIMIT_ACCESS16BIT.LIMITL = value;
}

static inline void SctLimitH(SCT_Type *peripheral, const uint16_t value) {
  peripheral->LIMIT_ACCESS16BIT.LIMITH = value;
}

static inline void SctHaltU(SCT_Type *peripheral, const uint32_t value) {
  peripheral->HALT = value;
}

static inline void SctHaltL(SCT_Type *peripheral, const uint16_t value) {
  peripheral->HALT_ACCESS16BIT.HALTL = value;
}

static inline void SctHaltH(SCT_Type *peripheral, const uint16_t value) {
  peripheral->HALT_ACCESS16BIT.HALTH = value;
}

static inline void SctStopU(SCT_Type *peripheral, const uint32_t value) {
  peripheral->STOP = value;
}

static inline void SctStopL(SCT_Type *peripheral, const uint16_t value) {
  peripheral->STOP_ACCESS16BIT.STOPL = value;
}

static inline void SctStopH(SCT_Type *peripheral, const uint16_t value) {
  peripheral->STOP_ACCESS16BIT.STOPH = value;
}

static inline void SctStartU(SCT_Type *peripheral, const uint32_t value) {
  peripheral->START = value;
}

static inline void SctStartL(SCT_Type *peripheral, const uint16_t value) {
  peripheral->START_ACCESS16BIT.STARTL = value;
}

static inline void SctStartH(SCT_Type *peripheral, const uint16_t value) {
  peripheral->START_ACCESS16BIT.STARTH = value;
}

static inline void SctCountU(SCT_Type *peripheral, const uint32_t count) {
  peripheral->COUNT = count;
}

static inline void SctCountL(SCT_Type *peripheral, const uint16_t count) {
  peripheral->COUNT_ACCESS16BIT.COUNTL = count;
}

static inline void SctCountH(SCT_Type *peripheral, const uint16_t count) {
  peripheral->COUNT_ACCESS16BIT.COUNTH = count;
}

static inline void SctRegisterModeU(SCT_Type *peripheral,
                                    const uint32_t value) {
  peripheral->REGMODE = value;
}

static inline void SctRegisterModeL(SCT_Type *peripheral,
                                    const uint16_t value) {
  peripheral->REGMODE_ACCESS16BIT.REGMODEL = value;
}

static inline void SctRegisterModeH(SCT_Type *peripheral,
                                    const uint16_t value) {
  peripheral->REGMODE_ACCESS16BIT.REGMODEH = value;
}

static inline void SctMatchU(SCT_Type *peripheral, const SCT_MATCH_REG_T n,
                             const uint32_t value) {
  peripheral->MATCH[n] = value;
}

static inline void SctMatchL(SCT_Type *peripheral, const SCT_MATCH_REG_T n,
                             const uint16_t value) {
  peripheral->MATCH_ACCESS16BIT[n].MATCHL = value;
}

static inline void SctMatchH(SCT_Type *peripheral, const SCT_MATCH_REG_T n,
                             const uint16_t value) {
  peripheral->MATCH_ACCESS16BIT[n].MATCHH = value;
}

static inline void SctCaptureU(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n,
                               uint32_t *value) {
  *value = peripheral->CAP[n];
}

static inline void SctCaptureL(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n,
                               uint16_t *value) {
  *value = peripheral->CAP_ACCESS16BIT[n].CAPL;
}

static inline void SctCaptureH(SCT_Type *peripheral, const SCT_CAPTURE_REG_T n,
                               uint16_t *value) {
  *value = peripheral->CAP_ACCESS16BIT[n].CAPH;
}

static inline void SctMatchReloadU(SCT_Type *peripheral,
                                   const SCT_MATCH_REG_T n,
                                   const uint32_t value) {
  peripheral->MATCHREL[n] = value;
}

static inline void SctMatchReloadL(SCT_Type *peripheral,
                                   const SCT_MATCH_REG_T n,
                                   const uint16_t value) {
  peripheral->MATCHREL_ACCESS16BIT[n].MATCHRELL = value;
}

static inline void SctMatchReloadH(SCT_Type *peripheral,
                                   const SCT_MATCH_REG_T n,
                                   const uint16_t value) {
  peripheral->MATCHREL_ACCESS16BIT[n].MATCHRELH = value;
}

static inline void SctCaptureControlU(SCT_Type *peripheral,
                                      const SCT_CAPTURE_REG_T n,
                                      const uint32_t value) {
  peripheral->CAPCTRL[n] = value;
}

static inline void SctCaptureControlL(SCT_Type *peripheral,
                                      const SCT_CAPTURE_REG_T n,
                                      const uint16_t value) {
  peripheral->CAPCTRL_ACCESS16BIT[n].CAPCTRLL = value;
}

static inline void SctCaptureControlH(SCT_Type *peripheral,
                                      const SCT_CAPTURE_REG_T n,
                                      const uint16_t value) {
  peripheral->CAPCTRL_ACCESS16BIT[n].CAPCTRLH = value;
}

static inline void SctEventInt(SCT_Type *peripheral, const uint32_t value) {
  peripheral->EVEN = value & ~SCT_EVEN_RESERVED;
}

static inline void SctSetEventInt(SCT_Type *peripheral,
                                  const SCT_EVENT_BIT_T evt) {
  peripheral->EVEN = evt | (peripheral->EVEN & ~SCT_EVEN_RESERVED);
}

static inline void SctClearEventInt(SCT_Type *peripheral,
                                    const SCT_EVENT_BIT_T evt) {
  uint32_t evenRegister = peripheral->EVEN & ~(evt | SCT_EVEN_RESERVED);
  peripheral->EVEN = evenRegister;
}

static inline void SctClearEventFlag(SCT_Type *peripheral,
                                     const SCT_EVENT_BIT_T evt) {
  peripheral->EVFLAG = evt;
}

static inline void SctConflictResolution(SCT_Type *peripheral,
                                         const uint32_t value) {
  peripheral->RES = value;
}

static inline void SctSetEventStateMask(SCT_Type *peripheral,
                                        const SCT_EVENT_VAL_T evt,
                                        const uint32_t stateMask) {
  peripheral->EV[evt].STATE = stateMask;
}

static inline void SctSetEventControl(SCT_Type *peripheral,
                                      const SCT_EVENT_VAL_T evt,
                                      const uint32_t value) {
  peripheral->EV[evt].CTRL = value;
}

static inline void SctOutputSet(SCT_Type *peripheral,
                                const SCT_OUTPUT_VALUE_T output,
                                const uint32_t value) {
  peripheral->OUT[output].SET = value;
}

static inline void SctOutputClear(SCT_Type *peripheral,
                                  const SCT_OUTPUT_VALUE_T output,
                                  const uint32_t value) {
  peripheral->OUT[output].CLR = value;
}

static inline void SctOutput(SCT_Type *peripheral, const uint32_t value) {
  peripheral->OUTPUT = value;
}

static inline void SctOutputDirCtrl(SCT_Type *peripheral,
                                    const uint32_t value) {
  peripheral->OUTPUTDIRCTRL = value;
}

#include "nxp/LPC8XX/LPC8XX_sct_old.h"

#endif