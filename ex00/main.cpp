#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	for (int i = 1; argc > i; i ++){
		ScalarConverter::convert(argv[i]);
	}
}
