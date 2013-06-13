;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn3
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;/////////////////////
;/// MAIN FUNCTION ///
;/////////////////////

.orig x3000
;R1 -> inputed number (VALUE WE ARE CONVERTING)
;R2 -> 16-counter
;R3 -> 4-counter

;set user input number & counters, output initial string
LEA R0,string1
LD R1,input_number              ;<<<<<----- VALUE WE ARE CONVERTING TO BINARY
LD R2,dec_16
LD R3,dec_4
puts

;read value and output
forloop1                        ;for(int i = 16; i > 0; i--)
    ADD R1,R1,#0
    BRzp if_positive

    ;if leading bit is 0
        LD R0,ascii_1           ;output "1"
        out
        BR if_positive_end

    ;if leading bit is 1
    if_positive
        LD R0,ascii_0           ;output "0"
        out
    if_positive_end

    ;check 4char spacing
    ADD R3,R3,#-1
    BRp if_4charspacing_end     ;output space if necessary (every 4 iterations)
        LD R0,ascii_space
        out
        LD R3,dec_4
    if_4charspacing_end

    ;left shift, increment counters
    ADD R1,R1,R1
    ADD R2,R2,#-1
    BRp forloop1
for_loop1_end

;output goodbye message
LEA R0, string2
PUTS

HALT

;///MAIN->DATA///////
input_number .fill #169   ;<<<<<<<<------- VALUE WE ARE CONVERTING TO BINARY
dec_16 .fill #16
dec_4  .fill #4
ascii_0 .fill #48
ascii_1 .fill #49
ascii_space .fill #32
string1 .stringz "Converting (#169) to binary:\n"
string2 .stringz "\n\n////End Program////"

.end
