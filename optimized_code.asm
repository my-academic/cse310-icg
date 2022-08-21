.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'

;line 1: int foo function

 
foo_procedure proc 
push bp 

;line 2: a

mov bp,  sp 

;line 2: b

push [bp+6] 

;line 2: a+b

mov bx,  [bp+4] 

pop cx 
add cx,  bx 

;line 2: 5

push cx 

;line 2: a+b<=5

mov cx,  5 

pop bx 
cmp bx,  cx 
jle L1 
push 0 
jmp L0 
L1: 
push 1 
L0: 
pop cx 
cmp cx,  0 

;line 3: 7

je L2 

;line 3: return 7

mov cx,  7 

jmp L3 


;line 5: a

L2: 

;line 5: 2

push [bp+6] 

;line 5: a-2

mov bx,  2 

pop cx 
sub cx,  bx 

;line 5: b

push cx 

;line 5: 1

push [bp+4] 

;line 5: b-1

mov bx,  1 

pop cx 
sub cx,  bx 

;line 5: foo(a-2,b-1)

push cx 
call foo_procedure 

;line 5: 2

push cx 

;line 5: a

push 2 

;line 5: 1

push [bp+6] 

;line 5: a-1

mov bx,  1 

pop cx 
sub cx,  bx 

;line 5: b

push cx 

;line 5: 2

push [bp+4] 

;line 5: b-2

mov bx,  2 

pop cx 
sub cx,  bx 

;line 5: foo(a-1,b-2)

push cx 
call foo_procedure 

;line 5: 2*foo(a-1,b-2)

mov ax,  cx 

pop bx 
mul bx 

;line 5: foo(a-2,b-1)+2*foo(a-1,b-2)

mov bx,  ax 

pop cx 
add cx,  bx 

;line 5: return foo(a-2,b-1)+2*foo(a-1,b-2)



jmp L4 

L3: 
L4: 

pop bp 
ret 4 

;line 6: foo function ended


;line 9: int main function

foo_procedure endp 
main proc 
push bp 
mov bp,  sp 
mov cx,  @data 
mov ds,  cx 
sub sp,  2 
sub sp,  2 

;line 11: 7

sub sp,  2 

;line 11: i = 7

mov cx,  7 

mov word ptr [bp-2],  cx 
mov ax,  cx 

;line 12: 3



;line 12: j = 3

mov cx,  3 

mov word ptr [bp-4],  cx 
mov ax,  cx 

;line 14: i



;line 14: j

push [bp-2] 

;line 14: foo(i,j)

push [bp-4] 
call foo_procedure 

;line 14: k = foo(i,j)



mov word ptr [bp-6],  cx 
mov ax,  cx 

;line 15: println(k);


mov ax,  [bp-6] 

;line 17: 0

call print_number 

;line 17: return 0

mov cx,  0 

jmp L5 
add sp,  6 
L5: 
add sp,  6 
mov ah,  4ch 
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