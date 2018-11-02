#include "WorkMode_History.h"
#include "..\VisualTFT\hmi_driver.h"
#include "..\WirelessProc.h"
#include "TFTWorkProc.h"
#include <stdio.h>
#include "cmd_process.h"
#include "FRAM.h"
#include "DS18x20.h"
#include "SPIROM.h"



uint32_t History_TSensorIndex;
uint32_t History_PSensorIndex;

uint32_t History_TSensorDataItemCount;
uint32_t History_PSensorDataItemCount;
uint32_t History_TPageOfBarCharts;
uint32_t History_PPageOfBarCharts;
uint32_t History_TPageCountOfBarCharts;
uint32_t History_PPageCountOfBarCharts;


uint32_t History_TPageOfRecord;
uint32_t History_PPageOfRecord;
uint32_t History_TPageCountOfRecord;
uint32_t History_PPageCountOfRecord;

void HistoryModeInit(void)
{
	char str[50];
	uint32_t i,addr,index,addrMax,dataAddr;
	_SensorData sd;
	uint8_t t1,t2;
	//获取要查看的传感器编号
	if(ReadTextbox(6,51)==0)//温度编号
		return;
	sscanf((char *)controlValue,"%d",&History_TSensorIndex);	
	History_TSensorIndex--;
	if(ReadTextbox(6,52)==0)//压力编号
		return;
	sscanf((char *)controlValue,"%d",&History_PSensorIndex);	
	History_PSensorIndex--;
	//温度
	myRecordClear(7,cID_Record,20);
	sprintf(str,"%u-%u\0",TSensorAddrList[History_TSensorIndex].Addr1,TSensorAddrList[History_TSensorIndex].Addr2);
	SetTextValue(7,50,str);
	SetTextValue(9,120,str);
	sprintf(str,"%03u\0",History_TSensorIndex+1);
	SetTextValue(7,51,str);
	SetTextValue(9,121,str);

	FRAM_GetSensorDataInfo(TemperatureSensor,History_TSensorIndex);
	History_TPageOfRecord=0;
	History_TPageOfBarCharts=0;
	index=0;
	addrMax=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataListCount;
	if(SensorDataInfo.bLoop)//已存储满，则当前位置的下一位置为最旧数据，依次添加到数据表格中
	{
		History_TPageCountOfBarCharts=SensorDataItemCount/ItemCountOfBarCharts;
		History_TPageCountOfRecord=SensorDataItemCount/ItemCountOfRecord;
		dataAddr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount+SensorDataInfo.curDataSaveIndex*6+6;
		if(dataAddr==addrMax)
			dataAddr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		History_TSensorDataItemCount=SensorDataItemCount;
	}
	else//未存满，则0位置为最旧数据，依次添加到数据表格中
	{
		if(SensorDataInfo.curDataSaveIndex==0xff)//当前还没有数据
		{
			History_TPageCountOfBarCharts=0;
			History_TPageCountOfRecord=0;
			History_TSensorDataItemCount=0;
		}
		else		
		{
			History_TPageCountOfBarCharts=(SensorDataInfo.curDataSaveIndex+1)/ItemCountOfBarCharts;
			if(((SensorDataInfo.curDataSaveIndex+1)%ItemCountOfBarCharts)!=0)
				History_TPageCountOfBarCharts++;
			History_TPageCountOfRecord=(SensorDataInfo.curDataSaveIndex+1)/ItemCountOfRecord;
			if(((SensorDataInfo.curDataSaveIndex+1)%ItemCountOfRecord)!=0)
				History_TPageCountOfRecord++;
			dataAddr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;	
			History_TSensorDataItemCount=SensorDataInfo.curDataSaveIndex+1;
		}
	}	
	//处理列表
	addr=dataAddr;
	for(i=0;i<ItemCountOfRecord;i++)
	{
		if(i>=History_TSensorDataItemCount)
			break;
		SPIROM_ReadArray(addr,sd.All,6);
		index++;
		t1=(sd.SensorData&0x0fff)>>4;
		t2=sd.SensorData&0x000f;
		sprintf(str,"%u;%02u-%02u %02u:%02u;%u.%u;\0",
			index,sd.Month,sd.Day,sd.Hour,sd.Minute,				
			t1,DS18X20_ToDecicel[t2]);		
		Record_Add(7,cID_Record,str);
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}
	}
	if(History_TPageCountOfRecord==0)
		SetTextValue(7,cID_PageNum,"\0");
	else
	{
		sprintf(str,"共%u页，第%u页\0",History_TPageCountOfRecord,History_TPageOfRecord+1);
		SetTextValue(7,cID_PageNum,str);
	}
	//处理柱形图
	addr=dataAddr;
	for(i=0;i<ItemCountOfBarCharts;i++)
	{
		if(i>=History_TSensorDataItemCount)		
		{
			SetTextValue(9,cID_Bar1Text+i,"\0");
			SetTextValue(9,cID_Bar1Text_1+i,"\0");
			SetProgressValue(9,cID_Bar1+i,0);
			continue;
		}
		SPIROM_ReadArray(addr,sd.All,6);
		t1=(sd.SensorData&0x0fff)>>4;
		sprintf(str,"%02u-%02u\0",sd.Month,sd.Day);	
		SetTextValue(9,cID_Bar1Text+i,str);
		sprintf(str,"%02u:%02u\0",sd.Hour,sd.Minute);
		SetTextValue(9,cID_Bar1Text_1+i,str);
		SetProgressValue(9,cID_Bar1+i,t1);
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}
	}
	if(History_TPageCountOfBarCharts==0)
	{
		SetTextValue(9,cID_PageNum,"\0");
	}
	else
	{
		sprintf(str,"共%u页，第%u页\0",History_TPageCountOfBarCharts,History_TPageOfBarCharts+1);
		SetTextValue(9,cID_PageNum,str);
	}
	//压力
	//跳转页面
	SetScreen(7);
}
void History_TRecordSwitchPage(uint16_t cID)
{
	char str[50];
	uint32_t addr,i,t1,t2,x1,x2,addrMax;
	_SensorDataInfo sdInfo;
	_SensorData sd;
	if(History_TPageCountOfRecord<2)
		return;
	if(cID==cID_btBackward)
	{
		History_TPageOfRecord++;
		if(History_TPageOfRecord>=History_TPageCountOfRecord)
			History_TPageOfRecord=0;
	}
	else
	{
		if(History_TPageOfRecord==0)
			History_TPageOfRecord=History_TPageCountOfRecord-1;
		else
			History_TPageOfRecord--;
	}
	sprintf(str,"共%u页，第%u页\0",History_TPageCountOfRecord,History_TPageOfRecord+1);
	SetTextValue(7,cID_PageNum,str);
	x1=History_TPageOfRecord*ItemCountOfRecord;
	x2=x1+ItemCountOfRecord;
	FRAM_GetSensorDataInfo(TemperatureSensor,History_TSensorIndex);
	addrMax=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataListCount;
	if(SensorDataInfo.bLoop)//已存储满，则当前位置的下一位置为最旧数据，依次添加到数据表格中
	{
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount+SensorDataInfo.curDataSaveIndex*6+6;
		if(addr==addrMax)
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
	}
	else//未存满，则0位置为最旧数据，依次添加到数据表格中
	{
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;	
	}
	myRecordClear(7,cID_Record,20);
	for(i=0;i<History_TSensorDataItemCount;i++)
	{
		if((i>=x1) && (i<x2))
		{			
			SPIROM_ReadArray(addr,sd.All,6);
			t1=(sd.SensorData&0x0fff)>>4;
			t2=sd.SensorData&0x000f;
			sprintf(str,"%u;%02u-%02u %02u:%02u;%u.%u;\0",
				i+1,sd.Month,sd.Day,sd.Hour,sd.Minute,				
				t1,DS18X20_ToDecicel[t2]);		
			Record_Add(7,cID_Record,str);
		}	
		else if(i>=x2)
			break;
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}		
	}
}
void History_TBarChartsSwitchPage(uint16_t cID)
{
	char str[50];
	uint32_t addr,i,t1,t2,x1,x2,addrMax,barIndex;
	_SensorDataInfo sdInfo;
	_SensorData sd;
	if(History_TPageCountOfBarCharts<2)
		return;
	if(cID==cID_btBackward)
	{
		History_TPageOfBarCharts++;
		if(History_TPageOfBarCharts>=History_TPageCountOfBarCharts)
			History_TPageOfBarCharts=0;
	}
	else
	{
		if(History_TPageOfBarCharts==0)
			History_TPageOfBarCharts=History_TPageCountOfBarCharts-1;
		else
			History_TPageOfBarCharts--;
	}
	sprintf(str,"共%u页，第%u页\0",History_TPageCountOfBarCharts,History_TPageOfBarCharts+1);
	SetTextValue(9,cID_PageNum,str);
	x1=History_TPageOfBarCharts*ItemCountOfBarCharts;
	x2=x1+ItemCountOfBarCharts;
	FRAM_GetSensorDataInfo(TemperatureSensor,History_TSensorIndex);
	addrMax=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataListCount;
	if(SensorDataInfo.bLoop)//已存储满，则当前位置的下一位置为最旧数据，依次添加到数据表格中
	{
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount+SensorDataInfo.curDataSaveIndex*6+6;
		if(addr==addrMax)
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
	}
	else//未存满，则0位置为最旧数据，依次添加到数据表格中
	{
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;	
	}
	barIndex=0;
	for(i=0;i<History_TSensorDataItemCount;i++)
	{
		if((i>=x1) && (i<x2))//加入到柱形图中
		{			
			SPIROM_ReadArray(addr,sd.All,6);
			t1=(sd.SensorData&0x0fff)>>4;
			sprintf(str,"%02u-%02u\0",sd.Month,sd.Day);	
			SetTextValue(9,cID_Bar1Text+barIndex,str);
			sprintf(str,"%02u:%02u\0",sd.Hour,sd.Minute);
			SetTextValue(9,cID_Bar1Text_1+barIndex,str);
			SetProgressValue(9,cID_Bar1+barIndex,t1);
			barIndex++;
		}	
		else if(i>=x2)
			break;
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}		
	}
	while(barIndex<ItemCountOfBarCharts)
	{		
		SetTextValue(9,cID_Bar1Text+barIndex,"\0");
		SetTextValue(9,cID_Bar1Text_1+barIndex,"\0");
		SetProgressValue(9,cID_Bar1+barIndex,0);
		barIndex++;	
	}
}