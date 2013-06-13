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


.orig x3000
;=======================
;MAIN FUNCTION
;=======================
LD R5, data_ptr;        ;loads all registries with the ptr to x4000

LDR R3, R5, #0          ;loads R3 with data at mem location x4000
LDR R4, R5, #1          ;loads R4 with data at mem location x4001 (x4000+1)

ADD R3, R3, #1          ;adds 1 to R3
ADD R4, R4, #1          ;adds 1 to R4

STR R3, R5, #0          ;stores vlaue at mem locatoin x4000
STR R4, R5, #0          ;stores value at mem locatoin x4001

HALT

;---------------
;data
;---------------
data_ptr .fill x4000     ;points to mem locatoin at x4000

.orig x4000
.fill #65               ;data at mem locatoin x4000
.fill x41               ;data at mem locatoin x4001

.end
