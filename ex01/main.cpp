#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data hehe;
	// hehe.power0 = 1;
	hehe.power1 = 1;
	// hehe.power2 = 1;
	hehe.power3 = 1;
	hehe.power4 = 1;
	// hehe.power5 = 1;
	hehe.power6 = 1;
	hehe.power7 = 1;
	std::cout << hehe;
	
	uintptr_t raw = Serializer::serialize(&hehe);
	Data *ptr = Serializer::deserialize(raw);

	if (ptr == &hehe)
		std::cout << "Pointers match!" << std::endl;
	std::cout << *ptr;
}
