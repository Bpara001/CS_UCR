;--------------------------------------
;MAIN code block
;INSTRUCTION BLOCK: main
;-------------------------------------
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

;LDI R1,data_ptr
;LD R5, DEC_10
LD R6, OUTPUT_SUBROUTINE_3400
JSRR R6

HALT
;----------------------------------
;DATA BLOCK: main
;----------------------------------
OUTPUT_SUBROUTINE_3400 .fill x3400
ARRAY_1 .fill x4000
data_ptr .fill x4000
DEC_0.fill #0
DEC_10 .fill #10
DEC_1 .fill #1
DEC_16 .fill #16
DEC_4 .fill#4



;-------------------------------------
;Subroutine: output_subroutine
;INSTRUCTION BLOCK: output_subroutine
;-------------------------------------
.orig x3400

;backup
ST R0, backup_r0_3400
ST R1, backup_r1_3400
ST R2, backup_r2_3400
ST R3, backup_r3_3400
ST R4, backup_r4_3400
ST R5, backup_r5_3400
ST R6, backup_r6_3400
ST R7, backup_r7_3400

;subroutine
LD R1,data_ptra
LD R5, DEC_10a

return_point:
ADD R5, R5, #0
BRz IF_4_FALSE
    LEA R0, message
    puts
    LDR R4, R1, #0
    ADD R1, R1, #1
    ADD R5,R5, #-1
    LEA R6, my_subroutine
    JMP R6
IF_4_FALSE

;restore
LD R0, backup_r0_3400
LD R1, backup_r1_3400
LD R2, backup_r2_3400
LD R3, backup_r3_3400
LD R4, backup_r4_3400
LD R5, backup_r5_3400
LD R6, backup_r6_3400
LD R7, backup_r7_3400

;return
RET

;subroutine_mini
my_subroutine:

LD R2, DEC_16
LD R3, DEC_4
LDI R0, ASCII_b
out
LOOP_1
ADD R2,R2,#0
BRZ END_LOOP_1
    ADD R4,R4,#0
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
    ADD R4, R4, R4
    BR LOOP_1
END_LOOP_1
LEA R6, return_point
JMP R6

;----------------------------------
;DATA BLOCK: reading_subroutine
;----------------------------------
backup_r0_3400 .blkw #1
backup_r1_3400 .blkw #1
backup_r2_3400 .blkw #1
backup_r3_3400 .blkw #1
backup_r4_3400 .blkw #1
backup_r5_3400 .blkw #1
backup_r6_3400 .blkw #1
backup_r7_3400 .blkw #1
DEC_16 .fill #16
DEC_4 .fill #4
DEC_10a .fill #10
data_ptra .fill x4000
message .STRINGZ "\n"
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
