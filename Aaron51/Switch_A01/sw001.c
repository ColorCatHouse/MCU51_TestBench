#include <STC89.H>

void delay(void)
{
	unsigned int t;

	for(t=0; t<30000; t++);
}

unsigned char getSwitch(void)
{
	P20 = 1;			// Make Pin P20 ready for input

	if (P20 == 0)		// Switch is On
	{
		return 1;
	}
	else
	{
		return 0;		// Switch is Off
	}
} /* getSwitch */

void setLight(unsigned char mode)		// 0:Off   1:On
{
	if (mode == 0)	 	// Light Off
	{	
		P00 = 1;
	}										  
	else
	{
		P00 = 0; 	// Light On    
	}		

} /* setLight */

void main(void)
{
	unsigned char light=0;

	P0=~0x00;			// Light off

	for (;;)
	{
		if (getSwitch() == 1)		// Switch is On
		{
			if (light == 0)			// Light is Off
			{
				setLight(1);		// Turn on the light now
				light = 1; 			// Mark light to On
			}
			else					// Light is on
			{
				setLight(0);  		// Turn off the light now
				light = 0;			// Mark light to Off
			}	
		}
		delay();   					// for debug use
	}
} /* main */ 
