/*******************************************************************************
 Title: 	LCD	Display Test
 Ver:		1.1

 Date:		2012-06-30
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

 V1.1			Clean up
 *******************************************************************************/
#include <STC89.H>

#define RS 			P20
#define RW 			P21
#define EN 			P22

#define DELAYCOUNT  5000
#define DELAYSHORT	10

unsigned char lcdCheckBusy(void);
void lcdWaitNotBusy(void);

void lcdWriteCmd(unsigned char cmd);
void lcdWriteData(unsigned char dData);
void lcdWriteString(char *str);

void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString);
void lcdSetDisplay(unsigned char mode);

void lcdClear(void);
void lcdInit(void);

void delay(unsigned int loopCount)
{
	unsigned int t;

	for (t=0; t<loopCount; t++);

} /* delay */

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
	
void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString)
{
	unsigned char mode;
	unsigned char cmd;

	mode = (shiftCursor << 1)|(shiftString);
	cmd = 0x04|mode;

	lcdWriteCmd(cmd);

} /* lcdSetInputMode */

void lcdSetDisplay(unsigned char mode)
{
	if (mode == 1)
	{
		lcdWriteCmd(0x0F);
	}
	else
	{
		lcdWriteCmd(0x80);
	}

} /* lcdSetDisplay */

void lcdClear(void)
{
	lcdWriteCmd(1);
} /* lcdClear */ 

void lcdInit(void)
{
	lcdClear();
	lcdSetDisplay(1);
	lcdWriteCmd(0x38);
} /* lcdClear */ 

void main(void)
{
	lcdInit();

	lcdSetInputMode(1,0);
	lcdWriteString("April Sin is a good girl");

	for (;;);

} /* main */


