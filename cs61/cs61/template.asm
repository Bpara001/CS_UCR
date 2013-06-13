;====================================================
;SUBROUTINE: SUB_intelligent_name_goes_here_3200
;Input (Register you are “passing” as a parameter): [description of parameter]
;Postcondition: [a short description of what the subroutine does]
;Return Value: [which register (if any) has a return value and what it means]
 .ORIG xabcd
;=====================================================

;-------------------------
; INSTRUCTIONS;
;-------------------------

;(1)Backup all modified registers except Return Value
ST R0, backup_r0
ST R1, backup_r1
ST R2, backup_r2
ST R3, backup_r3
ST R4, backup_r4
ST R5, backup_r5
ST R6, backup_r6
ST R7, backup_r7

;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;(3)Restore all modified registers except Return Values
LD R0, backup_r0
LD R1, backup_r1
LD R2, backup_r2
LD R3, backup_r3
LD R4, backup_r4
LD R5, backup_r5
LD R6, backup_r6
LD R7, backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA;
;------------------
backup_r0 .blkw #1
backup_r1 .blkw #1
backup_r2 .blkw #1
backup_r3 .blkw #1
backup_r4 .blkw #1
backup_r5 .blkw #1
backup_r6 .blkw #1
backup_r7 .blkw #1
