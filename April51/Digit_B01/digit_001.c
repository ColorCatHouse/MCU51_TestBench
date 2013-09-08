/*******************************************************************************
 File:			digit_001.c
 Title: 		7-Segment LED Test
 Ver:			1.0

 Date:			2013-07-28
 By:			April

 Hardware:		RichMCU RZ-51V2.0 Development Board
				X'tal: 11.0592MHz

 Connection:	

 Jumpers:		
 *******************************************************************************/
#include <STC89.H>

void delay()
{
	int i;

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
}