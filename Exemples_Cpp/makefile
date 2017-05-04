all : main 

main.o : main.cc addition.h
	g++ -c main.cc 

addition.o : addition.cc addition.h
	g++ -c addition.cc

change.o : change.cc change.h
	g++ -c change.cc

Personnage.o : Personnage.cc Personnage.h
	g++ -c Personnage.cc

Duree.o : Duree.cc Duree.h
	g++ -c Duree.cc

main : main.o addition.o change.o Personnage.o Duree.o
	g++ -o main.out main.o addition.o change.o Personnage.o Duree.o

clean :
	rm *.o *.out		
