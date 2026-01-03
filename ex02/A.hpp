#pragma once
#include "Base.hpp"

class A : public Base{
	public:
		char type;
		A();
		A(Base &base);
};
