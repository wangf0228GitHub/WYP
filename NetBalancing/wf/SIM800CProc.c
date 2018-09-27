#include "SIM800CProc.h"
#include "stdlib.h"

#define isPowerON GPIO_PIN_RESET
#define isPowerOFF GPIO_PIN_SET

char ICCID[21];
uint8_t CSQ;
uint8_t ErrState;
uint8_t txChar;
unsigned char InteractServer();
void InitGPRS(void)
{
	unsigned char retry,i;
	char *strx=0;
	wfDelay_ms(3000);
	
	if(ATCommand_SendCmd("AT\0")!=ATACK_OK)
	{
		ErrState=MissAT;
		return;
	}
	wfDelay_ms(20000);
	ATCommand_TxByte(0x1b);
	if(ATCommand_SendCmd("ATH\0")!=ATACK_OK)
	{
		ErrState=MissAT_ATH;
		return;
	}
	

	if(ATCommand_SendCmd("ATE1\0")!=ATACK_OK)
	{
		ErrState=MissAT_ATE1;
		return;
	}	
	retry=10;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CIMI\0")==ATACK_OK)
		{
			break;
		}
		wfDelay_ms(3000);
		retry--;		
	}	
	if(retry==0)
	{
		ErrState=MissSimCard;//没有网络
		return;
	}
	retry=10;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+ICCID\0")==ATACK_OK)
		{
			strx=strstr((const char*)ATCommand_RxList,"+ICCID: ");
			if(strx!=0)
			{
				for(i=0;i<15;i++)
				{
					ICCID[i]=strx[13+i];
				}
				ICCID[15]='\0';
				break;
			}
			else
			{
				retry--;
				wfDelay_ms(3000);
			}
		}
	}
	//sim900a_send_cmd("AT+CIPCLOSE=1","CLOSE OK",100);	//关闭连接
	//关闭短信提示
	if(ATCommand_SendCmd("AT+CNMI=0,0\0")!=ATACK_OK)
	{
		ErrState=MissAT_CNMI;
		return;
	}	
	//txt形式短信
	if(ATCommand_SendCmd("AT+CMGF=1\0")!=ATACK_OK)
	{
		ErrState=MissAT_CMGF;
		return;
	}
	//	while(1)
	//	{
	//		ATCommand_SendCmd("AT+CSQ\0");
	//	}	
	retry=10;
	CSQ=0xff;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CSQ\0")==ATACK_OK)
		{
			strx=strstr((const char*)ATCommand_RxList,"+CSQ: ");
			if(strx!=0)
			{
				CSQ=atoi(strx+6);
				if(CSQ!=0)
					break;
			}
			else
			{
				retry--;
				wfDelay_ms(3000);
			}
		}		
	}
	if(retry==0 && CSQ!=0xff)
	{
		ErrState=MissAT_CSQ;
		return;
	}	
	retry=20;
	while(retry!=0)
	{
		if(ATCommand_SendCmd("AT+CGREG?\0")!=ATACK_OK)
		{		
			ErrState=MissAT_COPS;
			return;
		}
		strx=strstr((const char*)ATCommand_RxList,"+CGREG: 0,1");
		if(strx!=0)
		{
			break;
		}
		strx=strstr((const char*)ATCommand_RxList,"+CGREG: 0,5");
		if(strx!=0)
		{
			break;
		}
		wfDelay_ms(3000);
		retry--;		
	}
	if(retry==0)
	{
		ErrState=MissNet;//没有网络
		return;
	}
	if(ATCommand_SendCmd("AT+COLP=1\0")!=ATACK_OK)
	{
		ErrState=MissAT_COLP;
		return;
	}	
	if(ICCID[0]=='6'|| ICCID[0]=='1')
	{
		if(ATCommand_SendCmd("AT+CSTT=\"UNIM2M.NJM2MAPN\",\"\",\"\"\0")!=ATACK_OK)
		{
			ErrState=MissAT_CSTT;
			return;
		}
	}
	else
	{
		if(ATCommand_SendCmd("AT+CSTT=\"CMMTM\",\"\",\"\"\0")!=ATACK_OK)
		{
			ErrState=MissAT_CSTT;
			return;
		}
	}
	ATCommand_WaitACKTimes=50000;
	if(ATCommand_SendCmd("AT+CIICR\0")!=ATACK_OK)
	{
		ErrState=MissAT_CIICR;
		return;
	}
	// 	//查询本机ip
	ATCommand_SendCmd("AT+CIFSR\0");
}
void CallSend(void)
{
	unsigned char i,ret;
	char *strx=0;	
	ErrState=NoErr;
	InitGPRS();
	if(ErrState!=NoErr)
	{
		wfDelay_ms(60000);
		ErrState=NoErr;
		InitGPRS();
		if(ErrState!=NoErr)
			return;
	}
	ATCommand_SendCmd("AT+CIPSTATUS\0");
	strcpy(ATCommand_OkString,"CONNECT OK");
	ATCommand_RetryTimes=1;
	ATCommand_WaitACKTimes=60000;
	//if(ATCommand_SendCmd("AT+CIPSTART=\"TCP\",\"221.208.194.71\",\"12128\"\0")!=ATACK_OK)
	if(ATCommand_SendCmd("AT+CIPSTART=\"TCP\",\"www.wlwdjcy.com\",\"12128\"\0")!=ATACK_OK)
	{
		ATCommand_SendCmd("AT+CIPSTART=?\0");
		ErrState=MissAT_CIPSTART;
		return;
	}

	wfDelay_ms(1000);

	ret=InteractServer();
	if(ret!=ATACK_OK)
	{
		if(ErrState==MissAT_ServerClose)
		{
			return;
		}
		/************************************************************************/
		/* 20180611,解决第一次发送，未收到返回，则将出现频繁上数，错误标志未复位*/
		/************************************************************************/
		ErrState=NoErr;
		/************************************************************************/
		/*                                                                      */
		/************************************************************************/
		ret=InteractServer();
		if(ret!=ATACK_OK)
		{
			return;
		}
	}
	//分析服务器返回的数据
	strx=strstr((const char*)ATCommand_RxList,"#KO$");
	if(strx==0)
	{
		ErrState=MissAT_ErrServerData;
		return;
	}
	//__delay_20ms(300);
	if(ATCommand_SendCmd("AT+CIPCLOSE=1\0")!=ATACK_OK)
	{
		// 		ErrState=MissAT_CIPCLOSE;
		// 		return;
	}

	if(ATCommand_SendCmd("AT+CIPSHUT\0")!=ATACK_OK)
	{
		// 		ErrState=MissAT_CIPSHUT;
		// 		return;
	}
}
unsigned char InteractServer()
{
	unsigned char res=0; 
	unsigned char retry,i,j,k,addr;
	retry=1;//ATCommand_RetryTimes;
	res=ATACK_Null;
	while(retry!=0)
	{		
		strcpy(ATCommand_OkString,">");
		ATCommand_WaitACKTimes=40000;
		if(ATCommand_SendCmd("AT+CIPSEND\0")!=ATACK_OK)
		{
			ErrState=MissAT_CIPSEND;
			ATCommand_TxByte(0x1b);
			return res;
		}
		
		ATCommand_TxByte('#');
		ATCommand_TxByte('@');
		ATCommand_TxByte(0x1a);
		ATCommand_WaitACKTimes=40000;
		ATCommand_Clear=0x1a;
		strcpy(ATCommand_OkString,"$OK#");	
		strcpy(ATCommand_ErrString,"CLOSE");
		res=ATCommand_WaitData();
		if(res!=ATACK_Null)
			break;
		ATCommand_WaitClientInterval();
		retry--;
	}
	if(res!=ATACK_OK)
	{
		if(res==ATACK_Err)
			ErrState=MissAT_ServerClose;
		else
			ErrState=MissAT_NoServerData;
		ATCommand_TxByte(0x1b);
		return res;
	}
	// 	ATCommand_WaitACKTimes=20000;//等待服务器返回，20s
	// 	strcpy(ATCommand_OkString,"$OK#");
	// 	res=ATCommand_WaitData();
	// 	if(res!=ATACK_OK)
	// 		return MissAT_NoServerData;
	//等待服务器回复
	return res;
}
void CallProc(void)
{
	ErrState=NoErr;	
	//显示“请勿按键”
	if(SIM800C_PowerON()==0)
	{
		ErrState=Miss900a;
	}
	else
	{
		CallSend();
		if(ErrState!=NoErr)
		{
			//if(STATUS_R==isPowerOFF)//自动关机
			if(HAL_GPIO_ReadPin(STATUS2MCU_GPIO_Port,STATUS2MCU_Pin)==isPowerOFF)
			{
				ErrState=MissPower;
			}
		}
		SIM800C_PowerDown();
	}
}

