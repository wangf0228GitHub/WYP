#include "HardwareProfile.h"
#include "Display.h"
#include <stdio.h>

unsigned char DpyNum[6]= {Smg_g,Smg_g,Smg_g,Smg_g,Smg_g,Smg_g}; 

//-------------------------------------------------------------------------------
//                         LCD显示程序
//S01-S09为1时显示对应的字符，为0时关闭对应的字符
//-------------------------------------------------------------------------------
void LcdDisplayNum(void)
{
#ifdef NoScreen
	return;
#endif
	if(DpyNum[0]&Smg_a) 
	{
		while(WA==0);
		SA1 = 1; 
	}
	else  
	{
		while(WA==0);
		SA1 = 0;
	}
	if(DpyNum[0]&Smg_b) 
	{
		while(WA==0);
		SB1 = 1; 
	}
	else  
	{
		while(WA==0);
		SB1 = 0;
	}
	if(DpyNum[0]&Smg_c)  
	{
		while(WA==0);
		SC1 = 1; 
	}
	else  
	{
		while(WA==0);
		SC1 = 0;
	}
	if(DpyNum[0]&Smg_d)  
	{
		while(WA==0);
		SD1 = 1; 
	}
	else  
	{
		while(WA==0);
		SD1 = 0;
	}
	if(DpyNum[0]&Smg_e)  
	{
		while(WA==0);
		SE1 = 1; 
	}
	else  
	{
		while(WA==0);
		SE1 = 0;
	}
	if(DpyNum[0]&Smg_f)  
	{
		while(WA==0);
		SF1 = 1; 
	}
	else  
	{
		while(WA==0);
		SF1 = 0;
	}
	if(DpyNum[0]&Smg_g)
	{
		while(WA==0);
		SG1 = 1; 
	}
	else  
	{
		while(WA==0);
		SG1 = 0;
	}

	if(DpyNum[1]&Smg_a)  
	{
		while(WA==0);
		SA2 = 1; 
	}
	else  
	{
		while(WA==0);
		SA2 = 0;
	}
	if(DpyNum[1]&Smg_b)  
	{
		while(WA==0);
		SB2 = 1; 
	}
	else  
	{
		while(WA==0);
		SB2 = 0;
	}
	if(DpyNum[1]&Smg_c)  
	{
		while(WA==0);
		SC2 = 1; 
	}
	else  
	{
		while(WA==0);
		SC2 = 0;
	}
	if(DpyNum[1]&Smg_d)  
	{
		while(WA==0);
		SD2 = 1; 
	}
	else  
	{
		while(WA==0);
		SD2 = 0;
	}
	if(DpyNum[1]&Smg_e)  
	{
		while(WA==0);
		SE2 = 1; 
	}
	else  
	{
		while(WA==0);
		SE2 = 0;
	}
	if(DpyNum[1]&Smg_f)  
	{
		while(WA==0);
		SF2 = 1; 
	}
	else  
	{
		while(WA==0);
		SF2 = 0;
	}
	if(DpyNum[1]&Smg_g)  
	{
		while(WA==0);
		SG2 = 1; 
	}
	else  
	{
		while(WA==0);
		SG2 = 0;
	}
	if(DpyNum[1]&Smg_dp) 
	{
		while(WA==0);
		SP1 = 1; 
	}
	else  
	{
		while(WA==0);
		SP1 = 0;
	}

	if(DpyNum[2]&Smg_a)  
	{
		while(WA==0);
		SA3 = 1; 
	}
	else  
	{
		while(WA==0);
		SA3 = 0;
	}
	if(DpyNum[2]&Smg_b)  
	{
		while(WA==0);
		SB3 = 1; 
	}
	else  
	{
		while(WA==0);
		SB3 = 0;
	}
	if(DpyNum[2]&Smg_c)  
	{
		while(WA==0);
		SC3 = 1; 
	}
	else  
	{
		while(WA==0);
		SC3 = 0;
	}
	if(DpyNum[2]&Smg_d)  
	{
		while(WA==0);
		SD3 = 1; 
	}
	else  
	{
		while(WA==0);
		SD3 = 0;
	}
	if(DpyNum[2]&Smg_e)  
	{
		while(WA==0);
		SE3 = 1; 
	}
	else  
	{
		while(WA==0);
		SE3 = 0;
	}
	if(DpyNum[2]&Smg_f)  
	{
		while(WA==0);
		SF3 = 1; 
	}
	else  
	{
		while(WA==0);
		SF3 = 0;
	}
	if(DpyNum[2]&Smg_g) 
	{
		while(WA==0);
		SG3 = 1; 
	}
	else  
	{
		while(WA==0);
		SG3 = 0;
	}	
}	
void LcdDisplayAll(unsigned char x)
{
#ifdef NoScreen
	return;
#endif
	if(x==0)
	{
		DpyNum[0]=0xff;
		DpyNum[1]=0xff;
		DpyNum[2]=0xff;
		LcdDisplayNum();
		while(WA==0);
		S01=1;
		while(WA==0);
		S02=1;
		while(WA==0);
		S03=1;
		while(WA==0);
		S04=1;
		while(WA==0);
		S05=1;
		while(WA==0);
		S06=1;
		while(WA==0);
		S07=1;
		while(WA==0);
		S08=1;
		while(WA==0);
		S09=1;
		while(WA==0);
		S10=1;
	}
	else if(x==1)
	{
		DpyNum[0]=0;
		DpyNum[1]=0;
		DpyNum[2]=0;
		LcdDisplayNum();
		while(WA==0);
		S01=0;
		while(WA==0);
		S02=0;
		while(WA==0);
		S03=0;
		while(WA==0);
		S04=0;
		while(WA==0);
		S05=0;
		while(WA==0);
		S06=0;
		while(WA==0);
		S07=0;
		while(WA==0);
		S08=0;
		while(WA==0);
		S09=0;
		while(WA==0);
		S10=0;
	}
	else if(x==2)
	{
		DpyNum[0]=BmpAMap;
		DpyNum[1]=BmpAMap;
		DpyNum[2]=BmpAMap;
		LcdDisplayNum();
		while(WA==0);
		S01=0;
		while(WA==0);
		S02=0;
		while(WA==0);
		S03=0;
		while(WA==0);
		S04=0;
		while(WA==0);
		S05=0;
		while(WA==0);
		S06=0;
		while(WA==0);
		S07=0;
		while(WA==0);
		S08=0;
		while(WA==0);
		S09=0;
		while(WA==0);
		S10=0;
	}
}
void LcdDisplay_CSQ(void)
{
	unsigned char t1,t2;
#ifdef NoScreen
	return;
#endif
	t1=CSQ/10;
	t2=CSQ%10;
	DpyNum[0]=BmpPMap;
	DpyNum[1]=SegCode[t1];
	DpyNum[2]=SegCode[t2];
	LcdDisplayNum();	
}
void LcdDisplay_CurTemp(void)
{
	unsigned char t1,t2;
#ifdef NoScreen
	return;
#endif
	if(CurTemp.u16==ErrDS18X20_T)
	{
		DpyNum[0]=BmpEMap;
		DpyNum[1]=Bmp0Map;
		DpyNum[2]=Bmp1Map;
		while(WA==0);
		S08=1;
		while(WA==0);
		S04=0;
	}
	else
	{
		while(WA==0);
		S04=1;
		t1=CurTemp.u16>>4;
		t2=CurTemp.u16&0x0f;
		t2=DS18X20_ToDecicel[t2];
		DpyNum[0]=SegCode[t1/10];
		DpyNum[1]=SegCode[t1%10];
		DpyNum[1] |= Smg_dp;
		DpyNum[2]=SegCode[t2];
	}
	LcdDisplayNum();	
}
void LcdDisplay_Err(void)
{
#ifdef NoScreen
	return;
#endif
	while(WA==0);
	S04=0;	
	while(WA==0);
	S08=1;
	DpyNum[0]=BmpEMap;
	DpyNum[1]=SegCode[ErrState/10];
	DpyNum[2]=SegCode[ErrState%10];		
	LcdDisplayNum();
}

