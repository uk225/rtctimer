#ifndef __DS1307_H__

#define __DS1307_H__
void ds1307_init();
void ds1307_setdate(unsigned char dd, unsigned char mm, unsigned char yy);
void ds1307_settime(unsigned char ss,unsigned char mm,unsigned char hh);
void ds1307_gettime(unsigned char *h_ptr,unsigned char *m_ptr,unsigned char *s_ptr);
void ds1307_getdate(unsigned char *dd_ptr,unsigned char *mm_ptr,unsigned char *yy_ptr);



#endif