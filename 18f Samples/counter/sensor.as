opt subtitle "Microchip Technology Omniscient Code Generator (Lite mode) build 59893"

opt pagewidth 120

	opt lm

	processor	18F4520
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
# 49 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PORTA equ 0F80h ;# 
# 269 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PORTB equ 0F81h ;# 
# 447 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PORTC equ 0F82h ;# 
# 631 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PORTD equ 0F83h ;# 
# 772 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PORTE equ 0F84h ;# 
# 1100 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LATA equ 0F89h ;# 
# 1232 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LATB equ 0F8Ah ;# 
# 1364 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LATC equ 0F8Bh ;# 
# 1496 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LATD equ 0F8Ch ;# 
# 1628 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LATE equ 0F8Dh ;# 
# 1730 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TRISA equ 0F92h ;# 
# 1735 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
DDRA equ 0F92h ;# 
# 1951 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TRISB equ 0F93h ;# 
# 1956 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
DDRB equ 0F93h ;# 
# 2172 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TRISC equ 0F94h ;# 
# 2177 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
DDRC equ 0F94h ;# 
# 2393 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TRISD equ 0F95h ;# 
# 2398 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
DDRD equ 0F95h ;# 
# 2614 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TRISE equ 0F96h ;# 
# 2619 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
DDRE equ 0F96h ;# 
# 2777 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
OSCTUNE equ 0F9Bh ;# 
# 2841 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PIE1 equ 0F9Dh ;# 
# 2920 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PIR1 equ 0F9Eh ;# 
# 2999 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
IPR1 equ 0F9Fh ;# 
# 3078 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PIE2 equ 0FA0h ;# 
# 3143 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PIR2 equ 0FA1h ;# 
# 3208 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
IPR2 equ 0FA2h ;# 
# 3273 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
EECON1 equ 0FA6h ;# 
# 3338 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
EECON2 equ 0FA7h ;# 
# 3344 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
EEDATA equ 0FA8h ;# 
# 3350 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
EEADR equ 0FA9h ;# 
# 3356 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
RCSTA equ 0FABh ;# 
# 3361 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
RCSTA1 equ 0FABh ;# 
# 3565 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TXSTA equ 0FACh ;# 
# 3570 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TXSTA1 equ 0FACh ;# 
# 3862 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TXREG equ 0FADh ;# 
# 3867 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TXREG1 equ 0FADh ;# 
# 3873 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
RCREG equ 0FAEh ;# 
# 3878 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
RCREG1 equ 0FAEh ;# 
# 3884 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SPBRG equ 0FAFh ;# 
# 3889 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SPBRG1 equ 0FAFh ;# 
# 3895 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SPBRGH equ 0FB0h ;# 
# 3901 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
T3CON equ 0FB1h ;# 
# 4014 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR3 equ 0FB2h ;# 
# 4020 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR3L equ 0FB2h ;# 
# 4026 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR3H equ 0FB3h ;# 
# 4032 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CMCON equ 0FB4h ;# 
# 4127 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CVRCON equ 0FB5h ;# 
# 4205 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ECCP1AS equ 0FB6h ;# 
# 4210 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ECCPAS equ 0FB6h ;# 
# 4366 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PWM1CON equ 0FB7h ;# 
# 4371 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ECCP1DEL equ 0FB7h ;# 
# 4503 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
BAUDCON equ 0FB8h ;# 
# 4508 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
BAUDCTL equ 0FB8h ;# 
# 4682 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCP2CON equ 0FBAh ;# 
# 4760 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR2 equ 0FBBh ;# 
# 4766 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR2L equ 0FBBh ;# 
# 4772 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR2H equ 0FBCh ;# 
# 4778 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCP1CON equ 0FBDh ;# 
# 4874 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR1 equ 0FBEh ;# 
# 4880 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR1L equ 0FBEh ;# 
# 4886 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
CCPR1H equ 0FBFh ;# 
# 4892 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADCON2 equ 0FC0h ;# 
# 4962 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADCON1 equ 0FC1h ;# 
# 5052 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADCON0 equ 0FC2h ;# 
# 5174 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADRES equ 0FC3h ;# 
# 5180 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADRESL equ 0FC3h ;# 
# 5186 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
ADRESH equ 0FC4h ;# 
# 5192 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SSPCON2 equ 0FC5h ;# 
# 5286 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SSPCON1 equ 0FC6h ;# 
# 5355 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SSPSTAT equ 0FC7h ;# 
# 5594 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SSPADD equ 0FC8h ;# 
# 5600 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
SSPBUF equ 0FC9h ;# 
# 5606 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
T2CON equ 0FCAh ;# 
# 5703 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PR2 equ 0FCBh ;# 
# 5708 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
MEMCON equ 0FCBh ;# 
# 5812 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR2 equ 0FCCh ;# 
# 5818 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
T1CON equ 0FCDh ;# 
# 5922 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR1 equ 0FCEh ;# 
# 5928 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR1L equ 0FCEh ;# 
# 5934 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR1H equ 0FCFh ;# 
# 5940 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
RCON equ 0FD0h ;# 
# 6072 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
WDTCON equ 0FD1h ;# 
# 6099 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
HLVDCON equ 0FD2h ;# 
# 6104 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
LVDCON equ 0FD2h ;# 
# 6368 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
OSCCON equ 0FD3h ;# 
# 6450 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
T0CON equ 0FD5h ;# 
# 6532 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR0 equ 0FD6h ;# 
# 6538 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR0L equ 0FD6h ;# 
# 6544 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TMR0H equ 0FD7h ;# 
# 6550 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
STATUS equ 0FD8h ;# 
# 6628 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR2 equ 0FD9h ;# 
# 6634 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR2L equ 0FD9h ;# 
# 6640 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR2H equ 0FDAh ;# 
# 6646 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PLUSW2 equ 0FDBh ;# 
# 6652 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PREINC2 equ 0FDCh ;# 
# 6658 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTDEC2 equ 0FDDh ;# 
# 6664 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTINC2 equ 0FDEh ;# 
# 6670 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INDF2 equ 0FDFh ;# 
# 6676 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
BSR equ 0FE0h ;# 
# 6682 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR1 equ 0FE1h ;# 
# 6688 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR1L equ 0FE1h ;# 
# 6694 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR1H equ 0FE2h ;# 
# 6700 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PLUSW1 equ 0FE3h ;# 
# 6706 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PREINC1 equ 0FE4h ;# 
# 6712 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTDEC1 equ 0FE5h ;# 
# 6718 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTINC1 equ 0FE6h ;# 
# 6724 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INDF1 equ 0FE7h ;# 
# 6730 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
WREG equ 0FE8h ;# 
# 6741 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR0 equ 0FE9h ;# 
# 6747 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR0L equ 0FE9h ;# 
# 6753 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
FSR0H equ 0FEAh ;# 
# 6759 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PLUSW0 equ 0FEBh ;# 
# 6765 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PREINC0 equ 0FECh ;# 
# 6771 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTDEC0 equ 0FEDh ;# 
# 6777 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
POSTINC0 equ 0FEEh ;# 
# 6783 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INDF0 equ 0FEFh ;# 
# 6789 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INTCON3 equ 0FF0h ;# 
# 6880 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INTCON2 equ 0FF1h ;# 
# 6949 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
INTCON equ 0FF2h ;# 
# 7085 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PROD equ 0FF3h ;# 
# 7091 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PRODL equ 0FF3h ;# 
# 7097 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PRODH equ 0FF4h ;# 
# 7103 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TABLAT equ 0FF5h ;# 
# 7111 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TBLPTR equ 0FF6h ;# 
# 7117 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TBLPTRL equ 0FF6h ;# 
# 7123 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TBLPTRH equ 0FF7h ;# 
# 7129 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TBLPTRU equ 0FF8h ;# 
# 7137 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PCLAT equ 0FF9h ;# 
# 7144 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PC equ 0FF9h ;# 
# 7150 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PCL equ 0FF9h ;# 
# 7156 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PCLATH equ 0FFAh ;# 
# 7162 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
PCLATU equ 0FFBh ;# 
# 7168 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
STKPTR equ 0FFCh ;# 
# 7241 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TOS equ 0FFDh ;# 
# 7247 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TOSL equ 0FFDh ;# 
# 7253 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TOSH equ 0FFEh ;# 
# 7259 "C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
TOSU equ 0FFFh ;# 
	FNCALL	_main,_delay
	FNROOT	_main
	global	_ADCON1
