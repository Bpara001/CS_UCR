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
LDI R3, new_DEC_65
LDI R4, new_HEX_41

ADD R3,R3,#1
ADD R4,R4,#1

HALT

;---------------
;data
;---------------
new_DEC_65 .fill x4000
new_HEX_41 .fill x4001

.orig x4000
.fill #65
.fill x41

.end
