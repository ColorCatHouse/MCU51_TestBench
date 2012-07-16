/*******************************************************************************
 File:			lcd006.c

 Title: 		LCD	Display Test
 Ver:			2.0

 Date:			2012-07-14
 By:			Aaron

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
#include "lib_uty.h"
#include "lcd_lib06.h"

void main (void)
{
	unsigned char n;

	lcdInit();							// Clear Screen, Display ON, Cursor ON, Blinking ON
										// Use 8-bit, 2 Lines, Font 5x7

	lcdSetInput(LCD_INPUT_INC);			// Input mode: INC, No Shift
	
	for (;;)
	{
		for(n=0; n<0xf; n++)
		{
			lcdClearRow(0);
			lcdWriteCmd(0x80 | n);

			lcdWriteString("April");
			delay(10000);
		}
	}

} /* main */