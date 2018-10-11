#include "WirelessProc.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
//#include "radio_config_Si4463rx.h"
#include "config_470rx.h"
#include "Si4463.h"
#include "PickParamDefine.h"

#include "Verify.h"
#include "FRAM.h"

const unsigned char config_table[] = RADIO_CONFIGURATION_DATA_ARRAY;

uint8_t Si4463Temp[10];
unsigned char WirelessRxList[64];
unsigned char WirelessRxCount;
uint32_t NoWirelessRxTick;
_WirelessPacket WirelessPacket;


void Wireless_RxINTProc(void)
{
	_WirelessPacket tmpPD;
	uint32_t i;
	uint8_t sum;
	NoWirelessRxTick=HAL_GetTick();		
	Si4463_INT_STATUS(Si4463Temp);
	if((Si4463Temp[3] & ( 1<<4 ))!=0)
	{
		Si4463_READ_PACKET(tmpPD.All);
		Si4463_FIFO_INFO(Si4463Temp);		
		if(!gFlags.bNewSensorData)//之前的新数据已经处理完了
		{
			sum=GetVerify_Sum(tmpPD.All,PACKET_LENGTH-1);
			if(sum==tmpPD.sum)
			{
				for(i=0;i<PACKET_LENGTH;i++)
					WirelessPacket.All[i]=tmpPD.All[i];
				gFlags.bNewSensorData=1;				
			}
		}		
	}
}
void Wireless_Init(void)
{
	unsigned char i,*cfg;
	unsigned int j = 0;
	
	cfg=(unsigned char*)config_table;
	Si4463_RESET();
	while( ( i = cfg[j] ) != 0 )
	{
		j += 1;
		Si4463_CMD( cfg + j, i );
		j += i;
	}
#if PACKET_LENGTH > 0           //fixed packet length
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_LENGTH_7_0, PACKET_LENGTH );
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_CRC_CONFIG, 0xA2 );
	Si4463_SET_PROPERTY_1( PKT_CRC_CONFIG, 0x05 );
#else                           //variable packet length
	Si4463_SET_PROPERTY_1( PKT_CONFIG1, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_CRC_CONFIG, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_LEN_FIELD_SOURCE, 0x01 );
	Si4463_SET_PROPERTY_1( PKT_LEN, 0x2A );
	Si4463_SET_PROPERTY_1( PKT_LEN_ADJUST, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_LENGTH_12_8, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_LENGTH_7_0, 0x01 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_CONFIG, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_1_CRC_CONFIG, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_2_LENGTH_12_8, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_2_LENGTH_7_0, 0x10 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_2_CONFIG, 0x00 );
	Si4463_SET_PROPERTY_1( PKT_FIELD_2_CRC_CONFIG, 0x00 );
#endif //PACKET_LENGTH
	//重要： 4463的GDO2，GDO3控制射频开关，  33 ,32 
	//发射时必须： GDO2=0，GDO3=1
	//接收时必须： GDO2=1，GDO3=0
	//所以，以下语句对于4463是必须的，4460或4461不需要射频开关，则可以去掉此语句
	Si4463_GPIO_CONFIG( 0, 0, 0x20, 0x21, 0, 0, 0 );//重要
}
void Wireless_RxInit(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	Wireless_Init();
	Si4463_FIFO_INFO(Si4463Temp);
	Si4463_INT_STATUS(Si4463Temp);
	Si4463_PART_INFO(Si4463Temp);
	Si4463_START_RX(ROMParams.WirelessParamIndex,0x00,PACKET_LENGTH,0x08,0x08,0x08);//(ROMParams.WirelessParamIndex,0x00,4,0x08,0x08,0x08);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
void Wireless_SetInit(void)
{
	HAL_NVIC_ClearPendingIRQ(EXTI0_IRQn);
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
	Wireless_Init();
	Si4463_FIFO_INFO(Si4463Temp);
	Si4463_INT_STATUS(Si4463Temp);
	Si4463_PART_INFO(Si4463Temp);
}


