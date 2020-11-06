@echo off

if "%1" == "box" (
    VirtualBoxVM --startvm Omega
    exit
)

if "%1" == "qemu" (
    qemu-system-x86_64 .\out\floppy.img
    exit
)
