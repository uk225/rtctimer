#include <reg51.h>


void delay(unsigned int itime)
{
	unsigned int i;
	for(i=0;i<itime;i++);
}