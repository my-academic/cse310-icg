
.code


;int main function
main proc
mov ax, @data
mov ds,ax


;i
mov ax, i1_1
mov t0, ax


;3
mov t1, 3


;i==3
        mov ax, t1
        cmp t0, ax
        je L1
        mov t0, 0
        jmp L0
        L1:
        mov t0, 1
        L0:
        
;println(j);
mov ax, j1_1
call print_number

;0
mov t2, 0


;return 0
mov ax, t2


mov ah, 4ch
int 21h
main endp

