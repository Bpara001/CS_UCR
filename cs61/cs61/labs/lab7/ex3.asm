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

LD R1,number              ;NUMBER TO RIGHT SHIFT

LD R6,SUB_RSHIFT          ;Load READ INT SUBROUTINE
JSRR R6

ADD R2,R0,#0

LEA R0,string1
PUTS



;;! ORGINAL NUMBER IS STORED IN R1, NEW NUMBER IS STORED IN R0


HALT
;----------------------------
;MAIN->DATA
;------------------------------
SUB_RSHIFT .fill x3400
number .fill x1234
string1 .stringz "ORGINAL NUMBER IS STORED IN R1, NEW NUMBER IS STORED IN R2"


;====================================================
;SUBROUTINE: Divide
;Input: Divides R1 / R2; q = n/d, remainder r
;Postcondition: Divdes R1 / R2 ; R0 = value; R3 = remainder
;Return Value: R0 = value, R3 = remainder
 .ORIG x3200
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
;SUBROUTINE: SUB Right shift
;Input: R1 <- value to right shift
;Postcondition: R0 <- new right shifted value
;Return Value: R0
 .ORIG x3400
;=====================================================

;-------------------------
; INSTRUCTIONS; Right shift
;-------------------------

;(1)Backup all modified registers except Return Value

ST R1, rshift_backup_r1
ST R2, rshift_backup_r2
ST R6, rshift_backup_r6
ST R7, rshift_backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R6, rshift_SUB_DIVIDE    ;load divide subroutine

LD R2,rshift_2          ;LD R2 with 2

JSRR R6                 ;divide input/2



;(3)Restore all modified registers except Return Values

LD R1, rshift_backup_r1
LD R2, rshift_backup_r2
LD R6, rshift_backup_r6
LD R7, rshift_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; Right Shift
;------------------

rshift_backup_r1 .blkw #1
rshift_backup_r2 .blkw #1
rshift_backup_r6 .blkw #1
rshift_backup_r7 .blkw #1
rshift_SUB_DIVIDE .fill x3200
rshift_2          .fill #2












.end                        ;signals end of prgroam

