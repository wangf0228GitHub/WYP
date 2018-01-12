//Build F:\work_tfs\MCU\WYP\Saving2\Saving2 for device 18F6621
//Using driver C:\Program Files\HI-TECH Software\PICC-18\PRO\9.63\bin\picc18.exe
#include "HardwareProfile.h"
__CONFIG(1,XINSTDIS&WDTEN&STVREN);
__CONFIG(2,HSPLL&FCMEN&IESOEN&WDTPS32K);//看门狗2s复位
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


void InitSystem(void);
void GetAD(void);
//void ProcRxFromPC( void );
void main()
{	
	unsigned char i,length;
	unsigned int x;	
	unsigned char sum;
	char tx[10];	
	InitSystem();
	//__delay_20ms(10);
	while(1)
	{
		if(SystemTick>30)
		{
			Display_ShowPic(1);
			GetAD();
			Display_ShowBatt();
			ADTick=SystemTick;
			break;
		}
	}
#ifdef TXTEST
	unsigned char buffer[20];
	unsigned char length,TxTick;
	unsigned char error;
	Wireless_SetInit();

	while(1)
	{
		while(1)
		{	
			CLRWDT();
			for( i = 0; i < 10; i ++ )      { buffer[i] = i; } //发送数字0-9

			Si4463_SEND_PACKET( buffer, 10, 0, 0 ); //发射数据包
			do{             
				Si4463_INT_STATUS( buffer );          //读状态寄存器
			}while( !( buffer[3] & ( 1<<5 ) ) ); //等待发射完成（发射中断产生）
			//---------------------------------------------------------------------------------------
			Si4463_START_RX( 0, 0, PACKET_LENGTH,0,0,3 );//进入接收模式，等待应答信号

			TxTick=20;
			while(TxTick!=0)
			{	
				__delay_ms(20);
				if(Si4463_NIRQ_R==0)
				{
					Si4463_INT_STATUS(tx);
					if((tx[3] & ( 1<<4 ))!=0)
					{
						length = Si4463_READ_PACKET( buffer );
						for( i = 0, error = 0; i < 10; i ++ )//判断数据是否有误
						{
							if( buffer[i] != i + 10 ) // 装入应答数据 10-19
							{
								error = 1;
								break;
							}
						}
						if( length == 10 && error == 0 )  //10字节应答信号, 且数据无误
						{												                            
							//Wait_Ack =1; //通讯成功标志位置1
							break;
						}
					}
				}			
				TxTick--;
			}		
		}
		__delay_20ms(200);
	}
#endif
	SleepTick=SystemTick;
	gFlags.bSleep=0;
	gFlags.bSleep1=0;
	while(1)
	{
		CLRWDT();
		if(NewOFF_R==0)
		{
			__delay_ms(20);
			if(NewOFF_R==0)
			{
				NewON_W=0;
				while (1);
			}
		}
		if(GetDeltaTick(ADTick)>100)
		{
			GetAD();
			Display_ShowBatt();
			ADTick=SystemTick;
		}
		switch(WorkMode)
		{
		case WorkMode_Main:
			WorkMode_MainProc();
			break;
		case WorkMode_Analyze:
			WorkMode_AnalyzeProc();
			break;
		case WorkMode_RealTime:
			WorkMode_RealTimeProc();
			break;
		case WorkMode_History:
			WorkMode_HistoryProc();
			break;
		case WorkMode_Setting:
			WorkMode_SettingProc();
			break;
		case WorkMode_WithPC:
			if(CP1616_Client_Flags.bRx)
			{
				ProcCommandFromPC();
			}
			if(GetDeltaTick(CP1616_Client_NoRxTick)>3000)
			{
				WorkMode=WorkMode_Main;
				Display_ShowPic(1);
				SleepTick=SystemTick;
				gFlags.bSleep=0;
				gFlags.bSleep1=0;
			}
			break;
		}	
		if(WorkMode!=WorkMode_WithPC)
		{
			if(CP1616_Client_Flags.bRx)
			{
				sum=GetVerify_Sum(CP1616_Client_RxList,CP1616_Client_NeedRxCount-2);
				if(sum==CP1616_Client_RxList[CP1616_Client_NeedRxCount-2])
				{
					WorkMode=WorkMode_WithPC;
					Display_BK(0xff);
					gFlags.bSleep=0;
					gFlags.bSleep1=0;
					Display_BK(80);
					Display_Clear();
					Display_ConPC();
					ProcCommandFromPC();
					CP1616_Client_NoRxTick=SystemTick;
				}
			}
		}
		if(WorkMode!=WorkMode_WithPC)
		{
			if(gFlags.bSleep)
			{
				if(GetDeltaTick(SleepTick)>ROMSleepTick)
				{
					Si4463_SDN_W=1;
					NewON_W=0;
					while (1)
					{
						CLRWDT();
						SLEEP();
						NOP();
						NOP();
					}
				}
			}
			else if(gFlags.bSleep1)
			{
				if(GetDeltaTick(SleepTick)>200)
				{
					SleepTick=SystemTick;
					gFlags.bSleep=1;
					Display_BK(0);
				}
			}
			else
			{
				if(GetDeltaTick(SleepTick)>100)
				{
					gFlags.bSleep1=1;
					gFlags.bSleep=0;
					SleepTick=SystemTick;
					Display_BK(10);
				}
			}
		}
	}
// 	while(1)
// 	{
//  		CLRWDT();
// 		switch(SystemMode)
// 		{
// 		case ModeMenu:
// 			ModeMenu_Proc();
// 			break;
// 		case Mode1:
// 			Mode1_Proc();
// 			break;
// 		case Mode2:
// 			Mode2_Proc();
// 			break;
// 		case Mode3:
// 			Mode3_Proc();
// 			break;
// 		case Mode4:
// 			Mode4_Proc();
// 			break;
// 		}
// 		if((SystemTick-LCDCKTick)>200)
// 		{
// 			LCD_CK_W=0;
// 		}
// 		if((SystemTick-SleepTick)>1200)//2分钟休眠
// 		{			
// 			LCD160X_OFF();
// 			LCD_RST_W=0;
// 			PEIE=0;
// 			GIE=0;
// 			TMR1IE=0;//使能中断
// 			LCD_CK_W=0;
// 			RCIE=0;		
// 			Si4432_SDN_W=1;
// 			while(1)
// 			{
// 				SLEEP();
// 			}
// 		}
// 	}
}
//#define SetWirelessRx() 	Si4432_WriteRegister(0x08, 0x03); \
//	Si4432_WriteRegister(0x08, 0x00); \
//	Si4432_WriteRegister(0x05, 0x03); \
//	Si4432_WriteRegister(0x06, 0x00); \
//	ItStatus1 = Si4432_ReadRegister(0x03); \
//	ItStatus2 = Si4432_ReadRegister(0x04); \
//	Si4432_WriteRegister(0x07, 0x05) 
void interrupt highISR(void)
{
	unsigned char sum;
	if(INT0IE&&INT0IF)
	{
		NoWirelessRxTick=SystemTick;		
		Si4463_INT_STATUS(Si4463Temp);
		if((Si4463Temp[3] & ( 1<<4 ))!=0)
		{
			Si4463_READ_PACKET(PickDatas.All);
			Si4463_FIFO_INFO(Si4463Temp);		
			sum=GetVerify_Sum(PickDatas.All,PACKET_LENGTH-1);
			if(sum==PickDatas.sum)
			{
				DS1302_GetTime();
				SensorData4Save.Month=DS1302_GetNum(DS1302_Time.Month);
				SensorData4Save.Day=DS1302_GetNum(DS1302_Time.Day);
				SensorData4Save.Hour=DS1302_GetNum(DS1302_Time.Hour);
				SensorData4Save.Minute=DS1302_GetNum(DS1302_Time.Minute);
				SensorData4Save.TData.u16=PickDatas.T1.u16;
				SensorDataSecond=DS1302_GetNum(DS1302_Time.Second&0x7f);
				gFlags.bNewT=1;
				if(gFlags.bUseFram)
				{
					SPIROM_CS_W=1;
					gFlags.bINT=1;				
				}
				FRAM_SaveSensorData();
			}
		}
		//Si4463_START_RX(0,0x00,PACKET_LENGTH,0x00,0x00,0x00);
		INT0IF=0;			
	}
}
void interrupt low_priority lowISR(void)
{
	unsigned char rx;
	if(RC2IE&&RC2IF)
	{
		RC2IF=0;
		if(OERR==1)
		{
			CREN=0;
			OERR=0;
			CREN=1;
		}
		rx=RCREG2;
		CP1616_Client_ProcRx(rx);
	}
	if(INT1IE&&INT1IF)
	{
		INT1IF=0;
	}
	if(TMR1IE&&TMR1IF)//接收超时
	{
		TMR1IF=0;
		WRITETIMER1(15535);//100ms
		SystemTick++;
	}	
	if(TMR0IE&&TMR0IF)//接收超时
	{
		TMR0IF=0;
		TMR0ON=0;
		WRITETIMER1(20536);//100ms
		gFlags.bWaitShow=0;
	}	
}
void GetAD(void)
{
	unsigned char i;
	unsigned int ADSum,x;
	ADON=1;
	__delay_ms(1);
	ADSum=0;
	for(i=0;i<8;i++)
	{
		GODONE=1;			
		while(GODONE);
		x=MAKE_INT(ADRESH,ADRESL);
		ADSum+=x;
		__delay_ms(5);			
	}
	ADValue=ADSum>>3;
	ADON=0;
}
