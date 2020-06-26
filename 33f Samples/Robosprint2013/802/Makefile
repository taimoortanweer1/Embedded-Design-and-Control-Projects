# MPLAB IDE generated this makefile for use with GNU make.
# Project: 802.mcp
# Date: Sat Jan 05 15:32:27 2013

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

802.hex : 802.cof
	$(HX) "802.cof"

802.cof : 802.o
	$(CC) -mcpu=33FJ64MC802 "802.o" -o"802.cof" -Wl,-Tp33FJ64MC802.gld,--defsym=__MPLAB_BUILD=1,-Map="802.map",--report-mem

802.o : ../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libpic30.h ../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33fj64mc802.h 802.c
	$(CC) -mcpu=33FJ64MC802 -x c -c "802.c" -o"802.o" -g -Wall

clean : 
	$(RM) "802.o" "802.cof" "802.hex"

