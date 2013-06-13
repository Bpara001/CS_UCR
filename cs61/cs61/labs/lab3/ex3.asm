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
array_1 .blkw #10               ;reserves 10 mem locaotins for array
LD R1,data_ptr1                 ; ptr to locatoin in array
LD R2,dec_10                    ;counter for 10 char's

;get input and store into array
LEA R0,string1                  ;outputs insturction message
PUTS
forloop1                        ;gets 10 char's from user
    GETC
    OUT
    STR R0,R1,#0                ;stores into array
    ADD R1,R1,#1                ;increment ptr
    ADD R2,R2,#-1               ;decrement counter
    brp forloop1
end_forloop1

;output contents of array
LD R1,data_ptr1                 ;reloads ptr to start of array
LD R2,dec_10                    ;resets counter to 10

LEA R0,string2                  ;output array string
PUTS
forloop2                        ;output's array contents
    LDR R0,R1,#0                ;loads R0 with arraypi] contents and outputs
    OUT
    ADD R1,R1,#1                ;decrements counter
    ADD R2,R2,#-1
    brp forloop2
end_forloop2


HALT

;---------------
;data
;---------------
string1 .stringz "Enter characters:"
string2 .stringz "\nArray contains: "
array_1 .fill x4000
data_ptr1 .fill x4000
dec_10 .fill #10


.end
