#include "A.hpp"
#include <cstring>
#include <iostream>

A::A(){
	this->type = 'A';
}

A::A(Base &base){
	std::memcpy(&this->type, (char *)&base + 8,  sizeof(char));
}
