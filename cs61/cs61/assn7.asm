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
;===============================
;MAIN function
;==============================


     LD R1,ptr                      ;load parameters for INPUT_SENTENCE 
     LD R6,SUB_INPUT_SENTENCE       ;load sub
     JSRR R6                        ;CALL INPUT_SENTENCE

     LD R2,ptr_longest              ;load parameters for FIND_LONGEST
     LD R6,SUB_FIND_LONGEST         ;load sub
     JSRR R6                        ;CALL FIND_LONGeST

     LD R6,SUB_PRINT_ANALYIST       ;load sub
     JSRR R6                        ;CALL PRINT_ANALYIST


HALT
;----------------
;Main data
;---------------
ptr .fill x4000
ptr_longest .fill x4200
SUB_INPUT_SENTENCE .fill x3400
SUB_FIND_LONGEST .fill x3600
SUB_PRINT_ANALYIST .fill x3800



;/////! Helper function for Input Sentence function ///////
;====================================================
;SUBROUTINE: SUB_GET_STRING
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
ST R6, gets_backup_r6
ST R7, gets_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
ADD R1,R0,#0                        ;copy pointer to R0
LD R5, gets_dec0                    ;set ocunter to 0

gets_While_loop1                    ;while userinput != [ENTER]
    GETC                            ;get input
    OUT                             ;echo
    ADD R0,R0,#-10                  ;check if enter
    BRz gets_While_loop1_end        ;if enter key, end while loop
    ADD R0,R0,#10                   ;convert back to ascii letter
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
LD R6, gets_backup_r6
LD R7, gets_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Get string
;------------------
gets_dec0 .fill #0
gets_backup_r0 .blkw #1
gets_backup_r1 .blkw #1
gets_backup_r4 .blkw #1
gets_backup_r6 .blkw #1
gets_backup_r7 .blkw #1


;====================================================
;SUBROUTINE: SUB_INPUT_SENTENCE
; Input (R1): The address of where to store the array of words 
; Postcondition: The subroutine has collected an ENTER‐terminated
;                string of words from the user and stored them in
;                consecutive memory locatoins,starting at (R1)
; Return Value: None
 .ORIG x3400
;=====================================================
;-------------------------
; INSTRUCTIONS; INPUT SENTENCE
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, insen_backup_r0
ST R1, insen_backup_r1
ST R5, insen_backup_r5
ST R6, insen_backup_r6
ST R7, insen_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform
LEA R0,insen_string1                    ;output introduction message
PUTS                                    ;output
ADD R0,R1,#0                            ;copy pointer into argument
 LD R6,insen_SUB_GET_STRING             ;load function into R6
