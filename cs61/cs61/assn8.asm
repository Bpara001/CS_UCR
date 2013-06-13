;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: assn7
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
.orig x3000
main_start
;=====================================
;Main function
;=====================================
LD R6, SUB_MENU                 ;call PRINT MENU
JSRR R6
LD R3,dec_48

;figure out which function to go to
ADD R1,R1,#-1                   ;if(input == 1) GOTO function 1
BRz function1
ADD R1,R1,#-1                   ;if(input == 2) GOTO function 2
BRz function2
ADD R1,R1,#-1                   ;if(input == 3) GOTO function 3
BRz function3
ADD R1,R1,#-1                   ;if(input == 4) GOTO function 4
BRz function4
ADD R1,R1,#-1                   ;if(input == 5) GOTO function 5
BRz function5
ADD R1,R1,#-1                   ;if(input == 6) GOTO function 6
BRz function6
BR function7                    ;else exit(1)

;All_Busy
function1
LD R6, SUB_ALL_BUSY             ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_Allmachinesare    ;load string pt1
PUTS                            ;output
ADD R2,R2,#0                    ;check sub return Value
BRp all_busy_true               ;if return is ftrue(1) go to true(1)
    ;is false                       ;if false
    LEA R0,string_not               ;load the string
    PUTS                            ;output
    ;is true                        ;if true
    all_busy_true
    ;do nothing
LEA R0, string_busy             ;load string pt2
PUTS                            ;output
LEA R0,string_newline            ;load newline
PUTS                            ;output
BR pause1                       ;reloop program

;All_free
function2
LD R6, SUB_ALL_FREE             ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_Allmachinesare    ;load string pt1
PUTS                            ;output
ADD R2,R2,#0                    ;check sub return Value
BRp all_free_true               ;if return is ftrue(1) go to true(1)
    ;is false                       ;if false
    LEA R0,string_not               ;load the string
    PUTS                            ;output
    ;is true                        ;if true
    all_free_true
    ;do nothing
LEA R0, string_free             ;load string pt2
PUTS                            ;output
LEA R0,string_newline           ;load newline
PUTS                            ;output
BR pause1                       ;reloop program

;Num Free
function3
LD R6,SUB_NUM_FREE              ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_Thereare          ;load string pt1
PUTS                            ;output to console
    ADD R4,R2,#-10                  ;multiple digit check
    BRn digitcheck1                 ;if number < 10 then skip
    LD R0,ascii_1                   ;else, output 1
    OUT                             ;output
    ADD R2,R2,#-10                  ;number by 10 then repoutput
    digitcheck1
ADD R0,R2,R3                    ;convert to ascii
OUT                             ;otuput number
LEA R0,string_free              ;load string pt2
PUTS                            ;output
LEA R0,string_machines          ;load string pt3
PUTS                            ;output
BR pause1                       ;reloop program

;Num Busy
function4
LD R6,SUB_NUM_BUSY              ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_Thereare          ;load string pt1
PUTS                            ;output to console
    ADD R4,R2,#-10                  ;multiple digit check
    BRn digitcheck2                 ;if number < 10 then skip
    LD R0,ascii_1                   ;else, output 1
    OUT                             ;output
    ADD R2,R2,#-10                  ;number by 10 then repoutput
    digitcheck2
ADD R0,R2,R3                    ;convert to ascii
OUT                             ;otuput number
LEA R0,string_busy              ;load string pt2
PUTS                            ;output
LEA R0,string_machines          ;load string pt3
PUTS                            ;output
BR pause1                       ;reloop program

;is_busy
function5
LD R6,SUB_IS_BUSY               ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_is                ;output string pt2
PUTS                            ;output
ADD R2,R2,#0                    ;check R2
BRp is_busy_true                ;skip printing "not"
    ;if false
    LEA R0,string_not           ;load string not
    PUTS                        ;output
    ;if true
    is_busy_true
    ;do nothing
LEA R0,string_busy              ;load string pt3
PUTS                            ;output
LEA R0,string_newline           ;load newline
PUTS                            ;output
BR pause1                       ;reloop program

;is_free
function6
LD R6,SUB_IS_FREE               ;load sub
JSRR R6                         ;jump to sub
LEA R0,string_is                ;output string pt2
PUTS                            ;output
ADD R2,R2,#0                    ;check R2
BRp is_free_true                ;skip printing "not"
    ;if false
    LEA R0,string_not           ;load string not
    PUTS                        ;output
    ;if true
    is_free_true
    ;do nothing
