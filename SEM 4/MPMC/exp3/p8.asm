exit equ 1
close equ 0
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	
	prompt1 db "Multiple of 3 from 0 - 9  :",10
	prompt1len equ $-prompt1
	comma db ",",0
	newline db 10,0
	multi db "1",0

section .bss
	result: resb 1

section .text
global _start

_start:
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h 
;3
	mov al, "3"
	sub al, '0'
	mov bl, [multi]
	sub bl, '0'
	mul bl
	add al, '0'
	mov [result], al
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
	mov eax, [multi]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [multi], eax
	int 80h
;6
	mov al, "3"
	sub al, '0'
	mov bl, [multi]
	sub bl, '0'
	mul bl
	add al, '0'
	mov [result], al
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, comma
	mov edx, 1
	int 80h
	mov eax, [multi]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [multi], eax
	int 80h
;9
	mov al, "3"
	sub al, '0'
	mov bl, [multi]
	sub bl, '0'
	mul bl
	add al, '0'
	mov [result], al
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, [multi]
	sub eax, '0'
	mov ebx, '1'
	add eax, ebx
	mov [multi], eax
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, exit
	mov ebx, close
	int 80h
	
