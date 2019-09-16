#!/bin/bash

g++ -c -g -O0 -std=c++98 -pedantic -pedantic-errors -D_GLIBCXX_USE_CXX11_ABI=0 main.cpp -o main_std98.o
g++ -c -g -O0 -std=c++11 main.cpp -o main_std11.o

g++ main_std98.o -o main_std98

nm -C main_std98.o > symbols_cpp98
nm -C main_std11.o > symbols_cpp11

# readelf -Ws main_std98

# scp main_std98 gautbure@grovsla6:/home/gautbure/test

# https://stackoverflow.com/questions/12606713/enforcing-the-c98-standard-in-gcc
# https://stackoverflow.com/questions/33394934/converting-std-cxx11string-to-stdstring
