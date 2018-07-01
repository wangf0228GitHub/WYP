//Build F:\work_tfs\MCU\WYP\Saving2\Saving2 for device 18F6621
//Using driver C:\Program Files\HI-TECH Software\PICC-18\PRO\9.63\bin\picc18.exe
#include "HardwareProfile.h"
__CONFIG(1,XINSTDIS&WDTEN&STVREN);
__CONFIG(2,HS&FCMEN&IESOEN&WDTPS256);//看门狗2s复位
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
void main()
{	
	unsigned char i,length;
	unsigned int x,n;
	char tx[10];
	unsigned char buffer[20];
	InitSystem();
#ifdef RXTEST
	Wireless_WorkInit();
	Si4463_FIFO_INFO(tx);
	Si4463_INT_STATUS(tx);
	Si4463_PART_INFO(tx);
	Si4463_START_RX(ROMParams.WirelessParamIndex,0x00,PACKET_LENGTH,0x08,0x08,0x08);
	while(1)
	{
		CLRWDT();
		if(Si4463_NIRQ_R==0)
		{
			Si4463_INT_STATUS(tx);
			if((tx[3] & ( 1<<4 ))!=0)
			{
				Si4463_READ_PACKET(PickDatas.All);
				Si4463_FIFO_INFO(tx);		
// 				sum=GetVerify_Sum(PickDatas.All,PACKET_LENGTH-1);
// 				if(sum==PickDatas.sum)
// 				{
// 					DS1302_GetTime();
// 					SensorData4Save.Month=DS1302_GetNum(DS1302_Time.Month);
// 					SensorData4Save.Day=DS1302_GetNum(DS1302_Time.Day);
// 					SensorData4Save.Hour=DS1302_GetNum(DS1302_Time.Hour);
// 					SensorData4Save.Minute=DS1302_GetNum(DS1302_Time.Minute);
// 					SensorData4Save.TData.u16=PickDatas.T1.u16;
// 					SensorDataSecond=DS1302_GetNum(DS1302_Time.Second&0x7f);
// 					gFlags.bNewT=1;
// 					if(gFlags.bUseFram)
// 					{
// 						SPIROM_CS_W=1;
// 						gFlags.bINT=1;				
// 					}
// 					FRAM_SaveSensorData();
// 				}
			}
		}
	}
#endif
#ifdef TXTEST
	
	unsigned char length;
	unsigned char error;
	Wireless_WorkInit();
	while(1)
	{
		while(1)
		{		  
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
	//Wireless_WorkInit();
	//  	while(1)
	//  	{
	// 	 	Wireless_WorkInit();
	// 		Si4463_FIFO_INFO(tx);
	// 		Si4463_INT_STATUS(tx);
	//  		Si4463_SEND_PACKET( PickDatas.All, 3, 1, 0 );
	//  		do{             
	//  			Si4463_INT_STATUS( tx );          //读状态寄存器
	//  		}while( ( tx[3] & ( 1<<5 ) )==0x00 ); //等待发射完成（发射中断产生）
	//  		NOP();
	//  		Si4463_SDN_W=1;
	//  		DelayS(3);
	//  	}
	MovePIN_DIR=1;
	//LATC5=1;
	if(TO)//非看门狗复位
	{
		Wireless_WorkInit();
		Si4463_FIFO_INFO(tx);
		Si4463_INT_STATUS(tx);
		Si4463_START_RX(SetFreq,0x00,PACKET_LENGTH,0x08,0x05,0x08);
		n=900;
		gFlags.bSet=0;
		while(1)
		{
			CLRWDT();
			if(Si4463_NIRQ_R==0)
			{
				Si4463_INT_STATUS(tx);
				if((tx[3] & ( 1<<4 ))!=0)
				{
					Si4463_READ_PACKET(tx);
					
					PickDatas.All[0]=tx[0];
					PickDatas.All[1]=0;//tx[1];	
					PickDatas.All[2]='o';
					PickDatas.All[3]='k';
					PickDatas.sum=GetVerify_Sum(PickDatas.All,PACKET_LENGTH-1);

					ROMParams.MyAddr=tx[0];
					ROMParams.WirelessParamIndex=0;//tx[1];
					SaveRomData();
					if(GetRomData()!=0)
					{
						if(ROMParams.MyAddr==PickDatas.All[0])
						{
							Si4463_FIFO_INFO(tx);
							Si4463_INT_STATUS(tx);
							Si4463_SEND_PACKET(PickDatas.All,PACKET_LENGTH,SetFreq,0x00);//发送完成休眠					
							TxTick=20;
							while(TxTick!=0)
							{				
								if(Si4463_NIRQ_R==0)
								{
									Si4463_INT_STATUS(tx);
									if((tx[3] & ( 1<<5 ))!=0)
									{
										gFlags.bSet=1;
										break;
									}
								}
								__delay_ms(20);
								TxTick--;
							}
						}
						if(TxTick==0)
						{
							Wireless_WorkInit();
							Si4463_FIFO_INFO(tx);
							Si4463_INT_STATUS(tx);
							Si4463_START_RX(SetFreq,0x00,PACKET_LENGTH,0x08,0x05,0x08);
						}
						else
							break;
					}				
					else
					{
						Wireless_WorkInit();
						Si4463_FIFO_INFO(tx);
						Si4463_INT_STATUS(tx);
						Si4463_START_RX(SetFreq,0x00,PACKET_LENGTH,0x08,0x05,0x08);
					}					
				}				
			}
			__delay_ms(10);
			n--;
			if(n==0)
				break;
			if(gFlags.bSet)
				break;
		}
	}
// 	i=GetRomData();
// 	if(i==0 || ROMParams.WirelessPowerLevel==0)//持续低功耗
// 	{
// 		Si4463_SDN_W = 1;//禁用无线模块
// 		while(1)
// 		{
// 			GIE=0;
// 			SLEEP();
// 			NOP();
// 			NOP();	
// 		}
// 	}
// 	else
// 	{
// 
// 	}	
	SystemState=0;
	//Wireless_WorkInit();
	while(1)
	{
		switch(SystemState)
		{
		case 0://该启动采集温度了
			if(MovePIN_R)
				PickDatas.StateBits.bMove=0;
			else
				PickDatas.StateBits.bMove=1;
			while(OSTS==0);
			if(DS18X20_StartMeas()==DS18X20_ERROR)//18b20无法复位
			{
				PickDatas.T1.u16=0xffff;
				ErrT++;
				if(ErrT>ErrT_Max)
				{
					ErrT=100;
					PickDatas.StateBits.bBreak=1;
					SystemState=2;//发送
				}							
			}
			else
			{
				ErrT=0;
				SystemState=1;
				DelayS(1);//1s			
			}		
			break;
		case 1://该采集温度了
			while(OSTS==0);
			DS18b20Retry=3;
			PickDatas.T1.u16=0xffff;
			PickDatas.StateBits.bBreak=1;	
			while(DS18b20Retry!=0)
			{
				DS18b20Retry--;				
				if(DS18X20_ReadMeas(1)==DS18X20_ERROR)//读数错误
				{
					continue;
				}
				else
				{
					ErrT=0;
					PickDatas.StateBits.bBreak=0;
					PickDatas.T1.u8s[0]=DS18X20_Scratchpad[0];
					PickDatas.T1.u8s[1]=DS18X20_Scratchpad[1];	
					break;
				}
			}	
			if(PickDatas.StateBits.bBreak)
			{
				PickDatas.StateBits.bBreak=0;
				ErrT++;
				if(ErrT>ErrT_Max)
				{
					ErrT=100;
					PickDatas.T1.u16=0xffff;
					PickDatas.StateBits.bBreak=1;					
				}
			}
			SystemState=2;//发送
			break;
		case 2://发送	
			Wireless_WorkInit();
			Si4463_FIFO_INFO(tx);
			Si4463_INT_STATUS(tx);
// 			for( i = 0; i < 10; i ++ )      { buffer[i] = i; }
// 			Si4463_SEND_PACKET( buffer, 10, 0, 0 );
// 			
			PickDatas.sum=GetVerify_Sum(PickDatas.All,PACKET_LENGTH-1);
			Si4463_SEND_PACKET(PickDatas.All,PACKET_LENGTH,ROMParams.WirelessParamIndex,0x00);//发送完成休眠
			TxTick=50;
			while(TxTick!=0)
			{				
				if(Si4463_NIRQ_R==0)
				{
					Si4463_INT_STATUS(tx);
					if((tx[3] & ( 1<<5 ))!=0)
						break;
				}
				__delay_ms(20);
				TxTick--;
			}
			if(TxTick==0)
				Wireless_WorkInit();
			SystemState=0;
			Si4463_SDN_W=1;
			n=30+(rand()%60);			
			//__delay_20ms(200);
			DelayS(n);
			//GotoSleep_Minute(ROMParams.PickCycle);//10m
			// 				n=rand()%1200;
			// 				n=n<<2;
			// 				GotoSleep(n);
			break;
		}				
	}
}
void interrupt highISR(void)
{	
	if(TMR2IE&&TMR2IF)//接收超时
	{	
		TMR2IF=0;
		Wait4TMR2--;
		if(Wait4TMR2==0)
		{
			gFlags.bWaitOut=1;
			TMR2ON=0;
		}
	}
}
void DelayS(unsigned char ns)
{
	unsigned char i;
#ifdef Debug 
	__delay_20ms(5);
#else
	OSCCON=0b00000011;//rc振荡器
	//GIE=0;
	for(i=0;i<ns;i++)
	{		
		SLEEP();
		NOP();
		NOP();			
	}
	OSCCON=0b00000010;
	while(OSTS==0);
	//GIE=1;	
#endif

}