void DisplayInit( void )
{	
#ifdef NoScreen
	return;
#endif
 	LCDPS  = 0b00000011;        // 分频比1:16
	LCDSE0 = 0;        
	LCDSE1 = 0;        
	LCDSE2 = 0; 
	SEG21=1;
	SEG5=1;
	SEG11=1;
	SEG16=1;
	SEG6=1;
	SEG3=1;
	SEG23=1;
	SEG22=1;
 	//LCDCON = 0b10000011; 
 	LCDCON = 0b00001111;     
	LCDDATA0=0;
	LCDDATA1=0;
	LCDDATA2=0;
	LCDDATA3=0;
	LCDDATA4=0;
	LCDDATA5=0;
	LCDDATA6=0;
	LCDDATA7=0;
	LCDDATA8=0;
	LCDDATA9=0;
	LCDDATA10=0;
	LCDDATA11=0;

 	LCDREF = 0b10100000;        // 参考电压
 	LCDRL  = 0b00110000;        
 	LCDCST = 0b00000000;       
 
 	LCDEN=1;

// 	LCDPS  = 0b00000000;        // 分频比1:1
// 	LCDCON = 0b10000011;        
// 	LCDREF = 0b10100000;        // 参考电压
// 	LCDRL  = 0b10000001;        
// 	LCDCST = 0b00000000;       

#ifdef Proteus
	SEG0=1;
	SEG1=1;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	SEG5=1;
	SEG6=1;
	SEG7=1;
	SEG10=1;
	SEG11=1;
#else
	S01=0;
	S02=0;
	S03=0;
	S04=1;
	S05=0;
	S06=0;
	S07=0;
	S08=0;
	S09=0;
	S10=0;
#endif
	
	
}

