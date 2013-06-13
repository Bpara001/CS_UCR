.orig x3000
;-------------

;------------
LD R0, HEX_x61
LD R1, HEX_x1A

FOR_LOOP_1
    OUT
    ADD R0, R0, #1
    ADD R1, R1, #-1
    BRp FOR_LOOP_1
END_FOR_LOOP_1
HALT
;------------
HEX_x61 .fill x61
HEX_x1A .fill x1A

.end
