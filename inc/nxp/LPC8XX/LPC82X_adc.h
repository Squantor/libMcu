/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common ADC registers, defines and functions.
*/
#ifndef LPC82X_ADC_H
#define LPC82X_ADC_H

/* Sequence index enumerations, used in various parts of the code for 
register indexing and sequencer selection */
typedef enum {
    ADC_SEQA_IDX,
    ADC_SEQB_IDX
} ADC_SEQ_IDX_T;

typedef struct {                                /* ADCn Structure */
    __IO uint32_t CTRL;                         /* A/D Control Register. The AD0CR register must be written to select the operating mode before A/D conversion can occur. */
    __I  uint32_t RESERVED0;
    __IO uint32_t SEQ_CTRL[ADC_SEQB_IDX + 1];   /* A/D Sequence A & B Control Register. Controls triggering and channel selection for sonversion sequence. */
    __IO uint32_t SEQ_GDAT[ADC_SEQB_IDX + 1];   /* A/D Sequence A & B Global Data Register. Contains the result of the most recent A/D conversion for sequence. */
    __I  uint32_t RESERVED1[2];
    __I  uint32_t DR[12];                       /* A/D Channel Data Register. This register contains the result of the most recent conversion completed on channel n. */
    __IO uint32_t THR_LOW[2];                   /* A/D Low Compare Threshold Register 0 & 1. Contains the lower threshold level for automatic threshold comparison. */
    __IO uint32_t THR_HIGH[2];                  /* A/D High Compare Threshold Register 0 & 1. Contains the higher threshold level for automatic threshold comparison. */
    __IO uint32_t CHAN_THRSEL;                  /* A/D Channel Threshold Select Register. Specifies which set of threshold compare registers to use. */
    __IO uint32_t INTEN;                        /* A/D Interrupt Enable Register. This register contains enable bits that enable sequence-A, sequence-B, threshold compare and overrun interrupts. */
    __IO uint32_t FLAGS;                        /* A/D Flags Register. This register contains interrupt flags. - To be checked */
    __IO uint32_t TRM;                          /* A/D Trim Register. */
} LPC_ADC_T;

#define ADC_MAX_SAMPLE_RATE (30000000u)
#define ADC_CAL_CLOCK       (500000u)

#define ADC_CR_MASK         (0xBFFFFB00)            /**< ADC CTRL register reserved bit mask*/
#define ADC_CR_CLKDIV(n)    ((((n) & 0xFF) << 0))   /**< The APB clock (PCLK) is divided by (this value plus one) to produce the clock for the A/D */
#define ADC_CR_ASYNMODE     (1 << 8)                /**< Asynchronous mode enable bit, undocumented in datasheet */
#define ADC_CR_LPWRMODEEN   (1 << 10)               /**< Low power mode enable bit */
#define ADC_CR_CALMODEEN    (1 << 30)               /**< Self calibration cycle enable bit */


#define ADC_SEQ_CTRL_CHANSEL(n)   (1 << (n))            /* Channel select macro */
#define ADC_SEQ_CTRL_CHANSEL_MASK (0xFFF)               /* Channel select mask */

#define ADC_SEQ_CTRL_HWTRIG_HIGH        (0 << 12)   /**< HW trigger input - Always logic high */
#define ADC_SEQ_CTRL_HWTRIG_PINTRIG0    (1 << 12)   /**< HW trigger input - ADC pin trigger 0, connect via SWM */
#define ADC_SEQ_CTRL_HWTRIG_PINTRIG1    (2 << 12)   /**< HW trigger input - ADC pin trigger 1, connect via SWM */
#define ADC_SEQ_CTRL_HWTRIG_SCT0_OUT3   (3 << 12)   /**< HW trigger input - SCT0 output 3 */
#define ADC_SEQ_CTRL_HWTRIG_ACMP_O      (4 << 12)   /**< HW trigger input - Analog comparator output */
#define ADC_SEQ_CTRL_HWTRIG_ARM_TXEV    (5 << 12)   /**< HW trigger input - ARM core TXEV event */
#define ADC_SEQ_CTRL_HWTRIG_MASK        (0x7 << 12) /**< HW trigger input bitfield mask */

