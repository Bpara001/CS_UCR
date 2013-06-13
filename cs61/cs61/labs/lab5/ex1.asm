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

array_1 .blkw #10           ;reserve space for array
LD R1, dec_0;               ;R1 = 0
LD R2, data_ptr             ;R2 = ptr to x4000
LD R3, dec_9                ;R3 = 9 (counter)

;populate&output
;store special case, 2^0 = 1
ADD R1,R1,#1            ;R1 = 1
STR R1,R2,#0            ;Store R1 into R2 ptr locatoin
ADD R2,R2,#1            ;move R2 ptr up by one space
LD R6,SUB_BINOUT        ;call SUB_BINOUT
JSRR R6                 ;travel to SUB_BINOUT
LD R0,ascii_newline     ;output newline
OUT                     ;output

;for loop for next 9 elements
loop1
    STR R1,R2,#0
    ADD R1,R1,R1             ;multiple value by 2
    LD R6,SUB_BINOUT         ;call BINOUT
    JSRR R6
    LD R0,ascii_newline     ;output newline
    OUT
    ADD R2,R2,#1            ;increment ptr
    ADD R3,R3,#-1           ;decrement counter
    BRp loop1
loop1_end                   ;end of for loop

HALT
;----------------------------
;MAIN->DATA
;------------------------------
SUB_BINOUT .fill x3200
dummynumber .fill #1337
array_1 .fill x4000
dec_0 .fill #0
dec_9 .fill #9
data_ptr .fill x4000
ascii_newline .fill #10


;================================================
;SUBROUTINE: Binary Output
;input R1 <- value
;Postcondition: prints R1 into a 16-bit binary
;return value: void
.orig x3200
;================================================

;(1) Backup all modified registers excsept Return Value
ST R0, binout_backup_r0
ST R1, binout_backup_r1
ST R2, binout_backup_r2
ST R3, binout_backup_r3
ST R7, binout_backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;set user input number & counters, output initial b
LD R2,binout_dec_16
LD R3,binout_dec_4
puts
LD R0,binout_ascii_b                   ;output initial 'b'
OUT

;read value and output
binout_forloop1                        ;for(int i = 16; i > 0; i--)
    ADD R1,R1,#0
    BRzp binout_if_positive

    ;if leading bit is 0
        LD R0,binout_ascii_1           ;output "1"
        out
        BR binout_if_positive_end

    ;if leading bit is 1
    binout_if_positive
        LD R0,binout_ascii_0           ;output "0"
        out
    binout_if_positive_end

    ;check 4char spacing
    ADD R3,R3,#-1
    BRp binout_if_4charspacing_end ;output space if needed(every 4 iterations)
        LD R0,binout_ascii_space
        out
        LD R3,binout_dec_4
    binout_if_4charspacing_end

    ;left shift, increment counters
    ADD R1,R1,R1
    ADD R2,R2,#-1
    BRp binout_forloop1
binout_for_loop1_end

;(3)Restore all modified registers except Return Values
LD R0, binout_backup_r0
LD R1, binout_backup_r1
LD R2, binout_backup_r2
LD R3, binout_backup_r3
LD R7, binout_backup_r7

;(4)Return to where you came from
RET
;-----------------------------
;BinOut->data
;------------------------------
binout_backup_r0 .blkw #1
binout_backup_r1 .blkw #1
binout_backup_r2 .blkw #1
binout_backup_r3 .blkw #1
binout_backup_r7 .blkw #1
binout_dec_16 .fill #16
binout_dec_4  .fill #4
binout_ascii_0 .fill #48
binout_ascii_1 .fill #49
binout_ascii_space .fill #32
binout_ascii_b .fill #98


.end

