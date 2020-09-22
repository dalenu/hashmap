#include "deque.h"
#include "deque.cpp"

class Hashmap {
public:
	int size;
	Deque** table;
	Hashmap(int i);
	~Hashmap();
	unsigned long hash(unsigned long key);
	int insertkey(unsigned long lookup, std::string data);
	int searchkey(unsigned long lookup);
	int remove(unsigned long lookup);
	void chainprint(int index);
};

Hashmap::Hashmap(int i) {
	table = new Deque*[i];
	for(int j = 0; j < i; j++) {
		table[j] = new Deque();
	}
	size = i;
}

Hashmap::~Hashmap() {
	for(int i = 0; i < size; i++) {
		delete table[i];
	}
}

unsigned long Hashmap::hash(unsigned long key) {
	return (key % size);
}

int Hashmap::insertkey(unsigned long lookup, std::string data) {
	Deque* temp = table[hash(lookup)];
	return temp->insert(lookup, data);
}

int Hashmap::searchkey(unsigned long lookup) {
	Deque* temp = table[hash(lookup)];
	temp->search(lookup, hash(lookup));
	return 0;
}

int Hashmap::remove(unsigned long lookup) {
	Deque* temp = table[hash(lookup)];
	return temp->deletekey(lookup);
}

void Hashmap::chainprint(int index) {
	Deque* temp = table[index];
	temp->print();
}
	
