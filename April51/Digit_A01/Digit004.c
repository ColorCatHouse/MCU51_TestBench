#include <STC89.H>

void delay(void)
{ 	
	unsigned int t;

	for(t=0;t<20000;t++);
}

void main(void)
{
	unsigned char hex[16]={~0x3F, ~0x06, ~0x5B, ~0x4F,
						   ~0x66, ~0x6D, ~0x7D, ~0x07,
						   ~0x7F, ~0x67, ~0x77, ~0x7C,
						   ~0x39, ~0x5E, ~0x79, ~0x71};
	unsigned char digit[4]={0xE, 0xD, 0xB, 0x7};
	
	for(;;)
	{
		P0=hex[0xb];
		P1=digit[0];
		delay();
	
		P0=hex[0xc];
		P1=digit[1];
		delay();
	
		P0=hex[0xd];
		P1=digit[2];
		delay();
		
		P0=hex[0xe];
		P1=digit[3];
		delay();	
	}
}