;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn1
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================



;================================================
;DEBUGGER TABLE
;================================================

;------------------------------------------------
;REG VALUES     R0  R1  R2  R3  R4  R5  R6  R7
;------------------------------------------------
;Pre-loop       0   0   0   0   0   0   0   1168  ;@ exec: 2      
;iteration 01   0   0   12  0   0   0   6   1168
;iteration 02   0   12  12  0   0   0   6   1168
;iteration 03   0   12  12  0   0   0   5   1168
;iteration 04   0   12  12  0   0   0   5   1168
;iteration 05   0   12  12  0   0   0   5   1168
;iteration 06   0   24  12  0   0   0   5   1168
;iteration 07   0   24  12  0   0   0   4   1168
;iteration 08   0   24  12  0   0   0   4   1168    ;
;iteration 09   0   36  12  0   0   0   4   1168
;iteration 10   0   36  12  0   0   0   3   1168
;iteration 11   0   36  12  0   0   0   3   1168
;iteration 12   0   48  12  0   0   0   3   1168
;iteration 13   0   48  12  0   0   0   2   1168
;iteration 14   0   48  12  0   0   0   2   1168
;iteration 15   0   60  12  0   0   0   2   1168
;iteration 16   0   60  12  0   0   0   1   1168
;iteration 17   0   60  12  0   0   0   1   1168
;iteration 18   0   72  12  0   0   0   1   1168
;iteration 19   0   72  12  0   0   0   0   1168
;iteration 20   0   72  12  0   0   0   0   1168

;total execuations: 21






;=================================================
;ACTUAL PROGRAM
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

