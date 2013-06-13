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
;====================================================

;====================
;MAIN FUNCTION
;====================

.orig x3000

;set user input number & counters, output initial string
LEA R0,string1                  ;R0 with introduction message
LD R1,input_number              ;<<<<<----- VALUE WE ARE CONVERTING TO BINARY
LD R2,dec_16                    ;R2 = 16 (total counter)
LD R3,dec_4                     ;R3 = 4 (space counter)
puts                            ;output message

LD R0,ascii_b                   ;output initial 'b'
OUT                             ;output

;read value and output
forloop1                        ;for(int i = 16; i > 0; i--)
    ADD R1,R1,#0                ;check R1
    BRzp if_positive            ;Go to if_poisitive if R1 is zero or negative

    ;if leading bit is 0
        LD R0,ascii_1           ;load 1 character
        out                     ;output "1"
        BR if_positive_end

    ;if leading bit is 1
    if_positive
        LD R0,ascii_0           ;load 0 character
        out                     ;output "0"
    if_positive_end

    ;check 4char spacing
    ADD R3,R3,#-1               ;decrement space counter
    BRp if_4charspacing_end     ;output space if necessary (every 4 iterations)
        LD R0,ascii_space       ;load ascii space
        out                     ;output space
        LD R3,dec_4             ;reset space counter to 4
    if_4charspacing_end

    ;left shift, increment counters
    ADD R1,R1,R1                ;left shift R1
    ADD R2,R2,#-1               ;decrememnt total counter
    BRp forloop1                ;if i<16 then go to top of loop
for_loop1_end

HALT                            ;ends program

;-----------------------------
;MAIN->DATA
;------------------------------
input_number .fill #1337   ;<<<<<<<<------- VALUE WE ARE CONVERTING TO BINARY
dec_16 .fill #16                ;declare dec16 = 16
dec_4  .fill #4                 ;declare dec_4 = 4
ascii_0 .fill #48               ;ascii for 9
ascii_1 .fill #49               ;ascii for 1
ascii_space .fill #32           ;ascii for space
string1 .stringz "Converting (#1337) to binary:\n"  ;intro message
ascii_b .fill #98               ;ascii for b

.end
