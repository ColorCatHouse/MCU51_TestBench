#include <STC89.H>

#define	DELAY_TIME	2000		// Set timer to 1000us (1ms)

unsigned int	wakeupcount;
unsigned char 	pattern;

void main(void)
{
	TH0=(65536 - DELAY_TIME) >> 8;
	TL0=(65536 - DELAY_TIME) % 256;

	ET0=1; 			// Enable timer0 interrupt 1
	EA =1;			// Enable all interrrupts

	TR0=1;			// Turn on the timer

	wakeupcount=0;
	pattern = 0;
	for (;;)
	{
		P0=~pattern;
	}
}

void timer0(void) interrupt 1
{
	wakeupcount++;

	if (wakeupcount >= 1000)			// After 1 second, change pattern
	{
		pattern++;
		wakeupcount = 0;
	}

	TH0=(65536 - DELAY_TIME) / 256;
	TL0=(65536 - DELAY_TIME) % 256;
}
