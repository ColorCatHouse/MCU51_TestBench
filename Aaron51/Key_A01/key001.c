#include <STC89.H>

void delay(void)
{
	int t;
	
	for (t=0; t<20000; t++);
}
				
void main(void)
{
	unsigned char ptn;
	unsigned char n;

	P2=0xFF;			// Ready to check key pressed
	for (;;)
	{
		ptn=1;
		for (n=0; n<8; n++)
		{
			P0 = ~(ptn << n);
			delay();
		}
		if (P2==0xFE)
		{
			ptn=0x80;
			for (n=0; n<8; n++)
			{
				P0 = ~(ptn >> n);
				delay();
			}
		}	
	}
}