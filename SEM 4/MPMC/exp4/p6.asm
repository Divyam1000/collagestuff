exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
    prompt db "Enter 2 strings : ", 10
    promptlen equ $ - prompt
    prompt2 db "Equal strings", 10
    prompt2len equ $ - prompt2
    prompt3 db "Not Equal Strings ", 10
    prompt3len equ $ - prompt3

section .bss
    str1: resb 20
    str2: resb 20

section .text
    global _start

_start:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt
    mov edx, promptlen
    int 80h

    mov eax, read
    mov ebx, stdin
    mov ecx, str1
    mov edx, 20
    int 80h

    mov eax, read
    mov ebx, stdin
    mov ecx, str2
    mov edx, 20
    int 80h

    mov esi, str1
    mov edi, str2
compare_string:
    mov al, [esi]
    mov bl, [edi]
    cmp al, bl
    jne string_not_equal
    cmp al, 0
    je string_equal
    inc esi
    inc edi
    jmp compare_string

string_equal:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt2
    mov edx, prompt2len
    int 80h
    jmp end

string_not_equal:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt3
    mov edx, prompt3len
    int 80h

end:
 
    mov eax, 1
    xor ebx, ebx
    int 0x80
