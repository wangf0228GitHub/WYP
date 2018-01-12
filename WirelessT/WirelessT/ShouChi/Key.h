#ifndef __Key_h__
#define __Key_h__

#define KEY_Up		0xed
#define KEY_Down	0xe7//0xeb
#define KEY_Left	0xeb
#define KEY_Right	0xee


#define KEY_Set		0x77
#define KEY_0		0x7b
#define KEY_1		0x7d
#define KEY_2		0x7e
#define KEY_3		0xb7
#define KEY_4		0xbb
#define KEY_5		0xbd
#define KEY_6		0xbe
#define KEY_7		0xd7
#define KEY_8		0xdb
#define KEY_9		0xdd
#define KEY_Enter	0xde	//#ºÅ

#define NoKey 0xff
unsigned char KeyCheck(void);
#endif // __Key_h__