_ADCON1	set	0xFC1
	global	_PORTAbits
_PORTAbits	set	0xF80
	global	_TRISA
_TRISA	set	0xF92
	global	_TRISD
_TRISD	set	0xF95
psect	text0,class=CODE,space=0,reloc=2
; #config settings
	file	"C:\Program Files (x86)\Microchip\xc8\v1.33\include\pic18f4520.h"
	line	2391
global __ptext0
__ptext0:
global __CFG_WDT$OFF
__CFG_WDT$OFF equ 0x0
	file	"sensor.as"
	line	#
psect	cinit,class=CODE,delta=1,reloc=2
global __pcinit
__pcinit:
global start_initialization
start_initialization:

global __initialization
__initialization:
psect cinit,class=CODE,delta=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:movlb 0
goto _main	;jump to C main() function
psect	cstackCOMRAM,class=COMRAM,space=1,noexec
global __pcstackCOMRAM
__pcstackCOMRAM:
?_delay:	; 0 bytes @ 0x0
?_main:	; 0 bytes @ 0x0
	global	delay@x
delay@x:	; 2 bytes @ 0x0
	ds   2
??_delay:	; 0 bytes @ 0x2
	ds   1
	global	delay@y
delay@y:	; 2 bytes @ 0x3
	ds   2
	global	delay@z
