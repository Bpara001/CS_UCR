
.orig x3000

LD R1, data_ptr
LD R2, DEC_0
LD R3, DEC_10
LD R4, DEC_1
LD R5, ARRAY_1
ARRAY_1 .BLKW #10

ADD R3,R3, #0

FOR_LOOP_1

    ADD R4,R4,R4

    STR R4, R1, #0      ;store

    ADD R1, R1, #1      ;increment ptr

    ADD R3, R3, #-1     ;decrement counter

    BRp FOR_LOOP_1
END_IF

;-----------------------------
LD R0, data_ptr
ADD R1, R4, #0
LD R2, DEC_16
LD R3, DEC_4
LDI R0, ASCII_b
out

LOOP_1
ADD R2,R2,#0
BRZ END_LOOP_1

    ADD R1,R1,#0
    BRzp TRUE_IF_1
        LDI R0,ASCII_1
        BR END_IF_1
    TRUE_IF_1
        LDI R0,ASCII_0
    END_IF_1

    out

    ADD R3, R3, #-1
    BRz TRUE_IF_2
        BR END_IF_2
    TRUE_IF_2
        LDI R0, ASCII_SPACE
        out
        LD R3, DEC_4
    END_IF_2


    ADD R2, R2, #-1
    ADD R1, R1, R1
    BR LOOP_1

END_LOOP_1




HALT

;-------------
data_ptr .fill x4000
ARRAY_1 .fill x4000
DEC_0.fill #0
DEC_10 .fill #10
DEC_1 .fill #1
DEC_16 .fill #16
DEC_4 .fill#4

ASCII_0 .fill x5000
ASCII_1 .fill x5001
ASCII_SPACE .fill x5002
ASCII_b .fill x5003

.orig x5000
.fill #48
.fill #49
.fill #32
.fill #98


.end
