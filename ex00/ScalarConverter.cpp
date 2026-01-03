#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>

static bool safe_atod(const char* str, double& out) {
	errno = 0;
	char* end;

	double val = std::strtod(str, &end);

	if (errno == ERANGE)
		return false;

	if (*end != '\0'){
		return false;
	}

	out = val;
	return true;
}

static bool safe_atof(const char* str, float& out) {
	errno = 0;
	char* end;

	float val = std::strtof(str, &end);

	if (errno == ERANGE)
		return false;

	if (*end != '\0')
		return false;

	out = val;
	return true;
}

static bool safe_atoi(const char* str, int& out) {
	errno = 0;
	char* end;

	long val = std::strtol(str, &end, 10);

	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
		return false;

	if (*end != '\0')
		return false;

	out = static_cast<int>(val);
	return true;
}

static void char_converter(const std::string str){
		std::cout << "char: ";
		int		num = - 1;
		if (safe_atoi(str.c_str(), num) == false
				|| num < CHAR_MIN || num > CHAR_MAX){
			std::cout << "impossible\n";
		}
		else if (std::isprint(num) == 0){
			std::cout << "Unprintable\n";
		}
		else{
			std::cout << static_cast<char>(num) << "\n";
		}
}

static void int_converter(const std::string str){
		std::cout << "int: ";
		int		num;
		if (safe_atoi(str.c_str(), num) == false){
			std::cout << "impossible\n";
		}
		else{
			std::cout << static_cast<int>(num) << "\n";
		}
}

static void float_converter(const std::string str){
		std::cout << "float: ";
		float	num;
		if (str == "-inff"){
			std::cout << "-inff\n";
		}
		else if (str == "+inff"){
			std::cout << "+inff\n";
		}
		else if (str == "inff"){
			std::cout << "inff\n";
		}
		else if (safe_atof(str.c_str(), num) == false){
			std::cout << "impossible\n";
		}
		else{
			std::cout << num << "f\n";
		}
}

static void double_converter(const std::string str){
		std::cout << "double: ";
		double num;
		if (safe_atod(str.c_str(), num) == false){
			std::cout << "impossible" << std::endl;
		}
		else{
			std::cout << num << std::endl;
		}
}

void ScalarConverter::convert(const std::string str){
	char_converter(str);
	int_converter(str);
	float_converter(str);
	double_converter(str);
}



ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(ScalarConverter& other){
	*this = other;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& obj){
	return (obj);
}
