 ;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn8
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;===============================================
;MAIN CODE BLOCK
;==============================================
.orig x3000
;instructions

MAIN_START

;extend vector
LD R6, extend_vector
JSRR R6


LD R0, DEC_0
LD R6,MENU
JSRR R6
GETC
LD R1,DEC_n48
ADD R0,R0,R1

;check what number was inputted
ADD R0,R0,#-1       ;check 1
BRz input1
ADD R0,R0,#1
ADD R0,R0,#-2       ;check 2
BRz input2
ADD R0,R0,#2
ADD R0,R0,#-3       ;check 3
BRz input3
ADD R0,R0,#3
ADD R0,R0,#-4       ;check 4
BRz input4
ADD R0,R0,#4
ADD R0,R0,#-5       ;check 5
BRz input5
ADD R0,R0,#5
ADD R0,R0,#-6       ;check 6
BRz input6
ADD R0,R0,#6
ADD R0,R0,#-7       ;check 7
BRz input7
ADD R0,R0,#7

;do something about input
input1
    LD R6,ALL_MACHINES_BUSY
    JSRR R6
    BR restart
input2
    LD R6,ALL_MACHINES_FREE
    JSRR R6
    BR restart
input3
    LD R6,NUM_FREE_MACHINES
    JSRR R6
    BR restart
input4
    LD R6,NUM_BUSY_MACHINES
    JSRR R6
    BR restart
input5
    LD R6,READINT
    JSRR R6
    LD R6,IS_BUSY
    JSRR R6
    BR restart
input6
    LD R6,READINT
    JSRR R6
    LD R6,IS_FREE
    JSRR R6
    BR restart
input7
    BR end_main

;prompt continue key
restart
    LEA R0,message3
    PUTS
    GETC
    BR MAIN_START
end_main
LEA R0,message1
PUTS
HALT

;data
MENU .FILL x3200
ALL_MACHINES_BUSY .FILL x3800
ALL_MACHINES_FREE .FILL x4000
NUM_FREE_MACHINES .FILL x4200
NUM_BUSY_MACHINES .FILL x4400
extend_vector .fill x5200
IS_BUSY .FILL x4600
IS_FREE .FILL x4800
READINT .FILL x5400
DEC_n48 .fill #-48
DEC_0 .fill #0
DEC_n121 .fill #-121
message1 .stringz "\n\nQUTTING PROGRAM"
message3 .stringz "\nPRESS ANY KEY TO CONTINUE "

;================================================
;SUBROUTINE:MENU
;arguments:none
;post cond: The subroutine has printed out a menu with numerical options
;return value: R1; the option selected
;================================================
.orig x3200

;backup
ST R0, backup_r0_menu
ST R1, backup_r1_menu
ST R2, backup_r2_menu
ST R6, backup_r6_menu
ST R7, backup_r7_menu

;-------------------------
; INSTRUCTIONS; MENU
;-------------------------
LD R6, menu_print1
JSRR R6
LD R6, menu_print2
JSRR R6

LD R2,menu_n48
ADD R1,R0,R2

;restore&return
LD R0, backup_r0_menu
LD R1, backup_r1_menu
LD R2, backup_r2_menu
LD R6, backup_r6_menu
LD R7, backup_r7_menu
RET

;------------------
; DATA; MENU
;------------------
backup_r0_menu .blkw #1
backup_r1_menu .blkw #1
backup_r2_menu .blkw #1
backup_r6_menu .blkw #1
backup_r7_menu .blkw #1
menu_print1 .fill x3400
menu_print2 .fill x3600
menu_n48 .fill #-48


;--------------------------------------------------------------------
;---------------
;menu_print1
;---------------
.orig x3400
ST R0, backup_r0_menuprint1
ST R1, backup_r1_menuprint1
ST R2, backup_r2_menuprint1
ST R3, backup_r3_menuprint1
ST R7, backup_r7_menuprint1
LEA R0, menu_line1
PUTS
LEA R0, menu_line2
PUTS
LEA R0, menu_line3
PUTS
LEA R0, menu_line3a
PUTS

;print raw data
LD R1,menu_arrayptr
LD R2,menu_8
LD R3,menu_48
menu_for_loop
    LDR R0,R1,#0
    ADD R0,R0,R3
    out
    ADD R1,R1,#1
    ADD R2,R2,#-1
    BRp menu_for_loop

;continue printing raw text
LEA R0, menu_line4
PUTS
LEA R0, menu_line5
PUTS
LD R0, backup_r0_menuprint1
LD R1, backup_r1_menuprint1
LD R2, backup_r2_menuprint1
LD R3, backup_r3_menuprint1
LD R7, backup_r7_menuprint1
RET

