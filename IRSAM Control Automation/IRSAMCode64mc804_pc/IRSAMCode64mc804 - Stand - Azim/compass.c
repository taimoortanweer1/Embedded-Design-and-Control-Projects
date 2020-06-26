
#include <p33FJ64MC804.h>
#include "compass.h"
#include "UART.h"
#include<stdio.h>
#include<stdlib.h>


extern volatile double g_standAzimuth;
extern volatile double g_standPitch;
extern volatile double g_standRange;


void GET_STAND_COMPASS(void)
{
	unsigned int iter = 0;
	volatile unsigned char recvChar = 0;
    unsigned char recvString[20];

	unsigned long int AZIMUTH = 0;
  	signed long int PITCH   = 0;


	U2STAbits.OERR = 0;

	while(1)
	{
		recvChar = GET_C2();
		if(recvChar == 13)
			break;
	}

	recvChar = 0;
	while(iter < 15)
	{
		recvString[iter] = GET_C2();
		iter++;
  	}

	iter = 0;
	AZIMUTH = ((unsigned int)recvString[9]*(unsigned int)256);
	AZIMUTH = AZIMUTH+(unsigned int)recvString[8];
	AZIMUTH = AZIMUTH*(unsigned int)1000;
	AZIMUTH = (AZIMUTH/(unsigned int)65535);
	AZIMUTH = AZIMUTH*(unsigned int)360;

    g_standAzimuth = AZIMUTH/(float)1000;
	
	PITCH = ((signed int)recvString[7]*(signed int)256);
	PITCH = PITCH+(signed int)recvString[6];
	PITCH = PITCH*(unsigned int)1000;
	PITCH = (PITCH/(unsigned int)65535);
	PITCH = PITCH*(unsigned int)360;

	g_standPitch = PITCH/(float)1000;


}


