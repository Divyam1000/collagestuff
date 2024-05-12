section .data
msg db 'Enter number of elements: '
msglen equ $-msg
msg1 db 'Enter elements:' 
msg1len equ $-msg1
msg2 db 'Array elements: ' 
msg2len equ $-msg2
msg3 db ' Enter Array elements: ', 10
msg3len equ $-msg3
newline db '',10
space db ' '

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

input_array:
    mov byte[i], 0
    mov esi, arr
    ip_loop:
        read element,1
        mov ebx, [element]
        sub ebx, '0'
        mov [esi], ebx
        inc esi
        inc byte[i]
        mov al, [i]
        mov bl, [n]
        cmp al, bl
        jl ip_loop
ret

display_array:
    mov byte[i], 0
    mov esi, arr
    op_loop:
        mov eax, [esi]
        add eax, '0'
        mov [element], eax
        write element, 1
        write space, 1
        inc esi
        inc byte[i]
        mov al, [i]
        mov bl, [n]
        cmp al, bl
        jl op_loop
    write newline,1
ret

section .bss
n RESB 1
arr resb 10
i resb 1
gb resb 1
element resb 1


section .text
global _start
_start:

    write msg, msglen
    read n, 1
    mov eax, [n]
    sub eax, '0'
    mov [n], eax
    write msg3, msg3len
    call input_array
    write msg2 ,msg2len
    call display_array
    
    mov eax, 1
    mov ebx, 0
    int 80h
    
    