#ifndef __wfFunc_h__
#define __wfFunc_h__

#include "os_type.h"
#include "TypeDefine.h"


// typedef union   
// {
// 	struct
// 	{
// 		unsigned bWork:1;
// 		unsigned bShow:1;
// 		unsigned bSet:1;
// 		unsigned bCD:1;
// 		unsigned bID:1;
// 		unsigned bFinish:1;
// 		unsigned bSetTime:1;
// 		unsigned bMC:1;
// 	};
// 	unsigned char AllFlag;
// } _DisplayFlags;        // general flags
// _DisplayFlags DisplayFlags;
#define Smg_a    0x01
#define Smg_b    0x02
#define Smg_c    0x04
#define Smg_d    0x08
#define Smg_e    0x10
#define Smg_f    0x20
#define Smg_g    0x40
#define Smg_dp   0x80

#define Bmp0Map      Smg_a | Smg_b | Smg_c | Smg_d | Smg_e | Smg_f 
#define Bmp1Map      Smg_b | Smg_c
#define Bmp2Map      Smg_a | Smg_b | Smg_d | Smg_e | Smg_g
#define Bmp3Map      Smg_a | Smg_b | Smg_c | Smg_d | Smg_g
#define Bmp4Map      Smg_b | Smg_c | Smg_f | Smg_g
#define Bmp5Map      Smg_a | Smg_c | Smg_d | Smg_f | Smg_g
#define Bmp6Map      Smg_a | Smg_c | Smg_d | Smg_e | Smg_f | Smg_g
#define Bmp7Map      Smg_a | Smg_b | Smg_c 
#define Bmp8Map      Smg_a | Smg_b | Smg_c | Smg_d | Smg_e | Smg_f | Smg_g
#define Bmp9Map      Smg_a | Smg_b | Smg_c | Smg_d | Smg_f | Smg_g
#define BmpAMap      Smg_a | Smg_b | Smg_c | Smg_e | Smg_f | Smg_g
#define BmpBMap      Smg_c | Smg_d | Smg_e | Smg_f | Smg_g
#define BmpCMap      Smg_a | Smg_d | Smg_e | Smg_f 
#define BmpDMap      Smg_b | Smg_c | Smg_d | Smg_e | Smg_g
#define BmpEMap      Smg_a | Smg_d | Smg_e | Smg_f | Smg_g
#define BmpFMap      Smg_a | Smg_e | Smg_f | Smg_g
#define BmpUMap      Smg_b | Smg_c |Smg_d | Smg_e | Smg_f
#define BmprMap      Smg_e | Smg_g
#define BmpNMap      Smg_a | Smg_b | Smg_c | Smg_e | Smg_f 
#define BmpPMap      Smg_a | Smg_b | Smg_e | Smg_f | Smg_g 
#define BmpBlank     0
//        LCD 硬件定义
#define S10  sensor_data.DisplayReg[0]|=0x01//SEG0COM0//感叹号
#define S01  sensor_data.DisplayReg[1]|=0x01//SEG1COM0 //请勿
#define SA3  sensor_data.DisplayReg[2]|=0x01//SEG2COM0
#define SF3  sensor_data.DisplayReg[3]|=0x01//SEG3COM0
#define SA2  sensor_data.DisplayReg[4]|=0x01//SEG4COM0
#define SF2  sensor_data.DisplayReg[5]|=0x01//SEG5COM0
#define SA1  sensor_data.DisplayReg[6]|=0x01//SEG6COM0
#define SF1  sensor_data.DisplayReg[7]|=0x01//SEG7COM0

#define S09  sensor_data.DisplayReg[0]|=0x02//SEG0COM1//报修
#define S02  sensor_data.DisplayReg[1]|=0x02//SEG1COM1//连续
#define SB3  sensor_data.DisplayReg[2]|=0x02//SEG2COM1
#define SG3  sensor_data.DisplayReg[3]|=0x02//SEG3COM1
#define SB2  sensor_data.DisplayReg[4]|=0x02//SEG4COM1
#define SG2  sensor_data.DisplayReg[5]|=0x02//SEG5COM1
#define SB1  sensor_data.DisplayReg[6]|=0x02//SEG6COM1
#define SG1  sensor_data.DisplayReg[7]|=0x02//SEG7COM1


#define S08  sensor_data.DisplayReg[0]|=0x04//SEG0COM2//故障
#define S03  sensor_data.DisplayReg[1]|=0x04//SEG1COM2 //按键
#define SC3  sensor_data.DisplayReg[2]|=0x04//SEG2COM2
#define SE3  sensor_data.DisplayReg[3]|=0x04//SEG3COM2
#define SC2  sensor_data.DisplayReg[4]|=0x04//SEG4COM2
#define SE2  sensor_data.DisplayReg[5]|=0x04//SEG5COM2
#define SC1  sensor_data.DisplayReg[6]|=0x04//SEG6COM2
#define SE1  sensor_data.DisplayReg[7]|=0x04//SEG7COM2