#define ADC_SEQ_CTRL_HWTRIG_POLPOS       (1 << 18)      /* HW trigger polarity - positive edge */
#define ADC_SEQ_CTRL_HWTRIG_SYNCBYPASS   (1 << 19)      /* HW trigger bypass synchronisation */
#define ADC_SEQ_CTRL_START               (1 << 26)      /* Start conversion enable bit */
#define ADC_SEQ_CTRL_BURST               (1 << 27)      /* Repeated conversion enable bit */
#define ADC_SEQ_CTRL_SINGLESTEP          (1 << 28)      /* Single step enable bit */
#define ADC_SEQ_CTRL_LOWPRIO             (1 << 29)      /* High priority enable bit (regardless of name) */
#define ADC_SEQ_CTRL_MODE_EOS            (1 << 30)      /* Mode End of sequence enable bit */
#define ADC_SEQ_CTRL_SEQ_ENA             (1UL << 31)    /* Sequence enable bit */

#define ADC_SEQ_GDAT_RESULT_MASK         (0xFFF << 4)   /* Result value mask */
#define ADC_SEQ_GDAT_RESULT_BITPOS       (4)            /* Result start bit position */
#define ADC_SEQ_GDAT_THCMPRANGE_MASK     (0x3 << 16)    /* Comparion range mask */
#define ADC_SEQ_GDAT_THCMPRANGE_BITPOS   (16)           /* Comparison range bit position */
#define ADC_SEQ_GDAT_THCMPCROSS_MASK     (0x3 << 18)    /* Comparion cross mask */
#define ADC_SEQ_GDAT_THCMPCROSS_BITPOS   (18)           /* Comparison cross bit position */
#define ADC_SEQ_GDAT_CHAN_MASK           (0xF << 26)    /* Channel number mask */
#define ADC_SEQ_GDAT_CHAN_BITPOS         (26)           /* Channel number bit position */
#define ADC_SEQ_GDAT_OVERRUN             (1 << 30)      /* Overrun bit */
#define ADC_SEQ_GDAT_DATAVALID           (1UL << 31)    /* Data valid bit */

#define ADC_DR_RESULT(n)           ((((n) >> 4) & 0xFFF))   /* Macro for getting the ADC data value */
#define ADC_DR_THCMPRANGE_MASK     (0x3 << 16)              /* Comparion range mask */
#define ADC_DR_THCMPRANGE_BITPOS   (16)                     /* Comparison range bit position */
#define ADC_DR_THCMPRANGE(n)       (((n) >> ADC_DR_THCMPRANGE_BITPOS) & 0x3)
#define ADC_DR_THCMPCROSS_MASK     (0x3 << 18)              /* Comparion cross mask */
#define ADC_DR_THCMPCROSS_BITPOS   (18)                     /* Comparison cross bit position */
#define ADC_DR_THCMPCROSS(n)       (((n) >> ADC_DR_THCMPCROSS_BITPOS) & 0x3)
#define ADC_DR_CHAN_MASK           (0xF << 26)              /* Channel number mask */
#define ADC_DR_CHAN_BITPOS         (26)                     /* Channel number bit position */
#define ADC_DR_CHANNEL(n)          (((n) >> ADC_DR_CHAN_BITPOS) & 0xF)    /* Channel number bit position */
#define ADC_DR_OVERRUN             (1 << 30)                /* Overrun bit */
#define ADC_DR_DATAVALID           (1UL << 31)              /* Data valid bit */
#define ADC_DR_DONE(n)             (((n) >> 31))

#define ADC_THR_VAL_MASK            (0xFFF << 4)            /* Threshold value bit mask */
#define ADC_THR_VAL_POS             (4)                     /* Threshold value bit position */

#define ADC_THRSEL_CHAN_SEL_THR1(n) (1 << (n))              /* Select THR1 register for channel n */

