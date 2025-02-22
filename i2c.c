#include <reg51.h>
#include "delay.h"

sbit scl=P1^0;
sbit sda=P1^1;

void clock()
{
	delay(50);
	scl=1;
	delay(50);
	scl=0;
	
}

void start()
{
	scl=0;
	sda=1;
	delay(50);
	scl=1;
	delay(50);
	sda=0;
	delay(50);
	scl=0;
}
void stop()
{
	scl=0;
	delay(50);
	sda=0;
	delay(50);
	scl=1;
	delay(50);
	sda=1;
}

void ack()
{
	sda=0;
	clock();
	sda=1;
}

void noack()
{
	
	sda=1;
	clock();
	scl=1;
}



void writei2c(unsigned char dat)
{
	unsigned int i;
	for(i=0;i<8;i++)
	{
		sda = dat & 0x80;
		clock();
		dat=dat<<1;
	}
	sda=1;
}

unsigned char readi2c(void)
{
	unsigned char dat=0x00;
	unsigned int i;
	
	sda=1;
	for(i=0;i<8;i++)
	{
		scl=1;
		dat=dat<<1;
		dat= dat | sda;
		scl=0;
	}
	return dat;
}