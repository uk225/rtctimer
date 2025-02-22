#include <reg51.h>
#include "i2c.h"
#define DS1307 0xD0


void ds1307_init()
{
	start();
	writei2c(DS1307);clock();
	writei2c(0x07);clock();
	writei2c(0x00);clock();
	stop();
}



void ds1307_setdate(unsigned char dd, unsigned char mm, unsigned char yy)
{
	start();
	
	writei2c(dd);clock();
	writei2c(mm);clock();
	writei2c(yy);clock();
	stop();
	
	
}
void ds1307_settime(unsigned char ss,unsigned char mm,unsigned char hh)
{
	start();
	
	writei2c(ss);clock();
	writei2c(mm);clock();
	writei2c(hh);clock();
	stop();
}

void ds1307_gettime(unsigned char *h_ptr,unsigned char *m_ptr,unsigned char *s_ptr)
{
	start();
	writei2c(DS1307);clock();
	writei2c(0x00);clock();
	
	stop();
	
	
	start();
	writei2c(0xD1);clock();
	*s_ptr=readi2c();ack();
	*m_ptr=readi2c();ack();
	*h_ptr=readi2c();noack();  
  stop();  
	
}


void ds1307_getdate(unsigned char *dd_ptr,unsigned char *mm_ptr,unsigned char *yy_ptr)
{
	start();
	writei2c(DS1307);clock();
	writei2c(0x04);clock();
	
	stop();
	
	start();
	writei2c(0xD1);clock();
	*dd_ptr=readi2c();ack();
	*mm_ptr=readi2c();ack();
	*yy_ptr=readi2c();noack();  
  stop();  
}



