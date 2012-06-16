#include <STC89.H>

void delay(void)
{
	unsigned int t;
	
	for(t=0;t<1000;t++);
}

void main(void)
{

	for (;;)
	{
		P0=0xF9;
		P1=0xE;	  
		delay();

		P0=0xA4;
		P1=0xD;
		delay();

		P0=0xB0;
		P1=0xB;
		delay();

		P0=0x99;
		P1=0x7;
		delay();
	}
}