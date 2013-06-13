 ;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn6
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;=================================================
; MAIN code block
;=================================================
.orig x3000
main_start

;-------------------
; INSTRUCTIONS; main
;-------------------
;1.READ INTS, R1 & R2
LD R6, read_int
JSRR R6                 ;call read_int

;2. CONVERT&OUTPUT DEC TO HEX
LD R6, hexconvert
JSRR R6

;3.ALLOW USER TO RE-RUN PROGRAM
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
ascii_y .fill #-121
read_int .fill x3200
hexconvert .fill x3600
message1 .STRINGz "\nRestart program? (y/n):"
message2 .STRINGz "\n\n"
message3 .STRINGz "\n//END PROGRAM//"

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
;NOTE: this subroutine is a 98% copy from my previous assn4&assn5
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
                BR readint_is_negative
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
readint_DEC_n43 .fill #-35
readint_DEC_0 .fill #0
readint_DEC_1 .fill #1
readint_DEC_10 .fill #10
readint_DEC_43  .fill #35
readint_DEC_45  .fill #45
readint_DEC_58 .fill #58
readint_message1 .STRINGZ"\nType int[0,65535],preceded with #, "
readint_message1a .STRINGZ "\nPress 'Enter' to finish: "
readint_message2 .STRINGZ "\n\n!!!ERROR!!!\nInvalid input!!!\n\n"
readint_HEX_4000 .fill x5000
.orig x5000
.fill x4000


;================================================
;SUBROUTINE: divide_int
;arguments: divides R1 by R2
;return value:(R1/R2) = R0; quotient -> R0, remainder -> R3
;================================================
;NOTE: this subroutine is a 108% copy from my previous assn5
.orig x3400

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
;SUBROUTINE: hexconvert
;arguments: R0 contains an int value
;return value: outputs the int value as its hex value equivilant
;================================================
.orig x3600

;backup
ST R0, backup_r0_hexconvert
ST R1, backup_r1_hexconvert
ST R2, backup_r2_hexconvert
ST R3, backup_r3_hexconvert
ST R4, backup_r4_hexconvert
ST R5, backup_r5_hexconvert
ST R6, backup_r6_hexconvert
ST R7, backup_r7_hexconvert

;-------------------------
; INSTRUCTIONS; hexconvert
;-------------------------
hexconvert_START_MAIN

add R1,R1,#0            ;check which case to go to, DOES IT OVERFLOW??
BRn hexconvert_case2

;CASE1, number does not overflow
hexconvert_case1
    LD R4, hexconvert_numbers
    LD R6, hexconvert_divide            ;storing first hex
    LD R2, hexconvert_dec_4096
    JSRR R6
    STR R0, R4, #0
    ADD R1, R3, #0                      ;storing second hex
    LD R2, hexconvert_dec_256
    JSRR R6
    STR R0, R4, #1
    ADD R1,R3,#0                        ;storing third &fourth hex
    LD R2, hexconvert_dec_16
    JSRR R6
    STR R0, R4, #2
    STR R3, R4, #3
    BR hexconvert_end_storage

;CASE2, number OVERFLOWS , (negative number)
hexconvert_case2
    NOT R1, R1
    ADD R1, R1, #0                     ;invert to positive equivlant
    LD R4, hexconvert_numbers
    LD R6, hexconvert_divide            ;storing first hex
    LD R2, hexconvert_dec_4096
    JSRR R6
    NOT R0, R0
    ADD R0, R0, #1
    ADD R0, R0, #15
    STR R0, R4, #0
    ADD R1, R3, #0                      ;storing second hex
    LD R2, hexconvert_dec_256
    JSRR R6
    NOT R0, R0
    ADD R0, R0, #1
    ADD R0, R0, #15
    STR R0, R4, #1
    ADD R1,R3,#0                        ;storing third &fourth hex
    LD R2, hexconvert_dec_16
    JSRR R6
    NOT R0, R0
    ADD R0, R0, #1
    ADD R0, R0, #15
    STR R0, R4, #2
    NOT R3, R3
    ADD R3, R3, #1
    ADD R3, R3, #15
    STR R3, R4, #3
hexconvert_end_storage


;OUTPUT the hex to console
;R4 -> ptr
;R5 -> counter
LD R0, hexconvert_ascii_x
LD R5, hexconvert_dec_4
out

hexconvert_output                   ;check; output number or letter?
    ADD R5, R5, #-1
    BRn end_hexconvert_output
    LDR R0, R4, #0
    ADD R0,R0, #-10
    BRn  hexconvert_number
hexconvert_letter                   ;CASE1, output letter
    ADD R0,R0,#10
    LD R1, hexconvert_dec_55
    ADD R0,R0,R1
    out
    ADD R4,R4, #1
    BR hexconvert_output
    end_hexconvert_letter
hexconvert_number                   ;CASE2, output number
    ADD R0,R0,#10
    LD R1, hexconvert_dec_48
    ADD R0,R0,R1
    out
    ADD R4,R4, #1
    BR hexconvert_output
    end_hexconvert_number
end_hexconvert_output

;restore&return
LD R0, backup_r0_hexconvert
LD R1, backup_r1_hexconvert
LD R2, backup_r2_hexconvert
LD R3, backup_r3_hexconvert
LD R4, backup_r4_hexconvert
LD R5, backup_r5_hexconvert
LD R6, backup_r6_hexconvert
LD R7, backup_r7_hexconvert
RET

;------------------
; DATA; hexconvert
;------------------
hexconvert_numbers .fill x3590
hexconvert_dec_4096 .fill #4096
hexconvert_dec_256 .fill #256
hexconvert_dec_16 .fill #16
hexconvert_dec_0 .fill #0
hexconvert_dec_55 .fill #55
hexconvert_dec_48 .fill #48
hexconvert_ascii_x .fill 120
hexconvert_dec_4 .fill #4
hexconvert_divide .fill x3400
backup_r0_hexconvert .blkw #1
backup_r1_hexconvert .blkw #1
backup_r2_hexconvert .blkw #1
backup_r3_hexconvert .blkw #1
backup_r4_hexconvert .blkw #1
backup_r5_hexconvert .blkw #1
backup_r6_hexconvert .blkw #1
backup_r7_hexconvert .blkw #1

