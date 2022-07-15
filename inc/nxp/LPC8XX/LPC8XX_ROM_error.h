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
LPC800 series common ROM error definition
*/
#ifndef LPC8XX_ROM_ERROR_H
#define LPC8XX_ROM_ERROR_H

/*
Error codes are a 32-bit value with :
- The 16 MSB contains the peripheral code number
- The 16 LSB contains an error code number associated to that peripheral
*/
typedef enum {
  LPC_OK = 0,    /* enum value returned on Successful completion */
  LPC_ERROR = 1, /* enum value returned on general error */

  /* ISP related errors */
  ERR_ISP_BASE = 0x00000000,
  ERR_ISP_INVALID_COMMAND = ERR_ISP_BASE + 1,
  ERR_ISP_SRC_ADDR_ERROR, /* Source address not on word boundary */
  ERR_ISP_DST_ADDR_ERROR, /* Destination address not on word or 256 byte boundary */
  ERR_ISP_SRC_ADDR_NOT_MAPPED,
  ERR_ISP_DST_ADDR_NOT_MAPPED,
  ERR_ISP_COUNT_ERROR, /* Byte count is not multiple of 4 or is not a permitted value */
  ERR_ISP_INVALID_SECTOR,
  ERR_ISP_SECTOR_NOT_BLANK,
  ERR_ISP_SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION,
  ERR_ISP_COMPARE_ERROR,
  ERR_ISP_BUSY,        /* Flash programming hardware interface is busy */
  ERR_ISP_PARAM_ERROR, /* Insufficient number of parameters */
  ERR_ISP_ADDR_ERROR,  /* Address not on word boundary */
  ERR_ISP_ADDR_NOT_MAPPED,
  ERR_ISP_CMD_LOCKED,   /* Command is locked */
  ERR_ISP_INVALID_CODE, /* Unlock code is invalid */
  ERR_ISP_INVALID_BAUD_RATE,
  ERR_ISP_INVALID_STOP_BIT,
  ERR_ISP_CODE_READ_PROTECTION_ENABLED,

  /* I2C related errors */
  ERR_I2C_BASE = 0x00060000,
  ERR_I2C_NAK = ERR_I2C_BASE + 1,       /* NAK */
  ERR_I2C_BUFFER_OVERFLOW,              /* Buffer overflow */
  ERR_I2C_BYTE_COUNT_ERR,               /* Byte count error */
  ERR_I2C_LOSS_OF_ARBRITRATION,         /* Loss of arbitration */
  ERR_I2C_SLAVE_NOT_ADDRESSED,          /* Slave not addressed */
  ERR_I2C_LOSS_OF_ARBRITRATION_NAK_BIT, /* Loss arbritation NAK */
  ERR_I2C_GENERAL_FAILURE,              /* General failure */
  ERR_I2C_REGS_SET_TO_DEFAULT,          /* Set to default */
  ERR_I2C_TIMEOUT,                      /* I2C Timeout */

  /* UART related errors */
  ERR_NO_ERROR = LPC_OK, /* Receive is busy */
  ERR_UART_BASE = 0x00080000,
  ERR_UART_RXD_BUSY = ERR_UART_BASE + 1, /* Receive is busy */
  ERR_UART_TXD_BUSY,                     /* Transmit is busy */
  ERR_UART_OVERRUN_FRAME_PARITY_NOISE,   /* Overrun, Frame, Parity , Receive Noise error */
  ERR_UART_UNDERRUN,                     /* Underrun */
  ERR_UART_PARAM,                        /* Parameter error */
} ErrorCode_t;

#endif