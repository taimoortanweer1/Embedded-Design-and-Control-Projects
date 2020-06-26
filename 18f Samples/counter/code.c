#include<stdio.h>
#include<pic18f4520.h>
#pragma config WDT = OFF

#define S1 PORTAbits.RA1
#define S2 PORTAbits.RA2 
#define S3 PORTAbits.RA3
void delay(int x);
void main()
{
char Flag = 0;
int count = 0;
ADCON1= 0xFF;
TRISA = 0xFF;
TRISD = 0x00;

while(1)
{
if(S1 == 1)
{
	delay(1000);
	if(S2 == 1 && S1 == 1)
	{
		count++;
		delay(2000);
	}
}
}


}

void delay(int x)
{
	for(int y = 0 ; y < x ; y++)
	for(int z = 0 ; z < 2000 ; z++);

}