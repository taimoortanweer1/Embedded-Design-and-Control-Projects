# MPLAB IDE generated this makefile for use with GNU make.
# Project: pro.mcp
# Date: Fri Nov 02 17:28:28 2012

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

pro.hex : pro.cof
	$(HX) "pro.cof"

pro.cof : TANK.o
	$(CC) -mcpu=33FJ64MC802 "TANK.o" -o"pro.cof" -Wl,--script="..\..\..\..\..\..\Program Files\Microchip\MPLAB C30\support\dsPIC33F\gld\p33FJ64MC802.gld",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="pro.map",--report-mem

TANK.o : ../../../../../../program\ files/microchip/mplab\ c30/include/string.h ../../../../../../program\ files/microchip/mplab\ c30/include/stdlib.h ../../../../../../program\ files/microchip/mplab\ c30/include/yvals.h ../../../../../../program\ files/microchip/mplab\ c30/include/stdio.h ../../../../../../program\ files/microchip/mplab\ c30/support/generic/h/libpic30.h ../../../../../../program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC802.h ../../../../../../program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33Fxxxx.h ../../../../../../program\ files/microchip/mplab\ c30/support/peripheral_30F_24H_33F/uart.h ../../../../../../program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC802.h ../../TANK.c
	$(CC) -mcpu=33FJ64MC802 -x c -c "C:\Users\user\Desktop\Taimoor\TANK.c" -o"TANK.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "TANK.o" "pro.cof" "pro.hex"

