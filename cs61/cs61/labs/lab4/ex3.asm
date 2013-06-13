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
LD R3, dec_9        ;R3 = 9 (counter)

;populate the array

;store special case, 2^0 = 1
ADD R1,R1,#1    ;R1 = 1
STR R1,R2,#0    ;Store R1 at ptr(r2)
ADD R2,R2,#1    ;incremeent pointer

loop1
    STR R1,R2,#0    ;Store R1 at ptr(r2)
    ADD R1,R1,R1    ;multiple value by 2
    ADD R2,R2,#1    ;increment ptr
    ADD R3,R3,#-1   ;decrement counter
    BRp loop1       ;if(i<10) go to start of loop
loop1_end

LD R1,data_ptr_7value   ;load 7 element of array into R1
LDR R2,R1,#0        ;Load R2 with 7th element of array


HALT                ;end program

;---------------
;data
;---------------
array_1 .fill x4000     ;sets location of the array
dec_0 .fill #0          ;declares dec_0 = 0
dec_9 .fill #9          ;declares dec_9 = 9
data_ptr .fill x4000    ;declares data_ptr = x4000
data_ptr_7value .fill x4006 ;declares varibale = x4006




.end
