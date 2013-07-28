
#line 1 "lcd_main001.c" /0



























 
  
#line 1 "lib_uty001.h" /0










 
 
 void delay(unsigned int delaycount);
#line 29 "lcd_main001.c" /0
 
  
#line 1 "lcd_lib001.h" /0



























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void lcdWriteData(unsigned char dData);
 void lcdWriteString(char *str);
 
 unsigned char lcdSelectDDRAMAddr(unsigned addr);	 
 unsigned char lcdSelectCGRAMAddr(unsigned addr);	 
 
 unsigned char lcdGetCursorAddress(void);
 unsigned char lcdGetCurrentRow(void);
 unsigned char lcdGetCursorCurrentPos(void);
 
 void lcdPutCharAtPos(unsigned char row, unsigned char pos, char c);
 
 void lcdClearRow(unsigned char row);
 void lcdClearCurrentRow(void);
 void lcdClearRestOfRow(unsigned char row);
 void lcdClearRestOfCurrentRow(void);
 
 void lcdCursorReset(void);
 
 void lcdClearScreen(void);
 void lcdSelectRow(unsigned char row);
 void lcdSelectRowPosition(unsigned char row, unsigned char pos);
 void lcdSelectPosition(unsigned char row, unsigned pos);
 
 
 void lcdSetInputShiftOn(void);
 void lcdSetInputShiftOff(void);
 void lcdSetInputInc(void);
 void lcdSetInputDec(void);
 
 void lcdSetDisplay(unsigned char mode);
 void lcdSetDisplayOn(void);
 void lcdSetDisplayOff(void);
 void lcdSetDisplayCursorOn(void);
 void lcdSetDisplayCursorOff(void);
 void lcdSetDisplayCursorBlinkOn(void);
 void lcdSetDisplayCursorBlinkOff(void);
 
 void lcdSetShifting(unsigned char mode);
 void lcdSetShiftingMsg(void);
 void lcdSetShiftingCursor(void);
 void lcdSetShiftingRight(void);
 void lcdSetShiftingLeft(void);
 
 void lcdSetFunction(unsigned char mode);
 void lcdSetFunction2Lines(void);
 void lcdSetFunction1Line(void);
 void lcdSetFunctionFont5x7(void);
 void lcdSetFunctionFont5x10(void);
 







 
 unsigned char lcdMakeRawFont(unsigned char c, unsigned char row0,
 unsigned char row1, 
 unsigned char row2, 
 unsigned char row3, 
 unsigned char row4,
 unsigned char row5,
 unsigned char row6,
 unsigned char row7);
 







 
 unsigned char lcdMakeFont(unsigned char c, char *row);
 void lcdInit(void);							 
 
 void lcdEfxBounce(unsigned char row, char *str, unsigned int speed);
 void lcdEfxRoll(unsigned char row, char *str, unsigned char dir, unsigned int speed);
#line 30 "lcd_main001.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 46 "lcd_main001.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 104 "lcd_main001.c" /0
 
 
 void lcdDemoFlip(void)
 {
 char msgA[]="I Love 8051";
 char msgB[]="Wow is Great!!!";
 
 unsigned char n;
 
 lcdInit();				 
 
 lcdSetDisplay(0x04);
 
 lcdClearScreen();
 lcdSetInputInc();
 lcdSetInputShiftOff();
 
 for (n=0; n<3; n++)
 {
 lcdClearRow(0);
 lcdSelectRow(0);
 lcdWriteString(msgA);
 lcdClearRow(1);
 lcdSelectRow(1);
 lcdWriteString(msgB);
 delay(30000);
 
 lcdClearRow(0);
 lcdSelectRow(0);
 lcdWriteString(msgB);
 lcdClearRow(1);
 lcdSelectRow(1);
 lcdWriteString(msgA);
 delay(30000);
 }
 }  
 
 
 void main(void)
 {
 for (;;)
 {
 
#line 147 "lcd_main001.c" /1
 
 
#line 149 "lcd_main001.c" /0
 
 
 lcdDemoFlip();
 
 }
 }  
 
