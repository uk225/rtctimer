
#ifndef __LCD_H__
#define __LCD_H__

void cmd(char a);
void dat(char a);
void mssg(unsigned char *ch);
void lcd_timedisplay(char hr,char min, char sec);
void lcd_datedisplay(char dd,char mm, char yy);
void init();


#endif

