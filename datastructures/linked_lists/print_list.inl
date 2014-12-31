#ifndef PRINT_LIST_INL
#define PRINT_LIST_INL

#include "linked_lists.hpp"
#include <stdexcept>
#include <iostream>

namespace datastructures {
namespace linked_lists {

template <class T>
void print_list(SingleList<T> &list)
{
	// Print all but last
	auto i = list.head();
	for (; i->next_; i = i->next_)
		std::cout << i->value_ << ", ";
	// Print last
	std::cout << i->value_ << std::endl;
}

} // namespace linked_lists
} // namespace datastructures

#endif
