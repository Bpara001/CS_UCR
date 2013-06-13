;----------------------------------------------------
; Wong, Chris
; 860-923-521
; Login: wongc
; Section: 23
; TA: Wasim
; Email: cwong030@ucr.edu
; Lab 01
;----------------------------------------------------
.orig x3000

;--------------------
;Instructions
;-------------------
LD R1, DEC_0
LD R2, DEC_12
LD R6, DEC_6

FOR_LOOP_1
    ADD R1, R1, R2
    ADD R6, R6, #-1
    BRp FOR_LOOP_1
END_FOR_LOOP_1
HALT

;-----------
;Data
;-----------

DEC_0 .fill #0
DEC_6 .fill #6
DEC_12 .fill #12
.end
