#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

static bool parseDouble(const std::string &str, double &out) {
  errno = 0;
  char *end;

  double val = std::strtod(str.c_str(), &end);

  if (errno == ERANGE)
    return false;

  if (str == "-inf" || str == "-inff")
    val = -1.0 / 0.0;
  else if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    val = 1.0 / 0.0;
  else if (str == "nan" || str == "nanf")
    val = 0.0 / 0.0;
  else if (*end != '\0' && !(*end == 'f' || *end == 'F'))
    return false;

  out = val;
  return true;
}

static void printChar(double val) {
  std::cout << "char: ";

  if (val != val || val < CHAR_MIN || val > CHAR_MAX) {
    std::cout << "impossible\n";
    return;
  }

  int int_val = static_cast<int>(val);
  if (int_val < CHAR_MIN || int_val > CHAR_MAX) {
    std::cout << "impossible\n";
    return;
  }

  if (std::isprint(int_val) == 0) {
    std::cout << "Non displayable\n";
  } else {
    std::cout << static_cast<char>(int_val) << "\n";
  }
}

static void printInt(double val) {
  std::cout << "int: ";

  if (val != val || val > INT_MAX || val < INT_MIN) {
    std::cout << "impossible\n";
    return;
  }

  std::cout << static_cast<int>(val) << "\n";
}

static void printFloat(double val) {
  std::cout << "float: ";

  if (std::isnan(val)) {
    std::cout << "nanf\n";
  } else if (std::isinf(val) && val > 0) {
    std::cout << "+inff\n";
  } else if (std::isinf(val) && val < 0) {
    std::cout << "-inff\n";
  } else {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << val;
    std::cout << oss.str() << "f\n";
  }
}

static void printDouble(double val) {
  std::cout << "double: ";

  if (val != val) {
    std::cout << "nan\n";
  } else if (val > 0 && val == (1.0 / 0.0)) {
    std::cout << "+inf\n";
  } else if (val < 0 && val == -(1.0 / 0.0)) {
    std::cout << "-inf\n";
  } else {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << val;
    std::cout << oss.str() << "\n";
  }
}

void ScalarConverter::convert(const std::string str) {
  double value;

  if (!parseDouble(str, value)) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
    return;
  }

  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
  *this = obj;
  return (*this);
}
