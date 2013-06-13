;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn6
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;NOTE: SUBROUTINES Read_int, multiply, & divide are copy and pasted from last assn.

;==============================================
;//////////////////////////////////////////////
;/////////////   MAIN FUNCTION   //////////////
;//////////////////////////////////////////////
;==============================================
.orig x3000

LEA R0,string1          ;load string into buffer
PUTS                    ;output into console
LD R6,SUB_readint       ;load READ INT SUBROUTINE
JSRR R6                 ;Execute READ INT SUBROUTINE
LEA R0,string2          ;load string into buffer
PUTS                    ;output into console
ADD R0,R1,#0            ;copy R1 int R0
LD R6,SUB_full_hprint   ;load int to hex print
JSRR R6                 ;execute subroutine

HALT


;----------------------------
;Data block-> Main
;------------------------------
SUB_readint .fill x3200
SUB_full_hprint .fill x3800
string1 .stringz "Enter a decimal number between [0,65535]"
string2 .stringz "\nConverting to Hexadecimal: "


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
    ADD R2,R2,#-1       ;decrement counter
    BRp multi_loop1
multi_loop1end
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

;====================================================
;SUBROUTINE: Divide
;Input: Divides R1 / R2; q = n/d, remainder r
;Postcondition: Divdes R1 / R2 ; R0 = value; R3 = remainder
;Return Value: R0 = value, R3 = remainder
 .ORIG x3600
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

;====================================================
;SUBROUTINE: Dec To Hex print
;Input R0 <- number we need to convert
;Postcondition: Converts R0 into a Hex and outputs to screen
;Return Value: void, none.
 .ORIG x3800
