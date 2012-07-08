/*******************************************************************************
 Title: 	LCD	Display Test
 Ver:		1.0

 Date:			2012-07-08
 By:			April

 Hardware:		RichMCU RZ-51V2.0 Development Board
				X'tal: 11.0592MHz

 Connection:	LCD pins as below -
 				RS - P20
				RW - P21
				EN - P22
				PORT_LCD - P0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs
 				Remove JPP0  - Disable LEDs
				Add JPBG     - Enable LCD Back Light

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
 				�� JPP0 ���߶˵�����ñ�ε��������1602 Һ����ʾ
				����1602LCDҺ��
				�� JPBG Һ���������߲���
 *******************************************************************************/
#include <STC89.H>
#include "lcd_lib.h"
#include "lib_uty.h"

 void main (void)
 {
 	lcdInit();								// Clear Screen, Display ON, Cursor ON, Blinking ON
											// Use 8-bit, 2 Lines, Font 5x7

	lcdSetInputMode(1,0);					// Cursor INC, No Shift

	for(;;)
	{
		lcdClearRow(0);
		lcdSelectRow(0);
		lcdWriteString("April is a girl");
	
		lcdClearRow(1);
		lcdSelectRow(1);
		lcdWriteString("Ha! Ha!");
	
		delay(50000);
		
		lcdClearRow(0);
		lcdSelectRow(0);
		lcdWriteString("Ha! Ha!");
	
		lcdClearRow(1);
		lcdSelectRow(1);
		lcdWriteString("April is a girl");
		
		delay(50000);
	}
 } /* main */

