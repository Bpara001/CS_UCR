;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn1
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;-------------------------------------------------
;REG VALUES     R0  R1    R2  R3  R4  R5  R6  R7
;-------------------------------------------------
;Pre-loop       0   32767 0   0   0   0   0   1168
;iteration 01   0   0     0   0   0   0   0   1168
;iteration 02   0   0     12  0   0   0   0   1168
;iteration 03   0   0     12  0   0   0   6   1168
;iteration 04   0   12    12  0   0   0   6   1168
;iteration 05   0   12    12  0   0   0   5   1168
;iteration 06   0   12    12  0   0   0   5   1168
;iteration 07   0   24    12  0   0   0   5   1168
;iteration 08   0   24    12  0   0   0   4   1168
;iteration 09   0   24    12  0   0   0   4   1168
;iteration 10   0   36    12  0   0   0   4   1168
;iteration 11   0   36    12  0   0   0   3   1168
;iteration 12   0   36    12  0   0   0   3   1168
;iteration 13   0   48    12  0   0   0   3   1168
;iteration 14   0   48    12  0   0   0   2   1168
;iteration 15   0   48    12  0   0   0   2   1168
;iteration 16   0   60    12  0   0   0   2   1168
;iteration 17   0   60    12  0   0   0   1   1168
;iteration 18   0   60    12  0   0   0   1   1168
;iteration 19   0   72    12  0   0   0   1   1168
;iteration 20   0   72    12  0   0   0   0   1168
;iteration 21   0   72    12  0   0   0   0   1168
;End of program 0   72    12  0   0   0   0   DEC_0
;-------------------------------------------------

.orig x3000         ;Program begins here
;--------------------
;Instructions
;-------------------
LD R1, DEC_0        ;R1 <-- 6
LD R2, DEC_12       ;R2 <-- 12
LD R6, DEC_6        ;R3 <-- 0

FOR_LOOP_1
    ADD R1, R1, R2  ;R3 <-- R3 + R2
    ADD R6, R6, #-1 ;R1 <-- R1 - 1
    BRp FOR_LOOP_1  ;if(LMR >0) repeat loop
END_FOR_LOOP_1
HALT                ;Terminate the program

;-----------
;Data
;-----------

DEC_0 .fill #0      ;Put the value 0 into memory here
DEC_6 .fill #6      ;Put the value 6 into memory here
DEC_12 .fill #12    ;Put the vlaue 12 into memory here
.end
