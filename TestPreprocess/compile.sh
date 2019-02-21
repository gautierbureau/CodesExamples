#!/bin/bash

# Object and the binary in 2 commands with -v options to see the steps
# g++ -c main.cpp -o main.o -v
# g++ main.o -o main -v 

# Preprocess output
g++ -E main.cpp -o main.ii

# Compile -> Assembly output
g++ -S main.ii  -o main.s
# g++ main.ii -S  -masm=intel -o main.s

# Assenmle -> object file
g++ -c main.s -o main.o
as main.s -o main.o
# nasm -f macho64 main.s -o main.o
# as assembler gnu et nasm un autre

# Link
g++ main.o -o main
# ld main.o -o main

# On mac it is special
ld -o main  main.o -lSystem
ld -dynamic -arch x86_64 -macosx_version_min 10.13.0 -o main main.o -lSystem
ld -o main main.o -lSystem -lstdc++

# Full from -v option
# ld -dynamic -arch x86_64 -macosx_version_min 10.13.0 -weak_reference_mismatches non-weak -o main -L/usr/local/lib/gcc/x86_64-apple-darwin17.5.0/8.1.0 -L/usr/local/lib/gcc/x86_64-apple-darwin17.5.0/8.1.0/../../.. main.o -lstdc++ -no_compact_unwind -lSystem -lgcc_ext.10.5 -lgcc -lSystem

# To have the ii s and o files and the binary
g++ -save-temps main.cpp

# https://www.thegeekstuff.com/2017/01/gnu-binutils-commands/
# https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
# https://jameshfisher.com/2017/02/20/macos-assembly-hello-world.html