#include <STC89.H>

unsigned char led(unsigned char a)
{
	return ~a;
}

void delay(unsigned int count)
{
	unsigned int t;

	for(t=0; t<count; t++);
}

void main(void)
{
	for(;;)
	{
		P0 = led(0x43);
		delay(10000);
		
		P0 = led(0x00);
		delay(10000);
	}
}

