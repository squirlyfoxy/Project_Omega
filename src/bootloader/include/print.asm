[bits 16]

printf:
    pusha
    strLoop:
        mov al, [si]
        cmp al, 0
        jne prChar      ; If AL != 0
        popa
        ret

    prChar:
        mov ah, 0x0E    ; 0x0E = Current memory Location (si)
        int 0x10        ; Print BIOS Call
        add si, 1

        jmp strLoop

[bits 32]
; Code from: https://github.com/cfenollosa/os-tutorial/blob/master/08-32bit-print/32bit-print.asm

VIDEO_MEMORY equ 0xb8000
WHITE_ON_WHITE equ 0x0f ; White

ProtectedPrintf:
    pusha
    mov edx, VIDEO_MEMORY

print_string_pm_loop:
    mov al, [ebx] ; [ebx] is the address of our character
    mov ah, WHITE_ON_WHITE

    cmp al, 0 ; check if end of string
    je print_string_pm_done

    mov [edx], ax ; store character + attribute in video memory
    add ebx, 1 ; next char
    add edx, 2 ; next video memory position

    jmp print_string_pm_loop

print_string_pm_done:
    popa
    ret