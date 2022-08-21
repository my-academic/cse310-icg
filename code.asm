.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'

.code


;line 1: int foo function
foo_procedure proc
push bp
mov bp, sp


;line 2: a
push [bp+6]

;line 2: b
push [bp+4]

;line 2: a+b
pop bx
pop cx
add cx, bx
push cx

;line 2: 5
push 5

;line 2: a+b<=5
        pop cx
        pop bx
        cmp bx, cx
        jle L1
        push 0
        jmp L0
        L1:
        push 1
        L0:
pop cx
cmp cx, 0
je L2

;line 3: 7
push 7

;line 3: return 7
pop cx
jmp L3
add sp, 0
L2:

;line 5: a
push [bp+6]

;line 5: 2
push 2

;line 5: a-2
pop bx
pop cx
sub cx, bx
push cx

;line 5: b
push [bp+4]

;line 5: 1
push 1

;line 5: b-1
pop bx
pop cx
sub cx, bx
push cx

;line 5: foo(a-2,b-1)
call foo_procedure
push cx

;line 5: 2
push 2

;line 5: a
push [bp+6]

;line 5: 1
push 1

;line 5: a-1
pop bx
pop cx
sub cx, bx
push cx

;line 5: b
push [bp+4]

;line 5: 2
push 2

;line 5: b-2
pop bx
pop cx
sub cx, bx
push cx

;line 5: foo(a-1,b-2)
call foo_procedure
push cx

;line 5: 2*foo(a-1,b-2)
        pop ax
        pop bx
        mul bx
push ax

;line 5: foo(a-2,b-1)+2*foo(a-1,b-2)
pop bx
pop cx
add cx, bx
push cx

;line 5: return foo(a-2,b-1)+2*foo(a-1,b-2)
pop cx
jmp L4
add sp, 0
L3: 
L4: 
add sp, 0

pop bp
ret 4
foo_procedure endp


;line 6: foo function ended



;line 9: int main function
main proc
push bp
mov bp, sp
mov cx, @data
mov ds, cx

sub sp, 2
sub sp, 2
sub sp, 2

;line 11: 7
push 7

;line 11: i = 7
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;line 12: 3
push 3

;line 12: j = 3
pop cx
mov word ptr [bp-4], cx
push cx
pop ax

;line 14: i
push [bp-2]

;line 14: j
push [bp-4]

;line 14: foo(i,j)
call foo_procedure
push cx

;line 14: k = foo(i,j)
pop cx
mov word ptr [bp-6], cx
push cx
pop ax

;line 15: println(k);
mov ax, [bp-6]
call print_number

;line 17: 0
push 0

;line 17: return 0
pop cx
jmp L5
add sp, 6
L5: 
add sp, 6

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