#ifndef __DS1307_H__
#define __DS1307_H__
void ds1307init();
void gettime(unsigned char *ss,unsigned char *mm,unsigned char *h);
void getdate(unsigned char *dd,unsigned char *mm, unsigned char *yy);
#endif 