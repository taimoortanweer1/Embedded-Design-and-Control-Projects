opt subtitle "Microchip Technology Omniscient Code Generator (Lite mode) build 59893"

opt pagewidth 120

	opt lm

	processor	18F2550
porta	equ	0F80h
portb	equ	0F81h
portc	equ	0F82h
portd	equ	0F83h
porte	equ	0F84h
lata	equ	0F89h
latb	equ	0F8Ah
latc	equ	0F8Bh
latd	equ	0F8Ch
late	equ	0F8Dh
trisa	equ	0F92h
trisb	equ	0F93h
trisc	equ	0F94h
trisd	equ	0F95h
trise	equ	0F96h
pie1	equ	0F9Dh
pir1	equ	0F9Eh
ipr1	equ	0F9Fh
pie2	equ	0FA0h
pir2	equ	0FA1h
ipr2	equ	0FA2h
t3con	equ	0FB1h
tmr3l	equ	0FB2h
tmr3h	equ	0FB3h
ccp1con	equ	0FBDh
ccpr1l	equ	0FBEh
ccpr1h	equ	0FBFh
adcon1	equ	0FC1h
adcon0	equ	0FC2h
adresl	equ	0FC3h
adresh	equ	0FC4h
sspcon2	equ	0FC5h
sspcon1	equ	0FC6h
sspstat	equ	0FC7h
sspadd	equ	0FC8h
sspbuf	equ	0FC9h
t2con	equ	0FCAh
pr2	equ	0FCBh
tmr2	equ	0FCCh
t1con	equ	0FCDh
tmr1l	equ	0FCEh
tmr1h	equ	0FCFh
rcon	equ	0FD0h
wdtcon	equ	0FD1h
lvdcon	equ	0FD2h
osccon	equ	0FD3h
t0con	equ	0FD5h
tmr0l	equ	0FD6h
tmr0h	equ	0FD7h
status	equ	0FD8h
fsr2	equ	0FD9h
fsr2l	equ	0FD9h
fsr2h	equ	0FDAh
plusw2	equ	0FDBh
preinc2	equ	0FDCh
postdec2	equ	0FDDh
postinc2	equ	0FDEh
indf2	equ	0FDFh
bsr	equ	0FE0h
fsr1	equ	0FE1h
fsr1l	equ	0FE1h
fsr1h	equ	0FE2h
plusw1	equ	0FE3h
preinc1	equ	0FE4h
postdec1	equ	0FE5h
postinc1	equ	0FE6h
indf1	equ	0FE7h
wreg	equ	0FE8h
fsr0	equ	0FE9h
fsr0l	equ	0FE9h
fsr0h	equ	0FEAh
plusw0	equ	0FEBh
preinc0	equ	0FECh
postdec0	equ	0FEDh
postinc0	equ	0FEEh
indf0	equ	0FEFh
intcon3	equ	0FF0h
intcon2	equ	0FF1h
intcon	equ	0FF2h
prod	equ	0FF3h
prodl	equ	0FF3h
prodh	equ	0FF4h
tablat	equ	0FF5h
tblptr	equ	0FF6h
tblptrl	equ	0FF6h
tblptrh	equ	0FF7h
tblptru	equ	0FF8h
pcl	equ	0FF9h
pclat	equ	0FFAh
pclath	equ	0FFAh
pclatu	equ	0FFBh
stkptr	equ	0FFCh
tosl	equ	0FFDh
tosh	equ	0FFEh
tosu	equ	0FFFh
clrc   macro
	bcf	status,0
endm
setc   macro
	bsf	status,0
endm
clrz   macro
	bcf	status,2
endm
setz   macro
	bsf	status,2
endm
skipnz macro
	btfsc	status,2
endm
skipz  macro
	btfss	status,2
endm
skipnc macro
	btfsc	status,0
endm
skipc  macro
	btfss	status,0
endm
pushw macro
	movwf postinc1
endm
pushf macro arg1
	movff arg1, postinc1
endm
popw macro
	movf postdec1,w
	movf indf1,w
endm
popf macro arg1
	movf postdec1,w
	movff indf1,arg1
endm
popfc macro arg1
	movff plusw1,arg1
	decfsz fsr1,f
endm
	global	__ramtop
	global	__accesstop
# 49 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UFRM equ 0F66h ;# 
# 55 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UFRML equ 0F66h ;# 
# 132 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UFRMH equ 0F67h ;# 
# 171 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UIR equ 0F68h ;# 
# 226 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UIE equ 0F69h ;# 
# 281 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEIR equ 0F6Ah ;# 
# 331 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEIE equ 0F6Bh ;# 
# 381 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
USTAT equ 0F6Ch ;# 
# 440 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UCON equ 0F6Dh ;# 
# 490 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UADDR equ 0F6Eh ;# 
# 553 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UCFG equ 0F6Fh ;# 
# 634 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP0 equ 0F70h ;# 
# 765 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP1 equ 0F71h ;# 
# 896 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP2 equ 0F72h ;# 
# 1027 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP3 equ 0F73h ;# 
# 1158 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP4 equ 0F74h ;# 
# 1289 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP5 equ 0F75h ;# 
# 1420 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP6 equ 0F76h ;# 
# 1551 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP7 equ 0F77h ;# 
# 1682 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP8 equ 0F78h ;# 
# 1769 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP9 equ 0F79h ;# 
# 1856 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP10 equ 0F7Ah ;# 
# 1943 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP11 equ 0F7Bh ;# 
# 2030 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP12 equ 0F7Ch ;# 
# 2117 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP13 equ 0F7Dh ;# 
# 2204 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP14 equ 0F7Eh ;# 
# 2291 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
UEP15 equ 0F7Fh ;# 
# 2378 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PORTA equ 0F80h ;# 
# 2534 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PORTB equ 0F81h ;# 
# 2643 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PORTC equ 0F82h ;# 
# 2796 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PORTE equ 0F84h ;# 
# 3029 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
LATA equ 0F89h ;# 
# 3164 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
LATB equ 0F8Ah ;# 
# 3296 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
LATC equ 0F8Bh ;# 
# 3411 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TRISA equ 0F92h ;# 
# 3416 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
DDRA equ 0F92h ;# 
# 3608 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TRISB equ 0F93h ;# 
# 3613 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
DDRB equ 0F93h ;# 
# 3829 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TRISC equ 0F94h ;# 
# 3834 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
DDRC equ 0F94h ;# 
# 4000 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
OSCTUNE equ 0F9Bh ;# 
# 4058 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PIE1 equ 0F9Dh ;# 
# 4131 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PIR1 equ 0F9Eh ;# 
# 4204 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
IPR1 equ 0F9Fh ;# 
# 4277 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PIE2 equ 0FA0h ;# 
# 4347 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PIR2 equ 0FA1h ;# 
# 4417 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
IPR2 equ 0FA2h ;# 
# 4487 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
EECON1 equ 0FA6h ;# 
# 4552 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
EECON2 equ 0FA7h ;# 
# 4558 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
EEDATA equ 0FA8h ;# 
# 4564 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
EEADR equ 0FA9h ;# 
# 4570 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
RCSTA equ 0FABh ;# 
# 4575 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
RCSTA1 equ 0FABh ;# 
# 4779 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TXSTA equ 0FACh ;# 
# 4784 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TXSTA1 equ 0FACh ;# 
# 5076 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TXREG equ 0FADh ;# 
# 5081 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TXREG1 equ 0FADh ;# 
# 5087 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
RCREG equ 0FAEh ;# 
# 5092 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
RCREG1 equ 0FAEh ;# 
# 5098 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SPBRG equ 0FAFh ;# 
# 5103 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SPBRG1 equ 0FAFh ;# 
# 5109 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SPBRGH equ 0FB0h ;# 
# 5115 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
T3CON equ 0FB1h ;# 
# 5237 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR3 equ 0FB2h ;# 
# 5243 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR3L equ 0FB2h ;# 
# 5249 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR3H equ 0FB3h ;# 
# 5255 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CMCON equ 0FB4h ;# 
# 5350 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CVRCON equ 0FB5h ;# 
# 5434 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ECCP1AS equ 0FB6h ;# 
# 5439 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCP1AS equ 0FB6h ;# 
# 5563 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ECCP1DEL equ 0FB7h ;# 
# 5568 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCP1DEL equ 0FB7h ;# 
# 5602 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
BAUDCON equ 0FB8h ;# 
# 5607 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
BAUDCTL equ 0FB8h ;# 
# 5781 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCP2CON equ 0FBAh ;# 
# 5844 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR2 equ 0FBBh ;# 
# 5850 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR2L equ 0FBBh ;# 
# 5856 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR2H equ 0FBCh ;# 
# 5862 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCP1CON equ 0FBDh ;# 
# 5925 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR1 equ 0FBEh ;# 
# 5931 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR1L equ 0FBEh ;# 
# 5937 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
CCPR1H equ 0FBFh ;# 
# 5943 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADCON2 equ 0FC0h ;# 
# 6013 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADCON1 equ 0FC1h ;# 
# 6103 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADCON0 equ 0FC2h ;# 
# 6225 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADRES equ 0FC3h ;# 
# 6231 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADRESL equ 0FC3h ;# 
# 6237 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
ADRESH equ 0FC4h ;# 
# 6243 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SSPCON2 equ 0FC5h ;# 
# 6304 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SSPCON1 equ 0FC6h ;# 
# 6373 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SSPSTAT equ 0FC7h ;# 
# 6639 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SSPADD equ 0FC8h ;# 
# 6645 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
SSPBUF equ 0FC9h ;# 
# 6651 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
T2CON equ 0FCAh ;# 
# 6748 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PR2 equ 0FCBh ;# 
# 6753 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
MEMCON equ 0FCBh ;# 
# 6857 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR2 equ 0FCCh ;# 
# 6863 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
T1CON equ 0FCDh ;# 
# 6967 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR1 equ 0FCEh ;# 
# 6973 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR1L equ 0FCEh ;# 
# 6979 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR1H equ 0FCFh ;# 
# 6985 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
RCON equ 0FD0h ;# 
# 7133 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
WDTCON equ 0FD1h ;# 
# 7160 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
HLVDCON equ 0FD2h ;# 
# 7165 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
LVDCON equ 0FD2h ;# 
# 7429 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
OSCCON equ 0FD3h ;# 
# 7511 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
T0CON equ 0FD5h ;# 
# 7580 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR0 equ 0FD6h ;# 
# 7586 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR0L equ 0FD6h ;# 
# 7592 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TMR0H equ 0FD7h ;# 
# 7598 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
STATUS equ 0FD8h ;# 
# 7676 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR2 equ 0FD9h ;# 
# 7682 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR2L equ 0FD9h ;# 
# 7688 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR2H equ 0FDAh ;# 
# 7694 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PLUSW2 equ 0FDBh ;# 
# 7700 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PREINC2 equ 0FDCh ;# 
# 7706 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTDEC2 equ 0FDDh ;# 
# 7712 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTINC2 equ 0FDEh ;# 
# 7718 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INDF2 equ 0FDFh ;# 
# 7724 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
BSR equ 0FE0h ;# 
# 7730 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR1 equ 0FE1h ;# 
# 7736 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR1L equ 0FE1h ;# 
# 7742 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR1H equ 0FE2h ;# 
# 7748 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PLUSW1 equ 0FE3h ;# 
# 7754 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PREINC1 equ 0FE4h ;# 
# 7760 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTDEC1 equ 0FE5h ;# 
# 7766 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTINC1 equ 0FE6h ;# 
# 7772 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INDF1 equ 0FE7h ;# 
# 7778 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
WREG equ 0FE8h ;# 
# 7784 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR0 equ 0FE9h ;# 
# 7790 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR0L equ 0FE9h ;# 
# 7796 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
FSR0H equ 0FEAh ;# 
# 7802 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PLUSW0 equ 0FEBh ;# 
# 7808 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PREINC0 equ 0FECh ;# 
# 7814 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTDEC0 equ 0FEDh ;# 
# 7820 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
POSTINC0 equ 0FEEh ;# 
# 7826 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INDF0 equ 0FEFh ;# 
# 7832 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INTCON3 equ 0FF0h ;# 
# 7923 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INTCON2 equ 0FF1h ;# 
# 7999 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
INTCON equ 0FF2h ;# 
# 8135 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PROD equ 0FF3h ;# 
# 8141 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PRODL equ 0FF3h ;# 
# 8147 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PRODH equ 0FF4h ;# 
# 8153 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TABLAT equ 0FF5h ;# 
# 8161 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TBLPTR equ 0FF6h ;# 
# 8167 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TBLPTRL equ 0FF6h ;# 
# 8173 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TBLPTRH equ 0FF7h ;# 
# 8179 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TBLPTRU equ 0FF8h ;# 
# 8187 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PCLAT equ 0FF9h ;# 
# 8194 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PC equ 0FF9h ;# 
# 8200 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PCL equ 0FF9h ;# 
# 8206 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PCLATH equ 0FFAh ;# 
# 8212 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
PCLATU equ 0FFBh ;# 
# 8218 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
STKPTR equ 0FFCh ;# 
# 8293 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TOS equ 0FFDh ;# 
# 8299 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TOSL equ 0FFDh ;# 
# 8305 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TOSH equ 0FFEh ;# 
# 8311 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f2550.h"
TOSU equ 0FFFh ;# 
	FNCALL	_main,_Delay1KTCYx
	FNCALL	_main,_TRIGGERING_SONAR
	FNCALL	_main,___ftmul
	FNCALL	_main,___fttol
	FNCALL	_main,___lldiv
	FNCALL	_main,___lwtoft
	FNCALL	___lwtoft,___ftpack
	FNCALL	___ftmul,___ftpack
	FNROOT	_main
	FNCALL	intlevel2,_isr
	global	intlevel2
	FNROOT	intlevel2
	global	_AVG_DATA1
	global	_AVG_DATA2
	global	_DATA1
	global	_DATA2
	global	_AVG_COUNT1
	global	_AVG_COUNT2
	global	_COUNT1
	global	_COUNT2
	global	_DIFF_TIME1
	global	_DIFF_TIME2
	global	_DIST1
	global	_DIST2
	global	_F1
	global	_F2
	global	_FLAG1
	global	_FLAG2
	global	_NE1
	global	_NE2
	global	_ON
	global	_PE1
	global	_PE2
	global	_THRES1
	global	_THRES2
	global	_TIME1_T1
	global	_TIME1_T2
	global	_TIME2_T1
	global	_TIME2_T2
	global	_TRIG_P1
	global	_TRIG_P2
	global	_ADCON1
