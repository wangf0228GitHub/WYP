#include "eeprom.h"

void eepromWriteBuffer( uint16_t addr, uint8_t* pBuf, uint16_t nCount)
{
	FLASH_SetProgrammingTime(FLASH_ProgramTime_Standard);
	FLASH_Unlock(FLASH_MemType_Data);
	while (nCount != 0)
	{
		nCount--;
		FLASH_ProgramByte(addr, *pBuf);
		addr++;
		pBuf++;
	}
	FLASH_Lock(FLASH_MemType_Data);
}

void eepromReadBuffer(uint16_t addr, uint8_t* pBuf, uint16_t nCount)
{
	while (nCount != 0)
	{
		nCount--;
		*pBuf= *(uint8_t *)addr;
		addr++;
		pBuf++;
	}
}
uint8_t GetRomData(void)
{
	uint8_t i;
	eepromReadBuffer(ROMParamStartAddr, ROMParams.All, ROMCount);
	i = GetVerify_Sum(&ROMParams.All[1], ROMCount - 1);
	i = i + ROMVerifySumOffset;
	if (i == ROMParams.sum)//存储区校验成功
	{
		//PickDatas.StateBits.bWinter=ROMParams.SystemState.bWinter;
		return 1;
	}
	else
		return 0;
}
void SaveRomData(void)
{
	ROMParams.sum = GetVerify_Sum(&ROMParams.All[1], ROMCount - 1);
	ROMParams.sum = ROMParams.sum + ROMVerifySumOffset;
	eepromWriteBuffer(ROMParamStartAddr, ROMParams.All, ROMCount);
}