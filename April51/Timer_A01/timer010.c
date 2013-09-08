/*******************************************************************************
 File:			digit_001.c
 Title: 		7-Segment LED Test
 Ver:			2.0

 Date:			2013-09-08
 By:			April

 Hardware:		RichMCU RZ-51V2.0 Development Board
				X'tal: 11.0592MHz

 Connection:	

 Jumpers:		
 *******************************************************************************/
#include "STC89.H"

int isrTimer0Cnt;

void delay()
{
	unsigned int i;

	for (i=0; i<10000; i++);

} /* delay */

void test01()
{
	int x=0;
	P2=0xf7;

	for	(;;)
	{
		P0=x++;
		delay();
	}

} /* test01 */

void main()
{
	isrTimer0Cnt = 0;  	//isrTimer0 interrupt calling counter

	EA = 0;				//Disable all inerrupts

	TMOD = T0_M1;		//Set Timer0 to Mode 1

	TR0 =  0;			//Disable Timer0

	TH0=(65536-50000) >> 8;  	//50,000 timer counts
	TL0=(65536-50000) & 0xff; 	//50,000 timer counts

	ET0 = 1; 			//Enable Timer0 Interrupt
	EA  = 1;			//Enable all interrupts

	P1 = 0x55;			/All LEDs ON

	TR0 = 1;			//Start Timer0

	P0=~0x77;

	for(;;)
	{
		P2=0xfe;
		delay();

		P2=0xfd;
		delay();

		P2=0xfb;
		delay();

		P2=0xf7;
		delay();

		P2=0xef;
	    delay();

		P2=0xdf;
		delay();

		P2=0xbf;
		delay();

		P2=0x7f;
		delay();
	}		
} /* main */

void isrTimer0(void) interrupt 1 using 2
{
	isrTimer0Cnt++;

	if(isrTimer0Cnt >= 10)
	{
		P1 = ~P1;
		isrTimerCnt=0;
	}

 	TR0 = 0;		//Disable Timer0
	
	TH0=(65536-50000) >> 8;		//50,000 timer counts
	TL0=(65536-50000) & 0xff;	//50,000 timer counts
	
	TR0 = 1;		//Enable Timer0 again	

} /* isrTimer0 */