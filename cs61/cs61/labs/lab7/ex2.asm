;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab7
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;==============================================
;//////////////////////////////////////////////
;/////////////   MAIN FUNCTION   //////////////
;//////////////////////////////////////////////
;==============================================
.orig x3000
LD R6,SUB_READINT           ;Load READ INT SUBROUTINE
LD R5,SUB_GET1              ;LOD GET1 SUBROUTINE

LEA R0,string1              ;load intro string1
PUTS                        ;output

JSRR R6                     ;execute READ INT SUBROUTINE

LEA R0,string2              ;load string2
PUTS                        ;output string2


JSRR R5                     ;execute GET1 SUBROUTINE

LD R1,dec48                 ;convert number into ascii
ADD R0,R0,R1
OUT                         ;output final answer




HALT
;----------------------------
;MAIN->DATA
;------------------------------
SUB_READINT .fill x3200
SUB_GET1 .fill x3600
string1 .stringz "Input a number between 0 to 32767"
string2 .stringz "The number of 1's is: "
dec48 .fill #48




;====================================================
;SUBROUTINE: ReadINT
;Input void, no arguments needed
;Postcondition: gets inputted string int, checks for valid input
;Return Value: R1 = user input
 .orig x3200
;=====================================================
;---------------------------
;INSTRUCTIONS : READ INT
;----------------------------
;(1)Backup all modified registers except Return Value
ST R0, readint_backup_r0        ;back up R0
ST R2, readint_backup_r2        ;back up R2
ST R3, readint_backup_r3        ;back up R3
ST R4, readint_backup_r4        ;back up R4
ST R5, readint_backup_r5        ;back up R5
ST R6, readint_backup_r6        ;back up R6
ST R7, readint_backup_r7        ;back up  R7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;Print arrow
LD R0, readint_dec0
LEA R0,readint_string1              ;load into R0
PUTS                                ;output to console
readint_end_check1
;Get user input for number ascci chars, convert on fly
LD R1, readint_dec0             ;R1 -> 0
LD R2, readint_dec10            ;R2 -> 10
LD R3, readint_dec0             ;R3 -> total number
LD R4, readint_decn38           ;R4  -> -48
LD R6, readint_SUB_Multiply     ;R6 -> function for multiply
readint_loop1
    GETC                ;get user input
    OUT
    ADD R0,R0,#-10      ;check if 'enter'
    BRz readint_end_loop1
    ADD R5,R0,R4
    ADD R1,R3,#0        ;call multiply -> total(R3) * 10
    JSRR R6
    ADD R3,R0,R5        ;add R0 to (total(R3) * 10)
    BR readint_loop1
readint_end_loop1
BR readint_end_main
;IF invalid input, do THIS:
readint_invalid_input
readint_end_invalid_input
;print ending message,prompt restart
readint_end_main
ADD R1,R3,#0            ;store total number into R1

;(3)Restore all modified registers except Return Values
LD R0, readint_backup_r0        ;restore R0
LD R2, readint_backup_r2        ;restore R2
LD R3, readint_backup_r3        ;restore R3
LD R4, readint_backup_r4        ;restore R4
LD R5, readint_backup_r5        ;restore R5
LD R6, readint_backup_r6        ;restore R6
LD R7, readint_backup_r7        ;restore R7
;(4)Return to where you came from
RET
;----------------------------
;Data block-> Read Int
;------------------------------
readint_backup_r0 .blkw #1
readint_backup_r2 .blkw #1
readint_backup_r3 .blkw #1
readint_backup_r4 .blkw #1
readint_backup_r5 .blkw #1
readint_backup_r6 .blkw #1
readint_backup_r7 .blkw #1
readint_SUB_Multiply .fill x3400
readint_signflag .blkw #1
readint_string1 .stringz "->"
readint_string3 .stringz "\nERROR:: INVALID INPUT!\nREENTER"
readint_dec0 .fill #0
readint_dec1 .fill #1
readint_dec10 .fill #10
readint_decn38 .fill #-38
readint_ascii_plus .fill #43
readint_ascii_minus .fill #45
readint_ascii_nplus .fill #-43
readint_ascii_nminus .fill #-45




;================================================
;SUBROUTINE: Multiply
;arguments: R1 <- first RAW number
;           R2 <- second RAW number
;return value: R0 <- product
;example: R0 = R1 * R2
.orig x3400
;================================================
;-------------------------
; INSTRUCTIONS; Multiply
;-------------------------
;(1)Backup all modified registers except Return Value
ST R1, multi_backup_r1
ST R2, multi_backup_r2
ST R7, multi_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R0,multi_decn1
ST R0,multi_xflag
ST R0,multi_yflag
LD R0,multi_dec1
;check if bits are zero or neg, invert if neg, return 0 if zero
ADD R1,R1,#0            ;check R1
BRz multi_endz           ;checking if zero
BRn multi_xchange       ;checking if negative
multi_continue1
ADD R2,R2,#0            ;check R2
BRz multi_endz           ;chicking if zero
BRn multi_ychange       ;checking if negative
BR multi_input_end
multi_xchange           ;When X is negative, invert and set bitflag to 1
    NOT R1,R1
    ADD R1,R1,#1
    ST R0,multi_xflag
    BR multi_continue1
