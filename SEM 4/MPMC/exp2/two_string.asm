close equ 0
write equ 4
exit equ 1

section .data
	string1 db 'Hello', 10
	s1len equ $-string1
	string2 db 'World', 10	
	s2len equ $-string2
	
		
section .text
global _start
_start:
	mov eax, write
	mov ebx, close
	mov ecx, string1
	mov edx, s1len
	int 80h

	mov eax, write
	mov ebx, close
	mov ecx, string2
	mov edx, s2len
	int 80h
	
	mov eax, exit
	mov ebx, close
	int 80h

