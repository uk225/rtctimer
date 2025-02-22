#include <reg51.h>
#include "delay.h"

#define lcddata P2
#define dataport P0


sbit rs = dataport^0;
sbit rw = dataport^1;
sbit en = dataport^2;



void cmd(char a)
{
	lcddata=(a & 0xf0);
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
	lcddata=((a<<4) & 0xf0);
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}

void dat(char a)
{
	lcddata=(a & 0xf0);
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
	lcddata=((a<<4) & 0xf0);
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}




void mssg(unsigned char *ch)
{
	while(*ch!='\0')
	{
		dat(*ch++);
	}
}

void init()
{
	
	cmd(0x02); //return home 
	cmd(0x28); //4bit mode
	cmd(0x0c); //display on cursor off 
	cmd(0x01); //clear screen
	cmd(0x80);
}
void lcd_timedisplay(char hr,char min, char sec)
{
	dat(((hr >> 4) & 0x0f) + 0x30);
	dat((hr & 0x0f) + 0x30);
	
	dat(':');
	
	dat(((min >> 4) & 0x0f) + 0x30);
	dat((min & 0x0f) + 0x30);
	
	dat(':');
	dat(((sec >> 4) & 0x0f) + 0x30);
	dat((sec & 0x0f) + 0x30);
	
}


void lcd_datedisplay(char dd,char mm, char yy)
{
	dat(((dd >> 4) & 0x0f) + 0x30);
	dat((dd & 0x0f) + 0x30);
	
	dat(':');
	
	dat(((mm >> 4) & 0x0f) + 0x30);
	dat((mm & 0x0f) + 0x30);
	
	dat(':');
	dat(((yy >> 4) & 0x0f) + 0x30);
	dat((yy & 0x0f) + 0x30);
	
}
