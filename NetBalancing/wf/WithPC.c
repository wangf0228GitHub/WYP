#include "WithPC.h"
#include "Verify.h"
#include "CP1616_Client.h"
#include "FRAM.h"
#include "wfDefine.h"
#include "SPIROM.h"
#include "hmi_driver.h"


void ProcCommandFromPC( void )
{
	uint8_t sum,Command,tx[10];
	uint8_t i,x1,x2,j;
	uint16_t len,count;
	uint32_t addr;
	sum=GetVerify_Sum(CP1616_Client_RxList,CP1616_Client_NeedRxCount-2);
	if(sum!=CP1616_Client_RxList[CP1616_Client_NeedRxCount-2])
	{
		CP1616_Client_EndProcCommand();
		return;
	}
	Command=CP1616_Client_RxList[pCP1616_CommandIndex];
	switch(Command)
	{
	case 1://建立连接
		CP1616_Client_EndProcCommand();
		tx[0]=HIGH_BYTE(ROMParams.DeviceID);
		tx[1]=LOW_BYTE(ROMParams.DeviceID);
		CP1616_Client_SendData(Command,tx,2);
		SetScreen(32);
		break;
	case 2://断开连接		
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);			
// 		FRAM_GetROMParams();
// 		WorkMode_RealTimeUIInit();
// 		Setting_UIInit();
// 		SetScreen(1);
		NVIC_SystemReset();
		break;
	case 3://设定地址
		FRAM_SaveSensorAddr();
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);	
		break;
	case 4://读取当前数据
		//64+(2+6)*100=861
 		sum=CP1616_Client_SendHeader(Command,800+AREALEN);			
		sum+=GetVerify_Sum(ROMParams.InstallArea,AREALEN);
		CP1616_Client_TxProc(ROMParams.InstallArea,AREALEN);
		for(i=0;i<100;i++)
		{
			FRAM_GetSensorDataInfo(TemperatureSensor,i);
			FRAM_GetLatestSensorData(TemperatureSensor,i);
			tx[0]=SensorDataInfo.Addr1;
			tx[1]=SensorDataInfo.Addr2;			
			for(j=0;j<6;j++)
			{
				tx[2+j]=LatestSensorData.All[j];
			}
			sum+=GetVerify_Sum(tx,8);
			CP1616_Client_TxProc(tx,8);
		}
		tx[0]=sum;
		tx[1]=0x0d;
		CP1616_Client_TxProc(tx,2);
		CP1616_Client_EndProcCommand();
		break;
	case 5://读出历史数据
 		FRAM_GetSensorDataInfo(TemperatureSensor,CP1616_Client_RxList[pCP1616_ClientData]);
		tx[0]=SensorDataInfo.Addr1;
		tx[1]=SensorDataInfo.Addr2;
 		if(SensorDataInfo.bLoop!=0)//循环了
 		{
			sum=CP1616_Client_SendHeader(Command,602+AREALEN);//2+6*100+AREALEN			
			CP1616_Client_TxProc(ROMParams.InstallArea,AREALEN);
			sum+=GetVerify_Sum(ROMParams.InstallArea,AREALEN);
			tx[0]=SensorDataInfo.Addr1;
			tx[1]=SensorDataInfo.Addr2;
			CP1616_Client_TxProc(tx,2);
 			sum+=GetVerify_Sum(tx,2);
			if(SensorDataInfo.curDataSaveIndex==(SensorDataItemCount-1))//最新的再队尾
			{
				addr=TSensor1DataAddr+(uint32_t)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount;
				for(i=0;i<SensorDataItemCount;i++)
				{
					SPIROM_ReadArray(addr,tx,6);
					CP1616_Client_TxProc(tx,6);
					sum+=GetVerify_Sum(tx,6);
					addr+=6;
				}
			}
			else//在队中，则最旧数据在当前位置的下一个
			{
				i=SensorDataInfo.curDataSaveIndex+1;
				addr=TSensor1DataAddr+(uint32_t)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount+(uint32_t)(i)*6;
				for(;i<SensorDataItemCount;i++)
				{
					SPIROM_ReadArray(addr,tx,6);
					CP1616_Client_TxProc(tx,6);
					sum+=GetVerify_Sum(tx,6);
					addr+=6;
				}
				addr=TSensor1DataAddr+(uint32_t)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount;
				for(i=0;i<=SensorDataInfo.curDataSaveIndex;i++)
				{
					SPIROM_ReadArray(addr,tx,6);
					CP1616_Client_TxProc(tx,6);
					sum+=GetVerify_Sum(tx,6);
					addr+=6;
				}
			} 			
 		}
 		else//没有存储满，则最旧的一个在第0位
 		{
			if(SensorDataInfo.curDataSaveIndex==0xff)//还没有数据
			{
				len=2+AREALEN;
				sum=CP1616_Client_SendHeader(Command,len);
				CP1616_Client_TxProc(ROMParams.InstallArea,AREALEN);
				sum+=GetVerify_Sum(ROMParams.InstallArea,AREALEN);
				tx[0]=SensorDataInfo.Addr1;
				tx[1]=SensorDataInfo.Addr2;
				CP1616_Client_TxProc(tx,2);
				sum+=GetVerify_Sum(tx,2);
			}
			else
			{
				len=((uint16_t)(SensorDataInfo.curDataSaveIndex+1))*6+2+AREALEN;
				sum=CP1616_Client_SendHeader(Command,len);
				CP1616_Client_TxProc(ROMParams.InstallArea,AREALEN);
				sum+=GetVerify_Sum(ROMParams.InstallArea,AREALEN);
				tx[0]=SensorDataInfo.Addr1;
				tx[1]=SensorDataInfo.Addr2;
				CP1616_Client_TxProc(tx,2);
				sum+=GetVerify_Sum(tx,2);
				addr=TSensor1DataAddr+(uint32_t)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount;
				for(i=0;i<=SensorDataInfo.curDataSaveIndex;i++)
				{
					SPIROM_ReadArray(addr,tx,6);
					CP1616_Client_TxProc(tx,6);
					sum+=GetVerify_Sum(tx,6);
					addr+=6;
				}
			}
 			
 		}		
		tx[0]=sum;
		tx[1]=0x0d;
		CP1616_Client_TxProc(tx,2);
		CP1616_Client_EndProcCommand();
		break;
	case 6://删除历史数据
		x1=CP1616_Client_RxList[pCP1616_ClientData];
		x2=CP1616_Client_RxList[pCP1616_ClientData+1];
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);	
		FRAM_InitSensorData(x1,x2);
		break;
	case 7://读取参数信息
		//64+(2+6)*100=861
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendData(Command,ROMParams.All,ROMParamsCount);
		break;
	case 100://设置DeviceID
		x1=CP1616_Client_RxList[pCP1616_ClientData];
		x2=CP1616_Client_RxList[pCP1616_ClientData+1];
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);
		ROMParams.DeviceID=MAKE_SHORT(x1,x2);
		FRAM_SaveROMParams();
		break;
	}
}




