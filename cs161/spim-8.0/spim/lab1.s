.text
.globl main

main:



ori   $t1, $t1, 0x5678
lui   $t1, 0x1234

add $a0, $t1, $s0
li $v0,1
syscall

li $v0, 10
syscall

#---------------
#DATA
#----------------
.data

STR1:
 .asciiz "Enter Location of the binary point\n"

li $v0,10
syscall

MASK:
 .word 0xFF7FFFFF
