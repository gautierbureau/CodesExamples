#!/bin/zsh
rm -rf build;
mkdir build;
cd build;
cmake ..;
#cmake .. -DCMAKE_INSTALL_PREFIX=../;
#cmake .; # Je ne sais pas a quoi sert cette ligne la
make; # make VERBOSE=true
#make VERBOSE=true
make install;

#cp bin/program ../; # avant que je fasse make install

## Ici je detruit tout et recompile tout 