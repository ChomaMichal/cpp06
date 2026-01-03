#pragma once
#include <iostream>

class Data {
public:
	Data();
	Data(const Data& obj);
	~Data();
	Data&	operator=(const Data& obj);

	bool power0;
	bool power1;
	bool power2;
	bool power3;
	bool power4;
	bool power5;
	bool power6;
	bool power7;
private:
};

std::ostream& operator<<(std::ostream& os, const Data& data);
