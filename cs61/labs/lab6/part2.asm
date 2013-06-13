
;===========================
;main: test harness
;===========================
.orig x3000
;-------------------
;main; intstructions
;-------------------

IN
LD R6, return_1s
JSRR R6

HALT
;-------------------
;main; data
;-------------------
return_1s .fill x3200

;================================================
;SUBROUTINE: return_1s
;arguments: R0
;return value: returns number of 1's to R1
;================================================
.orig x3200
ST R0, return1s_backup_r0
ST R2, return1s_backup_r2
ST R3, return1s_backup_r3
ST R4, return1s_backup_r4
ST R5, return1s_backup_r5
ST R6, return1s_backup_r6
ST R7, return1s_backup_r7
;----------------------
;instructions: return_1s
;-----------------------
;R0-> orginal #, temp #
;R1-> total 1's
;R2 -> count starting from 16

LD R1, return1s_DEC_0

LD R2, return1s_DEC_16

return1s_FOR_LOOP_1
    add R2,R2,#-1
    BRn return1s_END_FOR_LOOP_1
    add R0,R0,#0
        return1s_IF_STATMENT_1
        BRzp return1s_END_IF_STATEMENT_1
            add R1,R1,#1
        return1s_END_IF_STATEMENT_1
        add R0,R0,R0
        BR return1s_FOR_LOOP_1
return1s_END_FOR_LOOP_1

LD R0, return1s_backup_r0
LD R2, return1s_backup_r2
LD R3, return1s_backup_r3
LD R4, return1s_backup_r4
LD R5, return1s_backup_r5
LD R6, return1s_backup_r6
LD R7, return1s_backup_r7
RET

;;----------------------
;data
;-----------------------
return1s_backup_r0 .blkw #1
return1s_backup_r2 .blkw #1
return1s_backup_r3 .blkw #1
return1s_backup_r4 .blkw #1
return1s_backup_r5 .blkw #1
return1s_backup_r6 .blkw #1
return1s_backup_r7 .blkw #1
return1s_DEC_16 .fill #16
return1s_DEC_0 .fill#0





