#include <STC89.H>

unsigned char led(unsigned char a)
{
	return ~a;
}

void main(void)
{
	unsigned int	t;

	for(;;)
	{
		P0 = led(0x43);
		for (t=0; t<10000; t++);
		
		P0 = led(0x00);
		for (t=0; t<10000; t++);
	}
}