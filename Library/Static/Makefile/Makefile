CCX = clang++
LD = clang++
LIB_DIR = -L/Users/gautier/Codes/CodeExamples/Library/Static/Makefile/Library1/lib -L/Users/gautier/Codes/CodeExamples/Library/Static/Makefile/Library2/lib
LIB = -llibrary1 -llibrary2
INCLUDE_DIR = -I/Users/gautier/Codes/CodeExamples/Library/Static/Makefile/Library1 -I/Users/gautier/Codes/CodeExamples/Library/Static/Makefile/Library2

# CXXFLAG=-O3 -std=c++1y -g -Weverything -Wall -DNDEBUG -std=c++11 -O3
# W = warnings
# -g = symbol de debug
# -O = optimisation du code par le compilateur
# -D = macro
CXXFLAGS =-std=c++11
LDFLAGS =

EXEC = main

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)
		
$(EXEC): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(EXEC) $(LIB_DIR) $(LIB) 

%.o: %.cpp
	$(CCX)  -o $@ -c $(CXXFLAGS) $(INCLUDE_DIR) $^
	
clean:
	rm *.o $(EXEC)
	