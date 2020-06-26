#ifndef __SABERTOOTH_H
#define __SABERTOOTH_H

#define FCY				39613000

#define BAUDRATE1		9600	      
#define BRGVAL1			((FCY/BAUDRATE1)/16)-1

#define BAUDRATE2		9600
#define BRGVAL2			((FCY/BAUDRATE2)/16)-1

void INIT_SABERTOOTH(void);
void FORWARD1(char address, char speed);
void FORWARD2(char address, char speed);
void BACKWARD1(char address, char speed);
void BACKWARD2(char address, char speed);
#endif