LEA R0,string_free              ;load string pt3
PUTS                            ;output
LEA R0,string_newline           ;load newline
PUTS                            ;output
BR pause1                       ;reloop program


;pause1
pause1
LEA R0,string_pause
PUTS
GETC
BR main_start


;quit
function7
LEA R0,string_quit
PUTS


HALT
;=====================================
;Data <- main function
;====================================
SUB_MENU .fill x3200
SUB_ALL_BUSY .fill x3400
SUB_ALL_FREE .fill x3600
SUB_NUM_FREE .fill x3800
SUB_NUM_BUSY .fill x4000
SUB_IS_BUSY .fill x4200
SUB_IS_FREE .fill x4400
string_newline .stringz "\n"
string_Allmachinesare .stringz "All machines are"
string_free .stringz " free "
string_busy .stringz " busy "
string_machines .stringz "machines\n"
string_not .stringz " NOT"
string_Thereare .stringz "There are "
string_is .stringz " is"
string_quit .stringz "EXIT."
string_pause .stringz "\nPress any key\n"
dec_48 .fill #48
dec_n48 .fill #-48
ascii_1 .fill #49
dec_0 .fill #0

;====================================================
; Subroutine: MENU
; Inputs: None
; Postcondition: The subroutine has printed out a menu with numerical options,
; lets user to select an option, and returned the selected option.
; Return Value (R1): The option selected (i.e. #1, #2, #3, #4, #5, #6 or #7)
 .ORIG x3200
;=====================================================
;-------------------------
; INSTRUCTIONS; Menu
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, menu_backup_r0
ST R6, menu_backup_r6
ST R7, menu_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R1,menu_charptr          ;load ptr of where the block of chars are stored
menu_while                  ;while(ptr != NULL && ptr->next != NULL
    LDR R0,R1,#0            ;load the data at ptr
    BRz menu_while_check    ;check to see if ptr->data == NULL
    OUT                     ;if not NULL, output
    ADD R1,R1,#1            ;increment ptr
    BR menu_while           ;repeat loop
menu_while_end
BR menu_while_check_end     ;skip check block and terminate
;check
menu_while_check            ;check ptr->next->data
    LDR R0,R1,#1            ;check ptr->next
    BRz menu_while_check_end;if NULL end sub
    ADD R1,R1,#1            ;else, increment ptr
    BR menu_while           ;repeat loop
menu_while_check_end
;get user Input
GETC                        ;get user input
OUT                         ;output
ADD R1,R0,#0                ;copy input into R1
LD R0,menu_decn48           ;convert to real number
ADD R1,R1,R0                ;converting
LEA R0, menu_newline        ;output nweline character
PUTS                        ;output
;(3)Restore all modified registers except Return Values
LD R0, menu_backup_r0
LD R6, menu_backup_r6
LD R7, menu_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Menu
;------------------
menu_dec0 .fill #0
menu_charptr .fill x5000
menu_newline .stringz "\n->>>"
menu_decn48 .fill #-48
menu_backup_r0 .blkw #1
menu_backup_r2 .blkw #1
menu_backup_r3 .blkw #1
menu_backup_r4 .blkw #1
menu_backup_r5 .blkw #1
menu_backup_r6 .blkw #1
menu_backup_r7 .blkw #1


;====================================================
; Subroutine: ALL_MACHINES_BUSY
; Inputs: None
; Postcondition: The subroutine has returned a value
; indicating whether all machines are busy
; Return value (R2): 1 if all machines are busy, 0 otherwise
 .ORIG x3400
;=====================================================
;-------------------------
; INSTRUCTIONS;All busy
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, abusy_backup_r0
ST R1, abusy_backup_r1
ST R2, abusy_backup_r2
ST R3, abusy_backup_r3
ST R6, abusy_backup_r6
ST R7, abusy_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R2,abusy_ptr         ;load R2 with the ptr
LD R3,abusy_counter     ;load the counter
LDR R1,R2,#0            ;load the value of the busyness vector
abusy_loop1             ;for(int i = 0; i < 16; i++)
    ADD R1,R1,#0        ;check the value at busyness vector
    BRn abusy_false        ;if element is 1, print and exit
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BRp abusy_loop1     ;repeat loop
;if abusy is true
LD R2,abusy_dec1        ;load with bool true
BR abusy_end            ;end sub
;if abusy is false
abusy_false
LD R2,abusy_dec0        ;load with bool false

;(3)Restore all modified registers except Return Values
abusy_end
LD R0, abusy_backup_r0
LD R1, abusy_backup_r1
LD R2, abusy_backup_r2
LD R3, abusy_backup_r3
LD R6, abusy_backup_r6
LD R7, abusy_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; All busy
;------------------
abusy_dec0  .fill #0
abusy_dec1  .fill #1
abusy_ptr .fill x6000
abusy_counter .fill #16
abusy_backup_r0 .blkw #1
abusy_backup_r1 .blkw #1
abusy_backup_r2 .blkw #1
abusy_backup_r3 .blkw #1
abusy_backup_r6 .blkw #1
abusy_backup_r7 .blkw #1

;====================================================
; Subroutine: ALL_MACHINES_FREE
; Inputs: None
; Postcondition: The subroutine has returned a value
; indicating whether all machines are free
; Return value (R2): 1 if all machines are busy, 0 otherwise
 .ORIG x3600
;=====================================================
;-------------------------
; INSTRUCTIONS;All free
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, afree_backup_r0
ST R1, afree_backup_r1
ST R3, afree_backup_r3
ST R6, afree_backup_r6
ST R7, afree_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R2,afree_ptr         ;load R2 with the ptr
LD R3,afree_counter     ;load the counter
LDR R1,R2,#0            ;load the value of the busyness vector
afree_loop1             ;for(int i = 0; i < 16; i++)
    ADD R1,R1,#0        ;check the value at busyness vector
    BRzp afree_false        ;if element is 0, print and exit
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BRp afree_loop1     ;repeat loop
;if abusy is true
LD R2,afree_dec1        ;load with bool true
BR afree_end            ;end sub
;if abusy is false
afree_false
LD R2,afree_dec0        ;load with bool false

;(3)Restore all modified registers except Return Values
afree_end
LD R0, afree_backup_r0
LD R1, afree_backup_r1
LD R3, afree_backup_r3
LD R6, afree_backup_r6
LD R7, afree_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; All free
;------------------
afree_dec0  .fill #0
afree_dec1  .fill #1
afree_ptr .fill x6000
afree_counter .fill #16
afree_backup_r0 .blkw #1
afree_backup_r1 .blkw #1
afree_backup_r3 .blkw #1
afree_backup_r6 .blkw #1
afree_backup_r7 .blkw #1

;====================================================
; Subroutine: NUM_FREE_MACHINES
; Inputs: None
; Postcondition: The subroutine has returned the number of free machines
; Return Value (R2): The number of machines that are free
 .ORIG x3800
;=====================================================
;-------------------------
; INSTRUCTIONS;num free
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, nfree_backup_r0
ST R1, nfree_backup_r1
ST R3, nfree_backup_r3
ST R6, nfree_backup_r6
ST R7, nfree_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R2,nfree_ptr         ;load R2 with the ptr
LD R3,nfree_counter     ;load the counter
LDR R1,R2,#0            ;load the value of the busyness vector
LD R2,nfree_dec0        ;reset counter to 0
nfree_loop1             ;for(int i = 0; i < 16; i++)
    ADD R1,R1,#0        ;check the value at busyness vector
    BRzp nfree_false        ;if element is 0, do not add to counter
        ADD R2,R2,#1        ;increment total counter
    nfree_false
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BRp nfree_loop1     ;repeat loop
;(3)Restore all modified registers except Return Values
nfree_end
LD R0, nfree_backup_r0
LD R1, nfree_backup_r1
LD R3, nfree_backup_r3
LD R6, nfree_backup_r6
LD R7, nfree_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; num free
;------------------
nfree_dec0  .fill #0
nfree_dec48 .fill #48
nfree_ptr .fill x6000
nfree_counter .fill #16
nfree_backup_r0 .blkw #1
nfree_backup_r1 .blkw #1
nfree_backup_r3 .blkw #1
nfree_backup_r6 .blkw #1
nfree_backup_r7 .blkw #1

;====================================================
; Subroutine: NUM_BUSY_MACHINES
; Inputs: None
; Postcondition: The subroutine has returned the number of busy machines
; Return Value (R2): The number of machines that are busy
 .ORIG x4000
;=====================================================
;-------------------------
; INSTRUCTIONS;NUM busy
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, nbusy_backup_r0
ST R1, nbusy_backup_r1
ST R3, nbusy_backup_r3
ST R6, nbusy_backup_r6
ST R7, nbusy_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LD R2,nbusy_ptr         ;load R2 with the ptr
LD R3,nbusy_counter     ;load the counter
LDR R1,R2,#0            ;load the value of the busyness vector
LD R2,nbusy_dec0        ;reset counter to 0
nbusy_loop1             ;for(int i = 0; i < 16; i++)
    ADD R1,R1,#0        ;check the value at busyness vector
    BRn nbusy_false        ;if element is 0, do not add to counter
        ADD R2,R2,#1        ;increment total counter
    nbusy_false
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BRp nbusy_loop1     ;repeat loop
;(3)Restore all modified registers except Return Values
nbusy_end
LD R0, nbusy_backup_r0
LD R1, nbusy_backup_r1
LD R3, nbusy_backup_r3
LD R6, nbusy_backup_r6
LD R7, nbusy_backup_r7
;(4)Return to where you came from
RET

;------------------
; DATA; NUM busy
;------------------
nbusy_dec0  .fill #0
nbusy_ptr .fill x6000
nbusy_counter .fill #16
nbusy_backup_r0 .blkw #1
nbusy_backup_r1 .blkw #1
nbusy_backup_r3 .blkw #1
nbusy_backup_r6 .blkw #1
nbusy_backup_r7 .blkw #1


;====================================================
; Subroutine: IS_BUSY
; Input (R1): Which machine to check
; Postcondition: The subroutine has returned a value indicating
; whether the machine indicated  by (R1) is busy or not.
; Return Value (R2): 1 if machine (R1) is busy,    0 otherwise
 .ORIG x4200
;=====================================================
;-------------------------
; INSTRUCTIONS;IS_Busy
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, ibusy_backup_r0
ST R1, ibusy_backup_r1
ST R3, ibusy_backup_r3
ST R4, ibusy_backup_r4
ST R6, ibusy_backup_r6
ST R7, ibusy_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;getuser input
LEA R0, ibusy_string1       ;output get user input string
PUTS                        ;output to console
GETC                        ;get char
OUT                         ;echo
ADD R3,R0,#0                ;copy to R3
    GETC                        ;get second char
    OUT
    ADD R0,R0,#-10              ;check for enter
    BRz ibusy_check1_false     ;skip step if enter
    ADD R3,R0,#10               ;store second char +10
    ADD R3,R3,#10               ;+10
    GETC                        ;get dummy input
    ibusy_check1_false
LEA R0,ibusy_string2        ;load another string
PUTS                        ;output
    ADD R4,R3,#0                ;save element in R4
    LD R1,ibusy_decn58          ;check for multiple chars
    ADD R0,R3,R1                ;checking
    BRn ibusy_check2_false      ;ignore if check is wrong
    LD R0,ibusy_ascii_1         ;load '1'
    OUT                         ;output '1'
    ADD R3,R3,#-10              ;subtract -10 from ascii
    ibusy_check2_false
    ADD R0,R3,#0                ;copy R3 to R0
OUT                         ;echo machine number
ADD R3,R4,#0
LD R0,ibusy_decn48          ;convert machine number into dec
ADD R3,R3,R0                ;converting...

;determine if user ihnput is busy
LD R2,ibusy_ptr         ;load R2 with the ptr
LDR R1,R2,#0            ;load the value of the busyness vector
ibusy_loop1             ;for(int i = 0; i < 16; i++)
    ADD R3,R3,#0        ;check counter
    BRz ibusy_loop1_end ;repeat loop
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BR ibusy_loop1      ;repeat loop
ibusy_loop1_end
ADD R1,R1,#0            ;check right-shifted value
BRn ibusy_false
    LD R2,ibusy_dec1    ;if true
    BR ibusy_end        ;terminate sub,set to 1
ibusy_false             ;if false
    LD R2,ibusy_dec0    ;set to 0
;(3)Restore all modified registers except Return Values
ibusy_end
LD R0, ibusy_backup_r0
LD R1, ibusy_backup_r1
LD R3, ibusy_backup_r3
LD R4, ibusy_backup_r4
LD R6, ibusy_backup_r6
LD R7, ibusy_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; IS busy
;------------------
ibusy_string1 .stringz "Input Machine #[followed by [enter]]: "
ibusy_string2 .stringz "\nMachine "
ibusy_decn48 .fill #-48
ibusy_dec0  .fill #0
ibusy_dec1  .fill #2
ibusy_dec48 .fill #48
ibusy_ptr .fill x6000
ibusy_counter .fill #16
ibusy_decn58 .fill #-58
ibusy_ascii_1 .fill #49
ibusy_backup_r0 .blkw #1
ibusy_backup_r1 .blkw #1
ibusy_backup_r3 .blkw #1
ibusy_backup_r4 .blkw #1
ibusy_backup_r6 .blkw #1
ibusy_backup_r7 .blkw #1

;====================================================
; Subroutine: IS_Free
; Input (R1): Which machine to check
; Postcondition: The subroutine has returned a value indicating
; whether the machine indicated  by (R1) is free or not.
; Return Value (R2): 1 if machine (R1) is free,    0 otherwise
 .ORIG x4400
;=====================================================
;-------------------------
; INSTRUCTIONS;IS_Free
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, ifree_backup_r0
ST R1, ifree_backup_r1
ST R3, ifree_backup_r3
ST R4, ifree_backup_r4
ST R6, ifree_backup_r6
ST R7, ifree_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;getuser input
LEA R0, ifree_string1       ;output get user input string
PUTS                        ;output to console
GETC                        ;get char
OUT                         ;echo
ADD R3,R0,#0                ;copy to R3
    GETC                        ;get second char
    OUT
    ADD R0,R0,#-10              ;check for enter
    BRz isfree_check1_false     ;skip step if enter
    ADD R3,R0,#10               ;store second char +10
    ADD R3,R3,#10               ;+10
    GETC                        ;get dummy input
    isfree_check1_false
LEA R0,ifree_string2        ;load another string
PUTS                        ;output
    ADD R4,R3,#0                ;save element in R4
    LD R1,ifree_decn58          ;check for multiple chars
    ADD R0,R3,R1                ;checking
    BRn ifree_check2_false      ;ignore if check is wrong
    LD R0,ifree_ascii_1         ;load '1'
    OUT                         ;output '1'
    ADD R3,R3,#-10              ;subtract -10 from ascii
    ifree_check2_false
    ADD R0,R3,#0                ;copy R3 to R0
OUT                         ;echo machine number
ADD R3,R4,#0
LD R0,ifree_decn48          ;convert machine number into dec
ADD R3,R3,R0                ;converting...

;determine if user ihnput is free
LD R2,ifree_ptr         ;load R2 with the ptr
LDR R1,R2,#0            ;load the value of the busyness vector
ifree_loop1             ;for(int i = 0; i < 16; i++)
    ADD R3,R3,#0        ;check counter
    BRz ifree_loop1_end ;repeat loop
    ADD R1,R1,R1        ;double value
    ADD R3,R3,#-1       ;decrmeent counter
    BR ifree_loop1      ;repeat loop
ifree_loop1_end
ADD R1,R1,#0            ;check right-shifted value
BRzp ifree_false
    LD R2,ifree_dec1    ;if true
    BR ifree_end        ;terminate sub,set to 1
ifree_false             ;if false
    LD R2,ifree_dec0    ;set to 0
;(3)Restore all modified registers except Return Values
ifree_end
LD R0, ifree_backup_r0
LD R1, ifree_backup_r1
LD R3, ifree_backup_r3
LD R4, ifree_backup_r4
LD R6, ifree_backup_r6
LD R7, ifree_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; IS free
;------------------
ifree_string1 .stringz "Input Machine #[[followed by [enter]]: "
ifree_string2 .stringz "\nMachine "
ifree_decn48 .fill #-48
ifree_decn58 .fill #-58
ifree_dec58 .fill #48
ifree_ascii_1 .fill #49
ifree_dec0  .fill #0
ifree_dec1  .fill #2
ifree_dec48 .fill #48
ifree_ptr .fill x6000
ifree_counter .fill #16
ifree_backup_r0 .blkw #1
ifree_backup_r1 .blkw #1
ifree_backup_r3 .blkw #1
ifree_backup_r4 .blkw #1
ifree_backup_r6 .blkw #1
ifree_backup_r7 .blkw #1

;hard coded valuse used for outputing the characters
.orig x5000
.stringz "********************\n*The Busyness Server *"
.stringz "\n********************\n1.Check to see wether all "
.stringz "machines are busy\n2.Check to see weather all machines "
.stringz "are free\n3.Display the number of free machines\n4."
.stringz "Display the number of busy machines\n5.Display whether "
.stringz "a specific machine is busy\n6.Display whether a specific"
.stringz " machine is free\n7.Quit\n->>Choose function #: "

;//////////////////////////////////////////////////////////////////////
;//////////////////////////THE BUSYNESS VECTOR/////////////////////////
;//////////////////////////////////////////////////////////////////////
.orig x6000
.fill xFFFA


