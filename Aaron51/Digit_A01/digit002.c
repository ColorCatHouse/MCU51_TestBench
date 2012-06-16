#include <STC89.H>

void delay(void)
{
	unsigned int t;
	
	for(t=0;t<20000;t++);
}

void main(void)
{
	P0=0x92;

	for (;;)
	{
		P1=0xE;	  
		delay();

		P1=0xD;
		delay();

		P1=0xB;
		delay();

		P1=0x7;
		delay();
	}
}