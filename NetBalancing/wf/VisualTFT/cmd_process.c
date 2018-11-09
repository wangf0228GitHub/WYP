#include "cmd_process.h"
#include <stdio.h>
#include "TFTWorkProc.h"
#include "..\WirelessProc.h"
#include "WorkMode_RealTime.h"
#include "WorkMode_History.h"
#include "WorkMode_IntervalAnalysis.h"
#include "WorkMode_Setting.h"
#include "WorkMode_DataAnalysis.h"
#include "FRAM.h"

uint8 cmd_buffer[CMD_MAX_SIZE];
uint16_t waitSID;
uint16_t waitCID;
uint8_t controlValue[50];


extern uint32_t SleepSecond;
/*! 
 *  \brief  消息处理流程，此处一般不需要更改
 *  \param msg 待处理消息
 *  \param size 消息长度
 */
void ProcessMessage( PCTRL_MSG msg, uint16 size )
{
	uint8 cmd_type = msg->cmd_type;//指令类型
	uint8 ctrl_msg = msg->ctrl_msg;   //消息的类型
	uint8 control_type = msg->control_type;//控件类型
	uint16 screen_id = PTR2U16(&msg->screen_id_high);//画面ID
	uint16 control_id = PTR2U16(&msg->control_id_high);//控件ID
	uint32 value = PTR2U32(msg->param);//数值
	SleepSecond=0;
	switch(cmd_type)
	{
	case NOTIFY_REST://复位
		if(TFTWaitCommandFlags.bWaitReset)//主动复位
		{
			TFTWaitCommandFlags.bWaitReset=0;
			TFTNotifyCommandFlags.bRxReset=1;
		}
		else
		{
			WirelessOff();
		}
		/*	NVIC_SystemReset();*/
		break;
	case NOTIFY_CONTROL://控件事件
		{
			if(ctrl_msg==MSG_GET_CURRENT_SCREEN)//画面ID变化通知
			{
				NotifyScreen(screen_id);
			}
			else
			{
				switch(control_type)
				{
				case kCtrlButton: //按钮控件
					NotifyButton(screen_id,control_id,msg->param[1]);
					break;
				case kCtrlText://文本控件
					NotifyText(screen_id,control_id,msg->param);
					break;
				case kCtrlProgress: //进度条控件
					NotifyProgress(screen_id,control_id,value);
					break;
				case kCtrlSlider: //滑动条控件
					NotifySlider(screen_id,control_id,value);
					break;
				case kCtrlMeter: //仪表控件
					NotifyMeter(screen_id,control_id,value);
					break;
				case kCtrlMenu://菜单控件
					NotifyMenu(screen_id,control_id,msg->param[0],msg->param[1]);
					break;
				case kCtrlSelector://选择控件
					NotifySelector(screen_id,control_id,msg->param[0]);
					break;
				case kCtrlRTC://倒计时控件
					NotifyTimer(screen_id,control_id);
					break;
				default:
					break;
				}
			}			
		}
		break;
	case NOTIFY_TOUCH_PRESS://触摸屏按下
	case NOTIFY_TOUCH_RELEASE://触摸屏松开
		NotifyTouchXY(cmd_buffer[1],PTR2U16(cmd_buffer+2),PTR2U16(cmd_buffer+4));
		break;	
	case NOTIFY_WRITE_FLASH_OK://写FLASH成功
		NotifyWriteFlash(1);
		break;
	case NOTIFY_WRITE_FLASH_FAILD://写FLASH失败
		NotifyWriteFlash(0);
		break;
	case NOTIFY_READ_FLASH_OK://读取FLASH成功
		NotifyReadFlash(1,cmd_buffer+2,size-6);//去除帧头帧尾
		break;
	case NOTIFY_READ_FLASH_FAILD://读取FLASH失败
		NotifyReadFlash(0,0,0);
		break;
	case NOTIFY_READ_RTC://读取RTC时间
		NotifyReadRTC(cmd_buffer[2],cmd_buffer[3],cmd_buffer[4],cmd_buffer[5],cmd_buffer[6],cmd_buffer[7],cmd_buffer[8]);
		break;	
	default:
		break;
	}
}

