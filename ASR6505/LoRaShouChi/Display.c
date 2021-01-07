#include "HardwareProfile.h"
#include "Display.h"
#include "wfDefine.h"
#include <stdio.h>
//#include "ZiMo.h"
_lcd_dev lcddev;
uint16_t  POINT_COLOR = 0x0000, BACK_COLOR = 0xFFFF;
void NT35510_Init(void)
{
	GPIO_Init(DB0_GPIO_Port, DB0_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB1_GPIO_Port, DB1_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB2_GPIO_Port, DB2_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB3_GPIO_Port, DB3_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB4_GPIO_Port, DB4_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB5_GPIO_Port, DB5_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB6_GPIO_Port, DB6_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB7_GPIO_Port, DB7_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB8_GPIO_Port, DB8_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB9_GPIO_Port, DB9_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB10_GPIO_Port, DB10_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB11_GPIO_Port, DB11_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB12_GPIO_Port, DB12_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB13_GPIO_Port, DB13_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB14_GPIO_Port, DB14_Pin, GPIO_Mode_Out_PP_Low_Slow);
	GPIO_Init(DB15_GPIO_Port, DB15_Pin, GPIO_Mode_Out_PP_Low_Slow);

	GPIO_Init(L_CS_GPIO_Port, L_CS_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(L_RS_GPIO_Port, L_RS_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(L_WR_GPIO_Port, L_WR_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(L_RD_GPIO_Port, L_RD_Pin, GPIO_Mode_Out_PP_High_Slow);
	GPIO_Init(L_REST_GPIO_Port, L_REST_Pin, GPIO_Mode_Out_PP_High_Slow);
}
void NT35510_WriteData(uint16_t data)
{
	GPIO_WriteBit(DB0_GPIO_Port, DB0_Pin, (BitAction)GetBit(data, 0));
	GPIO_WriteBit(DB1_GPIO_Port, DB1_Pin, (BitAction)GetBit(data, 1));
	GPIO_WriteBit(DB2_GPIO_Port, DB2_Pin, (BitAction)GetBit(data, 2));
	GPIO_WriteBit(DB3_GPIO_Port, DB3_Pin, (BitAction)GetBit(data, 3));
	GPIO_WriteBit(DB4_GPIO_Port, DB4_Pin, (BitAction)GetBit(data, 4));
	GPIO_WriteBit(DB5_GPIO_Port, DB5_Pin, (BitAction)GetBit(data, 5));
	GPIO_WriteBit(DB6_GPIO_Port, DB6_Pin, (BitAction)GetBit(data, 6));
	GPIO_WriteBit(DB7_GPIO_Port, DB7_Pin, (BitAction)GetBit(data, 7));
	GPIO_WriteBit(DB8_GPIO_Port, DB8_Pin, (BitAction)GetBit(data, 8));
	GPIO_WriteBit(DB9_GPIO_Port, DB9_Pin, (BitAction)GetBit(data, 9));
	GPIO_WriteBit(DB10_GPIO_Port, DB10_Pin, (BitAction)GetBit(data, 10));
	GPIO_WriteBit(DB11_GPIO_Port, DB11_Pin, (BitAction)GetBit(data, 11));
	GPIO_WriteBit(DB12_GPIO_Port, DB12_Pin, (BitAction)GetBit(data, 12));
	GPIO_WriteBit(DB13_GPIO_Port, DB13_Pin, (BitAction)GetBit(data, 13));
	GPIO_WriteBit(DB14_GPIO_Port, DB14_Pin, (BitAction)GetBit(data, 14));
	if ((data & 0x8000) == 0)
		GPIO_WriteBit(DB15_GPIO_Port, DB15_Pin, RESET);
	else
		GPIO_WriteBit(DB15_GPIO_Port, DB15_Pin, SET);
}

//д�Ĵ�������
//regval:�Ĵ���ֵ
void LCD_WR_REG(uint16_t regval)
{	
	GPIO_WriteBit(L_RS_GPIO_Port, L_RS_Pin, RESET);
	GPIO_WriteBit(L_CS_GPIO_Port, L_CS_Pin, RESET);
	NT35510_WriteData(regval);
	GPIO_WriteBit(L_WR_GPIO_Port, L_WR_Pin, RESET);
	GPIO_WriteBit(L_WR_GPIO_Port, L_WR_Pin, SET);
	GPIO_WriteBit(L_CS_GPIO_Port, L_CS_Pin, SET);
	GPIO_WriteBit(L_RS_GPIO_Port, L_RS_Pin, SET); 
}
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(uint16_t data)
{
	GPIO_WriteBit(L_CS_GPIO_Port, L_CS_Pin, RESET);
	NT35510_WriteData(data);
	GPIO_WriteBit(L_WR_GPIO_Port, L_WR_Pin, RESET);
	GPIO_WriteBit(L_WR_GPIO_Port, L_WR_Pin, SET);
	GPIO_WriteBit(L_CS_GPIO_Port, L_CS_Pin, SET);
}
//д�Ĵ���
//LCD_Reg:�Ĵ�����ַ
//LCD_RegValue:Ҫд�������
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue)
{
	LCD_WR_REG(LCD_Reg);		//д��Ҫд�ļĴ������	 
	LCD_WR_DATA(LCD_RegValue);//д������	    		 
}
////���Ĵ���
////LCD_Reg:�Ĵ�����ַ
////����ֵ:����������
//u16 LCD_ReadReg(u16 LCD_Reg)
//{
//	LCD_WR_REG(LCD_Reg);		//д��Ҫ���ļĴ������
//	delay_us(5);
//	return LCD_RD_DATA();		//���ض�����ֵ
//}
//��ʼдGRAM
void LCD_WriteRAM_Prepare(void)
{
	LCD_WR_REG(lcddev.wramcmd);
}
//LCDдGRAM
//RGB_Code:��ɫֵ
void LCD_WriteRAM(uint16_t RGB_Code)
{
	LCD_WR_DATA(RGB_Code);//дʮ��λGRAM
}
//��ILI93xx����������ΪGBR��ʽ��������д���ʱ��ΪRGB��ʽ��
//ͨ���ú���ת��
//c:GBR��ʽ����ɫֵ
//����ֵ��RGB��ʽ����ɫֵ
u16 LCD_BGR2RGB(u16 c)
{
	u16  r, g, b, rgb;
	b = (c >> 0) & 0x1f;
	g = (c >> 5) & 0x3f;
	r = (c >> 11) & 0x1f;
	rgb = (b << 11) + (g << 5) + (r << 0);
	return(rgb);
}
//���ù��λ��
//Xpos:������
//Ypos:������
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{
	LCD_WR_REG(lcddev.setxcmd); LCD_WR_DATA(Xpos >> 8);
	LCD_WR_REG(lcddev.setxcmd + 1); LCD_WR_DATA(Xpos & 0XFF);
	LCD_WR_REG(lcddev.setycmd); LCD_WR_DATA(Ypos >> 8);
	LCD_WR_REG(lcddev.setycmd + 1); LCD_WR_DATA(Ypos & 0XFF);
}
//��������
//color:Ҫ���������ɫ
void LCD_Clear(uint16_t color)
{
	u32 index = 0;
	u32 totalpoint = lcddev.width;
	totalpoint *= lcddev.height; 			//�õ��ܵ���
	LCD_SetCursor(0x00, 0x0000);	//���ù��λ�� 
	LCD_WriteRAM_Prepare();     		//��ʼд��GRAM	 	  
	for (index = 0; index < totalpoint; index++)
	{
		LCD_WR_DATA(color);
	}
}
//����LCD���Զ�ɨ�跽��
//ע��:�����������ܻ��ܵ��˺������õ�Ӱ��(������9341/6804����������),
//����,һ������ΪL2R_U2D����,�������Ϊ����ɨ�跽ʽ,���ܵ�����ʾ������.
//dir:0~7,����8������(���嶨���lcd.h)
//9320/9325/9328/4531/4535/1505/b505/5408/9341/5310/5510/1963��IC�Ѿ�ʵ�ʲ���	   	   
void LCD_Scan_Dir(uint8_t dir)
{
	u16 regval = 0;
	u16 dirreg = 0;
	u16 temp;
	regval |= (0 << 7) | (0 << 6) | (0 << 5);
	dirreg = 0X3600;
	LCD_WriteReg(dirreg, regval);
	if (regval & 0X20)
	{
		if (lcddev.width < lcddev.height)//����X,Y
		{
			temp = lcddev.width;
			lcddev.width = lcddev.height;
			lcddev.height = temp;
		}
	}
	else
	{
		if (lcddev.width > lcddev.height)//����X,Y
		{
			temp = lcddev.width;
			lcddev.width = lcddev.height;
			lcddev.height = temp;
		}
	}
	LCD_WR_REG(lcddev.setxcmd); LCD_WR_DATA(0);
	LCD_WR_REG(lcddev.setxcmd + 1); LCD_WR_DATA(0);
	LCD_WR_REG(lcddev.setxcmd + 2); LCD_WR_DATA((lcddev.width - 1) >> 8);
	LCD_WR_REG(lcddev.setxcmd + 3); LCD_WR_DATA((lcddev.width - 1) & 0XFF);
	LCD_WR_REG(lcddev.setycmd); LCD_WR_DATA(0);
	LCD_WR_REG(lcddev.setycmd + 1); LCD_WR_DATA(0);
	LCD_WR_REG(lcddev.setycmd + 2); LCD_WR_DATA((lcddev.height - 1) >> 8);
	LCD_WR_REG(lcddev.setycmd + 3); LCD_WR_DATA((lcddev.height - 1) & 0XFF);	
}
void LCD_Init(void)
{
	uint8_t i = 0;
	NT35510_Init();
	LCD_WriteReg(0x0000, 0x0001);
	DelayMs(50); // delay 50 ms 
	lcddev.id = 0x5510;
	LCD_WriteReg(0xF000, 0x55);
	LCD_WriteReg(0xF001, 0xAA);
	LCD_WriteReg(0xF002, 0x52);
	LCD_WriteReg(0xF003, 0x08);
	LCD_WriteReg(0xF004, 0x01);
	//AVDD Set AVDD 5.2V
	LCD_WriteReg(0xB000, 0x0D);
	LCD_WriteReg(0xB001, 0x0D);
	LCD_WriteReg(0xB002, 0x0D);
	//AVDD ratio
	LCD_WriteReg(0xB600, 0x34);
	LCD_WriteReg(0xB601, 0x34);
	LCD_WriteReg(0xB602, 0x34);
	//AVEE -5.2V
	LCD_WriteReg(0xB100, 0x0D);
	LCD_WriteReg(0xB101, 0x0D);
	LCD_WriteReg(0xB102, 0x0D);
	//AVEE ratio
	LCD_WriteReg(0xB700, 0x34);
	LCD_WriteReg(0xB701, 0x34);
	LCD_WriteReg(0xB702, 0x34);
	//VCL -2.5V
	LCD_WriteReg(0xB200, 0x00);
	LCD_WriteReg(0xB201, 0x00);
	LCD_WriteReg(0xB202, 0x00);
	//VCL ratio
	LCD_WriteReg(0xB800, 0x24);
	LCD_WriteReg(0xB801, 0x24);
	LCD_WriteReg(0xB802, 0x24);
	//VGH 15V (Free pump)
	LCD_WriteReg(0xBF00, 0x01);
	LCD_WriteReg(0xB300, 0x0F);
	LCD_WriteReg(0xB301, 0x0F);
	LCD_WriteReg(0xB302, 0x0F);
	//VGH ratio
	LCD_WriteReg(0xB900, 0x34);
	LCD_WriteReg(0xB901, 0x34);
	LCD_WriteReg(0xB902, 0x34);
	//VGL_REG -10V
	LCD_WriteReg(0xB500, 0x08);
	LCD_WriteReg(0xB501, 0x08);
	LCD_WriteReg(0xB502, 0x08);
	LCD_WriteReg(0xC200, 0x03);
	//VGLX ratio
	LCD_WriteReg(0xBA00, 0x24);
	LCD_WriteReg(0xBA01, 0x24);
	LCD_WriteReg(0xBA02, 0x24);
	//VGMP/VGSP 4.5V/0V
	LCD_WriteReg(0xBC00, 0x00);
	LCD_WriteReg(0xBC01, 0x78);
	LCD_WriteReg(0xBC02, 0x00);
	//VGMN/VGSN -4.5V/0V
	LCD_WriteReg(0xBD00, 0x00);
	LCD_WriteReg(0xBD01, 0x78);
	LCD_WriteReg(0xBD02, 0x00);
	//VCOM
	LCD_WriteReg(0xBE00, 0x00);
	LCD_WriteReg(0xBE01, 0x64);
	//Gamma Setting
	LCD_WriteReg(0xD100, 0x00);
	LCD_WriteReg(0xD101, 0x33);
	LCD_WriteReg(0xD102, 0x00);
	LCD_WriteReg(0xD103, 0x34);
	LCD_WriteReg(0xD104, 0x00);
	LCD_WriteReg(0xD105, 0x3A);
	LCD_WriteReg(0xD106, 0x00);
	LCD_WriteReg(0xD107, 0x4A);
	LCD_WriteReg(0xD108, 0x00);
	LCD_WriteReg(0xD109, 0x5C);
	LCD_WriteReg(0xD10A, 0x00);
	LCD_WriteReg(0xD10B, 0x81);
	LCD_WriteReg(0xD10C, 0x00);
	LCD_WriteReg(0xD10D, 0xA6);
	LCD_WriteReg(0xD10E, 0x00);
	LCD_WriteReg(0xD10F, 0xE5);
	LCD_WriteReg(0xD110, 0x01);
	LCD_WriteReg(0xD111, 0x13);
	LCD_WriteReg(0xD112, 0x01);
	LCD_WriteReg(0xD113, 0x54);
	LCD_WriteReg(0xD114, 0x01);
	LCD_WriteReg(0xD115, 0x82);
	LCD_WriteReg(0xD116, 0x01);
	LCD_WriteReg(0xD117, 0xCA);
	LCD_WriteReg(0xD118, 0x02);
	LCD_WriteReg(0xD119, 0x00);
	LCD_WriteReg(0xD11A, 0x02);
	LCD_WriteReg(0xD11B, 0x01);
	LCD_WriteReg(0xD11C, 0x02);
	LCD_WriteReg(0xD11D, 0x34);
	LCD_WriteReg(0xD11E, 0x02);
	LCD_WriteReg(0xD11F, 0x67);
	LCD_WriteReg(0xD120, 0x02);
	LCD_WriteReg(0xD121, 0x84);
	LCD_WriteReg(0xD122, 0x02);
	LCD_WriteReg(0xD123, 0xA4);
	LCD_WriteReg(0xD124, 0x02);
	LCD_WriteReg(0xD125, 0xB7);
	LCD_WriteReg(0xD126, 0x02);
	LCD_WriteReg(0xD127, 0xCF);
	LCD_WriteReg(0xD128, 0x02);
	LCD_WriteReg(0xD129, 0xDE);
	LCD_WriteReg(0xD12A, 0x02);
	LCD_WriteReg(0xD12B, 0xF2);
	LCD_WriteReg(0xD12C, 0x02);
	LCD_WriteReg(0xD12D, 0xFE);
	LCD_WriteReg(0xD12E, 0x03);
	LCD_WriteReg(0xD12F, 0x10);
	LCD_WriteReg(0xD130, 0x03);
	LCD_WriteReg(0xD131, 0x33);
	LCD_WriteReg(0xD132, 0x03);
	LCD_WriteReg(0xD133, 0x6D);
	LCD_WriteReg(0xD200, 0x00);
	LCD_WriteReg(0xD201, 0x33);
	LCD_WriteReg(0xD202, 0x00);
	LCD_WriteReg(0xD203, 0x34);
	LCD_WriteReg(0xD204, 0x00);
	LCD_WriteReg(0xD205, 0x3A);
	LCD_WriteReg(0xD206, 0x00);
	LCD_WriteReg(0xD207, 0x4A);
	LCD_WriteReg(0xD208, 0x00);
	LCD_WriteReg(0xD209, 0x5C);
	LCD_WriteReg(0xD20A, 0x00);

	LCD_WriteReg(0xD20B, 0x81);
	LCD_WriteReg(0xD20C, 0x00);
	LCD_WriteReg(0xD20D, 0xA6);
	LCD_WriteReg(0xD20E, 0x00);
	LCD_WriteReg(0xD20F, 0xE5);
	LCD_WriteReg(0xD210, 0x01);
	LCD_WriteReg(0xD211, 0x13);
	LCD_WriteReg(0xD212, 0x01);
	LCD_WriteReg(0xD213, 0x54);
	LCD_WriteReg(0xD214, 0x01);
	LCD_WriteReg(0xD215, 0x82);
	LCD_WriteReg(0xD216, 0x01);
	LCD_WriteReg(0xD217, 0xCA);
	LCD_WriteReg(0xD218, 0x02);
	LCD_WriteReg(0xD219, 0x00);
	LCD_WriteReg(0xD21A, 0x02);
	LCD_WriteReg(0xD21B, 0x01);
	LCD_WriteReg(0xD21C, 0x02);
	LCD_WriteReg(0xD21D, 0x34);
	LCD_WriteReg(0xD21E, 0x02);
	LCD_WriteReg(0xD21F, 0x67);
	LCD_WriteReg(0xD220, 0x02);
	LCD_WriteReg(0xD221, 0x84);
	LCD_WriteReg(0xD222, 0x02);
	LCD_WriteReg(0xD223, 0xA4);
	LCD_WriteReg(0xD224, 0x02);
	LCD_WriteReg(0xD225, 0xB7);
	LCD_WriteReg(0xD226, 0x02);
	LCD_WriteReg(0xD227, 0xCF);
	LCD_WriteReg(0xD228, 0x02);
	LCD_WriteReg(0xD229, 0xDE);
	LCD_WriteReg(0xD22A, 0x02);
	LCD_WriteReg(0xD22B, 0xF2);
	LCD_WriteReg(0xD22C, 0x02);
	LCD_WriteReg(0xD22D, 0xFE);
	LCD_WriteReg(0xD22E, 0x03);
	LCD_WriteReg(0xD22F, 0x10);
	LCD_WriteReg(0xD230, 0x03);
	LCD_WriteReg(0xD231, 0x33);
	LCD_WriteReg(0xD232, 0x03);
	LCD_WriteReg(0xD233, 0x6D);
	LCD_WriteReg(0xD300, 0x00);
	LCD_WriteReg(0xD301, 0x33);
	LCD_WriteReg(0xD302, 0x00);
	LCD_WriteReg(0xD303, 0x34);
	LCD_WriteReg(0xD304, 0x00);
	LCD_WriteReg(0xD305, 0x3A);
	LCD_WriteReg(0xD306, 0x00);
	LCD_WriteReg(0xD307, 0x4A);
	LCD_WriteReg(0xD308, 0x00);
	LCD_WriteReg(0xD309, 0x5C);
	LCD_WriteReg(0xD30A, 0x00);

	LCD_WriteReg(0xD30B, 0x81);
	LCD_WriteReg(0xD30C, 0x00);
	LCD_WriteReg(0xD30D, 0xA6);
	LCD_WriteReg(0xD30E, 0x00);
	LCD_WriteReg(0xD30F, 0xE5);
	LCD_WriteReg(0xD310, 0x01);
	LCD_WriteReg(0xD311, 0x13);
	LCD_WriteReg(0xD312, 0x01);
	LCD_WriteReg(0xD313, 0x54);
	LCD_WriteReg(0xD314, 0x01);
	LCD_WriteReg(0xD315, 0x82);
	LCD_WriteReg(0xD316, 0x01);
	LCD_WriteReg(0xD317, 0xCA);
	LCD_WriteReg(0xD318, 0x02);
	LCD_WriteReg(0xD319, 0x00);
	LCD_WriteReg(0xD31A, 0x02);
	LCD_WriteReg(0xD31B, 0x01);
	LCD_WriteReg(0xD31C, 0x02);
	LCD_WriteReg(0xD31D, 0x34);
	LCD_WriteReg(0xD31E, 0x02);
	LCD_WriteReg(0xD31F, 0x67);
	LCD_WriteReg(0xD320, 0x02);
	LCD_WriteReg(0xD321, 0x84);
	LCD_WriteReg(0xD322, 0x02);
	LCD_WriteReg(0xD323, 0xA4);
	LCD_WriteReg(0xD324, 0x02);
	LCD_WriteReg(0xD325, 0xB7);
	LCD_WriteReg(0xD326, 0x02);
	LCD_WriteReg(0xD327, 0xCF);
	LCD_WriteReg(0xD328, 0x02);
	LCD_WriteReg(0xD329, 0xDE);
	LCD_WriteReg(0xD32A, 0x02);
	LCD_WriteReg(0xD32B, 0xF2);
	LCD_WriteReg(0xD32C, 0x02);
	LCD_WriteReg(0xD32D, 0xFE);
	LCD_WriteReg(0xD32E, 0x03);
	LCD_WriteReg(0xD32F, 0x10);
	LCD_WriteReg(0xD330, 0x03);
	LCD_WriteReg(0xD331, 0x33);
	LCD_WriteReg(0xD332, 0x03);
	LCD_WriteReg(0xD333, 0x6D);
	LCD_WriteReg(0xD400, 0x00);
	LCD_WriteReg(0xD401, 0x33);
	LCD_WriteReg(0xD402, 0x00);
	LCD_WriteReg(0xD403, 0x34);
	LCD_WriteReg(0xD404, 0x00);
	LCD_WriteReg(0xD405, 0x3A);
	LCD_WriteReg(0xD406, 0x00);
	LCD_WriteReg(0xD407, 0x4A);
	LCD_WriteReg(0xD408, 0x00);
	LCD_WriteReg(0xD409, 0x5C);
	LCD_WriteReg(0xD40A, 0x00);
	LCD_WriteReg(0xD40B, 0x81);

	LCD_WriteReg(0xD40C, 0x00);
	LCD_WriteReg(0xD40D, 0xA6);
	LCD_WriteReg(0xD40E, 0x00);
	LCD_WriteReg(0xD40F, 0xE5);
	LCD_WriteReg(0xD410, 0x01);
	LCD_WriteReg(0xD411, 0x13);
	LCD_WriteReg(0xD412, 0x01);
	LCD_WriteReg(0xD413, 0x54);
	LCD_WriteReg(0xD414, 0x01);
	LCD_WriteReg(0xD415, 0x82);
	LCD_WriteReg(0xD416, 0x01);
	LCD_WriteReg(0xD417, 0xCA);
	LCD_WriteReg(0xD418, 0x02);
	LCD_WriteReg(0xD419, 0x00);
	LCD_WriteReg(0xD41A, 0x02);
	LCD_WriteReg(0xD41B, 0x01);
	LCD_WriteReg(0xD41C, 0x02);
	LCD_WriteReg(0xD41D, 0x34);
	LCD_WriteReg(0xD41E, 0x02);
	LCD_WriteReg(0xD41F, 0x67);
	LCD_WriteReg(0xD420, 0x02);
	LCD_WriteReg(0xD421, 0x84);
	LCD_WriteReg(0xD422, 0x02);
	LCD_WriteReg(0xD423, 0xA4);
	LCD_WriteReg(0xD424, 0x02);
	LCD_WriteReg(0xD425, 0xB7);
	LCD_WriteReg(0xD426, 0x02);
	LCD_WriteReg(0xD427, 0xCF);
	LCD_WriteReg(0xD428, 0x02);
	LCD_WriteReg(0xD429, 0xDE);
	LCD_WriteReg(0xD42A, 0x02);
	LCD_WriteReg(0xD42B, 0xF2);
	LCD_WriteReg(0xD42C, 0x02);
	LCD_WriteReg(0xD42D, 0xFE);
	LCD_WriteReg(0xD42E, 0x03);
	LCD_WriteReg(0xD42F, 0x10);
	LCD_WriteReg(0xD430, 0x03);
	LCD_WriteReg(0xD431, 0x33);
	LCD_WriteReg(0xD432, 0x03);
	LCD_WriteReg(0xD433, 0x6D);
	LCD_WriteReg(0xD500, 0x00);
	LCD_WriteReg(0xD501, 0x33);
	LCD_WriteReg(0xD502, 0x00);
	LCD_WriteReg(0xD503, 0x34);
	LCD_WriteReg(0xD504, 0x00);
	LCD_WriteReg(0xD505, 0x3A);
	LCD_WriteReg(0xD506, 0x00);
	LCD_WriteReg(0xD507, 0x4A);
	LCD_WriteReg(0xD508, 0x00);
	LCD_WriteReg(0xD509, 0x5C);
	LCD_WriteReg(0xD50A, 0x00);
	LCD_WriteReg(0xD50B, 0x81);

	LCD_WriteReg(0xD50C, 0x00);
	LCD_WriteReg(0xD50D, 0xA6);
	LCD_WriteReg(0xD50E, 0x00);
	LCD_WriteReg(0xD50F, 0xE5);
	LCD_WriteReg(0xD510, 0x01);
	LCD_WriteReg(0xD511, 0x13);
	LCD_WriteReg(0xD512, 0x01);
	LCD_WriteReg(0xD513, 0x54);
	LCD_WriteReg(0xD514, 0x01);
	LCD_WriteReg(0xD515, 0x82);
	LCD_WriteReg(0xD516, 0x01);
	LCD_WriteReg(0xD517, 0xCA);
	LCD_WriteReg(0xD518, 0x02);
	LCD_WriteReg(0xD519, 0x00);
	LCD_WriteReg(0xD51A, 0x02);
	LCD_WriteReg(0xD51B, 0x01);
	LCD_WriteReg(0xD51C, 0x02);
	LCD_WriteReg(0xD51D, 0x34);
	LCD_WriteReg(0xD51E, 0x02);
	LCD_WriteReg(0xD51F, 0x67);
	LCD_WriteReg(0xD520, 0x02);
	LCD_WriteReg(0xD521, 0x84);
	LCD_WriteReg(0xD522, 0x02);
	LCD_WriteReg(0xD523, 0xA4);
	LCD_WriteReg(0xD524, 0x02);
	LCD_WriteReg(0xD525, 0xB7);
	LCD_WriteReg(0xD526, 0x02);
	LCD_WriteReg(0xD527, 0xCF);
	LCD_WriteReg(0xD528, 0x02);
	LCD_WriteReg(0xD529, 0xDE);
	LCD_WriteReg(0xD52A, 0x02);
	LCD_WriteReg(0xD52B, 0xF2);
	LCD_WriteReg(0xD52C, 0x02);
	LCD_WriteReg(0xD52D, 0xFE);
	LCD_WriteReg(0xD52E, 0x03);
	LCD_WriteReg(0xD52F, 0x10);
	LCD_WriteReg(0xD530, 0x03);
	LCD_WriteReg(0xD531, 0x33);
	LCD_WriteReg(0xD532, 0x03);
	LCD_WriteReg(0xD533, 0x6D);
	LCD_WriteReg(0xD600, 0x00);
	LCD_WriteReg(0xD601, 0x33);
	LCD_WriteReg(0xD602, 0x00);
	LCD_WriteReg(0xD603, 0x34);
	LCD_WriteReg(0xD604, 0x00);
	LCD_WriteReg(0xD605, 0x3A);
	LCD_WriteReg(0xD606, 0x00);
	LCD_WriteReg(0xD607, 0x4A);
	LCD_WriteReg(0xD608, 0x00);
	LCD_WriteReg(0xD609, 0x5C);
	LCD_WriteReg(0xD60A, 0x00);
	LCD_WriteReg(0xD60B, 0x81);

	LCD_WriteReg(0xD60C, 0x00);
	LCD_WriteReg(0xD60D, 0xA6);
	LCD_WriteReg(0xD60E, 0x00);
	LCD_WriteReg(0xD60F, 0xE5);
	LCD_WriteReg(0xD610, 0x01);
	LCD_WriteReg(0xD611, 0x13);
	LCD_WriteReg(0xD612, 0x01);
	LCD_WriteReg(0xD613, 0x54);
	LCD_WriteReg(0xD614, 0x01);
	LCD_WriteReg(0xD615, 0x82);
	LCD_WriteReg(0xD616, 0x01);
	LCD_WriteReg(0xD617, 0xCA);
	LCD_WriteReg(0xD618, 0x02);
	LCD_WriteReg(0xD619, 0x00);
	LCD_WriteReg(0xD61A, 0x02);
	LCD_WriteReg(0xD61B, 0x01);
	LCD_WriteReg(0xD61C, 0x02);
	LCD_WriteReg(0xD61D, 0x34);
	LCD_WriteReg(0xD61E, 0x02);
	LCD_WriteReg(0xD61F, 0x67);
	LCD_WriteReg(0xD620, 0x02);
	LCD_WriteReg(0xD621, 0x84);
	LCD_WriteReg(0xD622, 0x02);
	LCD_WriteReg(0xD623, 0xA4);
	LCD_WriteReg(0xD624, 0x02);
	LCD_WriteReg(0xD625, 0xB7);
	LCD_WriteReg(0xD626, 0x02);
	LCD_WriteReg(0xD627, 0xCF);
	LCD_WriteReg(0xD628, 0x02);
	LCD_WriteReg(0xD629, 0xDE);
	LCD_WriteReg(0xD62A, 0x02);
	LCD_WriteReg(0xD62B, 0xF2);
	LCD_WriteReg(0xD62C, 0x02);
	LCD_WriteReg(0xD62D, 0xFE);
	LCD_WriteReg(0xD62E, 0x03);
	LCD_WriteReg(0xD62F, 0x10);
	LCD_WriteReg(0xD630, 0x03);
	LCD_WriteReg(0xD631, 0x33);
	LCD_WriteReg(0xD632, 0x03);
	LCD_WriteReg(0xD633, 0x6D);
	//LV2 Page 0 enable
	LCD_WriteReg(0xF000, 0x55);
	LCD_WriteReg(0xF001, 0xAA);
	LCD_WriteReg(0xF002, 0x52);
	LCD_WriteReg(0xF003, 0x08);
	LCD_WriteReg(0xF004, 0x00);
	//Display control
	LCD_WriteReg(0xB100, 0xCC);
	LCD_WriteReg(0xB101, 0x00);
	//Source hold time
	LCD_WriteReg(0xB600, 0x05);
	//Gate EQ control
	LCD_WriteReg(0xB700, 0x70);
	LCD_WriteReg(0xB701, 0x70);
	//Source EQ control (Mode 2)
	LCD_WriteReg(0xB800, 0x01);
	LCD_WriteReg(0xB801, 0x03);
	LCD_WriteReg(0xB802, 0x03);
	LCD_WriteReg(0xB803, 0x03);
	//Inversion mode (2-dot)
	LCD_WriteReg(0xBC00, 0x02);
	LCD_WriteReg(0xBC01, 0x00);
	LCD_WriteReg(0xBC02, 0x00);
	//Timing control 4H w/ 4-delay
	LCD_WriteReg(0xC900, 0xD0);
	LCD_WriteReg(0xC901, 0x02);
	LCD_WriteReg(0xC902, 0x50);
	LCD_WriteReg(0xC903, 0x50);
	LCD_WriteReg(0xC904, 0x50);
	LCD_WriteReg(0x3500, 0x00);
	LCD_WriteReg(0x3A00, 0x55);  //16-bit/pixel
	LCD_WR_REG(0x1100);
	__delay_us(120);
	LCD_WR_REG(0x2900);

	//Ĭ��Ϊ����
	lcddev.dir = 0;	//����		
	lcddev.wramcmd = 0X2C00;
	lcddev.setxcmd = 0X2A00;
	lcddev.setycmd = 0X2B00;
	lcddev.width = 480;
	lcddev.height = 800;
	LCD_Scan_Dir(0);	//Ĭ��ɨ�跽��
	LCD_LED_On();				//��������
	LCD_Clear(BACK_COLOR);
}
void LCD_RESET(void)
{
	GPIO_WriteBit(L_REST_GPIO_Port, L_REST_Pin, RESET);
	DelayMs(100);
	GPIO_WriteBit(L_REST_GPIO_Port, L_REST_Pin, SET);
	DelayMs(50);
}
//���ô���,���Զ����û������굽�������Ͻ�(sx,sy).
//sx,sy:������ʼ����(���Ͻ�)
//width,height:���ڿ�Ⱥ͸߶�,�������0!!
//�����С:width*height. 
void LCD_Set_Window(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height)
{
	uint8_t hsareg, heareg, vsareg, veareg;
	uint16_t hsaval, heaval, vsaval, veaval;
	uint16_t twidth, theight;
	twidth = sx + width - 1;
	theight = sy + height - 1;
	
	LCD_WR_REG(lcddev.setxcmd); LCD_WR_DATA(sx >> 8);
	LCD_WR_REG(lcddev.setxcmd + 1); LCD_WR_DATA(sx & 0XFF);
	LCD_WR_REG(lcddev.setxcmd + 2); LCD_WR_DATA(twidth >> 8);
	LCD_WR_REG(lcddev.setxcmd + 3); LCD_WR_DATA(twidth & 0XFF);
	LCD_WR_REG(lcddev.setycmd); LCD_WR_DATA(sy >> 8);
	LCD_WR_REG(lcddev.setycmd + 1); LCD_WR_DATA(sy & 0XFF);
	LCD_WR_REG(lcddev.setycmd + 2); LCD_WR_DATA(theight >> 8);
	LCD_WR_REG(lcddev.setycmd + 3); LCD_WR_DATA(theight & 0XFF);
}
void Gui_Drawbmp16(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const unsigned char *p) //��ʾ40*40 QQͼƬ
{
	uint32_t i;
	uint32_t len;
	unsigned char picH, picL;
	uint16_t pic;
	LCD_Set_Window(x, y, w, h);//��������
	len = w*h;
	for (i = 0; i < len; i++)
	{
		picL = *(p + i * 2);
		picH = *(p + i * 2 + 1);
		LCD_WR_DATA(picH << 8 | picL);
	}
	LCD_Set_Window(0, 0, lcddev.width, lcddev.height);//�ָ���ʾ����Ϊȫ��
}
//��ָ��λ����ʾһ���ַ�
//x,y:��ʼ����
//num:Ҫ��ʾ���ַ�:" "--->"~"
//size:�����С 12/16/24
//mode:���ӷ�ʽ(1)���Ƿǵ��ӷ�ʽ(0)
void LCD_ShowChar(u16 x, u16 y, u8 num, u8 size, u8 mode)
{
// 	u8 temp, t1, t;
// 	u16 y0 = y;
// 	u8 csize = (size / 8 + ((size % 8) ? 1 : 0))*(size / 2);		//�õ�����һ���ַ���Ӧ������ռ���ֽ���	
// 	num = num - ' ';//�õ�ƫ�ƺ��ֵ��ASCII�ֿ��Ǵӿո�ʼȡģ������-' '���Ƕ�Ӧ�ַ����ֿ⣩
// 	for (t = 0; t<csize; t++)
// 	{
// 		if (size == 12)temp = asc2_1206[num][t]; 	 	//����1206����
// 		else if (size == 16)temp = asc2_1608[num][t];	//����1608����
// 		else if (size == 24)temp = asc2_2412[num][t];	//����2412����
// 		else return;								//û�е��ֿ�
// 		for (t1 = 0; t1<8; t1++)
// 		{
// 			if (temp & 0x80)LCD_Fast_DrawPoint(x, y, POINT_COLOR);
// 			else if (mode == 0)LCD_Fast_DrawPoint(x, y, BACK_COLOR);
// 			temp <<= 1;
// 			y++;
// 			if (y >= lcddev.height)return;		//��������
// 			if ((y - y0) == size)
// 			{
// 				y = y0;
// 				x++;
// 				if (x >= lcddev.width)return;	//��������
// 				break;
// 			}
// 		}
// 	}
}

//��ʾ����,��λΪ0,����ʾ
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
void LCD_ShowNum(u16 x, u16 y, u32 num, u8 len, u8 size)
{

}
//��ʾ�ַ���
//x,y:�������
//width,height:�����С  
//size:�����С
//*p:�ַ�����ʼ��ַ		  
void LCD_ShowString(u16 x, u16 y, u16 width, u16 height, u8 size, u8 *p)
{
	u8 x0 = x;
	width += x;
	height += y;
	while ((*p <= '~') && (*p >= ' '))//�ж��ǲ��ǷǷ��ַ�!
	{
		if (x >= width) { x = x0; y += size; }
		if (y >= height)break;//�˳�
		LCD_ShowChar(x, y, *p, size, 0);
		x += size / 2;
		p++;
	}
}
void Display_Clear(void)
{
	LCD_Clear(BACK_COLOR);
}
void Display_ShowPic(unsigned char index)
{
	Display_TxHeader();
	Display_UartTx(0x80);
	Display_UartTx(index);
	Display_TxEnder();
}
void Display_SetTxtColor(unsigned char index)
{
	Display_TxHeader();
	Display_UartTx(0x40);
	Display_UartTx(0x00);
	switch(index)
	{
	case 1:	//��ɫ	
		Display_UartTx(0xff);
		Display_UartTx(0xff);
		break;
	case 2://��ɫ
		Display_UartTx(0xff);
		Display_UartTx(0xe0);
		break;
	case 3://��ɫ
		Display_UartTx(0xf8);
		Display_UartTx(0x00);
		break;
	case 4://��ɫ
		Display_UartTx(0x00);
		Display_UartTx(0x1f);
		break;
	}	
	Display_TxEnder();
}
void DisplayInit( void )
{
	//Display_Clear();
	Display_ShowPic(0);
	Display_SetTxtColor(1);	
}
void Display_ShowTxt(unsigned char font,unsigned char x,unsigned int y,char* pBuffer,unsigned int len)
{
	unsigned int i;
	Display_TxHeader();
	Display_UartTx(0x51);
	Display_UartTx(font);
	Display_UartTx(0);
	//Display_UartTx(0);
	Display_UartTx(x);	
	Display_UartTx(HIGH_BYTE(y));
	Display_UartTx(LOW_BYTE(y));	
	for(i=0;i<len;i++)
	{
		Display_UartTx(pBuffer[i]);
	}
	Display_TxEnder();
}
void Display_ConPC(void)
{
	unsigned int i,sum;
	sum=sprintf(DisplayLine,"Connect to PC");
	Display_TxHeader();
	Display_UartTx(0x50);
	Display_UartTx(3);
	Display_UartTx(0);
	Display_UartTx(0);
	//Display_UartTx(0);
	Display_UartTx(20);	
	Display_UartTx(0);
	Display_UartTx(140);	
	for(i=0;i<sum;i++)
	{
		Display_UartTx(DisplayLine[i]);
	}
	Display_TxEnder();
}
void Display_BK(unsigned char level)
{
	Display_TxHeader();
	if(level==0)
	{
		Display_UartTx(0x02);
		Display_UartTx(0x01);
	}
	else if(level==0xff)
	{
		Display_UartTx(0x02);
		Display_UartTx(0x00);
	}
	else
	{
		Display_UartTx(0x90);
		Display_UartTx(level);
	}	
	Display_TxEnder();
}
void Display_ShowAnalyzeTemp(void)
{	
	unsigned char i,t1,t2,x,x1;
	unsigned int y,len;
	Display_SetTxtColor(1);
	t1=(SensorData4Save.TData.u16&0x0fff)>>4;
	t2=SensorData4Save.TData.u16&0x000f;
	sprintf(DisplayLine,AnalyzeString,t1,DS18X20_ToDecicel[t2]);
	y=DisplayRow*21;
	y=y+90;
	Display_ShowTxt(1,200,y,DisplayLine,5);
}
void Display_ShowHistory(void)
{	
	unsigned char i,t1,t2,x,x1;
	unsigned int y,len;
	for(i=0;i<History_ListCount;i++)
	{
		t1=(SensorData4ShowList[i].TData.u16&0x0fff)>>4;
		t2=SensorData4ShowList[i].TData.u16&0x000f;
		sprintf(DisplayLine,HistoryString,SensorData4ShowList[i].Month,SensorData4ShowList[i].Day,SensorData4ShowList[i].Hour,SensorData4ShowList[i].Minute,t1,DS18X20_ToDecicel[t2]);
		y=i*21;
		y=y+111;
		Display_ShowTxt(1,0,y,DisplayLine,30);
	}
}
void Display_ShowBatt(void)
{	
	unsigned char x;
	unsigned int ix;
	unsigned long l;
	l=((unsigned long)ADValue)*1000;
	l=l*3;
	l=l/6;
	ix=(unsigned int)(l>>9);
	if(ix<583)
		ix=0;
	else
	{
		ix=ix-583;
		if(ix>100)
			ix=100;
	}
	x=sprintf(DisplayLine,"%3u%%",ix);		
	Display_ShowTxt(1,208,0,DisplayLine,x);
}
void Display_ShowRealTemp(void)
{	
	unsigned char i,t1,t2,x,x1,j;
	unsigned int y,len;
	t1=(SensorData4Save.TData.u16&0x0fff)>>4;
	t2=SensorData4Save.TData.u16&0x000f;
	sprintf(DisplayString[DisplayRow],RealString,SensorData4Save.Month,SensorData4Save.Day,SensorData4Save.Hour,SensorData4Save.Minute,SensorDataSecond,PickDatas.index,t1,DS18X20_ToDecicel[t2]);
	if(gFlags.bShowLoop)
	{	
		Display_TxHeader();
		Display_UartTx(0x51);
		Display_UartTx(1);
		Display_UartTx(0);
		Display_UartTx(0);	
		Display_UartTx(0);
		Display_UartTx(90);
		for(i=DisplayRow+1;i<14;i++)
		{
			for(j=0;j<30;j++)
			{
				Display_UartTx(DisplayString[i][j]);
			}
// 			y=(i-DisplayRow-1)*21;
// 			y=y+90;
// 			Display_ShowTxt(1,0,y,&DisplayString[i],30);
		}
		//x=10-DisplayRow-1;
		for(i=0;i<DisplayRow+1;i++)
		{
			for(j=0;j<30;j++)
			{
				Display_UartTx(DisplayString[i][j]);
			}
			//y=(x+i)*21;
// 			y=y+90;
// 			Display_ShowTxt(1,0,y,&DisplayString[i],30);
		}
		Display_TxEnder();
	}
	else
	{
		y=DisplayRow<<4;
		y=y+90;
		Display_ShowTxt(1,0,y,&DisplayString[DisplayRow],30);		
	}
	DisplayRow++;
	if(DisplayRow>=14)
	{
		gFlags.bShowLoop=1;
		DisplayRow=0;
	}
// 	if(gFlags.bShowLoop)
// 	{
// 		sprintf(DisplayString[DisplayRow],RealString,0,0,0,0,1,t1,DS18X20_ToDecicel[t2]);
// 		DisplayRow++;
// 		if(DisplayRow>=10)
// 			DisplayRow=0;
// 		len=10-DisplayRow;
// 		y=len<<4;
// 		y=y+90;
// 		len=len*30;
// 		Display_ShowTxt(1,0,90,&DisplayString[DisplayRow],len);
// 
// 		len=300-len;
// 		Display_ShowTxt(1,0,y,&DisplayString[0],len);
// 	}
// 	else
// 	{
// 		sprintf(DisplayString[DisplayRow],RealString,0,0,0,0,1,t1,DS18X20_ToDecicel[t2]);
// 		y=DisplayRow<<4;
// 		y=y+90;
// 		Display_ShowTxt(1,0,y,&DisplayString[DisplayRow],30);
// 		DisplayRow++;
// 		if(DisplayRow>=10)
// 		{
// 			gFlags.bShowLoop=1;
// 			DisplayRow=0;
// 		}
// 	}
}
