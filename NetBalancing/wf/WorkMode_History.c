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

void HistoryModeInit(void)
{
	char str[50];
	uint32_t i,addr,index,addrMax;
	_SensorData sd;
	uint8_t t1,t2;
	//获取要查看的传感器编号
	if(ReadTextbox(6,51)==0);//温度编号
		return;
	sscanf((char *)controlValue,"%d",&History_TSensorIndex);	
	if(ReadTextbox(6,52)==0);//压力编号
	return;
	sscanf((char *)controlValue,"%d",&History_TSensorIndex);	
	//温度
	sprintf(str,"%u-%u",TSensorAddrList[History_TSensorIndex].Addr1,TSensorAddrList[History_TSensorIndex].Addr2);
	SetTextValue(7,50,str);
	SetTextValue(9,50,str);

	sprintf(str,"%03u",History_TSensorIndex);
	SetTextValue(7,51,str);
	SetTextValue(9,51,str);

	FRAM_GetSensorDataInfo(TemperatureSensor,History_TSensorIndex);
	History_TPageOfBarCharts=0;
	index=0;
	addrMax=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataListCount;
	if(SensorDataInfo.bLoop)//已存储满，则当前位置的下一位置为最旧数据，依次添加到数据表格中
	{
		History_TPageCountOfBarCharts=SensorDataItemCount/SensorCountOfBarCharts;
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount+SensorDataInfo.curDataSaveIndex*6+6;
		if(addr==addrMax)
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		History_TSensorDataItemCount=SensorDataItemCount;
	}
	else//未存满，则0位置为最旧数据，依次添加到数据表格中
	{
		History_TPageCountOfBarCharts=(SensorDataInfo.curDataSaveIndex+1)/SensorCountOfBarCharts;
		if(((SensorDataInfo.curDataSaveIndex+1)%SensorCountOfBarCharts)!=0)
			History_TPageCountOfBarCharts++;
		addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;	
		History_TSensorDataItemCount=SensorDataInfo.curDataSaveIndex+1;
	}
	for(i=0;i<History_TSensorDataItemCount;i++)
	{
		SPIROM_ReadArray(addr,sd.All,6);
		index++;
		t1=(sd.SensorData&0x0fff)>>4;
		t2=sd.SensorData&0x000f;
		sprintf(str,"%u;%02u:%02u %02u:%02u;%u.%u;",
			index,sd.Month,sd.Day,sd.Hour,sd.Minute,				
			t1,DS18X20_ToDecicel[t2]);		
		Record_Add(7,cID_Record,str);
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}
		if(i<SensorCountOfBarCharts)//加入到柱形图中
		{
			if(t2>4)
				t1++;
			SetProgressValue(9,cID_Bar1+i,t1);
		}
	}
	sprintf(str,"共%u页，第%u页",History_TPageCountOfBarCharts,History_TPageOfBarCharts+1);
	SetTextValue(9,52,str);
	//压力
	sprintf(str,"%u-%u",PSensorAddrList[History_PSensorIndex].Addr1,PSensorAddrList[History_PSensorIndex].Addr2);
	SetTextValue(8,50,str);

	sprintf(str,"%03u",History_PSensorIndex);
	SetTextValue(8,51,str);

}

void History_TBarChartsSwitchPage(uint16_t cID)
{
	char str[50];
	uint32_t addr,i,t1,t2,x1,x2,addrMax;
	_SensorDataInfo sdInfo;
	_SensorData sd;
	if(cID==cID_btForward)
	{
		if(History_TPageOfBarCharts==History_TPageCountOfBarCharts)
			History_TPageOfBarCharts=0;
		else
			History_TPageOfBarCharts++;
	}
	else
	{
		if(History_TPageOfBarCharts==0)
			History_TPageOfBarCharts=History_TPageCountOfBarCharts;
		else
			History_TPageOfBarCharts--;
	}
	sprintf(str,"共%u页，第%u页",History_TPageCountOfBarCharts,History_TPageOfBarCharts+1);
	SetTextValue(9,52,str);
	x1=History_TPageOfBarCharts*SensorCountOfBarCharts;
	x2=x1+SensorCountOfBarCharts;
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
	for(i=0;i<History_TSensorDataItemCount;i++)
	{
		if((i>=x1) && (i<x2))//加入到柱形图中
		{
			SPIROM_ReadArray(addr,sd.All,6);
			t1=(sd.SensorData&0x0fff)>>4;
			t2=sd.SensorData&0x000f;
			if(t2>4)
				t1++;
			SetProgressValue(9,cID_Bar1+i,t1);
		}		
		addr+=6;
		if(addr>=addrMax)
		{
			addr=TSensor1DataAddr+(uint32_t)History_TSensorIndex*SensorDataListCount+SensorDataInfoCount;
		}
		
	}
}