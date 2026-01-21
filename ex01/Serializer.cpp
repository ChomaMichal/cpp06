#include "Serializer.hpp"

uintptr_t Serializer::serialize(const Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}



Serializer::Serializer(){
}

Serializer::Serializer(Serializer& other){
	*this = other;
}

Serializer::~Serializer(){
}

Serializer& Serializer::operator=(Serializer& obj){
	return (obj);
}
