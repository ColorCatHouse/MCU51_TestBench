/*******************************************************************************
 Title: 	lcd_hardware.h
 Ver:		1.0

 Date:		2012-07-07
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