/*! 
 *  \brief  画面切换通知
 *  \details  当前画面改变时(或调用GetScreen)，执行此函数
 *  \param screen_id 当前画面ID
 */
void NotifyScreen(uint16 screen_id)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  触摸坐标事件响应
 *  \param press 1按下触摸屏，3松开触摸屏
 *  \param x x坐标
 *  \param y y坐标
 */
void NotifyTouchXY(uint8 press,uint16 x,uint16 y)
{
	//TODO: 添加用户代码
}

//文本控件显示整数值
void SetTextValueInt32(uint16 screen_id, uint16 control_id,int32 value)
{
	char buffer[12] = {0};
	sprintf(buffer,"%ld",value);
	SetTextValue(screen_id,control_id,(uchar *)buffer);
}

//字符串转整数
int32 StringToInt32(uint8 *str)
{
	int32 v = 0;
	sscanf((char *)str,"%ld",&v);
	return v;
}

/*! 
 *  \brief  按钮控件通知
 *  \details  当按钮状态改变(或调用GetControlValue)时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param state 按钮状态：0弹起，1按下
 */
void NotifyButton(uint16 screen_id, uint16 control_id, uint8  state)
{
	//TODO: 添加用户代码	
	char str[50];
	//处理公共按钮控件
	if(JumpButtonProc(control_id)!=0)
	{
		if((screen_id==3) ||(screen_id==4) ||(screen_id==5) ||(screen_id==2))
		{
			switch(control_id)
			{
			case 1:
				SetScreen(1);
				break;
			case 5:
				SetScreen(6);
				break;
			case 8:
				SetScreen(21);
				break;
			case 11:
				SetScreen(30);
				break;
			}
		}
		return;
	}
	switch(screen_id)
	{
	case 4://实时温度柱形图
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			RealTime_TBarChartsSwitchPage(control_id);
		}
		break;
	case 5://实时压力柱形图
		break;
	case 6://历史
		if(control_id==cID_btConfirm)//确定按键
		{
			HistoryModeInit();
		}
		break;
	case 7://历史温度列表
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			History_TRecordSwitchPage(control_id);
		}
		break;
	case 9://历史温度柱形图
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			History_TBarChartsSwitchPage(control_id);
		}
		break;
	case 11://分析、栋平均温度、列表
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			DataAnalysis_DA_TRecordSwitchPage(control_id);
		}
		break;
	case 13://分析、单元温度、列表
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			DataAnalysis_DY_TRecordSwitchPage(control_id);
		}
		break;
	case 15://分析、栋平均温度、柱形图
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			DataAnalysis_DA_TBarChartsSwitchPage(control_id);
		}
		break;
	case 17://分析、单元温度、柱形图
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			DataAnalysis_DY_TBarChartsSwitchPage(control_id);
		}
		break;
	case 19://温度间隔分析
		if(control_id==cID_btBackward || control_id==cID_btForward)//柱形图换页
		{
			IntervalAnalysis_TRecordSwitchPage(control_id);
		}
		break;
	case 25://设置：时间间隔
		if(control_id==cID_btConfirm)//确定按键
		{
			Setting_IntervalAnalysis();
		}
		else
		{
			sprintf(str,"%d\0",ROMParams.TimeSpan1);
			SetTextValue(25,50,str);
			sprintf(str,"%d\0",ROMParams.TimeSpan2);
			SetTextValue(25,51,str);
			sprintf(str,"%d\0",ROMParams.TimeSpan3);
			SetTextValue(25,52,str);
			sprintf(str,"%d\0",ROMParams.TimeSpan4);
			SetTextValue(25,53,str);
			SetScreen(21);
		}
		break;
	case 26://设置：休眠时间
		if(control_id==cID_btConfirm)
		{
			Setting_SleepTimesSpan();
		}
		else
		{
			sprintf(str,"%d\0",ROMParams.SleepTimeSpan);
			SetTextValue(26,50,str);
			SetScreen(21);
		}
		break;
	case 27://设置：终端编码
		if(control_id==cID_btConfirm)
		{
			Setting_SensorProgram();
		}
		else if(control_id==41)//返回键
		{
			SetScreen(21);
		}
		break;
	case 29:
	case 28://对话框
		if(control_id==100)
		{
			StopTimer(screen_id,cID_Timer);
			SetScreen(autoReturnSID);
		}
		break;
	}
}

