#include "HardwareProfile.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
//#include "radio_config_Si4463rx.h"
#include "config_470rx.h"
const unsigned char config_table[] = RADIO_CONFIGURATION_DATA_ARRAY;

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
	INT0IF=0;
	INT0IE=0;
	Wireless_Init();
	Si4463_FIFO_INFO(Si4463Temp);
	Si4463_INT_STATUS(Si4463Temp);
	Si4463_PART_INFO(Si4463Temp);
	Si4463_START_RX(ROMParams.WirelessParamIndex,0x00,PACKET_LENGTH,0x08,0x08,0x08);//(ROMParams.WirelessParamIndex,0x00,4,0x08,0x08,0x08);
	INT0IF=0;
	INT0IE=1;
}
void Wireless_SetInit(void)
{
	INT0IF=0;
	INT0IE=0;
	Wireless_Init();
	Si4463_FIFO_INFO(Si4463Temp);
	Si4463_INT_STATUS(Si4463Temp);
	Si4463_PART_INFO(Si4463Temp);
}


