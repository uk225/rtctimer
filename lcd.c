#include <reg51.h>
#include "delay.h"

#define lcddata P2
#define dataport P0


sbit rs = dataport^0;
sbit rw = dataport^1;
sbit en = dataport^2;



void cmd(unsigned char a)
{
	lcddata=a;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}

void dat(unsigned char a)
{
	lcddata=a;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}



void init()
{
	cmd(0x38); //4bit mode
	cmd(0x0e); //display on cursor blinking
	cmd(0x01); //clear screen
	cmd(0x06);
	cmd(0x80);
}

void lcd_time_display(unsigned char ss, unsigned char mm, unsigned char hh)
{
	unsigned char left,right;
	
	left = 0x30 | ((hh & 0xf0 ) >> 4) ;
	dat(left);
	right= 0x30 | (hh & 0x0f );
	dat(right);
	
	dat(':');
	
	left = 0x30 | ((mm & 0xf0 ) >> 4) ;
	dat(left);
	right= 0x30 | (mm & 0x0f );
	dat(right);
	
	dat(':');
	
	left = (0x30 | ((ss & 0xf0 ) >> 4)) ;
	dat(left);
	right= 0x30 | (ss & 0x0f );
	dat(right);

}

void lcd_date_display(unsigned char dd, unsigned char mon, unsigned char yy)
{
	
	dat(0x30 | ((dd & 0xf0) >> 4));
	dat(0x30 | ((dd & 0x0f)));
	dat(':');
	
	dat(0x30 | ((mon & 0xf0) >> 4));
	dat(0x30 | ((mon & 0x0f)));
	dat(':');

	dat(0x30 | ((yy & 0xf0) >> 4));
	dat(0x30 | ((yy & 0x0f)));

}