;=====================================================
;-------------------------
; INSTRUCTIONS; DEC to HEX print
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, hex_backup_r0
ST R1, hex_backup_r1
ST R2, hex_backup_r2
ST R3, hex_backup_r3
ST R4, hex_backup_r4
ST R5, hex_backup_r5
ST R6, hex_backup_r6
ST R7, hex_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R5,hex_SUB_HEXprint          ;load R5 with the hex print subroutine
LD R6,hex_SUB_DIVIDE            ;load R6 with divide subroutine
ADD R1,R0,#0                    ;copy value to R1
LD R0,hex_x                     ;load value 'x' into R0
OUT                             ;output
ADD R1,R1,#0                    ;check for overflow
BRn hex_do_negative             ;if negative, go to negative logic
;positive(number range (0 to 32767) logic loop
LD R2, hex_4096                 ;load (16^3)
JSRR R6                         ;divide by (16^3)
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_256                  ;load (16^2)
JSRR R6                         ;divide by (16^2)
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_16                   ;load (16^1)
JSRR R6                         ;divide by (16^1)
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_1                    ;load (16^0)
JSRR R6                         ;divide by (16^0)
JSRR R5                         ;print hex value
BR hex_end
;negative(number range 32768 to 65535) logic loop
hex_do_negative
NOT R1,R1                       ;inverse value
ADD R1,R1,#1                    ;change to two's complement
LD R2, hex_4096                 ;load (16^3)
JSRR R6                         ;divide by (16^3)
NOT R0,R0                       ;subtract 16-quotient
ADD R0,R0,#1
ADD R0,R0,#15
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_256                  ;load (16^2)
JSRR R6                         ;divide by (16^2)
NOT R0,R0                       ;subtract 16-quotient
ADD R0,R0,#1
ADD R0,R0,#15
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_16                   ;load (16^1)
JSRR R6                         ;divide by (16^1)
NOT R0,R0                       ;subtract 16-quotient
ADD R0,R0,#1
ADD R0,R0,#15
JSRR R5                         ;print hex value
ADD R1,R3,#0                    ;(REPEAT)copy remainder into buffer
LD R2, hex_1                    ;load (16^0)
JSRR R6                         ;divide by (16^0)
NOT R0,R0                       ;subtract 16-quotient
ADD R0,R0,#2
ADD R0,R0,#15
JSRR R5                         ;print hex value
hex_end
;(3)Restore all modified registers except Return Values
LD R0, hex_backup_r0
LD R1, hex_backup_r1
LD R2, hex_backup_r2
LD R3, hex_backup_r3
LD R4, hex_backup_r4
LD R5, hex_backup_r5
LD R6, hex_backup_r6
LD R7, hex_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; DEC to HEX print
;------------------
hex_backup_r0 .blkw #1
hex_backup_r1 .blkw #1
hex_backup_r2 .blkw #1
hex_backup_r3 .blkw #1
hex_backup_r4 .blkw #1
hex_backup_r5 .blkw #1
hex_backup_r6 .blkw #1
hex_backup_r7 .blkw #1
hex_SUB_DIVIDE .fill x3600
hex_SUB_HEXprint .fill x4000
hex_4096 .fill #4096
hex_256 .fill #256
hex_16 .fill #16
hex_1  .fill #1
hex_x .fill #120
hex65535 .fill #65535

;====================================================
;SUBROUTINE: Hex Print
;Input: R0 <- 4 bit hex to output to console
;Postcondition: outputs R0 to console as a hex
;Return Value: none, void
 .ORIG x4000
;=====================================================
;-------------------------
; INSTRUCTIONS; Hex Print
;-------------------------

;(1)Backup all modified registers except Return Value
ST R0, hprint_backup_r0
ST R6, hprint_backup_r6
ST R7, hprint_backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;figure out what number was read in (either 1 to 16) & go to approiate branch
ADD R0,R0,#0            ;check for 0
BRz hprint_hex0
ADD R0,R0,#-1           ;check for 1
BRz hprint_hex1
ADD R0,R0,#-1           ;check for 2
BRz hprint_hex2
ADD R0,R0,#-1           ;check for 3
BRz hprint_hex3
ADD R0,R0,#-1           ;check for 4
BRz hprint_hex4
ADD R0,R0,#-1           ;check for 5
BRz hprint_hex5
ADD R0,R0,#-1           ;check for 6
BRz hprint_hex6
ADD R0,R0,#-1           ;check for 7
BRz hprint_hex7
ADD R0,R0,#-1           ;check for 8
BRz hprint_hex8
ADD R0,R0,#-1           ;check for 9
BRz hprint_hex9
ADD R0,R0,#-1           ;check for 10 -> A
BRz hprint_hex10
ADD R0,R0,#-1           ;check for 11 -> B
BRz hprint_hex11
ADD R0,R0,#-1           ;check for 12 -> C
BRz hprint_hex12
ADD R0,R0,#-1           ;check for 13 -> D
BRz hprint_hex13
ADD R0,R0,#-1           ;check for 14 -> E
BRz hprint_hex14
ADD R0,R0,#-1           ;check for 15 -> F
BRz hprint_hex15
;print the approiate number associated with the input
hprint_hex0         ;Print 0
LD R0,hprint_0
OUT
BR hprint_end
hprint_hex1         ;Print 1
LD R0,hprint_1
OUT
BR hprint_end
hprint_hex2         ;Print 2
LD R0,hprint_2
OUT
BR hprint_end
hprint_hex3         ;Print 3
LD R0,hprint_3
OUT
BR hprint_end
hprint_hex4         ;Print 4
LD R0,hprint_4
OUT
BR hprint_end
hprint_hex5         ;Print 5
LD R0,hprint_5
OUT
BR hprint_end
hprint_hex6         ;Print 6
LD R0,hprint_6
OUT
BR hprint_end
hprint_hex7         ;print7
LD R0,hprint_7
OUT
BR hprint_end
hprint_hex8         ;print 8
LD R0,hprint_8
OUT
BR hprint_end
hprint_hex9         ;print 9
LD R0,hprint_9
OUT
BR hprint_end
hprint_hex10        ;print 10 -> A
LD R0,hprint_A
OUT
BR hprint_end
hprint_hex11        ;print 11 -> B
LD R0,hprint_B
OUT
BR hprint_end
hprint_hex12        ;print 12 -> C
LD R0,hprint_C
OUT
BR hprint_end
hprint_hex13        ;print 13-> D
LD R0,hprint_D
OUT
BR hprint_end
hprint_hex14        ;print 14-> E
LD R0,hprint_E
OUT
BR hprint_end
hprint_hex15        ;print 15->F
LD R0,hprint_F
OUT
hprint_end
;(3)Restore all modified registers except Return Values
LD R0, hprint_backup_r0
LD R6, hprint_backup_r6
LD R7, hprint_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Hex Print
;------------------
hprint_backup_r0 .blkw #1
hprint_backup_r6 .blkw #1
hprint_backup_r7 .blkw #1
hprint_A    .fill #65
hprint_B    .fill #66
hprint_C    .fill #67
hprint_D    .fill #68
hprint_E    .fill #69
hprint_F    .fill #70
hprint_0    .fill #48
hprint_1    .fill #49
hprint_2    .fill #50
hprint_3    .fill #51
hprint_4    .fill #52
hprint_5    .fill #53
hprint_6    .fill #54
hprint_7    .fill #55
hprint_8    .fill #56
hprint_9    .fill #57

.end
