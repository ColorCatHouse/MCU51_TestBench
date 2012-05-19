#include <STC89.H>

unsigned char led(unsigned char a)
{
	return ~a;
}

void main(void)
{
	for(;;)
	{
		P0 = led(0x43);
	}
}