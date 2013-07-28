/***************************************************************************
Title:		7-Segment LED Test

Ver:		1.00

Data:		2013-7-28
By:			Aaron

Hardware:	RichMCU RZ-51V2.0 Development Board
			X'tal:	11.0592

Connection:	

Jumpers:
****************************************************************************/
#include <STC89.H>

void delay()
{
	unsigned int i;

	for (i=0; i<10000; i++);

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
