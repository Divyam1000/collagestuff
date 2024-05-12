vexit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
    prompt db "Enter a number: ", 0
    promptlen equ $ - prompt
    prompt2 db "Odd ", 10
    prompt2len equ $ - prompt2
    prompt3 db "Even ", 10
    prompt3len equ $ - prompt3

section .bss
    num: resb 1

section .text
    global _start

_start:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt
    mov edx, promptlen
    int 80h

    mov eax, 3
    mov ebx, 0
    mov ecx, num
    mov edx, 2
    int 80h

    mov al, [num]
    and al, 1
    jz even
    
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt2
    mov edx, prompt2len
    int 80h
    jmp end

even:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt3
    mov edx, prompt3len
    int 80h

end:
 
    mov eax, 1
    xor ebx, ebx
    int 0x80
