#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
public:
	static uintptr_t serialize(const Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(Serializer& obj);
  ~Serializer();
  Serializer& operator=(Serializer& obj);
};
