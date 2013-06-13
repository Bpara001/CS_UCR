;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab9
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
.orig x3000
;===============================================
;MAIN FUNCITON
;===============================================
LD R0, ptr                  ;load paramters of sub
LD R6, SUB_TO_UPPER         ;load sub
JSRR R6                     ;call sub
PUTS                        ;output the new string

HALT


;=============================
;data: main function
;=============================
SUB_TO_UPPER .fill x3200
ptr .fill x4000



;====================================================
; Subroutine: SUB_TO_UPPER
; Parameter (R0): Address to store a string at
; Postcondition: The subroutine has allowed the user to input a string,
;   terminated by the [ENTER] key, has converted the string
;   to upper-case, and has stored it in a null-terminated array that
;   starts at (R0).
; Return Value: R0 <- The address of the now upper case string.
 .ORIG x3200
;=====================================================
;-------------------------
; INSTRUCTIONS; SUB_TO UPPER
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, upper_backup_r0
ST R1, upper_backup_r1
ST R2, upper_backup_r2
ST R6, upper_backup_r6
ST R7, upper_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

ADD R1,R0,#0                ;copy address to R1
LEA R0,upper_string1        ;load introduction message
PUTS                        ;output to screen
LD R2,upper_conversion
upper_while1                ;while userinput != [enter]
    GETC                    ;get user input
    OUT                     ;echo
    ADD R0,R0,#-10          ;check if [enter] is inputted
    BRz upper_while1_end    ;if [enter] end loop
    ADD R0,R0,R2            ;convert to uppercase
    STR R0,R1,#0            ;store into array
    ADD R1,R1,#1            ;increment ptr
    BR upper_while1         ;repeat loop
upper_while1_end
ADD R1,R1,#1                ;increment ptr one lcast time
LD R0,upper_dec0            ;store null terminating character

;(3)Restore all modified registers except Return Values
LD R0, upper_backup_r0
LD R1, upper_backup_r1
LD R2, upper_backup_r2
LD R6, upper_backup_r6
LD R7, upper_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA;
;------------------
upper_string1 .stringz"Enter lowercase string, press [Enter] key when done:\n"
upper_conversion .fill #-22
upper_dec0  .fill #0
upper_backup_r0 .blkw #1
upper_backup_r1 .blkw #1
upper_backup_r2 .blkw #1
upper_backup_r6 .blkw #1
upper_backup_r7 .blkw #1




.end
