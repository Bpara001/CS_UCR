;================================================
;SUBROUTINE:
;arguments:
;return value:
;================================================
.orig xabcd
;backup
ST R0, backup_r0_
ST R1, backup_r1_
ST R2, backup_r2_
ST R3, backup_r3_
ST R4, backup_r4_
ST R5, backup_r5_
ST R6, backup_r6_
ST R7, backup_r7_
;-------------------------
; INSTRUCTIONS;
;-------------------------








;restore&return
LD R0, backup_r0_
LD R1, backup_r1_
LD R2, backup_r2_
LD R3, backup_r3_
LD R4, backup_r4_
LD R5, backup_r5_
LD R6, backup_r6_
LD R7, backup_r7_
RET

;------------------
; DATA;
;------------------
backup_r0_ .blkw #1
backup_r1_ .blkw #1
backup_r2_ .blkw #1
backup_r3_ .blkw #1
backup_r4_ .blkw #1
backup_r5_ .blkw #1
backup_r6_ .blkw #1
backup_r7_ .blkw #1
