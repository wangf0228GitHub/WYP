#include "HardwareProfile.h"
unsigned char GetRomData(void)
{
	unsigned char i;
	unsigned long RomAddr=RomParamAddr;	
	for(i=0;i<ROMCount;i++)
		ROMParams.All[i]=flash_read(RomAddr+i);
	i=GetVerify_Sum(&ROMParams.All[1],ROMCount-1);
	if(i==ROMParams.sum)//存储区校验成功
	{		
		//PickDatas.StateBits.bWinter=ROMParams.SystemState.bWinter;
		return 1;
	}
	else
		return 0;	
}
void SaveRomData(void)
{
	const unsigned char * source=ROMParams.All;
	far unsigned char * dest=(far unsigned char *)RomParamAddr;
	ROMParams.sum=GetVerify_Sum(&ROMParams.All[1],ROMCount-1);
	wf_flash_write(source,ROMCount,dest);
}

