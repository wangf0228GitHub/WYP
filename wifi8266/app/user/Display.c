
#include "c_types.h"
#include "..\..\include\gpio.h"
#include "..\..\include\osapi.h"
#include "Display.h"
#include "DS18B20.h"
#include "uart_register.h"


const unsigned char SegCode[] =            
{
	Bmp0Map,Bmp1Map,Bmp2Map,Bmp3Map,Bmp4Map,Bmp5Map,Bmp6Map,Bmp7Map, //LCD段码表
	Bmp8Map,Bmp9Map,BmpAMap,BmpBMap,BmpCMap,BmpDMap,BmpEMap,BmpFMap,
	BmprMap
};
const unsigned char DS18X20_ToDecicel[16]={
	0,
	1,
	1,
	2,
	3,
	3,
	4,
	4,
	5,
	6,
	6,
	7,
	8,
	8,
	9,
	9
};
unsigned char TxTemperature[4];
unsigned char DpyNum[6];
unsigned char ErrState;
#define HT162X_CS_W 12
#define HT162X_WR_W 13
#define HT162X_DATA_W 14
void ICACHE_FLASH_ATTR HT162X_Init( void )
{
// 	// 选择为gpio功能
// 	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDI_U, FUNC_GPIO12);
// 	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_GPIO13);
// 	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTMS_U, FUNC_GPIO14);
	GPIO_OUTPUT_SET(HT162X_CS_W,1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
}

void ICACHE_FLASH_ATTR HT162X_Setting(unsigned char x)
{
	unsigned char i;
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	GPIO_OUTPUT_SET(HT162X_CS_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	for(i=0; i<9; i++) 
	{   
		if((x & 0x80)==0x80) 
			GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
		else 
			GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,1);
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,0);
		x=x<<1; 
	}  
	GPIO_OUTPUT_SET(HT162X_CS_W,1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
}
void ICACHE_FLASH_ATTR HT162X_WriteData(unsigned char reg,unsigned char d)
{
	unsigned char i;
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	GPIO_OUTPUT_SET(HT162X_CS_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	reg=reg<<2;
	for(i=0; i<6; i++) 
	{   
		if((reg & 0x80)==0x80) 
			GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
		else 
			GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,1);
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,0);
		reg=reg<<1; 
	}  
	for(i=0; i<5; i++) 
	{   
		if((d & 0x01)==0x01) 
			GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
		else 
			GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,1);
		os_delay_us(10);
		GPIO_OUTPUT_SET(HT162X_WR_W,0);
		d=d>>1; 
	}
	GPIO_OUTPUT_SET(HT162X_CS_W,1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
}
void ICACHE_FLASH_ATTR HT162X_WriteDatas(unsigned char reg,const unsigned char* pBuf,unsigned char count)
{
	unsigned char i,j,x;
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	GPIO_OUTPUT_SET(HT162X_CS_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	reg=reg<<2;
	for(i=0; i<6; i++) 
	{   
		if((reg & 0x80)==0x80) 
			GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
		else 
			GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
		os_delay_us(1);
		GPIO_OUTPUT_SET(HT162X_WR_W,1);
		os_delay_us(1);
		GPIO_OUTPUT_SET(HT162X_WR_W,0);
		reg<<=1; 
	}  
	for(i=0; i<count; i++) 
	{   
		x=*pBuf;
		for(j=0;j<4;j++)
		{ 
			if((x & 0x01)==0x01) 
				GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
			else 
				GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
			os_delay_us(1);
			GPIO_OUTPUT_SET(HT162X_WR_W,1);
			os_delay_us(1);
			GPIO_OUTPUT_SET(HT162X_WR_W,0);
			x>>=1; 
		}
		pBuf++;
	}  
	GPIO_OUTPUT_SET(HT162X_CS_W,1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
}
#define HT162X_SYS_EN 0b00000001 
#define HT162X_LCD_ON 0b00000011 
void ICACHE_FLASH_ATTR Display_Init(void)
{
	HT162X_Init();
	HT162X_Setting(0b00101000);
	HT162X_Setting(HT162X_SYS_EN);
	HT162X_Setting(HT162X_LCD_ON);
}
void ICACHE_FLASH_ATTR LCDShow(void)
{
	unsigned char i,j,x;
	unsigned char reg=0;
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	GPIO_OUTPUT_SET(HT162X_CS_W,0);
	os_delay_us(10);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_DATA_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
	os_delay_us(1);
	GPIO_OUTPUT_SET(HT162X_WR_W,0);
	reg=reg<<2;
	for(i=0; i<6; i++) 
	{   
		if((reg & 0x80)==0x80) 
			GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
		else 
			GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
		os_delay_us(1);
		GPIO_OUTPUT_SET(HT162X_WR_W,1);
		os_delay_us(1);
		GPIO_OUTPUT_SET(HT162X_WR_W,0);
		reg<<=1; 
	}  
	for(i=0; i<8; i++) 
	{   
		x=sensor_data.DisplayReg[i];
		for(j=0;j<4;j++)
		{ 
			if((x & 0x01)==0x01) 
				GPIO_OUTPUT_SET(HT162X_DATA_W,1); 
			else 
				GPIO_OUTPUT_SET(HT162X_DATA_W,0); 
			os_delay_us(1);
			GPIO_OUTPUT_SET(HT162X_WR_W,1);
			os_delay_us(1);
			GPIO_OUTPUT_SET(HT162X_WR_W,0);
			x>>=1; 
		}
	}  
	GPIO_OUTPUT_SET(HT162X_CS_W,1);
	GPIO_OUTPUT_SET(HT162X_WR_W,1);
}
void ICACHE_FLASH_ATTR LcdDisplayNum(void)
{
#ifdef NoScreen
	return;
#endif
	if(DpyNum[0]&Smg_a) 
	{
		SA1; 
	}
	else  
	{		
		_SA1;
	}
	if(DpyNum[0]&Smg_b) 
	{		 
		SB1; 
	}
	else  
	{		 
		_SB1;
	}
	if(DpyNum[0]&Smg_c)  
	{		 
		SC1; 
	}
	else  
	{		 
		_SC1;
	}
	if(DpyNum[0]&Smg_d)  
	{		 
		SD1; 
	}
	else  
	{		 
		_SD1;
	}
	if(DpyNum[0]&Smg_e)  
	{		 
		SE1; 
	}
	else  
	{		 
		_SE1;
	}
	if(DpyNum[0]&Smg_f)  
	{		 
		SF1; 
	}
	else  
	{
		 
		_SF1;
	}
	if(DpyNum[0]&Smg_g)
	{		 
		SG1; 
	}
	else  
	{		
		_SG1;
	}

	if(DpyNum[1]&Smg_a)  
	{		 
		SA2; 
	}
	else  
	{		 
		_SA2;
	}
	if(DpyNum[1]&Smg_b)  
	{		 
		SB2; 
	}
	else  
	{		 
		_SB2;
	}
	if(DpyNum[1]&Smg_c)  
	{		 
		SC2; 
	}
	else  
	{		 
		_SC2;
	}
	if(DpyNum[1]&Smg_d)  
	{		 
		SD2; 
	}
	else  
	{		 
		_SD2;
	}
	if(DpyNum[1]&Smg_e)  
	{		 
		SE2; 
	}
	else  
	{		 
		_SE2;
	}
	if(DpyNum[1]&Smg_f)  
	{		 
		SF2; 
	}
	else  
	{		 
		_SF2;
	}
	if(DpyNum[1]&Smg_g)  
	{		 
		SG2; 
	}
	else  
	{		 
		_SG2;
	}
	if(DpyNum[1]&Smg_dp) 
	{		 
		SP1; 
	}
	else  
	{		 
		_SP1;
	}

	if(DpyNum[2]&Smg_a)  
	{		 
		SA3; 
	}
	else  
	{		 
		_SA3;
	}
	if(DpyNum[2]&Smg_b)  
	{		 
		SB3; 
	}
	else  
	{		 
		_SB3;
	}
	if(DpyNum[2]&Smg_c)  
	{		 
		SC3; 
	}
	else  
	{		 
		_SC3;
	}
	if(DpyNum[2]&Smg_d)  
	{		 
		SD3; 
	}
	else  
	{		 
		_SD3;
	}
	if(DpyNum[2]&Smg_e)  
	{		 
		SE3; 
	}
	else  
	{		 
		_SE3;
	}
	if(DpyNum[2]&Smg_f)  
	{		 
		SF3; 
	}
	else  
	{		 
		_SF3;
	}
	if(DpyNum[2]&Smg_g) 
	{		 
		SG3; 
	}
	else  
	{		 
		_SG3;
	}
}
void ICACHE_FLASH_ATTR LcdDisplayAll(unsigned char x)
{
#ifdef NoScreen
	return;
#endif
	unsigned char i;
	if(x==0)
	{
		for(i=0;i<8;i++)
			sensor_data.DisplayReg[i]=0x0f;
	}
	else if(x==1)
	{
		for(i=0;i<8;i++)
			sensor_data.DisplayReg[i]=0x00;
	}
	else if(x==2)
	{
		DpyNum[0]=BmpAMap;
		DpyNum[1]=BmpAMap;
		DpyNum[2]=BmpAMap;
		_S01;		 
		_S02;		 
		_S03;		 
		_S04;		 
		_S05;		 
		_S06;		 
		_S07;		 
		_S08;		 
		_S09;		 
		_S10;
		LcdDisplayNum();
	}
	LCDShow();
}

void ICACHE_FLASH_ATTR LcdDisplay_CurTemp(void)
{
	unsigned char t1,t2;
	unsigned int t;
#ifdef NoScreen
	return;
#endif
	if(GETFLG(flg_bErrShow)==bTrue)
	{
		return;
	}
	if(sensor_data.DST_H==0xf0)
	{
		DpyNum[0]=BmpEMap;
		DpyNum[1]=Bmp0Map;
		DpyNum[2]=Bmp1Map;
		S08;
		_S04;
	}
	else
	{
		_S08;
		S04;
		t=sensor_data.DST_H;
		t=t<<8;
		t=t+sensor_data.DST_L;
		t1=t>>4;
		t2=t&0x0f;
		t2=DS18X20_ToDecicel[t2];
		DpyNum[0]=SegCode[t1/10];
		DpyNum[1]=SegCode[t1%10];
		DpyNum[1] |= Smg_dp;
		DpyNum[2]=SegCode[t2];
	}
	LcdDisplayNum();	
	LCDShow();
}
void ICACHE_FLASH_ATTR LcdDisplay_Err(void)
{
#ifdef NoScreen
	return;
#endif
	SETFLG(flg_bErrShow);
	sensor_data.ErrTick=0;
	_S04;	
	S08;
	DpyNum[0]=BmpEMap;
	DpyNum[1]=SegCode[ErrState/10];
	DpyNum[2]=SegCode[ErrState%10];		
	LcdDisplayNum();
	LCDShow();
}
void ICACHE_FLASH_ATTR GotoSleep(void)
{
	if(GETFLG(flg_bWifi)==bFasle)
	{
		return;
	}
 	if(bDS18B20!=0 || bSendding!=0 || bKey!=0)
 		return;
 	os_timer_disarm(&TickTimer); 	
 	if(GETFLG(flg_bNeedTx)==bTrue)
 	{
 		system_deep_sleep_set_option(1);		
 	}
 	else
 	{
		CLEARFLG(flg_FisrtUp);
		CLEARFLG(flg_bNotify);
		_S01;
		_S03;
		_S05;
		_S06;
 		system_deep_sleep_set_option(4);
 	}
	system_rtc_mem_write(SENSOR_DATA_MEM_ADDR, &sensor_data, sizeof(SENSOR_DATA_RTC_MEM));
 // 	SET_PERI_REG_MASK(UART_CONF0(0), UART_TXFIFO_RST);//RESET FIFO
 // 	CLEAR_PERI_REG_MASK(UART_CONF0(0), UART_TXFIFO_RST);
 // 	system_deep_sleep_instant(1000000); 
 	system_deep_sleep(1000000);
}

void ICACHE_FLASH_ATTR MakeTxTemperature(unsigned char tH,unsigned char tL)
{
	unsigned char x;
	x=HIGH_NIBBLE(tH);
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
	x=LOW_NIBBLE(tH);
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
	x=HIGH_NIBBLE(tL);
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
	x=LOW_NIBBLE(tL);
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

