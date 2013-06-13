;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab2
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================


.orig x3000
;=======================
;MAIN FUNCTION
;=======================
LD R3, DEC_65
LD R4, HEX_41
LD R5, DEC_65
LD R6, HEX_41

LDR R3, R5, #0
LDR R4, R6, #0

ADD R3, R3, #1
ADD R4, R4, #1

STR R3, R5, #0
STR R4, R6, #0

HALT

;---------------
;data
;---------------
DEC_65 .fill x4000
HEX_41 .fill x4001

.ORIG x4000
.fill #65
.fill x41

.end