#define ADC_INTEN_SEQA_ENABLE       (1 << 0)                /* Sequence A Interrupt enable bit */
#define ADC_INTEN_SEQB_ENABLE       (1 << 1)                /* Sequence B Interrupt enable bit */
#define ADC_INTEN_SEQN_ENABLE(seq)  (1 << (seq))            /* Sequence A/B Interrupt enable bit */
#define ADC_INTEN_OVRRUN_ENABLE     (1 << 2)                /* Overrun Interrupt enable bit */
#define ADC_INTEN_CMP_DISBALE       (0)                     /* Disable comparison interrupt value */
#define ADC_INTEN_CMP_OUTSIDETH     (1)                     /* Outside threshold interrupt value */
#define ADC_INTEN_CMP_CROSSTH       (2)                     /* Crossing threshold interrupt value */
#define ADC_INTEN_CMP_MASK          (3)                     /* Comparison interrupt value mask */
#define ADC_INTEN_CMP_ENABLE(isel, ch) (((isel) & ADC_INTEN_CMP_MASK) << ((2 * (ch)) + 3))    /* Interrupt selection for channel */

#define ADC_FLAGS_THCMP_MASK(ch)    (1 << (ch))             /* Threshold comparison status for channel */
#define ADC_FLAGS_OVRRUN_MASK(ch)   (1 << (12 + (ch)))      /* Overrun status for channel */
#define ADC_FLAGS_SEQA_OVRRUN_MASK  (1 << 24)               /* Seq A Overrun status */
#define ADC_FLAGS_SEQB_OVRRUN_MASK  (1 << 25)               /* Seq B Overrun status */
#define ADC_FLAGS_SEQN_OVRRUN_MASK(seq) (1 << (24 + (seq))) /* Seq A/B Overrun status */
#define ADC_FLAGS_SEQA_INT_MASK     (1 << 28)               /* Seq A Interrupt status */
#define ADC_FLAGS_SEQB_INT_MASK     (1 << 29)               /* Seq B Interrupt status */
#define ADC_FLAGS_SEQN_INT_MASK(seq) (1 << (28 + (seq)))    /* Seq A/B Interrupt status */
#define ADC_FLAGS_THCMP_INT_MASK    (1 << 30)               /* Threshold comparison Interrupt status */
#define ADC_FLAGS_OVRRUN_INT_MASK   (1UL << 31)             /* Overrun Interrupt status */

#define ADC_TRIM_VRANGE_HIGHV       (0 << 5)                /* Voltage range bit - High volatge (2.7V to 3.6V) */
#define ADC_TRIM_VRANGE_LOWV        (1 << 5)                /* Voltage range bit - Low volatge (1.8V to 2.7V) */

#define ADC_CHAN_THRSEL_RES 0xFFFFF000
#define ADC_INTEN_RES       0xF8000000
#define ADC_SEQ_CTRL_RES    ((7 << 15) | (0x3F << 20))

/* 
Example: ADC_Init(LPC_ADC, (ADC_CR_MODE10BIT | ADC_CR_LPWRMODEBIT));
*/
static inline void AdcInit(LPC_ADC_T *pADC, uint32_t flags)
{
    SysctlPowerUp(SYSCTL_SLPWAKE_ADC_PD);
    ClockEnablePeriphClock(SYSCTL_CLOCK_ADC);

    pADC->INTEN = 0;
    pADC->CTRL = ~ADC_CR_MASK & flags;
}

static inline void ADC_DeInit(LPC_ADC_T *pADC)
{
    pADC->INTEN = 0;
    pADC->CTRL = 0;

    ClockDisablePeriphClock(SYSCTL_CLOCK_ADC);
    SysctlPowerDown(SYSCTL_SLPWAKE_ADC_PD);
}


/*
The value is used as a divider to generate the ADC
clock rate from the ADC input clock. The ADC input clock is based
on the system clock. Valid values for this function are from 0 to 255
with 0=divide by 1, 1=divide by 2, 2=divide by 3, etc.<br>
Do not decrement this value by 1.<br>
To set the ADC clock rate to 1MHz, use the following function:<br>
AdcSetDivider(LPC_ADC, (Clock_GetSystemClockRate() / 1000000) - 1);
*/
static inline void AdcSetDivider(LPC_ADC_T *pADC, uint8_t div)
{
    uint32_t temp;

    temp = pADC->CTRL & ~(ADC_CR_MASK);
    pADC->CTRL = temp | (uint32_t) div;
}

