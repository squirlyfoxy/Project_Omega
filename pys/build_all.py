#The following script will automate the building process

import os, shutil

boot_str = "../src/bootloader/"
kernel_str = "../src/kernel/"
out_str = "../out/"

print("=| Project Omega Builder |=")
print("BOOTLOADER Path: ", boot_str)
print("KERNEL Path: ", kernel_str)
print("OUTPUT BINARYES Path: ", out_str)

print("Cleaning output folder")
os.chdir(out_str)
os.system("del /F /Q *")

# Per prima cosa individuiamo il nostro obbiettivo: automatizzare il build del SO rendendolo scalabile a prossimi updates
# Prima cosa da fare (per poter eseguire kpt.py) è procedere con il build del kernel
print("Building Kernel: ")
# Building Stage 1 (Assemblies)
print("- Building stage 1, Assemblies: ....")
os.system("nasm -i " + boot_str + "include " + boot_str + "kernel_entry/64_32mod.asm -f elf64 -o " + out_str + "k1.o")
print("- OK Stage 1")

# Building Stage 2 (C++)
print("- Building stage 2, C++: ....")

os.system("ubuntu run export cc=$HOME/opt/cross/bin/x86_64-elf-gcc")
os.system("ubuntu run export cxx=$HOME/opt/cross/bin/x86_64-elf-gcc")
os.system("ubuntu run cmake ../CMakeLists.txt -G 'Unix Makefiles'")
os.chdir("../")
os.system("ubuntu run make -f 'Makefile'")

print("- OK Stage 2")

# Executing kpt.py
os.chdir("pys")
print("- Executing kpt.py")
os.system("py kpt.py")

print("- OK Parent Stage")

# Build bootloader
assembly_to_build = boot_str + "bootloader.asm"

print("Building bootloader: ....")
os.system("nasm -i " + boot_str + "include " + boot_str + "bootloader.asm -f bin -o " + out_str + "bootloader.bin")
print("- OK Parent Stage")

print("Creating Kernel file: ....")
os.chdir(out_str)
os.system('copy /B /Y "bootloader.bin"+"kernel.bin" "boot.bin"')
print("- OK")

os.system("del bootloader.bin *.o kernel.bin kentry.bin")
os.chdir("../")