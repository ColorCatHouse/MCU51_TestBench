/*******************************************************************************
 Title: 		LCD	Driver Library
 Ver:			2.0

 Date:			2012-07-14
 By:			Michael

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
#include "lcd_hardware.h"
#include "lcd_lib05.h"
#include "lib_uty.h"

#define DELAYSHORT	10

unsigned char lcdCheckBusy(void)
{
	unsigned char busyFlag;

	BF = 1;						// Set BF pin to high and ready for input
	EN = 0;
		
	RS = 0;
	RW = 1;
	EN = 1;
	delay(DELAYSHORT);
	busyFlag = BF;
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

	EN = 0;
	RS = 0;				// Select Command mode
	RW = 0;				// Set to Write

	PORT_LCD = cmd;		// Send command to LCD module
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;
	RW = 1;
	RS = 1;

} /* lcdWriteCmd */

void lcdWriteData(unsigned char dData)
{
	lcdWaitNotBusy();

	EN = 0;
	RS = 1;				// Select Data mode
	RW = 0;				// Set to Write
	PORT_LCD = dData;	// Send data to LCD module
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

void lcdSetInput(unsigned char mode)
{
	lcdWriteCmd(0x04 | mode);

} /* lcdSetInput */

void lcdSetDisplay(unsigned char mode)
{
	lcdWriteCmd(0x08 | mode);

} /* lcdSetDisplay */

void lcdSetShifting(unsigned char mode)
{
	lcdWriteCmd(0x10 | mode);

} /* lcdSetShifting */

void lcdSetFunction(unsigned char mode)
{
	lcdWriteCmd(0x20 | mode);

} /* lcdSetFuncction */

void lcdClear(void)
{
	lcdWriteCmd(1);		  	// Clear LCD Screen, AC=0
} /* lcdClear */ 

void lcdInit(void)
{
	lcdClear();				// Clear LCD Screen

	lcdSetFunction(LCD_MODE_FUNCTION_DL8     |
				   LCD_MODE_FUNCTION_2LINES  |
				   LCD_MODE_FUNCTION_FONT5X7);

	lcdSetDisplay(LCD_MODE_DISPLAY_ON              |
				  LCD_MODE_DISPLAY_CURSOR_ON       |
				  LCD_MODE_DISPLAY_CURSOR_BLINK_ON);

} /* lcdClear */ 

void lcdSelectRow(unsigned char row) 	// row:0, 1
{					
	if (row == 0)
	{
		lcdWriteCmd(0x80 | 0x00);		// Select address 0, 1st Row
	}
	else
	{
		lcdWriteCmd(0x80 | 0x40);		// Select address 0x40, 2nd row and beyond
	}

} /* lcdSelectRow */

void lcdClearRow(unsigned char row)		// row:0, 1
{	
	unsigned int n;

	lcdSelectRow(row);

	for (n=0; n<40; n++) 					// Fill row with SPACEs
	{
		lcdWriteCmd(0x80 | (row*0x40+n));	// Use fill memory is better than auto INC/DEC input mode
		lcdWriteData(' ');
	}

	lcdSelectRow(row);						// CR: Move cursor to beginning of line [Carriage Return]					

} /* lcdClearRow */