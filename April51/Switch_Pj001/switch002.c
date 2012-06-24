/*******************************************************************************
 Title: 	Toogle switch
 Ver:		1.1

 Date:		2012-06-24
 By:		April

 Hardware:	XT-100 8x51 Development Board
			X'tal: 11.0592MHz

 Connection:	P0  -> LEDs (0:on 1:off)
 				P20 -> Switch S3 (0:On 1:Off)
 *******************************************************************************/
#include <STC89.H>

void delayKeyBounce(void)
{
	unsigned int t;

	for (t=0; t<15000; t++);
} /* delayKeyBounce */

unsigned char button(void)
{
	unsigned char buttonOn;

	buttonOn = 0;

	P20 = 1;			// Prepare the output level to high

	if (P20 == 0)		// Voltage level of P20 is low means button pressed
	{
		delayKeyBounce();
		if (P20 == 0)
		{
			buttonOn = 1;
		}
	}
	return buttonOn;

} /* button */

unsigned char changeLight(unsigned char s)
{
	unsigned char light;

	P0 = 0xFF;			// All LEDs off
	if (s == 1)
	{
		P00 = 0; 		// LED on
		light = 1;
	}
	else
	{
		P00 = 1;		// LED off
		light = 0;
	}
	return light;

} /* changeLight */

void main(void)
{
	unsigned char	light;

	for (;;)
	{
		if ((light == 0) && (button() == 1))
		{
			light = changeLight(1);
		}
		else if ((light == 1) && (button() == 1))
		{
			light = changeLight(0);
		}
	}
} /* main */
