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
LPC800 series common multi rate timer registers,definitions and 
functions.
*/
#ifndef LPC8XX_MRT_H
#define LPC8XX_MRT_H

/**
 * @brief LPC8xx MRT chip configuration
 */
#define MRT_CHANNELS_NUM      (4)
#define MRT_NO_IDLE_CHANNEL   (0x40)

/**
 * @brief MRT register block structure
 */
typedef struct {
	__IO uint32_t INTVAL;	/*!< Timer interval register */
	__O  uint32_t TIMER;	/*!< Timer register */
	__IO uint32_t CTRL;		/*!< Timer control register */
	__IO uint32_t STAT;		/*!< Timer status register */
} LPC_MRT_CH_T;

/**
 * @brief MRT register block structure
 */
typedef struct {
	LPC_MRT_CH_T CHANNEL[MRT_CHANNELS_NUM];
	uint32_t unused[45];
	__O  uint32_t IDLE_CH;
	__IO uint32_t IRQ_FLAG;
} LPC_MRT_T;

/* Reserved bits masks for registers */
#define MRT_CTRL_RESERVED   (~7)
#define MRT_STAT_RESERVED   (~3)

/**
 * @brief MRT Interrupt Modes enum
 */
typedef enum MRT_MODE {
	MRT_MODE_REPEAT =  (0 << 1),	/*!< MRT Repeat interrupt mode */
	MRT_MODE_ONESHOT = (1 << 1)		/*!< MRT One-shot interrupt mode */
} MRT_MODE_T;

/**
 * @brief MRT register bit fields & masks
 */
/* MRT Time interval register bit fields */
#define MRT_INTVAL_IVALUE        (0x7FFFFFFFUL)	/* Maximum interval load value and mask */
#define MRT_INTVAL_LOAD          (0x80000000UL)	/* Force immediate load of timer interval register bit */

/* MRT Control register bit fields & masks */
#define MRT_CTRL_INTEN_MASK      (0x01)
#define MRT_CTRL_MODE_MASK       (0x06)

/* MRT Status register bit fields & masks */
#define MRT_STAT_INTFLAG         (0x01)
#define MRT_STAT_RUNNING         (0x02)

/* Pointer to individual MR register blocks */
#define LPC_MRT_CH0         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[0])
#define LPC_MRT_CH1         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[1])
#define LPC_MRT_CH2         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[2])
#define LPC_MRT_CH3         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[3])
#define LPC_MRT_CH(ch)      ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[(ch)])

/* Global interrupt flag register interrupt mask/clear values */
#define MRT0_INTFLAG        (1)
#define MRT1_INTFLAG        (2)
#define MRT2_INTFLAG        (4)
#define MRT3_INTFLAG        (8)
#define MRTn_INTFLAG(ch)    (1 << (ch))

/**
 * @brief	Initializes the MRT
 * @return	Nothing
 */
static inline void Chip_MRT_Init(void)
{
	/* Enable the clock to the register interface */
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_MRT);

	/* Reset MRT */
	Chip_SYSCTL_PeriphReset(RESET_MRT);
}

/**
 * @brief	De-initializes the MRT Channel
 * @return	Nothing
 */
static inline void Chip_MRT_DeInit(void)
{
	/* Disable the clock to the MRT */
	Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_MRT);
}

/**
 * @brief	Returns a pointer to the register block for a MRT channel
 * @param	ch	: MRT channel tog et register block for (0..3)
 * @return	Pointer to the MRT register block for the channel
 */
static inline LPC_MRT_CH_T *Chip_MRT_GetRegPtr(uint8_t ch)
{
	return LPC_MRT_CH(ch);
}

/**
 * @brief	Returns the timer time interval value
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	Timer time interval value (IVALUE)
 */
static inline uint32_t Chip_MRT_GetInterval(LPC_MRT_CH_T *pMRT)
{
	return pMRT->INTVAL;
}

/**
 * @brief	Sets the timer time interval value
 * @param	pMRT	 : Pointer to selected MRT Channel
 * @param   interval : The interval timeout (31-bits)
 * @return	Nothing
 * @note	Setting bit 31 in timer time interval register causes the time interval value
 * to load immediately, otherwise the time interval value will be loaded in
 * next timer cycle.<br>
 * Example: Chip_MRT_SetInterval(pMRT, 0x500 | MRT_INTVAL_LOAD); // Will load timer interval immediately<br>
 * Example: Chip_MRT_SetInterval(pMRT, 0x500); // Will load timer interval after internal expires
 */
static inline void Chip_MRT_SetInterval(LPC_MRT_CH_T *pMRT, uint32_t interval)
{
	pMRT->INTVAL = interval;
}

/**
 * @brief	Returns the current timer value
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	The current timer value
 */
static inline uint32_t Chip_MRT_GetTimer(LPC_MRT_CH_T *pMRT)
{
	return pMRT->TIMER;
}

/**
 * @brief	Returns true if the timer is enabled
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	True if enabled, Flase if not enabled
 */
static inline bool Chip_MRT_GetEnabled(LPC_MRT_CH_T *pMRT)
{
	return (bool) ((pMRT->CTRL & MRT_CTRL_INTEN_MASK) != 0);
}