backup_r0_menuprint1 .blkw #1
backup_r1_menuprint1 .blkw #1
backup_r2_menuprint1 .blkw #1
backup_r3_menuprint1 .blkw #1
backup_r7_menuprint1 .blkw #1
menu_line1 .STRINGz "\n\n*********************\n"
menu_line2 .stringz "*The Busyness Server*\n"
menu_line3 .STRINGz "*********************\n"
menu_line3a .stringz "RAW DATA: "
menu_line4 .stringz "\n1.Check to see wheater all machines are busy\n"
menu_line5 .stringz "2.Check to see wheater all machines are free\n"
menu_arrayptr .fill x5001
menu_8 .fill#16
menu_48 .fill#48

;--------------------------------------------------------------------
;--------------------------------------------------------------------
;---------------
;menu_print2
;---------------
.orig x3600
ST R0, backup_r0_menuprint2
ST R7, backup_r7_menuprint2
LEA R0, menu_line6
PUTS
LEA R0, menu_line7
PUTS
LEA R0, menu_line8
PUTS
LEA R0, menu_line9
PUTS
LEA R0, menu_line10
PUTS
LD R0, backup_r0_menuprint2
LD R7, backup_r7_menuprint2
RET

backup_r0_menuprint2 .blkw #1
backup_r7_menuprint2 .blkw #1
menu_line6 .stringz "3.Display the number of free machines\n"
menu_line7 .stringz "4.Display the number of busy machines\n"
menu_line8 .stringz "5.Display whether a specific machine is busy\n"
menu_line9 .stringz "6.Dislay whether a specific machine is free\n"
menu_line10 .stringz "7.Quit\n"
;--------------------------------------------------------------------
;================================================
;SUBROUTINE:all_machines_busy
;arguments:none
;post cond: returns weahter all machines are busy
;return value: R2: 1 if all are busy, 0 if not
;================================================
.orig x3800

;backup
ST R0, backup_r0_allbusy
ST R1, backup_r1_allbusy
ST R7, backup_r7_allbusy
;-------------------------
; INSTRUCTIONS;all machines_busy
;-------------------------

;for loop check:
;R0<- data being read
;R1<- data ptr
;R2<- 16counter
LD R1, allbusy_ptr
LD R2, allbusy_16
allbusy_FOR_LOOP
    LDR R0,R1,#0
    BRp allbusy_false
    ADD R1,R1,#1
    ADD R2,R2,#-1
    BRz allbusy_true
    BR allbusy_FOR_LOOP

;if all machines are busy
allbusy_true
    LD R2, allbusy_1
    LEA R0,allbusy_message1
    PUTS
    BR end_allbusy_main

;if all machines are not busy
allbusy_false
    LEA R0,allbusy_message2
    PUTS
    LD R2,allbusy_0

;restore&return
end_allbusy_main
LD R0, backup_r0_allbusy
LD R1, backup_r1_allbusy
LD R7, backup_r7_allbusy
RET

;------------------
; DATA;
;------------------
backup_r0_allbusy .blkw #1
backup_r1_allbusy .blkw #1
backup_r7_allbusy .blkw #1
allbusy_0 .fill #0
allbusy_1 .fill #1
allbusy_16 .fill #16
allbusy_ptr .fill x5001
allbusy_message1 .stringz "\n\"All machines are busy\"\n"
allbusy_message2 .stringz "\n\"All machines are not busy\"\n"


;================================================
;SUBROUTINE:ALL_machiens_free
;arguments:none
;post cond: the sub has value indiciating weather all machines are free
;return value: R2: if all machiens are free, 0 otherwise
;================================================
.orig x4000

;backup
ST R0, backup_r0_allfree
ST R1, backup_r1_allfree
ST R7, backup_r7_allfree
;-------------------------
; INSTRUCTIONS;all_machines_free
;-------------------------
;for loop check:
;R0<- data being read
;R1<- data ptr
;R2<- 16counter
LD R1, allfree_ptr
LD R2, allfree_16
allfree_FOR_LOOP
    LDR R0,R1,#0
    BRz allfree_false
    ADD R1,R1,#1
    ADD R2,R2,#-1
    BRz allfree_true
    BR allfree_FOR_LOOP

;if all machines are busy
allfree_true
    LD R2, allfree_1
    LEA R0, allfree_message1
    PUTS
    BR end_allfree_main

;if all machines are not busy
allfree_false
    LD R2,allfree_0
    LEA R0, allfree_message2
    PUTS

