CCX = g++
LD = g++
LIB_DIR =
LIB =
INCLUDE_DIR =

CXXFLAGS = -O3 -g -Wall
# W = warnings
# -g = symbol de debug
# -O = optimisation du code par le compilateur
# -D = macro
#CXXFLAGS = -std=c++1
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
	