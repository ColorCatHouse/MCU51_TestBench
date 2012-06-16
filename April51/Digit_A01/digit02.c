#include <STC89.H>

void delay(void)
{ 	
	unsigned int t;

	for(t=0;t<20000;t++);
}

void main(void)
{
	for(;;)
	{
		P0=0x83;
		P1=0xe;
		delay();
	
		P1=0xd;
		delay();
	
		P1=0xb;
		delay();
		
		P1=0x7;
		delay();	
	}
}


		