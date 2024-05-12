exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	prompt1 db "Enter radius of circle : ",10
	prompt1len equ $-prompt1
	prompt2 db "Area of circle : ",10
	prompt2len equ $-prompt2	
	newline db 10, 0

section .bss
	r: resb 1
	area: resb 1

section .text
global _start
_start:

;circle inputs
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, r
	mov edx, 2
	int 80h
;area 
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt2
	mov edx, prompt2len
	int 80h
	mov ax, [r]
	sub ax, "0"
	mov bx, [r]
	sub bx, "0"
	mul bx
	add ax, "0"
	mov [area], ax
	int 80h
	mov ax, [area]
	sub ax, "0"
	mov bx, "3"
	sub bx, "0"
	mul bx
	add ax, "0"
	mov [area], ax
	int 80h
	
	mov eax, write
	mov ebx, stdout
	mov ecx, area
	mov edx, 1	
	int 80h	
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h

	mov eax, exit
	mov ebx, 0
	int 80h
	
