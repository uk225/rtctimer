#include<reg51.h>
#include "delay.h"

sbit sda = P1^0;
sbit scl = P1^1;

void start()
{
	sda = 1;
	scl = 1;
	delay(50);
	sda=0;
	delay(50);
	scl=0;
}

void stop()
{
	scl=0;
	sda=0;
	delay(50);
	scl=1;
	delay(50);
	sda=1;
}

void clock()
{
	delay(50);
	scl =1;
	delay(50);
	scl=0;
}


void ack()
{
	sda =0;
	clock();
	//sda=1;
}
void nack()
{
	sda = 1;
	clock();
	//scl=1;
}


void write(unsigned char ch)
{
	unsigned int i; 
	for( i=0;i<8;i++)
	{
		sda = ch & 0x80;
		clock();
		ch = ch << 1;
	}
	sda = 1;
}
unsigned char read()
{
	unsigned int i;
	unsigned char temp=0x00;
	sda=1;
	for(i=0;i<8;i++)
	{
		temp = temp << 1;
		temp =temp | sda;
		clock();
		
	}
	return temp;
}