/*******************************************************************************
 Title: 	lcd_hardware.h
 Ver:		2.0

 Date:		2012-07-18
 By:		April

 Hardware:	RichMCU RZ-51V2.0 Development Board
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
#define RS 			P20
#define RW 			P21
#define EN 			P22
#define	BF			P07
#define	PORT_LCD	P0

#define LCD_MAX_LENGTH							40
#define LCD_ADDR_ROW1							0x00
#define LCD_ADDR_ROW2							0x40
#define LCD_CGRAM_ADDR							0x00
#define LCD_USRCHR_SIZE							8					//Size of per character
#define LCD_USRCHR_FONT							8		 			//Total Number of user defined characters

#define LCD_WINDOW_LENGTH						16
#define LCD_WINDOW_ROWS							2
