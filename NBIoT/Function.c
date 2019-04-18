#include "HardwareProfile.h"
#include "string.h"
#include "stdio.h"
#include <ctype.h>
#include "stdlib.h"
void PowerON(void)
{
	POWER_ON_W=1;
	__delay_20ms(5);
	POWER_ON_W=0;
	__delay_20ms(500);	
}
void CallProc(void)
{
#ifndef NoScreen
	while(WA==0);//请勿按键
	S01=1;
	while(WA==0);
	S03=1;
	while(WA==0);
	S07=0;
	while(WA==0);
	S08=0;
	if(gFlags.bNotify)
	{
		while(WA==0);//低温投诉
		S05=1;
		while(WA==0);
		S06=1;
	}
#endif
	unsigned char retry=2;
	while(retry!=0)
	{
		ErrState=NoErr;	
		gFlags.bRetry=0;	
		CallSend();
		if(gFlags.bRetry)
		{
			retry--;
// 			if(ErrState!=NoErr)
// 			{
// 				LcdDisplay_Err();
// 			}
			LcdDisplay_CurTemp();
			__delay_20ms(3000);//未连接上服务器，等一分钟重试一次
		}
		else
			break;
	}
	//取消“请勿按键”
#ifndef NoScreen
	while(WA==0);//请勿按键
	S01=0;
	while(WA==0);
	S03=0;
	while(WA==0);//低温投诉
	S05=0;
	while(WA==0);
	S06=0;
	if(ErrState!=NoErr)
	{
		LcdDisplay_Err();
	}
	else
	{
		LcdDisplay_CurTemp();
	}
#endif
}

