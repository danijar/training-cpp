#ifndef BIT_MANIPULATION_HPP
#define BIT_MANIPULATION_HPP

#include "../../common/menu.hpp"

namespace puzzle {
namespace bit_manipulation {

common::Menu menu();
void copy_range(int &destination, int source, size_t from, size_t to);
int create_range(size_t position, size_t length);

} // namespace bit_manipulation
} // namespace puzzle

#endif
