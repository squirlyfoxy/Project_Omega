OUTPUT_FORMAT(binary)

ENTRY(_start)

INPUT
(
    ./out/k1.o
    ./out/libkernel.a
)

SECTIONS
{
    . = 0x8000;

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.text)
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        _idt = .;
        . = . + 0x1000;
    }

    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
       *(COMMON)
        *(.bss)
    }
}