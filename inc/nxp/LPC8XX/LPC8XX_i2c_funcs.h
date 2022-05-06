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
#ifndef LPC8XX_I2C_FUNCS_H
#define LPC8XX_I2C_FUNCS_H

#define I2C_ADDR_READ (data)(data | 0x01)  /*!< Change address to a read address */
#define I2C_ADDR_WRITE (data)(data & 0xFE) /*!< Change address to a write address */

/**
 * @brief   Set I2C configuration register
 * @param   peripheral  base address of I2C peripheral
 * @param   config      I2C peripheral global configuration
 */
static inline void i2cSetConfiguration(I2C_Type *peripheral, uint32_t config) {
  peripheral->CFG = config & ~I2C_CFG_RESERVED;
}

/**
 * @brief   Get I2C Status register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetStatus(I2C_Type *peripheral) {
  return peripheral->STAT & ~I2C_STAT_RESERVED;
}

/**
 * @brief   Set clock division ratio
 * @param   peripheral  base address of I2C peripheral
 * @param   divider     divider value, 0 is passthrough
 */
static inline void i2cSetClockDivider(I2C_Type *peripheral, uint32_t divider) {
  peripheral->CLKDIV = divider & ~I2C_CLKDIV_RESERVED;
}

/**
 * @brief   Set I2C master control register
 * @param   peripheral  base address of I2C peripheral
 * @param   control     control bits to set for master mode
 */
static inline void i2cSetMasterControl(I2C_Type *peripheral, uint32_t control) {
  peripheral->MSTCTL = control & ~I2C_MSCTL_RESERVED;
}

/**
 * @brief   Set I2C master data register
 * @param   peripheral  base address of I2C peripheral
 * @param   data        data to write to I2C master peripheral
 */
static inline void i2cSetMasterData(I2C_Type *peripheral, uint32_t data) {
  peripheral->MSTDAT = data & ~I2C_MSDAT_RESERVED;
}

/**
 * @brief   Get I2C master data register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetMasterData(I2C_Type *peripheral) {
  return peripheral->MSTDAT & ~I2C_MSDAT_RESERVED;
}

/**
 * @brief   Set I2C slave control register
 * @param   peripheral  base address of I2C peripheral
 * @param   control     control bits to set for slave mode
 */
static inline void i2cSetSlaveControl(I2C_Type *peripheral, uint32_t control) {
  peripheral->SLVCTL = control & ~I2C_SLVCTL_RESERVED;
}

/**
 * @brief   Set I2C slave data register
 * @param   peripheral  base address of I2C peripheral
 * @param   data        data to write to I2C slave peripheral
 */
static inline void i2cSetSlaveData(I2C_Type *peripheral, uint32_t data) {
  peripheral->SLVDAT = data & ~I2C_SLVDAT_RESERVED;
}

/**
 * @brief   Get I2C slave data register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetSlaveData(I2C_Type *peripheral) {
  return peripheral->SLVDAT & ~I2C_SLVDAT_RESERVED;
}

/**
 * @brief   Set I2C slave address match register
 * @param   peripheral  base address of I2C peripheral
 * @param   index       Which match register to set
 * @param   address     I2C address for the slave to respond to
 */
static inline void i2cSetSlaveAddress(I2C_Type *peripheral, I2C_SLVADR_INDEX_Type index, uint32_t address) {
  peripheral->SLVADR[index] = address & ~I2C_SLVADR_RESERVED;
}
#endif