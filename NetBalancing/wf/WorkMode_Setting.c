#include "WorkMode_Setting.h"
#include "TFTWorkProc.h"
#include "cmd_process.h"
#include "FRAM.h"
#include "WirelessProc.h"
#include "Si4463.h"
#include "Verify.h"


void Setting_SensorProgram( void )
{
	uint8_t sensorID,tx[10],sum,testCount;
	uint32_t SensorProgramTick,retry;
	if(ReadTextbox(27,50)==0);
	{
		ShowFailDialog(27,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&sensorID);	
	Wireless_SetInit();
	testCount=20;
	SetProgressValue(27,51,testCount);//重试次数20次
	tx[0]=sensorID;
	tx[1]=0;//sensorFreq;
	while(testCount!=0)
	{			
		retry=5;
		while(retry!=0)
		{
			retry--;				
			Si4463_SEND_PACKET(tx,PACKET_LENGTH,SetFreq,0x00);
			SensorProgramTick=GetCurTick();
			while(1)
			{				
				if(bRFIRQ())
				{
					Si4463_INT_STATUS(Si4463Temp);
					if((Si4463Temp[3] & ( 1<<5 ))!=0)//发送成功
					{
						retry=0xff;
						break;
					}
				}
				if(GetDeltaTick(SensorProgramTick)>500)
				{
					Wireless_SetInit();
					break;
				}
			}
			if(retry==0xff)
				break;
		}
		if(retry==0)//发送失败
		{
			ShowFailDialog(27,"发送数据超时，请重试");
			return;
		}
		Si4463_FIFO_INFO(Si4463Temp);
		Si4463_INT_STATUS(Si4463Temp);
		Si4463_PART_INFO(Si4463Temp);
		Si4463_START_RX(SetFreq,0x00,PACKET_LENGTH,0x08,0x08,0x08);
		SensorProgramTick=GetCurTick();
		while(1)
		{				
			if(bRFIRQ())
			{
				Si4463_INT_STATUS(Si4463Temp);
				if((Si4463Temp[3] & ( 1<<4 ))!=0)
				{
					Si4463_READ_PACKET(Si4463Temp);
					if(Si4463Temp[0]==sensorID)
					{
						sum=GetVerify_Sum(Si4463Temp,PACKET_LENGTH-1);
						if(sum==Si4463Temp[PACKET_LENGTH-1])
						{
							if(Si4463Temp[0]==sensorID && Si4463Temp[2]=='o' && Si4463Temp[3]=='k')// && Si4463Temp[1]==sensorFreq)
							{
								WirelessOff();
								ShowSuccessDialog(27);
								return;
							}
						}		
					}				
					Si4463_FIFO_INFO(Si4463Temp);
				}
			}
			if(GetDeltaTick(SensorProgramTick)>1000)
			{
				break;
			}
		}	
		testCount--;
		SetProgressValue(27,51,testCount);
	}
	WirelessOff();
	ShowFailDialog(27,"设置失败");
}
void Setting_IntervalAnalysis( void )
{
	uint32_t t1,t2,t3,t4;
	if(ReadTextbox(25,50)==0);
	{
		ShowFailDialog(25,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&t1);	
	if(ReadTextbox(25,51)==0);
	{
		ShowFailDialog(25,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&t2);
	if(ReadTextbox(25,52)==0);
	{
		ShowFailDialog(25,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&t3);
	if(ReadTextbox(25,53)==0);
	{
		ShowFailDialog(25,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&t4);
	ROMParams.TimeSpan1=t1;
	ROMParams.TimeSpan2=t2;
	ROMParams.TimeSpan3=t3;
	ROMParams.TimeSpan4=t4;
	FRAM_SaveROMParams();
	ShowSuccessDialog(21);
}
void Setting_SleepTimesSpan( void )
{	
	if(ReadTextbox(26,50)==0);
	{
		ShowFailDialog(26,"获取数据超时，请重试");
		return;
	}
	sscanf((char *)controlValue,"%d",&ROMParams.SleepTimeSpan);	
	FRAM_SaveROMParams();
	ShowSuccessDialog(21);
}
