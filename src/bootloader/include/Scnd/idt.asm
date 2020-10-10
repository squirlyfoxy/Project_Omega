[extern _idt]

idtDescriptor:
    dw 4095
    dq _idt

    %macro PUSHALL 0
        push rax
        push rcx
        push rdx
        push r8
        push r9
        push r10
        push r11
    %endmacro

    %macro POPHALL 0
        pop r11
        pop r10
        pop r9
        pop r8
        pop rdx
        pop rcx
        pop rax
    %endmacro

[extern isr0Handler]
isr0:
    PUSHALL

    call isr0Handler

    POPHALL
    iretq
    GLOBAL isr0

[extern isr1Handler]
isr1:
    PUSHALL

    call isr1Handler

    POPHALL
    iretq
    GLOBAL isr1

[extern isr2Handler]
isr2:
    PUSHALL

    call isr2Handler

    POPHALL
    iretq
    GLOBAL isr2

[extern isr3Handler]
isr3:
    PUSHALL

    call isr3Handler

    POPHALL
    iretq
    GLOBAL isr3

[extern isr4Handler]
isr4:
    PUSHALL

    call isr4Handler

    POPHALL
    iretq
    GLOBAL isr4

[extern isr5Handler]
isr5:
    PUSHALL

    call isr5Handler

    POPHALL
    iretq
    GLOBAL isr5

[extern isr6Handler]
isr6:
    PUSHALL

    call isr6Handler

    POPHALL
    iretq
    GLOBAL isr6

[extern isr7Handler]
isr7:
    PUSHALL

    call isr7Handler

    POPHALL
    iretq
    GLOBAL isr7

[extern isr8Handler]
isr8:
    PUSHALL

    call isr8Handler

    POPHALL
    iretq
    GLOBAL isr8

[extern isr9Handler]
isr9:
    PUSHALL

    call isr9Handler

    POPHALL
    iretq
    GLOBAL isr9

[extern isr10Handler]
isr10:
    PUSHALL

    call isr10Handler

    POPHALL
    iretq
    GLOBAL isr10

[extern isr11Handler]
isr11:
    PUSHALL

    call isr11Handler

    POPHALL
    iretq
    GLOBAL isr11

[extern isr12Handler]
isr12:
    PUSHALL

    call isr12Handler

    POPHALL
    iretq
    GLOBAL isr12

[extern isr13Handler]
isr13:
    PUSHALL

    call isr13Handler

    POPHALL
    iretq
    GLOBAL isr13

[extern isr14Handler]
isr14:
    PUSHALL

    call isr14Handler

    POPHALL
    iretq
    GLOBAL isr14

[extern isr15Handler]
isr15:
    PUSHALL

    call isr15Handler

    POPHALL
    iretq
    GLOBAL isr15

LoadIDT:
    lidt[idtDescriptor]
    sti
    ret
    GLOBAL LoadIDT