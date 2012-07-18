/*******************************************************************************
 File:			lcd_lib06.h

 Title: 		LCD Driver library
 Ver:			3.0	Alpha

 Date:			2012-07-14
 By:			Aaron

 Hardware:		RichMCU RZ-51V2.0 Development Board
				X'tal: 11.0592MHz

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				DATAPORT - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���

 *******************************************************************************/
#define		LCD_MAX_LENGTH					40
#define		LCD_ADDR_ROW0					0x00
#define		LCD_ADDR_ROW1					0x40
#define		LCD_CGRAM_ADDR					0x00
#define		LCD_USRCHR_SIZE					8 			//Size of per character
#define		LCD_USRCHR_SIZE					8			//total number of user def ined character

#define		LCD_WINDOW_LENGTH				16
#define  	LCD_WIDOW_ROW					2