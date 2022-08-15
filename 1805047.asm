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
t35 DW 0
t36 DW 0
t37 DW 0
t38 DW 0
t39 DW 0
t40 DW 0
t41 DW 0
t42 DW 0
t43 DW 0
t44 DW 0
t45 DW 0
t46 DW 0

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


;a
mov ax, a1
mov t2, ax


;5
mov t3, 5


;a>=5
mov ax, t3
cmp t2, ax
jge L3
mov t2, 0
jmp L2
L3:
mov t2, 1
L2:

;a = a>=5
mov ax, t2 
mov a1, ax


;a
mov ax, a1
mov t4, ax


;5
mov t5, 5


;a<=5
mov ax, t5
cmp t4, ax
jle L5
mov t4, 0
jmp L4
L5:
mov t4, 1
L4:

;a = a<=5
mov ax, t4 
mov a1, ax


;0
mov t6, 0


;c[0]
mov bx, t6
shl bx, 1
mov t7, bx


;5
mov t8, 5


;c[0] = 5
mov ax, t8 
mov bx, t7
mov c1[bx], ax


;19
mov t9, 19


;a = 19
mov ax, t9 
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


;a+c[0]
mov ax, t13
add t10, ax

;a = a+c[0]
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


;a-c[0]
mov ax, t17
sub t14, ax

;a = a-c[0]
mov ax, t14 
mov a1, ax


;a
mov ax, a1
mov t18, ax


;0
mov t19, 0


;c[0]
mov bx, t19
shl bx, 1
mov t20, bx


;c[0]
mov bx, t20
mov ax, c1[bx]
mov t21, ax


;a%c[0]
mov ax, t18
mov bx, t21
xor dx, dx
div bx
mov t18, dx

;a = a%c[0]
mov ax, t18 
mov a1, ax


;a
mov ax, a1
mov t22, ax


;0
mov t23, 0


;c[0]
mov bx, t23
shl bx, 1
mov t24, bx


;c[0]
mov bx, t24
mov ax, c1[bx]
mov t25, ax


;a/c[0]
mov ax, t22
mov bx, t25
xor dx, dx
div bx
mov t22, ax

;a = a/c[0]
mov ax, t22 
mov a1, ax


;a
mov ax, a1
mov t26, ax


;0
mov t27, 0


;c[0]
mov bx, t27
shl bx, 1
mov t28, bx


;c[0]
mov bx, t28
mov ax, c1[bx]
mov t29, ax


;a*c[0]
mov ax, t29
mov bx, t26
mul bx
mov t26, ax

;a = a*c[0]
mov ax, t26 
mov a1, ax


;a
mov ax, a1
mov t30, ax


;!a
cmp t30, 0
je L6
mov t30, 0
jmp L7
L6:
mov t30, 1
L7:

;a = !a
mov ax, t30 
mov a1, ax


;1
mov t31, 1


;c[1]
mov bx, t31
shl bx, 1
mov t32, bx


;a
mov ax, a1
mov t33, ax


;+a

;c[1] = +a
mov ax, t33 
mov bx, t32
mov c1[bx], ax


;1
mov t34, 1


;c[1]
mov bx, t34
shl bx, 1
mov t35, bx


;a
mov ax, a1
mov t36, ax


;-a
mov ax, t36
neg ax
mov t37, ax

;c[1] = -a
mov ax, t37 
mov bx, t35
mov c1[bx], ax


;0
mov t38, 0


;c[0]
mov bx, t38
shl bx, 1
mov t39, bx


;1
mov t40, 1


;c[1]
mov bx, t40
shl bx, 1
mov t41, bx


;c[1]
mov bx, t41
mov ax, c1[bx]
mov t42, ax


;c[0] = (c[1])
mov ax, t42 
mov bx, t39
mov c1[bx], ax


;a++
inc a1


;0
mov t43, 0


;c[0]
mov bx, t43
shl bx, 1
mov t44, bx


;c[0]++
mov bx, t44
inc c1[bx]


;a
mov ax, a1
mov t45, ax

push t45

;b
mov ax, b1
mov t46, ax

push t46

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp

end main