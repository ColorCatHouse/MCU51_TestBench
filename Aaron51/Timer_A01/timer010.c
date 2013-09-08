/***************************************************************************
Title:		7-Segment LED Test

Ver:		2.00

Data:		2013-9-8
By:			Aaron

Hardware:	RichMCU RZ-51V2.0 Development Board
			X'tal:	11.0592

Connection:	

Jumpers:
****************************************************************************/
#include <STC89.H>

int isrTimerCnt;		

void delay()
{
	unsigned int i;

	for (i=0; i<15000; i++);

} /* delay */

void test01()
{
	int x=0;

	P2=0xf7;

	for(;;)
	{
 		P0 = ~0x6d;
		delay();
	}

} /* test01 */

void main()
{
	isrTimerCnt = 0;
		
	EA  = 0;			//Disable All interrupt

	TMOD = T0_M1;		//Set Timer to Mode 1

	TR0 = 0;			//Disable Timer0

	TH0 = (65536 - 50000) >> 8;		//50,000 timer count
	TL0 = (65536 - 50000) & 0xff;	//50,000 timer count low byter 	
	
	ET0 = 1;			//Enable Timer0 interrupt
	EA  = 1;			//Enable All interrupt 

	P1 = 0xaa;

	TR0 = 1;			//Start Timer 
	
	P0 = ~0x6d;

	for(;;)
	{
 		P2=0xfE;
		delay();
		P2=0xfD;
		delay();
		P2=0xfB;
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
	TR0 = 0;			// Stop Timer0

	isrTimerCnt++;

	if (isrTimerCnt >= 10)
	{
		P1 =  ~P1;
		isrTimerCnt=0;
	}

	TH0 = (65536 - 50000) >> 8;		//50,000 timer count high byte
	TL0 = (65536 - 50000) & 0xff;	//50,000 timer count low byte

	TR0 = 1;			// Start Timer0

}/* isrTimer0 */
