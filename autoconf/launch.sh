#!/bin/bash

aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure CC=clang # Generate Makefile from Makefile.in
CC=clang make distcheck # Use Makefile to build and test a tarball to distribute

#https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install
#https://ftp.gnu.org/old-gnu/Manuals/autoconf-2.57/html_chapter/autoconf_13.html
#https://elinux.org/images/4/43/Petazzoni.pdf

# http://www-igm.univ-mlv.fr/~dr/XPOSE/Breugnot/

# http://www.idryman.org/blog/2016/03/10/autoconf-tutorial-1/
# http://www-igm.univ-mlv.fr/~dr/XPOSE/Breugnot/
# https://www.lrde.epita.fr/~adl/dl/autotools.pdf