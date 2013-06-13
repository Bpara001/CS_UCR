.data

V0: .word 12
V1: .word 3
V4: .word 16
V3: .word 128
V5: .word 1

.text

lw $1,V3($0)
lw $2,129($0)
lw $3,130($0)
lw $4,131($0)

L0:
add $5,$1,$2
sub $6,$3,$2
and $7,$1,$4
or $8,$1,$2
sw $8,133($0)
lw $9,133($0)
lw $10,132($0)

L1:
sub $9,$9,$2
slt $11,$9,$10
beq $11,$0,L1

j L0

