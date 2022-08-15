
.code


;int main function
main proc
mov ax, @data
mov ds,ax


;3
mov t0, 3


;i = 3
mov ax, t0 
mov i1_1, ax


;8
mov t1, 8


;j = 8
mov ax, t1 
mov j1_1, ax


;6
mov t2, 6


;k = 6
mov ax, t2 
mov k1_1, ax


;i
mov ax, i1_1
mov t3, ax


;3
mov t4, 3


;i==3
        mov ax, t4
        cmp t3, ax
        je L1
        mov t3, 0
        jmp L0
        L1:
        mov t3, 1
        L0:
cmp t3, 0
je L2

;println(j);
mov ax, j1_1
call print_number
L2:

;j
mov ax, j1_1
mov t5, ax


;8
mov t6, 8


;j<8
        mov ax, t6
        cmp t5, ax
        jl L4
        mov t5, 0
        jmp L3
        L4:
        mov t5, 1
        L3:
cmp t5, 0
je L5

;println(i);
mov ax, i1_1
call print_number
jmp L6
L5:

;println(k);
mov ax, k1_1
call print_number
L6:

;k
mov ax, k1_1
mov t7, ax


;6
mov t8, 6


;k!=6
        mov ax, t8
        cmp t7, ax
        jne L8
        mov t7, 0
        jmp L7
        L8:
        mov t7, 1
        L7:
cmp t7, 0
je L9

;println(k);
mov ax, k1_1
call print_number
jmp L10
L9:

;j
mov ax, j1_1
mov t9, ax


;8
mov t10, 8


;j>8
        mov ax, t10
        cmp t9, ax
        jg L12
        mov t9, 0
        jmp L11
        L12:
        mov t9, 1
        L11:
cmp t9, 0
je L13

;println(j);
mov ax, j1_1
call print_number
jmp L14
L13:

;i
mov ax, i1_1
mov t11, ax


;5
mov t12, 5


;i<5
        mov ax, t12
        cmp t11, ax
        jl L16
        mov t11, 0
        jmp L15
        L16:
        mov t11, 1
        L15:
cmp t11, 0
je L17

;println(i);
mov ax, i1_1
call print_number
jmp L18
L17:

;0
mov t13, 0


;k = 0
mov ax, t13 
mov k1_1, ax


;println(k);
mov ax, k1_1
call print_number
L18:
L14:
L10:

;0
mov t14, 0


;return 0
mov ax, t14


mov ah, 4ch
int 21h
main endp

