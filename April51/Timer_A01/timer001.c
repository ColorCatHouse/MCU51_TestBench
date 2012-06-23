#include <STC89.H>				  

unsigned char pattern;

void main(void)
{
	TH0=0;
	TL0=0;

	TMOD=T0_M1;
	
	ET0=1;
	EA=1;

	TR0=1;

	for (;;)
	{
		P0=~pattern;
	}
}

void isrTimer(void) interrupt 1
{
	pattern++;

	TH0=0;
	TL0=0;
}