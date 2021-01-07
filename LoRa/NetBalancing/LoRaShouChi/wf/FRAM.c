#include "HardwareProfile.h"
#include "FRAM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Verify.h"
#include "TMRList.h"
#include "Variables.h"
#include "spi.h"

#define eeprom_offset 1


uint8_t SPI_Proc(uint8_t outData)
{
	uint8_t rxData = 0;	
	HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)&outData, (uint8_t*)&rxData, 1, 0xFFFF);
	return(rxData);
}

void FRAM_Init(void)
{
	FRAM_GetROMParams();
}
void FRAM_SaveROMParams(void)
{
	//uint8_t i;
	ROMParams.sum=GetVerify_Sum(&ROMParams.All[1],ROMParamsCount-1);
	ROMParams.sum+=eeprom_offset;
	SPIROM_WriteArray(ROMParamsAddr,ROMParams.All,ROMParamsCount);
	TmrSetTime(SystemSleep_TMRNUM, ROMParams.SleepTimeSpan * 6000);
	//ROMSleepTick=ROMParams.SleepTimeSpan*600;
}

void FRAM_GetROMParams(void)
{
	uint8_t i;
	uint32_t addr;
	SPIROM_ReadArray(ROMParamsAddr,ROMParams.All,ROMParamsCount);
	i=GetVerify_Sum(&ROMParams.All[1],ROMParamsCount-1);
	i+=eeprom_offset;
	if(i!=ROMParams.sum)//�洢��У�鲻�ɹ�����ʼ�����в���
	{
		ROMParams.WirelessParamIndex=0;
		ROMParams.TimeSpan1=10;
		ROMParams.TimeSpan2=30;
		ROMParams.TimeSpan3=60;
		ROMParams.TimeSpan4=300;
		ROMParams.SleepTimeSpan=30;
		FRAM_SaveROMParams();	
		for(i=0;i<100;i++)
		{
			addr=Sensor1DataAddr+(uint32_t)i*SensorDataListCount;
			SPIROM_Fill(addr,0x00,SensorDataInfoCount);
		}
		FRAM_InitSensorData(0,100);
	}
	TmrSetTime(SystemSleep_TMRNUM, ROMParams.SleepTimeSpan * 6000);
	//ROMSleepTick=ROMParams.SleepTimeSpan*600;
}
void FRAM_InitSensorData(uint8_t s,uint8_t e)
{
	uint8_t i;
	uint32_t addr;
	for(i=s;i<e;i++)
	{
		addr=Sensor1DataAddr+(uint32_t)i*SensorDataListCount+(uint32_t)21;
		SPIROM_Fill(addr,0x00,3);
	}
}
void FRAM_SaveSensorData(void)
{
	uint8_t index;
	uint32_t addr;
	uint8_t curIndex;
	index=PickDatas.index-1;
	addr=Sensor1DataAddr+(uint32_t)index*SensorDataListCount;
	addr=addr+(uint32_t)23;
	curIndex=SPIROM_ReadByte(addr);
	curIndex++;
	if(curIndex>=SensorDataCount)
	{
		curIndex=0;
		SPIROM_WriteByte(addr-1,1);
	}
	SPIROM_WriteByte(addr,curIndex);
	addr=addr+(uint32_t)(curIndex-1)*6+1;
	SPIROM_WriteArray(addr,SensorData4Save.All,6);	
}
void FRAM_GetSensorDataInfo(uint8_t index)
{
	uint32_t addr;
	addr=Sensor1DataAddr+(uint32_t)index*SensorDataListCount;
	SPIROM_ReadArray(addr,SensorDataInfo.All,SensorDataInfoCount);
	if(SensorDataInfo.bLoop==0)//δ����
	{	
		History_curPageCount=(SensorDataInfo.curIndex-1+History_PageSize)/History_PageSize;
	}
	else
	{
		History_curPageCount=History_PageCount;
	}
}
void FRAM_SaveSensorAddr(uint8_t index,uint8_t* pBuff,uint8_t Count)
{
	uint32_t addr;
	addr=Sensor1DataAddr+(uint32_t)index*SensorDataListCount;
	if(Count>20)
		Count=20;
	SPIROM_WriteArray(addr,pBuff,Count);
}
void FRAM_GetSensorData(uint8_t index,uint8_t* pBuf)
{
	uint32_t addr;
	if(SensorDataInfo.curIndex==0)
	{
		if(SensorDataInfo.bLoop!=0)//ѭ����
		{
			addr=Sensor1DataAddr+(uint32_t)(index+1)*SensorDataListCount-7;
		}
		else
		{
			pBuf[0]=0xff;
			return;
		}
	}
	else
	{
		addr=Sensor1DataAddr+(uint32_t)index*SensorDataListCount+SensorDataInfoCount+(uint32_t)(SensorDataInfo.curIndex-1)*6;
	}
	SPIROM_ReadArray(addr,pBuf,6);
}
void FRAM_HistoryGetPageSensorData()
{
	uint32_t addr;
	unsigned int n;
	uint8_t x,x1,x2,i;//,curIndex;
	addr=Sensor1DataAddr+(uint32_t)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
	if(SensorDataInfo.bLoop==0)//δ����
	{	
		i=History_Page*History_PageSize;		
		x=SensorDataInfo.curIndex-i;		
		if(x>=History_PageSize)//����һ����ʾ
		{
			History_ListCount=History_PageSize;			
			n=History_PageSize*6;
			i=History_Page+1;
			addr=addr+(uint32_t)(History_Page*10)*6;
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}
		else
		{
			History_ListCount=x;
			addr=addr+(uint32_t)(History_Page*10)*6;
			n=x*6;
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}		
	}
	else//��ʼѭ���洢
	{	
		n=History_PageSize*6;
		History_ListCount=History_PageSize;	
		i=(History_Page+1)*History_PageSize;
		x1=History_Page*History_PageSize;
		x=SensorDataMaxCount-SensorDataInfo.curIndex;
		if(x>=i)//ͷ���������㹻
		{
			addr=addr+(uint32_t)SensorDataInfo.curIndex*6+(uint32_t)x1*6;			
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}
		else
		{
			x2=x+History_PageSize;
			if(x2>=i)//��ͷȡ
			{
				addr=addr+(uint32_t)SensorDataInfo.curIndex*6+(uint32_t)x1*6;			
				x=x-x1;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,x*6);
				x1=History_PageSize-x;
				addr=Sensor1DataAddr+(uint32_t)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
				SPIROM_ReadArray(addr,SensorData4ShowList[x].All,x1*6);
			}
			else//ѭ����ͷȡ
			{
				x2=x1-x;
				addr+=(uint32_t)x2*6;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
			}
		}		
	}
}
