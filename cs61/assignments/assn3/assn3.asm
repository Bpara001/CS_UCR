 ;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn3
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;------------------
; INSTRUCTIONS
;------------------
.orig x3000


;-----Set up basic output and registries-----
LEA R0,message_1          ;outputs introduction message
PUTS
LDI R1, converted_num   ;R1->#(variable)!THIS IS THE NUMBER WE ARE CONVERTING!
LD R2, DEC_16           ;R2 -> #16
LD R3, DEC_4            ;R3 -> #4

;-----Using left shifting, print out the 16-bit binary number-----
LOOP_1                          ;for(int i=0; i<16; i++)
ADD R2, R2, #0
BRz END_LOOP_1
    ADD R1, R1, #0
    BRzp TRUE_CONDITION_1       ;if(R2 >= 0)
    FALSE_CONDITION_1           ;then
        LDI R0, ascii_1         ;output 0
        BR END_IF_STATEMENT_1
    TRUE_CONDITION_1            ;else
        LDI R0, ascii_0         ;output 1
        BR END_IF_STATEMENT_1
    END_IF_STATEMENT_1
    out                         ;output to buffer

;----Add spaces for every 4 binary numbers-----
    ADD R3,R3,#-1               ;j--
    BRz TRUE_CONDITION_2        ;if(j > 0),
    FALSE_CONDITION_2           ;then
        BR END_IF_STATEMENT_2   ;do nothing
    TRUE_CONDITION_2            ;else
        LDI R0, ascii_space     ;output space character
        out                     ;output to buffer
        LD R3, DEC_4            ;j -> 4
        BR END_IF_STATEMENT_2
    END_IF_STATEMENT_2

;-----Counting logic-----
    ADD R2, R2, #-1             ;i++
    ADD R1, R1, R1              ;R1 -> R1 +R1 (left shifting)
    BR LOOP_1                   ;repeat for loop

END_LOOP_1

HALT
;------------------
; DATA
;------------------
message_1 .STRINGZ "\nConverting #169 to binary:\n"

zero .fill #0
DEC_4 .fill #4
DEC_16 .fill #16

ascii_0 .fill x4000
ascii_1 .fill x4001
ascii_space .fill x4002
converted_num.fill x4003

.orig x4000
.fill #48
.fill #49
.fill #32
.fill #169  ;!!!! <- NUMBER WE ARE CONVERTING !!!!!!!!!!!


.end