/*! 
 *  \brief  文本控件通知
 *  \details  当文本通过键盘更新(或调用GetControlValue)时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param str 文本控件内容
 */
void NotifyText(uint16 screen_id, uint16 control_id, uint8 *str)
{
	//TODO: 添加用户代码
	uint32_t i; 
	if(!TFTWaitCommandFlags.bWaitControlValue)
		return;
	if(screen_id!=waitSID)
		return;
	if(control_id!=waitCID)
		return;
	i=0;
	while(str[i]!='\0')
	{
		controlValue[i]=str[i];
		i++;
		if(i==(ControlValue_MAX_SIZE-1))
		{
			break;
		}
	}
	controlValue[i]='\0';
	TFTNotifyCommandFlags.bRxControlValue=1;
	TFTWaitCommandFlags.bWaitControlValue=0;
}

/*! 
 *  \brief  进度条控件通知
 *  \details  调用GetControlValue时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param value 值
 */
void NotifyProgress(uint16 screen_id, uint16 control_id, uint32 value)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  滑动条控件通知
 *  \details  当滑动条改变(或调用GetControlValue)时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param value 值
 */
void NotifySlider(uint16 screen_id, uint16 control_id, uint32 value)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  仪表控件通知
 *  \details  调用GetControlValue时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param value 值
 */
void NotifyMeter(uint16 screen_id, uint16 control_id, uint32 value)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  菜单控件通知
 *  \details  当菜单项按下或松开时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param item 菜单项索引
 *  \param state 按钮状态：0松开，1按下
 */
void NotifyMenu(uint16 screen_id, uint16 control_id, uint8  item, uint8  state)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  选择控件通知
 *  \details  当选择控件变化时，执行此函数
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 *  \param item 当前选项
 */
void NotifySelector(uint16 screen_id, uint16 control_id, uint8  item)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  定时器超时通知处理
 *  \param screen_id 画面ID
 *  \param control_id 控件ID
 */
void NotifyTimer(uint16 screen_id, uint16 control_id)
{
	//TODO: 添加用户代码
	switch(screen_id)
	{
	case 28:
	case 29://自动返回
		SetScreen(autoReturnSID);
		break;
	}
}

/*! 
 *  \brief  读取用户FLASH状态返回
 *  \param status 0失败，1成功
 *  \param _data 返回数据
 *  \param length 数据长度
 */
void NotifyReadFlash(uint8 status,uint8 *_data,uint16 length)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  写用户FLASH状态返回
 *  \param status 0失败，1成功
 */
void NotifyWriteFlash(uint8 status)
{
	//TODO: 添加用户代码
}

/*! 
 *  \brief  读取RTC时间，注意返回的是BCD码
 *  \param year 年（BCD）
 *  \param month 月（BCD）
 *  \param week 星期（BCD）
 *  \param day 日（BCD）
 *  \param hour 时（BCD）
 *  \param minute 分（BCD）
 *  \param second 秒（BCD）
 */
void NotifyReadRTC(uint8 year,uint8 month,uint8 week,uint8 day,uint8 hour,uint8 minute,uint8 second)
{
	if(!TFTWaitCommandFlags.bWaitRTC)
		return;
	RTCData.year=year;
	RTCData.month=month;
	RTCData.week=week;
	RTCData.day=day;
	RTCData.hour=hour;
	RTCData.minute=minute;
	RTCData.second=second;
	TFTNotifyCommandFlags.bRxRTC=1;
	TFTWaitCommandFlags.bWaitRTC=0;
}
