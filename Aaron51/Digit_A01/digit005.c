#include <STC89.H>

void delay(void)
{
	unsigned int t;
	
	for(t=0;t<1000;t++);
}

void main(void)
{
	unsigned char hex[16]={0x3F, 0x06, 0x5B, 0x4F,
						 0x66, 0x6D, 0x7D, 0x07,
						 0x7F, 0x67, 0x77, 0x7C,
						 0x39, 0x5E, 0x79, 0x71};

	unsigned char digit[4]={0x0E, 0x0D, 0x0B, 0x07};

	for (;;)
	{
		P0=~hex[0xA];
		P1=digit[0];	  
		delay();

		P0=~hex[0xB];
		P1=digit[1];
		delay();

		P0=~hex[0xC];
		P1=digit[2];
		delay();

		P0=~hex[0xD];
		P1=digit[3];
		delay();
	}
}