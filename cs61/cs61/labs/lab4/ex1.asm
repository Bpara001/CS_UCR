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
array_1 .blkw #10   ;reserve a space of 10 for array1
LD R1, dec_0        ;R1 = 0
LD R2, data_ptr     ;R2 = x4000 (ptr)
LD R3, dec_10       ;R3 = 10 (counter)

;populate loop
loop1               ;for(int i=0;i<10;i++)
    STR R1,R2,#0    ;store R1 at R2 ptr
    ADD R1,R1,#1    ;increment value
    ADD R2,R2,#1    ;increment ptr
    ADD R3,R3,#-1   ;decrement counter
    BRp loop1       ;if i<10 redo loop
loop1_end

LD R1,data_ptr_7value   ;load the 7th element
LDR R2,R1,#0            ;store the value into R2


HALT

;---------------
;data
;---------------
array_1 .fill x4000     ;sets location of the array
dec_0 .fill #0          ;declares dec_0 = 0
dec_10 .fill #10
data_ptr .fill x4000
data_ptr_7value .fill x4006




.end
