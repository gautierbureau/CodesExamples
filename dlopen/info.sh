#!/bin/bash
ldd -r Model.so
readelf -d Model.so # same as ldd
objdump -t Model.so | c++filt
readelf -Ws Model.so | c++filt
nm -C Model.so

# dwarfdump
# abi-dumper

# https://stackoverflow.com/questions/34732/how-do-i-list-the-symbols-in-a-so-file
# http://nickdesaulniers.github.io/blog/2016/08/13/object-files-and-symbols/
# http://nickdesaulniers.github.io/blog/2016/11/20/static-and-dynamic-libraries/
