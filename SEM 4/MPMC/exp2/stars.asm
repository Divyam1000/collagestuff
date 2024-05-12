section .data
	
	star times 9 db '*'
	newline db 10,0

section .text
global _start
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, star
	mov edx, 10
	int 80h
	
	mov eax, 1
	mov ebx, 0
	int 80h

