
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


;0
mov t1, 0


;!0
cmp t1, 0
je L0
mov t1, 0
jmp L1
L0:
mov t1, 1
L1:

;a = !0
mov ax, t1 
mov a1, ax


;5
mov t2, 5


;a = 5
mov ax, t2 
mov a1, ax


;a
mov ax, a1
mov t3, ax


;!a
cmp t3, 0
je L2
mov t3, 0
jmp L3
L2:
mov t3, 1
L3:

;a = !a
mov ax, t3 
mov a1, ax


;1
mov t4, 1


;c[1]
mov bx, t4
shl bx, 1
mov t5, bx


;a
mov ax, a1
mov t6, ax


;+a

;c[1] = +a
mov ax, t6 
mov bx, t5
mov c1[bx], ax


;1
mov t7, 1


;c[1]
mov bx, t7
shl bx, 1
mov t8, bx


;a
mov ax, a1
mov t9, ax


;-a
mov ax, t9
neg ax
mov t10, ax

;c[1] = -a
mov ax, t10 
mov bx, t8
mov c1[bx], ax


;0
mov t11, 0


;c[0]
mov bx, t11
shl bx, 1
mov t12, bx


;1
mov t13, 1


;c[1]
mov bx, t13
shl bx, 1
mov t14, bx


;c[1]
mov bx, t14
mov ax, c1[bx]
mov t15, ax


;c[0] = (c[1])
mov ax, t15 
mov bx, t12
mov c1[bx], ax


;a++
inc a1


;0
mov t16, 0


;c[0]
mov bx, t16
shl bx, 1
mov t17, bx


;c[0]++
mov bx, t17
inc c1[bx]


;a
mov ax, a1
mov t18, ax

push t18

;b
mov ax, b1
mov t19, ax

push t19

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp


;main function ended


