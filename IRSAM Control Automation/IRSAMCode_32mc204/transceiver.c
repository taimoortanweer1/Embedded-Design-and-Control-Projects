#include <p33FJ32MC204.h>
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

void GET_BINO_COMPASS(void)
{
	unsigned int i=0;
	char str1[5], str2[5], str3[5];

	U1STAbits.OERR = 0;

	while(GET_C1()!= 'H');
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
	str3[i] = '\0';

	if( str1[0] == '9' && str1[1] == '9' && str1[2] == '9' && str1[3] == '9' && str1[4] == '9' )
	{
		out1=1;						//pin high to stop horizental movement 
		__delay32(10000);
		out2=1;						//pin high to stop vertical movement 
		
		SERVO = (.3)*3750*2;
		__delay32(20000000);
		P1TCON = 0x0000;
		__delay32(60000000);
		
		SERVO1 = (.25)*3750*2;
		__delay32(20000000);
		P2TCON = 0x0000;
		
		while(1);


	}
	
	g_BinoAzimuth	=	atof(str1);
	g_BinoPitch 	=	atof(str2);
	g_BinoRange		=	atof(str3);

}