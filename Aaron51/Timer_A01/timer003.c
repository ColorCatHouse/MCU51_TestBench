/**********************************************
 Title: 	1 sec interval timer
 Ver:		1.0

 Date:		2012-06-23
 By:		Aaron

 Hardware:	XT-100 8x51 Develoment Board
 			X'tal:	11.0592MHz
			Timer click = 1/(11.0592/12) = 1.085069uS = 0x000 001 085069s
			Total clicks for 1sec = 1/0.000 001 085069 = 921600 = 9216 x 100

Connection:	P0 -> LEDs (0:ON 1:Off)
 **********************************************/
#include <STC89.H>

unsigned char n=0;
unsigned char timerCount=0;

void main(void)
{
	TMOD=T0_M1;		//Set timer0 to Mode-1 (16-bit timer)
								
	TL0 = (65536 - 9216) % 256;
	TH0 = (65536 - 9216) / 256;

	ET0 = 1;		// Enable Timer0 interrupt
	EA  = 1;		// Enable all interrupts

	TR0 = 1;			// Timer start now

	for(;;)
	{
		P0=~n;
	}
}

void isrTimer0(void) interrupt 1
{
	timerCount++;

	if (timerCount >= 100)
	{
		timerCount=0;
		n++;
	}
	
	TL0 = (65536 - 9216) % 256;		// Restart Timer0
	TH0 = (65536 - 9216) / 256;


}