;restore&return
end_allfree_main
LD R0, backup_r0_allfree
LD R1, backup_r1_allfree
LD R7, backup_r7_allfree
RET

;------------------
; DATA;all_machines_free
;------------------
backup_r0_allfree .blkw #1
backup_r1_allfree .blkw #1
backup_r3_allfree .blkw #1
backup_r4_allfree .blkw #1
backup_r5_allfree .blkw #1
backup_r6_allfree .blkw #1
backup_r7_allfree .blkw #1
allfree_0 .fill #0
allfree_1 .fill #1
allfree_16 .fill #16
allfree_ptr .fill x5001
allfree_message1 .stringz "\n\"All machines are free\"\n"
allfree_message2 .stringz "\n\"All machines are not free\"\n"



;================================================
;SUBROUTINE:NUM_MACHINES_FREE
;arguments:none
;postcond. The subroutine returns the number of free machines
;return value: R2 <- the number of machines that are free
;================================================
.orig x4200

;backup
ST R0, backup_r0_numfree
ST R1, backup_r1_numfree
ST R3, backup_r3_numfree
ST R7, backup_r7_numfree
;-------------------------
; INSTRUCTIONS;NUM_MACHINES_FREE
;-------------------------

;for loop check
;R0 <- data being read
;R1 <- array ptr
;R2 <- counter
;R3 <- total machines free
LD R1, numfree_ptr
LD R2, numfree_16
LD R3, numfree_0
numfree_for_loop
    LDR R0,R1,#0
    BRp numfree_found
    numfree_continued
    ADD R1,R1,#1
    ADD R2,R2,#-1
    BRz end_numfree_main
    BR numfree_for_loop

;if free machine is found
numfree_found
    ADD R3,R3,#1
    BR numfree_continued

end_numfree_main

;print out how many are free
LEA R0, numfree_message1
PUTS
ADD R2,R3,#0
ADD R0,R2,#0
LD R3,numfree_outputint
JSRR R3
LEA R0, numfree_message2
PUTS
;restore&return
LD R0, backup_r0_numfree
LD R1, backup_r1_numfree
LD R3, backup_r3_numfree
LD R7, backup_r7_numfree
RET

;------------------
; DATA;NUM_MACHINES_FREE
;------------------
backup_r0_numfree .blkw #1
backup_r1_numfree .blkw #1
backup_r3_numfree .blkw #1
backup_r7_numfree .blkw #1
numfree_ptr .fill x5001
numfree_0 .fill #0
numfree_16 .fill #16
numfree_message1 .stringz "\n\"There are "
numfree_message2 .stringz " free machines\"\n "
numfree_48 .fill#-48
numfree_outputint .fill x5600


;================================================
;SUBROUTINE:NUM_BUSY_MACHINES
;arguments:none
;postcond: returns the number of busy machines
;return value:R2 <- the number of busy machines
;================================================
.orig x4400

;backup
ST R0, backup_r0_numbusy
ST R1, backup_r1_numbusy
ST R3, backup_r3_numbusy
ST R7, backup_r7_numbusy
;-------------------------
; INSTRUCTIONS;NUM_BUSY_MACHINES
;-------------------------
;for loop check
;R0 <- data being read
;R1 <- array ptr
;R2 <- counter
;R3 <- total machines free
LD R1, numbusy_ptr
LD R2, numbusy_16
LD R3, numbusy_0
numbusy_for_loop
    LDR R0,R1,#0
    BRz numbusy_found
    numbusy_continued
    ADD R1,R1,#1
    ADD R2,R2,#-1
    BRz end_numbusy_main
    BR numbusy_for_loop

;if busy machine is found
numbusy_found
    ADD R3,R3,#1
    BR numbusy_continued

end_numbusy_main
;print out how many are busy
LEA R0, numbusy_message1
PUTS
ADD R2,R3,#0
ADD R0,R2,#0
LD R3,numbusy_outputint
JSRR R3
LEA R0, numbusy_message2
PUTS

;restore&return
LD R0, backup_r0_numbusy
LD R1, backup_r1_numbusy
LD R3, backup_r3_numbusy
LD R7, backup_r7_numbusy
RET

;------------------
; DATA;NUM_BUSY_MACHINES
;------------------
backup_r0_numbusy .blkw #1
backup_r1_numbusy .blkw #1
backup_r3_numbusy .blkw #1
backup_r7_numbusy .blkw #1
numbusy_ptr .fill x5001
numbusy_0 .fill #0
numbusy_16 .fill #16
numbusy_message1 .stringz "\n\"There are "
numbusy_message2 .stringz " machines busy\"\n"
numbusy_48 .fill #48
numbusy_outputint .fill x5600

