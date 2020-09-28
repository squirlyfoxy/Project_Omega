PROJDIRS := ../kernel
SRCFILES := $(wildcard $(PROJDIRS)/*.cpp)
LIB_PATH := ../out

all: kernel.bin

kernel.bin: $(SRCFILES)
	$$HOME/opt/cross/bin/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c $< $(LIB_PATH)