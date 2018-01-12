#ifndef __user_work_h__
#define __user_work_h__
#include "..\..\include\os_type.h"
// typedef enum {
// 	WorkStatus_TInit = 0,
// 	WorkStatus_TRead,
// 	WorkStatus_NeedTx,
// 	WorkStatus_WaitWifi,
// 	WorkStatus_ESPWork
// } _WorkStatus;
// extern _WorkStatus WorkStatus;


#define ESP_PARAM_START_SEC		17
struct esp_platform_saved_param {
	uint8 myID[64];
	uint16 flg;
	uint8 pad[2];
};
//#define ESP_ID_START_SEC		0x10000


#define SENSOR_DATA_TxMax 24
#define SENSOR_DATA_MAX 144*2 
#define SENSOR_DATA_MEM_ADDR 64
#define SENSOR_DATA_SIZE 

typedef struct{
	uint16 flg;
	uint16 workTick;
	uint16 cnt;
	uint16 ErrTick;
	unsigned char DST_H;
	unsigned char DST_L;
	uint16 tempX;
	unsigned char DisplayReg[8];
	uint8 data[SENSOR_DATA_MAX];
}SENSOR_DATA_RTC_MEM;
extern SENSOR_DATA_RTC_MEM sensor_data ;


#define bTrue 0x0001
#define bFasle 0x0000
#define flg_bErrShow 5
#define flg_bNotify 4
#define flg_FisrtUp 3
#define flg_bNeedTx 2
#define flg_bFull 1
#define flg_bWifi 0
#define GETFLG(num) ((sensor_data.flg>>num)&0x0001)
#define SETFLG(num) (sensor_data.flg|=(1<<num))
#define CLEARFLG(num) (sensor_data.flg&=(~(1 << num)))
#define NOTFLG(num) (sensor_data.flg^=(1 << num))


#define FLASHTemp 15
#define ESPWorkTick 458

#define ShowErrTime FLASHTemp

extern unsigned char bDS18B20;
extern unsigned char bSendding;
extern unsigned char bKey;
extern unsigned char errDST;
extern os_timer_t TickTimer;
extern os_timer_t esp_client_timer;
extern os_timer_t DS18B20_worktimer;
void DS18B20_Convert_cb(void *timer_arg);
// extern void user_esp_platform_workProc(void *timer_arg);
#endif // user_work_h__
