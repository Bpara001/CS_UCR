#Names: James Fang, Chris Wong
#Login: jfang003, wongc
#Email: jfang003@ucr.edu, cwong030@ucr.edu
#Lab Section: 0##
#Assignment: Lab #2
#I acknowledge all content is original.

.text
.globl main

main:
    subu $sp, $sp, 32
    sw $ra, 20($sp)
    sw $fp, 16($sp)
    addiu $fp, $sp, 28

#====================================================================
#User interface
#====================================================================

#==== PHASE 1: GET USER INPUTs ======
li $v0, 4                   #output string to console
la $a0, STR1
syscall

li $v0, 5                   #get first input from user
syscall                     #s0 <- user input (binary pnt)
add $s0, $v0, $zero

li $v0, 4                   #output string to console
la $a0, STR2
syscall

li $v0, 5                   #get second input from user
syscall                     #s1 <- user input (fixed number)
add $s1, $v0, $zero


#==== PHASE 2: GETTING SIGNED BIT =====
bgtz $s1, POS               #If signed is positive, go to positive block
addi $s7, $zero, 1          #else, invert the bits
sll $s7, $s7, 31
addi $t5, $zero, -1
xor $s1, $s1, $t5           #s1 <- NOT(s1) +1
j NEXT

POS:
add $s7, $zero, $zero       #s7 <- signed bit flag

NEXT:


#==== PHASE 3: SETTING MAN. and EXPONENT =======

add $t2, $zero, $zero       #t2 <- i (initialize at 0)
addi $t1, $zero, 32         #t1 <- 32
addi $s2, $zero, 1          #s2 <- the mask

LOOP1:
    beq $t2, $t1, ENDLOOP1  #for(int i = 0; i < 32; i++)
    and $s3, $s2, $s1       #s3 <- s2 & s1
    beq $s3, $zero, CONT    #if s3 == 0 go to cont'
    add $s4, $t2, $zero     #s4 <- t2
    CONT:
    addi $t2, $t2, 1        #increment t2
    sll $s2, $s2, 1         #left shift s2 by 1
    j LOOP1                 #repeat loop
ENDLOOP1:

addi $t4, $zero, 127        #t4 <- set base 127 to exponent
add $t4, $t4, $s4           #t4 <- 127 + s4
sub $t4, $t4, $s0           #t4 <- t4 - binary pnt

addi $t6, $zero, 511        #mask t6 to set other bits to zero
sll $t6, $t6, 23
addi $t5, $zero, -1
xor $t6, $t6, $t5

addi $t7, $zero, 23         #move mantica to approprate place
sub $t7, $t7, $s4
sll $t5, $s1, $t7
and $t5, $t5, $t6

sll $t4, $t4, 23            #shift exponent to appropriate place
add $s5, $zero, $zero
or $s5, $s5, $t5            #OR all the parts together
or $s5, $s5, $t4            #s5 <- signed bit | exponent | man
or $s5, $s5, $s7

li $v0,1                    #output s5 to console
add $a0, $s5, $zero
syscall
li $v0, 4
la $a0, NEWLINE
syscall

li $v0, 10                  #call halt (end program)
syscall

#====================================================================
#Data Block
#====================================================================
.data
STR1:
    .asciiz "Enter the location of the binary point: "
STR2:
    .asciiz "Enter the 32-bit fixed point number: "
NEWLINE:
    .asciiz "\n"
