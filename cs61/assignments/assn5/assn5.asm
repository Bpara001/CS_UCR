 ;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn4
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;=================================================
; MAIN code block
;-read ints -> [uses read_int]
;-multiply ints-> [uses multiply_int]
;-output ints -> [uses output_int ->[uses divide_int] ]
;-restart program option
;=================================================
.orig x3000
main_start

;-------------------
; INSTRUCTIONS; main
;-------------------
;1.READ INTS, R1 & R2
LD R6, read_int
JSRR R6                 ;call read_int twice
add R2, R1, #0
LD R6, read_int
JSRR R6                 ;inputs become r1 & r2

;2.Printing chars, x * y = z
LEA R0, dnewline
PUTS
ADD R0, R2,#0           ;call output_int
LD R6, output_int       ;output first number
JSRR R6
LD R0, ascii_star       ;output sstar character
OUT
ADD R0, R1,#0
LD R6, output_int       ;output second number
JSRR R6
LD R0, ascii_equal      ;output equal character
OUT

;3.MULTIPLY INTS,R1 * R2 = R0
LD R6, multiply_int     ;call multiply_int
JSRR R6
LD R6, output_int       ;output product to console
JSRR R6

;4.ALLOW USER TO RE-RUN PROGRAM
LEA R0,message1         ;display Restart instructions
PUTS
GETC                    ;get user input
out
ADD R1,R0,#0
LEA R0,message2         ;display white space
puts
LD R2, ascii_y
ADD R1,R1,R2
BRz main_start          ;if user enters y, restart program
LEA R0,message3
PUTS
HALT
;------------------
; DATA; main
;------------------
read_int .fill x3200
multiply_int .fill x3400
output_int .fill x3600
dnewline .STRINGZ "\n"
ascii_star .fill #42
ascii_equal .fill #61
ascii_y .fill #-121
message1 .STRINGz "\nRestart program? (y/n):"
message2 .STRINGz "\n\n"
message3 .STRINGz "\n//END PROGRAM//"

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
;SUBROUTINE: read_int
;arguments: none
;return value: returns user INPUT of INT into R1
;================================================
;***** NOTICE: imported from assn4, made into subroutine*******
.orig x3200

;backup
ST R0, backup_r0_read_int
ST R2, backup_r2_read_int
ST R3, backup_r3_read_int
ST R4, backup_r4_read_int
ST R5, backup_r5_read_int
ST R6, backup_r6_read_int
ST R7, backup_r7_read_int
;-----------------------
; INSTRUCTIONS; read_int
;-----------------------
;NOTE: this subroutine is a 99% copy from my previous assn4
;------PART 1: READ THE STRING, make sure input is VALID-----;
readint_START_MAIN
LD R1, readint_data_ptr     ;set intinal pointers, array, and counters
LD R2, readint_DEC_0
LD R3, readint_DEC_0
LD R5, readint_ARRAY_1
readint_ARRAY_1 .BLKW #10
LEA R0,readint_message1     ;outputs introduction messages
PUTS
LEA R0,readint_message1a
PUTS

readint_WHILE_LOOP          ;accepts user input until they press enter key
    GETC
    OUT

    ;CHECK 1: make sure leading character is "+" or "-"
    ADD R2,R2, #0
    BRp readint_end_first_input_check
        LD R6,readint_DEC_n43
        ADD R0,R0,R6
        BRz readint_is_positive             ;check positive
            LD R6,readint_DEC_43
            ADD R0,R0,R6
            LD R6,readint_DEC_n45
            ADD R0,R0,R6
        BRz readint_is_negative             ;check negative
            readint_INVALID_INPUT           ;invalid input branch
                LEA R0, readint_message2
                PUTS
                BR readint_START_MAIN
            readint_is_positive
                LD R0,readint_DEC_0
                ST R0, readint_number_sign
                ADD R2, R2, #1
                BR readint_WHILE_LOOP
            readint_is_negative
                LD R0,readint_DEC_1
                ST R0, readint_number_sign
                ADD R2, R2, #1
                BR readint_WHILE_LOOP
    readint_end_first_input_check

    ;continue reading input, ends if "enter/return" is pressed
    ADD R0,R0, #-10
    readint_IF_STATEMENT_1
    BRz readint_TRUE_CONDITION_1
    readint_FALSE_CONDITION_1
        ADD R0,R0, #10
        STR R0, R1, #0
        ADD R1, R1, #1
        ADD R2, R2, #1
    ;check #1A: make sure max digits does not exceed 5
        ADD R2, R2, #-7
        BRz readint_INVALID_INPUT
        ADD R2,R2,#7
        BR readint_WHILE_LOOP
    readint_TRUE_CONDITION_1

