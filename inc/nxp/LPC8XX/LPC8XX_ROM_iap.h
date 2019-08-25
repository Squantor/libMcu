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
LPC800 series common In application programming ROM functions
*/
#ifndef LPC8XX_ROM_IAP_H
#define LPC8XX_ROM_IAP_H

/* IAP command definitions */
#define IAP_PREWRRITE_CMD           50	/*!< Prepare sector for write operation command */
#define IAP_WRISECTOR_CMD           51	/*!< Write Sector command */
#define IAP_ERSSECTOR_CMD           52	/*!< Erase Sector command */
#define IAP_BLANK_CHECK_SECTOR_CMD  53	/*!< Blank check sector */
#define IAP_REPID_CMD               54	/*!< Read PartID command */
#define IAP_READ_BOOT_CODE_CMD      55	/*!< Read Boot code version */
#define IAP_COMPARE_CMD             56	/*!< Compare two RAM address locations */
#define IAP_REINVOKE_ISP_CMD        57	/*!< Reinvoke ISP */
#define IAP_READ_UID_CMD            58	/*!< Read UID */
#define IAP_ERASE_PAGE_CMD          59	/*!< Erase page */
#define IAP_EEPROM_WRITE            61	/*!< EEPROM Write command */
#define IAP_EEPROM_READ             62	/*!< EEPROM READ command */

/* IAP response definitions */
#define IAP_CMD_SUCCESS             0	/*!< Command is executed successfully */
#define IAP_INVALID_COMMAND         1	/*!< Invalid command */
#define IAP_SRC_ADDR_ERROR          2	/*!< Source address is not on word boundary */
#define IAP_DST_ADDR_ERROR          3	/*!< Destination address is not on a correct boundary */
#define IAP_SRC_ADDR_NOT_MAPPED     4	/*!< Source address is not mapped in the memory map */
#define IAP_DST_ADDR_NOT_MAPPED     5	/*!< Destination address is not mapped in the memory map */
#define IAP_COUNT_ERROR             6	/*!< Byte count is not multiple of 4 or is not a permitted value */
#define IAP_INVALID_SECTOR          7	/*!< Sector number is invalid or end sector number is greater than start sector number */
#define IAP_SECTOR_NOT_BLANK        8	/*!< Sector is not blank */
#define IAP_SECTOR_NOT_PREPARED     9	/*!< Command to prepare sector for write operation was not executed */
#define IAP_COMPARE_ERROR           10	/*!< Source and destination data not equal */
#define IAP_BUSY                    11	/*!< Flash programming hardware interface is busy */
#define IAP_PARAM_ERROR             12	/*!< nsufficient number of parameters or invalid parameter */
#define IAP_ADDR_ERROR              13	/*!< Address is not on word boundary */
#define IAP_ADDR_NOT_MAPPED         14	/*!< Address is not mapped in the memory map */
#define IAP_CMD_LOCKED              15	/*!< Command is locked */
#define IAP_INVALID_CODE            16	/*!< Unlock code is invalid */
#define IAP_INVALID_BAUD_RATE       17	/*!< Invalid baud rate setting */
#define IAP_INVALID_STOP_BIT        18	/*!< Invalid stop bit setting */
#define IAP_CRP_ENABLED             19	/*!< Code read protection enabled */

/* Pointer to ROM IAP entry functions */
#define IAP_ENTRY_LOCATION        0X1FFF1FF1UL

/* IAP_ENTRY API function type */
typedef void (*IAP_ENTRY_T)(uint32_t[], uint32_t[]);

static inline void iap_entry(uint32_t cmd_param[], uint32_t status_result[])
{
    ((IAP_ENTRY_T) IAP_ENTRY_LOCATION)(cmd_param, status_result);
}

/**
 * @brief	Prepare sector for write operation
 * @param	strSector	: Start sector number
 * @param	endSector	: End sector number
 * @return	Status code to indicate the command is executed successfully or not
 * @note	This command must be executed before executing "Copy RAM to flash"
 *			or "Erase Sector" command.
 *			The end sector must be greater than or equal to start sector number
 */
static inline uint8_t Chip_IAP_PreSectorForReadWrite(uint32_t strSector, uint32_t endSector)
{
	uint32_t command[5], result[5];

	command[0] = IAP_PREWRRITE_CMD;
	command[1] = strSector;
	command[2] = endSector;
	iap_entry(command, result);

	return result[0];
}

/**
 * @brief	Copy RAM to flash
 * @param	dstAdd		: Destination FLASH address where data bytes are to be written
 * @param	srcAdd		: Source RAM address where data bytes are to be read
 * @param	byteswrt	: Number of bytes to be written
 * @return	Status code to indicate the command is executed successfully or not
 * @note	The addresses should be a 256 byte boundary and the number of bytes
 *			should be 256 | 512 | 1024 | 4096
 */
uint8_t Chip_IAP_CopyRamToFlash(uint32_t dstAdd, uint32_t *srcAdd, uint32_t byteswrt);

/**
 * @brief	Erase sector
 * @param	strSector	: Start sector number
 * @param	endSector	: End sector number
 * @return	Status code to indicate the command is executed successfully or not
 * @note	The end sector must be greater than or equal to start sector number
 */
uint8_t Chip_IAP_EraseSector(uint32_t strSector, uint32_t endSector);

/**
 * @brief Blank check a sector or multiples sector of on-chip flash memory
 * @param	strSector	: Start sector number
 * @param	endSector	: End sector number
 * @return	Offset of the first non blank word location if the status code is SECTOR_NOT_BLANK
 * @note	The end sector must be greater than or equal to start sector number
 */
// FIXME - There are two return value (result[0] & result[1]
// Result0:Offset of the first non blank word location if the Status Code is
// SECTOR_NOT_BLANK.
// Result1:Contents of non blank word location.
uint8_t Chip_IAP_BlankCheckSector(uint32_t strSector, uint32_t endSector);

/**
 * @brief	Read part identification number
 * @return	Part identification number
 */
uint32_t Chip_IAP_ReadPID(void);

/**
 * @brief	Read boot code version number
 * @return	Boot code version number
 */
uint32_t Chip_IAP_ReadBootCode(void);

/**
 * @brief	Compare the memory contents at two locations
 * @param	dstAdd		: Destination of the RAM address of data bytes to be compared
 * @param	srcAdd		: Source of the RAM address of data bytes to be compared
 * @param	bytescmp	: Number of bytes to be compared
 * @return	Offset of the first mismatch of the status code is COMPARE_ERROR
 * @note	The addresses should be a word boundary and number of bytes should be
 *			a multiply of 4
 */
uint8_t Chip_IAP_Compare(uint32_t dstAdd, uint32_t srcAdd, uint32_t bytescmp);

/**
 * @brief	IAP reinvoke ISP to invoke the bootloader in ISP mode
 * @return	none
 */
uint8_t Chip_IAP_ReinvokeISP(void);

/**
 * @brief	Read the unique ID
 * @return	Status code to indicate the command is executed successfully or not
 */
uint32_t Chip_IAP_ReadUID(uint32_t* uid);

/**
 * @brief	Erase a page or multiple papers of on-chip flash memory
 * @param	strPage	: Start page number
 * @param	endPage	: End page number
 * @return	Status code to indicate the command is executed successfully or not
 * @note	The page number must be greater than or equal to start page number
 */
// FIXME - There are four return value
// Result0:The first 32-bit word (at the lowest address)
// Result1:The second 32-bit word.
// Result2:The third 32-bit word.
// Result3:The fourth 32-bit word.
uint8_t Chip_IAP_ErasePage(uint32_t strPage, uint32_t endPage);

#endif