exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1


section .data
     
    prompt1 db "Enter a numbers : ",10
    prompt1len equ $-prompt1
    prompt2 db "Is multiple of 3 ",10
    prompt2len equ $-prompt2
    prompt3 db "Is Not multiple of 3 ",10
    prompt3len equ $-prompt3

section .bss
    num: resb 1

section .text
    global _start

_start:
   
    	mov eax, write
	mov ebx, stdout
	mov ecx, prompt1
	mov edx, prompt1len
	int 80h
    	mov eax, read
	mov ebx, stdin
	mov ecx, num
	mov edx, 2
	int 80h
  	
	mov al, [num]
	sub al, '0'
	mov bl, '3'
	sub bl, '0'
	div bl
	cmp ah, 0
	je is_multipal
	
	mov eax, write
	mov ebx, stdout
	mov ecx, prompt3
	mov edx, prompt3len
	int 80h
	jmp end

is_multipal:
    	mov eax, write
    	mov ebx, stdout
    	mov ecx, prompt2
    	mov edx, prompt2len
    	int 80h
	
end:
    	mov eax, exit    
    	mov ebx, 0
    	int 80h