/*
When ADC is set to ADC_CR_ASYNMODE this function has no effect. The
rate mentioned in @a rate is the sampling clock rate and not the frequency at
at which the conversion will be done. Example setting at a rate to 30 MHz will
get a sampling rate of 1.2M samples per second.
*/
static inline void AdcSetClockRate(LPC_ADC_T *pADC, uint32_t rate)
{
    AdcSetDivider(pADC, (uint8_t) (ClockGetSystemClockRate() / rate) - 1);
}

/**
 * @brief   Starts the calibration according to the datasheet
 * 
 * Calibration is not done as part of ADC_Init(), but
 * is required after the call to ADC_Init() or after returning
 * from a power-down state. Calibration may alter the ADC_CR_ASYNMODE
 * and ADC_CR_LPWRMODEBIT flags in the CTRL register. Make sure you
 * preset the divider to a 500KHz ADC clock before calling this function!
 * 
 * @param   peripheral  base address of ADC peripheral
 * @return  Nothing
 */

static inline void AdcStartCalibration(LPC_ADC_T *peripheral)
{
    uint32_t temp = peripheral->CTRL;
    temp |= ADC_CR_CALMODEEN;
    temp &= ~ADC_CR_LPWRMODEEN;
    peripheral->CTRL = temp;
}

/**
 * @brief   Returns ADC calibration status
 * @param   peripheral  base address of ADC peripheral
 * @return  true if the calibration is done
 */
static inline bool AdcIsCalibrationDone(LPC_ADC_T *peripheral)
{
    return (peripheral->CTRL & ADC_CR_CALMODEEN) == 0;
}

/*
This function will safely set the ADC sequencer register bits
while maintaining bits 20..25 as 0, regardless of the read state of those bits.
*/
static inline void AdcSetSequencerBits(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex, uint32_t bits)
{
    pADC->SEQ_CTRL[seqIndex] = (pADC->SEQ_CTRL[seqIndex] & ~ADC_SEQ_CTRL_RES) | bits;
}

/*
This function will safely clear the ADC sequencer register bits
while maintaining bits 20..25 as 0, regardless of the read state of those bits.
*/
static inline void AdcClearSequencerBits(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex, uint32_t bits)
{
    pADC->SEQ_CTRL[seqIndex] = pADC->SEQ_CTRL[seqIndex] & ~(ADC_SEQ_CTRL_RES | bits);
}

/*
Sets up sequencer options for a conversion sequence. This function
should be used to setup the selected channels for the sequence, the sequencer
trigger, the trigger polarity, synchronization bypass, priority, and mode. All
options are passed to the functions as a OR'ed list of values. This function will
disable/clear the sequencer start/burst/single step/enable if they are enabled.<br>
Select the channels by OR'ing in one or more ADC_SEQ_CTRL_CHANSEL(ch) values.<br>
Select the hardware trigger by OR'ing in one ADC_SEQ_CTRL_HWTRIG_* value.<br>
Select a positive edge hardware trigger by OR'ing in ADC_SEQ_CTRL_HWTRIG_POLPOS.<br>
Select trigger bypass synchronisation by OR'ing in ADC_SEQ_CTRL_HWTRIG_SYNCBYPASS.<br>
Select ADC single step on trigger/start by OR'ing in ADC_SEQ_CTRL_SINGLESTEP.<br>
Select higher priority conversion on the other sequencer by OR'ing in ADC_SEQ_CTRL_LOWPRIO.<br>
Select end of seqeuence instead of end of conversion interrupt by OR'ing in ADC_SEQ_CTRL_MODE_EOS.<br>
Example for setting up sequencer A (channels 0-2, trigger on high edge of PIO0_2, interrupt on end of sequence):<br>
ADC_SetupSequencer(LPC_ADC, ADC_SEQA_IDX, (
    ADC_SEQ_CTRL_CHANSEL(0) | ADC_SEQ_CTRL_CHANSEL(1) | ADC_SEQ_CTRL_CHANSEL(2) |
    ADC_SEQ_CTRL_HWTRIG_PIO0_2 | ADC_SEQ_CTRL_HWTRIG_POLPOS | ADC_SEQ_CTRL_MODE_EOS));
*/
static inline void AdcSetupSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex, uint32_t options)
{
    pADC->SEQ_CTRL[seqIndex] = options;
}

