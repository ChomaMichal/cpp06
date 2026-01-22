#pragma once
#include <string>

class ScalarConverter {
public:
  static void convert(const std::string str);

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &obj);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &obj);
};
