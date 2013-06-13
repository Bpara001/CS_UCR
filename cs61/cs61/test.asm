;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn5
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

start

;Prompt instructions and introduction
LEA R0,string1          ;load introduction message1
PUTS                    ;output to console
LEA R0,string2          ;load introduction message2
PUTS                    ;output to cnosole
;Get user input
LD R6,SUB_readint       ;load subroutine into R6
JSRR R6                 ;call subroutine, get first input
ADD R3,R1,#0            ;copy input value into R2
JSRR R6                 ;call subroutine, get second input
ADD R2,R1,#0
ADD R1,R3,#0
;Multiply the numbers (R1 * R2), print equation
LD R6,SUB_outint        ;load output subroutine
JSRR R6                 ;call output subroutine
LEA R0,string3          ;load R0 with string equation pt1
PUTS                    ;output to console
ADD R1,R2,#0            ;put second input as argument
JSRR R6                 ;load output subroutine
LEA R0,string3a         ;load R0 with string equation pt2
PUTS                    ;otuput to console
ADD R2,R3,#0            ;set multiplers up
LD R5, SUB_multiply     ;load R6 with multiply subroutine
JSRR R5                 ;call subroutine, get product
ADD R1,R0,#0            ;copy product into R1 for argument of output fucntion
JSRR R6                 ;call subroutine, output the number

BR start

HALT
;----------------------------
;Data block -> main
;------------------------------
SUB_readint .fill x3200
SUB_outint  .fill x3400
SUB_multiply .fill x3600
string1 .stringz "Input 2 numbers (max 5 digits),preceded with +/-,"
string2 .stringz "followed by ENTER \nEX: '+14250'\n\n"
string3 .stringz " * "
string3a .stringz " = "


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
readint_start_main
LD R0, readint_dec0
ST R0, readint_signflag             ;set sign flag to defualt "0"
LEA R0,readint_string1              ;load into R0
PUTS                                ;output to console
;ERROR CHECK: make sure first char is "+" or "-"
readint_check1
    GETC                            ;get user input
    OUT                             ;echo to console
    LD R1,readint_ascii_nplus       ;testing "+"
    ADD R0,R0,R1                    ;check if "+"
    Brz readint_end_check1
    LD R1,readint_ascii_plus
    ADD R0,R0,R1                    ;checking R0
    LD R1,readint_ascii_nminus      ;testing "-"
    ADD R0,R0,R1                    ;checking R0
    BRnp readint_invalid_input      ;if invalid, go to invalid block
    LD R1,readint_dec1
    ST R1,readint_signflag           ;set sign flag to neg if appliciable
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
    BRn readint_invalid_input   ;ERROR CHECK: check if input was num char
    ADD R5,R5,#-9
    BRp readint_invalid_input
    ADD R5,R5,#9
    ADD R1,R3,#0        ;call multiply -> total(R3) * 10
    JSRR R6
    ADD R3,R0,R5        ;add R0 to (total(R3) * 10)
    BRn readint_invalid_input   ;ERROR CHECK: check if input is too large
    BR readint_loop1
readint_end_loop1
;sign check and change sign if applicable
LD R0,readint_signflag
    BRz readint_end_signchange
    NOT R3,R3               ;if negative, invert number & add 1
    ADD R3,R3,#1
    readint_end_signchange
BR readint_end_main
;IF invalid input, do THIS:
readint_invalid_input
    LEA R0,readint_string3      ;output error message,. restart
    PUTS
    BR readint_start_main
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
readint_SUB_Multiply .fill x3600
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


;====================================================
;SUBROUTINE: SUB_Output Int
;Input R1 <- The integer we need to output
;Postcondition: gets the value of R1 and outputs to console
;Return Value: none. outputs with format: (-1234) or (+9873)
 .ORIG x3400
;=====================================================
;-------------------------
; INSTRUCTIONS; Output Int
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, outint_backup_r0
ST R1, outint_backup_r1
ST R2, outint_backup_r2
ST R3, outint_backup_r3
ST R4, outint_backup_r4
ST R5, outint_backup_r5
ST R6, outint_backup_r6
ST R7, outint_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;CHeck sign and inverse if applicable, also print correct sign character
LD R0,outint_par1               ;output first parentheses
OUT
ADD R1,R1,#0                    ;checking R1
BRzp outint_if1                 ;If positive, go to positive char block
BRn outint_if2                  ;If negative, go to negative char block
outint_if1                      ;positive block
    LD R0,outint_plus           ;output plus sign
    OUT
    BR outint_checks_end
outint_if2                      ;negative block
    NOT R1,R1                   ;inverse R1
    ADD R1,R1,#1                ;add for twos complement conversion
    LD R0,outint_minus          ;output negative sign
    OUT
    BR outint_checks_end
outint_checks_end
;Divide R1 by 10 until q=0, Store remainders in temp array
LD R2, outint_dec10             ;divide by 10
LD R4, outint_dec0              ;R4 = char counter
LD R5, outint_ptr               ;R5 = pointer to temp array
LD R6, outint_DIVIDE            ;R6 = Divide subroutine
outint_while1                   ;while q > 0
    JSRR R6                     ;preform divide function
    ADD R1,R0,#0                ;Set R1 to be quotient
    STR R3,R5,#0                ;store remainder in array
    ADD R4,R4,#1                ;increment total char counter
    ADD R5,R5,#-1               ;move ptr to array
    ADD R0,R0,#0                ;check to see if we need to dvide anymore
    BRnp outint_while1          ;If we do, then continue while loop
