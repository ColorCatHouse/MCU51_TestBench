/*******************************************************************************
 Title: 	LCD	Driver Library
 Ver:		1.0

 Date:		2012-07-07
 By:		April

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

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上

 *******************************************************************************/
#include <STC89.H>
#include "lcd_lib.h"
#include "lib_uty.h"

#define DELAYSHORT	10

unsigned char lcdCheckBusy(void)
{
	unsigned char busyFlag;

	RS = 0;
	RW = 1;
	EN = 1;
	delay(DELAYSHORT);
	busyFlag = P07;
	EN = 0;
	RS = 1;

	return busyFlag;

} /* lcdCheckBusy */

void lcdWaitNotBusy(void)
{
	while(lcdCheckBusy() == 1);

} /* lcdWaitNotBusy */

void lcdWriteCmd(unsigned char cmd)
{
	lcdWaitNotBusy();

	RS = 0;
	RW = 0;
	EN = 0;
	P0 = cmd;
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
	RW = 1;
	RS = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	P0 = 0;
	lcdWaitNotBusy();
	RS = 1;
	RW = 0;
	P0 = dData;
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
	RW = 1;

} /* lcdWriteData */

void lcdWriteString(char *str)
{
	char *s;

	for(s=str; *s!= 0; s++)
	{
		lcdWriteData(*s);
	}
} /* lcdWriteString */

// shiftCursor-> I/D -> 1:Inc, 0:Dec
// shiftString-> S   -> 1:Shift ON, 0:Shift Off	
void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString)
{
	unsigned char mode;
	unsigned char cmd;

	mode = (shiftCursor << 1)|(shiftString);
	cmd = 0x04|mode;

	lcdWriteCmd(cmd);

} /* lcdSetInputMode */

void lcdSetDisplay(unsigned char mode)		// 1:Display ON, Cursor ON, Blinking ON
{
	if (mode == 0) 							// 0: Display OFF
	{
		lcdWriteCmd(0x80);
	}
	else
	{
		lcdWriteCmd(0x0f);				 	// DISPLAY ON, Cursor ON, Blinking ON
	}

} /* lcdSetDisplay */

void lcdClear(void)
{
	lcdWriteCmd(1);		  	// Clear LCD Screen, AC=0
} /* lcdClear */ 

void lcdInit(void)
{
	lcdClear();				// Clear LCD Screen
	lcdSetDisplay(1);		// Display ON, Cursor ON, Blinking ON
	lcdWriteCmd(0x38);		// Use 8-bit, 2 Lines, Font 5x7
} /* lcdClear */ 


