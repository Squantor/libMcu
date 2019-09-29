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
LPC800 series common ROM i2c driver functions/definitions
*/
#ifndef LPC8XX_ROM_I2C_H
#define LPC8XX_ROM_I2C_H

/**
 * LPC8xx I2C ROM driver handle structure
 */
typedef void *I2C_HANDLE_T;

/**
 * LPC8xx I2C ROM driver callback function
 */
typedef void  (*I2C_CALLBK_T)(uint32_t err_code, uint32_t n);

/**
 * LPC8xx I2C ROM driver parameter structure
 */
typedef struct I2C_PARAM {
    uint32_t        num_bytes_send;        /*!< No. of bytes to send */
    uint32_t        num_bytes_rec;        /*!< No. of bytes to receive */
    uint8_t         *buffer_ptr_send;    /*!< Pointer to send buffer */
    uint8_t         *buffer_ptr_rec;    /*!< Pointer to receive buffer */
    I2C_CALLBK_T    func_pt;            /*!< Callback function */
    uint8_t         stop_flag;            /*!< Stop flag */
    uint8_t         dummy[3];
} I2C_PARAM_T;

/**
 * LPC8xx I2C ROM driver result structure
 */
typedef struct I2C_RESULT {
    uint32_t n_bytes_sent;    /*!< No. of bytes sent */
    uint32_t n_bytes_recd;    /*!< No. of bytes received */
} I2C_RESULT_T;

/**
 * LPC8xx I2C ROM driver modes enum
 */
typedef enum I2C_MODE {
    IDLE,            /*!< IDLE state */
    MASTER_SEND,    /*!< Master send state */
    MASTER_RECEIVE,    /*!< Master Receive state */
    SLAVE_SEND,        /*!< Slave send state */
    SLAVE_RECEIVE    /*!< Slave receive state */
} I2C_MODE_T;

/**
 * LPC8xx I2C ROM driver APIs structure
 */
typedef struct  I2CD_API {
    /* Interrupt Support Routine */
    void (*i2c_isr_handler)(I2C_HANDLE_T *handle);

    /* MASTER functions */
    ErrorCode_t (*i2c_master_transmit_poll)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_master_receive_poll)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_master_tx_rx_poll)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_master_transmit_intr)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_master_receive_intr)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_master_tx_rx_intr)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);

    /* SLAVE functions */
    ErrorCode_t (*i2c_slave_receive_poll)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_slave_transmit_poll)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_slave_receive_intr)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_slave_transmit_intr)(I2C_HANDLE_T *handle, I2C_PARAM_T *param, I2C_RESULT_T *result);
    ErrorCode_t (*i2c_set_slave_addr)(I2C_HANDLE_T *handle, uint32_t slave_addr_0_3, uint32_t slave_mask_0_3);

    /* OTHER support functions */
    uint32_t        (*i2c_get_mem_size)(void);
    I2C_HANDLE_T *  (*i2c_setup)( uint32_t  i2c_base_addr, uint32_t * start_of_ram);
    ErrorCode_t     (*i2c_set_bitrate)(I2C_HANDLE_T *handle, uint32_t  p_clk_in_hz, uint32_t bitrate_in_bps);
    uint32_t        (*i2c_get_firmware_version)(void);
    I2C_MODE_T (*i2c_get_status)(I2C_HANDLE_T *handle);
    ErrorCode_t     (*i2c_set_timeout)(I2C_HANDLE_T *handle, uint32_t timeout);
} I2CD_API_T;

#endif