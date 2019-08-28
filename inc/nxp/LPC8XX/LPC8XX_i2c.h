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
LPC800 series common I2C bus registers, definitions and functions.
*/
#ifndef LPC8XX_I2C_H
#define LPC8XX_I2C_H

/* I2C register block structure */
typedef struct {                    /* I2C0 Structure         */
    __IO uint32_t CFG;                /* I2C Configuration Register common for Master, Slave and Monitor */
    __IO uint32_t STAT;                /* I2C Status Register common for Master, Slave and Monitor */
    __IO uint32_t INTENSET;            /* I2C Interrupt Enable Set Register common for Master, Slave and Monitor */
    __O  uint32_t INTENCLR;            /* I2C Interrupt Enable Clear Register common for Master, Slave and Monitor */
    __IO uint32_t TIMEOUT;            /* I2C Timeout value Register */
    __IO uint32_t CLKDIV;            /* I2C Clock Divider Register */
    __I  uint32_t INTSTAT;            /* I2C Interrupt Status Register */
    __I  uint32_t RESERVED0;        
    __IO uint32_t MSTCTL;            /* I2C Master Control Register */
    __IO uint32_t MSTTIME;            /* I2C Master Time Register for SCL */
    __IO uint32_t MSTDAT;            /* I2C Master Data Register */
    __I  uint32_t RESERVED1[5];     
    __IO uint32_t SLVCTL;            /* I2C Slave Control Register */
    __IO uint32_t SLVDAT;            /* I2C Slave Data Register */
    __IO uint32_t SLVADR[4];        /* I2C Slave Address Registers */
    __IO uint32_t SLVQUAL0;            /* I2C Slave Address Qualifier 0 Register */
    __I  uint32_t RESERVED2[9];     
    __I  uint32_t MONRXDAT;            /* I2C Monitor Data Register */
} LPC_I2C_T;

/* Reserved bits masks for registers */
#define I2C_CFG_RESERVED            (~0x1f)
#define I2C_STAT_RESERVED           ((1<<5)|(1<<7)|(0xf<<20)|(0x3fu<<26))
#define I2C_INTENSET_RESERVED       ((7<<1)|(1<<5)|(1<<7)|(3<<9)|(7<<12)|(1<<18)|(0xf<<20)|(0x3fu<<26))
#define I2C_INTENCLR_RESERVED       ((7<<1)|(1<<5)|(1<<7)|(3<<9)|(7<<12)|(1<<18)|(0xf<<20)|(0x3fu<<26))
#define I2C_TIMEOUT_RESERVED        0xffff0000
#define I2C_CLKDIV_RESERVED         0xffff0000
#define I2C_INTSTAT_RESERVED        ((7<<1)|(1<<5)|(1<<7)|(3<<9)|(7<<12)|(1<<18)|(0xf<<20)|(0x3fu<<26))
#define I2C_MSTCTL_RESERVED         (~7)
#define I2C_MSTTIME_RESERVED        (~0x7f)
#define I2C_MSTDAT_RESERVED         (~0xff)
#define I2C_SLVCTL_RESERVED         (~3)
#define I2C_SLVDAT_RESERVED         (~0xff)
#define I2C_SLVADR_RESERVED         (~0xff)
#define I2C_SLVQUAL0_RESERVED       (~0xff)

/* I2C Configuration register Bit definition */
#define I2C_CFG_MSTEN               (1 << 0)            /* Master Enable/Disable Bit */
#define I2C_CFG_SLVEN               (1 << 1)            /* Slave Enable/Disable Bit */
#define I2C_CFG_MONEN               (1 << 2)            /* Monitor Enable/Disable Bit */
#define I2C_CFG_TIMEOUTEN           (1 << 3)            /* Timeout Enable/Disable Bit */
#define I2C_CFG_MONCLKSTR           (1 << 4)            /* Monitor Clock Stretching Bit */
#define I2C_CFG_MASK                ((uint32_t) 0x1F)    /* Configuration register Mask */

/* I2C Status register Bit definition */
#define I2C_STAT_MSTPENDING         (1 << 0)            /* Master Pending Status Bit */
#define I2C_STAT_MSTSTATE           (0x7 << 1)            /* Master State Code */
#define I2C_STAT_MSTRARBLOSS        (1 << 4)            /* Master Arbitration Loss Bit */
#define I2C_STAT_MSTSTSTPERR        (1 << 6)            /* Master Start Stop Error Bit */
#define I2C_STAT_SLVPENDING         (1 << 8)            /* Slave Pending Status Bit */
#define I2C_STAT_SLVSTATE           (0x3 << 9)            /* Slave State Code */
#define I2C_STAT_SLVNOTSTR          (1 << 11)            /* Slave not stretching Clock Bit */
#define I2C_STAT_SLVIDX             (0x3 << 12)            /* Slave Address Index */
#define I2C_STAT_SLVSEL             (1 << 14)            /* Slave Selected Bit */
#define I2C_STAT_SLVDESEL           (1 << 15)            /* Slave Deselect Bit */
#define I2C_STAT_MONRDY             (1 << 16)            /* Monitor Ready Bit */
#define I2C_STAT_MONOV              (1 << 17)            /* Monitor Overflow Flag */
#define I2C_STAT_MONACTIVE          (1 << 18)            /* Monitor Active Flag */
#define I2C_STAT_MONIDLE            (1 << 19)            /* Monitor Idle Flag */
#define I2C_STAT_EVENTTIMEOUT       (1 << 24)            /* Event Timeout Interrupt Flag */
#define I2C_STAT_SCLTIMEOUT         (1 << 25)            /* SCL Timeout Interrupt Flag */

