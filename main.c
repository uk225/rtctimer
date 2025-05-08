#include<reg51.h>
#include "lcd.h"
#include "delay.h"
#include "ds1307.h"

void main()
{
	
	unsigned char ss;
	unsigned char mm;
	unsigned char hh;
	unsigned char dd;
	unsigned char mon;
	unsigned char yy;
	init();
	ds1307init();
	
	while(1)
	{
		
		gettime(&ss,&mm,&hh);
		getdate(&dd,&mon,&yy);
		cmd(0x80);
		lcd_time_display(ss,mm,hh);
		cmd(0xc0);
		lcd_date_display(dd,mon,yy);
		delay(500);
		
		
	}
	
}

