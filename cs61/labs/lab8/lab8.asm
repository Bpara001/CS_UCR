.orig x3000
;=============================
;MAIN CODE BLOCK: instructions
;=============================
LD R0, array_ptr
LD R6, get_string
JSRR R6
LD R6, is_palindrome
JSRR R6

HALT
;=============================
;MAIN COde BLOCK; data
;=============================
get_string .fill x3200
is_palindrome .fill x3400
array_ptr .fill x4000

;-----------------------------------------------------------------------------------------------
; Subroutine: SUB_GET_STRING
; Parameter (R0): The address of where to start storing the string
; Postcondition: The subroutine has allowed the user to input a string,
; terminated by the [ENTER] key, and has stored it in an array
; that starts at (R0) and is NULL-terminated.
; Return Value: R5 <- The number of non-sentinel characters read from the user
;-----------------------------------------------------------------------------------------------
.orig x3200
;------------------------
;get_string instructions
;------------------------
ST R0, R0_GETSTRING
ST R1, R1_GETSTRING
ST R2, R2_GETSTRING
ST R3, R3_GETSTRING
ST R4, R4_GETSTRING
ST R6, R6_GETSTRING
ST R7, R6_GETSTRING

;R0 -> inputed data
;R1 -> array_ptr
;R5 -> char counter
ADD R1,R0,#1
LD R5, getstring_DEC_0
LEA R0, getstring_message1
PUTS

INPUT_LOOP
    GETC
    OUT
    ADD R0, R0, #-10
    BRz END_INPUT_LOOP
    ADD R0, R0, #10

    ;ignore punctuation1
    getstring_check1
        LD R4, getstring_n122
        ADD R0,R0,R4
        BRp INPUT_LOOP
        LD R4, getstring_122
        ADD R0,R0,R4

    ;not case sensitive
    getstring_check2
        LD R4, getstring_n97
        ADD R0, R0, R4
        BRzp getstring_convert
        LD R4, getstring_97
        ADD R0, R0, R4
        BR getstring_check3
    getstring_end_check2

    ;ignore punctuation2
    getstring_check3
        LD R4, getstring_n90
        ADD R0,R0,R4
        BRp INPUT_LOOP
        LD R4, getstring_90
        ADD R0,R0,R4

    ;ignore punctuation3
    getstring_check4
        LD R4, getstring_n63
        ADD R0, R0, R4
        BRn INPUT_LOOP
        LD R4, getstring_63
        ADD R0, R0,R4

    BR getstring_end_checks

    ;fixes if check is true
    getstring_convert
        LD R4, getstring_97
        ADD R0, R0, R4
        LD R4, getstring_n32
        ADD R0, R0, R4
        BR getstring_end_check2

    ;continue with logic
    getstring_end_checks
    ADD R5, R5, #1
    STR R0, R1, #0
    ADD R1,R1,#1
    BR INPUT_LOOP
END_INPUT_LOOP
NOT R6,R5
ADD R1,R1,R6
STR R5,R1,#0

LD R0, R0_GETSTRING
LD R1, R1_GETSTRING
LD R2, R2_GETSTRING
LD R3, R3_GETSTRING
LD R4, R4_GETSTRING
LD R6, R6_GETSTRING
LD R7, R6_GETSTRING
RET
;---------------------
;get string data
;--------------------
getstring_message1 .stringz "Press [enter] to end input:\n"
getstring_address_start .blkw #1
getstring_n63 .fill #-63
getstring_63 .fill#63
getstring_n90 .fill #-90
getstring_90 .fill #90
getstring_n122 .fill #-122
getstring_122 .fill #122
getstring_n32 .fill #-32
getstring_DEC_0 .fill #0
getstring_n65 .fill #-65
getstring_65 .fill #65
getstring_n97 .fill #-97
getstring_97 .fill #97
getstring_65 .fill #65
R0_GETSTRING .BLKW #1
R1_GETSTRING .BLKW #1
R2_GETSTRING .BLKW #1
R3_GETSTRING .BLKW #1
R4_GETSTRING .BLKW #1
R6_GETSTRING .BLKW #1
R7_GETSTRING .BLKW #1


;-----------------------------------------------------------------------------------------------
; Subroutine: SUB_IS_A_PALINDROME
; Parameter (R0): The address of a string
; Parameter (R5): The number of characters in the array.
; Postcondition: The subroutine has determined whether the string at (R0) is
;a palindrome or not returned a flag indicating such.
;Return Value: R4  {1 if the string is a palindrome,
;0 otherwise}
;-----------------------------------------------------------------------------------------------
.orig x3400
;-------------------------
;is_palindrome instructions
;--------------------------
ST R0, R0_ISPALINDROME
ST R1, R1_ISPALINDROME
ST R2, R2_ISPALINDROME
ST R3, R3_ISPALINDROME
ST R5, R5_ISPALINDROME
ST R6, R6_ISPALINDROME
ST R7, R7_ISPALINDROME

;calculate # of chars / 2
ADD R4, R0,#1
LDR R1, R0, #0
ADD R5, R0, R1
LD R6, ispalindrome_divide_int
LD R2, ispalindrome_dec_2
JSRR R6
ADD R3,R0,#0
ADD R6,R0,#0


;R2 -> value of front
;R3 -> value of back
;R4 -> ptr_front_counter
;R5 -> ptr_back_counter
;R6 -> # of chars /2
ispalindrome_logic_loop
    LDR R2, R4, #0
    LDR R3, R5, #0
    NOT R2,R2
    ADD R2,R2,#1
    ADD R2,R2,R3
    BRnp ispalindrome_false
    ADD R4,R4,#1
    ADD R5,R5,#-1
    ADD R6,R6,#-1
    BRz ispalindrome_true
    BR ispalindrome_logic_loop

ispalindrome_true
    LEA R0,ispalindrome_message_true
    PUTS
    BR end_ispalindrome

ispalindrome_false
    LEA R0,ispalindrome_message_false
    PUTS

end_ispalindrome
LD R0, R0_ISPALINDROME
LD R1, R1_ISPALINDROME
LD R2, R2_ISPALINDROME
LD R3, R3_ISPALINDROME
LD R5, R5_ISPALINDROME
LD R6, R6_ISPALINDROME
LD R7, R7_ISPALINDROME
RET

;--------------------------
;is_palindrome instructions
;--------------------------
R0_ISPALINDROME .BLKW #1
R1_ISPALINDROME .BLKW #1
R2_ISPALINDROME .BLKW #1
R3_ISPALINDROME .BLKW #1
R5_ISPALINDROME .BLKW #1
R6_ISPALINDROME .BLKW #1
R7_ISPALINDROME .BLKW #1
ispalindrome_n97 .fill #-97
ispalindrome_97 .fill #97
ispalindrome_n65 .fill #-65
ispalindrome_65 .fill #65
ispalindrome_message_true .stringz "THIS IS A PALINDROME\n"
ispalindrome_message_false .stringz "THIS IS NOT A PALINDROME\n"
ispalindrome_dec_2 .fill #2
ispalindrome_divide_int .fill x3600

;================================================
;SUBROUTINE: divide_int
;arguments: divides R1 by R2
;return value:(R1/R2) = R0; quotient -> R0, remainder -> R3
;================================================
;NOTE: this subroutine is a 108% copy from my previous assn5
.orig x3600

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
