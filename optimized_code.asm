
 
.code
 

 

 
func_procedure proc
 
push bp
 
mov bp,  sp
 

 
sub sp,  2
 

 
push [bp+4]
 

 
push 0
 

 
pop cx
 
pop bx
 
cmp bx,  cx
 
je L0
 
push 0
 
jmp L1
 
L0:
 
push 1
 
L1:
 
pop cx
 
cmp cx,  0
 
je L2
 

 
push 0
 

 
pop cx
 
jmp L3
 
L2:
 

 
push [bp+4]
 

 
pop cx
 
mov word ptr [bp-2],  cx
 
push cx
 
pop ax
 

 
push [bp+4]
 

 
push 1
 

 
pop bx
 
pop cx
 
sub cx,  bx
 
push cx
 

 
call func_procedure
 
push cx
 

 
push [bp-2]
 

 
pop bx
 
pop cx
 
add cx,  bx
 
push cx
 

 
pop cx
 
jmp L4
 
add sp,  2
 
L3: 
 
L4: 
 
add sp,  2
 

 
pop bp
 
ret 2
 
func_procedure endp
 

 

 

 

 

 
func2_procedure proc
 
push bp
 
mov bp,  sp
 

 
sub sp,  2
 

 
push [bp+4]
 

 
push 0
 

 
pop cx
 
pop bx
 
cmp bx,  cx
 
je L5
 
push 0
 
jmp L6
 
L5:
 
push 1
 
L6:
 
pop cx
 
cmp cx,  0
 
je L7
 

 
push 0
 

 
pop cx
 
jmp L8
 
L7:
 

 
push [bp+4]
 

 
pop cx
 
mov word ptr [bp-2],  cx
 
push cx
 
pop ax
 

 
push [bp+4]
 

 
push 1
 

 
pop bx
 
pop cx
 
sub cx,  bx
 
push cx
 

 
call func_procedure
 
push cx
 

 
push [bp-2]
 

 
pop bx
 
pop cx
 
add cx,  bx
 
push cx
 

 
pop cx
 
jmp L9
 
add sp,  2
 
L8: 
 
L9: 
 
add sp,  2
 

 
pop bp
 
ret 2
 
func2_procedure endp
 

 

 

 

 

 
main proc
 
push bp
 
mov bp,  sp
 
mov cx,  @data
 
mov ds,cx
 

 
sub sp,  2
 

 
mov ax,  [bp-2]
 
call print_number
 

 
push 0
 

 
pop cx
 
jmp L10
 
add sp,  2
 
L10: 
 
add sp,  2
 

 
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