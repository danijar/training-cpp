#include "arrays_and_strings.hpp"

namespace datastructures {
namespace arrays_and_strings {

void remove_duplicate_chars(std::string &string)
{
	size_t removed = 0;
	// Loop over string by current and last letter
	for (size_t i = 1; i < string.length(); ++i) {
		char current = string.at(i);
		char last = string.at(i - 1);
		// Found duplicate
		if (current == last) {
			// Copy letters from here one position to the left
			for (size_t j = i; j < string.length(); ++j)
				string[j] = string[j - 1];
			removed++;
		}
	}
	// Free memory at the end
	string.resize(string.size() - removed);
}

} // namespace arrays_and_strings
} // namespace datastructures
