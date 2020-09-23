@echo off

echo Building bootloader:
:: Build bootloader
echo - Building Stage 1
nasm -i ./bootloader/include bootloader/booltoader.asm -f bin -o ./out/bootloader.bin
echo - Building Stage 2
nasm -i ./bootloader/include bootloader/Stage2/64_32mod.asm -f elf64 -o ./out/k1.o

:: Build kernel
echo Building kernel:
echo - Building Stage 1
wsl $HOME/opt/cross/bin/x86_64-elf-gcc  -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "kernel/kentry.cpp" -o "out/kentry.o"

echo Linking kernel:
echo - Linking Stage 1
wsl $HOME/opt/cross/x86_64-elf/bin/x86_64-elf-ld -T "linker.ld"

:: Generating KPT
echo Generating KPT bin file:

echo - Executing kpt.py:
py kpt.py

:: Bulding KPT
echo - Building KPT
nasm bootloader/kpt.asm -o out/kpt.o

:: Create system image
echo Creating system image:
cd out

echo - Combining Bootloader and KPT togheder
:: TODO: Combining KPT & bootloader togheder
copy /B /Y "bootloader.bin"+"kpt.o" "finalBoot.bin"

:: Combining files togheder togheder
echo - Combining files togheder
copy /B /Y "finalBoot.bin"+"kernel.bin" "boot.bin"
del bootloader.bin *.o kernel.bin frsTKernel.tmp finalBoot.bin kpt.o
cd ..