_ADCON1	set	0xFC1
	global	_CCP1CON
_CCP1CON	set	0xFBD
	global	_CCP2CON
_CCP2CON	set	0xFBA
	global	_CCPR1H
_CCPR1H	set	0xFBF
	global	_CCPR1L
_CCPR1L	set	0xFBE
	global	_INTCONbits
_INTCONbits	set	0xFF2
	global	_PIE1bits
_PIE1bits	set	0xF9D
	global	_PIE2bits
_PIE2bits	set	0xFA0
	global	_PIR1bits
_PIR1bits	set	0xF9E
	global	_PIR2bits
_PIR2bits	set	0xFA1
	global	_PORTA
_PORTA	set	0xF80
	global	_PORTAbits
_PORTAbits	set	0xF80
	global	_PORTC
_PORTC	set	0xF82
	global	_T1CON
_T1CON	set	0xFCD
	global	_TRISAbits
_TRISAbits	set	0xF92
	global	_TRISCbits
_TRISCbits	set	0xF94
psect	intcode_body,class=CODE,space=0,reloc=2
global __pintcode_body
__pintcode_body:
; #config settings
global __CFG_CPUDIV$OSC1_PLL2
__CFG_CPUDIV$OSC1_PLL2 equ 0x0
global __CFG_PLLDIV$12
__CFG_PLLDIV$12 equ 0x0
global __CFG_USBDIV$2
__CFG_USBDIV$2 equ 0x0
global __CFG_FCMEN$OFF
__CFG_FCMEN$OFF equ 0x0
global __CFG_IESO$OFF
__CFG_IESO$OFF equ 0x0
global __CFG_FOSC$INTOSC_HS
__CFG_FOSC$INTOSC_HS equ 0x0
global __CFG_PWRT$OFF
__CFG_PWRT$OFF equ 0x0
global __CFG_VREGEN$OFF
__CFG_VREGEN$OFF equ 0x0
global __CFG_BORV$3
__CFG_BORV$3 equ 0x0
global __CFG_BOR$OFF
__CFG_BOR$OFF equ 0x0
global __CFG_WDTPS$32768
__CFG_WDTPS$32768 equ 0x0
global __CFG_WDT$OFF
__CFG_WDT$OFF equ 0x0
global __CFG_CCP2MX$ON
__CFG_CCP2MX$ON equ 0x0
global __CFG_PBADEN$ON
__CFG_PBADEN$ON equ 0x0
global __CFG_MCLRE$OFF
__CFG_MCLRE$OFF equ 0x0
global __CFG_LPT1OSC$OFF
__CFG_LPT1OSC$OFF equ 0x0
global __CFG_STVREN$ON
__CFG_STVREN$ON equ 0x0
global __CFG_LVP$OFF
__CFG_LVP$OFF equ 0x0
global __CFG_XINST$OFF
__CFG_XINST$OFF equ 0x0
global __CFG_CP0$OFF
__CFG_CP0$OFF equ 0x0
global __CFG_CP1$OFF
__CFG_CP1$OFF equ 0x0
global __CFG_CP2$OFF
__CFG_CP2$OFF equ 0x0
global __CFG_CP3$OFF
__CFG_CP3$OFF equ 0x0
global __CFG_CPB$OFF
__CFG_CPB$OFF equ 0x0
global __CFG_CPD$OFF
__CFG_CPD$OFF equ 0x0
global __CFG_WRT0$OFF
__CFG_WRT0$OFF equ 0x0
global __CFG_WRT1$OFF
__CFG_WRT1$OFF equ 0x0
global __CFG_WRT2$OFF
__CFG_WRT2$OFF equ 0x0
global __CFG_WRT3$OFF
__CFG_WRT3$OFF equ 0x0
global __CFG_WRTB$OFF
__CFG_WRTB$OFF equ 0x0
global __CFG_WRTC$OFF
__CFG_WRTC$OFF equ 0x0
global __CFG_WRTD$OFF
__CFG_WRTD$OFF equ 0x0
global __CFG_EBTR0$OFF
__CFG_EBTR0$OFF equ 0x0
global __CFG_EBTR1$OFF
__CFG_EBTR1$OFF equ 0x0
global __CFG_EBTR2$OFF
__CFG_EBTR2$OFF equ 0x0
global __CFG_EBTR3$OFF
__CFG_EBTR3$OFF equ 0x0
global __CFG_EBTRB$OFF
__CFG_EBTRB$OFF equ 0x0
	file	"pro.as"
	line	#
psect	cinit,class=CODE,delta=1,reloc=2
global __pcinit
__pcinit:
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssCOMRAM,class=COMRAM,space=1,noexec
global __pbssCOMRAM
__pbssCOMRAM:
	global	_DATA1
_DATA1:
       ds      4
	global	_COUNT1
_COUNT1:
       ds      2
	global	_DIFF_TIME1
_DIFF_TIME1:
       ds      2
	global	_DIST1
_DIST1:
       ds      2
	global	_F1
_F1:
       ds      2
	global	_FLAG1
_FLAG1:
       ds      2
	global	_FLAG2
_FLAG2:
       ds      2
	global	_NE1
	global	_NE1
_NE1:
       ds      2
	global	_PE1
_PE1:
       ds      2
	global	_PE2
	global	_PE2
_PE2:
       ds      2
	global	_THRES1
_THRES1:
       ds      2
	global	_TIME1_T1
_TIME1_T1:
       ds      2
	global	_TIME1_T2
_TIME1_T2:
       ds      2
	global	_TRIG_P1
_TRIG_P1:
       ds      2
	global	_TRIG_P2
_TRIG_P2:
       ds      2
psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
	global	_AVG_DATA1
	global	_AVG_DATA1
_AVG_DATA1:
       ds      4
	global	_AVG_DATA2
	global	_AVG_DATA2
_AVG_DATA2:
       ds      4
	global	_DATA2
	global	_DATA2
_DATA2:
       ds      4
	global	_AVG_COUNT1
	global	_AVG_COUNT1
