#!/bin/bash

if [ -z "$1" ]; then
  echo "You need to give build or clean as argument."
  exit 1
fi

if [ "$1" = "build" ]; then
  g++ -c -g -O0 -fPIC Singleton.cpp -o Singleton.o
  ar -cq libsingleton.a Singleton.o
  g++ -c -g -O0 -fPIC foo.cpp -o foo.o
  ar -cq libfoo.a foo.o
  g++ -c -g -O0 -fPIC ModelImpl.cpp -o ModelImpl.o
  g++ -c -g -O0 -fPIC Model.cpp -o Model.o
  g++ -shared Model.o ModelImpl.o -ldl libfoo.a -o Model.so
  g++ -c -g -O0 -fPIC Factory.cpp -o Factory.o
  g++ -c -g -O0 main.cpp -o main.o
  g++ Factory.o Model.o main.o -ldl libsingleton.a libfoo.a -rdynamic -o main
elif [ "$1" = "clean" ]; then
  rm -f *.o
  rm -f vgcore*
  rm -f *.so
  rm -f *.a
  if [ -f "main" ]; then rm main; fi
else
  echo "Nothing."
fi
