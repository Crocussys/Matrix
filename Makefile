all: main.o matrix.o
	g++ main.o matrix.o -o Matrix
	
main.o: main.cpp
	g++ -c main.cpp
	
matrix.o: matrix.cpp
	g++ -c matrix.cpp
	
clean:
	rm -rf *~ *.o