.model small
.stack 100h
.data
MINUS DB ?
NUMBER_STRING DB '00000$'

;line 2: int main function

 
main proc 
push bp 
mov bp,  sp 
mov cx,  @data 
mov ds,  cx 
sub sp,  2 
sub sp,  2 

;line 4: 1

sub sp,  6 

;line 4: 2

push 1 

;line 4: 3

push 2 

;line 4: 2+3

mov bx,  3 

pop cx 
add cx,  bx 

;line 4: 1*(2+3)

mov ax,  cx 

pop bx 
mul bx 

;line 4: 3

push ax 

;line 4: 1*(2+3)%3

mov bx,  3 

pop ax 
xor dx,  dx 
div bx 

;line 4: a = 1*(2+3)%3

mov cx,  dx 

mov word ptr [bp-2],  cx 
mov ax,  cx 

;line 5: 1



;line 5: 5

push 1 

;line 5: 1<5

mov cx,  5 

pop bx 
cmp bx,  cx 
jl L1 
push 0 
jmp L0 
L1: 
push 1 

;line 5: b = 1<5

L0: 
pop cx 
mov word ptr [bp-4],  cx 
mov ax,  cx 

;line 6: 0



;line 6: c[0]

mov bx,  0 

shl bx,  1 

;line 6: 2

push bx 

;line 6: c[0] = 2

mov cx,  2 

pop bx 
push bp 
sub bx,  -6 
sub bp,  bx 
mov word ptr [bp],  cx 
pop bp 
mov ax,  cx 

;line 7: a



;line 7: b

push [bp-2] 

;line 7: a&&b

mov bx,  [bp-4] 

pop cx 
cmp cx,  0 
je L3 
cmp bx,  0 
je L3 
push 1 
jmp L2 
L3: 
push 0 
L2: 
pop cx 
cmp cx,  0 

;line 8: 0

je L4 

;line 8: c[0]

mov bx,  0 

shl bx,  1 

;line 8: c[0]++



push bp 
sub bx,  -6 
sub bp,  bx 
mov cx,  [bp] 
mov ax,  cx 
inc cx 
mov word ptr [bp],  cx 
pop bp 


jmp L5 

;line 10: 1

L4: 

;line 10: c[1]

mov bx,  1 

shl bx,  1 

;line 10: 0

push bx 

;line 10: c[0]

mov bx,  0 

shl bx,  1 

;line 10: c[0]



push bp 
sub bx,  -6 
sub bp,  bx 
mov cx,  [bp] 
pop bp 

;line 10: c[1] = c[0]


mov bx,  cx 

push bp 
sub bx,  -6 
sub bp,  bx 
mov word ptr [bp],  cx 
pop bp 
mov ax,  cx 


;line 11: println(a);

L5: 
mov ax,  [bp-2] 

;line 12: println(b);

call print_number 
mov ax,  [bp-4] 
call print_number 
add sp,  10 
add sp,  10 
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