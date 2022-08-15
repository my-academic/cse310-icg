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
t23 DW 0
t24 DW 0
t25 DW 0
t26 DW 0
t27 DW 0
t28 DW 0
t29 DW 0
t30 DW 0
t31 DW 0
t32 DW 0
t33 DW 0
t34 DW 0

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


;0
mov t2, 0


;c[0]
mov bx, t2
shl bx, 1
mov t3, bx


;5
mov t4, 5


;c[0] = 5
mov ax, t4 
mov bx, t3
mov c1[bx], ax


;19
mov t5, 19


;a = 19
mov ax, t5 
mov a1, ax


;a
mov ax, a1
mov t6, ax


;0
mov t7, 0


;c[0]
mov bx, t7
shl bx, 1
mov t8, bx


;c[0]
mov bx, t8
mov ax, c1[bx]
mov t9, ax


;a%c[0]
mov ax, t6
mov bx, t9
xor dx, dx
div bx
mov t6, dx

;a = a%c[0]
mov ax, t6 
mov a1, ax


;a
mov ax, a1
mov t10, ax


;0
mov t11, 0


;c[0]
mov bx, t11
shl bx, 1
mov t12, bx


;c[0]
mov bx, t12
mov ax, c1[bx]
mov t13, ax


;a/c[0]
mov ax, t10
mov bx, t13
xor dx, dx
div bx
mov t10, ax

;a = a/c[0]
mov ax, t10 
mov a1, ax


;a
mov ax, a1
mov t14, ax


;0
mov t15, 0


;c[0]
mov bx, t15
shl bx, 1
mov t16, bx


;c[0]
mov bx, t16
mov ax, c1[bx]
mov t17, ax


;a*c[0]
mov ax, t17
mov bx, t14
mul bx
mov t14, ax

;a = a*c[0]
mov ax, t14 
mov a1, ax


;a
mov ax, a1
mov t18, ax


;!a
cmp t18, 0
je L2
mov t18, 0
jmp L3
L2:
mov t18, 1
L3:

;a = !a
mov ax, t18 
mov a1, ax


;1
mov t19, 1


;c[1]
mov bx, t19
shl bx, 1
mov t20, bx


;a
mov ax, a1
mov t21, ax


;+a

;c[1] = +a
mov ax, t21 
mov bx, t20
mov c1[bx], ax


;1
mov t22, 1


;c[1]
mov bx, t22
shl bx, 1
mov t23, bx


;a
mov ax, a1
mov t24, ax


;-a
mov ax, t24
neg ax
mov t25, ax

;c[1] = -a
mov ax, t25 
mov bx, t23
mov c1[bx], ax


;0
mov t26, 0


;c[0]
mov bx, t26
shl bx, 1
mov t27, bx


;1
mov t28, 1


;c[1]
mov bx, t28
shl bx, 1
mov t29, bx


;c[1]
mov bx, t29
mov ax, c1[bx]
mov t30, ax


;c[0] = (c[1])
mov ax, t30 
mov bx, t27
mov c1[bx], ax


;a++
inc a1


;0
mov t31, 0


;c[0]
mov bx, t31
shl bx, 1
mov t32, bx


;c[0]++
mov bx, t32
inc c1[bx]


;a
mov ax, a1
mov t33, ax

push t33

;b
mov ax, b1
mov t34, ax

push t34

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp

end main