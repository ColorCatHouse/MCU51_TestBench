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

	EX0 = 1;			// Turn on Interrupt 0 (INT0 Pin-12)
	EX1 = 1;			// Turn on Interrupt 2 (INT1 Pin-13)
	EA  = 1;		   	// Turn on the main Interrupt switch

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
	}
}

void isrBeep(void) interrupt 0
{
	P3=0xEF;		// Turn on the Beeper
	delay();
	P3=0xFF;			// Turn off the Beeper
}

void isrBeep2(void) interrupt 2
{
	P3=0xEF;
	delay();
	P3=0xFF;
	delay();
	P3=0xEF;
	delay();
	P3=0xFF;
}