;------PART2: Convert from ASCII to multiple real numbers;-----;
LDI R4, readint_HEX_4000             ;reset pointers and counters
ADD R2, R2, #-1
ADD R1, R4, #0
ADD R3, R2, #0

readint_FOR_LOOP_2
    LDR R0, R1, #0
    LD R4, readint_DEC_n58
    ADD R0, R0, R4
    ;CHECK 2: make sure input was a numbers
    readint_IF_STATEMENT_2
    BRn readint_TRUE_CONDITION_2
    readint_FALSE_CONDITION_2
        BR readint_INVALID_INPUT
    readint_TRUE_CONDITION_2
        LD R4, readint_DEC_58
        ADD R0, R0, R4
        LD R4, readint_DEC_n48
        ADD R0, R0, R4
        STR R0, R1, #0
        BR readint_END_IF_2
    readint_END_IF_2
    ADD R1, R1, #1
    ADD R2, R2, #-1
    BRp readint_FOR_LOOP_2
readint_END_LOOP_2

;------PART3:Convert from multiple real numbers to single real number---;
;RESETS COUNTERS
;R0 -> the number of the ptr
;R1 -> ptr to the array of data
;R2 -> the big number we are calculating
;R3 -> temp number to add to R2
;R4 -> counter starting from 0
;R5 -> counter j; used inside the nested FOR_LOOP(multiply loop)
;R6 -> counter i; describes 10^N

ADD R1, R1, #-1 ;start from the last element,minus the newline char
LD R2, readint_DEC_0
LD R4, readint_DEC_0
ADD R5, R3, #0
ST R5, readint_total_digits
LD R6, readint_DEC_0
;Converts the string of digits to a single one using METHOD 1
readint_addition_loop
LD R3, readint_DEC_0
LDR R0, R1, #0
LDR R3, R0, #0
ADD R5, R5, #0
BRn readint_end_addition_loop
    ADD R6, R4, #-1
    LD R5, readint_DEC_10
    ADD R4,R4, #0
    BRp readint_multiply_loop
        ADD R2, R0, #0
        BR readint_end_multiply_loop
    ;Multplies the digit by 10^N times
    readint_multiply_loop
        ADD R3,R3,R0
        ADD R5, R5, #-1
        BRp readint_multiply_loop
            ADD R6,R6,#-1
            BRn readint_end_multiply_loop
                ADD R0, R3, #0
                LD R3, readint_DEC_0
                LD R5, readint_DEC_10
                BR readint_multiply_loop
    readint_end_multiply_loop
    ;increments/decrements counters
    ADD R2, R2, R3
    LD R5, readint_total_digits
    ADD R5, R5,#-1
    ST R5, readint_total_digits
    ADD R4, R4, #1
    ADD R1, R1,-1
    BR readint_addition_loop
readint_end_addition_loop
;CHECK OVERFLOW
ADD R2,R2,#0
BRn readint_INVALID_INPUT

;------PART4: converts number to negative IF necessary---------
ADD R1, R2, #0
LD R2, readint_number_sign
BRz readint_not_negative        ;converts to two's complement IF necessary
    NOT R1,R1
    ADD R1,R1,#1
readint_not_negative

;restore&return
LD R0, backup_r0_read_int
LD R2, backup_r2_read_int
LD R3, backup_r3_read_int
LD R4, backup_r4_read_int
LD R5, backup_r5_read_int
LD R6, backup_r6_read_int
LD R7, backup_r7_read_int
RET
;------------------
; DATA; read_int
;------------------
backup_r0_read_int .blkw #1
backup_r2_read_int .blkw #1
backup_r3_read_int .blkw #1
backup_r4_read_int .blkw #1
backup_r5_read_int .blkw #1
backup_r6_read_int .blkw #1
backup_r7_read_int .blkw #1
readint_ARRAY_1 .fill x4000
readint_data_ptr .fill x4000
readint_total_digits .BLKW #1
readint_number_sign .BLKW #1
readint_DEC_n58 .fill #-58
readint_DEC_n48 .fill #-48
readint_DEC_n45 .fill #-45
readint_DEC_n43 .fill #-43
readint_DEC_0 .fill #0
readint_DEC_1 .fill #1
readint_DEC_10 .fill #10
readint_DEC_43  .fill #43
readint_DEC_45  .fill #45
readint_DEC_58 .fill #58
readint_message1 .STRINGZ"\nType int[-32768,+32767],preceded with +/-, "
readint_message1a .STRINGZ "\nPress 'Enter' to finish: "
readint_message2 .STRINGZ "\n\n!!!ERROR!!!\nInvalid input!!!\n\n"
readint_HEX_4000 .fill x5000
.orig x5000
.fill x4000

.end
