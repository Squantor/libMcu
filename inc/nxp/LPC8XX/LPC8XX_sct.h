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

static inline void SctLimitU(SCT_Type *sct, const uint32_t value) {
  sct->LIMIT_U = value;
}

static inline void SctLimitL(SCT_Type *sct, const uint16_t value) {
  sct->LIMIT_L = value;
}

static inline void SctLimitH(SCT_Type *sct, const uint16_t value) {
  sct->LIMIT_H = value;
}

static inline void SctHaltU(SCT_Type *sct, const uint32_t value) {
  sct->HALT_U = value;
}

static inline void SctHaltL(SCT_Type *sct, const uint16_t value) {
  sct->HALT_L = value;
}

static inline void SctHaltH(SCT_Type *sct, const uint16_t value) {
  sct->HALT_H = value;
}

static inline void SctStopU(SCT_Type *sct, const uint32_t value) {
  sct->STOP_U = value;
}

static inline void SctStopL(SCT_Type *sct, const uint16_t value) {
  sct->STOP_L = value;
}

static inline void SctStopH(SCT_Type *sct, const uint16_t value) {
  sct->STOP_H = value;
}

static inline void SctStartU(SCT_Type *sct, const uint32_t value) {
  sct->START_U = value;
}

static inline void SctStartL(SCT_Type *sct, const uint16_t value) {
  sct->START_L = value;
}

static inline void SctStartH(SCT_Type *sct, const uint16_t value) {
  sct->START_H = value;
}

static inline void SctCountU(SCT_Type *sct, const uint32_t count) {
  sct->COUNT_U = count;
}

static inline void SctCountL(SCT_Type *sct, const uint16_t count) {
  sct->COUNT_L = count;
}

static inline void SctCountH(SCT_Type *sct, const uint16_t count) {
  sct->COUNT_H = count;
}

static inline void SctRegisterModeU(SCT_Type *sct, const uint32_t value) {
  sct->REGMODE_U = value;
}

static inline void SctRegisterModeL(SCT_Type *sct, const uint16_t value) {
  sct->REGMODE_L = value;
}

static inline void SctRegisterModeH(SCT_Type *sct, const uint16_t value) {
  sct->REGMODE_H = value;
}

static inline void SctMatchU(SCT_Type *sct, const SCT_MATCH_REG_T n,
                             const uint32_t value) {
  sct->MATCH[n].U = value;
}

static inline void SctMatchL(SCT_Type *sct, const SCT_MATCH_REG_T n,
                             const uint16_t value) {
  sct->MATCH[n].L = value;
}

static inline void SctMatchH(SCT_Type *sct, const SCT_MATCH_REG_T n,
                             const uint16_t value) {
  sct->MATCH[n].H = value;
}

static inline void SctCaptureU(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                               uint32_t *value) {
  *value = sct->CAP[n].U;
}

static inline void SctCaptureL(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                               uint16_t *value) {
  *value = sct->CAP[n].L;
}

static inline void SctCaptureH(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                               uint16_t *value) {
  *value = sct->CAP[n].H;
}

static inline void SctMatchReloadU(SCT_Type *sct, const SCT_MATCH_REG_T n,
                                   const uint32_t value) {
  sct->MATCHREL[n].U = value;
}

static inline void SctMatchReloadL(SCT_Type *sct, const SCT_MATCH_REG_T n,
                                   const uint16_t value) {
  sct->MATCHREL[n].L = value;
}

static inline void SctMatchReloadH(SCT_Type *sct, const SCT_MATCH_REG_T n,
                                   const uint16_t value) {
  sct->MATCHREL[n].H = value;
}

static inline void SctCaptureControlU(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                                      const uint32_t value) {
  sct->CAPCTRL[n].U = value;
}

static inline void SctCaptureControlL(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                                      const uint16_t value) {
  sct->CAPCTRL[n].L = value;
}

static inline void SctCaptureControlH(SCT_Type *sct, const SCT_CAPTURE_REG_T n,
                                      const uint16_t value) {
  sct->CAPCTRL[n].H = value;
}

static inline void SctEventInt(SCT_Type *sct, const uint32_t value) {
  sct->EVEN = value & ~SCT_EVEN_RESERVED;
}

static inline void SctSetEventInt(SCT_Type *sct, const SCT_EVENT_BIT_T evt) {
  sct->EVEN = evt | (sct->EVEN & ~SCT_EVEN_RESERVED);
}

static inline void SctClearEventInt(SCT_Type *sct, const SCT_EVENT_BIT_T evt) {
  uint32_t evenRegister = sct->EVEN & ~(evt | SCT_EVEN_RESERVED);
  sct->EVEN = evenRegister;
}

static inline void SctClearEventFlag(SCT_Type *sct, const SCT_EVENT_BIT_T evt) {
  sct->EVFLAG = evt;
}

static inline void SctConflictResolution(SCT_Type *sct, const uint32_t value) {
  sct->RES = value;
}

static inline void SctSetEventStateMask(SCT_Type *sct,
                                        const SCT_EVENT_VAL_T evt,
                                        const uint32_t stateMask) {
  sct->EV[evt].STATE = stateMask;
}

static inline void SctSetEventControl(SCT_Type *sct, const SCT_EVENT_VAL_T evt,
                                      const uint32_t value) {
  sct->EV[evt].CTRL = value;
}

static inline void SctOutputSet(SCT_Type *sct, const SCT_OUTPUT_VALUE_T output,
                                const uint32_t value) {
  sct->OUT[output].SET = value;
}

static inline void SctOutputClear(SCT_Type *sct,
                                  const SCT_OUTPUT_VALUE_T output,
                                  const uint32_t value) {
  sct->OUT[output].CLR = value;
}

static inline void SctOutput(SCT_Type *sct, const uint32_t value) {
  sct->OUTPUT = value;
}

static inline void SctOutputDirCtrl(SCT_Type *sct, const uint32_t value) {
  sct->OUTPUTDIRCTRL = value;
}

#include "nxp/LPC8XX/LPC8XX_sct_old.h"

#endif