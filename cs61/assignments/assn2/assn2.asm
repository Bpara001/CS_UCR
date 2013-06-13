;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn2
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================


;*****NOTE: please dont mark me down for too many comments,
;*****NOTE: i had to write them down for me debug/learn the language

.orig x3000             ;Program begins here

;--------------------
;Instructions
;-------------------

;******Display introduction, Get first input, output*******
LEA R0,message1         ;Stores intro message
PUTS                    ;Outputs string
GETC                    ;Gets the first input character
OUT                     ;Outputs input
LDI R1, DEC_n48         ;sets R1 to -48, needed for ASCII conversion
ADD R1, R0, #0          ;Copys R0 into R1
LDI R0, ASCII_DASH      ;Loads ASCII dash symbol
OUT                     ;Ouputs the - symbol

;******Get first input, convert to 2's compl, output*******
GETC                    ;Gets the second input character
OUT                     ;Outputs input
LDI R2, DEC_n48         ;sets R2 to -48, needed for ASCII conversion
ADD R2, R0, #0          ;Copys R0 into R2
NOT R2, R2              ;Two's complement, Inverts the number
ADD R2, R2, #1          ;Two's complement, Adds 1
LDI R0, ASCII_EQUAL     ;Loads ASCII equal symbol
OUT                     ;Ouputs the = symbol

;******Fix if sum is negative*******
ADD R3, R1, R2              ;R3 = R1 + R2
IF_STATEMENT                ;Accounts for a negative number
    BRn TRUE_CONDITION
FALSE_CONDITION             ;FALSE:: do nothing
    BR END_IF
TRUE_CONDITION              ;TRUE::
        LDI R0,ASCII_DASH   ;Loads ASCII dash symbol
        OUT                 ;outputs the - symbol
        NOT R3,R3           ;inverts R3
        ADD R3,R3, #1       ;R3 = R3 + 1
END_IF

;********Convert and output sum*******
LDI R0, DEC_48      ;Converts decimal to ASCII number
ADD R0,R0,R3        ;Converts decimal to ASCII number
OUT                 ;Outputs the final answer
LEA R0,message2     ;Stores intro message
PUTS                ;Outputs string
HALT                ;Ends the program

;-----------
;Data
;-----------
message1 .STRINGZ "\nPlease input two single digit numbers: \n"
message2 .STRINGZ "\n***END OF PROGRAM***\n"
DEC_n48 .fill x4000
ASCII_DASH .fill x4001
ASCII_EQUAL .fill x4002
DEC_48 .fill x4003

.orig x4000
.fill #-48
.fill #45
.fill #61
.fill #48


.end
