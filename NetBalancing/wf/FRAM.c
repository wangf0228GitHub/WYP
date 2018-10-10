#include "FRAM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Verify.h"
#include "SPIROM.h"
#include "WorkMode_History.h"
#include "WirelessProc.h"
#include "WorkMode_RealTime.h"
#include "hmi_driver.h"
#include "TFTWorkProc.h"
#define eeprom_offset 1

_ROMParams ROMParams;
_SensorDataInfo SensorDataInfo;
_SensorData LatestSensorData;
extern uint32_t SystemSleepTick;
extern _SensorData SensorData4Save;

_SensorAddrInfo TSensorAddrList[SensorDataItemCount];
_SensorAddrInfo PSensorAddrList[SensorDataItemCount];
_SensorAddrSortingInfo TSensorAddrSortingList[SensorDataItemCount];
_SensorAddrSortingInfo PSensorAddrSortingList[SensorDataItemCount];
uint8_t realTSensorCount;
uint8_t realPSensorCount;
//温度传感器排序后数组总长度
uint8_t TSensorAddrSortingListCount;//温度传感器排序后数组总长度
uint8_t PSensorAddrSortingListCount;
void FRAM_GetROMParams(void)
{
	uint8_t i;
	uint32_t addr;
	char str[50];
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
			addr=TSensor1DataAddr+(uint32_t)i*SensorDataListCount;
			SPIROM_Fill(addr,0x00,SensorDataInfoCount);
		}
		FRAM_InitSensorData(0,100);
	}	
	sprintf(str,"%d",ROMParams.DeviceID);
	SetTextValue(22,50,str);
	SetTextValue(22,51,ROMParams.InstallArea);

	sprintf(str,"%d",ROMParams.TimeSpan1);
	SetTextValue(25,50,str);
	sprintf(str,"%d",ROMParams.TimeSpan2);
	SetTextValue(25,51,str);
	sprintf(str,"%d",ROMParams.TimeSpan3);
	SetTextValue(25,52,str);
	sprintf(str,"%d",ROMParams.TimeSpan4);
	SetTextValue(25,53,str);

	sprintf(str,"%d",ROMParams.SleepTimeSpan);
	SetTextValue(26,50,str);
}
void FRAM_InitSensorAddrInfo( void )
{
	char str[20];
	uint32_t i,addr;
	uint32_t TminAddr1,TminAddr2,TmaxAddr1,TmaxAddr2;
	uint32_t PminAddr1,PminAddr2,PmaxAddr1,PmaxAddr2;
	uint32_t addr1,addr2,x1,x2;
	TminAddr1=0xff;
	TminAddr2=0xff;
	TmaxAddr1=0;
	TmaxAddr2=0;
	PminAddr1=0xff;
	PminAddr2=0xff;
	PmaxAddr1=0;
	PmaxAddr2=0;
	realTSensorCount=0;
	realPSensorCount=0;
	for(i=0;i<SensorDataItemCount;i++)
	{
		addr=TSensor1DataAddr+i*SensorDataListCount;
		SPIROM_ReadArray(addr,TSensorAddrList[i].All,2);
		//确定栋及单元的取值范围
		if(TSensorAddrList[i].Addr1!=0xff)
		{
			realTSensorCount++;
			if(TSensorAddrList[i].Addr1>TmaxAddr1)
				TmaxAddr1=TSensorAddrList[i].Addr1;
			if(TSensorAddrList[i].Addr1<TminAddr1)
				TminAddr1=TSensorAddrList[i].Addr1;
			if(TSensorAddrList[i].Addr2>TmaxAddr2)
				TmaxAddr2=TSensorAddrList[i].Addr2;
			if(TSensorAddrList[i].Addr2<TminAddr2)
				TminAddr2=TSensorAddrList[i].Addr2;
		}
		addr=PSensor1DataAddr+i*SensorDataListCount;
		SPIROM_ReadArray(addr,PSensorAddrList[i].All,2);
		if(PSensorAddrList[i].Addr1!=0xff)
		{
			realPSensorCount++;
			if(PSensorAddrList[i].Addr1>PmaxAddr1)
				PmaxAddr1=PSensorAddrList[i].Addr1;
			if(PSensorAddrList[i].Addr1<PminAddr1)
				PminAddr1=PSensorAddrList[i].Addr1;
			if(PSensorAddrList[i].Addr2>PmaxAddr2)
				PmaxAddr2=PSensorAddrList[i].Addr2;
			if(PSensorAddrList[i].Addr2<PminAddr2)
				PminAddr2=PSensorAddrList[i].Addr2;
		}
	}
	TSensorAddrSortingListCount=0;
	for(addr1=TminAddr1;addr1<=TmaxAddr1;addr1++)
	{
		for(addr2=TminAddr2;addr2<=TmaxAddr2;addr2++)
		{
			for(i=0;i<SensorDataItemCount;i++)
			{
				if((TSensorAddrList[i].Addr1==addr1) && (TSensorAddrList[i].Addr2==addr2))
				{
					TSensorAddrSortingList[TSensorAddrSortingListCount].SensorIndex=i;
					TSensorAddrSortingList[TSensorAddrSortingListCount].Addr1=addr1;
					TSensorAddrSortingList[TSensorAddrSortingListCount].Addr2=addr2;
					TSensorAddrSortingListCount++;
					break;
				}
			}
		}
	}
	realtimeTPageCountOfBarCharts=realTSensorCount/SensorCountOfBarCharts;
	if((realTSensorCount%SensorCountOfBarCharts)!=0)
		realtimeTPageCountOfBarCharts++;

	sprintf(str,"共%u页，第%u页",realtimeTPageCountOfBarCharts,realtimeTPageOfBarCharts+1);
	SetTextValue(4,52,str);

	PSensorAddrSortingListCount=0;
	for(addr1=PminAddr1;addr1<=PmaxAddr1;addr1++)
	{
		for(addr2=PminAddr2;addr2<=PmaxAddr2;addr2++)
		{
			for(i=0;i<SensorDataItemCount;i++)
			{
				if((PSensorAddrList[i].Addr1==addr1) && (PSensorAddrList[i].Addr2==addr2))
				{
					PSensorAddrSortingList[PSensorAddrSortingListCount].SensorIndex=i;
					PSensorAddrSortingList[PSensorAddrSortingListCount].Addr1=addr1;
					PSensorAddrSortingList[PSensorAddrSortingListCount].Addr2=addr2;
					PSensorAddrSortingListCount++;
					break;
				}
			}
		}
	}
	realtimePPageCountOfBarCharts=realPSensorCount/SensorCountOfBarCharts;
	if((realPSensorCount%SensorCountOfBarCharts)!=0)
		realtimePPageCountOfBarCharts++;

	sprintf(str,"共%u页，第%u页",realtimePPageCountOfBarCharts,realtimePPageOfBarCharts+1);
	SetTextValue(5,52,str);
}

