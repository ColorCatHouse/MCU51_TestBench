#include <STC89.H>

void delay(void)
{
	unsigned int t;

	for(t=0; t<500; t++);
}
unsigned char sw(void)
{
	P20 = 1;

	if (P20 == 0)		// Switch is ON
	{
		return 1;
	}
	else
	{
		return 0;
	}
} /* sw */

unsigned char changeLight(unsigned char s)
{
	if (s == 0)		// Light Off
	{
		delay();
		if (s == 0)
		{	
			P00 = 1;
		}										  
		else
		{
			P00 = 0; 	// Light On    
		}		
	}
} /* changeLight */

void main(void)
{
	unsigned char light=0;

	P0=~0x00;

	for(;;)
	{
		if(sw() == 1);
		{
			if (light == 0);

			chageLight(1);

			else if (light == 1);

			changeLight(0);	
		}
	}
}