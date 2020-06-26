#include <p33FJ64MC804.h>
#include "transceiver.h"
#include "UART.h"
#include<stdio.h>
#include<stdlib.h>

#define SERVO P1DC3
#define SERVO1 P2DC1

//#define out1 PORTBbits.RB7
//#define out2 PORTBbits.RB6

#define ButA_T1 PORTBbits.RB7
#define ButA_T2 PORTBbits.RB8
#define ButB_T1 PORTCbits.RC8
#define ButB_T2 PORTCbits.RC9
#define ButC_T1 PORTCbits.RC0 
#define ButC_T2 PORTCbits.RC1 
#define ButD_T1 PORTBbits.RB2 
#define ButD_T2 PORTBbits.RB3 

#define LED1_S1 PORTBbits.RB10 
#define LED1_S2 PORTCbits.RC7
#define LED2_S1 PORTBbits.RB11 
#define LED2_S2 PORTBbits.RB9 
#define LED3_S1 PORTCbits.RC6

extern volatile double g_BinoAzimuth;
extern volatile double g_BinoPitch;
extern volatile double g_BinoRange;
extern volatile double g_standAzimuth;
extern volatile double g_standPitch;
extern volatile double g_standRange;
extern volatile char g_standStatus[3];

void GET_STAND_STATUS(void)
{
	unsigned int i=0;

	U1STAbits.OERR = 0;

	while(GET_C1()!= 'B');
	i=0;
	
	while(i<3)
	{
		g_standStatus[i] = GET_C1();
		i++;
	}
	g_standStatus[i] = '\0';

	if(g_standStatus[0] == 1)
	{
		LED3_S1 = 1;		
	}
	else
	{
	    LED3_S1 = 0;		
	}

}

void SEND_DATA(void)
{
	char strAzimuth[5], strPitch[5], strRange[5], strButton[4];
	unsigned int lengthTemp = 0, iter = 0;

	if( g_standPitch < 15.0 )
	{
		g_standPitch = 15.0;
	}
	
		if( g_standPitch > 50.0 )
	{
		g_standPitch = 50.0;
	}
	lengthTemp = sprintf(strAzimuth, "%f", g_standAzimuth);
	lengthTemp = sprintf(strPitch, "%f", g_standPitch);
	lengthTemp = sprintf(strRange, "%f", g_standRange);

	
	strButton[0] = ButB_T1;	
	strButton[1] = ButC_T1;	
    strButton[2] = ButD_T1;
	strButton[3] = ButA_T1;

	iter = 0;
	TRANSMIT_C1('H');
		
	for(iter=0; iter<=4; iter++)
	{	
		TRANSMIT_C1(strAzimuth[iter]);
	}

	TRANSMIT_C1('P');
		
	for(iter=0; iter<=4; iter++)
	{
		TRANSMIT_C1(strPitch[iter]);
	}

	TRANSMIT_C1('R');

	for(iter=0; iter<=4; iter++)
	{
		TRANSMIT_C1(strRange[iter]);
	}

	TRANSMIT_C1('B');
	
	for(iter=0; iter<=3; iter++)
	{
		TRANSMIT_C1(strButton[iter]);
	}

	
}