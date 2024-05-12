section .data
msg1 db 'Number of Positive numbers: ' 
msg1len equ $-msg1
msg2 db 'Number of Negative numbers: ' 
msg2len equ $-msg2
new db '',10
nl equ $-new
arr db 1, -2, -3, -11, 5, -6, 4

%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro

fun:
	mov eax, 0
	mov [p_count], eax
	mov [n_count], eax
	mov ecx, 7
	mov esi, arr
	label:
	mov bl, [esi] 
	cmp bl,0
	jg positive
    	inc byte[n_count]
	    jmp end
	positive:
	    inc byte[p_count]
	end:
	inc esi
	loop label
	mov eax, [p_count]
	add eax, '0'
	mov [p_count], eax
	mov eax, [n_count]
	add eax, '0'
	mov [n_count], eax
ret


section .bss
p_count resb 1
n_count resb 1

section .text
global _start
_start:
	call fun
	write msg1,msg1len
	write p_count, 1
	write new,nl
	write msg2,msg2len
	write n_count, 1
	write new,nl
	mov eax ,1
	mov ebx ,0
	int 80h
