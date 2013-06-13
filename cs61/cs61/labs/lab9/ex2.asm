;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab9
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
.orig x3000
;===============================================
;MAIN FUNCITON
;===============================================
LD R6, SUB_PRINT_OPCODES
JSRR R6

HALT


;=============================
;data: main function
;=============================
SUB_PRINT_OPCODES .fill x3200



;====================================================

; Subroutine: SUB_PRINT_OPCODES
; Parameters: None
; Postcondition: The subroutine has printed out a list of every LC3 instruction
;   and corresponding opcode in the following format:
;   ADD = 0001
;   AND = 0101
;   BR = 0000
;   ....
;Return Value: None
 .ORIG x3200
;====================================================
;-------------------------
; INSTRUCTIONS; OPcode
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, op_backup_r0
ST R1, op_backup_r1
ST R2, op_backup_r2
ST R3, op_backup_r3
ST R4, op_backup_r4
ST R5, op_backup_r5
ST R6, op_backup_r6
ST R7, op_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R1,op_ptr1
LD R2,op_ptr2
LD R3,op_counter
LD R6, SUB_PRINT_4bit

;main logic loop
op_forloop1             ;(int i =0; i < 15; i++)
    ;print string
    ADD R0,R2,#0            ;copy string ptr to R0
    PUTS                    ;output string
    LEA R0,op_string1       ;load string
    PUTS                    ;output
    op_whileloop1          ;while ptr != NULL, increment to next string
        ADD R2,R2,#1            ;increment string ptr
        LDR R0,R2,#0            ;if string ptr data = 0
        BRnp op_whileloop1      ;top incrementing
    op_whileloop_end
    ;print 4-bit binary
    LDR R0,R1,#0
    JSRR R6
    ;do stuff with counters & ptrs
    LEA R0,op_string2           ;print newline
    PUTS                        ;print newline
    ADD R1,R1,#1
    ADD R2,R2,#1                ;increment string ptr once more
    ADD R3,R3,#-1               ;decrement counter
    BRp op_forloop1             ;repeat loop
op_forloop1_end

;(3)Restore all modified registers except Return Values
LD R0, op_backup_r0
LD R1, op_backup_r1
LD R2, op_backup_r2
LD R3, op_backup_r3
LD R4, op_backup_r4
LD R5, op_backup_r5
LD R6, op_backup_r6
LD R7, op_backup_r7
;(4)Return to where you came from
RET

;------------------
; DATA; OPcode
;------------------
SUB_PRINT_4bit .fill x3400
op_string1 .stringz " = "
op_string2 .stringz "\n"
op_counter .fill #15
op_ptr1     .fill x4000
op_ptr2     .fill x4200
op_backup_r0 .blkw #1
op_backup_r1 .blkw #1
op_backup_r2 .blkw #1
op_backup_r3 .blkw #1
op_backup_r4 .blkw #1
op_backup_r5 .blkw #1
op_backup_r6 .blkw #1
op_backup_r7 .blkw #1


;====================================================
;SUBROUTINE: print 4bit binary
;Input R0
;Postcondition: prints R0 in 4bit binary
;Return Value: void
 .ORIG x3400
;=====================================================
;------------------------
; INSTRUCTIONS; print binary
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, pbin_backup_r0
ST R1, pbin_backup_r1
ST R6, pbin_backup_r6
ST R7, pbin_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
ADD R1,R0,#0

;i dont feel like writing loops so im going to just hard code everything.
;left shift 12 times
ADD R1,R1,R1            ;multiply by 2, 12 times
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1
ADD R1,R1,R1

;first iteration
BRzp pbin_z_out1                ;if nubmer is zero or positive, print 0
LD R0,pbin_ascii1               ;else print 1
OUT
BR z_out1_end
pbin_z_out1
LD R0,pbin_ascii0
OUT
z_out1_end
ADd R1,R1,R1

;second iteration
BRzp pbin_z_out2              ;if number is zero of pisitve, print 0
LD R0,pbin_ascii1             ;else print 1
OUT                           ;output 1 to screen
BR z_out2_end
pbin_z_out2
LD R0,pbin_ascii0
OUT                           ;output 0 to screen
z_out2_end
ADd R1,R1,R1

;third iteration
BRzp pbin_z_out3            ;if number is zero or poisitive, print 0
LD R0,pbin_ascii1           ;else print 1
OUT                         ;otuput 1 to screen
BR z_out3_end
pbin_z_out3
LD R0,pbin_ascii0
OUT                         ;output 0 to screen
z_out3_end
ADd R1,R1,R1

;fourth iteration
BRzp pbin_z_out4        ;if number is zero or positive, print 0
LD R0,pbin_ascii1       ;else print 1
OUT                     ;output 1 to screen
BR z_out4_end
pbin_z_out4
LD R0,pbin_ascii0
OUT                     ;output 0 to screen
z_out4_end
ADd R1,R1,R1


;(3)Restore all modified registers except Return Values
LD R0, pbin_backup_r0
LD R1, pbin_backup_r1
LD R6, pbin_backup_r6
LD R7, pbin_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; print binary
;------------------
pbin_ascii0 .fill #48
pbin_ascii1 .fill #49
pbin_backup_r0 .blkw #1
pbin_backup_r1 .blkw #1
pbin_backup_r6 .blkw #1
pbin_backup_r7 .blkw #1


;Populate dec array
.orig x4000
.fill #1        ;add
.fill #5        ;and
.fill #0        ;br
.fill #12       ;jmp/ret
.fill #4        ;jsr/jsrr
.fill #2        ;ld
.fill #10       ;ldi
.fill #6        ;ldr
.fill #14       ;lea
.fill #9        ;not
.fill #8        ;rit
.fill #3        ;st
.fill #11       ;sti
.fill #7        ;str
.fill #15       ;trap

;Populate string array
.orig x4200
.STRINGZ "ADD"
.stringz "AND"
.stringz "BR"
.stringz "JMP/RET"
.stringz "JSR/JSRR"
.stringz "LD"
.stringz "LDI"
.stringz "LDR"
.stringz "LEA"
.stringz "NOT"
.stringz "RTI"
.stringz "ST"
.stringz "STI"
.stringz "STR"
.stringz "TRAP"

.end