#define I2C_STAT_MSTCODE_IDLE       (0)                    /* Master Idle State Code */
#define I2C_STAT_MSTCODE_RXREADY    (1)                    /* Master Receive Ready State Code */
#define I2C_STAT_MSTCODE_TXREADY    (2)                    /* Master Transmit Ready State Code */
#define I2C_STAT_MSTCODE_NACKADR    (3)                    /* Master NACK by slave on address State Code */
#define I2C_STAT_MSTCODE_NACKDAT    (4)                    /* Master NACK by slave on data State Code */

#define I2C_STAT_SLVCODE_ADDR       (0)                    /* Master Idle State Code */
#define I2C_STAT_SLVCODE_RX         (1)                    /* Received data is available Code */
#define I2C_STAT_SLVCODE_TX         (2)                    /* Data can be transmitted Code */

/* I2C Interrupt Enable Set register Bit definition */
#define I2C_INTENSET_MSTPENDING     (1 << 0)            /* Master Pending Interrupt Enable Bit */
#define I2C_INTENSET_MSTRARBLOSS    (1 << 4)            /* Master Arbitration Loss Interrupt Enable Bit */
#define I2C_INTENSET_MSTSTSTPERR    (1 << 6)            /* Master Start Stop Error Interrupt Enable Bit */
#define I2C_INTENSET_SLVPENDING     (1 << 8)            /* Slave Pending Interrupt Enable Bit */
#define I2C_INTENSET_SLVNOTSTR      (1 << 11)            /* Slave not stretching Clock Interrupt Enable Bit */
#define I2C_INTENSET_SLVDESEL       (1 << 15)            /* Slave Deselect Interrupt Enable Bit */
#define I2C_INTENSET_MONRDY         (1 << 16)            /* Monitor Ready Interrupt Enable Bit */
#define I2C_INTENSET_MONOV          (1 << 17)            /* Monitor Overflow Interrupt Enable Bit */
#define I2C_INTENSET_MONIDLE        (1 << 19)            /* Monitor Idle Interrupt Enable Bit */
#define I2C_INTENSET_EVENTTIMEOUT   (1 << 24)            /* Event Timeout Interrupt Enable Bit */
#define I2C_INTENSET_SCLTIMEOUT     (1 << 25)            /* SCL Timeout Interrupt Enable Bit */

/* I2C Interrupt Enable Clear register Bit definition */
#define I2C_INTENCLR_MSTPENDING     (1 << 0)            /* Master Pending Interrupt Clear Bit */
#define I2C_INTENCLR_MSTRARBLOSS    (1 << 4)            /* Master Arbitration Loss Interrupt Clear Bit */
#define I2C_INTENCLR_MSTSTSTPERR    (1 << 6)            /* Master Start Stop Error Interrupt Clear Bit */
#define I2C_INTENCLR_SLVPENDING     (1 << 8)            /* Slave Pending Interrupt Clear Bit */
#define I2C_INTENCLR_SLVNOTSTR      (1 << 11)            /* Slave not stretching Clock Interrupt Clear Bit */
#define I2C_INTENCLR_SLVDESEL       (1 << 15)            /* Slave Deselect Interrupt Clear Bit */
#define I2C_INTENCLR_MONRDY         (1 << 16)            /* Monitor Ready Interrupt Clear Bit */
#define I2C_INTENCLR_MONOV          (1 << 17)            /* Monitor Overflow Interrupt Clear Bit */
#define I2C_INTENCLR_MONIDLE        (1 << 19)            /* Monitor Idle Interrupt Clear Bit */
#define I2C_INTENCLR_EVENTTIMEOUT   (1 << 24)            /* Event Timeout Interrupt Clear Bit */
#define I2C_INTENCLR_SCLTIMEOUT     (1 << 25)            /* SCL Timeout Interrupt Clear Bit */

/* I2C TimeOut Value Macro */
#define I2C_TIMEOUT_VAL(n)          (((uint32_t) ((n) - 1) & 0xFFF0) | 0x000F)    /* Macro for Timeout value register */