multi_ychange           ;WHen Y is negative, intert and set bitflag to 1
    NOT R2,R2
    ADD R2,R2,#1
    ST R0,multi_yflag
multi_input_end
;check to see if using more efficent multiplication & swap if needed
LD R0,multi_dec1
NOT R0,R1                ;invert R1 so we can subtract
ADD R0,R0,#1             ;convert into two's complement number
ADD R0,R0,R2             ;subtract
Brp multi_end_check     ;swwap only if R1 - R2 < 0
ADD R0,R2,#0            ;set R0(temp) = R2
ADD R2,R1,#0            ;set R2 = R1
ADD R1,R0,#0            ;set R1 = R0(temp
multi_end_check
;begin adding loop (multiplication logic)
LD R0,multi_dec0
multi_loop1             ;adds R1 to itself R2 times, stores in R0
    ADD R0,R1,R0
    BRn multi_errors    ;check for overflow/underflow, branch if needed
    ADD R2,R2,#-1       ;decrement counter
    BRp multi_loop1
multi_loop1end
;check for sign change
LD R1,multi_xflag       ;load the sign flag of first number
LD R2,multi_yflag       ;load the sign flag of the second number
ADD R1,R1,R2            ;add together, to figure out if product needs to be neg
BRnp multi_end          ;if applicable dont change and leave positive
NOT R0,R0               ;make into inverse and change to negative number
ADD R0,R0,#1
BR multi_end
;overload/underload data block
multi_errors
    LD R1,multi_xflag   ;load sign flag for first and second argument
    LD R2,multi_yflag
    ADD R1,R1,R2        ;add together to figure otu if it overflowed or under
    BRnp multi_overload
        LEA R0,multi_underflow ;print out underflow if was negative
        PUTS
        BR multi_end
    multi_overload
        LEA R0,multi_overflow   ;print out overflow if was positive
        PUTS
        BR multi_end
multi_endz              ;if one of the arugemnts were zero, return 0
    LD R0,multi_dec0
multi_end
;(3)Restore all modified registers except Return Values
LD R1, multi_backup_r1
LD R2, multi_backup_r2
LD R7, multi_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Multiply
;------------------
multi_bitflag   .blkw #1
multi_xflag     .blkw #1
multi_yflag     .blkw #1
multi_backup_r1 .blkw #1
multi_backup_r2 .blkw #1
multi_backup_r7 .blkw #1
multi_decn1 .fill #-1
multi_dec0 .fill #0
multi_dec1 .fill #1
multi_overflow  .stringz "\nWoes! Overflows!\n"
multi_underflow .stringz "\nWoahs! Underflows!\n"



;====================================================
;SUBROUTINE: SUB Get number of 1's
;Input R1 <- gets number of binary 1's
;Postcondition: Returns number of binary 1's in R0
;Return Value: Number is stored in R0
 .ORIG x3600
;=====================================================

;-------------------------
; INSTRUCTIONS; GET1
;-------------------------

;(1)Backup all modified registers except Return Value
ST R1, get1_backup_r1
ST R2, get1_backup_r2
ST R3, get1_backup_r3
ST R4, get1_backup_r4
ST R5, get1_backup_r5
ST R6, get1_backup_r6
ST R7, get1_backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R2,get1_16           ;R2 <- counter
LD R3,get1_0            ;R3 <- total one's

get1_forloop1                   ;for(int i = 0 ; i < 16; i++)
    ADD R1,R1,#0                 ;if(number < 0) ;do not add 1 to total
    BRzp get1_negative_end
        ADD R3,R3,#1            ;if(number > 0) add 1 to total
    get1_negative_end
    ADD R1,R1,R1                ;left shift
    ADD R2,R2,#-1               ;decrement counter
    BRp get1_forloop1           ;repeat loop if counter holds
get1_forloop_end

ADD R0,R3,#0                ;copy total to R0 (return value)



;(3)Restore all modified registers except Return Values
LD R1, get1_backup_r1
LD R2, get1_backup_r2
LD R3, get1_backup_r3
LD R4, get1_backup_r4
LD R5, get1_backup_r5
LD R6, get1_backup_r6
LD R7, get1_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; GET1
;------------------
get1_backup_r1 .blkw #1
get1_backup_r2 .blkw #1
get1_backup_r3 .blkw #1
get1_backup_r4 .blkw #1
get1_backup_r5 .blkw #1
get1_backup_r6 .blkw #1
get1_backup_r7 .blkw #1
get1_0  .fill #0
get1_16  .fill #16

.end                        ;signals end of prgroam

