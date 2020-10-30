[bits 16]

jmp _main

; multiboot header
MODULEALIGN:        equ        1<<0
MEMINFO:            equ        1<<1
FLAGS:              equ        MODULEALIGN | MEMINFO
MAGIC:              equ        0x1BADB002
CHECKSUM:           equ        -(MAGIC + FLAGS)
 
section .text      ; Next is the Grub Multiboot Header
 
align 4
MultiBootHeader:
       dd MAGIC
       dd FLAGS
       dd CHECKSUM

; Presentation string (Kernel first stage)
PR2: db "K_Entry", 0

; Assembly Files for Protected Mode
%include "Scnd/gdt.asm"
%include "Scnd/Memory.asm"

_main:
    push eax
    push ebx

    call DetectMemory

    EnterProtectedMode:
        call EnableA20
        cli
        lgdt [gdt_descriptor]

        mov eax, cr0
        or eax, 1
        mov cr0, eax
        jmp codeseg:StartProtectedMode

    EnableA20:
        ; Code From: http://kernelx.weebly.com/a20-address-line.html
        cli                 ;Disables interrupts
        push ax             ;Saves AX
        mov al, 0xdd        ;Look at the command list 
        out 0x64, al        ;Command Register 
        pop ax              ;Restore's AX
        sti                 ;Enables interrupts
        ret 

[bits 32]
; Assembly Files for Long Mode
%include "Scnd/CPUID.asm"
%include "Scnd/64mod.asm"

StartProtectedMode:
    mov ax, dataseg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Disable interrupts
    cli

    ; Detect if Long Mode is supported
    call DetectCPUID
    call DetectLongMode

    ; SetUp Paging
    call PagingSetUp
    
    ; Set the LM-bit: 
    mov ecx, 0xC0000080          ; Set the C-register to 0xC0000080, which is the EFER MSR.
    rdmsr                        ; Read from the model-specific register.
    or eax, 1 << 8               ; Set the LM-bit which is the 9th bit (bit 8).
    wrmsr                        ; Write to the model-specific register.

    ; Enable Paging
    mov eax, cr0                 ; Set the A-register to control register 0.
    or eax, 1 << 31              ; Set the PG-bit, which is the 32nd bit (bit 31).
    mov cr0, eax                 ; Set control register 0 to the A-register.

    lgdt [GDT64.Pointer]         ; Load the 64-bit global descriptor table.

    jmp GDT64.Code:LongMode      ; Set the code segment and enter 64-bit long mode.

[bits 64]
[extern _start]

%include "Scnd/idt.asm"

LongMode:
    cli                           ; Clear the interrupt flag.
    mov ax, GDT64.Data            ; Set the A-register to the data descriptor.
    mov ds, ax                    ; Set the data segment to the A-register.
    mov es, ax                    ; Set the extra segment to the A-register.
    mov fs, ax                    ; Set the F-segment to the A-register.
    mov gs, ax                    ; Set the G-segment to the A-register.
    mov ss, ax                    ; Set the stack segment to the A-register.

    xor rax, rax
	mov dr0, rax	; Set CPU0

    ; Now we are in Long Mode!!!

    call _start

    jmp $                           ; Halt the processor.

ActivateSSE:
    ; Check for SSE Support
    mov eax, 0x1
    cpuid
    test edx, 1 << 25
    jz .noSEE

    ; Allow SEE instructions
    mov rax, cr0
    and ax, 0b11111101
    or ax, 0b00000001
    mov cr0, rax

    mov rax, cr4
    or ax, 0b1100000000
    mov cr4, rax
    ret

    .noSEE:
        ret

times 2048 - ($ - $$) db 0   ; Fill 4 sectors