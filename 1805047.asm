.model small
.stack 100h
.data
a1 DW 0
b1 DW 0
c1 DW 2 DUP(0)
t0 DW 0
t1 DW 0
t2 DW 0
t3 DW 0
t4 DW 0
t5 DW 0
t6 DW 0
t7 DW 0
t8 DW 0
t9 DW 0
t10 DW 0
t11 DW 0
t12 DW 0
t13 DW 0
t14 DW 0
t15 DW 0
t16 DW 0
t17 DW 0
t18 DW 0
t19 DW 0
t20 DW 0
t21 DW 0
t22 DW 0

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


;b = 5
mov ax, t2 
mov b1, ax


;2
mov t3, 2


;a = 2
mov ax, t3 
mov a1, ax


;a
mov ax, a1
mov t4, ax


;b
mov ax, b1
mov t5, ax


;a*b
mov ax, t4
mov bx, t5
mul bx
mov t4, ax

;a = a*b
mov ax, t4 
mov a1, ax


;a
mov ax, a1
mov t6, ax


;!a
cmp t6, 0
je L2
mov t6, 0
jmp L3
L2:
mov t6, 1
L3:

;a = !a
mov ax, t6 
mov a1, ax


;1
mov t7, 1


;c[1]
mov bx, t7
shl bx, 1
mov t8, bx


;a
mov ax, a1
mov t9, ax


;+a

;c[1] = +a
mov ax, t9 
mov bx, t8
mov c1[bx], ax


;1
mov t10, 1


;c[1]
mov bx, t10
shl bx, 1
mov t11, bx


;a
mov ax, a1
mov t12, ax


;-a
mov ax, t12
neg ax
mov t13, ax

;c[1] = -a
mov ax, t13 
mov bx, t11
mov c1[bx], ax


;0
mov t14, 0


;c[0]
mov bx, t14
shl bx, 1
mov t15, bx


;1
mov t16, 1


;c[1]
mov bx, t16
shl bx, 1
mov t17, bx


;c[1]
mov bx, t17
mov ax, c1[bx]
mov t18, ax


;c[0] = (c[1])
mov ax, t18 
mov bx, t15
mov c1[bx], ax


;a++
inc a1


;0
mov t19, 0


;c[0]
mov bx, t19
shl bx, 1
mov t20, bx


;c[0]++
mov bx, t20
inc c1[bx]


;a
mov ax, a1
mov t21, ax

push t21

;b
mov ax, b1
mov t22, ax

push t22

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp

end main