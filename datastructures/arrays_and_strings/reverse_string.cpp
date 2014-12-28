#include "arrays_and_strings.hpp"
#include <cstring>

namespace datastructures {
namespace arrays_and_strings {

void reverse_string(std::string &string)
{
	// Excercise is to reverse a C string, so convert first
	size_t length = string.length();
	char *buffer = new char[length + 1];
	buffer[length] = '\0';
	for (size_t i = 0; i < length; ++i)
		buffer[i] = string.at(i);
	// Reverse chars except terminator
	for (size_t i = 0; i < length / 2; ++i) {
		char tmp = buffer[i];
		buffer[i] = buffer[length - 1 - i];
		buffer[length - 1 - i] = tmp;
	}
	// Store result back to the string object
	string = buffer;
}

} // namespace arrays_and_strings
} // namespace datastructures
