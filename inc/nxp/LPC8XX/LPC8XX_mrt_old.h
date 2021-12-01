/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common multi rate timer registers, defines and functions.
*/
#ifndef LPC8XX_MRT_OLD_H
#define LPC8XX_MRT_OLD_H

static inline void MrtInit(void) {
  /* Enable the clock to the register interface */
  ClockEnablePeriphClock(SYSCTL_CLOCK_MRT);

  /* Reset MRT */
  SysctlPeriphReset(RESET_MRT);
}

static inline void MrtDeInit(void) {
  /* Disable the clock to the MRT */
  ClockDisablePeriphClock(SYSCTL_CLOCK_MRT);
}

static inline MRT_CH_Type *MrtGetRegPtr(uint8_t ch) { return MRT_CH(ch); }

static inline uint32_t MrtGetInterval(MRT_CH_Type *pMRT) {
  return pMRT->INTVAL;
}

static inline void MrtSetInterval(MRT_CH_Type *pMRT, uint32_t interval) {
  pMRT->INTVAL = interval;
}

static inline uint32_t MrtGetTimer(MRT_CH_Type *pMRT) { return pMRT->TIMER; }

static inline bool MrtGetEnabled(MRT_CH_Type *pMRT) {
  return (bool)((pMRT->CTRL & MRT_CTRL_INTEN_MASK) != 0);
}

static inline void MrtSetEnabled(MRT_CH_Type *pMRT) {
  pMRT->CTRL = MRT_CTRL_INTEN_MASK | (pMRT->CTRL & ~MRT_CTRL_RESERVED);
}

static inline void MrtSetDisabled(MRT_CH_Type *pMRT) {
  uint32_t ctrlRegister =
      pMRT->CTRL & ~(MRT_CTRL_INTEN_MASK | MRT_CTRL_RESERVED);
  pMRT->CTRL = ctrlRegister;
}

static inline MRT_MODE_T MrtGetMode(MRT_CH_Type *pMRT) {
  return (MRT_MODE_T)(pMRT->CTRL & MRT_CTRL_MODE_MASK);
}

static inline void MrtSetMode(MRT_CH_Type *pMRT, MRT_MODE_T mode) {
  uint32_t ctrlRegister;
  ctrlRegister = pMRT->CTRL & ~(MRT_CTRL_MODE_MASK | MRT_CTRL_RESERVED);
  pMRT->CTRL = ctrlRegister | (uint32_t)mode;
}

static inline bool MrtIsRepeatMode(MRT_CH_Type *pMRT) {
  return ((pMRT->CTRL & MRT_CTRL_MODE_MASK) != 0) ? false : true;
}

static inline bool MrtIsOneShotMode(MRT_CH_Type *pMRT) {
  return ((pMRT->CTRL & MRT_CTRL_MODE_MASK) != 0) ? true : false;
}

static inline bool MrtIntPending(MRT_CH_Type *pMRT) {
  return (bool)((pMRT->STAT & MRT_STAT_INTFLAG) != 0);
}

static inline void MrtIntClear(MRT_CH_Type *pMRT) {
  pMRT->STAT = MRT_STAT_INTFLAG | (pMRT->STAT & ~MRT_STAT_RESERVED);
}

static inline bool MrtRunning(MRT_CH_Type *pMRT) {
  return (bool)((pMRT->STAT & MRT_STAT_RUNNING) != 0);
}

static inline uint8_t MrtGetIdleChannel(void) {
  return (uint8_t)(MRT->IDLE_CH);
}

static inline uint8_t MrtGetIdleChannelShifted(void) {
  return (uint8_t)(MrtGetIdleChannel() >> 4);
}

static inline uint32_t MrtGetIntPending(void) { return MRT->IRQ_FLAG; }

static inline bool MrtGetIntPendingByChannel(uint8_t ch) {
  return (bool)(((MRT->IRQ_FLAG >> ch) & 1) != 0);
}

static inline void MrtClearIntPending(uint32_t mask) { MRT->IRQ_FLAG = mask; }

#endif