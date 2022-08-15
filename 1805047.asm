.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'
i1_1 DW 0
j1_1 DW 0
k1_1 DW 0
ll1_1 DW 0
m1_1 DW 0
n1_1 DW 0
o1_1 DW 0
p1_1 DW 0
t0 DW 0
t1 DW 0
t2 DW 0
t3 DW 0
t4 DW 0

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


;999
mov t1, 999


;j = 999
mov ax, t1 
mov j1_1, ax


;i
mov ax, i1_1
mov t2, ax


;3
mov t3, 3


;i==3
        mov ax, t3
        cmp t2, ax
        je L1
        mov t2, 0
        jmp L0
        L1:
        mov t2, 1
        L0:
cmp t2, 0
je L2

;println(j);
mov ax, j1_1
call print_number
L2:

;0
mov t4, 0


;return 0
mov ax, t4


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