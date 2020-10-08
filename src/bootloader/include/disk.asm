[bits 16]
readDisk:
    mov ah, 0x02
    mov bx, KERNEL_SPACE   ; Where code will put in memory?

    mov al, KPT_ENTRY               ; How many sectors?

    mov dl, [BOOT_DISK]     ; From Where?
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02            ; Read from 2nd sector

    int 0x13                ; BIOS Call for Disk Reading
    jc error                ; If 0x13 failed (Carry Flag)

    ret 

error:
    mov si, ReadErr
    call printf

    ; Press Any key to reboot
    getkey:
        xor ah,ah          ; AH = 0
        int 16h            ; Wait for key
        
        int 19h            ; Reboot
    hlt

%include "kpt.asm"

ReadErr: db "Read Disk Failed :(, Press any key to reboot...", 10, 13, 0

BOOT_DISK: db 0
KERNEL_SPACE: equ 0x8000
