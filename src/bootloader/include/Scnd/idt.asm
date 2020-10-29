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

[extern irq0Handler]
irq0:
    PUSHALL

    call irq0Handler

    POPHALL
    iretq
    GLOBAL irq0

[extern irq1Handler]
irq1:
    PUSHALL

    call irq1Handler

    POPHALL
    iretq
    GLOBAL irq1

[extern irq2Handler]
irq2:
    PUSHALL

    call irq2Handler

    POPHALL
    iretq
    GLOBAL irq2

[extern irq3Handler]
irq3:
    PUSHALL

    call irq3Handler

    POPHALL
    iretq
    GLOBAL irq3

[extern irq4Handler]
irq4:
    PUSHALL

    call irq4Handler

    POPHALL
    iretq
    GLOBAL irq4

[extern irq5Handler]
irq5:
    PUSHALL

    call irq5Handler

    POPHALL
    iretq
    GLOBAL irq5

[extern irq6Handler]
irq6:
    PUSHALL

    call irq6Handler

    POPHALL
    iretq
    GLOBAL irq6

[extern irq7Handler]
irq7:
    PUSHALL

    call irq7Handler

    POPHALL
    iretq
    GLOBAL irq7

[extern irq8Handler]
irq8:
    PUSHALL

    call irq8Handler

    POPHALL
    iretq
    GLOBAL irq8

[extern irq9Handler]
irq9:
    PUSHALL

    call irq9Handler

    POPHALL
    iretq
    GLOBAL irq9

[extern irq10Handler]
irq10:
    PUSHALL

    call irq10Handler

    POPHALL
    iretq
    GLOBAL irq10

[extern irq11Handler]
irq11:
    PUSHALL

    call irq11Handler

    POPHALL
    iretq
    GLOBAL irq11

[extern irq12Handler]
irq12:
    PUSHALL

    call irq12Handler

    POPHALL
    iretq
    GLOBAL irq12

[extern irq13Handler]
irq13:
    PUSHALL

    call irq13Handler

    POPHALL
    iretq
    GLOBAL irq13

[extern irq14Handler]
irq14:
    PUSHALL

    call irq14Handler

    POPHALL
    iretq
    GLOBAL irq14

[extern irq15Handler]
irq15:
    PUSHALL

    call irq15Handler

    POPHALL
    iretq
    GLOBAL irq15

LoadIDT:
    lidt[idtDescriptor]
    sti
    ret
    GLOBAL LoadIDT