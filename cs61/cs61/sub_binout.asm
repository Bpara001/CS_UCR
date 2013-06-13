;================================================
;SUBROUTINE: Binary Output
;arguments: R1 <- value
;return value: prints value into 16-bit binary
;================================================
.orig x3200
;backup registers
ST R0, binout_backup_r0
ST R1, binout_backup_r1
ST R2, binout_backup_r2
ST R3, binout_backup_r3
ST R7, binout_backup_r7
;set user input number & counters, output initial b
LD R2,binout_dec_16
LD R3,binout_dec_4
puts
LD R0,binout_ascii_b                   ;output initial 'b'
OUT
;read value and output
binout_forloop1                        ;for(int i = 16; i > 0; i--)
    ADD R1,R1,#0
    BRzp binout_if_positive
    ;if leading bit is 0
        LD R0,binout_ascii_1           ;output "1"
        out
        BR binout_if_positive_end
    ;if leading bit is 1
    binout_if_positive
        LD R0,binout_ascii_0           ;output "0"
        out
    binout_if_positive_end
    ;check 4char spacing
    ADD R3,R3,#-1
    BRp binout_if_4charspacing_end ;output space if needed(every 4 iterations)
        LD R0,binout_ascii_space
        out
        LD R3,binout_dec_4
    binout_if_4charspacing_end
    ;left shift, increment counters
    ADD R1,R1,R1
    ADD R2,R2,#-1
    BRp binout_forloop1
binout_for_loop1_end
;restore&return
LD R0, binout_backup_r0
LD R1, binout_backup_r1
LD R2, binout_backup_r2
LD R3, binout_backup_r3
LD R7, binout_backup_r7
RET
;-----------------------------
;BinOut->data
;------------------------------
binout_backup_r0 .blkw #1
binout_backup_r1 .blkw #1
binout_backup_r2 .blkw #1
binout_backup_r3 .blkw #1
binout_backup_r7 .blkw #1
binout_dec_16 .fill #16
binout_dec_4  .fill #4
binout_ascii_0 .fill #48
binout_ascii_1 .fill #49
binout_ascii_space .fill #32
binout_ascii_b .fill #98
