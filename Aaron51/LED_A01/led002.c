#include <STC89.H>

void main(void)
{
	unsigned char n;
	int	t;

	for (n=0;;)
	{
		P0=~n++;
		for (t=0; t< 50000; t++);
	}
}
