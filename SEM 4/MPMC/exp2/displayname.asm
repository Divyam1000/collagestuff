
section .data
	prompt db "Enter a name : "
	promptlen equ $-prompt
section .bss
	name: resb 10

section .text
global _start

_start:

	mov eax, 4
	mov ebx, 1
	mov ecx, prompt
	mov edx, promptlen
	int 80h

	mov eax, 3
	mov ebx, 1
	mov ecx, name
	mov edx, 20
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, name
	mov edx, 20
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
