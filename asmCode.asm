
.code


;int func function
func_procedure proc
push bp
mov bp, sp


;n
mov ax, [bp+4]
mov t0, ax


;0
mov t1, 0


;n==0
        mov ax, t1
        cmp t0, ax
        je L1
        mov t0, 0
        jmp L0
        L1:
        mov t0, 1
        L0:
cmp t0, 0
je L2

;0
mov t2, 0


;return 0
mov ax, t2
jmp L3
L2:

;n
mov ax, [bp+4]
mov t3, ax


;i = n
mov ax, t3 
mov i1_1, ax


;n
mov ax, [bp+4]
mov t4, ax


;1
mov t5, 1


;n-1
mov ax, t5
sub t4, ax
push t4

;func(n-1)
call func_procedure
mov t6, ax

;i
mov ax, i1_1
mov t7, ax


;func(n-1)+i
mov ax, t7
add t6, ax

;return func(n-1)+i
mov ax, t6
jmp L4
L3: 
L4: 

pop bp
ret 2
func_procedure endp


;func function ended



;int func2 function
func2_procedure proc
push bp
mov bp, sp


;n
mov ax, [bp+4]
mov t8, ax


;0
mov t9, 0


;n==0
        mov ax, t9
        cmp t8, ax
        je L6
        mov t8, 0
        jmp L5
        L6:
        mov t8, 1
        L5:
cmp t8, 0
je L7

;0
mov t10, 0


;return 0
mov ax, t10
jmp L8
L7:

;n
mov ax, [bp+4]
mov t11, ax


;i = n
mov ax, t11 
mov i1_2, ax


;n
mov ax, [bp+4]
mov t12, ax


;1
mov t13, 1


;n-1
mov ax, t13
sub t12, ax
push t12

;func(n-1)
call func_procedure
mov t14, ax

;i
mov ax, i1_2
mov t15, ax


;func(n-1)+i
mov ax, t15
add t14, ax

;return func(n-1)+i
mov ax, t14
jmp L9
L8: 
L9: 

pop bp
ret 2
func2_procedure endp


;func2 function ended



;int main function
main proc
mov ax, @data
mov ds,ax


;7
mov t16, 7

push t16

;func(7)
call func_procedure
mov t17, ax

;a = func(7)
mov ax, t17 
mov a1_3, ax


;println(a);
mov ax, a1_3
call print_number

;0
mov t18, 0


;return 0
mov ax, t18
jmp L10
L10: 

mov ah, 4ch
int 21h
main endp

