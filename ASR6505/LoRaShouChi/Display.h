#ifndef __Display_H__
#define __Display_H__

#include "HardwareProfile.h"


typedef struct
{
	uint16_t width;
	uint16_t height;
	uint16_t id;
	uint16_t id2;
	uint16_t dir;
	uint16_t wramcmd;
	uint16_t setxcmd;
	uint16_t setycmd;
}_lcd_dev;

//const unsigned char LCD160X_LineStart[4]={0x80,0xC0,0x90,0xD0};
const unsigned char LCD160X_LineStart[4]={0x80,0x90,0x88,0x98};
void DisplayPage(void);
void DisplayPageVariable(void);
void DisplayInit( void );
void Display_Menu( void );
#endif
