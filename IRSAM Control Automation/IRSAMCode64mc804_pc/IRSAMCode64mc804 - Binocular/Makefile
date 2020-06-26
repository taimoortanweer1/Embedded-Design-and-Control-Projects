# MPLAB IDE generated this makefile for use with GNU make.
# Project: New.mcp
# Date: Thu Sep 25 03:30:12 2014

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

New.hex : New.cof
	$(HX) "New.cof"

New.cof : UART.o SABERTOOTH.o clock.o lcd.o compass.o transceiver.o code.o
	$(CC) -mcpu=33FJ64MC804 "UART.o" "SABERTOOTH.o" "clock.o" "lcd.o" "compass.o" "transceiver.o" "code.o" -o"New.cof" -Wl,-L"C:\Program Files (x86)\Microchip\MPLAB C30\lib",--script="C:\Program Files\Microchip\MPLAB C30\support\dsPIC33F\gld\p33FJ64MC804.gld",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="New.map",--report-mem

UART.o : UART.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h UART.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "UART.c" -o"UART.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

SABERTOOTH.o : SABERTOOTH.h UART.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h SABERTOOTH.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "SABERTOOTH.c" -o"SABERTOOTH.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clock.o : c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h clock.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "clock.c" -o"clock.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

lcd.o : UART.h lcd.h c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/stdio.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h lcd.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "lcd.c" -o"lcd.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

compass.o : c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/stdio.h UART.h compass.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h compass.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "compass.c" -o"compass.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

transceiver.o : c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/stdio.h UART.h transceiver.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h transceiver.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "transceiver.c" -o"transceiver.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

code.o : lcd.h clock.h SABERTOOTH.h UART.h c:/program\ files/microchip/mplab\ c30/include/string.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ64MC804.h code.c
	$(CC) -mcpu=33FJ64MC804 -x c -c "code.c" -o"code.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "UART.o" "SABERTOOTH.o" "clock.o" "lcd.o" "compass.o" "transceiver.o" "code.o" "New.cof" "New.hex"

