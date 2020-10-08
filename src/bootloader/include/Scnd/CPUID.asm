%include "print.asm"

DetectCPUID:
    pushfd
    pop eax

    mov ecx, eax
    xor eax, 1 << 21

    push eax
    popfd

    pushfd
    pop eax

    push ecx
    popfd

    xor eax, ecx
    jz NoCPUID
    ret

DetectLongMode:
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz NoLongMode
    ret

NoCPUID:
    mov ebx, NoCPUIDStr
    call ProtectedPrintf
    hlt

NoLongMode:
    mov ebx, NoLongModeStr
    call ProtectedPrintf
    hlt

NoCPUIDStr: db "ERRNO 0x01: CPUID Not Supported", 10, 13, 0
NoLongModeStr: db "ERRNO 0x02: LMode Not Supported", 10, 13, 0