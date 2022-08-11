
.code


;int add function
add_procedure proc
push bp
mov bp, sp


;a
mov ax, [bp+6]
mov t0, ax


;return (a)
mov ax, t0


pop bp
ret 4
add_procedure endp


;add function ended



;int main function
main proc
mov ax, @data
mov ds,ax


;5
mov ax, 5
mov t1, ax


;a = 5
mov ax, t1 
mov a1, ax


;1
mov ax, 1
mov t2, ax


;c[1]
mov bx, t2
shl bx, 1
mov t3, bx


;a
mov ax, a1
mov t4, ax


;c[1] = a
mov ax, t4 
mov bx, t3
mov c1[bx], ax


;0
mov ax, 0
mov t5, ax


;c[0]
mov bx, t5
shl bx, 1
mov t6, bx


;1
mov ax, 1
mov t7, ax


;c[1]
mov bx, t7
shl bx, 1
mov t8, bx


;c[1]
mov bx, t8
mov ax, c1[bx]
mov t9, ax


;c[0] = (c[1])
mov ax, t9 
mov bx, t6
mov c1[bx], ax


;a++
inc a1


;0
mov ax, 0
mov t10, ax


;c[0]
mov bx, t10
shl bx, 1
mov t11, bx


;c[0]++
mov bx, t11
inc c1[bx]


;a
mov ax, a1
mov t12, ax

push t12

;b
mov ax, b1
mov t13, ax

push t13

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp


;main function ended


