;==============================================
;MAIN CODE BLOCK
;=============================================
.orig x3000
;-------------------------
; INSTRUCTIONS;MAIN CODE
;-------------------------
LD R4, DEC_1                ;toggle push
LD R3,DEC_n48
LD R6, STACK

;get user input
LEA R0, message1
PUTS
GETC
out
ADD R0,R0,R3
JSRR R6

LEA R0, message1a
PUTS
GETC
out
ADD R0,R0,R3
JSRR R6

LEA R0,message1b
PUTS

;multiply & output
LD R4, DEC_0                    ;toggle pop
LD R3, DEC_48

JSRR R6
ADD R1,R0,#0
ADD R0,R0,R3
OUT
LEA R0,message2
PUTS

JSRR R6
ADD R2,R0,#0
ADD R0,R0,R3
OUT
LEA R0,message2a
PUTS

LD R6,MULTIPLY
JSRR R6

;push onto stack
LD R6,STACK
LD R4,DEC_1                 ;toggle push
JSRR R6

;output
LD R6,OUTPUT
JSRR R6


;toggle to push
ADD R4,R4,#1

HALT
;------------------
; DATA;MAIN CODE BLOCK
;------------------
STACK .fill x3200
MULTIPLY .fill x3400
OUTPUT .fill x3600
DEC_0 .fill #0
DEC_1 .fill #1
DEC_n48 .fill #-48
DEC_48 .fill #48
message1 .stringz "Input two single digit ints: "
message1a .stringz " & "
message1b .stringz "\n"
message2 .stringz " * "
message2a .stringz " = "

;================================================
;SUBROUTINE:stack
;arguments: R0 <- data for push
;           R4 <- bit flag (1) enables PUSH
;           R4 <- bit flag (0) enables POP
;return value: R0 <- if POP, returns value at top of stack
;              R5 <- returns true or false value if operation was preformed
;================================================
.orig x3200
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

BASE 	.FILL xC001 		;Base has x-3FFF
MAX 	.FILL xC005 		;Max has x-4004
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



;================================================
;SUBROUTINE: multiply_int
;arguments: multiplies R1 and R2
;return value: value is returned to R0
;================================================
.orig x3400

;backup
ST R1, backup_r1_multiply_int
ST R2, backup_r2_multiply_int
ST R3, backup_r3_multiply_int
ST R4, backup_r4_multiply_int
ST R5, backup_r5_multiply_int
ST R6, backup_r6_multiply_int
ST R7, backup_r7_multiply_int
;----------------------------
; INSTRUCTIONS; multiply_int
;----------------------------
;x * y = product
;R0 -> product
;R1 -> x
;R2 -> y
;R3 -> product_temp
;R4 -> temp1
;R5 -> temp2

;***neg & zero checks***
LD R6,multiplyint_DEC_n1
ST R6, multiplyint_x_data
ST R6, multiplyint_y_data
multiplyint_check_x         ;checking x for 0 or neg
    ADD R1,R1,#0
    BRn multiplyint_x_neg
    BRz multiplyint_zero
multiplyint_check_y         ;checking y for 0 or neg
    ADD R2,R2,#0
    BRn multiplyint_y_neg
    BRz multiplyint_zero
BR END_multiplyint_check1
multiplyint_x_neg           ;if x<0
    NOT R1,R1
    ADD R1,R1,#1
    LD R6, multiplyint_DEC_1
    ST R6,multiplyint_x_data
    BR multiplyint_check_y
multiplyint_y_neg           ;if y<0
    NOT R2,R2
    ADD R2,R2,#1
    LD R6, multiplyint_DEC_1
    ST R6,multiplyint_y_data
    BR END_multiplyint_check1
multiplyint_zero            ;if x == 0 || y == 0
    LD R0, multiplyint_DEC_0
    RET
END_multiplyint_check1

LD R3, multiplyint_DEC_0

;***logic_CHECK***
multiplyint_logic_check
    NOT R1, R1
    ADD R1, R1,#1
    ADD R4, R1, R2
    BRn multiplyint_end_logic_check ; IF R1 < R2 then SWAP R1 & R2
    NOT R1,R1
    ADD R1,R1, #1
    ADD R4, R1, #0
    ADD R1, R2, #0
    ADD R2, R4, #0
    BR multiplyint_FOR_LOOP_1
