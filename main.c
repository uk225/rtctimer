#include<reg51.h>

#include "lcd.h"
#include "delay.h"
#include "ds1307.h"
void main()
{
	unsigned char hr,min,sec,dd,mm,yy;
	unsigned int k;
	init();
	ds1307_init();
	while(1)
	{
		ds1307_gettime(&hr,&min,&sec);
		lcd_timedisplay(hr,min,sec);
		cmd(0xc0);
		ds1307_getdate(&dd,&mm,&yy);
		lcd_datedisplay(dd,mm,yy);
		cmd(0x80);
		
		for(k=0;k<500;k++);
		
	}
	
}