#ifndef __EEPROM_H__
#define __EEPROM_H__

#include "HardwareProfile.h"
/*!
 * Writes the given buffer to the EEPROM at the specified address.
 *
 * \param[IN] addr EEPROM address to write to
 * \param[IN] buffer Pointer to the buffer to be written.
 * \param[IN] size Size of the buffer to be written.
 * \retval status [SUCCESS, FAIL]
 */
void eepromWriteBuffer( uint16_t addr, uint8_t* pBuf, uint16_t nCount);

/*!
 * Reads the EEPROM at the specified address to the given buffer.
 *
 * \param[IN] addr EEPROM address to read from
 * \param[OUT] buffer Pointer to the buffer to be written with read data.
 * \param[IN] size Size of the buffer to be read.
 * \retval status [SUCCESS, FAIL]
 */
void eepromReadBuffer(uint16_t addr, uint8_t* pBuf, uint16_t nCount);


uint8_t GetRomData(void);

void SaveRomData(void);
#endif // __EEPROM_H__
