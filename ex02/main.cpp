#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void){
	std::srand(time(0));
	int i = std::rand() % 3;
	
	switch (i){
		case 0:
			return(new A);
			break;
		case 1:
			return(new B);
			break;
		case 2:
			return(new C);
			break;
	}
	return (new A);
}

void	identify(Base* p){
	std::cout << *((char*)p + 8) << std::endl;
}

void	identify(Base& p){
	A a = p;
	std::cout << a.type << std::endl;
}

int main(){
	Base *idk = generate();
	identify(idk);
	identify(*idk);
}
