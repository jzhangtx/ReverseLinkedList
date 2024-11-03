ReverseLinkedList: ReverseLinkedList.o
	g++ -g -o ReverseLinkedList.exe ReverseLinkedList.o -pthread    

ReverseLinkedList.o: ReverseLinkedList/ReverseLinkedList.cpp
	g++ -g  -c -pthread ReverseLinkedList/ReverseLinkedList.cpp
