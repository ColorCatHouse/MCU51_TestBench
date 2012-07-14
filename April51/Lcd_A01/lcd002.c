/*******************************************************************************
 Title: 	LCD	Display Test
 Ver:		1.0

 Date:			2012-07-07
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
#include "lib_uty.h"
#include "lcd_lib.h"

void main(void)
{
	lcdInit();								// Clear Screen, Display ON, Cursor ON, Blinking ON
											// Use 8-bit, 2 Lines, Font 5x7

	lcdSetInputMode(1,0);					// Cursor INC, No Shift

	lcdWriteString("April is a girl");

	lcdSelectRow(1);
	lcdWriteString("Ha! Ha!");

	for (;;);

} /* main */

