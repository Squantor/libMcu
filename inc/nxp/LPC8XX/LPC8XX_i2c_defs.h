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
LPC800 series common I2C bus registers, defines and functions.
*/
#ifndef LPC8XX_I2C_DEFS_H
#define LPC8XX_I2C_DEFS_H

/** I2C - Register Layout Typedef */
typedef volatile struct {      /*!< I2C0 Structure */
  uint32_t CFG;                /*!< Configuration for shared functions */
  uint32_t STAT;               /*!< Status register for Master, Slave, and Monitor functions */
  uint32_t INTENSET;           /*!< Interrupt Enable Set and read register */
  uint32_t INTENCLR;           /*!< Interrupt Enable Clear register */
  uint32_t TIMEOUT;            /*!< Time-out value register */
  uint32_t CLKDIV;             /*!< Clock pre-divider for the entire I2C interface */
  const uint32_t INTSTAT;      /*!< Interrupt Status register for Master, Slave, and Monitor functions */
  const uint32_t RESERVED0;    /*!< reserved */
  uint32_t MSTCTL;             /*!< Master control register */
  uint32_t MSTTIME;            /*!< Master timing configuration */
  uint32_t MSTDAT;             /*!< Combined Master receiver and transmitter data register */
  const uint32_t RESERVED1[5]; /*!< reserved */
  uint32_t SLVCTL;             /*!< Slave control register */
  uint32_t SLVDAT;             /*!< Combined Slave receiver and transmitter data register */
  uint32_t SLVADR[4];          /*!< Slave address register */
  uint32_t SLVQUAL0;           /*!< Slave Qualification for address 0 */
  const uint32_t RESERVED2[9]; /*!< reserved */
  const uint32_t MONRXDAT;     /*!< Monitor receiver data register */
} I2C_Type;

#define I2C_CFG_RESERVED (0xFFFFFFE0) /*!< I2C configuration register reserved bits */
#define I2C_CFG_MSTEN (1 << 0)        /*!< I2C Master enable */
#define I2C_CFG_SLVEN (1 << 1)        /*!< I2C Slave enable */
#define I2C_CFG_MONEN (1 << 2)        /*!< I2C Monitor enable */
#define I2C_CFG_TIMEOUTEN (1 << 3)    /*!< I2C Timeout enable */
#define I2C_CFG_MONCLKSTR (1 << 4)    /*!< I2C monitor clock stretching enable */

