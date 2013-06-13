
;==============================================
;MAIN TEST HARNESS
;=============================================
.orig x3000
LD R0,ptr
LD R6, uppercase
JSRR R6

PUTS

HALT

;-=---------
uppercase .fill x3200
ptr .fill x4000


;================================================
;SUBROUTINE:uppercase
;arguments:R0 as the address location
;return value:R1 becomes uppercase
;================================================
.orig x3200
;backup
ST R0, backup_r0_uppercase
ST R1, backup_r1_uppercase
ST R2, backup_r2_uppercase
ST R3, backup_r3_uppercase
ST R4, backup_r4_uppercase
ST R5, backup_r5_uppercase
ST R6, backup_r6_uppercase
ST R7, backup_r7_uppercase

;-------------------------
; INSTRUCTIONS;
;-------------------------
ADD R1,R0,#0
LEA R0,uppercase_message1
PUTS
LEA R0,uppercase_message2
PUTS
LD R2,uppercase_n32
Ld R3, uppercase_32

input_loop
    GETC
    out

    ;check enter key
    ADD R0,R0,#-10
    BRz end_input_loop
    ADD R0,R0,#10

    ;check spacebar
    ADD R0,R0,R2
    BRz continue_input_loop_space
    ADD R0,R0,R3

    ;if lowercase
    ADD R0,R0,R2
    STR R0,R1,#0
    ADD R1,R1,#1
    BR input_loop

    ;if space
    continue_input_loop_space
    ADD R0,R0,R3
    STR R0,R1,#0
    ADD R1,R1,#1
    BR input_loop


end_input_loop



;restore&return
LD R0, backup_r0_uppercase
LD R1, backup_r1_uppercase
LD R2, backup_r2_uppercase
LD R3, backup_r3_uppercase
LD R4, backup_r4_uppercase
LD R5, backup_r5_uppercase
LD R6, backup_r6_uppercase
LD R7, backup_r7_uppercase
RET

;------------------
; DATA;
;------------------
backup_r0_uppercase .blkw #1
backup_r1_uppercase .blkw #1
backup_r2_uppercase .blkw #1
backup_r3_uppercase .blkw #1
backup_r4_uppercase .blkw #1
backup_r5_uppercase .blkw #1
backup_r6_uppercase .blkw #1
backup_r7_uppercase .blkw #1
uppercase_n32 .fill #-32
uppercase_32 .fill #32
uppercase_message1 .stringz "INPUT A SENTENCE IN LOWER CASE\n"
uppercase_message2 .stringz "TERMINATE WITH [enter]:\n "
