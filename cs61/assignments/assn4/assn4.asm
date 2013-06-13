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

;------------------
; INSTRUCTIONS
;------------------
.orig x3000

;------PART 1: READ THE STRING, make sure input is VALID-----;
START_MAIN
LD R1, data_ptr     ;set intinal pointers, array, and counters
LD R2, DEC_0
LD R3, DEC_0
LD R5, ARRAY_1
ARRAY_1 .BLKW #10
LEA R0,message1     ;outputs introduction messages
PUTS
LEA R0,message1a
PUTS

WHILE_LOOP          ;accepts user input until they press enter key
    GETC
    OUT

    ;CHECK 1: make sure leading character is "+" or "-"
    ADD R2,R2, #0
    BRp end_first_input_check
        LDI R6,DEC_n43
        ADD R0,R0,R6
        BRz is_positive             ;check positive
            LDI R6,DEC_43
            ADD R0,R0,R6
            LDI R6,DEC_n45
            ADD R0,R0,R6
        BRz is_negative             ;check negative
            INVALID_INPUT           ;invalid input branch
                LEA R0, message2
                PUTS
                BR START_MAIN
            is_positive
                LD R0,DEC_0
                ST R0, number_sign
                ADD R2, R2, #1
                BR WHILE_LOOP
            is_negative
                LD R0,DEC_1
                ST R0, number_sign
                ADD R2, R2, #1
                BR WHILE_LOOP
    end_first_input_check

    ;continue reading input, ends if "enter/return" is pressed
    ADD R0,R0, #-10
    IF_STATEMENT_1
    BRz TRUE_CONDITION_1
    FALSE_CONDITION_1
        ADD R0,R0, #10
        STR R0, R1, #0
        ADD R1, R1, #1
        ADD R2, R2, #1
    ;check #1A: make sure max digits does not exceed 5
        ADD R2, R2, #-7
        BRz INVALID_INPUT
        ADD R2,R2,#7
        BR WHILE_LOOP
    TRUE_CONDITION_1

;------PART2: Convert from ASCII to multiple real numbers;-----;
LDI R4, HEX_4000             ;reset pointers and counters
ADD R2, R2, #-1
ADD R1, R4, #0
ADD R3, R2, #0

FOR_LOOP_2
    LDR R0, R1, #0
    LDI R4, DEC_n58
    ADD R0, R0, R4
    ;CHECK 2: make sure input was a numbers
    IF_STATEMENT_2
    BRn TRUE_CONDITION_2
    FALSE_CONDITION_2
        BR INVALID_INPUT
    TRUE_CONDITION_2
        LDI R4, DEC_58
        ADD R0, R0, R4
        LDI R4, DEC_n48
        ADD R0, R0, R4
        STR R0, R1, #0
        BR END_IF_2
    END_IF_2
    ADD R1, R1, #1
    ADD R2, R2, #-1
    BRp FOR_LOOP_2
END_LOOP_2

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
LD R2, DEC_0
LD R4, DEC_0
ADD R5, R3, #0
ST R5, total_digits
LD R6, DEC_0

;Converts the string of digits to a single one using METHOD 1
addition_loop
LD R3, DEC_0
LDR R0, R1, #0
LDR R3, R0, #0
ADD R5, R5, #0
BRn end_addition_loop
    ADD R6, R4, #-1
    LD R5, DEC_10
    ADD R4,R4, #0
    BRp multiply_loop
        ADD R2, R0, #0
        BR end_multiply_loop

    ;Multplies the digit by 10^N times
    multiply_loop
        ADD R3,R3,R0
        ADD R5, R5, #-1
        BRp multiply_loop
            ADD R6,R6,#-1
            BRn end_multiply_loop
                ADD R0, R3, #0
                LD R3, DEC_0
                LD R5, DEC_10
                BR multiply_loop
    end_multiply_loop

    ;increments/decrements counters
    ADD R2, R2, R3
    LD R5, total_digits
    ADD R5, R5,#-1
    ST R5, total_digits
    ADD R4, R4, #1
    ADD R1, R1,-1
    BR addition_loop
end_addition_loop

;------PART4: converts number to negative IF necessary---------
ADD R1, R2, #0
LD R2, number_sign
BRz not_negative        ;converts to two's complement IF necessary
    NOT R1,R1
    ADD R1,R1,#1
not_negative
HALT

;------------------
; DATA
;------------------
ARRAY_1 .fill x4000
data_ptr .fill x4000
total_digits .BLKW #1
number_sign .BLKW #1

DEC_0 .fill #0
DEC_1 .fill #1
DEC_10 .fill #10

message1 .STRINGZ "\nEnter an integer[‐32768,+32767],\npreceded with +/-, "
message1a .STRINGZ "ex.\"+1523\",\nPress Enter to finish\n  Entered data: "
message2 .STRINGZ "\n\n!!!ERROR!!!ERROR!!!ERROR!!!\nInvalid input!!!\n\n"
DEC_n48 .fill x5000
DEC_n58 .fill x5001
DEC_58 .fill x5003
HEX_4000 .fill x5004
DEC_43  .fill x5005
DEC_n43 .fill x5006
DEC_45  .fill x5007
DEC_n45 .fill x5008

.orig x5000
.fill #-48
.fill #-58
.fill #-64
.fill #58
.fill x4000
.fill #43
.fill #-43
.fill #45
.fill #-45

.end

