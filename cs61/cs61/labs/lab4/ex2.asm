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

;reinitialize values
LD R1,dec_48        ;R1 = 48
LD R2, data_ptr     ;R2 = x4000 (ptr)
LD R3, dec_10       ;R3 = 10 (counter)

;output loop
loop2               ;for(int i =0; i<10;i++)
    LDR R0,R2,#0    ;load value at ptr into R0
    ADD R0,R0,R1    ;counvert R0 into ascii
    OUT             ;output to screen
    LD R0,ascii_space   ;load space into R0
    OUT             ;output to screen
    ADD R2,R2,#1    ;increment ptr
    ADD R3,R3,#-1   ;decrement counter
    BRp loop2       ;if i<10, redo loop
loop2_end

HALT                ;end program

;---------------
;data
;---------------
array_1 .fill x4000     ;sets location of the array
dec_0 .fill #0          ;declares dec_0 = 0
dec_10 .fill #10
data_ptr .fill x4000
data_ptr_7value .fill x4006
dec_48 .fill #48
ascii_space .fill #32




.end
