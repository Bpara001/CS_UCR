;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab2
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================


.orig x3000
;=======================
;MAIN FUNCTION
;=======================
LEA R0, string1
PUTS

loop1_start
    GETC
    ADD R0,R0,-#10
    BRz loop1_end
    ADD R0,R0,#10
    OUT
    BR loop1_start
loop1_end

LEA R0,string2
PUTS

HALT

;---------------
;data
;---------------
string1 .stringz "Type something!!! press enter to quit\n"
string2 .stringz "\n\n///End of program\n"

.end
