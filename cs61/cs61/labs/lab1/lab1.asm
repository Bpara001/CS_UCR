;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab 1
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

.orig x3000

;=======================
;instructions
;=======================
LD R1, dec_0
LD R2, dec_12
LD R6, dec_6

FOR_LOOP1
    ADD R1,R1,R2
    ADD R6,R6,#-1
    BRp FOR_LOOP1
END_FOR_LOOP_1
HALT

;=======================
;data block
;=======================
dec_0 .fill #0
dec_6 .fill #6
dec_12 .fill #12

.end

