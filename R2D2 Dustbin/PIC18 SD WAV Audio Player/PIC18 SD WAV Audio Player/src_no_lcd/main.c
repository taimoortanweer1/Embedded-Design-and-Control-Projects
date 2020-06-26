/***************************************************

PIC18F SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
May 2010

*****************************************************/
#include <htc.h>
#include <string.h>

#define _XTAL_FREQ 48000000

#pragma config FOSC     = HSPLL_HS
#pragma config PLLDIV   = 5				// (20 MHz crystal on PICDEM FS USB board)
#pragma config CPUDIV   = OSC1_PLL2		// Clock source from 96MHz PLL/2

#pragma config PWRT = ON
#pragma config BOR = ON
#pragma config BORV = 2
#pragma config WDT = OFF
#pragma config DEBUG = ON
#pragma config LVP = OFF

#include "pff.h"
#include "wave_file.h"
#include "pwm_audio.h"

FATFS Fs;			/* File system object */
DIR Dir;			/* Directory object */
FILINFO Fno;		/* File information */

void delay(void);

void main(void)
{
	pwm_audio_init();

	while(1){
		delay();
		if (pf_mount(&Fs) ) continue;	/* Initialize FS */
		while(1){
			if (pf_opendir(&Dir, "")) break;				// open root directory
			while (!pf_readdir(&Dir, &Fno) && Fno.fname[0]) {
				if( strstr(Fno.fname, ".WAV") ){			// WAV file
					play_wave_file(Fno.fname);
					//delay();
				}

				
			}
		}
		
	}
}

void delay(void)
{
	long i=0x7FFFF;
	while(--i);
}