_AVG_COUNT1:
       ds      2
	global	_AVG_COUNT2
	global	_AVG_COUNT2
_AVG_COUNT2:
       ds      2
	global	_COUNT2
	global	_COUNT2
_COUNT2:
       ds      2
	global	_DIFF_TIME2
	global	_DIFF_TIME2
_DIFF_TIME2:
       ds      2
	global	_DIST2
	global	_DIST2
_DIST2:
       ds      2
	global	_F2
	global	_F2
_F2:
       ds      2
	global	_NE2
	global	_NE2
_NE2:
       ds      2
	global	_ON
	global	_ON
_ON:
       ds      2
	global	_THRES2
	global	_THRES2
_THRES2:
       ds      2
	global	_TIME2_T1
	global	_TIME2_T1
_TIME2_T1:
       ds      2
	global	_TIME2_T2
	global	_TIME2_T2
_TIME2_T2:
       ds      2
	line	#
psect	cinit
; Clear objects allocated to BANK0 (34 bytes)
	global __pbssBANK0
lfsr	0,__pbssBANK0
movlw	34
clear_0:
clrf	postinc0,c
decf	wreg
bnz	clear_0
; Clear objects allocated to COMRAM (32 bytes)
	global __pbssCOMRAM
lfsr	0,__pbssCOMRAM
movlw	32
clear_1:
clrf	postinc0,c
decf	wreg
bnz	clear_1
psect cinit,class=CODE,delta=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:movlb 0
goto _main	;jump to C main() function
psect	cstackCOMRAM,class=COMRAM,space=1,noexec
global __pcstackCOMRAM
__pcstackCOMRAM:
?_Delay1KTCYx:	; 0 bytes @ 0x0
?_isr:	; 0 bytes @ 0x0
??_isr:	; 0 bytes @ 0x0
?_TRIGGERING_SONAR:	; 0 bytes @ 0x0
?_main:	; 0 bytes @ 0x0
	ds   18
??_Delay1KTCYx:	; 0 bytes @ 0x12
??_TRIGGERING_SONAR:	; 0 bytes @ 0x12
	global	?___ftpack
?___ftpack:	; 3 bytes @ 0x12
	global	?___lldiv
?___lldiv:	; 4 bytes @ 0x12
	global	Delay1KTCYx@unit
Delay1KTCYx@unit:	; 1 bytes @ 0x12
	global	___ftpack@arg
___ftpack@arg:	; 3 bytes @ 0x12
	global	___lldiv@dividend
___lldiv@dividend:	; 4 bytes @ 0x12
	ds   3
	global	___ftpack@exp
___ftpack@exp:	; 1 bytes @ 0x15
	ds   1
	global	___ftpack@sign
___ftpack@sign:	; 1 bytes @ 0x16
	global	___lldiv@divisor
___lldiv@divisor:	; 4 bytes @ 0x16
	ds   1
??___ftpack:	; 0 bytes @ 0x17
	ds   3
??___lldiv:	; 0 bytes @ 0x1A
	global	?___lwtoft
?___lwtoft:	; 3 bytes @ 0x1A
	global	___lwtoft@c
___lwtoft@c:	; 2 bytes @ 0x1A
	global	___lldiv@quotient
___lldiv@quotient:	; 4 bytes @ 0x1A
	ds   3
??___lwtoft:	; 0 bytes @ 0x1D
	global	?___ftmul
?___ftmul:	; 3 bytes @ 0x1D
	global	___ftmul@f1
___ftmul@f1:	; 3 bytes @ 0x1D
	ds   1
	global	___lldiv@counter
___lldiv@counter:	; 1 bytes @ 0x1E
	ds   2
	global	___ftmul@f2
___ftmul@f2:	; 3 bytes @ 0x20
	ds   3
??___ftmul:	; 0 bytes @ 0x23
	ds   3
	global	___ftmul@f3_as_product
___ftmul@f3_as_product:	; 3 bytes @ 0x26
	ds   3
	global	___ftmul@exp
___ftmul@exp:	; 1 bytes @ 0x29
	ds   1
	global	___ftmul@cntr
___ftmul@cntr:	; 1 bytes @ 0x2A
	ds   1
	global	___ftmul@sign
___ftmul@sign:	; 1 bytes @ 0x2B
	ds   1
	global	?___fttol
?___fttol:	; 4 bytes @ 0x2C
	global	___fttol@f1
___fttol@f1:	; 3 bytes @ 0x2C
	ds   4
??___fttol:	; 0 bytes @ 0x30
	ds   5
	global	___fttol@sign1
___fttol@sign1:	; 1 bytes @ 0x35
	ds   1
	global	___fttol@lval
___fttol@lval:	; 4 bytes @ 0x36
	ds   4
	global	___fttol@exp1
___fttol@exp1:	; 1 bytes @ 0x3A
	ds   1
