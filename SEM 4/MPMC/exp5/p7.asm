%MACRO write_string 2
    MOV EAX, 4
    MOV EBX, 1
    PUSH ECX
    MOV ECX, %1
    MOV EDX, %2
    int 0x80
    POP ECX
%ENDMACRO

%MACRO read_string 2
    MOV EAX, 3
    MOV EBX, 2
    MOV ECX, %1
    MOV EDX, %2
    int 0x80
%ENDMACRO

section .data
s1 db 'Enter the name: '
s1l equ $-s1
s2 db 'looping the name: ', 10
s2l equ $-s2

section .bss
name resb 40

section .text
global _start
_start:
	write_string s1, s1l

	read_string name, 40

	write_string s2, s2l

    MOV ECX, 9
    loop_name:
        write_string name, 40
        LOOP loop_name

MOV EAX, 1
MOV EBX, 0
int 0x80
