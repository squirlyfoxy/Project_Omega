[bits 16]
[org 0x7C00]

jmp main

; Presentation String (Project Omega File System)
PR: db ".PrOFS.", 0

main:
    mov [BOOT_DISK], dl

    mov si, welcome
    call printf

    call readDisk

    jmp PROGRAM_SPACE

%include "print.asm"        ; Print Function
%include "disk.asm"         ; Read Disk Function

welcome: db "|-Project Omega Bootloader v0.1-|", 10, 13, 0

times 510 - ($ - $$) db 0   ; Fill whith 0s
dw 0xAA55                   ; Must be the lastest 2 bytes