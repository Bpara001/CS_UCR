.orig x3000

LD R1, data_ptr
LD R2, count_dec_0
LD R3, count_dec_10
LD R5, ARRAY_1
ARRAY_1 .BLKW #10

ADD R3,R3, #0

FOR_LOOP_1
    STR R2, R1, #0
    ADD R1, R1, #1      ;increment ptr
    ADD R2, R2, #1      ;increment number
    ADD R3, R3, #-1     ;decrement counter
    BRp FOR_LOOP_1
END_IF

LD R1, data_ptr
LDR R2, R1, #7
add R2, R2, #0


HALT

;-------------
data_ptr .fill x4000
ARRAY_1 .fill x4000
count_dec_0 .fill #0
count_dec_10 .fill #10

.end
