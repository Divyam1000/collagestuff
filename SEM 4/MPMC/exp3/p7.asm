exit equ 1
close equ 0
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	
	prompt1 db "Odd numebrs from 0 - 9  :",10
	prompt1len equ $-prompt1
	odd db "1",0
	inct db "2",0
	comma db ",",0
	newline db 10,0

section .text
global _start

_start:
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h 
	
;1	
	mov eax, write
	mov ebx, stdout
	mov ecx, odd
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
;3	
	mov eax, [odd]
	sub eax, '0'
	mov ebx, [inct]
	sub eax, '0'	
	add eax, ebx
	add eax, '0'
	mov [odd], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, odd
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
;5
	mov eax, [odd]
	sub eax, '0'
	mov ebx, [inct]
	sub eax, '0'	
	add eax, ebx
	add eax, '0'
	mov [odd], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, odd
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
;7
	mov eax, [odd]
	sub eax, '0'
	mov ebx, [inct]
	sub eax, '0'	
	add eax, ebx
	add eax, '0'
	mov [odd], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, odd
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
;9
	mov eax, [odd]
	sub eax, '0'
	mov ebx, [inct]
	sub eax, '0'	
	add eax, ebx
	add eax, '0'
	mov [odd], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, odd
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
	
	
	
