#include <STC89.H>

#define	DELAY_TIME	65536

unsigned char pattern;

void main(void)
{
	TH0=(65536 - DELAY_TIME) / 256;
	TL0=(65536 - DELAY_TIME) % 256;

	ET0=1; 			// Enable timer0 interrupt 1
	EA =1;			// Enable all interrrupts

	TR0=1;			// Turn on the timer

	pattern = 0;
	for (;;)
	{
		P0=~pattern;
	}
}

void timer0(void) interrupt 1
{
	pattern++;

	TH0=(65536 - DELAY_TIME) / 256;
	TL0=(65536 - DELAY_TIME) % 256;
}
