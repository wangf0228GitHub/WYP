#include "HardwareProfile.h"
#include <stdio.h>
#include "ZiMo.h"
#define Display_UartTx(x) Uart1_PutChar(x)
#define Display_TxHeader() while(gFlags.bWaitShow);Display_UartTx(0xaa)
#define Display_TxEnder() Display_UartTx(0xf8);Display_UartTx(0x8f);Display_UartTx(0x88);Display_UartTx(0xff);gFlags.bWaitShow=1;TMR0ON=1
void Display_Clear(void)
{
	Display_TxHeader();
	Display_UartTx(0x70);
	Display_TxEnder();
}
void Display_ShowPic(unsigned char index)
{
	Display_TxHeader();
	Display_UartTx(0x80);
	Display_UartTx(index);
	Display_TxEnder();
}
void Display_SetTxtColor(unsigned char index)
{
	Display_TxHeader();
	Display_UartTx(0x40);
	Display_UartTx(0x00);
	switch(index)
	{
	case 1:	//白色	
		Display_UartTx(0xff);
		Display_UartTx(0xff);
		break;
	case 2://黄色
		Display_UartTx(0xff);
		Display_UartTx(0xe0);
		break;
	case 3://红色
		Display_UartTx(0xf8);
		Display_UartTx(0x00);
		break;
	case 4://蓝色
		Display_UartTx(0x00);
		Display_UartTx(0x1f);
		break;
	}	
	Display_TxEnder();
}
void DisplayInit( void )
{
	//Display_Clear();
	Display_ShowPic(0);
	Display_SetTxtColor(1);	
}
void Display_ShowTxt(unsigned char font,unsigned char x,unsigned int y,char* pBuffer,unsigned int len)
{
	unsigned int i;
	Display_TxHeader();
	Display_UartTx(0x51);
	Display_UartTx(font);
	Display_UartTx(0);
	//Display_UartTx(0);
	Display_UartTx(x);	
	Display_UartTx(HIGH_BYTE(y));
	Display_UartTx(LOW_BYTE(y));	
	for(i=0;i<len;i++)
	{
		Display_UartTx(pBuffer[i]);
	}
	Display_TxEnder();
}
void Display_ConPC(void)
{
	unsigned int i,sum;
	sum=sprintf(DisplayLine,"Connect to PC");
	Display_TxHeader();
	Display_UartTx(0x50);
	Display_UartTx(3);
	Display_UartTx(0);
	Display_UartTx(0);
	//Display_UartTx(0);
	Display_UartTx(20);	
	Display_UartTx(0);
	Display_UartTx(140);	
	for(i=0;i<sum;i++)
	{
		Display_UartTx(DisplayLine[i]);
	}
	Display_TxEnder();
}
void Display_BK(unsigned char level)
{
	Display_TxHeader();
	if(level==0)
	{
		Display_UartTx(0x02);
		Display_UartTx(0x01);
	}
	else if(level==0xff)
	{
		Display_UartTx(0x02);
		Display_UartTx(0x00);
	}
	else
	{
		Display_UartTx(0x90);
		Display_UartTx(level);
	}	
	Display_TxEnder();
}
void Display_ShowAnalyzeTemp(void)
{	
	unsigned char i,t1,t2,x,x1;
	unsigned int y,len;
	Display_SetTxtColor(1);
	t1=(SensorData4Save.TData.u16&0x0fff)>>4;
	t2=SensorData4Save.TData.u16&0x000f;
	sprintf(DisplayLine,AnalyzeString,t1,DS18X20_ToDecicel[t2]);
	y=DisplayRow*21;
	y=y+90;
	Display_ShowTxt(1,200,y,DisplayLine,5);
}
void Display_ShowHistory(void)
{	
	unsigned char i,t1,t2,x,x1;
	unsigned int y,len;
	for(i=0;i<History_ListCount;i++)
	{
		t1=(SensorData4ShowList[i].TData.u16&0x0fff)>>4;
		t2=SensorData4ShowList[i].TData.u16&0x000f;
		sprintf(DisplayLine,HistoryString,SensorData4ShowList[i].Month,SensorData4ShowList[i].Day,SensorData4ShowList[i].Hour,SensorData4ShowList[i].Minute,t1,DS18X20_ToDecicel[t2]);
		y=i*21;
		y=y+111;
		Display_ShowTxt(1,0,y,DisplayLine,30);
	}
}
void Display_ShowBatt(void)
{	
	unsigned char x;
	unsigned int ix;
	unsigned long l;
	l=((unsigned long)ADValue)*1000;
	l=l*3;
	l=l/6;
	ix=(unsigned int)(l>>9);
	if(ix<583)
		ix=0;
	else
	{
		ix=ix-583;
		if(ix>100)
			ix=100;
	}
	x=sprintf(DisplayLine,"%3u%%",ix);		
	Display_ShowTxt(1,208,0,DisplayLine,x);
}
void Display_ShowRealTemp(void)
{	
	unsigned char i,t1,t2,x,x1,j;
	unsigned int y,len;
	t1=(SensorData4Save.TData.u16&0x0fff)>>4;
	t2=SensorData4Save.TData.u16&0x000f;
	sprintf(DisplayString[DisplayRow],RealString,SensorData4Save.Month,SensorData4Save.Day,SensorData4Save.Hour,SensorData4Save.Minute,SensorDataSecond,PickDatas.index,t1,DS18X20_ToDecicel[t2]);
	if(gFlags.bShowLoop)
	{	
		Display_TxHeader();
		Display_UartTx(0x51);
		Display_UartTx(1);
		Display_UartTx(0);
		Display_UartTx(0);	
		Display_UartTx(0);
		Display_UartTx(90);
		for(i=DisplayRow+1;i<14;i++)
		{
			for(j=0;j<30;j++)
			{
				Display_UartTx(DisplayString[i][j]);
			}
// 			y=(i-DisplayRow-1)*21;
// 			y=y+90;
// 			Display_ShowTxt(1,0,y,&DisplayString[i],30);
		}
		//x=10-DisplayRow-1;
		for(i=0;i<DisplayRow+1;i++)
		{
			for(j=0;j<30;j++)
			{
				Display_UartTx(DisplayString[i][j]);
			}
			//y=(x+i)*21;
// 			y=y+90;
// 			Display_ShowTxt(1,0,y,&DisplayString[i],30);
		}
		Display_TxEnder();
	}
	else
	{
		y=DisplayRow<<4;
		y=y+90;
		Display_ShowTxt(1,0,y,&DisplayString[DisplayRow],30);		
	}
	DisplayRow++;
	if(DisplayRow>=14)
	{
		gFlags.bShowLoop=1;
		DisplayRow=0;
	}
// 	if(gFlags.bShowLoop)
// 	{
// 		sprintf(DisplayString[DisplayRow],RealString,0,0,0,0,1,t1,DS18X20_ToDecicel[t2]);
// 		DisplayRow++;
// 		if(DisplayRow>=10)
// 			DisplayRow=0;
// 		len=10-DisplayRow;
// 		y=len<<4;
// 		y=y+90;
// 		len=len*30;
// 		Display_ShowTxt(1,0,90,&DisplayString[DisplayRow],len);
// 
// 		len=300-len;
// 		Display_ShowTxt(1,0,y,&DisplayString[0],len);
// 	}
// 	else
// 	{
// 		sprintf(DisplayString[DisplayRow],RealString,0,0,0,0,1,t1,DS18X20_ToDecicel[t2]);
// 		y=DisplayRow<<4;
// 		y=y+90;
// 		Display_ShowTxt(1,0,y,&DisplayString[DisplayRow],30);
// 		DisplayRow++;
// 		if(DisplayRow>=10)
// 		{
// 			gFlags.bShowLoop=1;
// 			DisplayRow=0;
// 		}
// 	}
}
