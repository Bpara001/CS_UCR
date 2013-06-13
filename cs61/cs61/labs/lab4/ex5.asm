;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab4
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

array_1 .blkw #10           ;reserve a space of 10 for array1
LD R1, dec_0                ;R1 = 0
LD R2, data_ptr             ;R2 = x4000 (ptr)
LD R3, dec_9                ;R3 = 9 (counter)

;populate&output
;store special case, 2^0 = 1
ADD R1,R1,#1                ;R1 = 1
STR R1,R2,#0                ;Store R1 at ptr(r2)
ADD R2,R2,#1                ;incremeent pointer
LD R6,SUB_BINOUT            ;call BINOUT
JSRR R6                     ;jump to R6
LD R0,ascii_newline         ;output newline
OUT                         ;output

;for loop for next 9 elements
loop1                       ;for(int i = 0 i<9;i++)
    STR R1,R2,#0            ;store R1 at ptr
    ADD R1,R1,R1            ;multiple value by 2
    LD R6,SUB_BINOUT        ;call BINOUT
    JSRR R6                 ;jump to R6
    LD R0,ascii_newline     ;output newline
    OUT                     ;output
    ADD R2,R2,#1            ;increment ptr
    ADD R3,R3,#-1           ;decrement counter
    BRp loop1               ;if i < 9, go back to top of loop
loop1_end

HALT
;----------------------------
;MAIN->DATA
;------------------------------
SUB_BINOUT .fill x3200              ;location for subrotine
dummynumber .fill #1337             ;test number
array_1 .fill x4000                 ;locatoin for array 1
dec_0 .fill #0                       ;declares dec_0 = 0
dec_9 .fill #9                   ;  declares dec_9 = 9
data_ptr .fill x4000                ;set where ptr points to
ascii_newline .fill #10             ;set ascii newline


;================================================
;SUBROUTINE: Binary Output
;arguments: R1 <- value
;return value: prints value into 16-bit binary
;================================================
.orig x3200
;backup registers
ST R0, binout_backup_r0     ;store R0
ST R1, binout_backup_r1     ;store R1
ST R2, binout_backup_r2     ;store R2
ST R3, binout_backup_r3     ;store R3
ST R7, binout_backup_r7     ;store R7
;set user input number & counters, output initial b
LD R2,binout_dec_16                     ;R2 = 16 (total counter)
LD R3,binout_dec_4                      ;R3 = 4 (space counter)
puts
LD R0,binout_ascii_b                   ;output initial 'b'
OUT
;read value and output
binout_forloop1                        ;for(int i = 16; i > 0; i--)
    ADD R1,R1,#0                       ;check R1
    BRzp binout_if_positive       ;Go to if_poisitive if R1 is zero or negative
    ;if leading bit is 0
        LD R0,binout_ascii_1           ;load 1 character
        out                            ;output "1
        BR binout_if_positive_end
    ;if leading bit is 1
    binout_if_positive
        LD R0,binout_ascii_0           ;load 0 character
        out                            ;output "0"
    binout_if_positive_end
    ;check 4char spacing
    ADD R3,R3,#-1                      ;decrement space counter
    BRp binout_if_4charspacing_end  ;output space if needed(every 4 iterations)
        LD R0,binout_ascii_space       ;load ascii space
        out                            ;output space
        LD R3,binout_dec_4             ;reset space counter to 4
    binout_if_4charspacing_end
    ;left shift, increment counters
    ADD R1,R1,R1                       ;left shift R1
    ADD R2,R2,#-1                      ;decrememnt total counter
    BRp binout_forloop1                ;if i<16 then go to top of loop
binout_for_loop1_end
;restore&return
LD R0, binout_backup_r0                 ;reload backup R0
LD R1, binout_backup_r1                 ;reoloadbackup R1
LD R2, binout_backup_r2                 ;reload backup R2
LD R3, binout_backup_r3                 ;reload backup R3
LD R7, binout_backup_r7                 ;reload backup R7
RET
;-----------------------------
;BinOut->data
;------------------------------
binout_backup_r0 .blkw #1       ;backup R0
binout_backup_r1 .blkw #1       ;backup R1
binout_backup_r2 .blkw #1       ;backup R2
binout_backup_r3 .blkw #1       ;backup R3
binout_backup_r7 .blkw #1       ;backup R7
binout_dec_16 .fill #16
binout_dec_4  .fill #4
binout_ascii_0 .fill #48
binout_ascii_1 .fill #49
binout_ascii_space .fill #32
binout_ascii_b .fill #98


.end

