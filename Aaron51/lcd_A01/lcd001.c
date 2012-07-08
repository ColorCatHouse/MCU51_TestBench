#include <STC89.H> 

void delay(void)
{
	unsigned int a;

	for(a=0;a<1000;a++);
}

unsigned char checkBusy(void)
{
}
void waitUntilNotBusy(void)
{
	while(checkBusy()==1);
}
void writeCMD(cmd)
{
	waitUntilNotBusy();
	RS=0;
	RW=0;
	P0=cmd;
	EN=1;
	delay();
	EN=0;
	RW=1;
}
void lcdWriteData(Data)
{
	waitUntilNotBusy();
	RS=1
	RW=0;
	P0=dData;
	EN=1;
	delay();
	EN=0;
	RW=1;
}

void main(void)
{
	writeCmd(0x01);
	writeCMD(0xF);
	writeCMD(0x06);

	WriteData('A');
	WriteData('a');
	WriteData('r');
	WriteData('o');
	WriteData('n');
}