multiplyint_end_logic_check
NOT R1, R1
ADD R1, R1, #1

;***multiplication logic***
multiplyint_FOR_LOOP_1          ;for(int i = R2; i>0; i++)
    ADD R3,R3,R1
    BRn multiplyint_underflow   ;check for overflow/underflow error
    ADD R2,R2, #-1
    BRz end_multiplyint_FOR_LOOP_1
    BR multiplyint_FOR_LOOP_1
end_multiplyint_FOR_LOOP_1
ADD R0, R3, #0

 ;***dealing with pos/neg signs***
LD R1, multiplyint_x_data
LD R2, multiplyint_y_data        ;if only one is negative, number is neg.
ADD R1,R1,R2
BRnp end_multiplyint_check2      ;convert to neg number
    NOT R0,R0
    ADD R0, R0, #1
end_multiplyint_check2
BR end_multiplyint

;***underflow/overflow errors***
multiplyint_underflow                        ;
    LD R1, multiplyint_x_data
    LD R2, multiplyint_y_data
    ADD R1,R1,R2
    BRnp multiplyint_overflow
        LEA R0, multiplyint_message_underflow
        PUTS
        BR end_multiplyint
    multiplyint_overflow
        LEA R0, multiplyint_message_overflow
        PUTS
        end_multiply_int

;restore & return
end_multiplyint
LD R1, backup_r1_multiply_int
LD R2, backup_r2_multiply_int
LD R3, backup_r3_multiply_int
LD R4, backup_r4_multiply_int
LD R5, backup_r5_multiply_int
LD R6, backup_r6_multiply_int
LD R7, backup_r7_multiply_int
RET
;------------------
; DATA; multiply_int
;------------------
backup_r1_multiply_int .blkw #1
backup_r2_multiply_int .blkw #1
backup_r3_multiply_int .blkw #1
backup_r4_multiply_int .blkw #1
backup_r5_multiply_int .blkw #1
backup_r6_multiply_int .blkw #1
backup_r7_multiply_int .blkw #1
multiplyint_x_data .blkw #1
multiplyint_y_data .blkw #1
multiplyint_DEC_n1 .fill#-1
multiplyint_DEC_1 .fill #1
multiplyint_DEC_0 .fill #0
multiplyint_message_overflow .STRINGz"!!OVERFLOW ERROR!!\nproduct too large"
multiplyint_message_underflow .STRINGz"!!UNDERFLOW ERROR!!\nproduct too small"

;================================================
;SUBROUTINE: output_int
;arguments: R0 as an int
;return value: prints R0 to console
;================================================
.orig x3600

;backup
ST R0, backup_r0_output_int
ST R1, backup_r1_output_int
ST R2, backup_r2_output_int
ST R3, backup_r3_output_int
ST R4, backup_r4_output_int
ST R5, backup_r5_output_int
ST R6, backup_r6_output_int
ST R7, backup_r7_output_int
;-------------------------
; INSTRUCTIONS; output_int
;-------------------------

ADD R1, R0, #0
LD R2, outputint_DEC_10
LD R4, outputint_ptr
LD R5, outputint_DEC_0

;R0 -> number divided by 10
;R1 -> new number (must be replaced by R0)
;R2 -> const 10
;R3 -> least significant digit
;R4 -> ptr to array
;R5 -> counter

ADD R0,R0,#0                        ;CHECK, IF zero, then return 0 w/o sign
    BRnp end_outputint_CHECK1
    LD R0, outputint_DEC_48
    OUT
    BR end_outputint
end_outputint_CHECK1

LD R0, outputint_ascii_par          ;print open paranthesis
out

ADD R0, R1, #0                      ;SET & output SIGN OF NUMBER
    BRp outputint_positive
        NOT R1,R1
        ADD R1,R1,#1
        outputint_negative
        LD R0, outputint_ascii_neg
        out
        BR end_outputint_if_1
    outputint_positive
        LD R0, outputint_ascii_pos
        out
end_outputint_if_1

