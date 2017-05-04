# I need a normal mode for objdump
# I need a debug mode flag for gdb

CCX = g++
LD = g++
LIB_DIR =
LIB =
INCLUDE_DIR =

# CXXFLAG=-O3 -std=c++1y -g -Weverything -Wall -DNDEBUG -std=c++11 -O3
# W = warnings
# -g = symbol de debug
# -O = optimisation du code par le compilateur
# -D = macro
CXXFLAGS = 
LDFLAGS =

EXEC = main

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(EXEC)
		
$(EXEC): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(EXEC) $(LIB_DIR) $(LIB) 

%.o: %.cpp
	$(CCX) -o $@ -c $(CXXFLAGS) $(INCLUDE_DIR) $^

EXEC_DEBUG = main_debug

OBJ_DEBUG = main_debug.o
	
debug: $(EXEC_DEBUG)

$(EXEC_DEBUG): $(OBJ_DEBUG)
	$(LD) $(LDFLAGS) $(OBJ_DEBUG) -o $(EXEC_DEBUG) $(LIB_DIR) $(LIB) 

main_debug.o: main.cpp
	$(CCX) -o $@ -c $(CXXFLAGS) -g $(INCLUDE_DIR) $^	
	
clean:
	rm *.o $(EXEC) $(EXEC_DEBUG)
	