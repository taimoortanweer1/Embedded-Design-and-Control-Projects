#include <p33FJ64MC804.h>

#include<stdio.h>
#include<stdlib.h>

#include "lcd.h"
#include "UART.h"

extern volatile double g_standAzimuth;
extern volatile double g_standPitch;
extern volatile double g_BinoAzimuth;
extern volatile double g_BinoPitch;
extern volatile double g_BinoRange;

void INIT_LCD(void)
{
	__delay32(8000000);
	__delay32(8000000);

	TRANSMIT_C1(0x55); //Setting to Auto Baud Rate
	
	while(U1RXREG != 0x06);

	//__delay32(8000000);

	TRANSMIT_C1(0x45); //Clearing Display
	
	while(U1RXREG != 0x06);

	//__delay32(8000000);

	TRANSMIT_C1(0x59); //Setting Display Orientation
	TRANSMIT_C1(0x04);
	TRANSMIT_C1(0x01);

	while(U1RXREG != 0x06);

	//__delay32(8000000);

	TRANSMIT_C1(0x42); //Setting Background Color
	TRANSMIT_C1(0x00);
	TRANSMIT_C1(0x00);

	while(U1RXREG != 0x06);

	//__delay32(8000000);
	
	TRANSMIT_C1(0x4F); //Setting Text Transparent Property
	TRANSMIT_C1(0x01);

	while(U1RXREG != 0x06);

	//__delay32(8000000);
}

void DISP_TEMPLATE(void)
{
	TRANSMIT_C1(0x46); //Setting Font Size
	TRANSMIT_C1(0x03);

	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('B');
	TRANSMIT_C1(1);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('i');
	TRANSMIT_C1(2);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('n');
	TRANSMIT_C1(3);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('o');
	TRANSMIT_C1(4);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('c');
	TRANSMIT_C1(5);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('u');
	TRANSMIT_C1(6);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('l');
	TRANSMIT_C1(7);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(8);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('r');
	TRANSMIT_C1(9);
	TRANSMIT_C1(1);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('H');
	TRANSMIT_C1(2);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('e');
	TRANSMIT_C1(3);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(4);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
	
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('d');
	TRANSMIT_C1(5);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(' ');
	TRANSMIT_C1(6);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(':');
	TRANSMIT_C1(7);
	TRANSMIT_C1(3);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('P');
	TRANSMIT_C1(2);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('i');
	TRANSMIT_C1(3);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('t');
	TRANSMIT_C1(4);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('c');
	TRANSMIT_C1(5);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('h');
	TRANSMIT_C1(6);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(':');
	TRANSMIT_C1(7);
	TRANSMIT_C1(4);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('R');
	TRANSMIT_C1(2);
	TRANSMIT_C1(5);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(3);
	TRANSMIT_C1(5);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('n');
	TRANSMIT_C1(4);
	TRANSMIT_C1(5);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('g');
	TRANSMIT_C1(5);
	TRANSMIT_C1(5);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('e');
	TRANSMIT_C1(6);
	TRANSMIT_C1(5);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(':');
	TRANSMIT_C1(7); //Column
	TRANSMIT_C1(5); //Row
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('L');
	TRANSMIT_C1(1);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(2);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('u');
	TRANSMIT_C1(3);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('n');
	TRANSMIT_C1(4);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('c');
	TRANSMIT_C1(5);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('h');
	TRANSMIT_C1(6);
	TRANSMIT_C1(7);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(' ');
	TRANSMIT_C1(7); //Column
	TRANSMIT_C1(7); //Row
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('P');
	TRANSMIT_C1(8); //Column
	TRANSMIT_C1(7); //Row
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(9); //Column
	TRANSMIT_C1(7); //Row
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('d');
	TRANSMIT_C1(10); //Column
	TRANSMIT_C1(7);  //Row
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('H');
	TRANSMIT_C1(2);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('e');
	TRANSMIT_C1(3);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('a');
	TRANSMIT_C1(4);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('d');
	TRANSMIT_C1(5);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(' ');
	TRANSMIT_C1(6);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(':');
	TRANSMIT_C1(7);
	TRANSMIT_C1(9);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

//-----------------------------------------------

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('P');
	TRANSMIT_C1(2);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('i');
	TRANSMIT_C1(3);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('t');
	TRANSMIT_C1(4);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('c');
	TRANSMIT_C1(5);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1('h');
	TRANSMIT_C1(6);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
		
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);

	TRANSMIT_C1(0x54); //Drawing ASCII Character
	TRANSMIT_C1(':');
	TRANSMIT_C1(7);
	TRANSMIT_C1(10);
	TRANSMIT_C1(0xFF);
	TRANSMIT_C1(0xFF);
	
	while(U1RXREG != 0x06);

	__delay32(SMALL_DELAY);
}

void DISP_DATA(void)
{
	char strBinoRange[5];
	char strBinoAzimuth[5];
	char strBinoPitch[5];
	char strStandAzimuth[5];
	char strStandPitch[5];

	unsigned int lengthTemp = 0, iter = 0;

	lengthTemp = sprintf(strBinoRange, "%f", g_BinoRange);
	lengthTemp = sprintf(strBinoAzimuth, "%f", g_BinoAzimuth+10);
	lengthTemp = sprintf(strBinoPitch, "%f", g_BinoPitch);

	lengthTemp = sprintf(strStandAzimuth, "%f", g_standAzimuth);
	lengthTemp = sprintf(strStandPitch, "%f", g_standPitch);

	

	for(iter=0; iter<5; iter++)
	{
		TRANSMIT_C1(0x54); //Drawing ASCII Character
		TRANSMIT_C1(strBinoAzimuth[iter]);
		TRANSMIT_C1(9+iter); //Column
		TRANSMIT_C1(3); //Row
		TRANSMIT_C1(0xFF);
		TRANSMIT_C1(0xFF);
		
		while(U1RXREG != 0x06);

		__delay32(SMALL_DELAY);

		TRANSMIT_C1(0x54); //Drawing ASCII Character
		TRANSMIT_C1(strBinoPitch[iter]);
		TRANSMIT_C1(9+iter); //Column
		TRANSMIT_C1(4); //Row
		TRANSMIT_C1(0xFF);
		TRANSMIT_C1(0xFF);
		
		while(U1RXREG != 0x06);

		__delay32(SMALL_DELAY);

		TRANSMIT_C1(0x54); //Drawing ASCII Character
		TRANSMIT_C1(strBinoRange[iter]);
		TRANSMIT_C1(9+iter); //Column
		TRANSMIT_C1(5); //Row
		TRANSMIT_C1(0xFF);
		TRANSMIT_C1(0xFF);
		
		while(U1RXREG != 0x06);

		__delay32(SMALL_DELAY);

		TRANSMIT_C1(0x54); //Drawing ASCII Character
		TRANSMIT_C1(strStandAzimuth[iter]);
		TRANSMIT_C1(9+iter); //Column
		TRANSMIT_C1(9); //Row
		TRANSMIT_C1(0xFF);
		TRANSMIT_C1(0xFF);
		
		while(U1RXREG != 0x06);

		__delay32(SMALL_DELAY);

		TRANSMIT_C1(0x54); //Drawing ASCII Character
		TRANSMIT_C1(strStandPitch[iter]);
		TRANSMIT_C1(9+iter); //Column
		TRANSMIT_C1(10); //Row
		TRANSMIT_C1(0xFF);
		TRANSMIT_C1(0xFF);
		
		while(U1RXREG != 0x06);

		__delay32(SMALL_DELAY);
	}
}
