#include "io.hpp"
#include <iostream>
#include <iomanip>

namespace common {

void clear()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

std::string underline(std::string text, char symbol)
{
	std::stringstream ss;
	ss << text << std::endl;
	for (size_t i = 0; i < text.length(); ++i)
		ss << symbol;
	ss << std::endl;
	return ss.str();
}

void pause()
{
	// Wait for user to continue
	std::cin.get();
	std::cin.get();
}

std::string dual_string(int number, bool padded)
{
	std::stringstream ss;
	ss << "0b";
	if (padded) {
		size_t length = sizeof(number) * 8;
		for (size_t i = 0; i < length; ++i) {
			int index = length - 1 - i;
			int bit = number & (1 << index);
			ss << (bit ? '1' : '0');
		}
	} else {
		detail::dual_string_recursive(number, ss);
	}
	return ss.str();
}

int read_dual(std::string label)
{
	int result;
	bool fail;
	do {
		fail = false;
		// Read standard input
		std::cin.clear();
		std::cout << label << " 0b";
		std::string input;
		std::cin >> input;
		// Check if input doesn't fit into int
		if (0 < input.length() && input.length() > sizeof(int)* 8) {
			fail = true;
			continue;
		}
		// Parse string and set bit of integer on one
		result = (input.at(0) == '1') ? 1 : 0;
		for (size_t i = 1; i < input.length(); ++i) {
			result <<= 1;
			if (input.at(i) == '1') {
				result |= 1;
			} else if (input.at(i) != '0') {
				fail = true;
				break;
			}
		}
	} while (fail);
	return result;
}

int read_decimal(std::string label)
{
	// Read until good
	int input;
	do {
		std::cin.clear();
		std::cout << label << " ";
		std::cin >> input;
	} while(std::cin.fail());
	return input;
}

namespace detail {

void dual_string_recursive(int number, std::stringstream &ss)
{
	if (number) {
		dual_string_recursive(number >> 1, ss);
		ss << (number & 1);
	}
}

} // namespace detail

} // namespace common
