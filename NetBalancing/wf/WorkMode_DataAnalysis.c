#include "WorkMode_DataAnalysis.h"
#include "FRAM.h"
#include "hmi_driver.h"
#include "TFTWorkProc.h"
#include "DS18x20.h"


//DY 为单元
uint32_t DataAnalysis_DY_TPageCountOfRecord;
uint32_t DataAnalysis_DY_TPageIndexOfRecord;

uint32_t DataAnalysis_DY_TPageCountOfBarCharts;
uint32_t DataAnalysis_DY_TPageIndexOfBarCharts;

//DA 为栋平均
uint32_t DataAnalysis_DA_TPageCountOfRecord;
uint32_t DataAnalysis_DA_TPageIndexOfRecord;

uint32_t DataAnalysis_DA_TPageCountOfBarCharts;
uint32_t DataAnalysis_DA_TPageIndexOfBarCharts;
void DataAnalysisModeInit( void )
{
	uint32_t i,j,addr;
	uint8_t TAddrSortingListIndex,tCount,t1,t2;
	uint32_t t;
	char str[50];
	
	//栋平均温度列表
	DataAnalysis_DA_TPageIndexOfRecord=0;
	DataAnalysis_DA_TPageCountOfRecord=TAddr1ListCount/ItemCountOfRecord;
	if(TAddr1ListCount%ItemCountOfRecord!=0)
		DataAnalysis_DA_TPageCountOfRecord++;
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DA_TPageCountOfRecord,DataAnalysis_DA_TPageIndexOfRecord+1);
	SetTextValue(11,cID_PageNum,str);
	myRecordClear(11,cID_Record,20);		
	for(i=0;i<TAddr1ListCount;i++)
	{
		if(i>=ItemCountOfRecord)
			break;
		t=0;
		tCount=0;
		for(TAddrSortingListIndex=0;TAddrSortingListIndex<TSensorAddrSortingListCount;TAddrSortingListIndex++)
		{
			if(TSensorAddrSortingList[TAddrSortingListIndex].Addr1==TAddr1List[i])
			{
				FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[TAddrSortingListIndex].SensorIndex);
				if(IsLatestSensorDataValid())
				{
					t+=LatestSensorData.SensorData;
					tCount++;
				}
			}
		}			
		if (tCount!=0)
		{
			t=t/tCount;
			t1=(t&0x0fff)>>4;
			t2=DS18X20_ToDecicel[t&0x000f];			
			sprintf(str,"%u;%u.%u;%u;\0",
				i+1,t1,t2,TAddr1List[i]);			
		}
		else		
		{
			sprintf(str,"%u;xx.x;%u;\0",i+1,TAddr1List[i]);
		}
		Record_Add(11,cID_Record,str);
	}
	//栋温度柱形图
	DataAnalysis_DA_TPageIndexOfBarCharts=0;
	DataAnalysis_DA_TPageCountOfBarCharts=TAddr1ListCount/ItemCountOfBarCharts;
	if(TAddr1ListCount%ItemCountOfBarCharts!=0)
		DataAnalysis_DA_TPageCountOfBarCharts++;
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DA_TPageCountOfBarCharts,DataAnalysis_DA_TPageIndexOfBarCharts+1);
	SetTextValue(15,cID_PageNum,str);	
	for(i=0;i<ItemCountOfBarCharts;i++)
	{
		if(i>=TAddr1ListCount)
		{
			SetProgressValue(15,cID_Bar1+i,0);
			SetTextValue(15,cID_Bar1Text+i,"\0");
		}
		else
		{
			t=0;
			tCount=0;
			for(TAddrSortingListIndex=0;TAddrSortingListIndex<TSensorAddrSortingListCount;TAddrSortingListIndex++)
			{
				if(TSensorAddrSortingList[TAddrSortingListIndex].Addr1==TAddr1List[i])
				{
					FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[TAddrSortingListIndex].SensorIndex);
					if(IsLatestSensorDataValid())
					{
						t+=LatestSensorData.SensorData;
						tCount++;
					}
				}
			}			
			if (tCount!=0)
			{
				t=t/tCount;
				t1=(t&0x0fff)>>4;		
				SetProgressValue(15,cID_Bar1+i,t1);				
			}
			else		
			{
				SetProgressValue(15,cID_Bar1+i,0);
			}
			sprintf(str,"%u\0",TAddr1List[i]);
			SetTextValue(15,cID_Bar1Text+i,str);	
		}
	}
	//单元列表
	DataAnalysis_DY_TPageIndexOfRecord=0;
	DataAnalysis_DY_TPageCountOfRecord=TSensorAddrSortingListCount/ItemCountOfRecord;
	if(TSensorAddrSortingListCount%ItemCountOfRecord!=0)
		DataAnalysis_DY_TPageCountOfRecord++;
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DY_TPageCountOfRecord,DataAnalysis_DY_TPageIndexOfRecord+1);
	SetTextValue(13,cID_PageNum,str);
	myRecordClear(13,cID_Record,20);		
	for(i=0;i<TSensorAddrSortingListCount;i++)
	{
		if(i>=ItemCountOfRecord)
			break;
		FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[i].SensorIndex);
		if(IsLatestSensorDataValid())
		{
			t=LatestSensorData.SensorData;
			t1=(t&0x0fff)>>4;
			t2=DS18X20_ToDecicel[t&0x000f];			
			sprintf(str,"%u;%u.%u;%u-%u;\0",
				i+1,t1,t2,TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);	
		}	
		else
		{
			sprintf(str,"%u;xx.x;%u-%u;\0",
				i+1,TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);
		}
		Record_Add(13,cID_Record,str);
	}
	//单元柱形图
	DataAnalysis_DY_TPageIndexOfBarCharts=0;
	DataAnalysis_DY_TPageCountOfBarCharts=TSensorAddrSortingListCount/ItemCountOfBarCharts;
	if(TSensorAddrSortingListCount%ItemCountOfBarCharts!=0)
		DataAnalysis_DY_TPageCountOfBarCharts++;
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DY_TPageCountOfBarCharts,DataAnalysis_DY_TPageIndexOfBarCharts+1);
	SetTextValue(17,cID_PageNum,str);	
	for(i=0;i<ItemCountOfBarCharts;i++)
	{
		if(i>=TSensorAddrSortingListCount)
		{
			SetProgressValue(17,cID_Bar1+i,0);
			SetTextValue(17,cID_Bar1Text+i,"\0");
		}
		else
		{
			FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[i].SensorIndex);
			if(IsLatestSensorDataValid())
			{
				t=LatestSensorData.SensorData;
				t1=(t&0x0fff)>>4;		
				SetProgressValue(17,cID_Bar1+i,t1);		
			}
			else		
			{
				SetProgressValue(17,cID_Bar1+i,0);
			}
			sprintf(str,"%u-%u\0",TSensorAddrSortingList[i].Addr1,TSensorAddrSortingList[i].Addr2);
			SetTextValue(17,cID_Bar1Text+i,str);	
		}
	}
	SetScreen(11);
}
void DataAnalysis_DA_TRecordSwitchPage(uint16_t cID)
{
	uint32_t i,addr,itemIndex;
	uint8_t t1,t2,tCount,TAddrSortingListIndex;
	uint32_t t;
	char str[50];
	if(DataAnalysis_DA_TPageCountOfRecord<2)
		return;
	if(cID==cID_btBackward)
	{
		DataAnalysis_DA_TPageIndexOfRecord++;
		if(DataAnalysis_DA_TPageIndexOfRecord==DataAnalysis_DA_TPageCountOfRecord)
			DataAnalysis_DA_TPageIndexOfRecord=0;
	}
	else
	{
		if(DataAnalysis_DA_TPageIndexOfRecord==0)
			DataAnalysis_DA_TPageIndexOfRecord=DataAnalysis_DA_TPageCountOfRecord-1;
		else
			DataAnalysis_DA_TPageIndexOfRecord--;
	}
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DA_TPageCountOfRecord,DataAnalysis_DA_TPageIndexOfRecord+1);
	SetTextValue(11,cID_PageNum,str);
	myRecordClear(11,cID_Record,20);
	itemIndex=0;
	for(i=0;i<ItemCountOfRecord;i++)
	{
		itemIndex=i+DataAnalysis_DA_TPageIndexOfRecord*ItemCountOfRecord;
		if(itemIndex>=TAddr1ListCount)
			break;
		t=0;
		tCount=0;
		for(TAddrSortingListIndex=0;TAddrSortingListIndex<TSensorAddrSortingListCount;TAddrSortingListIndex++)
		{
			if(TSensorAddrSortingList[TAddrSortingListIndex].Addr1==TAddr1List[itemIndex])
			{
				FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[TAddrSortingListIndex].SensorIndex);
				if(IsLatestSensorDataValid())
				{
					t+=LatestSensorData.SensorData;
					tCount++;
				}
			}
		}		
		//栋平均温度列表	
		if (tCount!=0)
		{
			t=t/tCount;
			t1=(t&0x0fff)>>4;
			t2=DS18X20_ToDecicel[t&0x000f];			
			sprintf(str,"%u;%u.%u;%u;\0",
				itemIndex+1,t1,t2,TAddr1List[itemIndex]);			
		}
		else		
		{
			sprintf(str,"%u;xx.x;%u;\0",itemIndex+1,TAddr1List[itemIndex]);
		}
		Record_Add(11,cID_Record,str);		
	}
}
void DataAnalysis_DA_TBarChartsSwitchPage(uint16_t cID)
{
	uint32_t i,addr,itemIndex;
	uint8_t t1,t2,tCount,TAddrSortingListIndex;
	uint32_t t;
	char str[50];
	if(DataAnalysis_DA_TPageCountOfBarCharts<2)
		return;
	if(cID==cID_btBackward)
	{
		DataAnalysis_DA_TPageIndexOfBarCharts++;
		if(DataAnalysis_DA_TPageIndexOfBarCharts==DataAnalysis_DA_TPageCountOfBarCharts)
			DataAnalysis_DA_TPageIndexOfBarCharts=0;
	}
	else
	{
		if(DataAnalysis_DA_TPageIndexOfBarCharts==0)
			DataAnalysis_DA_TPageIndexOfBarCharts=DataAnalysis_DA_TPageCountOfBarCharts-1;
		else
			DataAnalysis_DA_TPageIndexOfBarCharts--;
	}
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DA_TPageCountOfBarCharts,DataAnalysis_DA_TPageIndexOfBarCharts+1);
	SetTextValue(15,cID_PageNum,str);
	itemIndex=0;
	for(i=0;i<ItemCountOfBarCharts;i++)
	{
		itemIndex=i+DataAnalysis_DA_TPageIndexOfBarCharts*ItemCountOfBarCharts;
		if(itemIndex>=TAddr1ListCount)
		{
			SetProgressValue(15,cID_Bar1+i,0);
			SetTextValue(15,cID_Bar1Text+i,"\0");
		}
		else
		{
			t=0;
			tCount=0;
			for(TAddrSortingListIndex=0;TAddrSortingListIndex<TSensorAddrSortingListCount;TAddrSortingListIndex++)
			{
				if(TSensorAddrSortingList[TAddrSortingListIndex].Addr1==TAddr1List[itemIndex])
				{
					FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[TAddrSortingListIndex].SensorIndex);
					if(IsLatestSensorDataValid())
					{
						t+=LatestSensorData.SensorData;
						tCount++;
					}
				}
			}		
			if (tCount!=0)
			{
				t=t/tCount;
				t1=(t&0x0fff)>>4;		
				SetProgressValue(15,cID_Bar1+i,t1);				
			}
			else		
			{
				SetProgressValue(15,cID_Bar1+i,0);
			}
			sprintf(str,"%u\0",TAddr1List[itemIndex]);
			SetTextValue(15,cID_Bar1Text+i,str);	
		}	
	}
}
void DataAnalysis_DY_TRecordSwitchPage(uint16_t cID)
{
	uint32_t i,addr,itemIndex;
	uint8_t t1,t2;
	uint32_t t;
	char str[50];
	if(DataAnalysis_DY_TPageCountOfRecord<2)
		return;
	if(cID==cID_btBackward)
	{
		DataAnalysis_DY_TPageIndexOfRecord++;
		if(DataAnalysis_DY_TPageIndexOfRecord==DataAnalysis_DY_TPageCountOfRecord)
			DataAnalysis_DY_TPageIndexOfRecord=0;
	}
	else
	{
		if(DataAnalysis_DY_TPageIndexOfRecord==0)
			DataAnalysis_DY_TPageIndexOfRecord=DataAnalysis_DY_TPageCountOfRecord-1;
		else
			DataAnalysis_DY_TPageIndexOfRecord--;
	}
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DY_TPageCountOfRecord,DataAnalysis_DY_TPageIndexOfRecord+1);
	SetTextValue(13,cID_PageNum,str);
	myRecordClear(13,cID_Record,20);
	itemIndex=0;
	for(i=0;i<ItemCountOfRecord;i++)
	{
		itemIndex=i+DataAnalysis_DY_TPageIndexOfRecord*ItemCountOfRecord;
		if(itemIndex>=TSensorAddrSortingListCount)
			break;
		FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[itemIndex].SensorIndex);
		if(IsLatestSensorDataValid())
		{
			t=LatestSensorData.SensorData;
			t1=(t&0x0fff)>>4;
			t2=DS18X20_ToDecicel[t&0x000f];			
			sprintf(str,"%u;%u.%u;%u-%u;\0",
				itemIndex+1,t1,t2,TSensorAddrSortingList[itemIndex].Addr1,TSensorAddrSortingList[itemIndex].Addr2);	
		}	
		else
		{
			sprintf(str,"%u;xx.x;%u-%u;\0",
				itemIndex+1,TSensorAddrSortingList[itemIndex].Addr1,TSensorAddrSortingList[itemIndex].Addr2);
		}
		Record_Add(13,cID_Record,str);
	}
}
void DataAnalysis_DY_TBarChartsSwitchPage(uint16_t cID)
{
	uint32_t i,addr,itemIndex;
	uint8_t t1,t2,tCount;
	uint32_t t;
	char str[50];
	if(DataAnalysis_DY_TPageCountOfBarCharts<2)
		return;
	if(cID==cID_btBackward)
	{
		DataAnalysis_DY_TPageIndexOfBarCharts++;
		if(DataAnalysis_DY_TPageIndexOfBarCharts==DataAnalysis_DY_TPageCountOfBarCharts)
			DataAnalysis_DY_TPageIndexOfBarCharts=0;
	}
	else
	{
		if(DataAnalysis_DY_TPageIndexOfBarCharts==0)
			DataAnalysis_DY_TPageIndexOfBarCharts=DataAnalysis_DY_TPageCountOfBarCharts-1;
		else
			DataAnalysis_DY_TPageIndexOfBarCharts--;
	}
	sprintf(str,"共%u页，第%u页\0",DataAnalysis_DY_TPageCountOfBarCharts,DataAnalysis_DY_TPageIndexOfBarCharts+1);
	SetTextValue(17,cID_PageNum,str);
	itemIndex=0;
	for(i=0;i<ItemCountOfBarCharts;i++)
	{
		itemIndex=i+DataAnalysis_DY_TPageIndexOfBarCharts*ItemCountOfBarCharts;
		if(itemIndex>=TSensorAddrSortingListCount)
		{
			SetProgressValue(17,cID_Bar1+i,0);
			SetTextValue(17,cID_Bar1Text+i,"\0");
		}
		else
		{
			FRAM_GetLatestSensorData(TemperatureSensor,TSensorAddrSortingList[itemIndex].SensorIndex);
			if(IsLatestSensorDataValid())
			{
				t=LatestSensorData.SensorData;
				t1=(t&0x0fff)>>4;		
				SetProgressValue(17,cID_Bar1+i,t1);		
			}
			else		
			{
				SetProgressValue(17,cID_Bar1+i,0);
			}
			sprintf(str,"%u-%u\0",TSensorAddrSortingList[itemIndex].Addr1,TSensorAddrSortingList[itemIndex].Addr2);
			SetTextValue(17,cID_Bar1Text+i,(uint8_t*)str);
		}	
	}
}