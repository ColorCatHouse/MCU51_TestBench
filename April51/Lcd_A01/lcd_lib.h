/*******************************************************************************
 Title: 	lcd_lib.h
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

				将 JPSMG 数码管控制跳线拔掉使数码管停止工作。
 				将 JPP0 跳线端的跳线帽拔掉以免干扰1602 液晶显示
				插上1602LCD液晶
				将 JPBG 液晶背光跳线插上

 *******************************************************************************/
#define RS 			P20
#define RW 			P21
#define EN 			P22

void lcdWaitNotBusy(void);

void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString);
void lcdSetDisplay(unsigned char mode);


// Clear LCD Screen
void lcdClear(void);

// Clear LCD Screen, Display ON, Cursor ON, Blinking ON,
void lcdInit(void);



