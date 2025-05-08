#ifndef __I2C_H__
#define __I2C_H__
void start();
void stop();
void clock();
void ack();
void nack();
unsigned char read();
void write(unsigned char ch);
#endif 