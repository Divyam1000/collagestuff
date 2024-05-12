section .data 
    prompt db 'Enter the number of terms : ' 
    plen equ $-prompt 
    newline db 10,0 
    result db 'The fibonacci series is : ' 
    rlen equ $-result 
    space db ', ' 
section .bss 
    n resb 5 
    a resb 5 
    b resb 5 
    i resb 5 
    c resb 5 
section .text 
global _start 
_start: 
    mov ecx,prompt 
    mov edx,plen 
    call write 
    mov ecx,n 
    mov edx,5 
    call read 
    mov ecx,result 
    mov edx,rlen 
    call write 
    call fibo 
exit: 
    mov ecx, newline
    mov edx, 1
    call write 
    mov eax,1 
    mov ebx,0 
    int 80h 

write: 
    mov eax,4 
    mov ebx,1 
    int 80h 
    ret 

read: 
    mov eax,3 
    mov ebx,2 
    int 80h 
    ret 

computesum: 
    mov al,[a] 
    mov bl,[b] 
    sub al,'0' 
    sub bl,'0' 
    add al,bl 
    add al,'0' 
    mov [c],al 
    ret

fibo: 
    mov [i], byte '0' 
    mov [a],byte'0' 
    mov [b],byte'1' 
    mov al ,[n] 
    cmp al,'0' 
    je exit 
    mov ecx,a 
    mov edx,1 
    call write
    mov ecx, space
    mov edx, 1
    call write 
    inc byte [i] 
    mov al, [i] 
    cmp al, byte[n] 
    je exit 
    mov ecx,b 
    mov edx,1 
    call write
    mov ecx, space
    mov edx, 1 
    call write
    inc byte [i] 
    mov al, [i] 
    cmp al, byte[n] 
    je exit 
    jmp loop

loop: 
    call computesum 
    mov ecx,c 
    mov edx,1 
    call write
    mov al, [b] 
    mov [a], al 
    mov al, [c] 
    mov [b], al 
    inc byte [i] 
    mov al, [i] 
    cmp al, byte[n] 
    je exit 
    mov ecx, space
    mov edx, 1
    call write 
    jmp loop 
    ret 