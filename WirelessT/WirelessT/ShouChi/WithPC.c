#include "HardwareProfile.h"


void ProcCommandFromPC( void )
{
	unsigned char sum,Command,tx[10];
	unsigned char i,x1,x2,j;
	unsigned int len,count;
	unsigned long addr;
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
// 		CP1616_Client_EndProcCommand();
// 		CP1616_Client_SendOK(Command);	
		CP1616_Client_EndProcCommand();
		unsigned char sum;
		sum=0;
		SetTx_CP1616_Client();
		CP1616_Client_AddTxHeader();
		CP1616_Client_TxByteWithVerify(Command);
		CP1616_Client_TxByteWithVerify(0x00);
		CP1616_Client_TxByteWithVerify(0x02);
		CP1616_Client_TxByteWithVerify(HIGH_BYTE(ROMParams.DeviceID));
		CP1616_Client_TxByteWithVerify(LOW_BYTE(ROMParams.DeviceID));
		CP1616_Client_AddTxEnder();
		SetRx_CP1616_Client();	
		break;
	case 2://断开连接		
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);	
		WorkMode=WorkMode_Main;
		Display_ShowPic(1);
		SleepTick=SystemTick;
		gFlags.bSleep=0;
		gFlags.bSleep1=0;
		break;
	case 3://设定地址
		FRAM_SaveSensorAddr(CP1616_Client_RxList[pCP1616_ClientData],&CP1616_Client_RxList[pCP1616_ClientData+2],CP1616_Client_RxList[pCP1616_ClientData+1]);
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);	
		break;
	case 4://读取当前数据
		sum=0;
		SetTx_CP1616_Client();
		CP1616_Client_AddTxHeader();
		CP1616_Client_TxByteWithVerify(Command);
		CP1616_Client_TxByteWithVerify(0x0A);
		CP1616_Client_TxByteWithVerify(0x8c);
		for(i=0;i<100;i++)
		{
			FRAM_GetSensorDataInfo(i);
			FRAM_GetSensorData(i,tx);
			for(j=0;j<21;j++)
			{
				CP1616_Client_TxByteWithVerify(SensorDataInfo.InstallPosition[j]);
			}
			for(j=0;j<6;j++)
			{
				CP1616_Client_TxByteWithVerify(tx[j]);
			}
		}
		CP1616_Client_AddTxEnder();
		SetRx_CP1616_Client();
		CP1616_Client_EndProcCommand();
		break;
	case 5://读出历史数据
		sum=0;
		FRAM_GetSensorDataInfo(CP1616_Client_RxList[pCP1616_ClientData]);		
		SetTx_CP1616_Client();
		CP1616_Client_AddTxHeader();
		CP1616_Client_TxByteWithVerify(Command);
		if(SensorDataInfo.bLoop!=0)//循环了
		{
			len=1281;
			CP1616_Client_TxByteWithVerify(HIGH_BYTE(len));
			CP1616_Client_TxByteWithVerify(LOW_BYTE(len));
			for(i=0;i<21;i++)
			{
				CP1616_Client_TxByteWithVerify(SensorDataInfo.InstallPosition[i]);
			}
			addr=Sensor1DataAddr+(unsigned long)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount+(unsigned long)(SensorDataInfo.curIndex)*6;
			for(i=SensorDataInfo.curIndex;i<210;i++)
			{
				SPIROM_ReadArray(addr,tx,6);
				for(j=0;j<6;j++)
				{
					CP1616_Client_TxByteWithVerify(tx[j]);
				}
				addr+=6;
			}
			addr=Sensor1DataAddr+(unsigned long)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount;
			for(i=0;i<SensorDataInfo.curIndex;i++)
			{
				SPIROM_ReadArray(addr,tx,6);
				for(j=0;j<6;j++)
				{
					CP1616_Client_TxByteWithVerify(tx[j]);
				}
				addr+=6;
			}
		}
		else
		{
			len=((unsigned int)SensorDataInfo.curIndex)*6+21;
			CP1616_Client_TxByteWithVerify(HIGH_BYTE(len));
			CP1616_Client_TxByteWithVerify(LOW_BYTE(len));
			FRAM_GetSensorDataInfo(CP1616_Client_RxList[pCP1616_ClientData]);
			for(i=0;i<21;i++)
			{
				CP1616_Client_TxByteWithVerify(SensorDataInfo.InstallPosition[i]);
			}
			addr=Sensor1DataAddr+(unsigned long)(CP1616_Client_RxList[pCP1616_ClientData])*SensorDataListCount+SensorDataInfoCount;
			for(i=0;i<SensorDataInfo.curIndex;i++)
			{
				SPIROM_ReadArray(addr,tx,6);
				for(j=0;j<6;j++)
				{
					CP1616_Client_TxByteWithVerify(tx[j]);
				}
				addr+=6;
			}
		}		
		CP1616_Client_AddTxEnder();
		SetRx_CP1616_Client();
		CP1616_Client_EndProcCommand();
		break;
	case 6://删除历史数据
		x1=CP1616_Client_RxList[pCP1616_ClientData];
		x2=CP1616_Client_RxList[pCP1616_ClientData+1];
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);	
		FRAM_InitSensorData(x1,x2);
		break;
	case 100://设置DeviceID
		x1=CP1616_Client_RxList[pCP1616_ClientData];
		x2=CP1616_Client_RxList[pCP1616_ClientData+1];
		CP1616_Client_EndProcCommand();
		CP1616_Client_SendOK(Command);
		ROMParams.DeviceID=MAKE_INT(x1,x2);
		FRAM_SaveROMParams();
		break;
	}
}




