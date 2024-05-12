section .data
msg1 db 'Enter the elements of the array:', 10 
msg1len equ $-msg1
msg2 db 'Enter the number of elements in the array: '
msg2len equ $-msg2
msg3 db 'The number of elements above 5 are'
msg3len equ $-msg3 
msg4 db 'The number of elements below 5 are'
msg4len equ $-msg4
newline db '  ',10
newlinelen equ $-newline
tab db ' '
tablen equ $-tab
;array declaration and initialization
array dw 0,0,0,0,0,0,0,0,0
arraylen equ 9

%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro
 
%macro read 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
	mov eax,3
	mov ebx,2
	mov ecx,gb
	mov edx,1
	int 80h
%endmacro

section .bss
n resb 9
element resb 9
i resb 9
above resb 9
below resb 9
gb resb 1

section .text
global _start

_start:

write msg2, msg2len
read n, 1
write msg1, msg1len

mov eax, [n]
mov [i], eax
mov esi, array 
mov eax, n

input_element:
	read element, 1
	mov ebx, [element] 
	mov [esi], ebx
	dec byte[n] 
	inc esi
	cmp byte[n], '0'
	jne input_element

mov esi, array 
mov eax,i

mov byte[above],'0'
mov byte[below],'0'

check:
	mov eax, [esi]
	mov [element], eax
	mov al, [element]
	mov bl,'5'
	cmp al,bl
	jl LESS
	jg GREATER

LESS:
	inc byte[below]
	jmp END

GREATER:
	inc byte[above]
	jmp END

END:
	dec byte[i]
	inc esi
	cmp byte[i],'0'
	jne check

write msg3, msg3len
write above, 1
write tab, tablen
write newline, newlinelen
write msg4, msg4len
write below, 1
write tab, tablen
write newline, newlinelen

mov eax, 1
mov ebx,0
int 80h
