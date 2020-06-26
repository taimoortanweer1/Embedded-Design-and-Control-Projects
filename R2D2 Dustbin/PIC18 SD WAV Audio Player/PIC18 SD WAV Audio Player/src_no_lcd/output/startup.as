
	; HI-TECH C PRO for the PIC18 MCU Family V9.64
	; Copyright (C) 1984-2009 HI-TECH Software
	;Serial no. HCPIC18P-123456

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -oPIC_WAV_Player.cof -mPIC_WAV_Player.map --summary=default \
	; --output=default main.p1 pff.p1 spi_pic18.p1 wave_file.p1 \
	; pwm_audio.p1 sd_mmc.p1 --chip=18F2550 -P --runtime=default \
	; --opt=default -D__DEBUG=1 -g --asmlist \
	; --errformat=Error   [%n] %f; %l.%c %s --msgformat=Advisory[%n] %s \
	; --warnformat=Warning [%n] %f; %l.%c %s
	;



; Config register @ 0x300000
;	CPU System Clock Postscaler
;	CPUDIV = OSC1_PLL2, [OSC1/OSC2 Src: /1][96 MHz PLL Src: /2]
;	PLL Prescaler Selection bits
;	PLLDIV = 5, Divide by 5 (20 MHz oscillator input)

	psect	config,class=CONFIG,delta=1
		org 0x0
		db 0x4

; Config register @ 0x300001
;	Oscillator Selection bits
;	FOSC = HSPLL_HS, HS oscillator, PLL enabled, HS used by USB

	psect	config,class=CONFIG,delta=1
		org 0x1
		db 0xE

; Config register @ 0x300002
;	Brown-out Reset Enable bits
;	BOR = ON, Brown-out Reset enabled in hardware only (SBOREN is disabled)
;	Brown-out Voltage bits
;	BORV = 2, 
;	Power-up Timer Enable bit
;	PWRT = ON, PWRT enabled

	psect	config,class=CONFIG,delta=1
		org 0x2
		db 0x16

; Config register @ 0x300003
;	Watchdog Timer Enable bit
;	WDT = OFF, HW Disabled - SW Controlled

	psect	config,class=CONFIG,delta=1
		org 0x3
		db 0x1E

; Config register @ 0x300006
;	Background Debugger Enable bit
;	DEBUG = ON, Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
;	Single-Supply ICSP Enable bit
;	LVP = OFF, Single-Supply ICSP disabled

	psect	config,class=CONFIG,delta=1
		org 0x6
		db 0x1

	GLOBAL	_main,start,_exit
	FNROOT	_main

	pic18cxx	equ	1

	psect	config,class=CONFIG,delta=1
	psect	idloc,class=IDLOC,delta=1
	psect	eeprom_data,class=EEDATA,delta=1
	psect	const,class=CODE,delta=1,reloc=2
	psect	smallconst,class=SMALLCONST,delta=1,reloc=2
	psect	mediumconst,class=MEDIUMCONST,delta=1,reloc=2
	psect	rbss,class=COMRAM,space=1
	psect	bss,class=RAM,space=1
	psect	rdata,class=COMRAM,space=1
	psect	irdata,class=CODE,space=0,reloc=2
	psect	bss,class=RAM,space=1
	psect	data,class=RAM,space=1
	psect	idata,class=CODE,space=0,reloc=2
	psect	nvram,class=NVRAM,space=1
	psect	nvrram,class=COMRAM,space=1
	psect	nvbit,class=COMRAM,bit,space=1
	psect	temp,ovrld,class=COMRAM,space=1
	psect	struct,ovrld,class=COMRAM,space=1
	psect	rbit,class=COMRAM,bit,space=1
	psect	bigbss,class=BIGRAM,space=1
	psect	bigdata,class=BIGRAM,space=1
	psect	ibigdata,class=CODE,space=0,reloc=2
	psect	farbss,class=FARRAM,space=0,reloc=2,delta=1
	psect	fardata,class=FARRAM,space=0,reloc=2,delta=1
	psect	ifardata,class=CODE,space=0,reloc=2,delta=1

	psect	reset_vec,class=CODE,delta=1,reloc=2
	psect	powerup,class=CODE,delta=1,reloc=2
	psect	intcode,class=CODE,delta=1,reloc=2
	psect	intcodelo,class=CODE,delta=1,reloc=2
	psect	intret,class=CODE,delta=1,reloc=2
	psect	intentry,class=CODE,delta=1,reloc=2

	psect	intsave_regs,class=BIGRAM,space=1
	psect	init,class=CODE,delta=1,reloc=2
	psect	text,class=CODE,delta=1,reloc=2
GLOBAL	intlevel0,intlevel1,intlevel2
intlevel0:
intlevel1:
intlevel2:
GLOBAL	intlevel3
intlevel3:
	psect	end_init,class=CODE,delta=1,reloc=2
	psect	clrtext,class=CODE,delta=1,reloc=2

	psect	rparam,class=COMRAM,space=1
	psect	param0,class=BANK0,space=1
	psect	param1,class=BANK1,space=1
	psect	param2,class=BANK2,space=1
	psect	param3,class=BANK3,space=1
wreg	EQU	0FE8h
fsr0l	EQU	0FE9h
fsr0h	EQU	0FEAh
fsr1l	EQU	0FE1h
fsr1h	EQU	0FE2h
fsr2l	EQU	0FD9h
fsr2h	EQU	0FDAh
postinc0	EQU	0FEEh
postdec0	EQU	0FEDh
postinc1	EQU	0FE6h
postdec1	EQU	0FE5h
postinc2	EQU	0FDEh
postdec2	EQU	0FDDh
tblptrl	EQU	0FF6h
tblptrh	EQU	0FF7h
tblptru	EQU	0FF8h
tablat		EQU	0FF5h

	GLOBAL __accesstop
__accesstop EQU 96
	PSECT	ramtop,class=RAM
	GLOBAL	__S1			; top of RAM usage
	GLOBAL	__ramtop
	GLOBAL	__LRAM,__HRAM
__ramtop:

	PSECT	reset_vec
reset_pos:
	goto	start

	PSECT	init
start:
_exit:
; fardata psect  - 0 bytes to load

; farbss psect  - 0 bytes to clear

; bigdata psect - 0 bytes to load

	lfsr	0,0
	movlw	96	; loop counter
clear_1:
	clrf	postinc0,c	; clear, increment FSR0
	decf	wreg,c	; decrement loop counter
	bnz	clear_1
	lfsr	0,256
	lfsr	1,512
	call	clear_ram
	PSECT	end_init
	GLOBAL	__Lmediumconst
	movlw	low highword(__Lmediumconst)
	movwf	tblptru
	goto	_main		;go do the main stuff
; Clear these memory locations
clear_ram:
	clrf	postinc0	;clear, increment FSR0
	movf	postdec1,w	;decrement loop variable
	movf	fsr1l,w
	bnz	clear_ram
	movf	fsr1h,w
	bnz	clear_ram
	return

	END	reset_pos
