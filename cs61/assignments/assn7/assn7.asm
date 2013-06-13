 ;=================================================
;
; Name: Wong, Chris
; Login id: wongc
;
; Assignment name: assn7
; Lab section: 23
; TA: wasim
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;=================================================
;MAIN TEST HARNESS
;=================================================
.orig x3000
;instructions
LD R0, data_ptr1
LD R6, input_sentence
JSRR R6

LD R1, data_ptr2
LD R6,find_longest_word
JSRR R6

ADD R4,R0,#0
LD R6,print_analysis
JSRR R6

HALT

;---------------
;DATA
;---------------
input_sentence .fill x3200
find_longest_word .fill x3400
print_analysis .fill x3600
data_ptr1 .fill x4000
data_ptr2 .fill x4200

;================================================
;SUBROUTINE:print_analysis
;arguments:
;           R1 <- address of the arrays of longest words
;           R3 <- size of largest word array
;           R4 <- address of the beginning of the array of words,
;return value: nothing
;================================================
.orig x3600

;backup
ST R0, backup_r0_print
ST R1, backup_r1_print
ST R2, backup_r2_print
ST R3, backup_r3_print
ST R4, backup_r4_print
ST R5, backup_r5_print
ST R6, backup_r6_print
ST R7, backup_r7_print
;-------------------------
; INSTRUCTIONS;
;-------------------------

;echo the input
LEA R0,print_message1d
PUTS
print_while_loop1
    LDR R0,R4,#0
    BRn end_print_while_loop1
    BRz print_while_loop1_0
    out
    ADD R4,R4,#1
    BR print_while_loop1

    ;check to see if needs to print a space
    print_while_loop1_0
        LD R0,print_32
        OUT
        ADD R4,R4,#1
        BR print_while_loop1
end_print_while_loop1

LEA R0,print_message1c
PUTS

;Print the longest words
LD R0,print_0
NOT R3,R3
ADD R3,R3,#1
LEA R0,print_message1
PUTS
print_longest_words

    LEA R0,print_message1a
    PUTS
    LDR R0,R1,#0
    PUTS
    LEA R0,print_message1b
    PUTS
    ;check to see if there are any more to print
    ADD R5,R5,#1
    ADD R6,R3,R5
    BRz end_print_longest_words
    ADD R1,R1,#1
    BR print_longest_words
end_print_longest_words

;restore&return
print_message1 .stringz "the longest word(s):\n "
print_message1a .stringz "\""
print_message1b .stringz "\", "
print_message1c .stringz "\n"
print_message1d .stringz "\nINPUTED WORDS: "
print_0 .fill #0
LD R0, backup_r0_print
LD R1, backup_r1_print
LD R2, backup_r2_print
LD R3, backup_r3_print
LD R4, backup_r4_print
LD R5, backup_r5_print
LD R6, backup_r6_print
LD R7, backup_r7_print
RET

;------------------
; DATA;
;------------------
backup_r0_print .blkw #1
backup_r1_print .blkw #1
backup_r2_print .blkw #1
backup_r3_print .blkw #1
backup_r4_print .blkw #1
backup_r5_print .blkw #1
backup_r6_print .blkw #1
backup_r7_print .blkw #1
print_32 .fill #32

;================================================
;SUBROUTINE:find_longest_word
;arguments: R0 <- address of sentence,
;           R1 <- address to store words,
;           R2 <- # of chars for longest word
;return value:R3 <- size of longes words array
;================================================
.orig x3400
;backup
ST R0, backup_r0_longest
ST R1, backup_r1_longest
ST R2, backup_r2_longest
ST R4, backup_r4_longest
ST R5, backup_r5_longest
ST R6, backup_r6_longest
ST R7, backup_r7_longest

;-------------------------
; INSTRUCTIONS; find_longest_word
;-------------------------
find_longest_word_START_MAIN

;R0 <- ptr to sentence array
;R1 <- ptr to long words array
;R2 <- # of chars for the longest word
;R3 <- data being read
;R4 <- temp count
;R5 <- temp ptr
;R6 <- temp junk

