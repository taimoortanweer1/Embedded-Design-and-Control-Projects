# MPLAB IDE generated this makefile for use with GNU make.
# Project: control.mcp
# Date: Sat Aug 03 23:19:19 2013

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

control.hex : control.cof
	$(HX) "control.cof"

control.cof : controlpi.o
	$(CC) -mcpu=33FJ64MC802 "controlpi.o" -o"control.cof" -Wl,-Tp33FJ64MC802.gld,--defsym=__MPLAB_BUILD=1,-Map="control.map",--report-mem

controlpi.o : ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libpic30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33fj64mc802.h controlpi.c
	$(CC) -mcpu=33FJ64MC802 -x c -c "controlpi.c" -o"controlpi.o" -g -Wall

clean : 
	$(RM) "controlpi.o" "control.cof" "control.hex"

