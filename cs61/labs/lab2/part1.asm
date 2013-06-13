; Direct addressing, LD Rx, TAG
; Indirect addressing, LDI Rx, TAG
; Relative addressing, LDR Rx, Ra, #8
.ORIG x3000
;-------------
LD R3, DEC_65
LD R4, HEX_41

HALT
;------------
DEC_65 .fill #65
HEX_41 .fill x41

.end
