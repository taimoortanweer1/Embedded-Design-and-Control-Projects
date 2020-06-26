#ifndef __clock_H
#define __clock_H

#define FCY				39613000

#define BAUDRATE1		9600	      
#define BRGVAL1			((FCY/BAUDRATE1)/16)-1

#define BAUDRATE2		9600
#define BRGVAL2			((FCY/BAUDRATE2)/16)-1

void CLOCK_CONFIGURATION();

#endif