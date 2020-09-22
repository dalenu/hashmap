/*
 *     ECE250
 *     classes.h
 *     Purpose: Class declarations for deque data structure
 *
 *     Author Russell Hassan (rkdhassa)
 *     Version 1.0  - 14/02/2020
 */

class deque_empty{};

class Node {
public:
	unsigned long key;
        std::string data;
        Node(unsigned long identify, std::string input, int side, Node* point);
	Node* prev;
        Node* next;
};

class Deque {
public:
        Node* first;
        Node* last;
        int amount;
        Deque();
        ~Deque();
        int enqueue_front(unsigned long j, std::string i);
        int enqueue_back(unsigned long j, std::string i);
       	int clear();
        int empty();
        int size();
	void search(unsigned long lookup, int hash);
	int deletekey(unsigned long lookup);
	int insert(unsigned long lookup, std::string input);
        int print();
};
