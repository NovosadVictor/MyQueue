




all: prog

prog: MyQueue.o main.o MyList.o
	g++ MyQueue.o main.o MyList.o -o prog

MyQueue.o: MyQueue.h
	g++ -c MyQueue.h

main.o: main.cpp MyQueue.h MyList.h
	g++ -c main.cpp

MyList.o: MyList.h
	g++ -c MyList.h  




clean:
	rm -f  *.o prog 
