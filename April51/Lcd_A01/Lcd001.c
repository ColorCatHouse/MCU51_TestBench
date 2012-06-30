/*******************************************************************************
 Title: 	LCD	Display Test
 Ver:		1.0

 Date:		2012-06-30
 By:		April

 Hardware:	RichMCU RZ-51 Development Board
			X'tal: 11.0592MHz
 *******************************************************************************/
#include <STC89.H>

#define RS 			P20
#define RW 			P21
#define EN 			P22

#define DELAYCOUNT  5000
#define DELAYSHORT	10

void lcdWriteCmd(unsigned char cmd);
unsigned char lcdCheckBusy(void);
void lcdWaitNotBusy(void);
void lcdSetDisplay(unsigned char mode);

void delay(unsigned int loopCount)
{
	unsigned int t;

	for (t=0; t<loopCount; t++);
} /* delay */

void lcdWriteCmd(unsigned char cmd)
{
	P0 = 0;
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

void lcdClear(void)
{
	lcdWriteCmd(1);
} /* lcdClear */ 

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

void lcdInit(void)
{
	lcdClear();
	lcdSetDisplay(1);
	lcdWriteCmd(0x38);
} /* lcdClear */ 

void lcdSetInputMode(unsigned char shiftCursor, unsigned char shiftString)
{
	unsigned char mode;
	unsigned char cmd;

	mode = (shiftCursor << 1)|(shiftString);
	cmd = 0x04|mode;

	lcdWriteCmd(cmd);

} /* lcdSetInputMode */


void lcdWriteString(char *str)
{
	char *s;

	for(s=str; *s!= 0; s++)
	{
		lcdWriteData(*s);
	}
} /* lcdWriteString */

void main(void)
{
	lcdInit();

	lcdSetInputMode(1,0);
//	lcdWriteData('A');
//	lcdWriteData('p');
//	lcdWriteData('r');
	lcdWriteString("April Sin is a good girl");

	for (;;);

} /* main */