#define S07  sensor_data.DisplayReg[0]|=0x08//SEG0COM3//雪花
#define S04  sensor_data.DisplayReg[1]|=0x08//SEG1COM3//温度符号
#define SD3  sensor_data.DisplayReg[2]|=0x08//SEG2COM3
#define SP1  sensor_data.DisplayReg[3]|=0x08//SEG3COM3
#define SD2  sensor_data.DisplayReg[4]|=0x08//SEG4COM3
#define S06  sensor_data.DisplayReg[5]|=0x08//SEG5COM3//投诉
#define SD1  sensor_data.DisplayReg[6]|=0x08//SEG6COM3
#define S05  sensor_data.DisplayReg[7]|=0x08//SEG7COM3//低温

//        LCD 硬件定义
#define _S10  sensor_data.DisplayReg[0]&=0xfe//SEG0COM0//感叹号
#define _S01  sensor_data.DisplayReg[1]&=0xfe//SEG1COM0 //请勿
#define _SA3  sensor_data.DisplayReg[2]&=0xfe//SEG2COM0
#define _SF3  sensor_data.DisplayReg[3]&=0xfe//SEG3COM0
#define _SA2  sensor_data.DisplayReg[4]&=0xfe//SEG4COM0
#define _SF2  sensor_data.DisplayReg[5]&=0xfe//SEG5COM0
#define _SA1  sensor_data.DisplayReg[6]&=0xfe//SEG6COM0
#define _SF1  sensor_data.DisplayReg[7]&=0xfe//SEG7COM0

#define _S09  sensor_data.DisplayReg[0]&=0xfd//SEG0COM1//报修
#define _S02  sensor_data.DisplayReg[1]&=0xfd//SEG1COM1//连续
#define _SB3  sensor_data.DisplayReg[2]&=0xfd//SEG2COM1
#define _SG3  sensor_data.DisplayReg[3]&=0xfd//SEG3COM1
#define _SB2  sensor_data.DisplayReg[4]&=0xfd//SEG4COM1
#define _SG2  sensor_data.DisplayReg[5]&=0xfd//SEG5COM1
#define _SB1  sensor_data.DisplayReg[6]&=0xfd//SEG6COM1
#define _SG1  sensor_data.DisplayReg[7]&=0xfd//SEG7COM1


#define _S08  sensor_data.DisplayReg[0]&=0xfb//SEG0COM2//故障
#define _S03  sensor_data.DisplayReg[1]&=0xfb//SEG1COM2 //按键
#define _SC3  sensor_data.DisplayReg[2]&=0xfb//SEG2COM2
#define _SE3  sensor_data.DisplayReg[3]&=0xfb//SEG3COM2
#define _SC2  sensor_data.DisplayReg[4]&=0xfb//SEG4COM2
#define _SE2  sensor_data.DisplayReg[5]&=0xfb//SEG5COM2
#define _SC1  sensor_data.DisplayReg[6]&=0xfb//SEG6COM2
#define _SE1  sensor_data.DisplayReg[7]&=0xfb//SEG7COM2

#define _S07  sensor_data.DisplayReg[0]&=0xf7//SEG0COM3//雪花
#define _S04  sensor_data.DisplayReg[1]&=0xf7//SEG1COM3//温度符号
#define _SD3  sensor_data.DisplayReg[2]&=0xf7//SEG2COM3
#define _SP1  sensor_data.DisplayReg[3]&=0xf7//SEG3COM3
#define _SD2  sensor_data.DisplayReg[4]&=0xf7//SEG4COM3
#define _S06  sensor_data.DisplayReg[5]&=0xf7//SEG5COM3//投诉
#define _SD1  sensor_data.DisplayReg[6]&=0xf7//SEG6COM3
#define _S05  sensor_data.DisplayReg[7]&=0xf7//SEG7COM3//低温

#define _S07_  sensor_data.DisplayReg[0]^=0x08//SEG0COM3//雪花
extern unsigned char TxTemperature[4];
extern const unsigned char SegCode[]; 
extern const unsigned char DS18X20_ToDecicel[16];
extern unsigned char ErrState;
enum {NoErr=0,NoWifi,WifiErr,MissDNS,ErrIP,ErrConnect,DisConnect,DisConnect1,ReConnect};
//
// void Display_Init(void);
// void LcdDisplay_CurTemp(void);
// void LcdDisplay_Err(void);
// void LcdDisplayAll(unsigned char x);
// void LCDShow(void);
// void GotoSleep(void);

#define LOW_NIBBLE(x)	(x&0x0F)
#define HIGH_NIBBLE(x)	(x>>4)
//void MakeTxTemperature(unsigned char tH,unsigned char tL);
#endif // wfFunc_h__
