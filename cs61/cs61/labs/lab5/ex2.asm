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

LD R6, SUB_INTEGER_CONVERT
JSRR R6

HALT
;------------------------------
;MAIN->DATA
;------------------------------
SUB_INTEGER_CONVERT .fill x3200




;====================================================
;SUBROUTINE: Integer Convert
;Input: none, void of arguments
;Postcondition: Prompts user for a 16-bit binary number echos to screen then
;               converts to int value, storing value into R1
;Return Value: R1 <- Integer
 .ORIG x3200
;=====================================================

;-------------------------
; INSTRUCTIONS;INteger Convert
;-------------------------

;(1)Backup all modified registers except Return Value
ST R0, intcon_backup_r0
ST R2, intcon_backup_r2
ST R3, intcon_backup_r3
ST R4, intcon_backup_r4
ST R5, intcon_backup_r5
ST R6, intcon_backup_r6
ST R7, intcon_backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;Prompt user for Input
LEA R0,intcon_string1
PUTS
LEA R0,intcon_string2
PUTS

;Get first value, ascii char 'b'
GETC
OUT

;Get user input 16 times & converts number on the fly
LD R2,intcon_dec16                      ; R2 = 16 (conunter)
LD R3,intcon_decn48                     ; R3 = -48 (converting to real number)
LD R4,intcon_dec0                       ; R4 = total(start at 0)
intcon_forloop1                         ;(for int i=0;i<16;i++)
    ADD R1,R2,#0                        ;R1 = R2 Temp counter
    GETC                                ;Get intput
    OUT                                 ;echo to screen
    ADD R0,R0,R3                        ;convert to real number
    BRz intcon_forloop2_end             ;if input is 1 = then add to total(r4)
    intcon_forloop2
        ADD R1,R1,#-1                   ;decrement temp counter
        BRz intcon_forloop2_end         ;if temp counter == 0 then end loop
        ADD R0,R0,R0                    ;ADD R0 to R0
        BR intcon_forloop2              ;if temp counter != 0 then do again
    intcon_forloop2_end
    ADD R4,R4,R0
    ADD R2,R2,#-1                       ;decrement counters
    BRp intcon_forloop1                 ;if i< 16 repeat loop
intcon_forloop1_end

ADD R1,R4,#0                            ;copy to R1 (return value)

;(3)Restore all modified registers except Return Values
LD R0, intcon_backup_r0
LD R2, intcon_backup_r2
LD R3, intcon_backup_r3
LD R4, intcon_backup_r4
LD R5, intcon_backup_r5
LD R6, intcon_backup_r6
LD R7, intcon_backup_r7

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
intcon_string1 .stringz "\nENTER 16-bit binary string starting with 'b'"
intcon_string2 .stringz "\n(Ex. 0001 1000 1000 1111)\n"
SUB_POWERTO    .fill x3600
intcon_dec16    .fill #16
intcon_decn48   .fill #-48
intcon_dec0      .fill #0
intcon_dec1      .fill #1

.end