delay@z:	; 2 bytes @ 0x5
	ds   2
??_main:	; 0 bytes @ 0x7
	global	main@count
main@count:	; 2 bytes @ 0x7
	ds   2
	global	main@Flag
main@Flag:	; 1 bytes @ 0x9
	ds   1
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         0
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMRAM          127     10      10
;!    BANK0           128      0       0
;!    BANK1           256      0       0
;!    BANK2           256      0       0
;!    BANK3           256      0       0
;!    BANK4           256      0       0
;!    BANK5           256      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMRAM
;!
;!    _main->_delay
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _main in BANK2
;!
;!    None.
;!
;!Critical Paths under _main in BANK3
;!
;!    None.
;!
;!Critical Paths under _main in BANK4
;!
;!    None.
;!
;!Critical Paths under _main in BANK5
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 3     3      0     128
;!                                              7 COMRAM     3     3      0
;!                              _delay
;! ---------------------------------------------------------------------------------
;! (1) _delay                                                7     5      2     128
;!                                              0 COMRAM     7     5      2
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _delay
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMRAM           7F      0       0       0        0.0%
;!EEDATA             100      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMRAM              7F      A       A       1        7.9%
;!STACK                0      0       0       2        0.0%
;!DATA                 0      0       0       3        0.0%
;!BITBANK0            80      0       0       4        0.0%
;!BANK0               80      0       0       5        0.0%
;!BITBANK1           100      0       0       6        0.0%
;!BANK1              100      0       0       7        0.0%
;!BITBANK2           100      0       0       8        0.0%
;!BANK2              100      0       0       9        0.0%
;!BITBANK3           100      0       0      10        0.0%
;!BANK3              100      0       0      11        0.0%
;!BITBANK4           100      0       0      12        0.0%
;!BANK4              100      0       0      13        0.0%
;!BANK5              100      0       0      14        0.0%
;!ABS                  0      0       0      15        0.0%
;!BITBANK5           100      0       0      16        0.0%
;!BIGRAM             5FF      0       0      17        0.0%
;!BITSFR               0      0       0      40        0.0%
;!SFR                  0      0       0      40        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 9 in file "D:\Work\18f\counter\code.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  count           2    7[COMRAM] int 
;;  Flag            1    9[COMRAM] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5
;;      Params:         0       0       0       0       0       0       0
;;      Locals:         3       0       0       0       0       0       0
;;      Temps:          0       0       0       0       0       0       0
;;      Totals:         3       0       0       0       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_delay
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	text0
psect	text0
	file	"D:\Work\18f\counter\code.c"
	line	9
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:
;incstack = 0
	opt	stack 30
	line	11
	
l618:
;code.c: 11: char Flag = 0;
	movlw	low(0)
	movwf	((c:main@Flag)),c
	line	12
;code.c: 12: int count = 0;
	movlw	high(0)
	movwf	((c:main@count+1)),c
	movlw	low(0)
	movwf	((c:main@count)),c
	line	13
	
l620:
;code.c: 13: ADCON1= 0xFF;
	setf	((c:4033)),c	;volatile
	line	14
	
l622:
;code.c: 14: TRISA = 0xFF;
	setf	((c:3986)),c	;volatile
	line	15
;code.c: 15: TRISD = 0x00;
	movlw	low(0)
	movwf	((c:3989)),c	;volatile
	goto	l624
	line	17
;code.c: 17: while(1)
	
l13:
	line	19
	
