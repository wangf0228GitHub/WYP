#include "WithTFT.h"
#include <stdio.h>
#include "stdlib.h"
#include "wfSys.h"
#include "usart.h"
#include "wfDefine.h"
#include <string.h>
// void ProcAnimationFinish(void)
// {
// 	switch(TFTMsg.screen_id.u8H)
// 	{
// 	case 0://启动屏
// 		//切换到登录屏
// 		ScreenID=0x01;
// 		//SetTxt(0x01,0x01,"20");
// 		break;
// 	}
// }
uint8_t workScreen;
uint8_t GotoScreen;
uint8_t txList[100];
uint32_t TempWithTFTTick;
char pGetTxtBuf[10];
char pGetButton;
void ProcRxFromTFT(uint8_t rx)
{
	uint8_t x;
	if(TFTFlags.bWithTFTRx==1)
		return;
	TFTMsg.All[WithTFTRxCount++]=rx;
	if(WithTFTRxCount>5)
	{
		if(TFTFlags.bLen)
		{

		}
		else 	
		{	
			x=TFTMsg.All[WithTFTRxCount-1];
			if(x==0xff)
			{
				x=TFTMsg.All[WithTFTRxCount-2];
				if(x==0xff)
				{
					x=TFTMsg.All[WithTFTRxCount-3];
					if(x==0xfc)
					{
						x=TFTMsg.All[WithTFTRxCount-4];
						if(x==0xff)
						{
							TFTFlags.bWithTFTRx=1;	
						}
					}
				}
			}
		}
		if(WithTFTRxCount>MAXWithTFTRX)
		{
			WithTFTRxCount=0;
			WithTFTNeedRxCount=0xffff;				
		}
	}
// 	else if(WithTFTRxCount==7)
// 	{
// 		WithTFTNeedRxCount=MAKE_INT(WithTFTRxList[5],WithTFTRxList[6])+9;
// 	}
// 	else if(WithTFTRxCount==4)//判断地址
// 	{
// 		//地址不符，退出当前接收状态				
// 		if(WithTFTRxList[2]!=ROMParams.UnitAddr.u8H || WithTFTRxList[3]!=ROMParams.UnitAddr.u8L)
// 		{
// 			if(WithTFTRxList[2]!=0xff || WithTFTRxList[3]!=0xff)//0xffff 广播地址
// 			{
// 				WithTFTRxCount=0;				
// 				WithTFTNeedRxCount=0xffff;
// 			}
// 		}
// 	}
// 	else if(WithTFTRxCount==2)
// 	{
// 		if(rx!=0x16)
// 		{
// 			WithTFTRxCount=0;
// 		}
//	}
	else if(WithTFTRxCount==1)
	{
		if(rx!=0xee)
		{
			WithTFTRxCount=0;
		}
	}	
}
void ShowEnterDlg(const char *content)
{	
	SetTxt(sID_EnterDlg,3,content);
	SetScreen(sID_EnterDlg);
// 	while(GotoScreen==sID_EnterDlg)
// 	{
// 		if(TFTFlags.bWithTFTRx)
// 		{
// 			WithTFTRxLen.u16=WithTFTRxCount-12;
// 			switch(TFTMsg.cmd_type)//命令字
// 			{
// 			case 0xb1://主命令		
// 				if(TFTMsg.ctrl_msg==0x11)
// 				{
// 					if(TFTMsg.control_type==0x10)//按钮
// 					{
// 						if(TFTMsg.screen_id.u8H==sID_EnterDlg)//"确定对话框"页面
// 						{
// 							if(TFTMsg.control_id.u8H==0x05)
// 							{
// 								//if(gFlags.bEnterDlgJump)
// 								SetScreen(EnterDlgReNum);	
// 								EndProcCommandFromTFT();
// 								return;
// 							}
// 						}				
// 					}					
// 				}			
// 				// 		else if(TFTMsg.ctrl_msg==0x27)//动画播放完成
// 				// 		{
// 				// 			ProcAnimationFinish();
// 				// 		}
// 				break;
// 			case 0x07://显示器复位
// 				//初始化显示变量
// 				RESET();
// 				//gFlags.bLCDInit=1;
// 				break;
// 			}
// 			EndProcCommandFromTFT();
// 		}
// 		if(OERR1)
// 		{
// 			CREN1=0;
// 			NOP();
// 			CREN1=1;
// 		}
// 		if(OERR2)
// 		{
// 			CREN2=0;
// 			NOP();
// 			CREN2=1;
// 		}
// 	}
}
void ShowQueryDlg(const char *content)
{	
	SetTxt(sID_QueryDlg,2,content);
	SetScreen(sID_QueryDlg);
// 	while(GotoScreen==sID_QueryDlg)
// 	{
// 		if(TFTFlags.bWithTFTRx)
// 		{
// 			WithTFTRxLen.u16=WithTFTRxCount-12;
// 			switch(TFTMsg.cmd_type)//命令字
// 			{
// 			case 0xb1://主命令		
// 				if(TFTMsg.ctrl_msg==0x11)
// 				{
// 					if(TFTMsg.control_type==0x10)//按钮
// 					{
// 						if(TFTMsg.screen_id.u8H==sID_QueryDlg)//"确定对话框"页面
// 						{
// 							if(TFTMsg.control_id.u8H==6)
// 							{
// 								//if(gFlags.bEnterDlgJump)
// 								SetScreen(EnterDlgReNum);	
// 								EndProcCommandFromTFT();
// 								return;
// 							}
// 							else if(TFTMsg.control_id.u8H==4)
// 							{
// 								//if(gFlags.bEnterDlgJump)
// 								SetScreen(QueryDlgCancelNum);	
// 								EndProcCommandFromTFT();
// 								return;
// 							}
// 						}				
// 					}					
// 				}			
// 				// 		else if(TFTMsg.ctrl_msg==0x27)//动画播放完成
// 				// 		{
// 				// 			ProcAnimationFinish();
// 				// 		}
// 				break;
// 			case 0x07://显示器复位
// 				//初始化显示变量
// 				RESET();
// 				//gFlags.bLCDInit=1;
// 				break;
// 			}
// 			EndProcCommandFromTFT();
// 		}
// 		if(OERR1)
// 		{
// 			CREN1=0;
// 			NOP();
// 			CREN1=1;
// 		}
// 		if(OERR2)
// 		{
// 			CREN2=0;
// 			NOP();
// 			CREN2=1;
// 		}
// 	}
}
void ProcCommandFromTFT_Main( void )
{	
	uint8_t i;
	WithTFTRxLen=WithTFTRxCount-12;
	switch(TFTMsg.cmd_type)//命令字
	{
	case 0xb1://主命令		
		if(TFTMsg.ctrl_msg==0x11)
		{
			if(TFTMsg.control_type==0x10)//按钮
			{
// 				if(TFTMsg.screen_id_L==sID_Screen1)//首页
// 				{
// 					if(TFTMsg.control_id.u8H==4)
// 					{
// 						GotoScreen=sID_Menu;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);						
// 						//GetTxtFlags.bNeedGetStudent=1;
// 					}					
// 				}
// 				else if(TFTMsg.screen_id.u8H==sID_Menu)//"shiyan"页面
// 				{
// 					if(TFTMsg.control_id.u8H==1)//返回
// 					{
// 						GotoScreen=sID_Screen1;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}
//  					else if(TFTMsg.control_id.u8H==4)
//  					{
//  						GotoScreen=sID_Print;
//  					}
// 				}
// 				else if(TFTMsg.screen_id.u8H==sID_ExperimentalProject)//"shiyan"页面
// 				{
// 					if(TFTMsg.control_id.u8H==4)//普朗克常数测量
// 					{
// 						GotoScreen=sID_AutoPuLangke;						
// 					}
// 					else if(TFTMsg.control_id.u8H==6)//普朗克常数测量
// 					{
// 						GotoScreen=sID_AutoGQ;						
// 					}
// 					else if(TFTMsg.control_id.u8H==8)//普朗克常数测量
// 					{
// 						GotoScreen=sID_AutoVA;						
// 					}
// // 					else if(TFTMsg.control_id.u8H==2)//普朗克常数测量
// // 					{
// // 						GotoScreen=sID_Menu;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// // 					}
// 				}
//  				else if(TFTMsg.screen_id.u8H==sID_WIFIconfiguration)//首页
//  				{
//  					if(TFTMsg.control_id.u8H==4)//APK wifi
//  					{
//  						GotoScreen=sID_APKWifi;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
//  					}	
// 					else if(TFTMsg.control_id.u8H==6)//APK wifi
// 					{
// 						GotoScreen=sID_wxWifi;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}
// 					else if(TFTMsg.control_id.u8H==8)//APK wifi
// 					{
// 						GotoScreen=sID_wifimima;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}
//  				}
// 				else if(TFTMsg.screen_id.u8H==sID_Setting)//首页
// 				{
// 					if(TFTMsg.control_id.u8H==3)//设备参数配置
// 					{
// 						GotoScreen=sID_ParamSet;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}	
// 					else if(TFTMsg.control_id.u8H==10)//实验配置
// 					{
// 						GotoScreen=sID_ExperimentConfig;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}
// 				}
// 				else if(TFTMsg.screen_id.u8H==sID_FactorySettings)//首页
// 				{
// 					if(TFTMsg.control_id.u8H==2)
// 					{
// 						GotoScreen=sID_hWorkCurrent;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}	
// 					else if(TFTMsg.control_id.u8H==5)
// 					{
// 						GotoScreen=sID_FuAnWorkCurrent;
// // 						EndProcCommandFromTFT();						
// // 						SetScreen(GotoScreen);	
// 					}
// 				}
			}					
		}			
// 		else if(TFTMsg.ctrl_msg==0x27)//动画播放完成
// 		{
// 			ProcAnimationFinish();
// 		}
		break;
	case 0x07://显示器复位
		//初始化显示变量
		//RESET();
		//gFlags.bLCDInit=1;
		break;
	}
}

