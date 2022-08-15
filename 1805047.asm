.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'
i1_1 DW 0
j1_1 DW 0
k1_1 DW 0
t0 DW 0
t1 DW 0
t2 DW 0
t3 DW 0
t4 DW 0
t5 DW 0
t6 DW 0
t7 DW 0
t8 DW 0
t9 DW 0
t10 DW 0
t11 DW 0
t12 DW 0
t13 DW 0
t14 DW 0

.code


;int main function
main proc
mov ax, @data
mov ds,ax


;3
mov t0, 3


;i = 3
mov ax, t0 
mov i1_1, ax


;8
mov t1, 8


;j = 8
mov ax, t1 
mov j1_1, ax


;6
mov t2, 6


;k = 6
mov ax, t2 
mov k1_1, ax


;i
mov ax, i1_1
mov t3, ax


;3
mov t4, 3


;i==3
        mov ax, t4
        cmp t3, ax
        je L1
        mov t3, 0
        jmp L0
        L1:
        mov t3, 1
        L0:
cmp t3, 0
je L2

;println(j);
mov ax, j1_1
call print_number
L2:

;j
mov ax, j1_1
mov t5, ax


;8
mov t6, 8


;j<8
        mov ax, t6
        cmp t5, ax
        jl L4
        mov t5, 0
        jmp L3
        L4:
        mov t5, 1
        L3:
cmp t5, 0
je L5

;println(i);
mov ax, i1_1
call print_number
jmp L6
L5:

;println(k);
mov ax, k1_1
call print_number
L6:

;k
mov ax, k1_1
mov t7, ax


;6
mov t8, 6


;k!=6
        mov ax, t8
        cmp t7, ax
        jne L8
        mov t7, 0
        jmp L7
        L8:
        mov t7, 1
        L7:
cmp t7, 0
je L9

;println(k);
mov ax, k1_1
call print_number
jmp L10
L9:

;j
mov ax, j1_1
mov t9, ax


;8
mov t10, 8


;j>8
        mov ax, t10
        cmp t9, ax
        jg L12
        mov t9, 0
        jmp L11
        L12:
        mov t9, 1
        L11:
cmp t9, 0
je L13

;println(j);
mov ax, j1_1
call print_number
jmp L14
L13:

;i
mov ax, i1_1
mov t11, ax


;5
mov t12, 5


;i<5
        mov ax, t12
        cmp t11, ax
        jl L16
        mov t11, 0
        jmp L15
        L16:
        mov t11, 1
        L15:
cmp t11, 0
je L17

;println(i);
mov ax, i1_1
call print_number
jmp L18
L17:

;0
mov t13, 0


;k = 0
mov ax, t13 
mov k1_1, ax


;println(k);
mov ax, k1_1
call print_number
L18:
L14:
L10:

;0
mov t14, 0


;return 0
mov ax, t14


mov ah, 4ch
int 21h
main endp

PRINT_CHARACTER PROC
    
    ; PRINT VALUE IN DL
    MOV AH, 2
    INT 21H
    RET   
    
    
PRINT_CHARACTER ENDP  

PRINT_NEW_LINE PROC
    MOV AH, 2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H
    RET
PRINT_NEW_LINE ENDP  

PRINT_NUMBER PROC  
    
    ;PRINT VALUE IN AX 
    
    LEA SI, NUMBER_STRING    
    MOV CX, 5
    RESET_NUMBER_STRING:    
    MOV [SI], '0'
    INC SI
    LOOP RESET_NUMBER_STRING    
    
    DEC SI
    CMP AX, 0
    JE PRINT_NUMBER_N0T_MINUS
          
    MOV MINUS, 0
    CMP AX, 0
    JGE PRINT_NUMBER_LOOP1
    NEG AX
    MOV MINUS, 1
    PRINT_NUMBER_LOOP1: 
    XOR DX, DX 
    
                
    CMP AX, 0
    JE END_PRINT_NUMBER_LOOP1
    
    MOV BX, 10
    
    DIV BX
    ADD DL, '0'
    MOV [SI], DL   
    
    DEC SI  
    
    LOOP PRINT_NUMBER_LOOP1  
    END_PRINT_NUMBER_LOOP1:   
    
    INC SI
    
    MOV DH, MINUS
    CMP DH, 0
    JE PRINT_NUMBER_N0T_MINUS
    MOV DL, '-'
    CALL PRINT_CHARACTER
    
    PRINT_NUMBER_N0T_MINUS:
    MOV DX, SI
    CALL PRINT_STRING  
    CALL PRINT_NEW_LINE
    
    RET
PRINT_NUMBER ENDP 

PRINT_STRING PROC 
    ;PRINT VALUE IN DX
    MOV AH, 9
    INT 21H
    RET   
PRINT_STRING ENDP  

END MAIN 