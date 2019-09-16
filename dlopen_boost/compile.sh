#!/bin/bash

if [ -z "$1" ]; then
  echo "You need to give build or clean as argument."
  exit 1
fi

# FLAGS="-std=c++98"
FLAGS=

if [ "$1" = "build" ]; then
  g++ -c $FLAGS -g -O0 -fPIC ModelImpl.cpp -o ModelImpl.o
  g++ -c $FLAGS -g -O0 -fPIC Model.cpp -o Model.o
  g++ -shared Model.o ModelImpl.o -ldl -pthread -o Model.so
  g++ -c $FLAGS -g -O0 -fPIC Factory.cpp -o Factory.o
  g++ -c $FLAGS -g -O0 main.cpp -o main.o
  g++ Factory.o Model.o main.o -ldl -o main
elif [ "$1" = "clean" ]; then
  rm -f *.o
  rm -f *.so
  rm -f vgcore*
  if [ -f "main" ]; then rm main; fi
else
  echo "Nothing."
fi
