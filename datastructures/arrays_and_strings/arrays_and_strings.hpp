#ifndef ARRAYS_AND_STRINGS_HPP
#define ARRAYS_AND_STRINGS_HPP

#include <string>
#include "../../common/menu.hpp"

namespace datastructures {
namespace arrays_and_strings {

common::Menu menu();
bool all_unique_chars(const std::string &string);
bool all_unique_chars_inplace(const std::string &string);
void reverse_string(std::string &string);
void remove_duplicate_chars(std::string &string);

} // namespace arrays_and_strings
} // namespace datastructures

#endif
