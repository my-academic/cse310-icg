
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


;2
push 2

;a = 2
pop ax
mov a1_3, ax

push ax
pop cx

;2
push 2

;a = 2
pop ax
mov a1_3_1, ax

push ax
pop cx

;2
push 2

;b = 2
pop ax
mov b1_3, ax

push ax
pop cx

;4
push 4

;c[4]
pop bx
shl bx, 1
push bx


;6
push 6

;c[4] = 6
pop ax
pop bx
mov c1_3[bx], ax

push ax
pop cx

;4
push 4

;c[4]
pop bx
shl bx, 1
push bx


;c[4]
pop bx
push c1_3[bx]

;a = c[4]
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
jmp L2
L2: 

mov ah, 4ch
int 21h
main endp

