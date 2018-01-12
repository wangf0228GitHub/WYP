
#include "c_types.h"
#include "TypeDefine.h"
#include "..\..\include\osapi.h"
struct esp_platform_saved_param esp_param;
extern uint8 myID[48];
#define GETFLASHFLG(num) ((esp_param.flg>>num)&0x0001)
#define SETFLASHFLG(num) (esp_param.flg|=(1<<num))
#define CLEARFLASHFLG(num) (esp_param.flg&=(~(1 << num)))
void ICACHE_FLASH_ATTR InitFlashData(void)
{
	char buf[64] = {0};
	char* pChar;
	system_param_load(ESP_PARAM_START_SEC, 0, &esp_param, sizeof(esp_param));
	os_sprintf(buf, "wangf8266:%s %s", __DATE__, __TIME__);	
	pChar=(char *)os_strstr(esp_param.myID,buf);
	if(pChar==NULL)
	{
	 	os_printf("first work\n");
	 	os_memcpy(esp_param.myID,buf,63);
	 	esp_param.flg=0;
		//SETFLASHFLG(flg_bWifi);
	 	system_param_save_with_protect(ESP_PARAM_START_SEC, &esp_param, sizeof(esp_param));			
	}
	else
	{
	 	os_printf("future work\n");			
	}
	spi_flash_read(0x10000, myID, 48);
	myID[47]='\0';
	os_printf("myID£º%s\r\n",myID);
}
void ICACHE_FLASH_ATTR SetWififlg(unsigned char bWifi)
{
	system_param_load(ESP_PARAM_START_SEC, 0, &esp_param, sizeof(esp_param));
	if(bWifi==0)
	{
		CLEARFLASHFLG(flg_bWifi);
	}
	else
	{
		SETFLASHFLG(flg_bWifi);
	}
	system_param_save_with_protect(ESP_PARAM_START_SEC, &esp_param, sizeof(esp_param));
	os_printf("flg:%d\n",esp_param.flg);
}