static inline void AdcEnableSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    AdcSetSequencerBits(pADC, seqIndex, ADC_SEQ_CTRL_SEQ_ENA);
}

static inline void AdcDisableSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    AdcClearSequencerBits(pADC, seqIndex, ADC_SEQ_CTRL_SEQ_ENA);
}

/*
This function sets the START bit for the sequencer to force a
single conversion sequence or a single step conversion.
*/
static inline void AdcStartSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    AdcSetSequencerBits(pADC, seqIndex, ADC_SEQ_CTRL_START);
}

/*
This function sets the BURST bit for the sequencer to force
continuous conversion. Use ADC_StopBurstSequencer() to stop the
ADC burst sequence.
*/
static inline void AdcStartBurstSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    AdcSetSequencerBits(pADC, seqIndex, ADC_SEQ_CTRL_BURST);
}

static inline void AdcStopBurstSequencer(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    AdcClearSequencerBits(pADC, seqIndex, ADC_SEQ_CTRL_BURST);
}

typedef enum {
    ADC_DR_THCMPRANGE_INRANGE,
    ADC_DR_THCMPRANGE_RESERVED,
    ADC_DR_THCMPRANGE_BELOW,
    ADC_DR_THCMPRANGE_ABOVE
} ADC_DR_THCMPRANGE_T;

typedef enum {
    ADC_DR_THCMPCROSS_NOCROSS,
    ADC_DR_THCMPCROSS_RESERVED,
    ADC_DR_THCMPCROSS_DOWNWARD,
    ADC_DR_THCMPCROSS_UPWARD
} ADC_DR_THCMPCROSS_T;

/*
This function returns the raw value of the data register and clears
the overrun and datavalid status for the register. Once this register is read,
the following functions can be used to parse the raw value:<br>
uint32_t adcDataRawValue = ADC_ReadSequencerDataReg(LPC_ADC, ADC_SEQA_IDX); // Get raw value
uint32_t adcDataValue = ADC_DR_RESULT(adcDataRawValue); // Aligned and masked ADC data value
ADC_DR_THCMPRANGE_T adcRange = (ADC_DR_THCMPRANGE_T) ADC_DR_THCMPRANGE(adcDataRawValue); // Sample range compared to threshold low/high
ADC_DR_THCMPCROSS_T adcRange = (ADC_DR_THCMPCROSS_T) ADC_DR_THCMPCROSS(adcDataRawValue); // Sample cross compared to threshold low
uint32_t channel = ADC_DR_CHANNEL(adcDataRawValue); // ADC channel for this sample/data
bool adcDataOverrun = (bool) ((adcDataRawValue & ADC_DR_OVERRUN) != 0); // Data overrun flag
bool adcDataValid = (bool) ((adcDataRawValue & ADC_SEQ_GDAT_DATAVALID) != 0); // Data valid flag
*/
static inline uint32_t AdcGetSequencerDataReg(LPC_ADC_T *pADC, ADC_SEQ_IDX_T seqIndex)
{
    return pADC->SEQ_GDAT[seqIndex];
}

/*
This function returns the raw value of the data register and clears
the overrun and datavalid status for the register. Once this register is read,
the following functions can be used to parse the raw value:<br>
uint32_t adcDataRawValue = ADC_ReadSequencerDataReg(LPC_ADC, ADC_SEQA_IDX); // Get raw value
uint32_t adcDataValue = ADC_DR_RESULT(adcDataRawValue); // Aligned and masked ADC data value
ADC_DR_THCMPRANGE_T adcRange = (ADC_DR_THCMPRANGE_T) ADC_DR_THCMPRANGE(adcDataRawValue); // Sample range compared to threshold low/high
ADC_DR_THCMPCROSS_T adcRange = (ADC_DR_THCMPCROSS_T) ADC_DR_THCMPCROSS(adcDataRawValue); // Sample cross compared to threshold low
uint32_t channel = ADC_DR_CHANNEL(adcDataRawValue); // ADC channel for this sample/data
bool adcDataOverrun = (bool) ((adcDataRawValue & ADC_DR_OVERRUN) != 0); // Data overrun flag
bool adcDataValid = (bool) ((adcDataRawValue & ADC_SEQ_GDAT_DATAVALID) != 0); // Data valid flag
*/
static inline uint32_t AdcGetDataReg(LPC_ADC_T *pADC, uint8_t index)
{
    return pADC->DR[index];
}