void CallSend(void)
{
	unsigned char i,ret;
	char *strx=0;	
	ErrState=NoErr;
	InitGPRS();
	if(ErrState!=NoErr)
	{
		__delay_20ms(3000);
		ErrState=NoErr;
		InitGPRS();
		if(ErrState!=NoErr)
			return;
	}
// 	ATCommand_SendCmd("AT+CIPSTATUS\0");
// 	strcpy(ATCommand_OkString,"CONNECT OK");

	if(ATCommand_SendCmd("AT+NSOCR=STREAM,6,0,1\0")!=ATACK_OK)
	{
		ErrState=MissAT_NSOCR;
		return;
	}
	ATCommand_RetryTimes=1;
	ATCommand_WaitACKTimes=300;
	if(ATCommand_SendCmd("AT+NSOCO=1,\"www.wlwdjcy.com\",12129\0")!=ATACK_OK)
	{
		ErrState=MissAT_NSOCR;
		return;
	}

	__delay_20ms(50);

	ret=InteractServer();
	ATCommand_SendCmd("AT+NSOCL=1\0");//断开连接
	ATCommand_SendCmd("AT+CPSMS=1,,,01000111,00000001\0");
	if(ret!=ATACK_OK)
	{
		gFlags.bRetry=1;
		return;
	}	
}
unsigned char InteractServer()
{
	unsigned char res=0; 
	unsigned char retry,i,j,k,addr;
	uint t;
	unsigned int txLen;
	retry=1;//ATCommand_RetryTimes;
	res=ATACK_Null;
	while(retry!=0)
	{		
		if(gFlags.bFirst)//开机第一次呼叫
		{
			ATCommand_PutString("AT+NSOSD=1,32,\0");	
			Uart1_PutString_Hex("@#pt#1#\0");	
			Uart1_PutString_Hex(ICCID);
			Uart1_PutHex('#');
			if(RomParams.bWinter==0)//夏天
			{
				Uart1_PutString_Hex("60#\0");//夏季60分钟
			}
			else
			{
				Uart1_PutString_Hex("10#\0");//每10分钟测量一次
			}
			MakeTxTemperature(CurTemp);
			for(int i=0;i<4;i++)
			{
				Uart1_PutHex(TxTemperature[i]);
			}
		}
		else if(gFlags.bNotify)//呼叫
		{
			ATCommand_PutString("AT+NSOSD=1,32,\0");	
			Uart1_PutString_Hex("@#pt#3#\0");	
			Uart1_PutString_Hex(ICCID);
			Uart1_PutHex('#');
			if(RomParams.bWinter==0)//夏天
			{
				Uart1_PutString_Hex("60#\0");//夏季60分钟
			}
			else
			{
				Uart1_PutString_Hex("10#\0");//每10分钟测量一次
			}
			MakeTxTemperature(CurTemp);
			for(int i=0;i<4;i++)
			{
				Uart1_PutHex(TxTemperature[i]);
			}
		}
		else//正常发送
		{		
			if(TxErrDataIndex!=0xff)//之前有错误发生
			{
				if(gFlags.bErrFull)//已经存储满了
				{
					ATCommand_PutString("AT+NSOSD=1,687,\0");	//12*10*5+12*5-1+28					
				}
				else
				{
					ATCommand_PutString("AT+NSOSD=1,\0");	//12*10*5+12*5-1	
					txLen=28;
					for(i=0;i<TxErrDataIndex;i++)
					{
						txLen+=60;
					}
					txLen+=59;
					if(txLen/100!=0)
						Uart1_PutChar('0'+txLen/100);//659,
					txLen=txLen%100;
					Uart1_PutChar('0'+txLen/10);
					Uart1_PutChar('0'+txLen%10);
					Uart1_PutChar(',');
				}
			}
			else
			{
				ATCommand_PutString("AT+NSOSD=1,87,\0");	//12*10*5+12*5-1	
			}
			Uart1_PutString_Hex("@#pt#2#\0");
			Uart1_PutString_Hex(ICCID);
			Uart1_PutHex('#');
			if(RomParams.bWinter==0)//夏天
			{
				Uart1_PutString_Hex("60#\0");//夏季60分钟
			}
			else
			{
				Uart1_PutString_Hex("10#\0");//每10分钟测量一次
			}
			if(TxErrDataIndex!=0xff)//之前有错误发生
			{
				if(gFlags.bErrFull)//已经存储满了
				{
					for(i=(TxErrDataIndex-1);i<10;i--)
					{
						for(j=0;j<MaxTList;j++)
						{
							addr=(i)*12;
							addr+=TxErrDataPtr;
							addr+=(j<<1);
							t.u8s[0]=eeprom_read(addr);
							t.u8s[1]=eeprom_read(addr+1);
							MakeTxTemperature(t);
							for(k=0;k<4;k++)
							{
								Uart1_PutHex(TxTemperature[k]);
							}
							Uart1_PutHex('|');
						}
					}
					for(i=9;i>TxErrDataIndex;i--)
					{
						for(j=0;j<MaxTList;j++)
						{
							addr=(i)*12;
							addr+=TxErrDataPtr;
							addr+=(j<<1);
							t.u8s[0]=eeprom_read(addr);
							t.u8s[1]=eeprom_read(addr+1);
							MakeTxTemperature(t);
							for(k=0;k<4;k++)
							{
								Uart1_PutHex(TxTemperature[k]);
							}
							Uart1_PutHex('|');
						}
					}
				}
				else
				{
					for(i=0;i<TxErrDataIndex;i++)
					{
						for(j=0;j<MaxTList;j++)
						{
							addr=i*12;
							addr+=TxErrDataPtr;
							addr+=(j<<1);
							t.u8s[0]=eeprom_read(addr);
							t.u8s[1]=eeprom_read(addr+1);
							MakeTxTemperature(t);
							for(k=0;k<4;k++)
							{
								Uart1_PutHex(TxTemperature[k]);
							}
							Uart1_PutHex('|');
						}
					}
				}
			}
			for(i=0;i<MaxTList;i++)
			{
				MakeTxTemperature(TList.T[i]);
				for(int j=0;j<4;j++)
				{
					Uart1_PutHex(TxTemperature[j]);
				}
				if(i!=(MaxTList-1))
				{
					Uart1_PutHex('|');
				}
			}			
		}
		Uart1_PutHex('#');
		Uart1_PutHex('@');
		ATCommand_WaitACKTimes=400;
		strcpy(ATCommand_OkString,"NSONMI");	
		strcpy(ATCommand_ErrString,"ERROR");
		ATCommand_Clear='+';
		ATCommand_PutString(ATCommand_EndChar);		
		res=ATCommand_WaitData();
		if(res!=ATACK_Null)
			break;
		ATCommand_WaitClientInterval();
		retry--;
	}
	return res;
}
void MakeTxTemperature(uint T)
{
	unsigned char x;
	x=HIGH_NIBBLE(T.u8H);
	if(x>9)
	{
		x=x-10;
		x=x+0x41;
		TxTemperature[0]=x;
	}
	else
	{
		x=x+'0';
		TxTemperature[0]=x;
	}
	x=LOW_NIBBLE(T.u8H);
	if(x>9)
	{
		x=x-10;
		x=x+0x41;
		TxTemperature[1]=x;
	}
	else
	{
		x=x+'0';
		TxTemperature[1]=x;
	}
	x=HIGH_NIBBLE(T.u8L);
	if(x>9)
	{
		x=x-10;
		x=x+0x41;
		TxTemperature[2]=x;
	}
	else
	{
		x=x+'0';
		TxTemperature[2]=x;
	}
	x=LOW_NIBBLE(T.u8L);
	if(x>9)
	{
		x=x-10;
		x=x+0x41;
		TxTemperature[3]=x;
	}
	else
	{
		x=x+'0';
		TxTemperature[3]=x;
	}
}

