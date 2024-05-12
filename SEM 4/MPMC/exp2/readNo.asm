section .data
	prompt db "Enter a number : "
	promptlen equ $-prompt
section .bss
	num: resb 10

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
	mov ecx, num
	mov edx, 10
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
