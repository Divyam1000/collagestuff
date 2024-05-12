exit equ 1
close equ 0
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	
	prompt1 db "Enter 3 numbers ",10
	prompt1len equ $-prompt1
	prompt2 db "Sum of 3 numbers entered is : ",8
	prompt2len equ $-prompt2
	newline db 10,0

section .bss

	a: resb 1
	b: resb 1
	c: resb 1

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
	mov ecx, a
	mov edx, 2
	int 80h

	mov eax, read
	mov ebx, stdin
	mov ecx, b
	mov edx, 2
	int 80h

	mov eax, read
	mov ebx, stdin
	mov ecx, c
	mov edx, 2
	int 80h

;add

	mov eax, [a]
	sub eax, '0'
	mov ebx, [b]
	sub ebx, '0'
	add eax, ebx

	mov ebx, [c]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [a], eax
	int 80h
	
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt2
	mov edx, prompt2len
	int 80h
 	
	mov eax, write
	mov ebx, stdout
	mov ecx, a
	mov edx, 1
	int 80h	
	
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
	
	mov eax, exit
	mov ebx, close
	int 80h
	
	
	

