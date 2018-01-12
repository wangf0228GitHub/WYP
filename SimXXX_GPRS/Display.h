#ifndef __Display_H__
#define __Display_H__

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

//        LCD 硬件定义
#define S10  SEG21COM0//感叹号
#define S01  SEG5COM0 //请勿
#define SA3  SEG11COM0
#define SF3  SEG16COM0
#define SA2  SEG6COM0
#define SF2  SEG3COM0
#define SA1  SEG23COM0
#define SF1  SEG22COM0

#define S09  SEG21COM1//报修
#define S02  SEG5COM1//连续
#define SB3  SEG11COM1
#define SG3  SEG16COM1
#define SB2  SEG6COM1
#define SG2  SEG3COM1
#define SB1  SEG23COM1
#define SG1  SEG22COM1


#define S08  SEG21COM2//故障
#define S03  SEG5COM2 //按键
#define SC3  SEG11COM2
#define SE3  SEG16COM2
#define SC2  SEG6COM2
#define SE2  SEG3COM2
#define SC1  SEG23COM2
#define SE1  SEG22COM2

#define S07  SEG21COM3//雪花
#define S04  SEG5COM3//温度符号
#define SD3  SEG11COM3
#define SP1  SEG16COM3
#define SD2  SEG6COM3
#define S06  SEG3COM3//投诉
#define SD1  SEG23COM3
#define S05  SEG22COM3//低温





const unsigned char SegCode[] =            
{
	Bmp0Map,Bmp1Map,Bmp2Map,Bmp3Map,Bmp4Map,Bmp5Map,Bmp6Map,Bmp7Map, //LCD段码表
	Bmp8Map,Bmp9Map,BmpAMap,BmpBMap,BmpCMap,BmpDMap,BmpEMap,BmpFMap,
	BmprMap
};

void DisplayInit( void );
void LcdDisplay_CurTemp(void);
void LcdDisplay_Err(void);
void LcdDisplay_CSQ(void);
void LcdDisplayAll(unsigned char x);
#endif
