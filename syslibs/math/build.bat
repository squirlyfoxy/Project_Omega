@echo off

echo Building math.o library

cd ./math

ubuntu run gcc -c omath.cpp -o ../../out/syslib/omath.o