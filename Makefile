all: openhttest orderedhttest

openhttest: openhttest.cpp secondaryhash.cpp
	g++ -std=c++11 -o openhttest openhttest.cpp

orderedhttest: orderedhttest.cpp orderedhash.cpp deque.cpp deque.h
	g++ -std=c++11 -o orderedhttest orderedhttest.cpp

clean:
	rm openhttest
	rm orderedhttest
