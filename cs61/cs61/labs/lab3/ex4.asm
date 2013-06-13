;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab3
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================


;/// I AM NOT USING THE CODE YOU SUPPLIED ME WITH, MY PROGRAM WORkS FINE AS IS.

.orig x3000
;=======================
;MAIN FUNCTION
;=======================
LD R1,data_ptr1         ;pointer points to meme locatoin x4000
LD R2,counter           ;counts total number of char's by user input

;get input and store into array
LEA R0,string1          ;outputs instructions
PUTS
forloop1                ;while loop, gets user input unter enter key is hit
    GETC
    OUT
    ADD R0,R0,#-10      ;check to see if ascii enter is inputted
    brz end_forloop1
    ADD R0,R0,#10       ;return input to orginal value
    STR R0,R1,#0        ;stores char into x4000 + i
    ADD R1,R1,#1        ;increment pointer
    ADD R2,R2,#1        ;increment total counter
    br forloop1
end_forloop1

;output contents of array
LD R1,data_ptr1         ;reset ptr to start of mem location (x4000)
LEA R0,string2          ;outputs array content string
PUTS
forloop2
    LDR R0,R1,#0        ;output values stored at mem locatoin x4000 + i
    OUT
    ADD R1,R1,#1        ;increment pointer
    ADD R2,R2,#-1       ;decrmeent counter
    brp forloop2
end_forloop2


HALT

;---------------
;data
;---------------
string1 .stringz "Enter chars,hit return when done:\n-> "
string2 .stringz "\n\nArray contains:\n->"
data_ptr1 .fill x4000
counter .fill #0


.end
