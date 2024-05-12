section .data
msg1 db 'Enter the elements of the array:', 10 
msg1len equ $-msg1
msg2 db 'Enter the number of elements in the array: '
msg2len equ $-msg2
msg3 db 'The sum is:'
msg3len equ $-msg3 
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
sum resb 1
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

mov eax,'0'
mov [sum],eax

mov esi, array 
mov eax, i

SUM:
	mov eax,[esi]
	mov [element],eax

	mov al,[element]
	sub al,'0'
	mov bl,[sum]
	sub bl,'0'
	add al,bl
	add al,'0'
	mov [sum],al

	dec byte[i]
	inc esi

	cmp byte[i],'0'
	jne SUM

write msg3, msg3len
write sum,1
write newline, newlinelen

mov eax,1
mov ebx,0
int 80h


