#include <STC89.H>

unsigned char mode;

void delay(void)
{
	unsigned int t;
	for(t=0;t<20000;t++);
}

void main(void)
{
	unsigned char n;

	mode=0;

	n=0;

	EX0=1;						// Enable INT0
   	EA =1;						// Enable all interrupts

	for(;;)
	{
		if(mode==0)
		{
			P0=~(n++);
			delay();
		}
		else
		{
			P0=~(n--);
			delay();
		}
	}
}

void isrChangeMode(void) interrupt 0
{
	if (mode == 0)
	{
		mode = 1;
	}
	else
	{
		mode = 0;
	}
}
	