#define I2C_STAT_RESERVED (0xFCF000A0)                /*!< I2C status register reserved bits */
#define I2C_STAT_MSTPENDING (1 << 0)                  /*!< I2C Master pending or idle*/
#define I2C_STAT_MSTSTATE(status) (status & (7 << 1)) /*!< I2C Master status mask macro */
typedef enum {
  I2C_STAT_MSSTATE_IDLE = (0x0 << 1),           /*!< I2C master is in idle state */
  I2C_STAT_MSSTATE_RECEIVE_READY = (0x1 << 1),  /*!< I2C master has received data available */
  I2C_STAT_MSSTATE_TRANSMIT_READY = (0x2 << 1), /*!< I2C master can transmit data */
  I2C_STAT_MSSTATE_NACK_ADDRESS = (0x3 << 1),   /*!< I2C master did not get address acknowledged */
  I2C_STAT_MSSTATE_NACK_DATA = (0x4 << 1),      /*!< I2C master did not get data acknowledged */
} I2C_STAT_MSSTATE_Type;
#define I2C_STAT_MSTARBLOSS (1 << 4)                  /*!< Master lost arbitration */
#define I2C_STAT_MSTSTSTPERR (1 << 6)                 /*!< Master start stop error flag */
#define I2C_STAT_SLVPENDING (1 << 8)                  /*!< Slave pending */
#define I2C_STAT_SLVSTATE(status) (status & (3 << 9)) /*!< I2C Slave status mask macro */
typedef enum {
  I2C_STAT_SLVSTATE_ADDR = (0x0 << 9),     /*!< I2C slave address matched */
  I2C_STAT_SLVSTATE_RECEIVE = (0x1 << 9),  /*!< I2C slave has received data available */
  I2C_STAT_SLVSTATE_TRANSMIT = (0x2 << 9), /*!< I2C slave can transmit data */
} I2C_STAT_SLVSTATE_Type;
#define I2C_STAT_SLVNOTSTR (1 << 11)                 /*!< Slave not clock stretching */
#define I2C_STAT_SLVIDX(status) (status & (3 << 12)) /*!< Slave address match index */
typedef enum {
  I2C_STAT_SLVIDX_ADDR0 = (0x0 << 12), /*!< I2C slave address 0 matched */
  I2C_STAT_SLVIDX_ADDR1 = (0x1 << 12), /*!< I2C slave address 1 matched */
  I2C_STAT_SLVIDX_ADDR2 = (0x2 << 12), /*!< I2C slave address 2 matched */
  I2C_STAT_SLVIDX_ADDR3 = (0x3 << 12), /*!< I2C slave address 3 matched */
} I2C_STAT_SLVIDX_Type;
#define I2C_STAT_SLVSEL (1 << 14)       /*!< Slave selected flag */
#define I2C_STAT_SLVDESEL (1 << 15)     /*!< Slave deselected flag */
#define I2C_STAT_MONRDY (1 << 16)       /*!< Monitor ready flag*/
#define I2C_STAT_MONOV (1 << 17)        /*!< Monitor overflow flag */
#define I2C_STAT_MONACTIVE (1 << 18)    /*!< Monitor bus active flag */
#define I2C_STAT_MONIDLE (1 << 19)      /*!< Monitor bus idle flag */
#define I2C_STAT_EVENTTIMEOUT (1 << 24) /*!< Event timeout flag */
#define I2C_STAT_SCLTIMEOUT (1 << 25)   /*!< SCL timeout flag */

#define I2C_MSCTL_RESERVED (0xFFFFFFF0) /*!< I2C master data register reserved bits */
#define I2C_MSCTL_MSTCONTINUE (1 << 0)  /*!< I2C master continue to next operation */
#define I2C_MSCTL_MSTSTART (1 << 1)     /*!< I2C master generate start condition */
#define I2C_MSCTL_MSTSTOP (1 << 2)      /*!< I2C master generate stop condition */
#define I2C_MSCTL_MSTDMA (1 << 3)       /*!< I2C master DMA generation enable */

#define I2C_MSDAT_RESERVED (0xFFFFFF00) /*!< I2C master data register reserved bits */

#define I2C_CLKDIV_RESERVED (0xFFFF0000) /*!< I2C clock divide register reserved bits */

#define I2C_SLVCTL_RESERVED (0xFFFFFFF4) /*!< I2C slave control register reserved bits */
#define I2C_SLVCTL_SLVCONTINUE (1 << 0)  /*!< I2C slave continue operation */
#define I2C_SLVCTL_SLVNACK (1 << 1)      /*!< I2C slave not acknowledge */
#define I2C_SLVCTL_SLVDMA (1 << 3)       /*!< I2C slave DMA enable */

#define I2C_SLVADR_RESERVED (0xFFFFFF00) /*!< I2C slave address match register reserved bits */
#define I2C_SLVADR_IGNORE (1 << 0)       /*!< I2C slave adress match ignore flag */
typedef enum {
  I2C_SLVADR_0 = 0, /*!< I2C slave address match index 0 */
  I2C_SLVADR_1 = 1, /*!< I2C slave address match index 1 */
  I2C_SLVADR_2 = 2, /*!< I2C slave address match index 2 */
  I2C_SLVADR_3 = 3, /*!< I2C slave address match index 3 */
} I2C_SLVADR_INDEX_Type;

#define I2C_SLVDAT_RESERVED (0xFFFFFF00) /*!< I2C slave data register reserved bits */

#endif