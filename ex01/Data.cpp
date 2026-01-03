#include "Data.hpp"
#include <iostream>

Data::Data(){
	this->power0 = 0;
	this->power1 = 0;
	this->power2 = 0;
	this->power3 = 0;
	this->power4 = 0;
	this->power5 = 0;
	this->power6 = 0;
	this->power7 = 0;
}

Data::Data(const Data& other){
	this->power0 = other.power0;
	this->power1 = other.power1;
	this->power2 = other.power2;
	this->power3 = other.power3;
	this->power4 = other.power4;
	this->power5 = other.power5;
	this->power6 = other.power6;
	this->power7 = other.power7;
}

Data::~Data(){
}

Data& Data::operator=(const Data& obj){
	this->power0 = obj.power0;
	this->power1 = obj.power1;
	this->power2 = obj.power2;
	this->power3 = obj.power3;
	this->power4 = obj.power4;
	this->power5 = obj.power5;
	this->power6 = obj.power6;
	this->power7 = obj.power7;
	return (*this);
}


std::ostream& operator<<(std::ostream& os, const Data& data){
	os << "power0 = " << data.power0;
	os << "\npower1 = " << data.power1;
	os << "\npower2 = " << data.power2;
	os << "\npower3 = " << data.power3;
	os << "\npower4 = " << data.power4;
	os << "\npower5 = " << data.power5;
	os << "\npower6 = " << data.power6;
	os << "\npower7 = " << data.power7 << std::endl;
	return (os);
}
