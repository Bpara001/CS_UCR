
.orig x3000

LD R1, data_ptr
LD R2, count_dec_0
LD R3, count_dec_10
LDI R4, DEC_48
LD R5, ARRAY_1
ARRAY_1 .BLKW #10

ADD R3,R3, #0

FOR_LOOP_1
    STR R2, R1, #0
    ADD R1, R1, #1      ;increment ptr
    ADD R2, R2, #1      ;increment number
    ADD R3, R3, #-1     ;decrement counter
    BRp FOR_LOOP_1

LD R1, data_ptr
LD R3, count_dec_10

FOR_LOOP_2
    LDR R0, R1, #0
    add R0, R0, R4
    out
    ADD R1, R1, #1      ;increment ptr
    ADD R3, R3, #-1     ;decrement counter
    BRp FOR_LOOP_2



HALT

;-------------
data_ptr .fill x4000
ARRAY_1 .fill x4000
count_dec_0 .fill #0
count_dec_10 .fill #10
DEC_48 .fill x5000

.orig x5000
.fill #48

.end
