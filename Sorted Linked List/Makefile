main: main.o Data.o SortedLinkedList.o
	g++ -o main main.o Data.o SortedLinkedList.o

main.o: main.cpp Data.h SortedLinkedList.h
	g++ -c main.cpp

Data.o: Data.cpp Data.h
	g++ -c Data.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h
	g++ -c SortedLinkedList.cpp

clean:
	/bin/rm -f *.o
	/bin/rm -f main