void FRAM_SaveROMParams(void)
{
	uint8_t i;
	ROMParams.sum=GetVerify_Sum(&ROMParams.All[1],ROMParamsCount-1);
	ROMParams.sum+=eeprom_offset;
	SPIROM_WriteArray(ROMParamsAddr,ROMParams.All,ROMParamsCount);
	SystemSleepTick=ROMParams.SleepTimeSpan*60000;
}


void FRAM_InitSensorData(uint8_t s,uint8_t e)
{
	uint8_t i;
	uint32_t addr;
	_SensorDataInfo sdInfo;	
	for(i=s;i<e;i++)
	{
		addr=TSensor1DataAddr+(uint32_t)i*SensorDataListCount;
		SPIROM_ReadArray(addr,sdInfo.All,SensorDataInfoCount);
		sdInfo.bLoop=0;
		sdInfo.LastState=0;
		sdInfo.curDataSaveIndex=0xff;
		SPIROM_WriteArray(addr,sdInfo.All,SensorDataInfoCount);
	}
}

void FRAM_GetSensorDataInfo(uint8_t bT,uint8_t index)
{
	uint32_t addr;
	if(bT!=PressureSensor)
		addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	else
		addr=PSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	SPIROM_ReadArray(addr,SensorDataInfo.All,SensorDataInfoCount);
}
void FRAM_GetLatestSensorData( uint8_t bT,uint8_t index )
{
	uint32_t addr;
	_SensorDataInfo sdInfo;
	if(bT!=PressureSensor)
		addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	else
		addr=PSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	SPIROM_ReadArray(addr,sdInfo.All,SensorDataInfoCount);
	if(sdInfo.curDataSaveIndex==0xff)
	{
		LatestSensorData.Month=0xff;
		return;
	}
	addr=addr+SensorDataInfoCount+(uint32_t)(sdInfo.curDataSaveIndex)*6;
	SPIROM_ReadArray(addr,LatestSensorData.All,6);
}

