;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab5
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

LD R6, SUB_INTEGER_CONVERT              ;load R6 with SUBROUTINE
JSRR R6                                 ;jump to R6

ADD R2,R1,#0                            ;copy R0 to R2
HALT
;------------------------------
;MAIN->DATA
;------------------------------
SUB_INTEGER_CONVERT .fill x3200




;====================================================
;SUBROUTINE: Integer Convert
;Input: none, void of arguments
;Postcondition: Prompts the user for a number and stores it into R0
;               converts to int value, storing value into R0
;Return Value: R1 <- Integer
 .ORIG x3200
;=====================================================

;-------------------------
; INSTRUCTIONS;INteger Convert
;-------------------------

;(1)Backup all modified registers except Return Value
ST R0, intcon_backup_r0             ;backup r0
ST R2, intcon_backup_r2             ;backup r2
ST R3, intcon_backup_r3             ;backup r3
ST R4, intcon_backup_r4             ;backup r4
ST R5, intcon_backup_r5             ;backup r5
ST R6, intcon_backup_r6             ;backup r6
ST R7, intcon_backup_r7             ;backup r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;Prompt user for Input
LEA R0,intcon_string1               ;R0 = string 1
PUTS                                ;output

LD R2, intcon_dec0
LD R3, intcon_decn48

;get ten's place & calculate
GETC            ;get user input
OUT             ;echo to screen
ADD R0,R3,R0    ;convert to real number
ADD R1,R0,#0    ;multiply input by 10
ADD R0,R0,R1    ;add R0 to itself 10 times to get R0 *10
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R0,R0,R1    ;add R0 to R1 (R0 temp)
ADD R2,R0,#0    ;copy R0 to R2

;get one's place & calculate
GETC            ;get user input
OUT             ;echo to screen
ADD R0,R3,R0    ;convert to real number
ADD R2,R2,R0    ;add ones place to R0
ADD R1,R2,#0    ;copys R2(temp total) to return value (r1)

;(3)Restore all modified registers except Return Values
LD R0, intcon_backup_r0                 ;restore R0
LD R2, intcon_backup_r2                 ;restore R2
LD R3, intcon_backup_r3                 ;restore R3
LD R4, intcon_backup_r4                 ;restore R4
LD R5, intcon_backup_r5                 ;restore R5
LD R6, intcon_backup_r6                 ;restore R6
LD R7, intcon_backup_r7                 ;restore R7

;(4)Return to where you came from
RET

;------------------
; DATA;
;------------------
intcon_backup_r0 .blkw #1
intcon_backup_r2 .blkw #1
intcon_backup_r3 .blkw #1
intcon_backup_r4 .blkw #1
intcon_backup_r5 .blkw #1
intcon_backup_r6 .blkw #1
intcon_backup_r7 .blkw #1
intcon_string1 .stringz "\nENTER a pos int value, with two chars \n(Ex.'05')\n"
SUB_POWERTO    .fill x3600
intcon_dec16    .fill #16
intcon_decn48   .fill #-48
intcon_dec0      .fill #0
intcon_dec1      .fill #1

.end
