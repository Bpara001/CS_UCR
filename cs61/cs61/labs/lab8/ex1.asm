;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab8
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
.orig x3000
;===============================
;TEST HARNESS
;==============================

LD R0,ptr                       ;load ptr into argument
LD R6, SUB_GET_STRING           ;load SUBROUTINE
JSRR R6                         ;call subroutine

HALT
;----------------
;Main data
;---------------
ptr .fill x4000
SUB_GET_STRING .fill x3200


;====================================================
;SUBROUTINE: SUB_GET-STRING
;Input  (R0): The address of where to start storing the strin
;Postcondition: The subroutine has allowed the user to input a string,
;               terminated by the [ENTER] key, and has stored it in an array
;                that starts at (R0) and is NULL-terminated.
; Return Value: R5 <- The number of non-sentinel characters read from the use
 .ORIG x3200
;=====================================================
;-------------------------
; INSTRUCTIONS;Get string
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, gets_backup_r0
ST R1, gets_backup_r1
ST R6, gets_backup_r6
ST R7, gets_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
ADD R1,R0,#0                        ;copy pointer to R0
LEA R0, gets_string1                ;load instruction message
PUTS                                ;output to console
LD R5, gets_dec0                    ;set ocunter to 0

gets_While_loop1                    ;while userinput != [ENTER]
    GETC                            ;get input
    OUT                             ;echo
    ADD R0,R0,#-10                  ;check if enter
    BRz gets_While_loop1_end        ;if enter key, end while loop
    ADD R0,R0,#10                   ;convert back to ascii letter
    STR R0,R1,#0                    ;Store R0 into R1
    ADD R1,R1,#1                    ;increment pointer
    ADD R5,R5,#1                    ;increment total counter
    BR gets_While_loop1             ;repeat loop
gets_While_loop1_end
LD R0,gets_dec0                      ;load R0 with null terminating character
STR R0,R1,#0                        ;store R0 into the array
;(3)Restore all modified registers except Return Values
LD R0, gets_backup_r0
LD R1, gets_backup_r1
LD R6, gets_backup_r6
LD R7, gets_backup_r7
;(4)Return to where you came from
RET

;------------------
; DATA; Get string
;------------------
gets_string1 .stringz "Enter a string,hit [ENTER] key to finish:\n"
gets_dec0 .fill #0

gets_backup_r0 .blkw #1
gets_backup_r1 .blkw #1
gets_backup_r4 .blkw #1
gets_backup_r6 .blkw #1
gets_backup_r7 .blkw #1

.end
