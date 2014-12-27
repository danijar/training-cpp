#include "arrays_and_strings.hpp"
#include <unordered_set>

namespace puzzle {
namespace arrays_and_strings {

bool all_unique_chars(const std::string &string)
{
	std::unordered_set<char> letters;
	for (char letter : string) {
		if (letters.find(letter) != letters.end())
			return false;
		letters.insert(letter);
	}
	return true;
}

bool all_unique_chars_inplace(const std::string &string)
{
	for (size_t i = 0; i < string.length(); ++i)
		for (size_t j = i + 1; j < string.length(); ++j)
			if (string.at(i) == string.at(j))
				return false;
	return true;
}

} // namespace arrays_and_strings
} // namespace puzzle
