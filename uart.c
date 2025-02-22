#include<reg51.h>
#include "lcd.h"
unsigned char mybyte;

void write()
{
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	while(1)
	{
		while(RI==0);
		mybyte=SBUF;
		P1=mybyte;
		
		switch(mybyte)
		{
			case 0x0d:  //enter press
				cmd(0xc0);
				break;
			case 0x08:  // back space is pressed
			  cmd(0x04);
				dat(0x20); // to clear 1 character
			  cmd(0x06);
				break;
			case 0x2e: // delete is pres
				cmd(0x01);
				break;
			default:
				dat(mybyte);
				break;
		}
		RI=0;
	}
}




void init_uart()
{
	cmd(0x28);// 4 bitchar
	cmd(0x01); //clear screan
	cmd(0x0A); // display off cursor on
	cmd(0x06); //increment cursor to righit
  cmd(0x80); // force cursor to begin first line
}