; Direct addressing, LD Rx, TAG
; Indirect addressing, LDI Rx, TAG
; Relative addressing, LDR Rx, Ra, #8
.ORIG x3000
;-------------
LDI R3, DEC_65
LDI R4, HEX_41

ADD R3, R3, #1
ADD R4, R4, #1

STI R3, DEC_65
STI R4, HEX_41

HALT
;------------
DEC_65 .fill x4000
HEX_41 .fill x4001

.ORIG x4000
.fill #65
.fill x41

.end
