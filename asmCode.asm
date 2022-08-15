
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


;a+c[0]
mov ax, t9
add t6, ax

;a = a+c[0]
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


;a-c[0]
mov ax, t13
sub t10, ax

;a = a-c[0]
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


;a%c[0]
mov ax, t14
mov bx, t17
xor dx, dx
div bx
mov t14, dx

;a = a%c[0]
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


;a/c[0]
mov ax, t18
mov bx, t21
xor dx, dx
div bx
mov t18, ax

;a = a/c[0]
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


;a*c[0]
mov ax, t25
mov bx, t22
mul bx
mov t22, ax

;a = a*c[0]
mov ax, t22 
mov a1, ax


;a
mov ax, a1
mov t26, ax


;!a
cmp t26, 0
je L2
mov t26, 0
jmp L3
L2:
mov t26, 1
L3:

;a = !a
mov ax, t26 
mov a1, ax


;1
mov t27, 1


;c[1]
mov bx, t27
shl bx, 1
mov t28, bx


;a
mov ax, a1
mov t29, ax


;+a

;c[1] = +a
mov ax, t29 
mov bx, t28
mov c1[bx], ax


;1
mov t30, 1


;c[1]
mov bx, t30
shl bx, 1
mov t31, bx


;a
mov ax, a1
mov t32, ax


;-a
mov ax, t32
neg ax
mov t33, ax

;c[1] = -a
mov ax, t33 
mov bx, t31
mov c1[bx], ax


;0
mov t34, 0


;c[0]
mov bx, t34
shl bx, 1
mov t35, bx


;1
mov t36, 1


;c[1]
mov bx, t36
shl bx, 1
mov t37, bx


;c[1]
mov bx, t37
mov ax, c1[bx]
mov t38, ax


;c[0] = (c[1])
mov ax, t38 
mov bx, t35
mov c1[bx], ax


;a++
inc a1


;0
mov t39, 0


;c[0]
mov bx, t39
shl bx, 1
mov t40, bx


;c[0]++
mov bx, t40
inc c1[bx]


;a
mov ax, a1
mov t41, ax

push t41

;b
mov ax, b1
mov t42, ax

push t42

;add(a,b)
call add_procedure

mov ah, 4ch
int 21h
main endp

