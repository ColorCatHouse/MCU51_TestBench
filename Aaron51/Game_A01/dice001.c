#include <STC89.H>

void delay(void)
{
	unsigned int a;

	for(a=0; a<20000; a++);
}

void main(void)
{
	unsigned char n=0x01;
	unsigned char a;

	for(;;)
	{	
		for(a=0; a<8; a++)
		{
			P0=~(n<<a);
			delay();
		}	 
	}
}