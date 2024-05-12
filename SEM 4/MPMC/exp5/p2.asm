exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

%macro Write_numbers 4
	mov eax, write
    	mov ebx, stdout
    	mov ecx, %3
    	mov edx, %4
    	int 80h	
	
	mov eax, write
	mov ebx, stdout
	mov ecx, %1
	mov edx, 1
	int 80h	
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, %2
	mov edx, 1
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
%endmacro

section .data
     
    prompt1 db "Enter two numbers : ",10
    prompt1len equ $-prompt1
    prompt2 db "Entered numbers are : ",10
    prompt2len equ $-prompt2
    newline db 10,0

section .bss
    num1: resb 1
    num2: resb 1
    
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

	Write_numbers num1, num2, prompt1, prompt1len
    
    mov eax, exit    
    mov ebx, 0
    int 80h
