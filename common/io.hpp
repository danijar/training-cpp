#ifndef IO_HPP
#define IO_HPP

#include <string>
#include <sstream>

namespace common {

void clear();
void pause();
std::string underline(std::string text, char symbol = '-');
std::string dual_string(int number, bool padded = false);
int read_dual(std::string label);
int read_decimal(std::string label);
std::string read_string(std::string label);

namespace detail {

void dual_string_recursive(int number, std::stringstream &ss);

} // namespace detail

} // namespace common

#endif
