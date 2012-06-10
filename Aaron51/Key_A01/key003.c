#include <STC89.H>

void delay(void)
{
	int t;
	
	for (t=0; t<20000; t++);
}
				
void main(void)
{
	unsigned char ptn;
	unsigned char n;

	P2=0xFF;			// Ready to check key pressed
	for (;;)
	{
		ptn=1;
		for (n=0; n<8; n++)			// LED loop
		{
			P0 = ~(ptn << n);
			delay();
			delay();
			delay();
		}
		
		if (P2==0xFE)
		{
			P3=0xEF;		// Turn on the Beeper
		}
		else
		{
			P3=0xFF;		// Turn off the Beeper
		}
	}
}