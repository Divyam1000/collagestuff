
section .data
	prompt db "Enter two numbers : ",10
	promptlen equ $-prompt
	result db "Numbers entered : ",10
	resultlen equ $-result
section .bss
	num1: resb 5
	num2: resb 5
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
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 3
	mov ebx, 1
	mov ecx, num2
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, result
	mov edx, resultlen
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, num1
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, num2
	mov edx, 5
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
