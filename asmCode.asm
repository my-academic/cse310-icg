
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


;999
mov t1, 999


;j = 999
mov ax, t1 
mov j1_1, ax


;i
mov ax, i1_1
mov t2, ax


;3
mov t3, 3


;i==3
        mov ax, t3
        cmp t2, ax
        je L1
        mov t2, 0
        jmp L0
        L1:
        mov t2, 1
        L0:
cmp t2, 0
je L2

;println(j);
mov ax, j1_1
call print_number
L2:

;0
mov t4, 0


;return 0
mov ax, t4


mov ah, 4ch
int 21h
main endp