;Transverse array and print out the contents & print parentheses
LD R1,outint_dec48              ;set R1 as a const to convert to ascii
outint_while2                   ;while there are digits left
    ADD R5,R5,#1                ;increments ptr
    LDR R0,R5,#0                ;loads  hard value into R0
    ADD R0,R0,R1                ;converts value into ascii
    OUT                         ;outputs to console
    ADD R4,R4,#-1               ;decrements counter
    BRp outint_while2           ;go back to loop if chars remain
LD R0,outint_par2               ;output closing parentheses
OUT
;(3)Restore all modified registers except Return Values
LD R0, outint_backup_r0
LD R1, outint_backup_r1
LD R2, outint_backup_r2
LD R3, outint_backup_r3
LD R4, outint_backup_r4
LD R5, outint_backup_r5
LD R6, outint_backup_r6
LD R7, outint_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Output INt
;------------------
outint_DIVIDE   .fill x3800
outint_backup_r0 .blkw #1
outint_backup_r1 .blkw #1
outint_backup_r2 .blkw #1
outint_backup_r3 .blkw #1
outint_backup_r4 .blkw #1
outint_backup_r5 .blkw #1
outint_backup_r6 .blkw #1
outint_backup_r7 .blkw #1
outint_ptr      .fill x3500
outint_dec0     .fill #0
outint_par1     .fill #40
outint_par2     .fill #41
outint_plus     .fill #43
outint_minus    .fill #45
outint_dec10    .fill #10
outint_dec1     .fill #1
outint_dec48    .fill #48


;================================================
;SUBROUTINE: Multiply
;arguments: R1 <- first RAW number
;           R2 <- second RAW number
;return value: R0 <- product
;example: R0 = R1 * R2
.orig x3600
;================================================
;-------------------------
; INSTRUCTIONS; Multiply
;-------------------------
;(1)Backup all modified registers except Return Value
ST R1, multi_backup_r1
ST R2, multi_backup_r2
ST R3, multi_backup_r3
ST R7, multi_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R0,multi_dec0
ST R0,multi_bitflag
;check if multiply by zero
ADD R1,R1,#0
BRz multi_end
ADD R2,R2,#0
BRz multi_end
;check to see if using more efficent multiplication
NOT R0,R1                ;invert R1 so we can subtract
ADD R0,R0,#1             ;convert into two's complement number
ADD R0,R0,R2             ;subtract
Brp multi_end_check     ;swwap only if R1 - R2 < 0
;swap if applicable
ADD R0,R2,#0            ;set R0(temp) = R2
ADD R2,R1,#0            ;set R2 = R1
ADD R1,R0,#0            ;set R1 = R0(temp
multi_end_check
;check R2 leading sign, invert if applicable and set sign flag
ADD R2,R2,#0
BRp multi_end_check2
NOT R2,R2
ADD R2,R2,#1
LD R0,multi_dec0
ST R0,multi_bitflag
multi_end_check2
;begin adding loop (multiplication logic)
LD R0,multi_dec0
;adds R1 to itself R2 times, stores in R0
multi_loop1
    ADD R0,R1,R0
    ADD R2,R2,#-1       ;decrement counter
    BRp multi_loop1
multi_loop1end
;check for sign change
LD R1,multi_bitflag
BRz multi_end
NOT R0,R0
ADD R0,R0,#1

multi_end
;(3)Restore all modified registers except Return Values
LD R1, multi_backup_r1
LD R2, multi_backup_r2
LD R3, multi_backup_r3
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
multi_backup_r3 .blkw #1
multi_backup_r7 .blkw #1
multi_dec0 .fill #0
multi_dec1 .fill #0
multi_overflow  .stringz "Woes! Overflows!"
multi_underflows .stringz "Woahs! Underflows!"

;====================================================
;SUBROUTINE: Divide
;Input: Divides R1 / R2; q = n/d, remainder r
;Postcondition: Divdes R1 / R2 ; R0 = value; R3 = remainder
;Return Value: R0 = value, R3 = remainder
 .ORIG x3800
;=====================================================
;-------------------------
; INSTRUCTIONS; Divide
;-------------------------
;(1)Backup all modified registers except Return Value
ST R1, divide_backup_r1
ST R2, divide_backup_r2
ST R4, divide_backup_r4
ST R6, divide_backup_r6
ST R7, divide_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;Do division algoritum
LD R0, divide_dec0          ;set R0(q) = 0
LD R3, divide_dec0          ;set R3(r) = 0
NOT R2, R2                  ;set R2 to -R2
ADD R2, R2, #1              ;needed for twos complement conversion
divide_while1               ;n-d = temp
    ADD R4, R1, R2          ;R4 = temp
    BRz divide_ifz          ;check: temp == 0?
    BRn divide_ifn          ;check: temp < 0?
    ADD R0, R0, #1          ;Increment total divide answer by one (q)
    ADD R1, R4, #0          ;n = temp
    BR divide_while1         ;if there more diviison is possible, continue while
divide_while1_end
;check for remainder, and apply if applicable
divide_ifz                  ;no remainder
    ADD R0,R0,#1            ;increment final divide counter by 1
    BR divide_end
divide_ifn                   ;there is a remainder so calculate the remainder
    NOT R2,R2                ;inverse R2 so we can subtract
    ADD R2,R2,#1
    ADD R4, R4,R2            ;subtract partial total from R2
    ADD R3, R4, #0           ;get remainder
divide_end
;(3)Restore all modified registers except Return Values
LD R1, divide_backup_r1
LD R2, divide_backup_r2
LD R4, divide_backup_r4
LD R6, divide_backup_r6
LD R7, divide_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Divide
;------------------
divide_backup_r1 .blkw #1
divide_backup_r2 .blkw #1
divide_backup_r4 .blkw #1
divide_backup_r6 .blkw #1
divide_backup_r7 .blkw #1
divide_dec0 .fill #0

.end                        ;signals end of prgroam