void EndProcCommandFromTFT( void )
{
	WithTFTRxCount=0;
	WithTFTNeedRxCount=0xffff;
	TFTFlags.AllFlag=0;
}
void SetTxt(uint8_t sID,uint8_t cID,const char* data)
{
	uint8_t i;
	uint8_t txHeaderList[7]={0xee,0xb1,0x10,0x00,0xff,0x00,0xff};
	uint8_t txEndList[4]={0xff,0xfc,0xff,0xff};
	txHeaderList[4]=sID;
	txHeaderList[6]=cID;
	HAL_UART_Transmit(&huart1,txHeaderList,7,1000);
	HAL_UART_Transmit(&huart1,(uint8_t *)data,strlen(data),1000);	
	HAL_UART_Transmit(&huart1,txEndList,4,1000);
}
void ShowPic(uint8_t picID,uint16_t x,uint16_t y,uint16_t weight,uint16_t high)
{
	txList[0]=0xee;
	txList[1]=0x33;
	txList[2]=HIGH_BYTE(x);
	txList[3]=LOW_BYTE(x);
	txList[4]=HIGH_BYTE(y);
	txList[5]=LOW_BYTE(y);
	txList[6]=0x00;
	txList[7]=picID;
	txList[8]=HIGH_BYTE(x);
	txList[9]=LOW_BYTE(x);
	txList[10]=HIGH_BYTE(y);
	txList[11]=LOW_BYTE(y);
	txList[12]=HIGH_BYTE(weight);
	txList[13]=LOW_BYTE(weight);
	txList[14]=HIGH_BYTE(high);
	txList[15]=LOW_BYTE(high);
	txList[16]=0x00;
	txList[17]=0xff;
	txList[18]=0xfc;
	txList[19]=0xff;
	txList[20]=0xff;
	HAL_UART_Transmit(&huart1,txList,21,1000);
}
void GetTxt(uint8_t sID,uint8_t cID)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x11;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;	
	txList[7]=0xff;
	txList[8]=0xfc;
	txList[9]=0xff;
	txList[10]=0xff;
	HAL_UART_Transmit(&huart1,txList,11,1000);
}
void GetScreenID()
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x01;	
	txList[3]=0xff;
	txList[4]=0xfc;
	txList[5]=0xff;
	txList[6]=0xff;
	HAL_UART_Transmit(&huart1,txList,7,1000);
}
void SetChar(uint8_t sID,uint8_t cID,char data)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x10;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=data;
	txList[8]=0xff;
	txList[9]=0xfc;
	txList[10]=0xff;
	txList[11]=0xff;
	HAL_UART_Transmit(&huart1,txList,12,1000);
}

