#include "HardwareProfile.h"
void BigDelay(unsigned int x)//20ms为基数
{
	unsigned int x1;
#ifdef Proteus
	__delay_20ms(x);
	return;
#endif
	OSCCON=0b00000010;//内部晶振
	while(x--)
	{
		__delay_us(D32ms_31K);
	}
	OSCCON=0b00000000;//外部晶振
	while(OSTS==0);
	x1=((x+25)/50);
	NoCalls+=x1;
	//	NeedSendSMS+=x1;
}
void LowPower_Init(void)
{
	WDTCON=0b00011101;//看门狗16s

	/************************************************************************/
	/* 外部中断1,用于按键                                                   */
	/************************************************************************/
	TRISB2=1;
	IOCBP2=0;
	IOCBN2=1;//检测下降沿
	IOCBF2=0;
	TRISB3=1;
	IOCBP3=0;
	IOCBN3=0;//IOCBN3=1;//取消另一个按键
	IOCBF3=0;
	IOCIE=0;
}
void LowPower_High(void)
{
	TMR2IE=0;	
	TMR2ON=0;			
	IOCIE=0;
	TMR1ON=0;
	OSCCON=0b00000000;//外部晶振
	while(OSTS==0);
	SystemTick=0;
	WRITETIMER1(T1CYCLE_4M);	
	TMR1ON=1;
}
void LowPower_Low(void)
{
	/************************************************************************/
	/* 切换时钟                                                             */
	/************************************************************************/
	TMR1ON=0;
	OSCCON=0b00000010;//内部晶振
	SystemTick=0;

	IOCBP2=0;
	IOCBN2=1;//检测下降沿
	IOCBF2=0;
	IOCBF3=0;
	IOCIE=1;
}
void LowPower_Wait(void)
{
	if(ErrState==NoErr)
	{
		if(gFlags.bSMS)
		{
			gFlags.bSMS=0;
			return;//continue;
		}
		x1=(SystemTick+5)/10;
		NoCalls+=x1;
		//				NeedSendSMS+=x1;

#ifndef NoScreen
		while(WA==0);//请勿按键
		S01=0;
		while(WA==0);
		S03=0;
		while(WA==0);//低温投诉
		S05=0;
		while(WA==0);
		S06=0;
#endif

#ifdef  Test_4M
		CallDelay=10;
#else
		CallDelay=56;
#endif
		while(CallDelay!=0)
		{
			//__delay_ms(1);
			CallDelay--;
#ifndef NoScreen
			S07=!S07;
#endif
			SLEEP();
			NOP();
			if(gFlags.bKey)
			{
				while(gFlags.bKey);
				break;
			}
			if(gFlags.bTest)
			{
				//test();
				gFlags.bTest=0;
			}
			NoCalls+=16;
			//					NeedSendSMS+=16;
		}
		// 			SLEEP();
		// 			NOP();
	}
	else
	{
		BigDelay(3000);//60S
		OldTemp.u16=ErrDS18X20_T;
	}
}