static inline void AdcSetThrLowValue(LPC_ADC_T *pADC, uint8_t thrnum, uint16_t value)
{
    pADC->THR_LOW[thrnum] = (((uint32_t) value) << ADC_THR_VAL_POS);
}

static inline void AdcSetThrHighValue(LPC_ADC_T *pADC, uint8_t thrnum, uint16_t value)
{
    pADC->THR_HIGH[thrnum] = (((uint32_t) value) << ADC_THR_VAL_POS);
}

/*
Select multiple channels to use the threshold 0 comparison.
Example:
ADC_SelectTH0Channels(LPC_ADC, (ADC_THRSEL_CHAN_SEL_THR1(1) | ADC_THRSEL_CHAN_SEL_THR1(2))); // Selects channels 1 and 2 for threshold 0
*/
static inline void AdcSelectTH0Channels(LPC_ADC_T *pADC, uint32_t channels)
{
    pADC->CHAN_THRSEL = pADC->CHAN_THRSEL & ~(ADC_CHAN_THRSEL_RES | channels);
}

/*
Select multiple channels to use the 1 threshold comparison.
Example:
ADC_SelectTH1Channels(LPC_ADC, (ADC_THRSEL_CHAN_SEL_THR1(4) | ADC_THRSEL_CHAN_SEL_THR1(5))); // Selects channels 4 and 5 for 1 threshold
*/
static inline void AdcSelectTH1Channels(LPC_ADC_T *pADC, uint32_t channels)
{
    pADC->CHAN_THRSEL = (pADC->CHAN_THRSEL & ~ADC_CHAN_THRSEL_RES) | channels;
}

/*
Select one or more OR'ed values of ADC_INTEN_SEQA_ENABLE,
ADC_INTEN_SEQB_ENABLE, and ADC_INTEN_OVRRUN_ENABLE to enable the
specific ADC interrupts.
*/
static inline void AdcEnableInt(LPC_ADC_T *pADC, uint32_t intMask)
{
    pADC->INTEN = (pADC->INTEN & ~ADC_INTEN_RES) | intMask;
}

/*
Select one or more OR'ed values of ADC_INTEN_SEQA_ENABLE,
ADC_INTEN_SEQB_ENABLE, and ADC_INTEN_OVRRUN_ENABLE to disable the
specific ADC interrupts.
*/
static inline void AdcDisableInt(LPC_ADC_T *pADC, uint32_t intMask)
{
    pADC->INTEN = pADC->INTEN & ~(ADC_INTEN_RES | intMask);
}

typedef enum {
    ADC_INTEN_THCMP_DISABLE,
    ADC_INTEN_THCMP_OUTSIDE,
    ADC_INTEN_THCMP_CROSSING,
} ADC_INTEN_THCMP_T;

static inline void AdcSetThresholdInt(LPC_ADC_T *pADC, uint8_t ch, ADC_INTEN_THCMP_T thInt)
{
    pADC->INTEN = (pADC->INTEN & ~(ADC_INTEN_RES | (3 << (3 + (ch * 2))))) | (thInt << (3 + (ch * 2)));
}

/*
Mask the return value of this function with the ADC_FLAGS_*
definitions to determine the overall ADC interrupt events.
Example:
if (ADC_GetFlags(LPC_ADC) & ADC_FLAGS_THCMP_MASK(3) // Check of threshold comp status for ADC channel 3
*/
static inline uint32_t AdcGetFlags(LPC_ADC_T *pADC)
{
    return pADC->FLAGS;
}

static inline void AdcClearFlags(LPC_ADC_T *pADC, uint32_t flags)
{
    pADC->FLAGS = flags;
}

static inline void AdcSetTrim(LPC_ADC_T *pADC, uint32_t trim)
{
    pADC->TRM = trim;
}


#endif