LD R0, backup_r0_output_int         ;reload R0

outputint_WHILE_LOOP                ;STORE EACH CHARACTER in ARRAY w/ dec value
    LD R6, outputint_divide_int     ;CALL divide_int for SHIFTING
    JSRR R6
    STR R3, R4, #0
    ADD R4, R4, #-1
    ADD R1, R0,#0
    ADD R5,R5,#1
    ADD R0,R0,#0
    BRz end_outputint_WHILE_LOOP
    BR outputint_WHILE_LOOP
end_outputint_WHILE_LOOP
ADD R4,R4,#1

outputint_for_loop              ;output each char in the stored array
    LDR R0, R4, #0
    LD R6, outputint_DEC_48
    ADD R0,R0, R6
    out
    ADD R4,R4,#1
    ADD R5,R5,#-1
    BRz end_outputint_for_loop
    BR outputint_for_loop
end_outputint_for_loop

LD R0, outputint_ascii_par2     ;print closed parenthesis
out

;restore & return
end_outputint
LD R0, backup_r0_output_int
LD R1, backup_r1_output_int
LD R2, backup_r2_output_int
LD R3, backup_r3_output_int
LD R4, backup_r4_output_int
LD R5, backup_r5_output_int
LD R6, backup_r6_output_int
LD R7, backup_r7_output_int
RET
;------------------
; DATA; output_int
;------------------
backup_r0_output_int .blkw #1
backup_r1_output_int .blkw #1
backup_r2_output_int .blkw #1
backup_r3_output_int .blkw #1
backup_r4_output_int .blkw #1
backup_r5_output_int .blkw #1
backup_r6_output_int .blkw #1
backup_r7_output_int .blkw #1
outputint_divide_int .fill x3800
outputint_DEC_0 .fill #0
outputint_DEC_10 .fill #10
outputint_ptr .fill x3710
outputint_ascii_pos .fill #43
outputint_ascii_neg .fill #45
outputint_DEC_48 .fill #48
outputint_ascii_par .fill #40
outputint_ascii_par2 .fill #41


;================================================
;SUBROUTINE: divide_int
;arguments: divides R1 by R2
;return value: quotient -> R0, remainder -> R3
;================================================
.orig x3800

;backup
ST R1, backup_r1_divide_int
ST R2, backup_r2_divide_int
ST R4, backup_r4_divide_int
ST R5, backup_r5_divide_int
ST R6, backup_r6_divide_int
ST R7, backup_r7_divide_int
;-------------------------
; INSTRUCTIONS; divide_int
;--------------------------
;q = n/d, remainder r
;R0 -> q
;R1 -> n
;R2 -> d (converted to -d)
;R3 -> r
;R4 -> TEMP (partial remainder)
LD R0, divideint_DEC_0
LD R3, divideint_DEC_0
NOT R2, R2
ADD R2, R2, #1
divideint_WHILE_LOOP_1              ;n-d = temp
    ADD R4, R1, R2
    BRz divideint_temp_is_zero      ;check: temp == 0?
    BRn divideint_temp_is_negative  ;check: temp < 0?
    ADD R0, R0, #1
    ADD R1, R4, #0                  ;n = temp
    BR divideint_WHILE_LOOP_1
divideint_temp_is_zero              ;no remainder
    ADD R0,R0,#1
    BR divideint_end
divideint_temp_is_negative          ;there is a remainder
    NOT R2,R2
    ADD R2,R2,#1
    ADD R4, R4,R2
    ADD R3, R4, #0                  ;remainder = temp
divideint_end
;restore & return
LD R1, backup_r1_divide_int
LD R2, backup_r2_divide_int
LD R4, backup_r4_divide_int
LD R5, backup_r5_divide_int
LD R6, backup_r6_divide_int
LD R7, backup_r7_divide_int
RET
;------------------
; DATA; divide_int
;------------------
backup_r1_divide_int .blkw #1
backup_r2_divide_int.blkw #1
backup_r4_divide_int .blkw #1
backup_r5_divide_int .blkw #1
backup_r6_divide_int .blkw #1
backup_r7_divide_int .blkw #1
divideint_DEC_0 .fill #0
