#include <iostream>
#include <string>
#include "secondaryhash.cpp"

int main() {

        std::string line;
        Hashmap* map;
	map = nullptr;

        while(!std::cin.eof()) {
                getline(std::cin, line);
                int command_length;
                command_length = 1;
                std::string cmd;
                std::string params;
                cmd = line.substr(0, command_length);

                if(cmd == "n") {
                        int capacity = std::stoi(line.substr(command_length + 1));
                        if(map != nullptr) {
				delete map;
			}
                        map = new Hashmap(capacity);
                        std::cout << "success" << std::endl;
                } else if(cmd == "i") {
                        std::string params = line.substr(command_length + 1);
                        command_length = params.find(";");
                        unsigned long number = std::stoul(params);
                        std::string caller = params.substr(command_length + 1);
                        if(map->insert(number, caller)) {
                                std::cout << "failure" << std::endl;
                        } else {
                                std::cout << "success" << std::endl;
                        }
                } else if(cmd == "s") {
                        unsigned long number = std::stoul(line.substr(command_length + 1));
                        map->search(number);
                } else if(cmd == "d") {
                        unsigned long number = std::stoul(line.substr(command_length + 1));
                        if(map->deletekey(number)) {
                                std::cout << "failure" << std::endl;
                        } else {
                                std::cout << "success" << std::endl;
                        }
                }
        }
}
