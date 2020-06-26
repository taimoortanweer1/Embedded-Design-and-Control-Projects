
#include <p33FJ64MC804.h>
#include "compass.h"
#include "UART.h"
#include<stdio.h>
#include<stdlib.h>


extern volatile double g_standAzimuth;
extern volatile double g_standPitch;
extern volatile double g_standRange;

#define LED1_S1 PORTBbits.RB10 
#define LED1_S2 PORTCbits.RC7
#define LED2_S1 PORTBbits.RB11 
#define LED2_S2 PORTBbits.RB9 
#define LED3_S1 PORTCbits.RC6
//#define LED3_S2

//#define ButA_T1
//#define ButA_T2
#define ButB_T1 PORTCbits.RC8
#define ButB_T2 PORTCbits.RC9
#define ButC_T1 PORTCbits.RC0 
#define ButC_T2 PORTCbits.RC1 
#define ButD_T1 PORTBbits.RB2 
#define ButD_T2 PORTBbits.RB3 

void GET_STAND_COMPASS(void)
{
	unsigned int iter = 0;
	volatile unsigned char recvChar = 0;
    unsigned char recvString[20];

	unsigned long int AZIMUTH = 0;
  	signed long int PITCH   = 0;

	
	if(LED2_S1 == 1)
	LED2_S1 = 0;
	else
	LED2_S1 = 1;

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
	if(g_standPitch < 20)
		{g_standPitch = 20;}


}
