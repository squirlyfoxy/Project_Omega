@echo off

:: Build kernel
echo Building kernel:
echo - Building Stage 1
wsl $HOME/opt/cross/bin/x86_64-elf-gcc  -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "kernel/kentry.cpp" -o "out/kentry.o"
echo - Building Stage 2
nasm -i ./bootloader/include bootloader/Stage2/64_32mod.asm -f elf64 -o ./out/k1.o

echo Linking kernel:
echo - Linking Stage 1
wsl $HOME/opt/cross/x86_64-elf/bin/x86_64-elf-ld -T "linker.ld"

:: Generating KPT
echo Generating KPT.asm:

echo - Executing kpt.py:
py kpt.py

echo Building bootloader:
:: Build bootloader
echo - Building Stage 1
nasm -i ./bootloader/include bootloader/bootloader.asm -f bin -o ./out/bootloader.bin

:: Create system image
echo Creating system image:
cd out

:: Combining files togheder togheder
echo - Combining files togheder
copy /B /Y "bootloader.bin"+"kernel.bin" "boot.bin"
del bootloader.bin *.o kernel.bin frsTKernel.tmp finalBoot.bin
cd ..