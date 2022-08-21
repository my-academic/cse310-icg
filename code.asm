
.code


;line 1: int func function
func_procedure proc
push bp
mov bp, sp

sub sp, 2

;line 3: n
push [bp+4]

;line 3: 0
push 0

;line 3: n==0
        pop cx
        pop bx
        cmp bx, cx
        je L0
        push 0
        jmp L1
        L0:
        push 1
        L1:
pop cx
cmp cx, 0
je L2

;line 3: 0
push 0

;line 3: return 0
pop cx
jmp L3
L2:

;line 4: n
push [bp+4]

;line 4: i = n
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;line 5: n
push [bp+4]

;line 5: 1
push 1

;line 5: n-1
pop bx
pop cx
sub cx, bx
push cx

;line 5: func(n-1)
call func_procedure
push cx

;line 5: i
push [bp-2]

;line 5: func(n-1)+i
pop bx
pop cx
add cx, bx
push cx

;line 5: return func(n-1)+i
pop cx
jmp L4
add sp, 2
L3: 
L4: 
add sp, 2

pop bp
ret 2
func_procedure endp


;line 6: func function ended



;line 8: int func2 function
func2_procedure proc
push bp
mov bp, sp

sub sp, 2

;line 10: n
push [bp+4]

;line 10: 0
push 0

;line 10: n==0
        pop cx
        pop bx
        cmp bx, cx
        je L5
        push 0
        jmp L6
        L5:
        push 1
        L6:
pop cx
cmp cx, 0
je L7

;line 10: 0
push 0

;line 10: return 0
pop cx
jmp L8
L7:

;line 11: n
push [bp+4]

;line 11: i = n
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;line 12: n
push [bp+4]

;line 12: 1
push 1

;line 12: n-1
pop bx
pop cx
sub cx, bx
push cx

;line 12: func(n-1)
call func_procedure
push cx

;line 12: i
push [bp-2]

;line 12: func(n-1)+i
pop bx
pop cx
add cx, bx
push cx

;line 12: return func(n-1)+i
pop cx
jmp L9
add sp, 2
L8: 
L9: 
add sp, 2

pop bp
ret 2
func2_procedure endp


;line 13: func2 function ended



;line 15: int main function
main proc
push bp
mov bp, sp
mov cx, @data
mov ds,cx

sub sp, 2

;line 17: println(a);
mov ax, [bp-2]
call print_number

;line 18: 0
push 0

;line 18: return 0
pop cx
jmp L10
add sp, 2
L10: 
add sp, 2

mov ah, 4ch
int 21h
main endp

