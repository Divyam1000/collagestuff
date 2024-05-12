exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

; Add
%macro ADDITION 3
	
	mov eax, [%1]
	sub eax, '0'
	mov ebx, [%2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [%3], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, %3
	mov edx, 1	
	int 80h
%endmacro

; sub
%macro SUBTRACTION 3
	mov eax, [%1]
	sub eax, '0'
	mov ebx, [%2]
	sub ebx, '0'
	sub eax, ebx
	add eax, '0'	
	mov [%3], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, %3
	mov edx, 1	
	int 80h
%endmacro

; Mul
%macro MULTIPLICATION 3
	mov ax, [%1]
	sub ax, '0'
	mov bx, [%2]
	sub bx, '0'
	mul bx
	add ax, '0'
	mov [%3], ax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, %3
	mov edx, 1	
	int 80h
%endmacro

; Div
%macro DIVISION 4
	mov al, [%1]
	sub al, '0'
	mov bl, [%2]
	sub bl, '0'
	div bl
	add al, '0'
	add ah, '0'
	mov [%3], ah
	mov [%4], al 
	int 80h
%endmacro


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
	num1: resb 1
	num2: resb 2	
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
	mov ecx, num1
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, num2
	mov edx, 2
	int 80h
;adds	
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt2
	mov edx, prompt2len
	int 80h
	ADDITION num1, num2, result
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
;subs
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt3
	mov edx, prompt3len
	int 80h
	SUBTRACTION num1, num2, result
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h	
;multi's
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt4
	mov edx, prompt4len
	int 80h
	MULTIPLICATION num1, num2, result
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h	
;div's
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt5
	mov edx, prompt5len
	int 80h
	DIVISION num1, num2, remd, quot
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

	mov eax, exit
	mov ebx, 0
	int 80h
	

