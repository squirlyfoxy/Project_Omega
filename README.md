# Project Omega
[![CodeFactor](https://www.codefactor.io/repository/github/squirlyfoxy/project_omega/badge/master?s=90de48178d3300c5523d37fc6a04a96a0c986420)](https://www.codefactor.io/repository/github/squirlyfoxy/project_omega/overview/master)

"Project Omega" is a 64 bit hobby operating system developed by a youngh student who doesn't know what to do with his life. Don't be afraid to criticize, any criticism / advice will be well accepted and applied to improve the project.

## How To build?

To compile just run the "build.bat" script from a windows pc, to do this you will need some installed programs and a WSL distribution (Windows Subsystem For Linux).
The programs you will need to have are:
* NASM (Installed on windows)
* Python (Installed on windows)
* GCC-x86_64-elf cross compiler (Installed on WSL)
* CMAKE (Installed on WSL)

To build just run "build.bat", the magic of scripts will do everything for you!

## Fetures

* CPU

   * [x] <b>CPUID</b>
   * [ ] <b>MSR</b>
   * [x] <b>CMOS</b>
   * [ ] <b>RTC</b>

* Drivers

   * [x] <b>COM1 Driver (For Debugging)</b>
   * [x] <b>80x35 VGA Driver</b>
   * [x] <b>Keyborad Basic Driver</b>
   * [x] <b>Floppy Disk Controller (In Development)</b>
   
* File System
   * [ ] <b>PrOFS (Project Omega File System), in development</b>
   * [ ] <b>FAT</b>

* Memory Management

   * [x] <b>GDT</b>
   * [x] <b>IDT</b>
   * [x] <b>free</b>
   * [x] <b>malloc</b>
   * [x] <b>realloc</b>
   * [x] <b>memmove</b>
   * [x] <b>memcpy</b>
   * [x] <b>memset</b>
   
* Bootloader
   * [x] <b>Custom Homemade Bootloader</b>
   * [x] <b>Multiboot v.1 Support</b>
