import os, shutil

print("")
print("*************************************")
print("   Project Omega Iso Builder v.1.0   ")
print("*************************************")
print("")
print("Prerequisites: dd")
print("The following generates a .img 1440kb file")
print("")

out_str = "../out/"

#TODO: Create the FS into the output iso
os.chdir(out_str)
os.system("ubuntu run dd if=/dev/zero of=floppy.img bs=1024 count=1440 ")
os.system("ubuntu run dd if=boot.bin of=floppy.img seek=0 count=1200 conv=notrunc")

