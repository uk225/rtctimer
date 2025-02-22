#ifndef __I2C_H__

#define __I2C_H__

void clock();
void start();
void stop();
void ack();
void noack();
void writei2c(unsigned char dat);
unsigned char readi2c(void);


#endif