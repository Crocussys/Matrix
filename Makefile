all: main.o
	g++ main.o -o Matrix
	
main.o: main.cpp
	g++ -c main.cpp
		
clean:
	rm -rf *~ *.o