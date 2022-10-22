/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series ADC registers, defines and functions.
 */
#ifndef LPC84X_ADC_H
#define LPC84X_ADC_H

/** ADC - Register Layout Typedef */
typedef volatile struct ADC_Struct {
  uint32_t CTRL; /**< ADC Control register. Contains the clock divide value, resolution selection, sampling time selection, and mode
                    controls., offset: 0x0 */
  uint8_t RESERVED_0[4];
  uint32_t SEQ_CTRL[2]; /**< ADC Conversion Sequence-n control register: Controls triggering and channel selection for conversion
                           sequence-n. Also specifies interrupt mode for sequence-n., array offset: 0x8, array step: 0x4 */
  const uint32_t SEQ_GDAT[2]; /**< ADC Sequence-n Global Data register. This register contains the result of the most recent ADC
                                 conversion performed under sequence-n., array offset: 0x10, array step: 0x4 */
  uint8_t RESERVED_1[8];
  const uint32_t DAT[12]; /**< ADC Channel N Data register. This register contains the result of the most recent conversion
                             completed on channel N., array offset: 0x20, array step: 0x4 */
  uint32_t THR0_LOW;      /**< ADC Low Compare Threshold register 0: Contains the lower threshold level for automatic threshold
                             comparison for any channels linked to threshold pair 0., offset: 0x50 */
  uint32_t THR1_LOW;      /**< ADC Low Compare Threshold register 1: Contains the lower threshold level for automatic threshold
                             comparison for any channels linked to threshold pair 1., offset: 0x54 */
  uint32_t THR0_HIGH;     /**< ADC High Compare Threshold register 0: Contains the upper threshold level for automatic threshold
                             comparison for any channels linked to threshold pair 0., offset: 0x58 */
  uint32_t THR1_HIGH;     /**< ADC High Compare Threshold register 1: Contains the upper threshold level for automatic threshold
                             comparison for any channels linked to threshold pair 1., offset: 0x5C */
  uint32_t CHAN_THRSEL;   /**< ADC Channel-Threshold Select register. Specifies which set of threshold compare registers are to be
                             used for each channel, offset: 0x60 */
  uint32_t INTEN; /**< ADC Interrupt Enable register. This register contains enable bits that enable the sequence-A, sequence-B,
                     threshold compare and data overrun interrupts to be generated., offset: 0x64 */
  uint32_t
    FLAGS;      /**< ADC Flags register. Contains the four interrupt/DMA trigger flags and the individual component overrun and
                   threshold-compare flags. (The overrun bits replicate information stored in the result registers)., offset: 0x68 */
  uint32_t TRM; /**< ADC Startup register., offset: 0x6C */
} ADC_Type;

#endif
