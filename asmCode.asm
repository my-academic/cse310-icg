
.code


;int func function
func_procedure proc
push bp
mov bp, sp

sub sp, 2

;n
push [bp+4]

;0
push 0

;n==0
        pop cx
        pop bx
        cmp bx, cx
        je L1
        push 0
        jmp L0
        L1:
        push 1
        L0:
pop cx
cmp cx, 0
je L2

;0
push 0

;return 0
pop cx
jmp L3
L2:

;n
push [bp+4]

;i = n
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;n
push [bp+4]

;1
push 1

;n-1
pop bx
pop cx
sub cx, bx
push cx

;func(n-1)
call func_procedure
push cx

;i
push [bp-2]

;func(n-1)+i
pop bx
pop cx
add cx, bx
push cx

;return func(n-1)+i
pop cx
jmp L4
add sp, 2
L3: 
add sp, 2
L4: 
add sp, 2

pop bp
ret 2
func_procedure endp


;func function ended



;int func2 function
func2_procedure proc
push bp
mov bp, sp

sub sp, 2

;n
push [bp+4]

;0
push 0

;n==0
        pop cx
        pop bx
        cmp bx, cx
        je L6
        push 0
        jmp L5
        L6:
        push 1
        L5:
pop cx
cmp cx, 0
je L7

;0
push 0

;return 0
pop cx
jmp L8
L7:

;n
push [bp+4]

;i = n
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;n
push [bp+4]

;1
push 1

;n-1
pop bx
pop cx
sub cx, bx
push cx

;func(n-1)
call func_procedure
push cx

;i
push [bp-2]

;func(n-1)+i
pop bx
pop cx
add cx, bx
push cx

;return func(n-1)+i
pop cx
jmp L9
add sp, 2
L8: 
add sp, 2
L9: 
add sp, 2

pop bp
ret 2
func2_procedure endp


;func2 function ended



;int main function
main proc
push bp
mov bp, sp
mov cx, @data
mov ds,cx

sub sp, 2

;7
push 7

;func(7)
call func_procedure
push cx

;a = func(7)
pop cx
mov word ptr [bp-2], cx
push cx
pop ax

;println(a);
mov ax, [bp-2]
call print_number

;0
push 0

;return 0
pop cx
jmp L10
add sp, 2
L10: 
add sp, 2

mov ah, 4ch
int 21h
main endp