uint8_t SIM800C_PowerDown(void)
{
	unsigned char i;
	//if(STATUS_R==isPowerON)//已经开机，先关机
	if(HAL_GPIO_ReadPin(STATUS2MCU_GPIO_Port,STATUS2MCU_Pin)==isPowerON)
	{
		HAL_GPIO_WritePin(GSM_PWR_GPIO_Port,GSM_PWR_Pin,GPIO_PIN_SET);
		wfDelay_ms(1400);
		HAL_GPIO_WritePin(GSM_PWR_GPIO_Port,GSM_PWR_Pin,GPIO_PIN_RESET);
		i=15;
		while(i!=0)
		{
			wfDelay_ms(100);
			if(HAL_GPIO_ReadPin(STATUS2MCU_GPIO_Port,STATUS2MCU_Pin)==isPowerOFF)
				break;			
			i--;
		}
	}
	if(i==0)
		return 0;
	return 1;
}

uint8_t SIM800C_PowerON(void)
{
	unsigned char i;
	//if(STATUS_R==isPowerON)//已经开机，先关机
	if(HAL_GPIO_ReadPin(STATUS2MCU_GPIO_Port,STATUS2MCU_Pin)==isPowerON)
	{
		if(SIM800C_PowerDown()==0)
		{	
			ErrState=Miss900a;
			return 0;
		}
		wfDelay_ms(3000);
	}	
	//POWER_ON_W=1;	
	HAL_GPIO_WritePin(GSM_PWR_GPIO_Port,GSM_PWR_Pin,GPIO_PIN_SET);
	i=15;
	while(i!=0)
	{
		ATCommand_RetryTimes=1;
		if(ATCommand_SendCmd("AT\0")==ATACK_OK)
		{
			ErrState=MissAT;
			//POWER_ON_W=0;
			HAL_GPIO_WritePin(GSM_PWR_GPIO_Port,GSM_PWR_Pin,GPIO_PIN_RESET);
			return 1;
		}
		i--;
	}
	//POWER_ON_W=0;
	HAL_GPIO_WritePin(GSM_PWR_GPIO_Port,GSM_PWR_Pin,GPIO_PIN_RESET);
	return 0;
}

