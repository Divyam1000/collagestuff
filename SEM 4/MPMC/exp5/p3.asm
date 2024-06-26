exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

%macro Read_and_Display_number 3
	
	mov eax, read
	mov ebx, stdin
	mov ecx, %1
	mov edx, 1
	int 80h

	mov eax, write
    	mov ebx, stdout
    	mov ecx, %2
    	mov edx, %3
    	int 80h	

	mov eax, write
    	mov ebx, stdout
    	mov ecx, %1
    	mov edx, 1
    	int 80h	
%endmacro

section .data
     
    prompt1 db "Enter a numbers : ",8
    prompt1len equ $-prompt1
    prompt2 db "Entered number: ",8
    prompt2len equ $-prompt2
    newline db 10,0

section .bss
    num1: resb 1
    
section .text
    global _start

_start:
		
	mov eax, write
    	mov ebx, stdout
    	mov ecx, prompt1
    	mov edx, prompt1len
    	int 80h	

	Read_and_Display_number num1, prompt2, prompt2len

    	mov eax, write
	mov ebx, stdout
	mov ecx, newline
	mov edx, 1
	int 80h
    
    mov eax, exit    
    mov ebx, 0
    int 80h
