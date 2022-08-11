
.code


;int add function
add_procedure proc
push bp
mov bp, sp


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
mov t0, ax


;a = 5
mov ax, t0 
mov a1, ax


;1
mov ax, 1
mov t1, ax


;c[1]
mov bx, t1
shl bx, 1
mov t2, bx


;a
mov ax, a1
mov t3, ax


;c[1] = a
mov ax, t3 
mov bx, t2
mov c1[bx], ax


;0
mov ax, 0
mov t4, ax


;c[0]
mov bx, t4
shl bx, 1
mov t5, bx


;1
mov ax, 1
mov t6, ax


;c[1]
mov bx, t6
shl bx, 1
mov t7, bx


;c[1]
mov bx, t7
mov ax, c1[bx]
mov t8, ax


;c[0] = (c[1])
mov ax, t8 
mov bx, t5
mov c1[bx], ax


;a++
inc a1


;0
mov ax, 0
mov t9, ax


;c[0]
mov bx, t9
shl bx, 1
mov t10, bx


;c[0]++
mov bx, t10
inc c1[bx]


mov ah, 4ch
int 21h
main endp


;main function ended


