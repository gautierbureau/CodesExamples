CCX = clang++
LD = clang++
LIB_DIR =
LIB =
INCLUDE_DIR =

# CXXFLAG=-O3 -std=c++1y -g -Weverything -Wall -DNDEBUG -std=c++11 -O3
# W = warnings
# -g = symbol de debug
# -O = optimisation du code par le compilateur
# -D = macro
CXXFLAGS = -std=c++14 -fPIC #-stdlib=libstdc++
LDFLAGS = -dynamiclib -current_version 1.0 -compatibility_version 1.0 

LIBRARY = lib/liblibrary1.dylib

SRC = Foo.cpp Faa.cpp

OBJ = $(SRC:.cpp=.o)

all: $(LIBRARY)
		
$(LIBRARY): $(OBJ)
	mkdir -p lib;
	$(LD) $(LDFLAGS) $(OBJ) -o $(LIBRARY)

%.o: %.cpp
	$(CCX) -o $@ -c $(CXXFLAGS) $(INCLUDE_DIR) $^
	
	
clean:
	rm *.o $(EXEC)
	