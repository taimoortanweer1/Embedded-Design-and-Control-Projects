#include <p33FJ64MC804.h>
#include "UART.h"
#include "SABERTOOTH.h"

void INIT_SABERTOOTH(void)
{
	TRANSMIT_C2(0xAA); //Autobauding character to Sabertooth
	__delay32(2000000); //100mSEC delay	
}

void FORWARD1(char address, char speed)
{
	TRANSMIT_C2(address);
	TRANSMIT_C2(0); //drive motor 1 forward command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 0 + speed) & 0b01111111);
}
	
void FORWARD2(char address, char speed)
{
	TRANSMIT_C2(address);
	TRANSMIT_C2(4); //drive motor 2 forward command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 4 + speed) & 0b01111111);
}
	
void BACKWARD1(char address, char speed)
{
	TRANSMIT_C2(address);
	TRANSMIT_C2(1); //drive motor 1 backwards command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 1 + speed) & 0b01111111);
}
	
void BACKWARD2(char address, char speed)
{
	TRANSMIT_C2(address);
	TRANSMIT_C2(5);//drive motor 2 backwards command
	TRANSMIT_C2(speed);
	TRANSMIT_C2((address + 5 + speed) & 0b01111111);
}