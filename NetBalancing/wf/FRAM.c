#include "FRAM.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Verify.h"
#include "SPIROM.h"
#include "WorkMode_History.h"
#include "WirelessProc.h"
#include "WorkMode_RealTime.h"
#define eeprom_offset 1

_ROMParams ROMParams;
_SensorDataInfo SensorDataInfo;
extern uint32_t SystemSleepTick;
extern _SensorData SensorData4Save;

_SensorAddrInfo TSensorAddrList[SensorDataItemCount];
_SensorAddrInfo PSensorAddrList[SensorDataItemCount];
_SensorAddrSortingInfo TSensorAddrSortingList[SensorDataItemCount];
_SensorAddrSortingInfo PSensorAddrSortingList[SensorDataItemCount];
uint8_t realTSensorCount;
uint8_t realPSensorCount;
uint8_t TSensorAddrSortingListCount;
uint8_t PSensorAddrSortingListCount;
void FRAM_GetROMParams(void)
{
	uint8_t i;
	uint32_t addr;
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
	SystemSleepTick=ROMParams.SleepTimeSpan*600;
}
void FRAM_InitSensorAddrInfo( void )
{
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
	for(i=s;i<e;i++)
	{
		addr=TSensor1DataAddr+(uint32_t)i*SensorDataListCount+(uint32_t)21;
		SPIROM_Fill(addr,0x00,3);
	}
}
void FRAM_SaveSensorData(void)
{
	uint8_t index;
	uint32_t addr;
	uint8_t curIndex;
	index=WirelessPacket.index-1;
	addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	addr=addr+(uint32_t)23;
	curIndex=SPIROM_ReadByte(addr);
	curIndex++;
	if(curIndex>=SensorDataItemCount)
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
	addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	SPIROM_ReadArray(addr,SensorDataInfo.All,SensorDataInfoCount);
	if(SensorDataInfo.bLoop==0)//未存满
	{	
		History_curPageCount=(SensorDataInfo.curDataSaveIndex-1+History_PageSize)/History_PageSize;
	}
	else
	{
		History_curPageCount=History_PageCount;
	}
}
void FRAM_SaveSensorAddr(uint8_t index,uint8_t* pBuff,uint8_t Count)
{
	uint32_t addr;
	addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount;
	if(Count>20)
		Count=20;
	SPIROM_WriteArray(addr,pBuff,Count);
}
void FRAM_GetSensorData(uint8_t index,uint8_t* pBuf)
{
	uint32_t addr;
	if(SensorDataInfo.curDataSaveIndex==0)
	{
		if(SensorDataInfo.bLoop!=0)//循环了
		{
			addr=TSensor1DataAddr+(uint32_t)(index+1)*SensorDataListCount-7;
		}
		else
		{
			pBuf[0]=0xff;
			return;
		}
	}
	else
	{
		addr=TSensor1DataAddr+(uint32_t)index*SensorDataListCount+SensorDataInfoCount+(uint32_t)(SensorDataInfo.curDataSaveIndex-1)*6;
	}
	SPIROM_ReadArray(addr,pBuf,6);
}
void FRAM_HistoryGetPageSensorData()
{
	uint32_t addr;
	uint16_t n;
	uint8_t x,x1,x2,i,curIndex;
	addr=TSensor1DataAddr+(uint32_t)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
	if(SensorDataInfo.bLoop==0)//未存满
	{	
		i=History_Page*History_PageSize;		
		x=SensorDataInfo.curDataSaveIndex-i;		
		if(x>=History_PageSize)//还够一屏显示
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
	else//开始循环存储
	{	
		n=History_PageSize*6;
		History_ListCount=History_PageSize;	
		i=(History_Page+1)*History_PageSize;
		x1=History_Page*History_PageSize;
		x=SensorDataMaxCount-SensorDataInfo.curDataSaveIndex;
		if(x>=i)//头部数据已足够
		{
			addr=addr+(uint32_t)SensorDataInfo.curDataSaveIndex*6+(uint32_t)x1*6;			
			SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
		}
		else
		{
			x2=x+History_PageSize;
			if(x2>=i)//两头取
			{
				addr=addr+(uint32_t)SensorDataInfo.curDataSaveIndex*6+(uint32_t)x1*6;			
				x=x-x1;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,x*6);
				x1=History_PageSize-x;
				addr=TSensor1DataAddr+(uint32_t)History_SensorIndex*SensorDataListCount+SensorDataInfoCount;
				SPIROM_ReadArray(addr,SensorData4ShowList[x].All,x1*6);
			}
			else//循环从头取
			{
				x2=x1-x;
				addr+=(uint32_t)x2*6;
				SPIROM_ReadArray(addr,SensorData4ShowList[0].All,n);
			}
		}		
	}
}
