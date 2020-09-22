/*
 *     ECE250
 *     deque.cpp
 *     Purpose: Class function definitions for deque data structure
 *
 *     Author Russell Hassan (rkdhassa)
 *     Version 1.0  - 31/01/2020
 **/

//Node Constructor. Node data is set to input and one of next/prev is set to point
////(depending which side the node is inserted in the deque)
Node::Node(unsigned long identify, std::string input, int side, Node* point) {
	key = identify;
        data = input;
        if(side == 0) {
                prev = nullptr;
                next = point;
        } else {
                prev = point;
                next = nullptr;
        }
}

//Node uses default destructor, which deletes all pointers and primitive data
////contained by the object

//Deque constructor. Creates an empty deque with size 0 and no inserted nodes on
////either side
Deque::Deque() {
        first = nullptr;
        last = nullptr;
        amount = 0;
}

//Deque destructor. Runs clear function, which deletes all nodes between first
////and last. Primitive data int amount is automatically taken care of
Deque::~Deque() {
        clear();
}

//Creates a new node with key j and data i, and inserts it into first. The previous first
////node has prev set to the new node. If deque is empty, new node is both first
////and last
int Deque::enqueue_front(unsigned long j, std::string i) {
        Node* temp = new Node(j, i, 0, first);
        if(first == nullptr) {
               first = temp;
                last = temp;
        } else {
                first->prev = temp;
                first = temp;
        }
        amount += 1;
        return 0;
}

//Does the same as enqueue_front, but replaces the last node instead
int Deque::enqueue_back(unsigned long j, std::string i) {
        Node* temp = new Node(j, i, 1, last);
        if(last == nullptr) {
                first = temp;
                last = temp;
        } else {
                last->next = temp;
                last = temp;
        }
        amount += 1;
        return 0;
}

//Traverses through every node in the array starting from first and deletes it, then
////sets first and last to nullptr and sets size to 0 (to create an empty deque)
int Deque::clear() {
        if(first == nullptr) {
                return 0;
        }
        Node* temp = first;
        while(temp != nullptr) {
                temp = temp->next;
                delete first;
                first = temp;
        }
        last = nullptr;
        amount = 0;
        return 0;
}

//Searches list for a node with key and prints the data. If the key is not found,
//prints "not found"
void Deque::search(unsigned long lookup, int hash) {
	if(first == nullptr) {
		std::cout << "not found" << std::endl;
	} else {
		Node* temp = first;
		bool found = 0;
		std::string caller;
		
		while(temp != nullptr) {
			if(temp->key == lookup) {
				caller = temp->data;
				found = 1;
				temp = nullptr;
			} else {
				temp = temp->next;
			}
		}

		if(found) {
			std::cout << "found " << caller << " in " << hash << std::endl;
		} else {
			std::cout << "not found" << std::endl;
		}
	} 
}

//Searches list for a node with key and deletes that node. If the key is not found, fails
int Deque::deletekey(unsigned long lookup) {
	if(first == nullptr) {
		return 1;
	} else {
		Node* temp = first;

		while(temp != nullptr) {
			if(temp->key == lookup) {
				amount -= 1;
				if(first == temp) {
					if(temp->next == nullptr) {
						first = nullptr;
						last = nullptr;
						delete temp;
						return 0;
					} else {
						first = temp->next;
						first->prev = nullptr;
						delete temp;
						return 0;
					}
				} else if(last == temp) {
					last = temp->prev;
					last->next = nullptr;
					delete temp;
					return 0;
				} else {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
					return 0;
				}
			}
			temp = temp->next;

		}

		return 1;
	}
}

int Deque::insert(unsigned long lookup, std::string input) {
	if(first == nullptr) {
		enqueue_back(lookup, input);
		return 0;
	} else {
		Node* temp = first;
		int flag = 0;
		
		if(temp->key > lookup) {
			enqueue_front(lookup, input);
			return 0;
		}

		while(temp != nullptr) {
			if(temp->next != nullptr) {
				if(temp->next->key > lookup) {
					flag = 1;
				}
			}	
			if(temp->key == lookup) {
				return 1;
			}
			if(flag == 1) {
				temp->next = new Node(lookup, input, 0, temp->next);
				temp->next->prev = temp;
			} else {
				temp = temp->next;
			}
		}

		enqueue_back(lookup, input);
		return 0;
	}
}

int Deque::print() {
	if(first == nullptr) {
		return 0;
	}

	Node* temp = first;

	while(temp != nullptr) {
		std::cout << temp-> key;
		if(temp->next == nullptr) {
			std::cout << std::endl;
			return 0;
		} else {
			std::cout << " ";
			temp = temp->next;
		}
	}
	return 0;
}
