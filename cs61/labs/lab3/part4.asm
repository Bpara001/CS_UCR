
.orig x3000

LD R1, data_ptr
LD R2, count

LEA R0,message1
PUTS

DO_WHILE_LOOP
    GETC
    OUT
    ADD R0,R0, #-10

    IF_STATEMENT
    BRz TRUE_CONDITION
    FALSE_CONDITION
        ADD R0,R0, #10
        STR R0, R1, #0
        ADD R1, R1, #1
        ADD R2, R2, #1
        BR DO_WHILE_LOOP
    TRUE_CONDITION
    END_IF
END_DO_WHILE_LOOP

;--------------

LEA R0,message2
PUTS
ADD R2, R2,#-1
NOT R2,R2
ADD R1, R1, R2
NOT R2,R2
ADD R2, R2,#1

;---------------
FOR_LOOP_2
    LDR R0, R1, #0
    OUT
    ADD R1, R1, #1
    ADD R2, R2, #-1
    BRp FOR_LOOP_2
END_LOOP_2

HALT

;-------------
;data
;-------------
data_ptr .fill x4000
count .fill #0
message1 .STRINGZ "\nPress Enter to stop\n Entered data: "
message2 .STRINGZ "\n Ouputed data: "
comma .STRINGZ "\n "

.end
