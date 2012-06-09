#include <STC89.H>


void delay(void)
{
	unsigned int t;
	for(t=0; t< 800; t++);
}

void main(void)
{
	unsigned char hex[]={0x3F, 0x06, 0x5B, 0x4F, 0x66};

	for(;;)
	{
		P1=0xFF;
		P0=~hex[0];
		delay();
		P1=0xFE;
		delay();

		P1=0xFF;		
		P0=~hex[1];
		delay();
		P1=0xFD;
		delay();

		P1=0xFF;
		P0=~hex[2];
		delay();
		P1=0xFB;
		delay();

		P1=0xFF;
		P0=~hex[3];
		delay();
		P1=0xF7;
		delay();
	}
}
