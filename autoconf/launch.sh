#!/bin/bash

aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure CC=clang # Generate Makefile from Makefile.in
CC=clang make distcheck # Use Makefile to build and test a tarball to distribute