void InitGPRS(void)
{
	unsigned char retry,i;
	char *strx=0;
	PowerON();
	if(ATCommand_SendCmd("AT\0")!=ATACK_OK)
	{
		ErrState=MissAT;
		return;
	}
	
	if(ATCommand_SendCmd("ATE1\0")!=ATACK_OK)
	{
		ErrState=MissAT_ATE1;
		return;
	}	
	retry=10;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CIMI\0")==ATACK_OK)
		{
			break;
		}
		__delay_20ms(150);
		retry--;		
	}	
	if(retry==0)
	{
		ErrState=MissSimCard;//没有网络
		return;
	}
	retry=10;
	while(retry!=0)
	{

		if(ATCommand_SendCmd("AT+NCCID\0")==ATACK_OK)
		{
			strx=strstr((const char*)ATCommand_RxList,"8986");
			if(strx!=0)
			{
				for(i=0;i<15;i++)
				{
					ICCID[i]=strx[i+5];
				}
				ICCID[15]='\0';
				break;
			}
			else
			{
				retry--;
				__delay_20ms(150);
			}
		}
			
	}
	retry=100;
	CSQ=0xff;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CSQ\0")==ATACK_OK)
		{
			strx=strstr((const char*)ATCommand_RxList,"+CSQ:");
			if(strx!=0)
			{
				CSQ=atoi(strx+5);
#ifndef NoScreen
				LcdDisplay_CSQ();
#endif
				if(CSQ!=0 && CSQ!=99)
					break;
				else
				{
					retry--;
					__delay_20ms(150);
				}
			}
			else
			{
				retry--;
				__delay_20ms(150);
			}
		}		
	}
	if(retry==0 && CSQ!=0xff)
	{
		ErrState=MissAT_CSQ;
		return;
	}
	retry=20;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CEREG?\0")!=ATACK_OK)
		{		
			ErrState=MissAT_COPS;
			return;
		}
		strx=strstr((const char*)ATCommand_RxList,"+CEREG:0,1");
		if(strx!=0)
		{
			break;
		}
		__delay_20ms(150);
		retry--;		
	}
	if(retry==0)
	{
		ErrState=MissNet;//没有网络
		return;
	}

}


