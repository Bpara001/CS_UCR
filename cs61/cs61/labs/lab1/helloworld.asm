;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab 1
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

.orig x3000

;=======================
;instructions
;=======================
LEA R0,message1
PUTS
HALT

;=======================
;data block
;=======================
message1 .STRINGZ "HELLO WORLD\n"

.end

