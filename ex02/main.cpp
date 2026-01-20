#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  std::srand(time(0));
  int i = std::rand() % 3;

  switch (i) {
  case 0:
    return (new A);
    break;
  case 1:
    return (new B);
    break;
  case 2:
    return (new C);
    break;
  }
  return (new A);
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (...) {
    std::cerr << "Failed to cast" << std::endl;
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (...) {
    std::cerr << "Failed to cast" << std::endl;
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (...) {
    std::cerr << "Failed to cast" << std::endl;
  }
}

int main() {
  Base *idk = generate();
  identify(idk);
  identify(*idk);
  delete idk;
}
