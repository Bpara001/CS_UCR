;=================================================
;
; Name: wong, christ
; Login id: wongc
;
; Assignment name: lab8
; Lab section: 021
; TA: Tarango J
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
.orig x3000
;===============================
;TEST HARNESS
;==============================

LD R0,ptr                     ;load ptr into argument
LD R6, SUB_GET_STRING         ;load SUBROUTINE
LD R4, SUB_PALINDROME         ;load SUBROUTINE
JSRR R6                       ;call get string subroutine
JSRR R4                       ;call bool is palindrone subroutine

ADD R4,R4,#0                 ;check R4
BRz if_false                 ;check R4 for 0 or 1

if_true                     ;if R4 is true(1)
    LEA R0,stringtrue       ;load true string
    PUTS                    ;output to console
    BR main_end
if_false                    ;if R4 is flase(0)
    LEA R0,stringfalse      ;load false string
    PUTS                    ;output to console
main_end
HALT
;----------------
;Main data
;---------------
ptr .fill x4000
SUB_GET_STRING .fill x3200
SUB_PALINDROME .fill x3400
stringtrue .stringz "\nuser input IS palindrome!"
stringfalse .stringz "\nuser input is NOT palindrome!"


;====================================================
;SUBROUTINE: SUB_GET-STRING
;Input  (R0): The address of where to start storing the strin
;Postcondition: The subroutine has allowed the user to input a string,
;               terminated by the [ENTER] key, and has stored it in an array
;                that starts at (R0) and is NULL-terminated.
; Return Value: R5 <- The number of non-sentinel characters read from the use
 .ORIG x3200
;=====================================================
;-------------------------
; INSTRUCTIONS;Get string
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, gets_backup_r0
ST R1, gets_backup_r1
ST R2, gets_backup_r2
ST R6, gets_backup_r6
ST R7, gets_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
ADD R1,R0,#0                        ;copy pointer to R0
LEA R0, gets_string1                ;load instruction message
PUTS                                ;output to console
LD R5, gets_dec0                    ;set ocunter to 0

gets_While_loop1                    ;while userinput != [ENTER]
    GETC                            ;get input
    OUT                             ;echo

    ;CHECK#0: check if [enter] key
    ADD R0,R0,#-10                  ;check if enter
    BRz gets_While_loop1_end        ;if enter key, end while loop
    ADD R0,R0,#10                   ;convert back to ascii letter

    ;EXTRA CHECK#1: ignore whitespace & puncuation+symbols pt1
    LD R2,gets_ascii_ncheck1        ;load check1 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRnz gets_While_loop1            ;if n or z, igonore (repeat loop)
    LD R2,gets_ascii_check1         ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number

    ;EXTRA CHECK#2: ignore puncuation pt2
    LD R2,gets_ascii_ncheck2        ;load check2 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRp gets_While_loop1            ;if p igonore (repeat loop)
    LD R2,gets_ascii_check2         ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number

    ;EXTRA CHECK#3: ignore puncuation pt3
    LD R2,gets_ascii_ncheck3a       ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if z, igonore (repeat loop)
    LD R2,gets_ascii_check3a        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
        LD R2,gets_ascii_ncheck3b   ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if , igonore (repeat loop)
    LD R2,gets_ascii_check3b        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
        LD R2,gets_ascii_ncheck3c   ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if z, igonore (repeat loop)
    LD R2,gets_ascii_check3c        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
        LD R2,gets_ascii_ncheck3d   ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if n or z, igonore (repeat loop)
    LD R2,gets_ascii_check3d        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
        LD R2,gets_ascii_ncheck3e   ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if z, igonore (repeat loop)
    LD R2,gets_ascii_check3e        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
        LD R2,gets_ascii_ncheck3f   ;load check3 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRz gets_While_loop1            ;if z, igonore (repeat loop)
    LD R2,gets_ascii_check3f        ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number

    ;EXTRA CHECK#4: is NOT case-sensitive
    LD R2,gets_ascii_ncheck4        ;load check4 into R2
    ADD R0,R0,R2                    ;Do R0-R2
    BRp gets_check4_end             ;if p ignore this check
        LD R2, gets_ascii_convert   ;if uppercase, convert to lowercase
        ADD R0,R0,R2                ;convert by +32
    gets_check4_end
    LD R2,gets_ascii_check4         ;else
    ADD R0,R0,R2                    ;convert R0 back to orginal number
    ;If passes checks, stores input
    STR R0,R1,#0                    ;Store R0 into R1
    ADD R1,R1,#1                    ;increment pointer
    ADD R5,R5,#1                    ;increment total counter
    BR gets_While_loop1             ;repeat loop
