section .data
msg1 db 'Enter the elements of the array:', 10
msg1len equ $-msg1
msg2 db 'Even number of elements:'
msg2len equ $-msg2
msg3 db 'Enter the number of elements in the array: '
msg3len equ $-msg3
msg4 db 'Odd number of elements:'
msg4len equ $-msg4
newline db ' ',10
newlinelen equ $-newline
tab db ''
tablen equ $-tab

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
odd resb 9
even resb 9
rem resb 9
i resb 9
gb resb 1

section .text
global _start

_start:

write msg3, msg3len
read n, 1
write msg1, msg1len

mov eax, '0'
mov [even], eax
mov eax, '0'
mov [odd], eax
mov eax, [n]
mov [i], eax
mov esi, array
mov eax,n

input_element:
    read element, 1
    mov bx,[element]
    mov [esi], bx
    dec byte[n]
    inc esi
    cmp byte[n], '0'
    jne input_element

mov esi, array
mov eax,i

check:
    mov eax, [esi]
    mov [element], eax
    write tab, tablen

    mov al,[element]
    sub al,'0'
    mov bl,'2'
    sub bl,'0'
    div bl
    add ah,'0'
    add al,'0'
    mov[rem],ah
    mov eax,[rem]
    mov ebx,'0'
    cmp eax,ebx
    je EVEN
    jne ODD

    EVEN:
        inc byte[even]
        jmp CMP

    ODD:
        inc byte[odd]
        jmp CMP

    CMP:
        dec byte[i]
        inc esi
        cmp byte[i],'0'
        jne check

write msg2, msg2len
write tab, tablen
write even, 1
write newline, newlinelen
write msg4, msg4len
write tab, tablen
write odd, 1
write newline, newlinelen

mov eax,1
mov ebx,0
int 80h
