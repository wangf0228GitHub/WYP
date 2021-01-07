#include "HardwareProfile.h"

// #include "string.h"
// #include "stdio.h"
// #include "stdlib.h"
#include "SimI2C.h"
#include "TMRList.h"
#include "LCD\lcd.h"
uint8_t OldKey;
uint8_t KeyPollCheck(void)//tm1650������
{
	uint8_t key;
	SimI2C_Start();
	SimI2C_SendByte(0x49);//д
	if (SimI2C_RecAck())
		return 0;
	key=SimI2C_ReadByte();//д��д��ַ���ֽ�
	if (SimI2C_RecAck())
		return 0;
	SimI2C_Stop();
	if (key == NoKey)
		return 0;
	
	if (key == OldKey)//֮ǰ�Ѿ����������ˣ������ظ�����
	{
		return 0;
	}
	OldKey = key;
	/************************************************************************/
	/* ������ʾ                                                             */
	/************************************************************************/
	TmrSetTime(SystemSleep_TMRNUM, ROMParams.SleepTimeSpan * 6000);
	if (gFlags.bSleep)//�Ѿ�������
	{
		LCD_DisplayOn();
		return 0;
	}
	KeyValue = key;
	return 1;
}
uint8_t GetKeyNum(void)
{
	if(KeyValue==Key_1)
		return 1;
	else if(KeyValue==Key_2)
		return 2;
	else if(KeyValue==Key_3)
		return 3;
	else if(KeyValue==Key_4)
		return 4;
	else if(KeyValue==Key_5)
		return 5;
	else if(KeyValue==Key_6)
		return 6;
	else if(KeyValue==Key_7)
		return 7;
	else if(KeyValue==Key_8)
		return 8;
	else if(KeyValue==Key_9)
		return 9;
	else if(KeyValue==Key_0)
		return 0;
	else 
		return 0xff;
// 	switch(KeyValue)
// 	{
// 	case Key_0:
// 		return 0;
// 	case Key_1:
// 		return 1;
// 	case Key_2:
// 		return 2;
// 	case Key_3:
// 		return 3;
// 	case Key_4:
// 		return 4;
// 	case Key_5:
// 		return 5;
// 	case Key_6:
// 		return 6;
// 	case Key_7:
// 		return 7;
// 	case Key_8:
// 		return 8;
// 	case Key_9:
// 		return 9;
// 	default:
// 		return 0xff;
// 	}
}

void CommonKeyFun(void)
{
	if(KeyValue==Key_FastLeft)
	{
		//WorkMode_AnalyzeInit();
	}
	else if(KeyValue==Key_FastRight)
	{
		//WorkMode_RealTimeInit();
	}
	else if(KeyValue==Key_Main_1 || KeyValue==Key_Main_2 || KeyValue==Key_Main_3)
	{
// 		WorkMode=WorkMode_Main;
// 		Display_ShowPic(1);
	}
	else if(KeyValue==Key_ESC)
	{
 	//	if(WorkMode==WorkMode_Setting)
 	//	{
 	//		if(SetMode==SetMode_Main)
 	//		{
 	//			WorkMode=WorkMode_Main;
 	//			Display_ShowPic(1);
 	//		}
 	//		else
 	//		{
 	//			WorkMode_SettingInit();
 	//		}
		//}
		//else
		//{
 	//		WorkMode = WorkMode_Main;
 	//		Display_ShowPic(1);
		//}
	}
}
