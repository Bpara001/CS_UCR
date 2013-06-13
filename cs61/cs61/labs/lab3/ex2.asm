;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab4
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
array_1 .blkw #10
LD R1, dec_0;
LD R2, data_ptr
LD R3, dec_10

loop1
    STR R1,R2,#0
    ADD R1,R1,#1    ;increment value
    ADD R2,R2,#1    ;increment ptr
    ADD R3,R3,#-1   ;decrement counter
    BRp loop1
loop1_end

LD R1,data_ptr_7value
LDR R2,R1,#0


HALT

;---------------
;data
;---------------
array_1 .fill x4000
dec_0 .fill #0
dec_10 .fill #10
data_ptr .fill x4000
data_ptr_7value .fill x4006




.end
