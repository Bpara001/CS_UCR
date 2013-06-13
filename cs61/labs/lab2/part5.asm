.ORIG x3000
;--------------
;instructions
;---------------
LD R1, DEC_100


FOR_LOOP_1
    PUTS
    GETC
    OUT
    ADD R1, R1, #0
    BRp FOR_LOOP_1
END_FOR_LOOP_1

HALT
;--------------
;data
;--------------

DEC_100 .fill #255
.end
