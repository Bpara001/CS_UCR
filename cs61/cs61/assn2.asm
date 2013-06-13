;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn2
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
;R1 -> input1
;R2 -> input2
;R3 -> input1 - input2
;R4 -> temp

.orig x3000
main_start

;1.Read two numeric characters from storing in separate registers
LEA R0,string1      ;prompt input1, get input1
PUTS
GETC
OUT
ADD R1,R0,#0

LEA R0,string2      ;prompt input2, get input2
PUTS
GETC
OUT
ADD R2,R0,#0

;output equation with inputted numbers
LEA R0,newline
PUTS
ADD R0,R1,#0
OUT
LEA R0,string3
PUTS
ADD R0,R2,#0
OUT
LEA R0,string4
PUTS

;2.Convert the numeric characters into the actual numbers they represent
LD R4,dec_n48
ADD R1,R1,R4
ADD R2,R2,R4

;3,4,5. Calulate answer and display
NOT R2,R2
ADD R2,R2,#1
ADD R3,R1,R2            ;subtract second number from first
BRn if_statement1
BR if_statement1end
if_statement1           ;invert if answer is negative & print minus sign
    LD R0,ascii_minus
    OUT
    NOT R3,R3
    ADD R3,R3,#1
if_statement1end
LD R4,dec_48
ADD R0,R3,R4            ;output final answer
OUT

;prompt restart
LD R4,notascii_y
LEA R0,string5
PUTS
GETC
OUT
ADD R0,R0,R4
BRz main_start

;display end program
LEA R0,string6
PUTS

HALT

;///MAIN->DATA///////
string1 .stringz "\n\nInput two numeric characters (i.e '0...'9')\n\nInput 1: "
string2 .stringz "\nInput 2: "
string3 .stringz " - "
string4 .stringz " = "
string5 .stringz "\n\nRestart? (y/n): "
string6 .stringz "\n///End program///"
newline .stringz "\n"
dec_n48 .fill #-48
dec_48 .fill #48
ascii_minus .fill #45
notascii_y .fill#-121

