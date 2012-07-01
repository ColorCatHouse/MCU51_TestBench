/**********************************************
 Title: 	Toggle switch testing
 Ver:		1.0

 Date:		2012-07-01
 By:		Aaron

 Hardware:		XT-100 8x51 Develoment Board

 Connection:	P0  -> LEDs 	 (0:On 1:Off)
 				P20 -> Switch S3 (0:On 1:Off)
 **********************************************/
#include <STC89.H>

void delay(unsigned int delayCount)
{
	unsigned int t;

	for(t=0; t<delayCount; t++);
}

unsigned char getSwitch(void)
{
	P20 = 1;			// Make Pin P20 ready for input

	if (P20 == 0)		// Switch is On
	{
		delay(100);
		if (P20 == 0)
		{
			return 1;
		}
	}
	
	return 0;		// Switch is Off

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
	unsigned char lastkey=0;			// Mark key to be off

	P0=~0x00;			// Light off

	for (;;)
	{
		if (getSwitch() == 1)
		{
			if (lastkey == 0)			// Switch is from Off to On
			{
				lastkey = 1;			// Mark switch is on now
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
		}
		else
		{
			lastkey = 0;				// Switch is off
		}
//		delay(30000);   				// for debug use
	}
} /* main */ 
