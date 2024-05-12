exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	prompt1 db "Enter two numbers : ",10
	prompt1len equ $-prompt1
	prompt2 db "Sum of numbers : ",8
	prompt2len equ $-prompt2
	prompt3 db "Subtraction of numbers : ", 8
	prompt3len equ $-prompt3
	prompt4 db "Produt of numbers : ", 8
	prompt4len equ $-prompt4
	prompt5 db "Division of numbers : ", 10
	prompt5len equ $-prompt5
	prompt6 db "quot : ", 8
	prompt6len equ $-prompt6
	prompt7 db "rmd : ",8
	prompt7len equ $-prompt7
	newline db 10,0

section .bss
	n1: resb 1
	n2: resb 2	
	result: resb 1
	remd: resb 1
	quot: resb 1

section .text
global _start
_start:

;Inputs
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, n1
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, n2
	mov edx, 2
	int 80h
	

; Add
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt2
	mov edx, prompt2len
	int 80h
	mov eax, [n1]
	sub eax, '0'
	mov ebx, [n2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [result], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h

; sub
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt3
	mov edx, prompt3len
	int 80h
	mov eax, [n1]
	sub eax, '0'
	mov ebx, [n2]
	sub ebx, '0'
	sub eax, ebx
	add eax, '0'	
	mov [result], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
	
; Mul
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt4
	mov edx, prompt4len
	int 80h
	mov ax, [n1]
	sub ax, '0'
	mov bx, [n2]
	sub bx, '0'
	mul bx
	add ax, '0'
	mov [result], ax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, result
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h	

; Div
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt5
	mov edx, prompt5len
	int 80h
	mov al, [n1]
	sub al, '0'
	mov bl, [n2]
	sub bl, '0'
	mul bl
	add al, '0'
	add ah, '0'
	mov [remd], ah
	mov [quot], al 
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt6
	mov edx, prompt6len
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, quot
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt7
	mov edx, prompt7len
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, remd
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
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
	

	
