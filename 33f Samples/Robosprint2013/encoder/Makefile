# MPLAB IDE generated this makefile for use with GNU make.
# Project: encoder.mcp
# Date: Sun May 26 19:40:05 2013

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

encoder.hex : encoder.cof
	$(HX) "encoder.cof"

encoder.cof : encoder.o
	$(CC) -mcpu=33FJ64MC802 "encoder.o" -o"encoder.cof" -Wl,-Tp33FJ64MC802.gld,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="encoder.map",--report-mem

encoder.o : ../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libpic30.h ../../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33fj64mc802.h encoder.c
	$(CC) -mcpu=33FJ64MC802 -x c -c "encoder.c" -o"encoder.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "encoder.o" "encoder.cof" "encoder.hex"

