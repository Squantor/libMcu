/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common windowed watchdog registers, defines and functions.
*/
#ifndef LPC8XX_WWDT_OLD_H
#define LPC8XX_WWDT_OLD_H

static inline void WwdtSetTimeOut(WWDT_Type *pWWDT, uint32_t timeout) {
  pWWDT->TC = timeout;
}

static inline void WwdtFeed(WWDT_Type *pWWDT) {
  pWWDT->FEED = 0xAA;
  pWWDT->FEED = 0x55;
}

static inline void WwdtSetWarning(WWDT_Type *pWWDT, uint32_t timeout) {
  pWWDT->WARNINT = timeout;
}

static inline void WwdtSetWindow(WWDT_Type *pWWDT, uint32_t timeout) {
  pWWDT->WINDOW = timeout;
}

static inline void WwdtSetOption(WWDT_Type *pWWDT, uint32_t options) {
  uint32_t modRegister = options | (pWWDT->MOD & ~WWDT_MOD_RESERVED);
  pWWDT->MOD = modRegister;
}

static inline void WwdtUnsetOption(WWDT_Type *pWWDT, uint32_t options) {
  uint32_t modRegister = pWWDT->MOD & (~options) & WWDT_WDMOD_BITMASK;
  pWWDT->MOD = modRegister;
}

static inline void WwdtStart(WWDT_Type *pWWDT) {
  WwdtSetOption(pWWDT, WWDT_WDMOD_WDEN);
  WwdtFeed(pWWDT);
}

static inline uint32_t WwdtGetStatus(WWDT_Type *pWWDT) { return pWWDT->MOD; }

static inline void WwdtClearStatusFlag(WWDT_Type *pWWDT, uint32_t status) {
  uint32_t modRegister;
  if (status & WWDT_WDMOD_WDTOF)
    modRegister = pWWDT->MOD & (~WWDT_WDMOD_WDTOF) & WWDT_WDMOD_BITMASK;

  if (status & WWDT_WDMOD_WDINT)
    modRegister = WWDT_WDMOD_WDINT | (pWWDT->MOD & ~WWDT_MOD_RESERVED);
  pWWDT->MOD = modRegister;
}

static inline uint32_t WwdtGetCurrentCount(WWDT_Type *pWWDT) {
  return pWWDT->TV;
}

#endif