
;===========================
;main: test harness
;===========================
.orig x3000
;-------------------
;main; intstructions
;-------------------

LD R0, number
LD R6, right_shift
JSRR R6
HALT
;-------------------
;main; data
;-------------------
right_shift .fill x3200
number .fill x1234

;================================================
;SUBROUTINE: right_shift
;arguments: R0
;return value: R0 becomes right shifted
;================================================
.orig x3200
ST R1, rightshift_backup_r1
ST R2, rightshift_backup_r2
ST R3, rightshift_backup_r3
ST R4, rightshift_backup_r4
ST R5, rightshift_backup_r5
ST R6, rightshift_backup_r6
ST R7, rightshift_backup_r7
;----------------------
;instructions: right_shift
;-----------------------
ADD R1,R0,#0
LD R2, rightshift_DEC_2

LD R6, rightshift_divide_int
JSRR R6

LD R1, rightshift_backup_r1
LD R2, rightshift_backup_r2
LD R3, rightshift_backup_r3
LD R4, rightshift_backup_r4
LD R5, rightshift_backup_r5
LD R6, rightshift_backup_r6
LD R7, rightshift_backup_r7
RET

;;----------------------
;data: right_shift
;-----------------------
rightshift_divide_int .fill x3400
rightshift_DEC_2 .fill #2
rightshift_backup_r1 .blkw #1
rightshift_backup_r2 .blkw #1
rightshift_backup_r3 .blkw #1
rightshift_backup_r4 .blkw #1
rightshift_backup_r5 .blkw #1
rightshift_backup_r6 .blkw #1
rightshift_backup_r7 .blkw #1



;================================================
;SUBROUTINE: divide_int
;arguments: divides R1 by R2
;return value: quotient -> R0, remainder -> R3
;================================================
.orig x3400

;backup
ST R1, backup_r1_divide_int
ST R2, backup_r2_divide_int
ST R4, backup_r4_divide_int
ST R5, backup_r5_divide_int
ST R6, backup_r6_divide_int
ST R7, backup_r7_divide_int
;-------------------------
; INSTRUCTIONS; divide_int
;--------------------------
;q = n/d, remainder r
;R0 -> q
;R1 -> n
;R2 -> d (converted to -d)
;R3 -> r
;R4 -> TEMP (partial remainder)
LD R0, divideint_DEC_0
LD R3, divideint_DEC_0
NOT R2, R2
ADD R2, R2, #1
divideint_WHILE_LOOP_1              ;n-d = temp
    ADD R4, R1, R2
    BRz divideint_temp_is_zero      ;check: temp == 0?
    BRn divideint_temp_is_negative  ;check: temp < 0?
    ADD R0, R0, #1
    ADD R1, R4, #0                  ;n = temp
    BR divideint_WHILE_LOOP_1
divideint_temp_is_zero              ;no remainder
    ADD R0,R0,#1
    BR divideint_end
divideint_temp_is_negative          ;there is a remainder
    NOT R2,R2
    ADD R2,R2,#1
    ADD R4, R4,R2
    ADD R3, R4, #0                  ;remainder = temp
divideint_end
;restore & return
LD R1, backup_r1_divide_int
LD R2, backup_r2_divide_int
LD R4, backup_r4_divide_int
LD R5, backup_r5_divide_int
LD R6, backup_r6_divide_int
LD R7, backup_r7_divide_int
RET
;------------------
; DATA; divide_int
;------------------
backup_r1_divide_int .blkw #1
backup_r2_divide_int.blkw #1
backup_r4_divide_int .blkw #1
backup_r5_divide_int .blkw #1
backup_r6_divide_int .blkw #1
backup_r7_divide_int .blkw #1
divideint_DEC_0 .fill #0
