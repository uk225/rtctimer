#ifndef __LCD_H__
#define __LCD_H__
void cmd(unsigned char ch);
void dat(unsigned char ch);
void init();
void mssg(unsigned char *ch);
void lcd_time_display(unsigned char ss, unsigned char mm, unsigned char hh);
void lcd_date_display(unsigned char dd, unsigned char mon, unsigned char yy);

#endif 