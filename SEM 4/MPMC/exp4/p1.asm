exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1


section .data
     
    prompt1 db "Enter two numbers : ",10
    prompt1len equ $-prompt1
    prompt2 db "Largest of the numbers is : ",8
    prompt2len equ $-prompt2
    newline db 10,0

section .bss
    num1: resb 1
    num2: resb 1
    result: resb 1
    
section .text
    global _start

_start:
   
    mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h
    mov eax, read
	mov ebx, stdin
	mov ecx, num1
	mov edx, 2
	int 80h
    mov eax, read
	mov ebx, stdin
	mov ecx, num2
	mov edx, 2
	int 80h

    mov al, [num1]
    mov bl, [num2]
    cmp al, bl

    jg largest
    
    mov [result], bl
    jmp end

largest:
    mov [result], al

end:
    
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt2
    mov edx, prompt2len
    int 80h
    
    mov eax, write
    mov ebx, stdout
    mov ecx, result
    mov edx, 1
    int 80h
    
    mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
    
    mov eax, exit    
    mov ebx, 0
    int 80h
