
%macro Read 2
	mov eax, 3
    	mov ebx, 0
    	mov ecx, %1
    	mov edx, %2
    	int 80h
%endmacro
%macro Write 2
	mov eax, 4
    	mov ebx, 1
    	mov ecx, %1
    	mov edx, %2
    	int 80h
%endmacro

%macro Fibonacci 3
	mov al, [%1]
	mov bl, [%2]
	sub al, '0'
	sub bl, '0'
	add al, bl
	add al, '0'
	mov [%3], al
	int 80h
%endmacro


section .data
     
    prompt1 db "Enter number of elements of fibonacci : ",8
    prompt1len equ $-prompt1
    prompt2 db "Fibonacci : ",10
    prompt2len equ $-prompt2
    newline db 10,0
    a db '0',0
    b db '1',0
    c db '0',0
    count db '0',0

section .bss
	n: resb 1

section .text
    global _start

_start:
	Write prompt1, prompt1len
	Read n, 2

	mov al, [count]
	mov bl, [n]
	cmp al, bl
	je exit
	
	Write prompt2, prompt2len

	Write a, 1
	Write newline, 1
	inc byte [count]
	
	mov al, [count]
	mov bl, [n]
	cmp al, bl
	je exit
 	
	Write b, 1
	Write newline, 1
	inc byte [count]	

	mov al, [count]
	mov bl, [n]
	cmp al, bl
	je exit
	jmp loop

loop:	
	Fibonacci a,b,c
	Write c,1
	Write newline,1
	mov bl, [b]
	mov [a], bl
	mov bl, [c]
	mov [b], bl
	inc byte [count]
	mov al, [count]
	mov bl, [n]
	cmp al, bl
	je exit
	jmp loop
	
exit:
    Write newline,1
    mov eax, 1    
    mov ebx, 0
    int 80h
