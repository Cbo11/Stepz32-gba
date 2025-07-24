ENTRY(_start)

MEMORY
{
    ROM (rx) : ORIGIN = 0x08000000, LENGTH = 32M
    RAM (rwx) : ORIGIN = 0x02000000, LENGTH = 256K
}

SECTIONS
{
    .text : { *(.text*) } > ROM
    .rodata : { *(.rodata*) } > ROM
    .data : { *(.data*) } > RAM AT > ROM
    .bss : { *(.bss*) } > RAM
}