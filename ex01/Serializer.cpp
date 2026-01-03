#include "Serializer.hpp"

Data *Serializer::deserialize(size_t raw){
	Data	*rt = new Data;
	
	if (raw % 2 == 0)
		rt->power7 = false;
	else
		rt->power7 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power6 = false;
	else
		rt->power6 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power5 = false;
	else
		rt->power5 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power4 = false;
	else
		rt->power4 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power3 = false;
	else
		rt->power3 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power2 = false;
	else
		rt->power2 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power1 = false;
	else
		rt->power1 = true;
	raw = raw >> 1;
	if (raw % 2 == 0)
		rt->power0 = false;
	else
		rt->power0 = true;
	return (rt);
}

uintptr_t Serializer::serialize(const Data* ptr){
	uintptr_t rt = 0;

	if (ptr->power0 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power1 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power2 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power3 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power4 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power5 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power6 == true)
		rt ++;
	rt = rt << 1;
	if (ptr->power7 == true)
		rt ++;
	return (rt);
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
