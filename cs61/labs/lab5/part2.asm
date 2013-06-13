.orig x3000

;--------------------------------------
;MAIN code block
;INSTRUCTION BLOCK: main
;-------------------------------------
LD R6, READING_SUBROUTINE ;R2 becomes binary converted to decimal
JSRR R6
LD R6, WRITING_SUBROUTINE
JSRR R6

HALT
;----------------------------------
;DATA BLOCK: main
;----------------------------------
READING_SUBROUTINE .fill x3200
WRITING_SUBROUTINE .fill x3400

;-------------------------------------
;Subroutine: reading_subroutine
;Return value: R2 -> 16 bit binary converted to decimal
;INSTRUCTION BLOCK: reading_subroutine
;-------------------------------------
.orig x3200

;backup
ST R7, backup_r7_3200

;subroutine

;R0-number read
;R1-ptr
;R2-i counter
;R3-j counter
;R4-add total

LEA R0, message1
PUTS
LD R1, data_ptr
LD R3, DEC_1
LD R5, DEC_0a           ;couner from 0
LD R2, DEC_17          ;counter
FOR_LOOP_1              ;for(int i = 0; i++; i < 17)
    ADD R2,R2,#0
    Brz END_FOR_LOOP_1
    GETC
    OUT

    ;error checking
    ADD R5, R5, #0 ;check if b
    BRp ERROR_CHECK_pt2
        LD R6, DEC_n98
        ADD R0, R6, R0
        BRz PASSED_ERROR_CHECK_b

    ERROR_CHECK_pt2
    LD R6, DEC_n48    ;check if 0
    ADD R0, R6, R0
    BRz PASSED_ERROR_CHECK_0
    LD R6, DEC_48
    ADD R0, R6, R0

    LD R6, DEC_n49    ;check if 1
    ADD R0, R6, R0
    BRz PASSED_ERROR_CHECK_1
    LD R6, DEC_49
    ADD R0, R6, R0

    LD R6, DEC_n32    ;check if space, ignore and start over
    ADD R0, R6, R0
    BRz FOR_LOOP_1
    LD R6, DEC_32
    ADD R0, R6, R0

    CRY_COMPLAIN_QQ
        LEA R0, messageQQ
        PUTS
        BR END_FOR_LOOP_1

    PASSED_ERROR_CHECK_b
        LD R6, DEC_98
        ADD R0, R6, #0
        BR PASSED_ERROR_CHECK

    PASSED_ERROR_CHECK_0
        LD R6, DEC_48
        ADD R0, R6, #0
        BR PASSED_ERROR_CHECK

    PASSED_ERROR_CHECK_1
        LD R6, DEC_49
        ADD R0, R6, #0

    ;end_error_checking
    PASSED_ERROR_CHECK

    LD R6, DEC_n48
    ADD R0, R0, R6
    STR R0, R1, #0
    ADD R1, R1, #1
    ADD R2, R2, #-1
    ADD R5, R5, #1
    BR FOR_LOOP_1
END_FOR_LOOP_1

;start left shifting the array
;read numbers from the back of the array
ADD R1,R1,#-1

LD R2, DEC_16       ;counter
FOR_LOOP_2          ;for(int i =0; i++; i<16)
    BRz END_FOR_LOOP_2
    LDR R0,R1,#0
    ADD R0,R0,#0
    IF_STATEMENT_1  ;to add or not to add, taht is the question
        BRz END_IF_STATEMENT_1
        ADD R4, R4, R3
    END_IF_STATEMENT_1
    ADD R3, R3,R3   ;change count J
    ADD R1, R1, #-1 ;move ptr
    ADD R2, R2, #-1 ;decrement i
    BR FOR_LOOP_2
END_FOR_LOOP_2
ADD R2, R4, #0      ;replace R2 with total value (R4)

;restore
LD R7, backup_r7_3200

;return
RET

;----------------------------------
;DATA BLOCK: reading_subroutine
;----------------------------------
backup_r7_3200 .blkw #1
message1 .STRINGZ "enter b, followed by a 16bit binary\n e.g b0001001000110100\n"
messageQQ .STRINGZ "\n\ncomputer is QQ, you entered wrong input so everything is WRONG\n"
DEC_n16 .fill#-16
DEC_16 .fill#16
DEC_17 .fill #17
DEC_1 .fill #1
DEC_n48 .fill #-48
DEC_48 .fill #48
DEC_49 .fill #49
DEC_n49 .fill #-49
DEC_32 .fill #32
DEC_n32 .fill #-32
DEC_0a .fill #0
DEC_98 .fill #98
DEC_n98 .fill #-98
data_ptr .fill x4000


;-------------------------------------
;Subroutine: output_subroutine
;ARGUMENT: R2 must be dec. number to convert
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
LEA R0, message1a
puts
ADD R4, R2, #0
LD R2, DEC_16a
LD R3, DEC_4
LDI R0, ASCII_b
out
output_subroutine_LOOP_1
ADD R2,R2,#0
BRZ output_subroutine_END_LOOP_1
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
    BR output_subroutine_LOOP_1
output_subroutine_END_LOOP_1
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
message1a .STRINGZ "\n CONVERTED TO BINARY::\n"
DEC_16a .fill #16
DEC_4 .fill #4
DEC_10a .fill #10
DEC_0 .fill #0
data_ptra .fill x4000
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