insen_while1                            ;while( input != two enters
    JSRR R6                             ;call function
    ADD R5,R5,#0                        ;if string size = 0
    BRz insen_while1_end                 ;end loop
    ADD R0,R0,R5                        ;increment pointer
    ADD R0,R0,#1
    BR insen_while1
insen_while1_end
;(3)Restore all modified registers except Return Values
LD R0, insen_backup_r0
LD R1, insen_backup_r1
LD R5, insen_backup_r5
LD R6, insen_backup_r6
LD R7, insen_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA;INPUT SENTENCE
;------------------
insen_string1 .stringz "Enter words,press[ENTER] to input:\n"
insen_SUB_GET_STRING .fill x3200
insen_backup_r0 .blkw #1
insen_backup_r1 .blkw #1
insen_backup_r5 .blkw #1
insen_backup_r6 .blkw #1
insen_backup_r7 .blkw #1


;====================================================
;SUBROUTINE: FIND_LONGEST_WORD
;Input (R1): The address of the array of words
;      (R2): The address of the longest array of words
;Postcondition: the subroutine has located and the longest word(s)
;Return Value: none
 .ORIG x3600
;=====================================================
;-------------------------
; INSTRUCTIONS; Find Longest
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, findl_backup_r0
ST R1, findl_backup_r1
ST R2, findl_backup_r2
ST R3, findl_backup_r3
ST R4, findl_backup_r4
ST R5, findl_backup_r5
ST R6, findl_backup_r6
ST R7, findl_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;PASS 1, figure out what is the size of the longest words
;R0 <- value being read
;R1 <- array_ptr
;R2 <- temp counter
;R3 <- current max
;R4 <- temp/junk/trash
;R5 <- ptr to array of longest words
ADD R5,R2,#0
LD R2,findl_dec0
LD R3,findl_dec0
findl_while1                    ;while(ptr != NULL && ptr->next != NULL)
    LDR R0,R1,#0                ;load R0 with value at R1
    ;if data_ptr == NULL
    BRnp findl_while1_check1end  ;if R0 == NULL
        NOT R2,R2                   ;invert R2
        ADD R2,R2,#1                ;invert +1
        ADD R4,R2,R3                ;CHECK if R2 > R3
        BRp findl_while1_check2end  ;else skip this
            NOT R2,R2               ;return R2 to orginal Value
            ADD R2,R2,#1            ;return R2 to orginal Value
            ADD R3,R2,#0            ;R3 = R2
        findl_while1_check2end      ;terminate check2
        LDR R0,R1,#1                ;check R1->next
        BRz findl_while1_end        ;end if R1->next == NULL
        LDR R0,R1,#0                ;revert R0 back to orginal value
        LD R2,findl_dec0            ;reset temp counter
        ADD R1,R1,#1                ;increment pointer
        BR findl_while1             ;repeat loop
    findl_while1_check1end       ;end terminate check
    ;else
    ADD R2,R2,#1                ;increment counter
    ADD R1,R1,#1                ;increment pointer
    BR findl_while1             ;repeat loop
findl_while1_end

;PASS 2, figure out which address(es) to return
LD R1, findl_backup_r1          ;reload R1 with the ptr to the start of array
LD R2, findl_dec0               ;set temp counter to 0
NOT R3,R3                       ;inverting R3 to neg
ADD R3,R3,#1                    ;inverting R3 to neg
findl_while2
    LDR R0,R1,#0                ;load r0 with value at R1
    ;if data_ptr == NULL
    BRnp findl_while2_check1end     ;if R0 == NULL
        ADD R4,R2,R3                ;check if R2 = R3
        BRnp findl_while2_check2end ;if R2 == R3
            ADD R4,R1,R3             ;set R4 to the start of that string
            STR R4,R5,#0             ;Store R4 into the ptr at R5(longest array)
            ADD R5,R5,#1             ;increment R5 ptr
        findl_while2_check2end
        LD R2,findl_dec0            ;reset temp counter
        LDR R0,R1,#1                ;check ptr->next
        BRz findl_while2_end        ;if ptr->next == NULL end
        ADD R1,R1,#1                ;increment ptr
        BR findl_while2             ;repeat loop
    findl_while2_check1end
    ;else,
    ADD R2,R2,#1                    ;increment temp counter
    ADD R1,R1,#1                    ;increment start array ptrd
    BR findl_while2
findl_while2_end
LD R0,findl_dec0         ;load null terminating character
STR R0,R5,#1             ;store R0 into R5
;(3)Restore all modified registers except Return Values
LD R0, findl_backup_r0
LD R1, findl_backup_r1
LD R2, findl_backup_r2
LD R3, findl_backup_r3
LD R4, findl_backup_r4
LD R5, findl_backup_r5
LD R6, findl_backup_r6
LD R7, findl_backup_r7

;(4)Return to where you came from
RET

;------------------
; DATA; Find longest
;------------------
findl_dec0 .fill #0
findl_backup_r0 .blkw #1
findl_backup_r1 .blkw #1
findl_backup_r2 .blkw #1
findl_backup_r3 .blkw #1
findl_backup_r4 .blkw #1
findl_backup_r5 .blkw #1
findl_backup_r6 .blkw #1
findl_backup_r7 .blkw #1

;====================================================
;SUBROUTINE: PRINT_ANALYSIS
;Input (R1) The address of the begining ofthe array of words
;      (R2): The addres of the longest word
;Postcondition: the subroutine has printed out a list of all the words entered
;               as well as the longest word in the sentence
;Return Value: none
 .ORIG x3800
;=====================================================
;-------------------------
; INSTRUCTIONS; Print analysis
;-------------------------
;(1)Backup all modified registers except Return Value
ST R0, anal_backup_r0
ST R1, anal_backup_r1
ST R2, anal_backup_r2
ST R3, anal_backup_r3
ST R4, anal_backup_r4
ST R5, anal_backup_r5
ST R6, anal_backup_r6
ST R7, anal_backup_r7
;(2)Perform whatever algorithm(s) this subroutine is suppose to perform

;PART1 print out all words
LEA R0,anal_string1                 ;load string1
PUTS                                ;output
anal_while1
    LDR R0,R1,#0                    ;load data at R1
    ;if ptr == NULL
    BRnp anal_while1_check1end
        LDR R0,R1,#1
        BRnp anal_while1_check2end       ;if ptr->next == NULL
            BR anal_while1end           ;terminate loop
            anal_while1_check2end
        LD R0,anal_ascii_c              ;load comma
        OUT                             ;output "," to screen
        ADD R1,R1,#1                    ;increment ptr
        BR anal_while1                  ;repeat loop
    anal_while1_check1end
    ;else
    OUT                             ;output chracter
    ADD R1,R1,#1                    ;increment ptr
    BR anal_while1                  ;repeat looop
anal_while1end

;PART2 print out longest words
LEA R0,anal_string2                 ;load string2
PUTS                                ;output
anal_while2a
    LDR R3,R2,#0                    ;load address at R3
    anal_while2b
    LDR R0,R3,#0
    ;if ptr == NULL
    BRnp anal_while2_check1end
        LDR R0,R2,#1
        BRnp anal_while2_check2end       ;if ptr->next == NULL
            BR anal_while2end           ;terminate loop
            anal_while2_check2end
        LD R0,anal_ascii_c              ;load comma
        OUT                             ;output "," to screen
        ADD R2,R2,#1                    ;increment ptr
        BR anal_while2a                  ;repeat loop
    anal_while2_check1end
    ;else
    OUT                             ;output chracter
    ADD R3,R3,#1                    ;increment ptr
    BR anal_while2b                  ;repeat looop
anal_while2end
LEA R0,anal_string3                 ;load string3
PUTS                                ;output
;(3)Restore all modified registers except Return Values
LD R0, anal_backup_r0
LD R1, anal_backup_r1
LD R2, anal_backup_r2
LD R3, anal_backup_r3
LD R4, anal_backup_r4
LD R5, anal_backup_r5
LD R6, anal_backup_r6
LD R7, anal_backup_r7
;(4)Return to where you came from
RET
;------------------
; DATA; Print anaylsis
;------------------
anal_string1 .stringz "The words in the sentence includes:\n{"
anal_string2 .stringz "}\nThe longest word(s) include:\n{"
anal_string3 .stringz "}"
anal_ascii_p .fill #32
anal_ascii_c .fill #44
anal_backup_r0 .blkw #1
anal_backup_r1 .blkw #1
anal_backup_r2 .blkw #1
anal_backup_r3 .blkw #1
anal_backup_r4 .blkw #1
anal_backup_r5 .blkw #1
anal_backup_r6 .blkw #1
anal_backup_r7 .blkw #1





.end
