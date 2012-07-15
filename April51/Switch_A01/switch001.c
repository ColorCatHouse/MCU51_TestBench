#include <STC89.H>

void main(void)
{
	P2=0xFF;

	if (P2==0xFE)
	{
		P0=0x00;		// LED On
	}
	else
	{
		P0=0xFF;		// LED Off
	}

}
