;----------------------------------------------------
; Wong, Chris
; 860-923-521
; Login: wongc
; Section: 23
; TA: Wasim
; Email: cwong030@ucr.edu
; Lab 01
;----------------------------------------------------

;; hello world program

.ORIG x3000

LEA R0,message  ;store address of start message in RO
PUTS    ; INvokes BIOS routine to outputstring
HALT    ; terminates program execution

;;end of code

;;date block
message .STRINGZ "Hello World!\n"


.END    ;
