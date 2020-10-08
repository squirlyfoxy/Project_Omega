;%include "print.asm"

MemoryRegionCount:
    db 0
    GLOBAL MemoryRegionCount

DetectMemory:
    mov ax, 0
    mov es, ax
    mov di, 0x5000
    mov edx, 0x534D4150
    xor ebx, ebx

    .repet:
        mov eax, 0xE820
        mov ecx, 24 ; 24 bytes
        int 0x15
        jc short .failed
        cmp ebx, 0
        je .finished

        add di, 24
        inc byte [MemoryRegionCount]
        jmp .repet
    
    .finished:

    .failed:
        mov ebx, DETECT_MEMORY_FAILED
        call printf
        stc
        ret

    ret

DETECT_MEMORY_FAILED: db "ERRNO 0x03: 0x15 non supported", 0