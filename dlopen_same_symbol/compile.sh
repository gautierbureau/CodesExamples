#!/bin/bash

if [ -z "$1" ]; then
  echo "You need to give build or clean as argument."
  exit 1
fi

# FLAGS="-std=c++98"
FLAGS=

if [ "$1" = "build" ]; then
  gcc -c $FLAGS -g -O0 -fPIC foo1.c -o foo1.o
  gcc -c $FLAGS -g -O0 -fPIC foo2.c -o foo2.o
  gcc -shared foo1.o -o foo1.so
  gcc -shared foo2.o -o foo2.so
  g++ -c $FLAGS -g -O0 main.cpp -o main.o
  g++ main.o -ldl -o main
  # g++ -c $FLAGS -g -O0 -fPIC ModelImpl.cpp -o ModelImpl.o
  # g++ -c $FLAGS -g -O0 -fPIC Model.cpp -o Model.o
  # g++ -shared Model.o ModelImpl.o -ldl -pthread -o Model.so
  # g++ -c $FLAGS -g -O0 -fPIC Factory.cpp -o Factory.o
elif [ "$1" = "clean" ]; then
  rm -f *.o
  rm -f *.so
  rm -f vgcore*
  if [ -f "main" ]; then rm main; fi
else
  echo "Nothing."
fi
