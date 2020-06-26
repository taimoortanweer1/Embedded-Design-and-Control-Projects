#include <p33FJ64MC804.h>
#include "transceiver.h"
#include "UART.h"
#include<stdio.h>
#include<stdlib.h>

#define SERVO P1DC3
#define SERVO1 P2DC1

#define out1 PORTBbits.RB7
#define out2 PORTBbits.RB6

extern volatile double g_BinoAzimuth;
extern volatile double g_BinoPitch;
extern volatile double g_BinoRange;
extern volatile char   g_BinoButton[4];

extern volatile double g_standAzimuth;
extern volatile double g_standPitch;
extern volatile double g_standRange;
volatile char          g_standStatus;

void GET_BINO_COMPASS(void)
{
	unsigned int i=0;
	char str1[5], str2[5], str3[5];//str4[3]

	U1STAbits.OERR = 0;

	while(GET_C1()!= 'H' )
	{
		if (g_standPitch<17)
			{
				FORWARD1(129,0);
				FORWARD2(129,0);
			}
	}
	i=0;
	
	while(i<6)
	{
		str1[i] = GET_C1();
		i++;
	}
	str1[i] = '\0';
	
	while(GET_C1()!= 'P');
	i=0;
	  	
	while(i<6)
	{
		str2[i] = GET_C1();
		i++;
	}
	str2[i] = '\0';
	
	while(GET_C1()!= 'R');

	i=0;
	
	while(i<6)
	{
		str3[i] = GET_C1();
		i++;
	}
	
	while(GET_C1()!= 'B');
	
	i=0;
	
	while(i<4)
	{
		g_BinoButton[i] = GET_C1();
		i++;
	}
	g_BinoButton[i]= '\0';

	g_BinoAzimuth	=	atof(str1);
	g_BinoPitch 	=	atof(str2);
	g_BinoRange	    =   atof(str3);
		
	i = 0;

}

void SEND_STATUS_DATA(void)
{
	TRANSMIT_C1('W');
	TRANSMIT_C1(g_standStatus);		
}

	
