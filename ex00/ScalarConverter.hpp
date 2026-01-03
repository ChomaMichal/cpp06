#pragma once
#include <string>

class ScalarConverter {
public:
	static void convert(const std::string str);

private:
  ScalarConverter();
  ScalarConverter(ScalarConverter& obj);
  ~ScalarConverter();
  ScalarConverter& operator=(ScalarConverter& obj);
};
