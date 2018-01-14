#include "main.h"
void InitMCU(void)             //系统初始化程序
{	
	//AD初始化	
	ADCON1=0b00111111;  //全部为数据口
	
	ANSELA=0;
	ANSELB=0;
	ANSELD=0;
	ANSELE=0;

	POWER_ON_W=0;
	POWER_ON_IO=0;	
	STATUS_IO=1;

	nWPUEN=0;
	TestMode_DIR=1;
	TestMode_WPUB=1;

	LED1_W=0;
	LED2_W=0;

	LED1_DIR=0;
	LED2_DIR=0;

	KeyNotify_IO=1;
	/************************************************************************/
	/* TMR2 AT指令，20ms                                                 */
	/************************************************************************/
	T2CON=0b00111011;//1:128
	PR2=227;
	TMR2ON=0;
	TMR2IE=0;//使能中断
	TMR2IF=0;//清中断标志
	/************************************************************************/
	/* TMR1 系统节拍，100ms                                                 */
	/************************************************************************/
	T1CON=0b01110000;//1:1	
	WRITETIMER1(T1CYCLE_4M);
	TMR1ON=1;
	TMR1IE=1;//使能中断
	TMR1IF=0;//清中断标志

	
	/************************************************************************/
	/* 串口1																*/
	/************************************************************************/
 	TRISC7=1;
 	TRISC6=1;
 	TXSTA=0b00100110;//异步方式、使能发送(bit6=1是9位数据)八位字长、高波特率(bit2低速0)
 	RCSTA=0b10010000; //使能串口、使能接收、异步方式、(bit6=1是9位数据)八位字长
 	SPBRG=25;//0x67;	//Baud Rate = Fosc/(16(SPBRG+1)) = 9600
 	RCIE=1;//使能中断
 	RCIF=0;//清中断标志
	
	PEIE=1;
	GIE=1;
}
void InitVariable(void)
{
	if(GetRomData()==0)
	{
		RomParams.bWinter=1;
		SaveRomData();
	}
	gFlags.AllFlag=0;		
	SystemTick=0;	
#ifdef Test12M
	NeedMeasurementTick=600;
#elif defined(Test2M)
	NeedMeasurementTick=100;
#elif defined(Test)
	NeedMeasurementTick=1;
#else
	if(RomParams.bWinter==0)//夏天
	{
		NeedMeasurementTick=36000;//每小时测量一次
	}
	else
	{
		NeedMeasurementTick=6000;//每10分钟测量一次
	}
#endif	
	TxErrDataIndex=0;
}

void InitSystem( void )
{
	unsigned char x;
	InitMCU();	
	InitVariable();		
#ifndef NoScreen
	DisplayInit();
	if(RomParams.bWinter==0)//夏天
	{
		while(WA==0);//请勿按键
		S10=1;//感叹号
	}
	else
	{
		while(WA==0);//请勿按键
		S10=0;//感叹号
	}
#endif
	ATCommand_Init();	

	x=10;
	while(x!=0)
	{
		if(OneWire_Reset()==0) //单总线复位成功
		{
			gFlags.b18B20=1;
			break;
		}
		x--;
	}
	if(x==0)//没有18b20
	{
		gFlags.b18B20=0;
		TCN75_Init();
		TCN75_Config.bShutdown=1;
		TCN75_Config.COMP_INT=0;
		TCN75_Config.Polarity=0;
		TCN75_Config.FaultQueue=0b00;
		TCN75_Config.Resolution=0b11;
		TCN75_Config.OneShot=0;	
		TCN75_SetConfig();
	}
	__delay_20ms(50);
	ReadTData();
	__delay_20ms(250);
}