;================================================
;SUBROUTINE:IS_BUSY
;arguments:R1, which machine to check
;postcond: checks if certain machine is busy
;return value:R2 <- 1 if true, 0 of false
;================================================
.orig x4600

;backup
ST R0, backup_r0_isbusy
ST R1, backup_r1_isbusy
ST R3, backup_r3_isbusy
ST R7, backup_r7_isbusy
;-------------------------
; INSTRUCTIONS;IS_BUSY
;-------------------------

;check to see if it is busy
;R0 <- data in R1
;R1 <- array number
;R2 <-array number ptr
;R3 <- stored location # in array
ADD R3, R1, #0
NOT R1,R1
ADD R1,R1,#1
LD R2,isbusy_ptr_end
ADD R2,R2,R1
LDR R0,R2,#0
ADD R0,R0,#0
BRz isbusy_true
BR isbusy_false

isbusy_true
    LD R2, isbusy_1
    LEA R0,isbusy_message1
    PUTS
    LD R0,backup_r1_isbusy
    LD R3,isbusy_outputint
    JSRR R3
    LEA R0,isbusy_message2t
    PUTS
    BR end_isbusy_main

isbusy_false
    LD R2, isbusy_0
    LEA R0,isbusy_message1
    PUTS
    LD R0,backup_r1_isbusy
    LD R3,isbusy_outputint
    JSRR R3
    LEA R0,isbusy_message2f
    PUTS

end_isbusy_main
;restore&return
LD R0, backup_r0_isbusy
LD R1, backup_r1_isbusy
LD R3, backup_r3_isbusy
LD R7, backup_r7_isbusy
RET

;------------------
; DATA;IS_BUSY
;------------------
backup_r0_isbusy .blkw #1
backup_r1_isbusy .blkw #1
backup_r3_isbusy .blkw #1
backup_r7_isbusy .blkw #1
isbusy_ptr_end .fill x5010
isbusy_0 .fill #0
isbusy_1 .fill #1
isbusy_message1 .stringz "\nMachine "
isbusy_message2f .stringz " is not busy"
isbusy_message2t .stringz " is busy"
isbusy_48 .fill #48
isbusy_outputint .fill x5600

;================================================
;SUBROUTINE:IS_FREE
;arguments:R1 <- which machien to check
;return value: R2 <- weather the machine is free
;================================================
.orig x4800
;backup
ST R0, backup_r0_isfree
ST R1, backup_r1_isfree
ST R3, backup_r3_isfree
ST R7, backup_r7_isfree
;-------------------------
; INSTRUCTIONS; IS_FREE
;-------------------------
;check to see if it is busy
;R0 <- data in R1
;R1 <- array number
;R2 <-array number ptr
;R3 <- temp holder for #
ADD R3,R1,#0
NOT R1,R1
ADD R1,R1,#1

LD R2,isfree_ptr_end
ADD R2,R2,R1            ;R2 = R2 - R1
LDR R0,R2,#0
ADD R0,R0,#0
BRp isfree_true
BR isfree_false

isfree_true
    LD R2, isfree_1
    LEA R0,isfree_message1
    PUTS
    LD R0,backup_r1_isfree
    LD R3,isfree_outputint
    JSRR R3
    LEA R0,isfree_message2t
    PUTS
    BR end_isfree_main

isfree_false
    LD R2, isfree_0
    LEA R0,isfree_message1
    PUTS
    LD R0,backup_r1_isfree
    LD R3,isfree_outputint
    JSRR R3
    LEA R0,isfree_message2f
    PUTS

end_isfree_main

;restore&return
LD R0, backup_r0_isfree
LD R1, backup_r1_isfree
LD R3, backup_r3_isfree
LD R7, backup_r7_isfree
RET

;------------------
; DATA; IS_FREE
;------------------
backup_r0_isfree .blkw #1
backup_r1_isfree .blkw #1
backup_r3_isfree .blkw #1
backup_r7_isfree .blkw #1
isfree_ptr_end .fill x5010
isfree_0 .fill #0
isfree_1 .fill #1
isfree_message1 .stringz "\nMachine "
isfree_message2f .stringz " is not free"
isfree_message2t .stringz " is free\""
isfree_48 .fill #48
isfree_outputint .fill x5600

