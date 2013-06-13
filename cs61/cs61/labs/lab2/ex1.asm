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
LD R0,DEC_65
LD R1, HEX_41

HALT

;---------------
;data
;---------------
DEC_65 .fill #65
HEX_41 .fill x41

.end
