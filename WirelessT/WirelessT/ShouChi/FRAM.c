#include "HardwareProfile.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define eeprom_offset 1

void FRAM_SaveROMParams(void)
{
	unsigned char i;
	ROMParams.sum=GetVerify_Sum(&ROMParams.All[1],ROMParamsCount-1);
	ROMParams.sum+=eeprom_offset;
	SPIROM_WriteArray(ROMParamsAddr,ROMParams.All,ROMParamsCount);
	ROMSleepTick=ROMParams.SleepTimeSpan*600;
}

void FRAM_GetROMParams(void)
{
	unsigned char i;
	unsigned long addr;
	SPIROM_ReadArray(ROMParamsAddr,ROMParams.All,ROMParamsCount);
	i=GetVerify_Sum(&ROMParams.All[1],ROMParamsCount-1);
	i+=eeprom_offset;
	if(i!=ROMParams.sum)//存储区校验不成功，初始化所有参数
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
			addr=Sensor1DataAddr+(unsigned long)i*SensorDataListCount;
			SPIROM_Fill(addr,0x00,SensorDataInfoCount);
		}
		FRAM_InitSensorData(0,100);
	}	
	ROMSleepTick=ROMParams.SleepTimeSpan*600;
}
void FRAM_InitSensorData(unsigned char s,unsigned char e)
{
	unsigned char i;
	unsigned long addr;
	for(i=s;i<e;i++)
	{
		addr=Sensor1DataAddr+(unsigned long)i*SensorDataListCount+(unsigned long)21;
		SPIROM_Fill(addr,0x00,3);
	}
}
void FRAM_SaveSensorData(void)
{
	unsigned char index;
	unsigned long addr;
	unsigned char curIndex;
	index=PickDatas.index-1;
	addr=Sensor1DataAddr+(unsigned long)index*SensorDataListCount;
	addr=addr+(unsigned long)23;
	curIndex=SPIROM_ReadByte(addr);
	curIndex++;
	if(curIndex>=SensorDataCount)
	{
		curIndex=0;
		SPIROM_WriteByte(addr-1,1);
	}
	SPIROM_WriteByte(addr,curIndex);
	addr=addr+(unsigned long)(curIndex-1)*6+1;
	SPIROM_WriteArray(addr,SensorData4Save.All,6);	
}
void FRAM_GetSensorDataInfo(unsigned char index)
{
	unsigned long addr;
	addr=Sensor1DataAddr+(unsigned long)index*SensorDataListCount;
	SPIROM_ReadArray(addr,SensorDataInfo.All,SensorDataInfoCount);
	if(SensorDataInfo.bLoop==0)//未存满
	{	
		History_curPageCount=(SensorDataInfo.curIndex-1+History_PageSize)/History_PageSize;
	}
	else
	{
		History_curPageCount=History_PageCount;
	}
}
void FRAM_SaveSensorAddr(unsigned char index,unsigned char* pBuff,unsigned char Count)
{
	unsigned long addr;
	addr=Sensor1DataAddr+(unsigned long)index*SensorDataListCount;
	if(Count>20)
		Count=20;
	SPIROM_WriteArray(addr,pBuff,Count);
}
void FRAM_GetSensorData(unsigned char index,unsigned char* pBuf)
{
	unsigned long addr;
	if(SensorDataInfo.curIndex==0)
	{
		if(SensorDataInfo.bLoop!=0)//循环了
		{
			addr=Sensor1DataAddr+(unsigned long)(index+1)*SensorDataListCount-7;
		}
		else
		{
			pBuf[0]=0xff;
			return;
		}
	}
	else
	{
		addr=Sensor1DataAddr+(unsigned long)index*SensorDataListCount+SensorDataInfoCount+(unsigned long)(SensorDataInfo.curIndex-1)*6;
	}
	SPIROM_ReadArray(addr,pBuf,6);
}
void FRAM_HistoryGetPageSensorData()
{
	unsigned long addr;
	unsigned int n;
	unsigned char x,x1,x2,i,curIndex;
	addr=Sensor1DataAddr+(unsigned long)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
	if(SensorDataInfo.bLoop==0)//未存满
	{	
		i=History_Page*History_PageSize;		
		x=SensorDataInfo.curIndex-i;		
		if(x>=History_PageSize)//还够一屏显示
		{
			History_ListCount=History_PageSize;			
			n=History_PageSize*6;
			i=History_Page+1;
			addr=addr+(unsigned long)(History_Page*10)*6;
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}
		else
		{
			History_ListCount=x;
			addr=addr+(unsigned long)(History_Page*10)*6;
			n=x*6;
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}		
	}
	else//开始循环存储
	{	
		n=History_PageSize*6;
		History_ListCount=History_PageSize;	
		i=(History_Page+1)*History_PageSize;
		x1=History_Page*History_PageSize;
		x=SensorDataMaxCount-SensorDataInfo.curIndex;
		if(x>=i)//头部数据已足够
		{
			addr=addr+(unsigned long)SensorDataInfo.curIndex*6+(unsigned long)x1*6;			
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}
		else
		{
			x2=x+History_PageSize;
			if(x2>=i)//两头取
			{
				addr=addr+(unsigned long)SensorDataInfo.curIndex*6+(unsigned long)x1*6;			
				x=x-x1;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,x*6);
				x1=History_PageSize-x;
				addr=Sensor1DataAddr+(unsigned long)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
				SPIROM_ReadArray(addr,&SensorData4ShowList[x].All,x1*6);
			}
			else//循环从头取
			{
				x2=x1-x;
				addr+=(unsigned long)x2*6;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
			}
		}		
	}
}