;================================================
;SUBROUTINE:extend vector
;arguments:none
;return value: reads and puts first 8 bits of 16 bit number at x5001 to x5010
;================================================
.orig x5200
;backup
ST R0, backup_r0_extend
ST R1, backup_r1_extend
ST R2, backup_r2_extend
ST R3, backup_r3_extend
ST R7, backup_r7_extend
;-------------------------
; INSTRUCTIONS;extend
;-------------------------
;R0 data being read
;R1 ptr to array
;R2 counter 8
LD R0, extend_ptr5000
LD R1, extend_ptrfront
LD R2, extend_8
LDR R0,R0,#0

extend_FOR_LOOP
    ADD R0,R0,#0
    BRzp extend_positive

        extend_negative
            LD R3, extend_1
            BR end_if_extend
        extend_positive
            LD R3, extend_0
    end_if_extend
    STR R3,R1,#0
    ADD R1,R1,#1
    ADD R0,R0,R0
    ADD R2,R2,#-1
    BRp extend_FOR_LOOP
end_extend_FOR_LOOP

;restore&return
LD R0, backup_r0_extend
LD R1, backup_r1_extend
LD R2, backup_r2_extend
LD R3, backup_r3_extend
LD R7, backup_r7_extend
RET

;------------------
; DATA;extend
;------------------
backup_r0_extend .blkw #1
backup_r1_extend .blkw #1
backup_r2_extend .blkw #1
backup_r3_extend .blkw #1
backup_r7_extend .blkw #1
extend_ptr5000 .fill x5000
extend_ptrfront .fill x5001
extend_ptrback .fill x5010
extend_0 .fill #0
extend_1 .fill #1
extend_8 .fill #16

;================================================
;SUBROUTINE: read_int
;arguments: none
;return value: returns user INPUT of INT into R1
;================================================
.orig x5400
;backup
ST R0, backup_r0_readint
ST R2, backup_r2_readint
ST R3, backup_r3_readint
ST R4, backup_r4_readint
ST R7, backup_r7_readint
;-------------------------
; INSTRUCTIONS; read_int
;-------------------------
;determine if one or two digits was inputed
readint_determine
    LD R4, readint_n48
    LEA R0,readint_message1
    PUTS
    GETC
    OUT
    ADD R2,R0,R4
    GETC
    OUT
    ADD R0,R0,#-10
    BRz readint_CASE1
    ADD R3,R0,R4
    GETC
    ADD R0,R0,#-10
    BRz readint_CASE2
    BR readint_invalid

;only one digit was inputed
readint_CASE1
    ADD R1,R2,#0
    BR end_readint

;two digits was inputed
readint_CASE2
    ADD R3,R3,#10
    ADD R1,R3,#10
    BR end_readint

;invalid input
readint_invalid
    LEA R0,readint_message2
    BR readint_determine


;restore&return
end_readint
LD R0, backup_r0_readint
LD R2, backup_r2_readint
LD R3, backup_r3_readint
LD R4, backup_r4_readint
LD R7, backup_r7_readint
RET

;------------------
; DATA;read_int
;------------------
backup_r0_readint .blkw #1
backup_r2_readint .blkw #1
backup_r3_readint .blkw #1
backup_r4_readint .blkw #1
backup_r7_readint .blkw #1
readint_message1 .stringz "INPUT NUMBER,PRESS[ENTER] WHEN DONE\n"
readint_message2 .stringz "----INVALID INPUT---\n"
readint_n48 .fill #-48

;================================================
;SUBROUTINE:output_int
;arguments:R0 as the dec value
;return value:outputs R0 to the console
;================================================
.orig x5600
;backup
ST R0, backup_r0_output
ST R1, backup_r1_output
ST R2, backup_r2_output
ST R7, backup_r7_output
;-------------------------
; INSTRUCTIONS;output_int
;-------------------------
;determine if weather to output 2 or 1 char's
LD R2, output_48
ADD R1,R0,#-10
BRzp outputcase2

outputcase1             ;output one char
    ADD R0,R0,R2
    OUT
    BR end_output

outputcase2             ;output two char's
    ADD R0,R2,#1
    OUT
    ADD R0,R1,R2
    OUT
    BR end_output

;restore&return
end_output
LD R0, backup_r0_output
LD R1, backup_r1_output
LD R2, backup_r2_output
LD R7, backup_r7_output
RET

;------------------
; DATA;
;------------------
backup_r0_output .blkw #1
backup_r1_output .blkw #1
backup_r2_output .blkw #1
backup_r7_output .blkw #1
output_48 .fill #48


;================================
;BUSYNESS VECTOR
;================================
.orig x5000
.fill xABCD
