#include "HardwareProfile.h"
void InitMCU(void)             //系统初始化程序
{	
	RCON=0;
	//AD初始化	
	ADCON1=0b00111111;  //全部为数据口

	Si4463_SDN_W=1;//si4432复位	
	Si4463_SDN_DIR=0;	
	/************************************************************************/
	/* TMR2 强制按钮延时，1ms                                               */
	/************************************************************************/
// 	T2CON=0b01111010;//1:256,10us
// 	PR2=196;//50+ms
// 	TMR2IE=1;//使能中断
// 	TMR2IF=0;//清中断标志

	IDLEN=0;
	/************************************************************************/
	/* 外部中断1                                                            */
	/************************************************************************/
// 	TRISB1=1;
// 	TRISB0=1;
// 	INTEDG0=0;
// 	INT0IF=0;
// 	INT0IE=0;
	/************************************************************************/
	/* 串口1																*/
	/************************************************************************/
// 	TRISC7=1;
// 	TRISC6=1;
// 	TXSTA=0b00100110;//异步方式、使能发送(bit6=1是9位数据)八位字长、高波特率(bit2低速0)
// 	RCSTA=0b10010000; //使能串口、使能接收、异步方式、(bit6=1是9位数据)八位字长
// 	//BAUDCON1=0x40;//不用自动波特率自动检测
// 	SPBRG=0x67;	//Baud Rate = Fosc/(16(SPBRG+1)) = 9600
// 	RCIP=0;//低优先级
// 	RCIE=1;//使能中断
// 	RCIF=0;//清中断标志
	
// 	PEIE=1;
// 	GIE=1;
}
void InitVariable(void)
{
	gFlags.AllFlag=0;	
//	SystemTick=0;
	PickDatas.T1.u16=0xffff;

	if(GetRomData()==0)
	{
		ROMParams.MyAddr=0x01;
		ROMParams.WirelessPowerLevel=4;
		ROMParams.WirelessParamIndex=0;
		//
		ROMParams.SystemState.bWinter=1;
		ROMParams.PickCycle=1;
		SaveRomData();	
	}

// 	ROMParams.MyAddr.u8H=0;
// 	ROMParams.MyAddr.u8L=1;
	
	PickDatas.index=ROMParams.MyAddr;
}

void InitSystem( void )
{
	//unsigned int ii;
	InitMCU();
	InitVariable();		
  	Si4463_Init();
}
