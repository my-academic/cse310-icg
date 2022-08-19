.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'
x1_2 DW 0
a1_3 DW 0
b1_3 DW 0

.code


;int f function
f_procedure proc
push bp
mov bp, sp


;2
push 2

;a
push [bp+4]

;2*a
        pop ax
        pop bx
        mul bx
push ax

;return 2*a
pop ax
jmp L0

;9
push 9

;a = 9
pop ax
mov [bp+4], ax

push ax
pop cx
L0: 

pop bp
ret 2
f_procedure endp


;f function ended



;int g function
g_procedure proc
push bp
mov bp, sp


;a
push [bp+6]

;f(a)
call f_procedure
push ax

;a
push [bp+6]

;f(a)+a
pop bx
pop ax
add ax, bx
push ax

;b
push [bp+4]

;f(a)+a+b
pop bx
pop ax
add ax, bx
push ax

;x = f(a)+a+b
pop ax
mov x1_2, ax

push ax
pop cx

;x
push x1_2

;return x
pop ax
jmp L1
L1: 

pop bp
ret 4
g_procedure endp


;g function ended



;int main function
main proc
mov ax, @data
mov ds,ax


;1
push 1

;2                                                                                                                                                           
push 2

;1||2
        pop bx
        pop ax
        cmp ax, 0
        jne L3
        cmp bx, 0
        jne L3
        push 0
        jmp L2
        L3:
        push 1
        L2:

;a = 1||2
pop ax
mov a1_3, ax

push ax
pop cx

;2
push 2

;0
push 0

;2&&0
        pop bx
        pop ax
        cmp ax, 0
        je L5
        cmp bx, 0
        je L5
        push 1
        jmp L4
        L5:
        push 0
        L4:

;a = 2&&0
pop ax
mov a1_3, ax

push ax
pop cx

;2
push 2

;b = 2
pop ax
mov b1_3, ax

push ax
pop cx

;a
push a1_3

;b
push b1_3

;g(a,b)
call g_procedure
push ax

;a = g(a,b)
pop ax
mov a1_3, ax

push ax
pop cx

;println(a);
mov ax, a1_3
call print_number

;0
push 0

;return 0
pop ax
jmp L6
L6: 

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