LD R4, longest_0
longest_while_loop1

    LDR R3,R0,#0
    ADD R0,R0,#1
    ADD R4,R4,#1

    ;Check if R3 == '-1'
    ADD R3,R3,#1
    BRz end_longest_while_loop1
    ADD R3,R3,#-1

    ;Check if R3 == '0'
    ADD R3,R3,#0
    BRz longest_found0

    ;Check if temp count == longest word
    NOT R4,R4
    ADD R4,R4,#1
    ADD R6,R4,R2
    BRz longest_foundword
    NOT R4,R4
    ADD R4,R4,#1
    BR longest_while_loop1

    ;if longestword is found,
    longest_foundword
        NOT R2,R2
        ADD R2,R2,#1

        ;store start of address into array#2
        ADD R5,R0,R2
        STR R5,R1,#0
        ADD R1,R1,#1
        NOT R2,R2
        ADD R2,R2,#1
        LD R4,longest_0
        LD R6,longest_size_of_array
        ADD R6,R6,#1
        ST R6,longest_size_of_array
        BR longest_while_loop1
    end_longest_foundword

    ;if 0 is found
    longest_found0
        LD R4,longest_0
        BR longest_while_loop1
    end_longest_found0

end_longest_while_loop1

LD R6, longest_size_of_array
ADD R3,R6,#0

;restore&return
LD R0, backup_r0_longest
LD R1, backup_r1_longest
LD R2, backup_r2_longest
LD R4, backup_r4_longest
LD R5, backup_r5_longest
LD R6, backup_r6_longest
LD R7, backup_r7_longest
RET

;------------------
; DATA;
;------------------
longest_0 .fill #0
longest_48 .fill #48
longest_n48 .fill #-48
longest_size_of_array .blkw #1
backup_r0_longest .blkw #1
backup_r1_longest .blkw #1
backup_r2_longest .blkw #1
backup_r4_longest .blkw #1
backup_r5_longest .blkw #1
backup_r6_longest .blkw #1
backup_r7_longest .blkw #1

;================================================
;SUBROUTINE:input_sentence
;arguments:R0 the address of where to store the address
;return value: R2, the # value of the longest word
;================================================
.orig x3200

;backup
ST R0, backup_r0_input
ST R1, backup_r1_input
ST R3, backup_r3_input
ST R4, backup_r4_input
ST R5, backup_r5_input
ST R6, backup_r6_input
ST R7, backup_r7_input
;-------------------------
; INSTRUCTIONS; input_sentence
;-------------------------
input_sentence_START_MAIN
;Display instructions
LD R2, input_0
LD R6, input_0
ADD R1, R0, #0
LEA R0, input_message1a
PUTS
LEA R0, input_message1b
PUTS
LEA R0, input_message1c
PUTS
;R0 <- user char input
;R1 <- data_ptr
;R2 <- largest word counter
;R3 <- total largest word #
;R4 <- temp
;R5 <- temp
;R6 <- flag,
input_while_loop1
    GETC
    OUT

    ;check to see if input is [enter]
    ADD R0,R0,#-10
    BRz end_input_while_loop1
    ADD R0,R0,#10

    ;check to see if input is [space]
    LD R5, input_n32
    ADD R0,R0,R5
    BRz input_store_zero
    LD R5, input_32
    ADD R0,R0,R5
    ADD R2,R2,#1
    BR input_loop_continued

    ;zero pad if input is [space], determine if largest string
    input_store_zero
        LD R0,input_0
        NOT R2,R2
        ADD R2,R2,#1
        ADD R4,R2,R3
        BRzp end_input_replace
        input_replace
            NOT R2,R2
            ADD R3,R2,#1
        end_input_replace
        LD R2,input_0
        ADD R6,R6,#0
        BRp input_end_continue          ;check flag
        BR input_loop_continued
    end_input_store_zero

    ;continue with logic; store data and increment ptr & counter
    input_loop_continued
    STR R0,R1,#0
    ADD R1,R1,#1
    BR input_while_loop1
end_input_while_loop1

;store final -1 at the end of input check and for greatest one last time,
ADD R6,R6,#1
BR input_store_zero
input_end_continue
LD R0, input_0
STR R0,R1,#0
LD R0, input_n1
STR R0,R1,#1
ADD R2,R3,#0

;restore&return
input_sentence_END_MAIN
LD R0, backup_r0_input
LD R1, backup_r1_input
LD R3, backup_r3_input
LD R4, backup_r4_input
LD R5, backup_r5_input
LD R6, backup_r6_input
LD R7, backup_r7_input
RET

;------------------
; DATA;
;------------------
backup_r0_input .blkw #1
backup_r1_input .blkw #1
backup_r3_input .blkw #1
backup_r4_input .blkw #1
backup_r5_input .blkw #1
backup_r6_input .blkw #1
backup_r7_input .blkw #1
input_n1 .fill #-1
input_0 .fill #0
input_n32 .fill #-32
input_32 .fill #32
input_48 .fill #48
input_message1a .stringz "Input a sentence, separated by [spaces],\n"
input_message1b .stringz "Press the [enter] button to continue,\n"
input_message1c .stringz "Ex,\"The quick brown fox \"\n  "