void SetScreen(uint8_t sID)
{
	uint8_t i;
	//SetScreenRetry=SetScreenRetryMax;
	//while(SetScreenRetry!=0)
	while(1)
	{		
		txList[0]=0xee;
		txList[1]=0xb1;
		txList[2]=0x00;
		txList[3]=0x00;
		txList[4]=sID;
		txList[5]=0xff;
		txList[6]=0xfc;
		txList[7]=0xff;
		txList[8]=0xff;
		HAL_UART_Transmit(&huart1,txList,9,1000);
 		wfDelay_ms(40);
		EndProcCommandFromTFT();
 		txList[0]=0xee;
 		txList[1]=0xb1;
 		txList[2]=0x01;	
 		txList[3]=0xff;
 		txList[4]=0xfc;
 		txList[5]=0xff;
 		txList[6]=0xff;
		HAL_UART_Transmit(&huart1,txList,7,1000);
		TempWithTFTTick=GetCurTick();
		while(1)
		{
			if(TFTFlags.bWithTFTRx)
			{
				WithTFTRxLen=WithTFTRxCount-12;
				if(TFTMsg.cmd_type==0xb1)//命令字
				{		
					if(TFTMsg.ctrl_msg==0x01)
					{
						if(TFTMsg.screen_id_L==sID)
						{							
							//if(TFTMsg.control_id.u8H==100)
							{
								EndProcCommandFromTFT();
								workScreen=sID;
								GotoScreen=workScreen;
								return;
							}
						}						
					}
				}
				EndProcCommandFromTFT();
			}
			if(GetDeltaTick(TempWithTFTTick)>500)
			{
				//GetTxtRetry--;
				break;
			}
		}
	}
	//ShowEnterDlg(strSetScreenErr);
	//return 0;
}
void SetButton(uint8_t sID,uint8_t cID,uint8_t status)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x10;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=status;
	txList[8]=0xff;
	txList[9]=0xfc;
	txList[10]=0xff;
	txList[11]=0xff;
	HAL_UART_Transmit(&huart1,txList,12,1000);
}
void SetProgress(uint8_t sID,uint8_t cID,uint8_t status)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x10;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=0x00;
	txList[8]=0x00;
	txList[9]=0x00;
	txList[10]=status;
	txList[11]=0xff;
	txList[12]=0xfc;
	txList[13]=0xff;
	txList[14]=0xff;
	HAL_UART_Transmit(&huart1,txList,15,1000);
}
void DeleteCurve(uint8_t sID,uint8_t cID,uint8_t n)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x33;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;	
	txList[7]=n;
	txList[8]=0xff;
	txList[9]=0xfc;
	txList[10]=0xff;
	txList[11]=0xff;
	HAL_UART_Transmit(&huart1,txList,12,1000);
}
void SetTextFlash(uint8_t sID,uint8_t cID,uint16_t time)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x15;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=HIGH_BYTE(time);
	txList[8]=LOW_BYTE(time);
	txList[9]=0xff;
	txList[10]=0xfc;
	txList[11]=0xff;
	txList[12]=0xff;
	HAL_UART_Transmit(&huart1,txList,13,1000);
}
void AddCurveData(uint8_t sID,uint8_t cID,uint8_t channel,uint16_t data)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x32;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=channel;
	txList[8]=0x00;
	txList[9]=0x02;
	txList[10]=HIGH_BYTE(data);
	txList[11]=LOW_BYTE(data);	
	txList[12]=0xff;
	txList[13]=0xfc;
	txList[14]=0xff;
	txList[15]=0xff;
	HAL_UART_Transmit(&huart1,txList,16,1000);
}
void SetCurveVerticalScaling(uint8_t sID,uint8_t cID,uint16_t XScaling,uint16_t YScaling)
{
	txList[0]=0xee;
	txList[1]=0xb1;
	txList[2]=0x34;
	txList[3]=0x00;
	txList[4]=sID;
	txList[5]=0x00;
	txList[6]=cID;
	txList[7]=0x00;
	txList[8]=0x00;
	txList[9]=HIGH_BYTE(XScaling);
	txList[10]=LOW_BYTE(XScaling);	
	txList[11]=0x00;
	txList[12]=0x00;
	txList[13]=HIGH_BYTE(YScaling);
	txList[14]=LOW_BYTE(YScaling);	
	txList[15]=0xff;
	txList[16]=0xfc;
	txList[17]=0xff;
	txList[18]=0xff;
	HAL_UART_Transmit(&huart1,txList,19,1000);
}
void ResetTFT(void)
{
	txList[0]=0xee;
	txList[1]=0x07;
	txList[2]=0x35;
	txList[3]=0x5a;
	txList[4]=0x53;
	txList[5]=0xa5;
	txList[6]=0xff;
	txList[7]=0xfc;
	txList[8]=0xff;
	txList[9]=0xff;
	HAL_UART_Transmit(&huart1,txList,10,1000);
}
void InitWithTFT(void)
{
// 	uint8_t i;
// 	float fx;
// 	InitLCDTick=SystemTick;
// 	while(1)
// 	{		
// 		if(GetDeltaTick(InitLCDTick)>20)
// 		{
// 			InitLCDTick=SystemTick;
// 			txList[]=0xee);
// 			txList[]=0x07);
// 			txList[]=0x35);
// 			txList[]=0x5a);
// 			txList[]=0x53);
// 			txList[]=0xa5);
// 			txList[]=0xff);
// 			txList[]=0xfc);
// 			txList[]=0xff);
// 			txList[]=0xff);
// 		}
// 		if(TFTFlags.bWithTFTRx)
// 		{
// 			if(TFTMsg.cmd_type==0x07)//复位
// 			{			
// 				EndProcCommandFromTFT();
// 				break;
// 			}	
// 			EndProcCommandFromTFT();
// 		}
// 	}
// 	__delay_20ms(100);	
// 	SetTxt(sID_AutoPuLangke,16,"000.0");
// 	SetChar(sID_AutoPuLangke,30,'0');
// 	SetChar(sID_AutoPuLangke,31,'0');
// 	SetChar(sID_AutoPuLangke,32,'0');
// 	SetChar(sID_AutoPuLangke,33,'0');
// 	SetTextFlash(sID_AutoPuLangke,33,50);
// 
// 	SetTxt(sID_Screen1,0x01,RomParams.SitNum);
// 
// 
// 	SetTxt(sID_wifimima,2,RomParams.WifiSSID);
// 	SetTxt(sID_wifimima,1,RomParams.WifiPASS);
// 	SetTxt(sID_ParamSet,2,RomParams.SitNum);
// 	SetTxt(sID_ParamSet,1,RomParams.ServerIP);
// 	SetTxt(sID_ParamSet,13,RomParams.ServerPort);
// 	for(i=0;i<6;i++)
// 	{
// 		sprintf(DisplayLine,"%d",RomParams.hWorkCurrent[i]);
// 		SetTxt(sID_hWorkCurrent,1+i,DisplayLine);
// 		sprintf(DisplayLine,"%.2f",RomParams.hCorrection[i]);
// 		SetTxt(sID_hWorkCurrent,30+i,DisplayLine);
// 	}
// 	for(i=0;i<6;i++)
// 	{
// 		sprintf(DisplayLine,"%d",RomParams.FAWorkCurrent[i]);
// 		SetTxt(sID_FuAnWorkCurrent,1+i,DisplayLine);
// 		sprintf(DisplayLine,"%.2f",RomParams.FACorrection[i]);
// 		SetTxt(sID_FuAnWorkCurrent,30+i,DisplayLine);
// 	}
// 	if(RomParams.exWorkTepy.bFAAuto)
// 	{
// 		SetButton(sID_ExperimentConfig,31,1);
// 		SetButton(sID_ExperimentConfig,13,0);
// 	}
// 	else
// 	{
// 		SetButton(sID_ExperimentConfig,31,0);
// 		SetButton(sID_ExperimentConfig,13,1);
// 	}
// 	if(RomParams.exWorkTepy.bFAPrint)
// 		SetButton(sID_ExperimentConfig,34,1);
// 	else
// 		SetButton(sID_ExperimentConfig,34,0);
// 	if(RomParams.exWorkTepy.bGQAuto)
// 	{
// 		SetButton(sID_ExperimentConfig,22,1);
// 		SetButton(sID_ExperimentConfig,26,0);
// 	}
// 	else
// 	{
// 		SetButton(sID_ExperimentConfig,22,0);
// 		SetButton(sID_ExperimentConfig,26,1);
// 	}
// 	if(RomParams.exWorkTepy.bGQPrint)
// 	{
// 		SetButton(sID_ExperimentConfig,39,1);
// 	}
// 	else
// 	{
// 		SetButton(sID_ExperimentConfig,39,0);
// 	}
// 	if(RomParams.exWorkTepy.bPLKPrint)
// 	{
// 		SetButton(sID_ExperimentConfig,57,1);
// 	}
// 	else
// 	{
// 		SetButton(sID_ExperimentConfig,57,0);
// 	}
// 
// 	
// 	fx=300*0.000763;
// 	fx=fx/5;
// 	sprintf(DisplayLine,"%.1f",fx);
// 	SetTxt(sID_AutoVA,16,DisplayLine);
// 	SetTxt(sID_AutoVA_Work,16,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*2);
// 	SetTxt(sID_AutoVA,15,DisplayLine);
// 	SetTxt(sID_AutoVA_Work,15,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*3);
// 	SetTxt(sID_AutoVA,14,DisplayLine);
// 	SetTxt(sID_AutoVA_Work,14,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*4);
// 	SetTxt(sID_AutoVA,13,DisplayLine);
// 	SetTxt(sID_AutoVA_Work,13,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*5);
// 	SetTxt(sID_AutoVA,12,DisplayLine);
// 	SetTxt(sID_AutoVA_Work,12,DisplayLine);
// 
// 	sprintf(DisplayLine,"%.1f",fx);
// 	SetTxt(sID_ManVA,16,DisplayLine);
// 	SetTxt(sID_ManVA_Work,13,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*2);
// 	SetTxt(sID_ManVA,15,DisplayLine);
// 	SetTxt(sID_ManVA_Work,11,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*3);
// 	SetTxt(sID_ManVA,14,DisplayLine);
// 	SetTxt(sID_ManVA_Work,10,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*4);
// 	SetTxt(sID_ManVA,13,DisplayLine);
// 	SetTxt(sID_ManVA_Work,7,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*5);
// 	SetTxt(sID_ManVA,10,DisplayLine);
// 	SetTxt(sID_ManVA_Work,5,DisplayLine);
// 
// 	sprintf(DisplayLine,"%.1f",fx);
// 	SetTxt(sID_AutoGQ,14,DisplayLine);
// 	SetTxt(sID_AutoGQ_Work,6,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*2);
// 	SetTxt(sID_AutoGQ,13,DisplayLine);
// 	SetTxt(sID_AutoGQ_Work,5,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*3);
// 	SetTxt(sID_AutoGQ,12,DisplayLine);
// 	SetTxt(sID_AutoGQ_Work,4,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*4);
// 	SetTxt(sID_AutoGQ,9,DisplayLine);
// 	SetTxt(sID_AutoGQ_Work,3,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*5);
// 	SetTxt(sID_AutoGQ,6,DisplayLine);
// 	SetTxt(sID_AutoGQ_Work,2,DisplayLine);
// 
// 	sprintf(DisplayLine,"%.1f",fx);
// 	SetTxt(sID_ManGQ,17,DisplayLine);
// 	SetTxt(sID_ManGQ_Work,10,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*2);
// 	SetTxt(sID_ManGQ,12,DisplayLine);
// 	SetTxt(sID_ManGQ_Work,9,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*3);
// 	SetTxt(sID_ManGQ,10,DisplayLine);
// 	SetTxt(sID_ManGQ_Work,7,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*4);
// 	SetTxt(sID_ManGQ,9,DisplayLine);
// 	SetTxt(sID_ManGQ_Work,5,DisplayLine);
// 	sprintf(DisplayLine,"%.1f",fx*5);
// 	SetTxt(sID_ManGQ,1,DisplayLine);
// 	SetTxt(sID_ManGQ_Work,1,DisplayLine);
// 	//SetCurveVerticalScaling(6,1,600,100);
// 	EndProcCommandFromTFT();
}
uint8_t WithTFT_GetTxt(uint8_t sID,uint8_t cID,char* pBuf)
{
	uint8_t i;
	uint8_t GetTxtRetry=GetTxtRetryMax;
	while(GetTxtRetry!=0)
	{		
		txList[0]=0xee;
		txList[1]=0xb1;
		txList[2]=0x11;
		txList[3]=0x00;
		txList[4]=sID;
		txList[5]=0x00;
		txList[6]=cID;	
		txList[7]=0xff;
		txList[8]=0xfc;
		txList[9]=0xff;
		txList[10]=0xff;
		HAL_UART_Transmit(&huart1,txList,11,1000);
		TempWithTFTTick=GetCurTick();
		while(1)
		{
			if(TFTFlags.bWithTFTRx)
			{
				WithTFTRxLen=WithTFTRxCount-12;
				if(TFTMsg.cmd_type==0xb1)//命令字
				{		
					if(TFTMsg.ctrl_msg==0x11)
					{
						if(pBuf==&pGetButton)
						{
							if(TFTMsg.control_type==0x10)//按钮
							{
								if(TFTMsg.screen_id_L==sID)//指定的页面
								{
									if(TFTMsg.control_id_L==cID)//指定的控件
									{										
										*pBuf=TFTMsg.data[1];
										EndProcCommandFromTFT();
										return 1;
									}					
								}
							}
						}
						else
						{
							if(TFTMsg.control_type==0x11)//文本
							{
								if(TFTMsg.screen_id_L==sID)//指定的页面
								{
									if(TFTMsg.control_id_L==cID)//指定的控件
									{
										i=0;
										while(TFTMsg.data[i]!='\0')
										{
											pBuf[i]=TFTMsg.data[i];
											i++;
										}
										pBuf[i]='\0';
										EndProcCommandFromTFT();
										return 1;
									}					
								}
							}	
						}		
					}
				}
				EndProcCommandFromTFT();
			}			
			if(GetDeltaTick(TempWithTFTTick)>300)
			{
				GetTxtRetry--;
				break;
			}
		}		
	}
	return 0;
}
