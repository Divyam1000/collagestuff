exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
	prompt1 db "Enter both sides of rectangle : ",10
	prompt1len equ $-prompt1
	prompt2 db "Enter base and height of triangle : ",10
	prompt2len equ $-prompt2
	prompt3 db "Area of rectangle : ", 8
	prompt3len equ $-prompt3
	prompt4 db "Area of triangle : ", 8
	prompt4len equ $-prompt4
	prompt5 db "Parameter of rectangle : ", 8
	prompt5len equ $-prompt5
	prompt6 db "Parameter of triangle : ", 8
	prompt6len equ $-prompt6
	prompt7 db "Enter all three side of the triangle : ",10
	prompt7len equ $-prompt7
	newline db 10,0
	two db "2",0

section .bss
	s1: resb 1
	s2: resb 1
	s3: resb 1
	area: resb 1
	par: resb 1	
	

section .text
global _start
_start:

;rectangle inputs
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s1
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s2
	mov edx, 2
	int 80h
	

;area of rectangle
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt3
	mov edx, prompt3len
	int 80h
	mov al, [s1]
	sub al, '0'
	mov bl, [s2]
	sub bl, '0'
	mul bl
	add ax, '0'
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

; Parameter of rectangle
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt5
	mov edx, prompt5len
	int 80h
	mov eax, [s1]
	sub eax, '0'
	mov ebx, [s2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'	
	mov [par], eax
	int 80h
	mov al, [par]
	sub al, '0'
	mov bl, "2"
	sub bl, '0'
	mul bl
	add ax, '0'
	mov [par], ax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, par
	mov edx, 1	
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
	
;triangle inputs
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt2
	mov edx, prompt2len
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s1
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s2
	mov edx, 2
	int 80h
	

;area of triangle
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt4
	mov edx, prompt4len
	int 80h
	mov al, [s1]
	sub al, '0'
	mov bl, [s2]
	sub bl, '0'
	mul bl
	add al, '0'
	mov [area], al
	int 80h
	mov al, [area]
	sub al, '0'
	mov bl, [two]
	sub bl, '0'
	div bl
	add al, '0'
	mov [area], al
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

; Parameter of triangle
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt7
	mov edx, prompt7len
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s1
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s2
	mov edx, 2
	int 80h
	mov eax, read
	mov ebx, stdin
	mov ecx, s3
	mov edx, 2
	int 80h

	mov eax, write
	mov ebx, stdout
	mov ecx, prompt6
	mov edx, prompt6len
	int 80h
	mov eax, [s1]
	sub eax, '0'
	mov ebx, [s2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'	
	mov [par], eax
	int 80h
	mov eax, [s3]
	sub eax, '0'
	mov ebx, [par]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'	
	mov [par], eax
	int 80h
	mov eax, write
	mov ebx, stdout
	mov ecx, par
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
	

	
