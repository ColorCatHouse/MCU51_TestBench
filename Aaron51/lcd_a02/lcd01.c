/***************************************************************************
Title:		LCD Test

Ver:		1.0
Data:		2012-7-16
By:			Aaron

Hardware:	RichMCU RZ-51V2.0 Development Board
			X'tal:	11.0592

Connection:	LCD pins as below -
			RS - P20
			RW - P21
			EN - P22
			DATAPORT - P0

Jumpers:	Remove JPSMG - Disable 7-Segment LEDs
			Remove JPP0  - Disable LEDs
			Add JPBG	 - Enable LCD Back Light
****************************************************************************/
#include <STC89.H>

#define	LCD_DATA		P0
#define	RS				P20
#define	RW				P21
#define	EN				P22
#define BF				P07

void delay(void)
{
	unsigned int a;

	for(a=0; a<1000; a++);

} /* delay */

unsigned char lcdCheckBusy(void)
{
	RS=0;
	RW=1;
	EN=1;
	delay();
	BF=P07;
	EN=0;

	return BF;

} /* lcdCheckBusy */

void lcdWaitUntilNotBusy(void)
{
	while(lcdCheckBusy()==1);

} /* lcdWaitUntilNotBusy */

void lcdWriteCMD(unsigned char cmd)
{
	lcdWaitUntilNotBusy();

	RS=0;
	RW=0;
	LCD_DATA=cmd;
	EN=1;
	delay();
	EN=0;
	RW=1;

} /* lcdWriteCMD */

void lcdWriteData(unsigned char dData)
{
	lcdWaitUntilNotBusy();

	RS=1;
	RW=0;
	LCD_DATA=dData;
	EN=1;
	delay();
	EN=0;
	RW=1;

} /* lcdWriteData */

void main(void)
{
	lcdWriteCMD(0x01);						//Clear Screen
	lcdWriteCMD(0x02);
	lcdWriteCMD(0xF);						
	lcdWriteCMD(0x6);
	
	lcdWriteData('A');
	lcdWriteData('a');
	lcdWriteData('r');
	lcdWriteData('o');
	lcdWriteData('n');

	for(;;);

} /* main */