#include <STC89.H>

void delay(void)
{
	unsigned int t;

	for(t=0; t<500; t++);
}

unsigned char sw(void)
{
	P20 = 1;

	if (P20 == 0)		// Switch is On
	{
		return 1;
	}
	else
	{
		return 0;		// Switch is Off
	}
} /* sw */

void changeLight(unsigned char s)
{
	if (s == 0)	 	// Light Off
	{	
		P00 = 1;
	}										  
	else
	{
		P00 = 0; 	// Light On    
	}		

} /* changeLight */

void main(void)
{
	unsigned char light=0;

	P0=~0x00;

	for (;;)
	{
		if (sw() == 1)
		{
			if (light == 0)
			{
				changeLight(1);
			}
			else
			{
				changeLight(0);
			}	
		}
	}
} /* main */ 
