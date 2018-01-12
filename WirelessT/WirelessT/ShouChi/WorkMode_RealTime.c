#include "HardwareProfile.h"
#include <stdio.h>
void WorkMode_RealTimeInit(void)
{
	WorkMode=WorkMode_RealTime;
	NoWirelessRxTick=SystemTick;
	gFlags.bShowLoop=0;
	Display_ShowPic(3);
	Display_SetTxtColor(2);
#ifndef Proteus
	Wireless_RxInit();	
#endif
	DisplayRow=0;
		
}
void WorkMode_RealTimeProc(void)
{
	unsigned char keynum;
	if(gFlags.bNewT)
	{
		Display_ShowRealTemp();
		gFlags.bNewT=0;
	}
#ifndef Proteus
	if(GetDeltaTick(NoWirelessRxTick)>200)
	{
		NoWirelessRxTick=SystemTick;
		Wireless_RxInit();
	}
#endif
	if(KeyPollCheck()==1)
	{			
		CommonKeyFun();
	}
// 	if(KeyPollCheck()==1)
// 	{			
// 		
// 	}
}
