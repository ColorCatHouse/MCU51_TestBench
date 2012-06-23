#include <STC89.H>

void delay(void)
{
	unsigned int t;

	for (t=0; t<20000; t++);
}

void main(void)
{
	unsigned char n=1;
	unsigned char a;

	for(;;)
	{	
		for(a=0; a<8; a++)
		{
			P0=~n;
			n*=2;
			delay();
		}
		n=1;
	 }
}