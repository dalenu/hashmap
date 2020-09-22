class Entry {
public:
	unsigned long key;
	std::string data;
	Entry();
};

Entry::Entry() {
	key = 0;
	data = "";
}

class Hashmap {
public:
	int size;
	Entry* table;
	int count;
	int hash2(unsigned long i);
	int insert(unsigned long lookup, std::string caller);
	Hashmap(int i);
	~Hashmap();
	int search(unsigned long lookup);
	int deletekey(unsigned long lookup);
};

int Hashmap::hash2(unsigned long i) {
	unsigned long hash = (i / size) % size;
	if(hash % 2 == 0) {
		hash++;
	}
	return hash;
}

int Hashmap::insert(unsigned long lookup, std::string caller) {
	if(count == size) {
		return 1;
	}
	int probe = lookup % size;
	int offset = hash2(lookup);
	while(true) {
		if(table[probe].key == lookup) {
			return 1;
		} else if(table[probe].key == 0) {
			count++;
        		table[probe].key = lookup;
        		table[probe].data = caller;
        		return 0;
		} else {
			probe = (probe + offset) % size;
		}
	}
}

Hashmap::Hashmap(int i) {
	size = i;
	table = new Entry[i];
	count = 0;
}

Hashmap::~Hashmap() {
	delete table;
}

int Hashmap::search(unsigned long lookup) {
	int probe = lookup % size;
	int offset = hash2(lookup);
	for(int i = 0; i < size; i++) {
		if(table[probe].key == lookup) {
			std::cout << "found " << table[probe].data << " in " << probe << std::endl;
			return 0;
		}
		probe = (probe + offset) % size;
	}
	std::cout << "not found" << std::endl;
	return 1;
}

int Hashmap::deletekey(unsigned long lookup) {
	int probe = lookup % size;
	int offset = hash2(lookup);
	for(int i = 0; i < size; i++) {
		if(table[probe].key == lookup) {
			count--;
			table[probe].key = 0;
			table[probe].data = "";
			return 0;
		}
		probe = (probe + offset) % size;
	}
	return 1;
}
