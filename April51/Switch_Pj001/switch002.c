/***************************************
****************************************
 Title: 	Toogle switch
 Ver:		1.0

 Date:		2012-06-24
 By:		April

 Hardware:	XT-100 8x51 Development Board
			X'tal: 11.0592MHz

 Connection:	P0  -> LEDs (0:on 1:off)
 				P20 -> Switch S3 (0:On 1:Off)
 *******************************************************************************/
#include <STC89.H>
 
unsigned char button()
{
	P20 = 1;			// Prepare the output level to high

	if (P20 == 0)		// Voltage level of P20 is low means button pressed
	{
		return 1;
	}
	else				// Voltage level of P20 is high means button is not pressed				
	{
		return 0;
	}
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
	unsigned char light;

	for (;;)
	{
		if ((button() == 0) && (light == 0))
		{
			light = changeLight(1);
		}
		else if ((button() == 0) && (light == 1))
		{
			light = changeLight(1);
		}
		else if ((button() == 1) && (light == 0))
		{
			light = changeLight(1);
		}
		else if ((button() == 1) && (light == 1))
		{
			light = changeLight(0);
		}
	}
} /* main */
