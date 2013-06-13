;==============================================
;MAIN TEST HARNESS
;=============================================
.orig x3000

LEA R0, message1
PUTS
LD R1,ptr4

input_loop
    GETC
    out
    ADD R0,R0,#-10
    BRz end_input_loop
    ADD R0,R0,#10
    STR R0,R1,#0
    ADD R1,R1,#1
    BR input_loop
end_input_loop
;ADD R1,R1,#1
LD R2,DEC_n1
STR R2,R1,#0


;R1 <- instruction_FIXED ptr
;R2 <- user input ptr
;R3 <- value at instruction_FIXED ptr
;R4 <- value at user input ptr
;R5 <- counter position
;R6 <- total conuter
LD R1,ptr3
LD R2,ptr4
LD R5, DEC_0
LD R6, DEC_0

CHECK_LOOP
    LDR R3,R1,#0
    BRn CHECK_LOOP_FAILED
    LDR R4,R2,#0
    BRn CHECK_LOOP_SUCCESS

    ;compare if identical
    NOT R3,R3
    ADD R3,R3,#1
    ADD R0,R3,R4
    BRnp CHECK_LOOP_next
    ADD R1,R1,#1
    ADD R2,R2,#1
    BR CHECK_LOOP

    ;go till next '0' is hit
    CHECK_LOOP_next
        ADD R1,R1,#1
        LDR R0,R1,#0
        BRz end_CHECK_LOOP_next
        BR CHECK_LOOP_next
    end_CHECK_LOOP_next

    ;add counter position,reset user input ptr
    ADD R1,R1,#1
    ADD R5,R5,#1
    LD R2,ptr4
    BR CHECK_LOOP

end_CHECK_LOOP


CHECK_LOOP_FAILED
    LEA R0,messagef
    PUTS
    BR finish


CHECK_LOOP_SUCCESS
    LEA R0,messaget
    PUTS

finish
HALT

LEA R0, message2
PUTS
LD R6, opcode
JSRR R6

PUTS

HALT
;----------
opcode .fill x3200
ptr1 .fill x3400
ptr2 .fill x3600
ptr3 .fill x3800
ptr4 .fill x4000
message1 .stringz "TYPE INSTRUCTION: "
message2 .stringz "\n"
messaget .stringz "FOUND INSTRUCTION\n"
messagef .stringz "COULD NOT FIND\n"
DEC_0 .fill #0
DEC_n1 .fill #-1
;================================================
;SUBROUTINE:opcode_print
;arguments: R1 <- specific starting point of array INSTRUCTION
;           R2 <- specific starting point of array OPCODE
;return value:none
;================================================
.orig x3200
;backup
ST R0, backup_r0_opcode
ST R1, backup_r1_opcode
ST R2, backup_r2_opcode
ST R3, backup_r3_opcode
ST R4, backup_r4_opcode
ST R5, backup_r5_opcode
ST R6, backup_r6_opcode
ST R7, backup_r7_opcode
;-------------------------
; INSTRUCTIONS;
;-------------------------
;R0 <- buffer
;R1 <- ptr of INSTRUCTION
;R2 <- ptr of OPECODE
;R3 <- #4 counter
;R4 <- temp value
;R5 <- #16 counter
LD R5, opcode_16

opcode_PRINT_LOOP
    LDR R4,R2,#0
    LD R3,opcode_4
    ADD R0,R1,#0
    PUTS
    ADD R1,R1,#5
    LEA R0,opcode_message0
    PUTS

    ;left shift 12 times
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4
    ADD R4,R4,R4

    opcode_for_loop
        ;if statement1
        ADD R4,R4,#0
        BRn opcode_print_1
            LD R0,opcode_48
            OUT
            BR end_opcode_if1
        opcode_print_1
            LD R0,opcode_49
            OUT
        end_opcode_if1
        ;end if statement
        ADD R4,R4,R4
        ADD R3,R3,#-1
        BRz end_opcode_for_loop
        BR opcode_for_loop
    end_opcode_for_loop

    ADD R2,R2,#1
    LEA R0, opcode_message1
    PUTS
    ADD R5,R5,#-1
    BRz end_opcode_PRINT_LOOP
    BR opcode_PRINT_LOOP
end_opcode_PRINT_LOOP

HALT
;restore&return
LD R0, backup_r0_opcode
LD R1, backup_r1_opcode
LD R2, backup_r2_opcode
LD R3, backup_r3_opcode
LD R4, backup_r4_opcode
LD R5, backup_r5_opcode
LD R6, backup_r6_opcode
LD R7, backup_r7_opcode
RET

;------------------
; DATA;
;------------------
backup_r0_opcode .blkw #1
backup_r1_opcode .blkw #1
backup_r2_opcode .blkw #1
backup_r3_opcode .blkw #1
backup_r4_opcode .blkw #1
backup_r5_opcode .blkw #1
backup_r6_opcode .blkw #1
backup_r7_opcode .blkw #1
opcode_48 .fill #48
opcode_49 .fill #49
opcode_4 .fill #4
opcode_16 .fill #1
opcode_message0 .stringz "= "
opcode_message1 .stringz "\n"


.orig x3400
.stringz "ADD "
.stringz "AND "
.stringz "BR  "
.stringz "JMP "
.stringz "JSR "
.stringz "LD  "
.stringz "LDI "
.stringz "LDR "
.stringz "LEA "
.stringz "NOT "
.stringz "RET "
.stringz "RTI "
.stringz "ST  "
.stringz "STI "
.stringz "TRAP"
.stringz "reserved"

.orig x3600
.fill #1
.fill #5
.fill #0
.fill #12
.fill #4
.fill #2
.fill #10
.fill #6
.fill #14
.fill #9
.fill #12
.fill #8
.fill #3
.fill #11
.fill #15
.fill #13

.orig x3800
.stringz "ADD"
.stringz "AND"
.stringz "BR"
.stringz "JMP"
.stringz "JSR"
.stringz "LD"
.stringz "LDI"
.stringz "LDR"
.stringz "LEA"
.stringz "NOT"
.stringz "RET"
.stringz "RTI"
.stringz "ST"
.stringz "STI"
.stringz "TRAP"
.stringz "reserved"
.fill #-1



