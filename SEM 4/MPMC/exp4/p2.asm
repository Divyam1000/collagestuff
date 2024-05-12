
exit equ 1
read equ 3
write equ 4
stdin equ 0
stdout equ 1

section .data
    prompt db "Enter 3 numbers: ", 10
    prompt_len equ $ - prompt
    prompt2 db "Largest of 3 numbers entered : ", 0
    prompt2_len equ $ - prompt2
    newline db 10,0
    
section .bss
    num1: resb 1
    num2: resb 1
    num3: resb 1
    result: resb 1
    
section .text
    global _start

_start:
    mov eax, write
    mov ebx, stdout
    mov ecx, prompt      
    mov edx, prompt_len  
    int 80h             

    mov eax, read
    mov ebx, stdin
    mov ecx, num1 
    mov edx, 2    
    int 80h

    mov eax, read
    mov ebx, stdin
    mov ecx, num2
    mov edx, 2    
    int 80h
    
    mov eax, read
    mov ebx, stdin
    mov ecx, num3 
    mov edx, 2    
    int 80h

    mov al, [num1]
    mov bl, [num2]
    cmp al, bl
    jg check_num1_num3

    mov al, [num2]
    mov bl, [num3]
    cmp al, bl
    jg check_num2_num3

    mov [result], bl
    jmp end

check_num1_num3:
    mov al, [num1]
    mov bl, [num3]
    cmp al, bl
    jg move_num1_result

    mov [result], bl
    jmp end

check_num2_num3:
    mov [result], al
    jmp end

move_num1_result:
    mov [result], al

end:
     mov eax, write
    mov ebx, stdout
    mov ecx, prompt2      
    mov edx, prompt2_len  
    int 80h    
    
    mov eax, write
    mov ebx, stdout
    mov ecx, result      
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
