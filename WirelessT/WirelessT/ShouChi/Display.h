#ifndef __Display_H__
#define __Display_H__

//const unsigned char LCD160X_LineStart[4]={0x80,0xC0,0x90,0xD0};
const unsigned char LCD160X_LineStart[4]={0x80,0x90,0x88,0x98};
void DisplayPage(void);
void DisplayPageVariable(void);
void DisplayInit( void );
void Display_Menu( void );
#endif
