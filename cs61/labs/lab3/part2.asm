.orig x3000

LD R1, data_ptr
LD R3, count_dec_10
LD R5, ARRAY_1
ARRAY_1 .BLKW #10

ADD R3,R3, #0

FOR_LOOP_1
    IN
    STR R0, R1, #0
    ADD R1, R1, #1
    ADD R3, R3, #-1
    BRp FOR_LOOP_1
END_IF


LEA R0,message2
PUTS
ADD R1, R1, #-10
ADD R3, R3, #10

FOR_LOOP_2
    LDR R0, R1, #0
    OUT
    LEA R0,comma
    PUTS
    ADD R1, R1, #1
    ADD R3, R3, #-1
    BRp FOR_LOOP_2
END_IF

HALT

;-------------
data_ptr .fill x4000
ARRAY_1 .fill x4000
count_dec_0 .fill #0
count_dec_10 .fill #10

message2 .STRINGZ "\nInputed Characters in order: "
comma .STRINGZ ", "



.end
