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

/** Error code returned by Boot ROM drivers/library functions
*
*  Error codes are a 32-bit value with :
*      - The 16 MSB contains the peripheral code number
*      - The 16 LSB contains an error code number associated to that peripheral
*
*/
typedef enum
{
  LPC_OK = 0,		/* enum value returned on Successful completion */
  LPC_ERROR = 1,			/* enum value returned on general error */

  /* ISP related errors */
  ERR_ISP_BASE = 0x00000000,
  ERR_ISP_INVALID_COMMAND = ERR_ISP_BASE + 1,
  ERR_ISP_SRC_ADDR_ERROR,			/*!< Source address not on word boundary */
  ERR_ISP_DST_ADDR_ERROR,			/*!< Destination address not on word or 256 byte boundary */
  /**\b 0x00000004*/ ERR_ISP_SRC_ADDR_NOT_MAPPED,
  /**\b 0x00000005*/ ERR_ISP_DST_ADDR_NOT_MAPPED,
  /**\b 0x00000006*/ ERR_ISP_COUNT_ERROR,				/*!< Byte count is not multiple of 4 or is not a permitted value */
  /**\b 0x00000007*/ ERR_ISP_INVALID_SECTOR,
  /**\b 0x00000008*/ ERR_ISP_SECTOR_NOT_BLANK,
  /**\b 0x00000009*/ ERR_ISP_SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION,
  /**\b 0x0000000A*/ ERR_ISP_COMPARE_ERROR,
  /**\b 0x0000000B*/ ERR_ISP_BUSY,						/*!< Flash programming hardware interface is busy */
  /**\b 0x0000000C*/ ERR_ISP_PARAM_ERROR,				/*!< Insufficient number of parameters */
  /**\b 0x0000000D*/ ERR_ISP_ADDR_ERROR,				/*!< Address not on word boundary */
  /**\b 0x0000000E*/ ERR_ISP_ADDR_NOT_MAPPED,
  /**\b 0x0000000F*/ ERR_ISP_CMD_LOCKED,				/*!< Command is locked */
  /**\b 0x00000010*/ ERR_ISP_INVALID_CODE,				/*!< Unlock code is invalid */
  /**\b 0x00000011*/ ERR_ISP_INVALID_BAUD_RATE,
  /**\b 0x00000012*/ ERR_ISP_INVALID_STOP_BIT,
  /**\b 0x00000013*/ ERR_ISP_CODE_READ_PROTECTION_ENABLED,

  /* I2C related errors */
  ERR_I2C_BASE = 0x00060000,
  /**\b 0x00060001*/ ERR_I2C_NAK = ERR_I2C_BASE + 1,		/*!< NAK */
  /**\b 0x00060002*/ ERR_I2C_BUFFER_OVERFLOW,				/*!< Buffer overflow */
  /**\b 0x00060003*/ ERR_I2C_BYTE_COUNT_ERR,				/*!< Byte count error */
  /**\b 0x00060004*/ ERR_I2C_LOSS_OF_ARBRITRATION,			/*!< Loss of arbitration */
  /**\b 0x00060005*/ ERR_I2C_SLAVE_NOT_ADDRESSED,			/*!< Slave not addressed */
  /**\b 0x00060006*/ ERR_I2C_LOSS_OF_ARBRITRATION_NAK_BIT,	/*!< Loss arbritation NAK */
  /**\b 0x00060007*/ ERR_I2C_GENERAL_FAILURE,				/*!< General failure */
  /**\b 0x00060008*/ ERR_I2C_REGS_SET_TO_DEFAULT,			/*!< Set to default */
  /**\b 0x00060009*/ ERR_I2C_TIMEOUT,						/*!< I2C Timeout */

  /* UART related errors */
  /**\b 0x00080001*/ ERR_NO_ERROR = LPC_OK,					/*!< Receive is busy */
  ERR_UART_BASE = 0x00080000,
  /**\b 0x00080001*/ ERR_UART_RXD_BUSY = ERR_UART_BASE + 1,	/*!< Receive is busy */
  /**\b 0x00080002*/ ERR_UART_TXD_BUSY,						/*!< Transmit is busy */
  /**\b 0x00080003*/ ERR_UART_OVERRUN_FRAME_PARITY_NOISE,	/*!< Overrun, Frame, Parity , Receive Noise error */
  /**\b 0x00080004*/ ERR_UART_UNDERRUN,						/*!< Underrun */
  /**\b 0x00080005*/ ERR_UART_PARAM,						/*!< Parameter error */
} ErrorCode_t;

#endif