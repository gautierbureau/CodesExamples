CCX = clang++
LD = ar
LIB_DIR =
LIB =
INCLUDE_DIR =

# CXXFLAG=-O3 -std=c++1y -g -Weverything -Wall -DNDEBUG -std=c++11 -O3
# W = warnings
# -g = symbol de debug
# -O = optimisation du code par le compilateur
# -D = macro
CXXFLAGS = -std=c++11
LDFLAGS = rcs

LIBRARY = lib/liblibrary2.a

SRC = Fee.cpp

OBJ = $(SRC:.cpp=.o)

all: $(LIBRARY)
		
$(LIBRARY): $(OBJ)
	mkdir lib;
	$(LD) $(LDFLAGS) $(LIBRARY) $(OBJ)

%.o: %.cpp
	$(CCX) -o $@ -c $(CXXFLAGS) $(INCLUDE_DIR) $^
	
	
clean:
	rm *.o $(EXEC)
	