l624:
;code.c: 18: {
;code.c: 19: if(PORTAbits.RA1 == 1)
	btfss	((c:3968)),c,1	;volatile
	goto	u41
	goto	u40
u41:
	goto	l624
u40:
	line	21
	
l626:
;code.c: 20: {
;code.c: 21: delay(1000);
	movlw	high(03E8h)
	movwf	((c:delay@x+1)),c
	movlw	low(03E8h)
	movwf	((c:delay@x)),c
	call	_delay	;wreg free
	line	22
	
l628:
;code.c: 22: if(PORTAbits.RA2 == 1 && PORTAbits.RA1 == 1)
	btfss	((c:3968)),c,2	;volatile
	goto	u51
	goto	u50
u51:
	goto	l624
u50:
	
l630:
	btfss	((c:3968)),c,1	;volatile
	goto	u61
	goto	u60
u61:
	goto	l624
u60:
	line	24
	
l632:
;code.c: 23: {
;code.c: 24: count++;
	infsnz	((c:main@count)),c
	incf	((c:main@count+1)),c
	line	25
	
l634:
;code.c: 25: delay(2000);
	movlw	high(07D0h)
	movwf	((c:delay@x+1)),c
	movlw	low(07D0h)
	movwf	((c:delay@x)),c
	call	_delay	;wreg free
	goto	l624
	line	26
	
l15:
	goto	l624
	line	27
	
l14:
	goto	l624
	line	28
	
l16:
	line	17
	goto	l624
	
l17:
	line	31
	
l18:
	global	start
	goto	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,88
	global	_delay

;; *************** function _delay *****************
;; Defined at:
;;		line 33 in file "D:\Work\18f\counter\code.c"
;; Parameters:    Size  Location     Type
;;  x               2    0[COMRAM] int 
;; Auto vars:     Size  Location     Type
;;  z               2    5[COMRAM] int 
;;  y               2    3[COMRAM] int 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMRAM   BANK0   BANK1   BANK2   BANK3   BANK4   BANK5
;;      Params:         2       0       0       0       0       0       0
;;      Locals:         4       0       0       0       0       0       0
;;      Temps:          1       0       0       0       0       0       0
;;      Totals:         7       0       0       0       0       0       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,class=CODE,space=0,reloc=2
	line	33
global __ptext1
__ptext1:
psect	text1
	file	"D:\Work\18f\counter\code.c"
	line	33
	global	__size_of_delay
	__size_of_delay	equ	__end_of_delay-_delay
	
_delay:
;incstack = 0
	opt	stack 30
	line	35
	
l602:
;code.c: 35: for(int y = 0 ; y < x ; y++)
	movlw	high(0)
	movwf	((c:delay@y+1)),c
	movlw	low(0)
	movwf	((c:delay@y)),c
	goto	l616
	line	36
	
l22:
	
l604:
;code.c: 36: for(int z = 0 ; z < 2000 ; z++);
	movlw	high(0)
	movwf	((c:delay@z+1)),c
	movlw	low(0)
	movwf	((c:delay@z)),c
	
l606:
	movf	((c:delay@z+1)),c,w
	xorlw	80h
	addlw	-((07h)^80h)
	movlw	0D0h
	btfsc	status,2
	subwf	((c:delay@z)),c,w
	btfss	status,0
	goto	u11
	goto	u10
u11:
	goto	l610
u10:
	goto	l614
	
l608:
	goto	l614
	
l23:
	
l610:
	infsnz	((c:delay@z)),c
	incf	((c:delay@z+1)),c
	
l612:
	movf	((c:delay@z+1)),c,w
	xorlw	80h
	addlw	-((07h)^80h)
	movlw	0D0h
	btfsc	status,2
	subwf	((c:delay@z)),c,w
	btfss	status,0
	goto	u21
	goto	u20
u21:
	goto	l610
u20:
	goto	l614
	
l24:
	line	35
	
l614:
	infsnz	((c:delay@y)),c
	incf	((c:delay@y+1)),c
	goto	l616
	
l21:
	
l616:
	movf	((c:delay@y+1)),c,w
	xorlw	80h
	movwf	(??_delay+0+0)&0ffh,c
	movf	((c:delay@x)),c,w
	subwf	((c:delay@y)),c,w
	movf	((c:delay@x+1)),c,w
	xorlw	80h
	subwfb	(??_delay+0+0)&0ffh,c,w
	btfss	status,0
	goto	u31
	goto	u30
u31:
	goto	l604
u30:
	goto	l26
	
l25:
	line	38
	
l26:
	return
	opt stack 0
GLOBAL	__end_of_delay
	__end_of_delay:
	signat	_delay,4216
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
