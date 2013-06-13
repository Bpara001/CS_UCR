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

LD R0,HEX_61
LD R1,HEX_1A

loop1_start
    OUT
    ADD R1,R1,#-1
    BRp loop1_start
loop1_end

HALT

;---------------
;data
;---------------
HEX_61.fill x61
HEX_1A .fill x1A
.orig x4000
.fill #65
.fill x41

.end