gets_While_loop1_end
LD R0,gets_dec0                      ;load R0 with null terminating character
STR R0,R1,#0                        ;store R0 into the array
;(3)Restore all modified registers except Return Values
LD R0, gets_backup_r0
LD R1, gets_backup_r1
LD R2, gets_backup_r2
LD R6, gets_backup_r6
LD R7, gets_backup_r7
;(4)Return to where you came from
RET

;------------------
; DATA; Get string
;------------------
gets_string1 .stringz "Enter a string,hit [ENTER] key to finish:\n"
gets_dec0 .fill #0
gets_ascii_check1 .fill #64
gets_ascii_ncheck1 .fill #-64
gets_ascii_check2 .fill #122
gets_ascii_ncheck2 .fill #-122
gets_ascii_check3a .fill #91
gets_ascii_ncheck3a .fill #-91
gets_ascii_check3b .fill #92
gets_ascii_ncheck3b .fill #-92
gets_ascii_check3c .fill #93
gets_ascii_ncheck3c .fill #-93
gets_ascii_check3d .fill #94
gets_ascii_ncheck3d .fill #-94
gets_ascii_check3e .fill #95
gets_ascii_ncheck3e .fill #-95
gets_ascii_check3f .fill #96
gets_ascii_ncheck3f .fill #-96
gets_ascii_check4 .fill #90
gets_ascii_ncheck4 .fill #-90
gets_ascii_convert .fill #32
gets_backup_r0 .blkw #1
gets_backup_r1 .blkw #1
gets_backup_r2 .blkw #1
gets_backup_r4 .blkw #1
gets_backup_r6 .blkw #1
gets_backup_r7 .blkw #1


;====================================================

; Subroutine: SUB_IS_A_PALINDROME
; Parameter (R0): The address of a string
; Parameter (R5): The number of characters in the array.
; Postcondition: The subroutine has determined whether the string at (R0) is
;                  a palindrome or not returned a flag indicating such.
;Return Value: R4 <- {1 if the string is a palindrome, 0 otherwise
 .ORIG x3400
;=====================================================
;-------------------------
; INSTRUCTIONS; IS Palindrome
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, isp_backup_r0
ST R1, isp_backup_r1
ST R2, isp_backup_r2
ST R3, isp_backup_r3
ST R5, isp_backup_r5
ST R6, isp_backup_r6
ST R7, isp_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
;R0 <- ptr to beginning
;R1 <- ptr to end
;R2 <- value of beginning
;R3 <- value of end
ADD R1,R0,R5                  ;set R1 to end of array
ADD R1,R1,#-1                 ;subtract sential to get correct ptr location
isp_while1                    ;while begin_ptr != end ptr || bein_ptr > end_ptr
    LDR R2,R0,#0                ;R2 <- data at begin_ptr
    LDR R3,R1,#0                ;R3 <- data at end_ptr
    NOT R2,R2                   ;invert R2
    ADD R2,R2,#1                ;convert to two's compelment
    ADD R4,R2,R3                ;Do R2-R3; check if letters are palidrome
    BRnp isp_FALSE              ;if false, go to false block
    ADD R0,R0,#1                ;increment front ptr
    ADD R1,R1,#-1               ;decrement back ptr
    NOT R0,R0                   ;invert R0
    ADD R0,R0,#1                ;convert to two's comeplement
    ADD R4,R0,R1                ;check if ptrs
    BRnz isp_while1_end          ;if beginp == endp || begin_ptr > end_ptr
    NOT R0,R0                   ;else reconvert R0
    ADD R0,R0,#1                ;convert back
    BR isp_while1               ;repeat loop
isp_while1_end

LD R4,isp_dec1                  ;if palindrome, then return 1
BR isp_end

isp_FALSE                       ;if not palindrome, return 0
LD R4,isp_dec0


;(3)Restore all modified registers except Return Values
isp_end
LD R0, isp_backup_r0
LD R1, isp_backup_r1
LD R2, isp_backup_r2
LD R3, isp_backup_r3
LD R5, isp_backup_r5
LD R6, isp_backup_r6
LD R7, isp_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; is Palindrome
;------------------
isp_dec0        .fill #0
isp_dec1        .fill #1
isp_backup_r0 .blkw #1
isp_backup_r1 .blkw #1
isp_backup_r2 .blkw #1
isp_backup_r3 .blkw #1
isp_backup_r5 .blkw #1
isp_backup_r6 .blkw #1
isp_backup_r7 .blkw #1





.end
