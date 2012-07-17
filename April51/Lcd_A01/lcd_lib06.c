/*******************************************************************************
 File:			lcd_lib06.c
 Title: 		LCD	Driver Library
 Version:		3.0 alpha

 Date:			2012-07-17
 By:			April

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
#include "lcd_lib06.h"
#include "lib_uty.h"

#define DELAYSHORT	10

unsigned char lcdCurrentModeInput;
unsigned char lcdCurrentModeDisplay;
unsigned char lcdCurrentModeShifting;
unsigned char lcdCurrentModeFunction;

unsigned char lcdCurrentRow;

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

void lcdReadData(unsigned char dData)
{
	lcdWaitNotBusy();

	EN = 0;
	RS = 1;
	RW = 1;
	PORT_LCD = dData;
	EN = 1;
	delay(DELAYSHORT);
	EN = 0;

} /* lcdReadData */

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
	lcdCurrentModeInput = mode;
		
	lcdWriteCmd(0x04 | mode);

} /* lcdSetInput */

void lcdSetInputInc(void)
{
	lcdCurrentModeInput |= LCD_MODE_INPUT_INC;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputInc */

void lcdSetInputDec(void)
{
	lcdCurrentModeInput &= ~LCD_MODE_INPUT_INC;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputDec */

void lcdSetInputShiftOn(void)
{
	lcdCurrentModeInput |= LCD_MODE_INPUT_SHIFT_ON;

	lcdWriteCmd(0x04 | LCD_MODE_INPUT_SHIFT_ON | lcdCurrentModeInput);

} /* lcdSetInputShiftOn*/

void lcdSetInputShiftOff(void)
{
	lcdCurrentModeInput &= ~LCD_MODE_INPUT_SHIFT_ON;

	lcdWriteCmd(0x04 | lcdCurrentModeInput);

} /* lcdSetInputShiftOff */

void lcdSetDisplayOn(void)
{
	lcdCurrentModeDisplay |= LCD_MODE_DISPLAY_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayOn */

void lcdSetDisplayOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_MODE_DISPLAY_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayOff */

void lcdSetDisplayCursorOn(void)
{
	lcdCurrentModeDisplay |= LCD_MODE_DISPLAY_CURSOR_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayCursorOn */

void lcdSetDisplayCursorOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_MODE_DISPLAY_CURSOR_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayCursorOff */														   

void lcdSetDisplayCursorBlinkOn(void)
{
	lcdCurrentModeDisplay |= LCD_MODE_DISPLAY_CURSOR_BLINK_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayCursorBlinkOn */

void lcdSetDisplayCursorBlinkOff(void)
{
	lcdCurrentModeDisplay &= ~LCD_MODE_DISPLAY_CURSOR_BLINK_ON;

	lcdWriteCmd(0x08 | lcdCurrentModeDisplay);

} /* lcdSetDisplayCursorBlinkOff */

void lcdModeShiftMsg(void)
{
	lcdCurrentModeShifting |= LCD_MODE_SHIFT_MSG;

	lcdWriteCmd(0x08 | lcdCurrentModeShifting);

} /* lcdModeShiftMsg */
				
void lcdModeShiftCursor(void)
{
	lcdCurrentModeShifting &= ~LCD_MODE_SHIFT_MSG;

	lcdWriteCmd(0x08 | lcdCurrentModeShifting);

} /* lcdModeShiftCursor */
			
void lcdModeShiftRight(void)
{
	lcdCurrentModeShifting |= LCD_MODE_SHIFT_RIGHT;

	lcdWriteCmd(0x08 | lcdCurrentModeShifting);

} /* lcdModeShiftRight */
	
void lcdModeShiftLeft(void)
{
	lcdCurrentModeShifting &= ~LCD_MODE_SHIFT_RIGHT;

	lcdWriteCmd(0x08 | lcdCurrentModeShifting);

} /* lcdModeShiftLeft */
		

void lcdModeFunctionDL8(void)
{
	lcdCurrentModeFunction |= LCD_MODE_FUNCTION_DL8;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunctionDL8 */
			
void lcdModeFunctionDL4(void)
{
	lcdCurrentModeFunction &= ~LCD_MODE_FUNCTION_DL8;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunctionDL4 */

void lcdModeFunction2Lines(void)
{
	lcdCurrentModeFunction |= LCD_MODE_FUNCTION_2LINES;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunction2Lines */

void lcdModeFunction1Line(void)
{
	lcdCurrentModeFunction &= ~LCD_MODE_FUNCTION_2LINES;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunction1Line */

void lcdModeFunctionFont5X10(void)
{
	lcdCurrentModeFunction |= LCD_MODE_FUNCTION_FONT5X10;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunctionFont5X10 */

void lcdModeFunctionFont5X7(void)
{
	lcdCurrentModeFunction &= ~LCD_MODE_FUNCTION_FONT5X10;

	lcdWriteCmd(0x08 | lcdCurrentModeFunction);

} /* lcdModeFunctionFont5X7 */

void lcdSetShifting(unsigned char mode)
{
	lcdWriteCmd(0x10 | mode);

} /* lcdSetShifting */

void lcdSetFunction(unsigned char mode)	
{
	lcdWriteCmd(0x20 | mode);

} /* lcdSetFunction */

void lcdClear(void)
{
	lcdWriteCmd(1);		  	// Clear LCD Screen, AC=0

} /* lcdClear */ 

void lcdInit(void)
{
	lcdClear();				// Clear LCD Screen

	lcdSetFunction(LCD_MODE_FUNCTION_DL8    |
				   LCD_MODE_FUNCTION_2LINES);

	lcdSetDisplay(LCD_MODE_DISPLAY_ON 		 	   |
				  LCD_MODE_DISPLAY_CURSOR_ON 	   |
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

void lcdSelectRowPosition(unsigned char row, unsigned char pos)
{
	lcdSelectRow(row);
	lcdWriteCmd(0x80 | pos);

} /* lcdSelectRowPosition */

void lcdSelectDDRAMAddr(unsigned addr)
{
	lcdWriteCmd(0x80 | addr);		    	//Select address addr

} /* lcdSelectDDRAMAddr */

											
void lcdClearRow(unsigned char row)			// row:0, 1
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

void lcdClearCurrentRow(void)
{
	lcdCurrentRow = 
	lcdClearRow(lcdCurrentRow);
	
} /* lcdClearCurrentRow */

void lcdClearRestOfRow(unsigned char row)
{
	unsigned char n;

   	lcdSelectRow(row);
	
	for(n=dData; n!=0; n++)
	{
		lcdSelectPosition(n);
		lcdClearPosition();
	}
} /* lcdClearRestofRow */

void lcdClearRestOfCurrentRow(void)
{
	unsigned char n;

	lcdCurrentRow = 
	lcdSelectRow(lcdCurrentRow);

	for(n=dData; n!=0; n++)
	{
		lcdClearPosition(n);
	}
} /* lcdClearRestofCurrentRow */