??_main:	; 0 bytes @ 0x3B
	ds   4
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         66
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMRAM           95     63      95
;!    BANK0           160      0      34
;!    BANK1           256      0       0
;!    BANK2           256      0       0
;!    BANK3           239      0       0
;!    BANK4           256      0       0
;!    BANK5           256      0       0
;!    BANK6           256      0       0
;!    BANK7           256      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMRAM
;!
;!    _main->___fttol
;!    ___lwtoft->___ftpack
;!    ___fttol->___ftmul
;!    ___ftmul->___lwtoft
;!
;!Critical Paths under _isr in COMRAM
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _isr in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _isr in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _isr in BANK2
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _isr in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK4
;!
;!    None.
;!
;!Critical Paths under _isr in BANK4
;!
;!    None.
;!
;!Critical Paths under _main in BANK5
;!
;!    None.
;!
;!Critical Paths under _isr in BANK5
;!
;!    None.
;!
;!Critical Paths under _main in BANK6
;!
;!    None.
;!
;!Critical Paths under _isr in BANK6
;!
;!    None.
;!
;!Critical Paths under _main in BANK7
;!
;!    None.
;!
;!Critical Paths under _isr in BANK7
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 4, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 4     4      0    2848
;!                                             59 COMRAM     4     4      0
;!                        _Delay1KTCYx
;!                   _TRIGGERING_SONAR
;!                            ___ftmul
;!                            ___fttol
;!                            ___lldiv
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (1) ___lwtoft                                             3     0      3    1090
;!                                             26 COMRAM     3     0      3
;!                           ___ftpack
;! ---------------------------------------------------------------------------------
;! (1) ___lldiv                                             13     5      8     173
;!                                             18 COMRAM    13     5      8
;! ---------------------------------------------------------------------------------
;! (1) ___fttol                                             15    11      4     199
;!                                             44 COMRAM    15    11      4
;!                            ___ftmul (ARG)
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (1) ___ftmul                                             15     9      6    1371
;!                                             29 COMRAM    15     9      6
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftpack                                             8     3      5    1041
;!                                             18 COMRAM     8     3      5
;! ---------------------------------------------------------------------------------
;! (1) _TRIGGERING_SONAR                                     0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _Delay1KTCYx                                          1     1      0      15
;!                                             18 COMRAM     1     1      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (3) _isr                                                 18    18      0       0
;!                                              0 COMRAM    18    18      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _Delay1KTCYx
;!   _TRIGGERING_SONAR
;!   ___ftmul
;!     ___ftpack
;!     ___lwtoft (ARG)
;!       ___ftpack
;!   ___fttol
;!     ___ftmul (ARG)
;!       ___ftpack
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___lwtoft (ARG)
;!       ___ftpack
;!   ___lldiv
;!   ___lwtoft
;!     ___ftpack
;!
;! _isr (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BIGRAM_1           400      0       0      21        0.0%
;!BIGRAM             3EE      0       0      22        0.0%
;!EEDATA             100      0       0       0        0.0%
;!BITBANK7           100      0       0      19        0.0%
;!BANK7              100      0       0      20        0.0%
;!BITBANK6           100      0       0      17        0.0%
;!BANK6              100      0       0      18        0.0%
;!BITBANK5           100      0       0      15        0.0%
;!BANK5              100      0       0      16        0.0%
;!BITBANK4           100      0       0      13        0.0%
;!BANK4              100      0       0      14        0.0%
;!BITBANK2           100      0       0       8        0.0%
;!BANK2              100      0       0       9        0.0%
;!BITBANK1           100      0       0       6        0.0%
;!BANK1              100      0       0       7        0.0%
;!BITBANK3            EF      0       0      12        0.0%
;!BANK3               EF      0       0      10        0.0%
;!BITBANK0            A0      0       0       4        0.0%
;!BANK0               A0      0      22       5       21.3%
;!BITCOMRAM           5F      0       0       0        0.0%
;!COMRAM              5F     3F      5F       1      100.0%
;!BITSFR_5             0      0       0      40        0.0%
;!SFR_5                0      0       0      40        0.0%
;!BITSFR_4             0      0       0      40        0.0%
;!SFR_4                0      0       0      40        0.0%
;!BITSFR_3             0      0       0      40        0.0%
;!SFR_3                0      0       0      40        0.0%
;!BITSFR_2             0      0       0      40        0.0%
;!SFR_2                0      0       0      40        0.0%
;!BITSFR_1             0      0       0      40        0.0%
;!SFR_1                0      0       0      40        0.0%
;!BITSFR               0      0       0      40        0.0%
;!SFR                  0      0       0      40        0.0%
;!STACK                0      0       0       2        0.0%
;!NULL                 0      0       0       0        0.0%
;!ABS                  0      0      81      11        0.0%
;!DATA                 0      0      81       3        0.0%
;!CODE                 0      0       0       0        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 199 in file "D:\Work\R2D2\PIC18F\capture4.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0
;;      Temps:          4       0       0       0       0       0       0       0       0
;;      Totals:         4       0       0       0       0       0       0       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_Delay1KTCYx
;;		_TRIGGERING_SONAR
;;		___ftmul
;;		___fttol
;;		___lldiv
;;		___lwtoft
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	text0,class=CODE,space=0,reloc=2
	file	"D:\Work\R2D2\PIC18F\capture4.c"
	line	199
global __ptext0
__ptext0:
psect	text0
	file	"D:\Work\R2D2\PIC18F\capture4.c"
	line	199
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:
;incstack = 0
	opt	stack 27
	line	201
	
l906:
;capture4.c: 201: ADCON1 = 0xFF;
	setf	((c:4033)),c	;volatile
	line	203
;capture4.c: 203: TRISCbits.TRISC2 = 1;
	bsf	((c:3988)),c,2	;volatile
	line	204
;capture4.c: 204: TRISCbits.TRISC1 = 1;
	bsf	((c:3988)),c,1	;volatile
	line	207
;capture4.c: 207: TRISAbits.TRISA1 = 0;
	bcf	((c:3986)),c,1	;volatile
	line	208
;capture4.c: 208: TRISAbits.TRISA3 = 0;
	bcf	((c:3986)),c,3	;volatile
	line	209
;capture4.c: 209: TRISAbits.TRISA5 = 0;
	bcf	((c:3986)),c,5	;volatile
	line	210
;capture4.c: 210: TRISAbits.TRISA4 = 0;
	bcf	((c:3986)),c,4	;volatile
	line	213
	
l908:
;capture4.c: 213: PORTA = 0x00;
	movlw	low(0)
	movwf	((c:3968)),c	;volatile
	line	214
;capture4.c: 214: PORTC = 0x00;
	movlw	low(0)
	movwf	((c:3970)),c	;volatile
	line	217
;capture4.c: 217: CCP1CON = 0x05;
	movlw	low(05h)
	movwf	((c:4029)),c	;volatile
	line	218
;capture4.c: 218: CCP2CON = 0x05;
	movlw	low(05h)
	movwf	((c:4026)),c	;volatile
	line	220
	
l910:
;capture4.c: 220: INTCONbits.GIE = 1;
	bsf	((c:4082)),c,7	;volatile
	line	221
	
l912:
;capture4.c: 221: INTCONbits.PEIE = 1;
	bsf	((c:4082)),c,6	;volatile
	line	223
	
l914:
;capture4.c: 223: PIE1bits.CCP1IE = 1;
	bsf	((c:3997)),c,2	;volatile
	line	224
	
l916:
;capture4.c: 224: PIR1bits.CCP1IF = 0;
	bcf	((c:3998)),c,2	;volatile
	line	226
	
l918:
;capture4.c: 226: PIE2bits.CCP2IE = 0;
	bcf	((c:4000)),c,0	;volatile
	line	227
	
l920:
;capture4.c: 227: PIR2bits.CCP2IF = 0;
	bcf	((c:4001)),c,0	;volatile
	line	229
;capture4.c: 229: T1CON = 0x21;
	movlw	low(021h)
	movwf	((c:4045)),c	;volatile
	goto	l922
	line	235
;capture4.c: 235: while(1)
	
l108:
	line	238
	
l922:
;capture4.c: 236: {
;capture4.c: 238: if(FLAG1 == 0 && FLAG2 == 0)
	movf	((c:_FLAG1+1)),c,w
	iorwf ((c:_FLAG1)),c,w

	btfss	status,2
	goto	u311
	goto	u310
u311:
	goto	l928
u310:
	
l924:
	movf	((c:_FLAG2+1)),c,w
	iorwf ((c:_FLAG2)),c,w

	btfss	status,2
	goto	u321
	goto	u320
u321:
	goto	l928
u320:
	line	239
	
l926:
;capture4.c: 239: TRIGGERING_SONAR();
	call	_TRIGGERING_SONAR	;wreg free
	goto	l928
	
l109:
	line	312
	
l928:
;capture4.c: 312: if(FLAG1 == 1)
	decf	((c:_FLAG1)),c,w
	iorwf ((c:_FLAG1+1)),c,w

	btfss	status,2
	goto	u331
	goto	u330
u331:
	goto	l922
u330:
	line	314
	
l930:
;capture4.c: 313: {
;capture4.c: 314: COUNT1++;
	infsnz	((c:_COUNT1)),c
	incf	((c:_COUNT1+1)),c
	line	315
	
l932:
;capture4.c: 315: if(COUNT1 > 40 && COUNT1 < 1050)
	movlw	029h
	subwf	((c:_COUNT1)),c,w
	movlw	0
	subwfb	((c:_COUNT1+1)),c,w
	btfss	status,0
	goto	u341
	goto	u340
u341:
	goto	l938
u340:
	
l934:
	movlw	01Ah
	subwf	((c:_COUNT1)),c,w
	movlw	04h
	subwfb	((c:_COUNT1+1)),c,w
	btfsc	status,0
	goto	u351
	goto	u350
u351:
	goto	l938
u350:
	line	316
	
l936:
;capture4.c: 316: {DATA1 = DATA1 + DIST1;}
	movf	((c:_DIST1)),c,w
	addwf	((c:_DATA1)),c,w
	movwf	((c:_DATA1)),c
	movf	((c:_DIST1+1)),c,w
	addwfc	((c:_DATA1+1)),c,w
	movwf	1+((c:_DATA1)),c
	
	movlw	0
	addwfc	((c:_DATA1+2)),c,w
	movwf	2+((c:_DATA1)),c
	
	movlw	0
	addwfc	((c:_DATA1+3)),c,w
	movwf	3+((c:_DATA1)),c
	goto	l946
	line	318
	
l111:
	
l938:
;capture4.c: 318: else if(COUNT1 > 1050 && F1 == 0)
	movlw	01Bh
	subwf	((c:_COUNT1)),c,w
	movlw	04h
	subwfb	((c:_COUNT1+1)),c,w
	btfss	status,0
	goto	u361
	goto	u360
u361:
	goto	l946
u360:
	
l940:
	movf	((c:_F1+1)),c,w
	iorwf ((c:_F1)),c,w

	btfss	status,2
	goto	u371
	goto	u370
u371:
	goto	l946
u370:
	line	320
	
l942:
;capture4.c: 319: {
;capture4.c: 320: THRES1 = DATA1/1000;
	movff	(c:_DATA1),(c:___lldiv@dividend)
	movff	(c:_DATA1+1),(c:___lldiv@dividend+1)
	movff	(c:_DATA1+2),(c:___lldiv@dividend+2)
	movff	(c:_DATA1+3),(c:___lldiv@dividend+3)
	movlw	low(03E8h)
	movwf	((c:___lldiv@divisor)),c
	movlw	high(03E8h)
	movwf	((c:___lldiv@divisor+1)),c
	movlw	low highword(03E8h)
	movwf	((c:___lldiv@divisor+2)),c
	movlw	high highword(03E8h)
	movwf	((c:___lldiv@divisor+3)),c
	call	___lldiv	;wreg free
	movff	0+?___lldiv,??_main+0+0
	movff	1+?___lldiv,??_main+0+0+1
	movff	2+?___lldiv,??_main+0+0+2
	movff	3+?___lldiv,??_main+0+0+3
	
	movff	??_main+0+0,(c:_THRES1)
	movff	??_main+0+1,(c:_THRES1+1)
	line	321
;capture4.c: 321: THRES1 = THRES1 * 0.8;
	movlw	low(float24(0.80000000000000004))
	movwf	((c:___ftmul@f2)),c
	movlw	high(float24(0.80000000000000004))
	movwf	((c:___ftmul@f2+1)),c
	movlw	low highword(float24(0.80000000000000004))
	movwf	((c:___ftmul@f2+2)),c

	movff	(c:_THRES1),(c:___lwtoft@c)
	movff	(c:_THRES1+1),(c:___lwtoft@c+1)
	call	___lwtoft	;wreg free
	movff	0+?___lwtoft,(c:___ftmul@f1)
	movff	1+?___lwtoft,(c:___ftmul@f1+1)
	movff	2+?___lwtoft,(c:___ftmul@f1+2)
	call	___ftmul	;wreg free
	movff	0+?___ftmul,(c:___fttol@f1)
	movff	1+?___ftmul,(c:___fttol@f1+1)
	movff	2+?___ftmul,(c:___fttol@f1+2)
	call	___fttol	;wreg free
	movff	0+?___fttol,??_main+0+0
	movff	1+?___fttol,??_main+0+0+1
	movff	2+?___fttol,??_main+0+0+2
	movff	3+?___fttol,??_main+0+0+3
	
	movff	??_main+0+0,(c:_THRES1)
	movff	??_main+0+1,(c:_THRES1+1)
	line	322
	
l944:
;capture4.c: 322: F1 = 1;
	movlw	high(01h)
	movwf	((c:_F1+1)),c
	movlw	low(01h)
	movwf	((c:_F1)),c
	goto	l946
	line	323
	
l113:
	goto	l946
	line	326
	
l112:
	
l946:
;capture4.c: 323: }
;capture4.c: 326: if(DIST1 < 20 && COUNT1 > 1050)
	movlw	014h
	subwf	((c:_DIST1)),c,w
	movlw	0
	subwfb	((c:_DIST1+1)),c,w
	btfsc	status,0
	goto	u381
	goto	u380
u381:
	goto	l960
u380:
	
l948:
	movlw	01Bh
	subwf	((c:_COUNT1)),c,w
	movlw	04h
	subwfb	((c:_COUNT1+1)),c,w
	btfss	status,0
	goto	u391
	goto	u390
u391:
	goto	l960
u390:
	line	329
	
l950:
;capture4.c: 327: {
;capture4.c: 329: PORTAbits.RA4 = 1;
	bsf	((c:3968)),c,4	;volatile
	line	331
	
l952:
;capture4.c: 331: Delay1KTCYx(50);
	movlw	(032h)&0ffh
	
	call	_Delay1KTCYx
	line	332
	
l954:
;capture4.c: 332: PORTAbits.RA4 = 0;
	bcf	((c:3968)),c,4	;volatile
	line	333
	
l956:
;capture4.c: 333: PORTAbits.RA1 = 0;
	bcf	((c:3968)),c,1	;volatile
	line	334
	
l958:
;capture4.c: 334: FLAG1=0;
	movlw	high(0)
	movwf	((c:_FLAG1+1)),c
	movlw	low(0)
	movwf	((c:_FLAG1)),c
	goto	l960
	line	335
	
l114:
	line	336
	
l960:
;capture4.c: 335: }
;capture4.c: 336: PIE1bits.CCP1IE = 1;
	bsf	((c:3997)),c,2	;volatile
	line	337
	
l962:
;capture4.c: 337: TRIGGERING_SONAR();
	call	_TRIGGERING_SONAR	;wreg free
	goto	l922
	line	339
	
l110:
	goto	l922
	line	341
	
l115:
	line	235
	goto	l922
	
l116:
	line	342
	
l117:
	global	start
	goto	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,88
	global	___lwtoft

;; *************** function ___lwtoft *****************
;; Defined at:
;;		line 28 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lwtoft.c"
;; Parameters:    Size  Location     Type
;;  c               2   26[COMRAM] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3   26[COMRAM] float 
;; Registers used:
;;		wreg, status,2, status,0, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         3       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0
;;      Totals:         3       0       0       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lwtoft.c"
	line	28
global __ptext1
__ptext1:
psect	text1
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lwtoft.c"
	line	28
	global	__size_of___lwtoft
	__size_of___lwtoft	equ	__end_of___lwtoft-___lwtoft
	
___lwtoft:
;incstack = 0
	opt	stack 27
	line	30
	
l876:
	movff	(c:___lwtoft@c),(c:___ftpack@arg)
	movff	(c:___lwtoft@c+1),(c:___ftpack@arg+1)
	clrf	((c:___ftpack@arg+2)),c
	movlw	low(08Eh)
	movwf	((c:___ftpack@exp)),c
	movlw	low(0)
	movwf	((c:___ftpack@sign)),c
	call	___ftpack	;wreg free
	movff	0+?___ftpack,(c:?___lwtoft)
	movff	1+?___ftpack,(c:?___lwtoft+1)
	movff	2+?___ftpack,(c:?___lwtoft+2)
	goto	l666
	
l878:
	line	31
	
l666:
	return
	opt stack 0
GLOBAL	__end_of___lwtoft
	__end_of___lwtoft:
	signat	___lwtoft,4219
	global	___lldiv

;; *************** function ___lldiv *****************
;; Defined at:
;;		line 8 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lldiv.c"
;; Parameters:    Size  Location     Type
;;  dividend        4   18[COMRAM] unsigned long 
;;  divisor         4   22[COMRAM] unsigned long 
;; Auto vars:     Size  Location     Type
;;  quotient        4   26[COMRAM] unsigned long 
;;  counter         1   30[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   18[COMRAM] unsigned long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         8       0       0       0       0       0       0       0       0
;;      Locals:         5       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0
;;      Totals:        13       0       0       0       0       0       0       0       0
;;Total ram usage:       13 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lldiv.c"
	line	8
global __ptext2
__ptext2:
psect	text2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\lldiv.c"
	line	8
	global	__size_of___lldiv
	__size_of___lldiv	equ	__end_of___lldiv-___lldiv
	
___lldiv:
;incstack = 0
	opt	stack 28
	line	14
	
l854:
	movlw	low(0)
	movwf	((c:___lldiv@quotient)),c
	movlw	high(0)
	movwf	((c:___lldiv@quotient+1)),c
	movlw	low highword(0)
	movwf	((c:___lldiv@quotient+2)),c
	movlw	high highword(0)
	movwf	((c:___lldiv@quotient+3)),c
	line	15
	
l856:
	movf	((c:___lldiv@divisor+3)),c,w
	iorwf ((c:___lldiv@divisor)),c,w
	iorwf ((c:___lldiv@divisor+1)),c,w
	iorwf ((c:___lldiv@divisor+2)),c,w

	btfsc	status,2
	goto	u261
	goto	u260
u261:
	goto	l576
u260:
	line	16
	
l858:
	movlw	low(01h)
	movwf	((c:___lldiv@counter)),c
	line	17
	goto	l862
	
l578:
	line	18
	
l860:
	bcf	status,0
	rlcf	((c:___lldiv@divisor)),c
	rlcf	((c:___lldiv@divisor+1)),c
	rlcf	((c:___lldiv@divisor+2)),c
	rlcf	((c:___lldiv@divisor+3)),c
	line	19
	incf	((c:___lldiv@counter)),c
	goto	l862
	line	20
	
l577:
	line	17
	
l862:
	
	btfss	((c:___lldiv@divisor+3)),c,(31)&7
	goto	u271
	goto	u270
u271:
	goto	l860
u270:
	goto	l864
	
l579:
	goto	l864
	line	21
	
l580:
	line	22
	
l864:
	bcf	status,0
	rlcf	((c:___lldiv@quotient)),c
	rlcf	((c:___lldiv@quotient+1)),c
	rlcf	((c:___lldiv@quotient+2)),c
	rlcf	((c:___lldiv@quotient+3)),c
	line	23
	
l866:
	movf	((c:___lldiv@divisor)),c,w
	subwf	((c:___lldiv@dividend)),c,w
	movf	((c:___lldiv@divisor+1)),c,w
	subwfb	((c:___lldiv@dividend+1)),c,w
	movf	((c:___lldiv@divisor+2)),c,w
	subwfb	((c:___lldiv@dividend+2)),c,w
	movf	((c:___lldiv@divisor+3)),c,w
	subwfb	((c:___lldiv@dividend+3)),c,w
	btfss	status,0
	goto	u281
	goto	u280
u281:
	goto	l872
u280:
	line	24
	
l868:
	movf	((c:___lldiv@divisor)),c,w
	subwf	((c:___lldiv@dividend)),c
	movf	((c:___lldiv@divisor+1)),c,w
	subwfb	((c:___lldiv@dividend+1)),c
	movf	((c:___lldiv@divisor+2)),c,w
	subwfb	((c:___lldiv@dividend+2)),c
	movf	((c:___lldiv@divisor+3)),c,w
	subwfb	((c:___lldiv@dividend+3)),c
	line	25
	
l870:
	bsf	(0+(0/8)+(c:___lldiv@quotient)),c,(0)&7
	goto	l872
	line	26
	
l581:
	line	27
	
l872:
	bcf	status,0
	rrcf	((c:___lldiv@divisor+3)),c
	rrcf	((c:___lldiv@divisor+2)),c
	rrcf	((c:___lldiv@divisor+1)),c
	rrcf	((c:___lldiv@divisor)),c
	line	28
	
l874:
	decfsz	((c:___lldiv@counter)),c
	
	goto	l864
	goto	l576
	
l582:
	line	29
	
l576:
	line	30
	movff	(c:___lldiv@quotient),(c:?___lldiv)
	movff	(c:___lldiv@quotient+1),(c:?___lldiv+1)
	movff	(c:___lldiv@quotient+2),(c:?___lldiv+2)
	movff	(c:___lldiv@quotient+3),(c:?___lldiv+3)
	line	31
	
l583:
	return
	opt stack 0
GLOBAL	__end_of___lldiv
	__end_of___lldiv:
	signat	___lldiv,8316
	global	___fttol

;; *************** function ___fttol *****************
;; Defined at:
;;		line 44 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\fttol.c"
;; Parameters:    Size  Location     Type
;;  f1              3   44[COMRAM] float 
;; Auto vars:     Size  Location     Type
;;  lval            4   54[COMRAM] unsigned long 
;;  exp1            1   58[COMRAM] unsigned char 
;;  sign1           1   53[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   44[COMRAM] long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         4       0       0       0       0       0       0       0       0
;;      Locals:         6       0       0       0       0       0       0       0       0
;;      Temps:          5       0       0       0       0       0       0       0       0
;;      Totals:        15       0       0       0       0       0       0       0       0
;;Total ram usage:       15 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\fttol.c"
	line	44
global __ptext3
__ptext3:
psect	text3
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\fttol.c"
	line	44
	global	__size_of___fttol
	__size_of___fttol	equ	__end_of___fttol-___fttol
	
___fttol:
;incstack = 0
	opt	stack 28
	line	49
	
l808:
	movff	(c:___fttol@f1+2),??___fttol+0+0
	clrf	(??___fttol+0+0+1)&0ffh,c
	clrf	(??___fttol+0+0+2)&0ffh,c
	rlcf	((c:___fttol@f1+1)),c,w
	rlcf	(??___fttol+0+0)&0ffh,c
	bnc	u181
	bsf	(??___fttol+0+0+1)&0ffh,c,0
u181:
	movf	(??___fttol+0+0),c,w
	movwf	((c:___fttol@exp1)),c
	tstfsz	((c:___fttol@exp1))&0ffh
	goto	u191
	goto	u190
u191:
	goto	l814
u190:
	line	50
	
l810:
	movlw	low(0)
	movwf	((c:?___fttol)),c
	movlw	high(0)
	movwf	((c:?___fttol+1)),c
	movlw	low highword(0)
	movwf	((c:?___fttol+2)),c
	movlw	high highword(0)
	movwf	((c:?___fttol+3)),c
	goto	l537
	
l812:
	goto	l537
	
l536:
	line	51
	
l814:
	movlw	(017h)&0ffh
	movwf	(??___fttol+0+0)&0ffh,c
	movff	(c:___fttol@f1),??___fttol+1+0
	movff	(c:___fttol@f1+1),??___fttol+1+0+1
	movff	(c:___fttol@f1+2),??___fttol+1+0+2
	incf	((??___fttol+0+0)),c,w
	movwf	(??___fttol+4+0)&0ffh,c
	goto	u200
u205:
	bcf	status,0
	rrcf	(??___fttol+1+2),c
	rrcf	(??___fttol+1+1),c
	rrcf	(??___fttol+1+0),c
u200:
	decfsz	(??___fttol+4+0)&0ffh,c
	goto	u205
	movf	(??___fttol+1+0),c,w
	movwf	((c:___fttol@sign1)),c
	line	52
	
l816:
	bsf	(0+(15/8)+(c:___fttol@f1)),c,(15)&7
	line	53
	
l818:
	movlw	low(0FFFFh)
	andwf	((c:___fttol@f1)),c
	movlw	high(0FFFFh)
	andwf	((c:___fttol@f1+1)),c
	movlw	low highword(0FFFFh)
	andwf	((c:___fttol@f1+2)),c

	line	54
	
l820:
	movf	((c:___fttol@f1)),c,w
	movwf	((c:___fttol@lval)),c
	movf	((c:___fttol@f1+1)),c,w
	movwf	1+((c:___fttol@lval)),c
	
	movf	((c:___fttol@f1+2)),c,w
	movwf	2+((c:___fttol@lval)),c
	
	clrf	3+((c:___fttol@lval)),c
	line	55
	
l822:
	movlw	(08Eh)&0ffh
	subwf	((c:___fttol@exp1)),c
	line	56
	
l824:
	btfss	((c:___fttol@exp1)),c,7
	goto	u211
	goto	u210
u211:
	goto	l836
u210:
	line	57
	
l826:
	movf	((c:___fttol@exp1)),c,w
	xorlw	80h
	movwf	(??___fttol+0+0)&0ffh,c
	movlw	(-15)&0ffh
	xorlw	80h
	subwf	(??___fttol+0+0),c,w
	btfsc	status,0
	goto	u221
	goto	u220
u221:
	goto	l832
u220:
	line	58
	
l828:
	movlw	low(0)
	movwf	((c:?___fttol)),c
	movlw	high(0)
	movwf	((c:?___fttol+1)),c
	movlw	low highword(0)
	movwf	((c:?___fttol+2)),c
	movlw	high highword(0)
	movwf	((c:?___fttol+3)),c
	goto	l537
	
l830:
	goto	l537
	
l539:
	goto	l832
	line	59
	
l540:
	line	60
	
l832:
	bcf	status,0
	rrcf	((c:___fttol@lval+3)),c
	rrcf	((c:___fttol@lval+2)),c
	rrcf	((c:___fttol@lval+1)),c
	rrcf	((c:___fttol@lval)),c
	line	61
	
l834:
	incfsz	((c:___fttol@exp1)),c
	
	goto	l832
	goto	l846
	
l541:
	line	62
	goto	l846
	
l538:
	line	63
	
l836:
	movlw	(018h-1)
	cpfsgt	((c:___fttol@exp1)),c
	goto	u231
	goto	u230
u231:
	goto	l844
u230:
	line	64
	
l838:
	movlw	low(0)
	movwf	((c:?___fttol)),c
	movlw	high(0)
	movwf	((c:?___fttol+1)),c
	movlw	low highword(0)
	movwf	((c:?___fttol+2)),c
	movlw	high highword(0)
	movwf	((c:?___fttol+3)),c
	goto	l537
	
l840:
	goto	l537
	
l543:
	line	65
	goto	l844
	
l545:
	line	66
	
l842:
	bcf	status,0
	rlcf	((c:___fttol@lval)),c
	rlcf	((c:___fttol@lval+1)),c
	rlcf	((c:___fttol@lval+2)),c
	rlcf	((c:___fttol@lval+3)),c
	line	67
	decf	((c:___fttol@exp1)),c
	goto	l844
	line	68
	
l544:
	line	65
	
l844:
	tstfsz	((c:___fttol@exp1)),c
	goto	u241
	goto	u240
u241:
	goto	l842
u240:
	goto	l846
	
l546:
	goto	l846
	line	69
	
l542:
	line	70
	
l846:
	movf	((c:___fttol@sign1)),c,w
	btfsc	status,2
	goto	u251
	goto	u250
u251:
	goto	l850
u250:
	line	71
	
l848:
	comf	((c:___fttol@lval+3)),c
	comf	((c:___fttol@lval+2)),c
	comf	((c:___fttol@lval+1)),c
	negf	((c:___fttol@lval)),c
	movlw	0
	addwfc	((c:___fttol@lval+1)),c
	addwfc	((c:___fttol@lval+2)),c
	addwfc	((c:___fttol@lval+3)),c
	goto	l850
	
l547:
	line	72
	
l850:
	movff	(c:___fttol@lval),(c:?___fttol)
	movff	(c:___fttol@lval+1),(c:?___fttol+1)
	movff	(c:___fttol@lval+2),(c:?___fttol+2)
	movff	(c:___fttol@lval+3),(c:?___fttol+3)
	goto	l537
	
l852:
	line	73
	
l537:
	return
	opt stack 0
GLOBAL	__end_of___fttol
	__end_of___fttol:
	signat	___fttol,4220
	global	___ftmul

;; *************** function ___ftmul *****************
;; Defined at:
;;		line 62 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\ftmul.c"
;; Parameters:    Size  Location     Type
;;  f1              3   29[COMRAM] float 
;;  f2              3   32[COMRAM] float 
;; Auto vars:     Size  Location     Type
;;  f3_as_produc    3   38[COMRAM] unsigned um
;;  sign            1   43[COMRAM] unsigned char 
;;  cntr            1   42[COMRAM] unsigned char 
;;  exp             1   41[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   29[COMRAM] float 
;; Registers used:
;;		wreg, status,2, status,0, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         6       0       0       0       0       0       0       0       0
;;      Locals:         6       0       0       0       0       0       0       0       0
;;      Temps:          3       0       0       0       0       0       0       0       0
;;      Totals:        15       0       0       0       0       0       0       0       0
;;Total ram usage:       15 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text4,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\ftmul.c"
	line	62
global __ptext4
__ptext4:
psect	text4
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\ftmul.c"
	line	62
	global	__size_of___ftmul
	__size_of___ftmul	equ	__end_of___ftmul-___ftmul
	
___ftmul:
;incstack = 0
	opt	stack 27
	line	67
	
l760:
	movff	(c:___ftmul@f1+2),??___ftmul+0+0
	clrf	(??___ftmul+0+0+1)&0ffh,c
	clrf	(??___ftmul+0+0+2)&0ffh,c
	rlcf	((c:___ftmul@f1+1)),c,w
	rlcf	(??___ftmul+0+0)&0ffh,c
	bnc	u121
	bsf	(??___ftmul+0+0+1)&0ffh,c,0
u121:
	movf	(??___ftmul+0+0),c,w
	movwf	((c:___ftmul@exp)),c
	tstfsz	((c:___ftmul@exp))&0ffh
	goto	u131
	goto	u130
u131:
	goto	l766
u130:
	line	68
	
l762:
	movlw	low(float24(0.0000000000000000))
	movwf	((c:?___ftmul)),c
	movlw	high(float24(0.0000000000000000))
	movwf	((c:?___ftmul+1)),c
	movlw	low highword(float24(0.0000000000000000))
	movwf	((c:?___ftmul+2)),c

	goto	l517
	
l764:
	goto	l517
	
l516:
	line	69
	
l766:
	movff	(c:___ftmul@f2+2),??___ftmul+0+0
	clrf	(??___ftmul+0+0+1)&0ffh,c
	clrf	(??___ftmul+0+0+2)&0ffh,c
	rlcf	((c:___ftmul@f2+1)),c,w
	rlcf	(??___ftmul+0+0)&0ffh,c
	bnc	u141
	bsf	(??___ftmul+0+0+1)&0ffh,c,0
u141:
	movf	(??___ftmul+0+0),c,w
	movwf	((c:___ftmul@sign)),c
	tstfsz	((c:___ftmul@sign))&0ffh
	goto	u151
	goto	u150
u151:
	goto	l772
u150:
	line	70
	
l768:
	movlw	low(float24(0.0000000000000000))
	movwf	((c:?___ftmul)),c
	movlw	high(float24(0.0000000000000000))
	movwf	((c:?___ftmul+1)),c
	movlw	low highword(float24(0.0000000000000000))
	movwf	((c:?___ftmul+2)),c

	goto	l517
	
l770:
	goto	l517
	
l518:
	line	71
	
l772:
	movf	((c:___ftmul@sign)),c,w
	addlw	low(07Bh)
	addwf	((c:___ftmul@exp)),c
	line	72
	
l774:
	movff	0+2+(c:___ftmul@f1),(c:___ftmul@sign)
	line	73
	movf	(0+2+(c:___ftmul@f2)),c,w
	xorwf	((c:___ftmul@sign)),c
	line	74
	movlw	(080h)&0ffh
	andwf	((c:___ftmul@sign)),c
	line	75
	
l776:
	bsf	(0+(15/8)+(c:___ftmul@f1)),c,(15)&7
	line	77
	
l778:
	bsf	(0+(15/8)+(c:___ftmul@f2)),c,(15)&7
	line	78
	
l780:
	movlw	low(0FFFFh)
	andwf	((c:___ftmul@f2)),c
	movlw	high(0FFFFh)
	andwf	((c:___ftmul@f2+1)),c
	movlw	low highword(0FFFFh)
	andwf	((c:___ftmul@f2+2)),c

	line	79
	
l782:
	movlw	low(0)
	movwf	((c:___ftmul@f3_as_product)),c
	movlw	high(0)
	movwf	((c:___ftmul@f3_as_product+1)),c
	movlw	low highword(0)
	movwf	((c:___ftmul@f3_as_product+2)),c

	line	134
	
l784:
	movlw	low(07h)
	movwf	((c:___ftmul@cntr)),c
	goto	l786
	line	135
	
l519:
	line	136
	
l786:
	
	btfss	((c:___ftmul@f1)),c,(0)&7
	goto	u161
	goto	u160
u161:
	goto	l790
u160:
	line	137
	
l788:
	movf	((c:___ftmul@f2)),c,w
	addwf	((c:___ftmul@f3_as_product)),c
	movf	((c:___ftmul@f2+1)),c,w
	addwfc	((c:___ftmul@f3_as_product+1)),c
	movf	((c:___ftmul@f2+2)),c,w
	addwfc	((c:___ftmul@f3_as_product+2)),c

	goto	l790
	
l520:
	line	138
	
l790:
	bcf	status,0
	rrcf	((c:___ftmul@f1+2)),c
	rrcf	((c:___ftmul@f1+1)),c
	rrcf	((c:___ftmul@f1)),c
	line	139
	bcf	status,0
	rlcf	((c:___ftmul@f2)),c
	rlcf	((c:___ftmul@f2+1)),c
	rlcf	((c:___ftmul@f2+2)),c
	line	140
	
l792:
	decfsz	((c:___ftmul@cntr)),c
	
	goto	l786
	goto	l794
	
l521:
	line	143
	
l794:
	movlw	low(09h)
	movwf	((c:___ftmul@cntr)),c
	goto	l796
	line	144
	
l522:
	line	145
	
l796:
	
	btfss	((c:___ftmul@f1)),c,(0)&7
	goto	u171
	goto	u170
u171:
	goto	l800
u170:
	line	146
	
l798:
	movf	((c:___ftmul@f2)),c,w
	addwf	((c:___ftmul@f3_as_product)),c
	movf	((c:___ftmul@f2+1)),c,w
	addwfc	((c:___ftmul@f3_as_product+1)),c
	movf	((c:___ftmul@f2+2)),c,w
	addwfc	((c:___ftmul@f3_as_product+2)),c

	goto	l800
	
l523:
	line	147
	
l800:
	bcf	status,0
	rrcf	((c:___ftmul@f1+2)),c
	rrcf	((c:___ftmul@f1+1)),c
	rrcf	((c:___ftmul@f1)),c
	line	148
	bcf	status,0
	rrcf	((c:___ftmul@f3_as_product+2)),c
	rrcf	((c:___ftmul@f3_as_product+1)),c
	rrcf	((c:___ftmul@f3_as_product)),c
	line	149
	
l802:
	decfsz	((c:___ftmul@cntr)),c
	
	goto	l796
	goto	l804
	
l524:
	line	156
	
l804:
	movff	(c:___ftmul@f3_as_product),(c:___ftpack@arg)
	movff	(c:___ftmul@f3_as_product+1),(c:___ftpack@arg+1)
	movff	(c:___ftmul@f3_as_product+2),(c:___ftpack@arg+2)
	movff	(c:___ftmul@exp),(c:___ftpack@exp)
	movff	(c:___ftmul@sign),(c:___ftpack@sign)
	call	___ftpack	;wreg free
	movff	0+?___ftpack,(c:?___ftmul)
	movff	1+?___ftpack,(c:?___ftmul+1)
	movff	2+?___ftpack,(c:?___ftmul+2)
	goto	l517
	
l806:
	line	157
	
l517:
	return
	opt stack 0
GLOBAL	__end_of___ftmul
	__end_of___ftmul:
	signat	___ftmul,8315
	global	___ftpack

;; *************** function ___ftpack *****************
;; Defined at:
;;		line 62 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\float.c"
;; Parameters:    Size  Location     Type
;;  arg             3   18[COMRAM] unsigned um
;;  exp             1   21[COMRAM] unsigned char 
;;  sign            1   22[COMRAM] unsigned char 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3   18[COMRAM] float 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         5       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0
;;      Temps:          3       0       0       0       0       0       0       0       0
;;      Totals:         8       0       0       0       0       0       0       0       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		___ftmul
;;		___lwtoft
;; This function uses a non-reentrant model
;;
psect	text5,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\float.c"
	line	62
global __ptext5
__ptext5:
psect	text5
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\common\float.c"
	line	62
	global	__size_of___ftpack
	__size_of___ftpack	equ	__end_of___ftpack-___ftpack
	
___ftpack:
;incstack = 0
	opt	stack 27
	line	64
	
l700:
	movf	((c:___ftpack@exp)),c,w
	btfsc	status,2
	goto	u11
	goto	u10
u11:
	goto	l704
u10:
	
l702:
	movf	((c:___ftpack@arg)),c,w
	iorwf	((c:___ftpack@arg+1)),c,w
	iorwf	((c:___ftpack@arg+2)),c,w
	btfss	status,2
	goto	u21
	goto	u20
u21:
	goto	l710
u20:
	goto	l704
	
l432:
	line	65
	
l704:
	movlw	low(float24(0.0000000000000000))
	movwf	((c:?___ftpack)),c
	movlw	high(float24(0.0000000000000000))
	movwf	((c:?___ftpack+1)),c
	movlw	low highword(float24(0.0000000000000000))
	movwf	((c:?___ftpack+2)),c

	goto	l433
	
l706:
	goto	l433
	
l430:
	line	66
	goto	l710
	
l435:
	line	67
	
l708:
	incf	((c:___ftpack@exp)),c
	line	68
	bcf	status,0
	rrcf	((c:___ftpack@arg+2)),c
	rrcf	((c:___ftpack@arg+1)),c
	rrcf	((c:___ftpack@arg)),c
	goto	l710
	line	69
	
l434:
	line	66
	
l710:
	movlw	low(0FE0000h)
	andwf	((c:___ftpack@arg)),c,w
	movwf	(??___ftpack+0+0)&0ffh,c
	movlw	0
	andwf	((c:___ftpack@arg+1)),c,w
	movwf	1+(??___ftpack+0+0)&0ffh,c
	movlw	0FEh
	andwf	((c:___ftpack@arg+2)),c,w
	movwf	2+(??___ftpack+0+0)&0ffh,c

	movf	(??___ftpack+0+0),c,w
	iorwf	(??___ftpack+0+1),c,w
	iorwf	(??___ftpack+0+2),c,w
	btfss	status,2
	goto	u31
	goto	u30
u31:
	goto	l708
u30:
	goto	l716
	
l436:
	line	70
	goto	l716
	
l438:
	line	71
	
l712:
	incf	((c:___ftpack@exp)),c
	line	72
	
l714:
	movlw	low(01h)
	addwf	((c:___ftpack@arg)),c
	movlw	high(01h)
	addwfc	((c:___ftpack@arg+1)),c
	movlw	low highword(01h)
	addwfc	((c:___ftpack@arg+2)),c

	line	73
	bcf	status,0
	rrcf	((c:___ftpack@arg+2)),c
	rrcf	((c:___ftpack@arg+1)),c
	rrcf	((c:___ftpack@arg)),c
	goto	l716
	line	74
	
l437:
	line	70
	
l716:
	movlw	low(0FF0000h)
	andwf	((c:___ftpack@arg)),c,w
	movwf	(??___ftpack+0+0)&0ffh,c
	movlw	0
	andwf	((c:___ftpack@arg+1)),c,w
	movwf	1+(??___ftpack+0+0)&0ffh,c
	movlw	0FFh
	andwf	((c:___ftpack@arg+2)),c,w
	movwf	2+(??___ftpack+0+0)&0ffh,c

	movf	(??___ftpack+0+0),c,w
	iorwf	(??___ftpack+0+1),c,w
	iorwf	(??___ftpack+0+2),c,w
	btfss	status,2
	goto	u41
	goto	u40
u41:
	goto	l712
u40:
	goto	l720
	
l439:
	line	75
	goto	l720
	
l441:
	line	76
	
l718:
	decf	((c:___ftpack@exp)),c
	line	77
	bcf	status,0
	rlcf	((c:___ftpack@arg)),c
	rlcf	((c:___ftpack@arg+1)),c
	rlcf	((c:___ftpack@arg+2)),c
	goto	l720
	line	78
	
l440:
	line	75
	
l720:
	
	btfss	((c:___ftpack@arg+1)),c,(15)&7
	goto	u51
	goto	u50
u51:
	goto	l718
u50:
	
l442:
	line	79
	
	btfsc	((c:___ftpack@exp)),c,(0)&7
	goto	u61
	goto	u60
u61:
	goto	l724
u60:
	line	80
	
l722:
	bcf	(0+(15/8)+(c:___ftpack@arg)),c,(15)&7
	goto	l724
	
l443:
	line	81
	
l724:
	bcf status,0
	rrcf	((c:___ftpack@exp)),c

	line	82
	movf	((c:___ftpack@exp)),c,w
	iorwf	((c:___ftpack@arg+2)),c

	line	83
	
l726:
	movf	((c:___ftpack@sign)),c,w
	btfsc	status,2
	goto	u71
	goto	u70
u71:
	goto	l730
u70:
	line	84
	
l728:
	bsf	(0+(23/8)+(c:___ftpack@arg)),c,(23)&7
	goto	l730
	
l444:
	line	85
	
l730:
	movff	(c:___ftpack@arg),(c:?___ftpack)
	movff	(c:___ftpack@arg+1),(c:?___ftpack+1)
	movff	(c:___ftpack@arg+2),(c:?___ftpack+2)
	goto	l433
	
l732:
	line	86
	
l433:
	return
	opt stack 0
GLOBAL	__end_of___ftpack
	__end_of___ftpack:
	signat	___ftpack,12411
	global	_TRIGGERING_SONAR

;; *************** function _TRIGGERING_SONAR *****************
;; Defined at:
;;		line 188 in file "D:\Work\R2D2\PIC18F\capture4.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0
;;      Totals:         0       0       0       0       0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text6,class=CODE,space=0,reloc=2
	file	"D:\Work\R2D2\PIC18F\capture4.c"
	line	188
global __ptext6
__ptext6:
psect	text6
	file	"D:\Work\R2D2\PIC18F\capture4.c"
	line	188
	global	__size_of_TRIGGERING_SONAR
	__size_of_TRIGGERING_SONAR	equ	__end_of_TRIGGERING_SONAR-_TRIGGERING_SONAR
	
_TRIGGERING_SONAR:
;incstack = 0
	opt	stack 28
	line	190
	
l734:
;capture4.c: 190: PORTAbits.RA3 = 1;
	bsf	((c:3968)),c,3	;volatile
	line	191
	
l736:
;capture4.c: 191: for(TRIG_P1 = 0 ; TRIG_P1 < 5 ; TRIG_P1++);
	movlw	high(0)
	movwf	((c:_TRIG_P1+1)),c
	movlw	low(0)
	movwf	((c:_TRIG_P1)),c
	
l738:
	movlw	05h
	subwf	((c:_TRIG_P1)),c,w
	movlw	0
	subwfb	((c:_TRIG_P1+1)),c,w
	btfss	status,0
	goto	u81
	goto	u80
u81:
	goto	l742
u80:
	goto	l102
	
l740:
	goto	l102
	
l101:
	
l742:
	infsnz	((c:_TRIG_P1)),c
	incf	((c:_TRIG_P1+1)),c
	
l744:
	movlw	05h
	subwf	((c:_TRIG_P1)),c,w
	movlw	0
	subwfb	((c:_TRIG_P1+1)),c,w
	btfss	status,0
	goto	u91
	goto	u90
u91:
	goto	l742
u90:
	
l102:
	line	192
;capture4.c: 192: PORTAbits.RA3 = 0;
	bcf	((c:3968)),c,3	;volatile
	line	194
;capture4.c: 194: PORTAbits.RA5 = 1;
	bsf	((c:3968)),c,5	;volatile
	line	195
	
l746:
;capture4.c: 195: for(TRIG_P2 = 0 ; TRIG_P2 < 5 ; TRIG_P2++);
	movlw	high(0)
	movwf	((c:_TRIG_P2+1)),c
	movlw	low(0)
	movwf	((c:_TRIG_P2)),c
	
l748:
	movlw	05h
	subwf	((c:_TRIG_P2)),c,w
	movlw	0
	subwfb	((c:_TRIG_P2+1)),c,w
	btfss	status,0
	goto	u101
	goto	u100
u101:
	goto	l752
u100:
	goto	l104
	
l750:
	goto	l104
	
l103:
	
l752:
	infsnz	((c:_TRIG_P2)),c
	incf	((c:_TRIG_P2+1)),c
	
l754:
	movlw	05h
	subwf	((c:_TRIG_P2)),c,w
	movlw	0
	subwfb	((c:_TRIG_P2+1)),c,w
	btfss	status,0
	goto	u111
	goto	u110
u111:
	goto	l752
u110:
	
l104:
	line	196
;capture4.c: 196: PORTAbits.RA5 = 0;
	bcf	((c:3968)),c,5	;volatile
	line	197
	
l105:
	return
	opt stack 0
GLOBAL	__end_of_TRIGGERING_SONAR
	__end_of_TRIGGERING_SONAR:
	signat	_TRIGGERING_SONAR,88
	global	_Delay1KTCYx

;; *************** function _Delay1KTCYx *****************
;; Defined at:
;;		line 8 in file "C:\Program Files (x86)\Microchip\xc8\v1.33\sources\pic18\d1ktcyx.c"
;; Parameters:    Size  Location     Type
;;  unit            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  unit            1   18[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         0       0       0       0       0       0       0       0       0
;;      Locals:         1       0       0       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0       0       0
;;      Totals:         1       0       0       0       0       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text7,class=CODE,space=0,reloc=2
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\pic18\d1ktcyx.c"
	line	8
global __ptext7
__ptext7:
psect	text7
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\sources\pic18\d1ktcyx.c"
	line	8
	global	__size_of_Delay1KTCYx
	__size_of_Delay1KTCYx	equ	__end_of_Delay1KTCYx-_Delay1KTCYx
	
_Delay1KTCYx:
;incstack = 0
	opt	stack 28
;Delay1KTCYx@unit stored from wreg
	movwf	((c:Delay1KTCYx@unit)),c
	line	10
	
l343:
	line	11
	
l756:
	movlw	250
u407:
	nop
decfsz	wreg,f
	goto	u407

	line	12
	
l758:
	decfsz	((c:Delay1KTCYx@unit)),c
	
	goto	l343
	goto	l345
	
l344:
	line	13
	
l345:
	return
	opt stack 0
GLOBAL	__end_of_Delay1KTCYx
	__end_of_Delay1KTCYx:
	signat	_Delay1KTCYx,4216
	global	_isr

;; *************** function _isr *****************
;; Defined at:
;;		line 117 in file "D:\Work\R2D2\PIC18F\capture4.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5   BANK6   BANK7
;;      Params:         0       0       0       0       0       0       0       0       0
;;      Locals:         0       0       0       0       0       0       0       0       0
;;      Temps:         18       0       0       0       0       0       0       0       0
;;      Totals:        18       0       0       0       0       0       0       0       0
;;Total ram usage:       18 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 2
;; This function uses a non-reentrant model
;;
psect	intcode,class=CODE,space=0,reloc=2
global __pintcode
__pintcode:
psect	intcode
	file	"D:\Work\R2D2\PIC18F\capture4.c"
	line	117
	global	__size_of_isr
	__size_of_isr	equ	__end_of_isr-_isr
	
_isr:
;incstack = 0
	opt	stack 27
	movff	pclat+0,??_isr+4
	movff	pclat+1,??_isr+5
	movff	fsr0l+0,??_isr+6
	global	int_func
	call	int_func,f	;refresh shadow registers
psect	intcode_body
int_func:

	pop	; remove dummy address from shadow register refresh
	movff	fsr0h+0,??_isr+7
	movff	fsr1l+0,??_isr+8
	movff	fsr1h+0,??_isr+9
	movff	fsr2l+0,??_isr+10
	movff	fsr2h+0,??_isr+11
	movff	prodl+0,??_isr+12
	movff	prodh+0,??_isr+13
	movff	tblptrl+0,??_isr+14
	movff	tblptrh+0,??_isr+15
	movff	tblptru+0,??_isr+16
	movff	tablat+0,??_isr+17
	line	121
	
i2l880:
;capture4.c: 121: if(PIR1bits.CCP1IF)
	btfss	((c:3998)),c,2	;volatile
	goto	i2u29_41
	goto	i2u29_40
i2u29_41:
	goto	i2l98
i2u29_40:
	line	124
	
i2l882:
;capture4.c: 122: {
;capture4.c: 124: if(PE1==1)
	decf	((c:_PE1)),c,w
	iorwf ((c:_PE1+1)),c,w

	btfss	status,2
	goto	i2u30_41
	goto	i2u30_40
i2u30_41:
	goto	i2l892
i2u30_40:
	line	126
	
i2l884:
;capture4.c: 125: {
;capture4.c: 126: FLAG1 = 0;
	movlw	high(0)
	movwf	((c:_FLAG1+1)),c
	movlw	low(0)
	movwf	((c:_FLAG1)),c
	line	127
	
i2l886:
;capture4.c: 127: TIME1_T1 = (CCPR1L | (CCPR1H<<8));
	movf	((c:4031)),c,w	;volatile
	movwf	(??_isr+0+0+1)&0ffh,c
	clrf	(??_isr+0+0)&0ffh,c
	movf	((c:4030)),c,w	;volatile
	movwf	(??_isr+2+0)&0ffh,c
	clrf	(??_isr+2+0+1)&0ffh,c

	movf	(??_isr+0+0),c,w
	iorwf	(??_isr+2+0),c,w
	
	movwf	((c:_TIME1_T1)),c
	movf	(??_isr+0+1),c,w
	iorwf	(??_isr+2+1),c,w
	movwf	1+((c:_TIME1_T1)),c
	line	128
	
i2l888:
;capture4.c: 128: PE1 = 0;
	movlw	high(0)
	movwf	((c:_PE1+1)),c
	movlw	low(0)
	movwf	((c:_PE1)),c
	line	129
	
i2l890:
;capture4.c: 129: CCP1CON=0x04;
	movlw	low(04h)
	movwf	((c:4029)),c	;volatile
	line	130
;capture4.c: 130: }
	goto	i2l904
	line	131
	
i2l96:
	line	133
	
i2l892:
;capture4.c: 131: else
;capture4.c: 132: {
;capture4.c: 133: PE1 = 1;
	movlw	high(01h)
	movwf	((c:_PE1+1)),c
	movlw	low(01h)
	movwf	((c:_PE1)),c
	line	134
	
i2l894:
;capture4.c: 134: PIE1bits.CCP1IE=0;
	bcf	((c:3997)),c,2	;volatile
	line	135
	
i2l896:
;capture4.c: 135: PIE2bits.CCP2IE=0;
	bcf	((c:4000)),c,0	;volatile
	line	136
	
i2l898:
;capture4.c: 136: TIME1_T2 = (CCPR1L | (CCPR1H<<8));
	movf	((c:4031)),c,w	;volatile
	movwf	(??_isr+0+0+1)&0ffh,c
	clrf	(??_isr+0+0)&0ffh,c
	movf	((c:4030)),c,w	;volatile
	movwf	(??_isr+2+0)&0ffh,c
	clrf	(??_isr+2+0+1)&0ffh,c

	movf	(??_isr+0+0),c,w
	iorwf	(??_isr+2+0),c,w
	
	movwf	((c:_TIME1_T2)),c
	movf	(??_isr+0+1),c,w
	iorwf	(??_isr+2+1),c,w
	movwf	1+((c:_TIME1_T2)),c
	line	137
	
i2l900:
;capture4.c: 137: DIFF_TIME1 = TIME1_T2 - TIME1_T1 + 1;
	movff	(c:_TIME1_T1),??_isr+0+0
	movff	(c:_TIME1_T1+1),??_isr+0+0+1
	comf	(??_isr+0+0),c
	comf	(??_isr+0+1),c
	infsnz	(??_isr+0+0),c
	incf	(??_isr+0+1),c
	movf	((c:_TIME1_T2)),c,w
	addwf	(??_isr+0+0),c
	movf	((c:_TIME1_T2+1)),c,w
	addwfc	(??_isr+0+1),c
	movlw	low(01h)
	addwf	(??_isr+0+0),c,w
	
	movwf	((c:_DIFF_TIME1)),c
	movlw	high(01h)
	addwfc	(??_isr+0+1),c,w
	movwf	1+((c:_DIFF_TIME1)),c
	line	139
;capture4.c: 139: CCP1CON = 0x05;
	movlw	low(05h)
	movwf	((c:4029)),c	;volatile
	line	142
	
i2l902:
;capture4.c: 142: DIST1 = DIFF_TIME1;
	movff	(c:_DIFF_TIME1),(c:_DIST1)
	movff	(c:_DIFF_TIME1+1),(c:_DIST1+1)
	line	143
;capture4.c: 143: FLAG1 = 1;
	movlw	high(01h)
	movwf	((c:_FLAG1+1)),c
	movlw	low(01h)
	movwf	((c:_FLAG1)),c
	goto	i2l904
	line	148
	
i2l97:
	line	149
	
i2l904:
;capture4.c: 148: }
;capture4.c: 149: PIR1bits.CCP1IF=0;
	bcf	((c:3998)),c,2	;volatile
	goto	i2l98
	line	150
	
i2l95:
	line	186
	
i2l98:
	movff	??_isr+17,tablat+0
	movff	??_isr+16,tblptru+0
	movff	??_isr+15,tblptrh+0
	movff	??_isr+14,tblptrl+0
	movff	??_isr+13,prodh+0
	movff	??_isr+12,prodl+0
	movff	??_isr+11,fsr2h+0
	movff	??_isr+10,fsr2l+0
	movff	??_isr+9,fsr1h+0
	movff	??_isr+8,fsr1l+0
	movff	??_isr+7,fsr0h+0
	movff	??_isr+6,fsr0l+0
	movff	??_isr+5,pclat+1
	movff	??_isr+4,pclat+0
	retfie f
	opt stack 0
GLOBAL	__end_of_isr
	__end_of_isr:
	signat	_isr,88
	GLOBAL	__activetblptr
__activetblptr	EQU	0
	psect	intsave_regs,class=BIGRAM,space=1,noexec
	PSECT	rparam,class=COMRAM,space=1,noexec
	GLOBAL	__Lrparam
	FNCONF	rparam,??,?
GLOBAL	__Lparam, __Hparam
GLOBAL	__Lrparam, __Hrparam
__Lparam	EQU	__Lrparam
__Hparam	EQU	__Hrparam
	end
