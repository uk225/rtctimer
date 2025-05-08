#include<reg51.h>
#include "i2c.h"
#define DS1307 0xD0


void ds1307init()
{
	start();
	write(DS1307);clock();
	write(0x00);clock();
	stop();
}

void gettime(unsigned char *ss,unsigned char *mm,unsigned char *hh)
{
	start();
	write(DS1307);clock();
	write(0x00);clock();
	stop();
	
	start();
	write(0xD1);clock();
	*ss = read();ack();
	*mm = read();ack();
	*hh = read();nack();
	stop();
}

void getdate(unsigned char *dd,unsigned char *mm, unsigned char *yy)
{
	start();
	write(DS1307);clock();
	write(0x04);clock();
	stop();
	
	start();
	write(0xD1);clock();
	*dd = read();ack();
	*mm =read();ack();
	*yy =read();nack();
	stop();
}