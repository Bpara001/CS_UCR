;==============================================
;MAIN CODE BLOCK
;=============================================
.orig x3000
;-------------------------
; INSTRUCTIONS;MAIN CODE
;-------------------------
LD R0,DEC_0
LD R2,DEC_48
LD R3,DEC_n48
LD R6, STACK

;toggle to push
LD R4, DEC_1                ;toggle push
LEA R0,message1
PUTS

inputloop
    GETC
    OUT

    ADD R0,R0,#-10          ;check if user hits enter button
    BRz endinputloop
    ADD R0,R0,#10

    ADD R0,R3,R0            ;convert to binary number
    JSRR R6                 ;check overflow
    ADD R5,R5,#0
    BRp errorcheck2

    BR inputloop
endinputloop

LD R4,DEC_0                 ;toogle pop
LEA R0,message2
PUTS

poploop
    GETC
    ADD R0,R0,#-10          ;check if user hits enter button
    BRz enderror2
    ADD R0,R0,#10

    JSRR R6                 ;check underflow
    ADD R5,R5,#0
    BRp errorcheck1

    ADD R0,R2,R0
    OUT
    BR poploop
endpoploop

BR enderror2

errorcheck1
    LEA R0,message_error1
    PUTS
    BR enderror2
enderror1

errorcheck2
    LEA R0,message_error2
    PUTS
enderror2


LEA R0,message_end
PUTS


HALT
;------------------
; DATA;MAIN CODE BLOCK
;------------------
STACK .fill x4000
DEC_0 .fill #0
DEC_1 .fill #1
DEC_n48 .fill #-48
DEC_48 .fill #48
message1 .stringz "\nInput chars(up to 4) for stack:\n"
message2 .stringz "\npress any key to pop\n"
message_error1 .stringz "\nstack is empty cannot pop\n"
message_error2 .stringz "\nstack is full cannot push\n"
message_end .stringz "\nend program\n"

;================================================
;SUBROUTINE:stack
;arguments: R0 <- data for push
;           R4 <- bit flag (1) enables PUSH
;           R4 <- bit flag (0) enables POP
;return value: R0 <- if POP, returns value at top of stack
;              R5 <- returns true or false value if operation was preformed
;================================================
.orig x4000
;backup
ST R1, backup_r1_stack
ST R2, backup_r2_stack
ST R3, backup_r3_stack
ST R4, backup_r4_stack
ST R6, backup_r6_stack
ST R7, backup_r7_stack
;-------------------------
; INSTRUCTIONS;stack_pop
;-------------------------

ADD R4,R4,#0
Brp PUSH

POP     ST	R2, Sv2 			;save, needed by POP
        ST	R1, Sv1 			;save, needed by POP
        LD	R1, BASE		    ;BASE contains x-3FFF
        ADD	R1,	R1, # -1 		;R1 now has x-4000
        ADD	R2, R6, R1 		    ;Compare SP to x4000
        BRz	fail_exit			;Branch if stack is empty
        LDR	R0, R6, # 0 		;The actual ‘pop’
        ADD	R6, R6, # 1 		;Adjust stack pointer
        BRnzp success_exit

PUSH 	ST	R2, Sv2 		    ;needed by PUSH
		ST	R1, Sv1 		    ;needed by PUSH
		LD	R1, MAX	            ;MAX has x-3FFB
		ADD	R2, R6, R1 	        ;Compare SP to x4004
		BRz	fail_exit		    ;Branch is stack is full
		ADD	R6, R6, # -1	    ;Adjust Stack Pointer
		STR	R0, R6, # 0 	    ;The actual ‘push’

success_exit
        LD	R1, Sv1 	    ;Restore register values
        LD	R2, Sv2 	    ;
        AND	R5, R5, # 0	    ;R5 <-- success
        RET
	;
fail_exit
        LD	R1, Sv1	;Restore register values
        LD	R2, Sv2
        AND	R5, R5, # 0
        ADD	R5, R5, # 1	;R5 <-- fail
        RET

BASE 	.FILL xC001	        ;Base has x-3FFF
MAX 	.FILL xC004 		;Max has x-4004
Sv1 	.FILL x0000
Sv2 	.FILL x0000

;restore&return
LD R1, backup_r1_stack
LD R2, backup_r2_stack
LD R3, backup_r3_stack
LD R4, backup_r4_stack
LD R6, backup_r6_stack
LD R7, backup_r7_stack
RET

;------------------
; DATA;
;------------------
backup_r1_stack .blkw #1
backup_r2_stack .blkw #1
backup_r3_stack .blkw #1
backup_r4_stack .blkw #1
backup_r6_stack .blkw #1
backup_r7_stack .blkw #1

