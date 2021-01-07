#ifndef __Key_h__
#define __Key_h__

#define NoKey 0x0f

#define Key_Main_1 0x070e
#define Key_Main_2 0x060e
#define Key_Main_3 0x050e
#define Key_FastLeft 0x080e
#define Key_FastRight 0x040e

#define Key_ESC 0x080b
#define Key_Up 0x080d
#define Key_TAB 0x070d
#define Key_ENT 0x0807

#define Key_Left 0x070b
#define Key_Down 0x050d
#define Key_Right 0x060d
#define Key_Back 0x0707

#define Key_1 0x060b
#define Key_2 0x040d
#define Key_3 0x0607

#define Key_4 0x050b
#define Key_5 0x030d
#define Key_6 0x0507

#define Key_7 0x040b
#define Key_8 0x010d
#define Key_9 0x0407

#define Key_Start 0x030b
#define Key_0 0x020d
#define Key_Sharp 0x0307

#define Key_Power 0x020b
#define Key_Windows 0x010b
#define Key_Shift 0x0107
#define Key_Fn 0x0207

uint8_t KeyPollCheck(void);//tm1650¶Á°´¼ü
uint8_t GetKeyNum(void);
void CommonKeyFun(void);
#endif // __Key_h__
