/*******************************************************************************
 File: 			lcd_lib06.h
 Title:			LCD Driver Library Header
 Ver:			3.0

 Date:			2012-07-16
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
#define		LCD_MODE_INPUT_INC					0x02
#define		LCD_MODE_INPUT_SHIFT_ON				0x01

#define		LCD_MODE_DISPLAY_ON					0x04
#define		LCD_MODE_DISPLAY_CURSOR_ON			0x02
#define 	LCD_MODE_DISPLAY_CURSOR_BLINK_ON	0x01

#define		LCD_MODE_SHIFT_MSG					0x08
#define		LCD_MODE_SHIFT_RIGHT				0x04

#define		LCD_MODE_FUNCTION_DL8				0x10
#define		LCD_MODE_FUNCTION_2LINES			0x08
#define		LCD_MODE_FUNCTION_FONT5X10			0x04

// unsigned char lcdCheckBusy(void)
// void lcdWaitNotBusy(void);

//void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

//addr: 0x00 - 0x27, 0x40 - 0x67
void lcdSelectDDRAMaddr(unsigned char addr);
void lcdSelectCGRAMaddr(unsigned char addr);

unsigned char lcdGetCursorPos(void);
void lcdPutCharAtPos(unsigned char row, unsigned char pos, char c);

// Clear LCD Screen
void lcdClear(void);
void lcdCursorReset(void);

void lcdClearRow(unsigned char row);
void lcdClearCurrentRow(void);
void lcdClearRestOfRow(unsigned char row);
void lcdClearRestOfCurrentRow(void);

// row: 0, 1
void lcdSelectRow(unsigned char row);
void lcdSelectRowPosition(unsigned char row, unsigned char pos);
void lcdSelectPosition(unsigned char pos);

void lcdSetInput(unsigned char mode);
void lcdSetInputInc(void);
void lcdSetInputDec(void);
void lcdSetInputShiftOn(void);
void lcdSetInputShiftOff(void);

void lcdSetDisplay(unsigned char mode);
void lcdSetDisplayOn(void);
void lcdSetDisplayOff(void);
void lcdSetDisplayOn(void);
void lcdSetDisplayOff(void);
void lcdSetDisplayOn(void);
void lcdSetDisplayOff(void);


void lcdSetShifting(unsigned char mode);
void lcdSetShifting(unsigned char mode);
void lcdSetShifting(unsigned char mode);

void lcdSetFunction(unsigned char mode);
void lcdSetFunction(unsigned char mode);
void lcdSetFunction(unsigned char mode);



/*******************************************************
 lcdInit()

 Clear LCD Screen, Display ON, Cursor ON, Blinking ON
 Use 8-bit, 2 Lines, Font 5x7
 *******************************************************/
void lcdInit(void);



