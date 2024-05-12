exit equ 1
close equ 0
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	
	prompt1 db "Enter a number ",10
	prompt1len equ $-prompt1
	prompt2 db "Entered Number with next 4 consiqutive numbers : ",10
	prompt2len equ $-prompt2
	comma db ",",0
	newline db 10,0

section .bss

	a: resb 1

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
	mov ecx, comma
	mov edx, 1
	int 80h

; next process

	mov eax, [a]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [a], eax
	int 80h
	
	mov eax, write
	mov ebx, stdout
	mov ecx, a
	mov edx, 1
	int 80h	

	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h

	mov eax, [a]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [a], eax
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, a
	mov edx, 1
	int 80h	

	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h

	mov eax, [a]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [a], eax
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, a
	mov edx, 1
	int 80h	

	mov eax, [a]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [a], eax
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
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
	
	
	

