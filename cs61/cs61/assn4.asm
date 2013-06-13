;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn4
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
start_main
;Prompt instructions & sets defualt signflag
LD R0,dec0
ST R0,signflag          ;create sign bitflag
LEA R0,string1
PUTS
LEA R0,string2
PUTS

;ERROR CHECK: make sure first char is "+" or "-"
check1
    GETC
    OUT
    LD R1,ascii_nplus        ;testing "+"
    ADD R0,R0,R1
    Brz end_check1
    LD R1,ascii_plus
    ADD R0,R0,R1
    LD R1,ascii_nminus       ;testing "-"
    ADD R0,R0,R1
    BRnp invalid_input       ;if invalid, go to invalid block
    LD R1,dec1
    ST R1,signflag           ;set sign flag to neg if appliciable
end_check1

;Get user input for number ascci chars, convert on fly
LD R1, dec0
LD R2, dec10
LD R3, dec0             ;R3 -> total number
LD R4, decn38
LD R6, SUB_Multiply
loop1
    GETC                ;get user input
    OUT
    ADD R0,R0,#-10      ;check if 'enter'
    BRz end_loop1
    ADD R5,R0,R4
    BRn invalid_input   ;ERROR CHECK: check if input was num char
    ADD R5,R5,#-9
    BRp invalid_input
    ADD R5,R5,#9
    ADD R1,R3,#0        ;call multiply -> total(R3) * 10
    JSRR R6
    ADD R3,R0,R5        ;add R0 to (total(R3) * 10)
    BRn invalid_input   ;ERROR CHECK: check if input is too large
    BR loop1
end_loop1

;sign check and change sign if applicable
LD R0,signflag
    BRz end_signchange
    NOT R3,R3               ;if negative, invert number & add 1
    ADD R3,R3,#1
    end_signchange
BR end_main

;IF invalid input, do THIS:
invalid_input
    LEA R0,string3      ;output error message,. restart
    PUTS
    restartmain
    LEA R0,string3a
    PUTS
    BR start_main
end_invalid_input

;print ending message,prompt restart
end_main
ADD R1,R3,#0            ;store total number into R1
LEA R0,string4          ;output restart, check user input
PUTS
GETC
OUT
LD R2,ascii_ny
ADD R0,R0,R2            ;if user enters 'y', restart program
BRz restartmain

HALT
;----------------------------
;MAIN->DATA
;------------------------------
SUB_Multiply .fill x3200
signflag .blkw #1
string1 .stringz "Input a number (max 5 digits),preceded with +/-,"
string2 .stringz "followed by ENTER \nEX: '+14250'\n\n->"
string3 .stringz "\nERROR:: INVALID INPUT!"
string3a .stringz "\nRESTARTING...\n\n"
string4 .stringz "\n->SUCCES! Input STORED in R1. Restart?(y/n):"
dec0 .fill #0
dec1 .fill #1
dec10 .fill #10
decn38 .fill #-38
ascii_plus .fill #43
ascii_minus .fill #45
ascii_nplus .fill #-43
ascii_nminus .fill #-45
ascii_ny .fill #-121

;================================================
;SUBROUTINE: Multiply
;arguments: R1 <- first RAW number
;           R2 <- second RAW number
;return value: R0 <- product
;example: R0 = R1 * R2
;================================================
.orig x3200
;backup
ST R1, multi_backup_r1
ST R2, multi_backup_r2
ST R7, multi_backup_r7
;-------------------------
; INSTRUCTIONS; Multiply
;-------------------------
LD R0,multi_dec0
;adds R1 to itself R2 times, stores in R0
multi_loop1
    ADD R0,R1,R0
    ADD R2,R2,#-1       ;decrement counter
    BRp multi_loop1
multi_loop1end
;restore&return
LD R1, multi_backup_r1
LD R2, multi_backup_r2
LD R7, multi_backup_r7
RET
;------------------
; DATA; Multiply
;------------------
multi_backup_r1 .blkw #1
multi_backup_r2 .blkw #1
multi_backup_r7 .blkw #1
multi_dec0 .fill #0

