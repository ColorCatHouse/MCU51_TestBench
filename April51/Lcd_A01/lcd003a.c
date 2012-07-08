/*******************************************************************************
 Title: 	LCD	Display Test
 Ver:		1.1

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

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上
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
		lcdWriteString("April is a girl");
		lcdClearRow(1);
		lcdWriteString("Ha! Ha!");
		delay(50000);
		
		lcdClearRow(0);
		lcdWriteString("Ha! Ha!");	
		lcdClearRow(1);
		lcdWriteString("April is a girl");	
		delay(50000);
	}
 } /* main */