/**
 * @brief	Enables the timer
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	Nothing
 */
static inline void Chip_MRT_SetEnabled(LPC_MRT_CH_T *pMRT)
{
	pMRT->CTRL = MRT_CTRL_INTEN_MASK | (pMRT->CTRL & ~MRT_CTRL_RESERVED);
}

/**
 * @brief	Disables the timer
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	Nothing
 */
static inline void Chip_MRT_SetDisabled(LPC_MRT_CH_T *pMRT)
{
	pMRT->CTRL &= ~(MRT_CTRL_INTEN_MASK | MRT_CTRL_RESERVED);
}

/**
 * @brief	Returns the timer mode (repeat or one-shot)
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	The current timer mode
 */
static inline MRT_MODE_T Chip_MRT_GetMode(LPC_MRT_CH_T *pMRT)
{
	return (MRT_MODE_T) (pMRT->CTRL & MRT_CTRL_MODE_MASK);
}

/**
 * @brief	Sets the timer mode (repeat or one-shot)
 * @param	pMRT	: Pointer to selected MRT Channel
 * @param   mode    : Timer mode
 * @return	Nothing
 */
static inline void Chip_MRT_SetMode(LPC_MRT_CH_T *pMRT, MRT_MODE_T mode)
{
	uint32_t reg;

	reg = pMRT->CTRL & ~(MRT_CTRL_MODE_MASK | MRT_CTRL_RESERVED);
	pMRT->CTRL = reg | (uint32_t) mode;
}

/**
 * @brief	Check if the timer is configured in repeat mode
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	True if in repeat mode, False if in one-shot mode
 */
static inline bool Chip_MRT_IsRepeatMode(LPC_MRT_CH_T *pMRT)
{
	return ((pMRT->CTRL & MRT_CTRL_MODE_MASK) != 0) ? false : true;
}

/**
 * @brief	Check if the timer is configured in one-shot mode
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	True if in one-shot mode, False if in repeat mode
 */
static inline bool Chip_MRT_IsOneShotMode(LPC_MRT_CH_T *pMRT)
{
	return ((pMRT->CTRL & MRT_CTRL_MODE_MASK) != 0) ? true : false;
}

/**
 * @brief	Check if the timer has an interrupt pending
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	True if interrupt is pending, False if no interrupt is pending
 */
static inline bool Chip_MRT_IntPending(LPC_MRT_CH_T *pMRT)
{
	return (bool) ((pMRT->STAT & MRT_STAT_INTFLAG) != 0);
}

/**
 * @brief	Clears the pending interrupt (if any)
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	Nothing
 */
static inline void Chip_MRT_IntClear(LPC_MRT_CH_T *pMRT)
{
	pMRT->STAT = MRT_STAT_INTFLAG | (pMRT->STAT & ~MRT_STAT_RESERVED);
}

/**
 * @brief	Check if the timer is running
 * @param	pMRT	: Pointer to selected MRT Channel
 * @return	True if running, False if stopped
 */
static inline bool Chip_MRT_Running(LPC_MRT_CH_T *pMRT)
{
	return (bool) ((pMRT->STAT & MRT_STAT_RUNNING) != 0);
}

/**
 * @brief	Returns the IDLE channel value
 * @return	IDLE channel value (unshifted in bits 7..4)
 */
static inline uint8_t Chip_MRT_GetIdleChannel(void)
{
	return (uint8_t) (LPC_MRT->IDLE_CH);
}

/**
 * @brief	Returns the IDLE channel value
 * @return	IDLE channel value (shifted in bits 3..0)
 */
static inline uint8_t Chip_MRT_GetIdleChannelShifted(void)
{
	return (uint8_t) (Chip_MRT_GetIdleChannel() >> 4);
}

/**
 * @brief	Returns the interrupt pending status for all MRT channels
 * @return	IRQ pending channel bitfield(bit 0 = MRT0, bit 1 = MRT1, etc.)
 */
static inline uint32_t Chip_MRT_GetIntPending(void)
{
	return LPC_MRT->IRQ_FLAG;
}

/**
 * @brief	Returns the interrupt pending status for a singel MRT channel
 * @param	ch	: Channel to check pending interrupt status for
 * @return	IRQ pending channel number
 */
static inline bool Chip_MRT_GetIntPendingByChannel(uint8_t ch)
{
	return (bool) (((LPC_MRT->IRQ_FLAG >> ch) & 1) != 0);
}

/**
 * @brief	Clears the interrupt pending status for one or more MRT channels
 * @param	mask	: Channels to clear (bit 0 = MRT0, bit 1 = MRT1, etc.)
 * @return	Nothing
 * @note	Use this function to clear multiple interrupt pending states in
 * a single call via the IRQ_FLAG register. Performs the same function for
 * all MRT channels in a single call as the Chip_MRT_IntClear() does for a
 * single channel.
 */
static inline void Chip_MRT_ClearIntPending(uint32_t mask)
{
	LPC_MRT->IRQ_FLAG = mask;
}

#endif