/* I2C Interrupt Status register Bit definition */
#define I2C_INTSTAT_MSTPENDING      (1 << 0)            /* Master Pending Interrupt Status Bit */
#define I2C_INTSTAT_MSTRARBLOSS     (1 << 4)            /* Master Arbitration Loss Interrupt Status Bit */
#define I2C_INTSTAT_MSTSTSTPERR     (1 << 6)            /* Master Start Stop Error Interrupt Status Bit */
#define I2C_INTSTAT_SLVPENDING      (1 << 8)            /* Slave Pending Interrupt Status Bit */
#define I2C_INTSTAT_SLVNOTSTR       (1 << 11)            /* Slave not stretching Clock Interrupt Status Bit */
#define I2C_INTSTAT_SLVDESEL        (1 << 15)            /* Slave Deselect Interrupt Status Bit */
#define I2C_INTSTAT_MONRDY          (1 << 16)            /* Monitor Ready Interrupt Status Bit */
#define I2C_INTSTAT_MONOV           (1 << 17)            /* Monitor Overflow Interrupt Status Bit */
#define I2C_INTSTAT_MONIDLE         (1 << 19)            /* Monitor Idle Interrupt Status Bit */
#define I2C_INTSTAT_EVENTTIMEOUT    (1 << 24)            /* Event Timeout Interrupt Status Bit */
#define I2C_INTSTAT_SCLTIMEOUT      (1 << 25)            /* SCL Timeout Interrupt Status Bit */

/* I2C Master Control register Bit definition */
#define I2C_MSTCTL_MSTCONTINUE      (1 << 0)            /* Master Continue Bit */
#define I2C_MSTCTL_MSTSTART         (1 << 1)            /* Master Start Control Bit */
#define I2C_MSTCTL_MSTSTOP          (1 << 2)            /* Master Stop Control Bit */
#define I2C_MSTCTL_MSTDMA           (1 << 3)            /* Master DMA Enable Bit */

/* I2C Master Time Register Field definition */
#define I2C_MSTTIME_MSTSCLLOW       (0x07 << 0)            /* Master SCL Low Time field */
#define I2C_MSTTIME_MSTSCLHIGH      (0x07 << 4)            /* Master SCL High Time field */

/* I2C Master Data Mask */
#define I2C_MSTDAT_DATAMASK         ((uint32_t) 0x00FF << 0)    /* Master data mask */

/* I2C Slave Control register Bit definition */
#define I2C_SLVCTL_SLVCONTINUE      (1 << 0)            /* Slave Continue Bit */
#define I2C_SLVCTL_SLVNACK          (1 << 1)            /* Slave NACK Bit */
#define I2C_SLVCTL_SLVDMA           (1 << 3)            /* Slave DMA Enable Bit */

/* I2C Slave Data Mask */
#define I2C_SLVDAT_DATAMASK         ((uint32_t) 0x00FF << 0)    /* Slave data mask */

/* I2C Slave Address register Bit definition */
#define I2C_SLVADR_SADISABLE        (1 << 0)            /* Slave Address n Disable Bit */
#define I2C_SLVADR_SLVADR           (0x7F << 1)            /* Slave Address field */
#define I2C_SLVADR_MASK             ((uint32_t) 0x00FF)    /* Slave Address Mask */

/* I2C Slave Address Qualifier 0 Register Bit definition */
#define I2C_SLVQUAL_QUALMODE0       (1 << 0)            /* Slave Qualifier Mode Enable Bit */
#define I2C_SLVQUAL_SLVQUAL0        (0x7F << 1)            /* Slave Qualifier Address for Address 0 */

/* I2C Monitor Data Register Bit definition */
#define I2C_MONRXDAT_DATA           (0xFF << 0)            /* Monitor Function Receive Data Field */
#define I2C_MONRXDAT_MONSTART       (1 << 8)            /* Monitor Received Start Bit */
#define I2C_MONRXDAT_MONRESTART     (1 << 9)            /* Monitor Received Repeated Start Bit */
#define I2C_MONRXDAT_MONNACK        (1 << 10)            /* Monitor Received Nack Bit */

static inline void I2C_Init(LPC_I2C_T *pI2C)
{
    Clock_EnablePeriphClock(I2C_GetClockID(pI2C));
    SYSCTL_PeriphReset(I2C_GetResetID(pI2C));    
}

static inline void I2C_DeInit(LPC_I2C_T *pI2C)
{
    Clock_DisablePeriphClock(I2C_GetClockID(pI2C));
}

static inline void I2C_SetClockDiv(LPC_I2C_T *pI2C, uint32_t clkdiv)
{
    if ((clkdiv >= 1) && (clkdiv <= 65536)) {
        pI2C->CLKDIV = clkdiv - 1;
    }
    else {
        pI2C->CLKDIV = 0;
    }
}

static inline uint32_t I2C_GetClockDiv(LPC_I2C_T *pI2C)
{
    return (pI2C->CLKDIV & 0xFFFF) + 1;
}

static inline void I2C_EnableInt(LPC_I2C_T *pI2C, uint32_t intEn)
{
    pI2C->INTENSET = intEn;
}

static inline void I2C_DisableInt(LPC_I2C_T *pI2C, uint32_t intClr)
{
    pI2C->INTENCLR = intClr;
}

static inline void I2C_ClearInt(LPC_I2C_T *pI2C, uint32_t intClr)
{
    I2C_DisableInt(pI2C, intClr);
}

static inline uint32_t I2C_GetPendingInt(LPC_I2C_T *pI2C)
{
    return pI2C->INTSTAT & ~I2C_INTSTAT_RESERVED;
}

#endif