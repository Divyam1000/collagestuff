section .data
	hello db 'Hello world', 10
	hellolen equ $-hello

	name db 'Divyam', 10
	namelen equ $-name

section .text
global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, hellolen
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, name
	mov edx, namelen
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h
