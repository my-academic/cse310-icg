
.code


;int main function
main proc
push bp
mov bp, sp
mov ax, @data
mov ds,ax

sub sp, 2
sub sp, 2
sub sp, 6

;1
push 1

;2
push 2

;3
push 3

;2+3
pop bx
pop ax
add ax, bx
push ax

;1*(2+3)
        pop ax
        pop bx
        mul bx
push ax

;3
push 3

;1*(2+3)%3
        pop bx
        pop ax
        xor dx, dx
        div bx
push dx

;a = 1*(2+3)%3
pop ax
mov word ptr [bp-2], ax
push ax
pop cx

;1
push 1

;5
push 5

;1<5
        pop ax
        pop bx
        cmp bx, ax
        jl L1
        push 0
        jmp L0
        L1:
        push 1
        L0:

;b = 1<5
pop ax
mov word ptr [bp-4], ax
push ax
pop cx

;0
push 0

;c[0]
pop bx
shl bx, 1
push bx


;2
push 2

;c[0] = 2
pop ax
mov word ptr c[0], ax
push ax
pop cx

;a
push [bp-2]

;b
push [bp-4]

;a&&b
        pop bx
        pop ax
        cmp ax, 0
        je L3
        cmp bx, 0
        je L3
        push 1
        jmp L2
        L3:
        push 0
        L2:
pop ax
cmp ax, 0
je L4

;0
push 0

;c[0]
pop bx
shl bx, 1
push bx


;c[0]++
push c[0]++
mov ax, c[0]++
inc ax
 mov word ptr c[0]++, ax
pop cx
jmp L5
L4:

;1
push 1

;c[1]
pop bx
shl bx, 1
push bx


;0
push 0

;c[0]
pop bx
shl bx, 1
push bx


;c[0]
push c[0]

;c[1] = c[0]
pop ax
mov word ptr c[1], ax
push ax
pop cx
L5:

;println(a);
mov ax, [bp-2]
call print_number

;println(b);
mov ax, [bp-4]
call print_number
add sp, 10

mov ah, 4ch
int 21h
main endp

