#include "linked_lists.hpp"
#include <iostream>
#include "../../common/io.hpp"

namespace datastructures {
namespace linked_lists {

SingleList<int> example_list()
{
	SingleList<int> list;
	for (int i = 0; i < 10; ++i)
		list.append(i);
	return list;
}

common::Menu menu()
{
	common::Menu menu("Linked Lists");
	menu.add("ii", "Insert at index", [] {
		// Print headline
		std::cout << common::underline("Insert at index") << std::endl;
		std::cout << "Insert an element with provided value at a given index. "
			"Negative indices are counted from the right side of the list."
			<< std::endl << std::endl;
		// Read input, run algorithm and print result
		auto list = example_list();
		print_list(list);
		auto index = static_cast<signed long>(common::read_decimal("Index:"));
		int value = common::read_decimal("Value:");
		list.insert(index, value);
		print_list(list);
		common::pause();
	});
	menu.add("ie", "Insert after element", [] {
		// Print headline
		std::cout << common::underline("Insert after element") << std::endl;
		std::cout << "Finds the first element with a given value. Then inserts "
			"a new element after it." << std::endl << std::endl;
		// Read input, run algorithm and print result
		auto list = example_list();
		print_list(list);
		auto find = static_cast<signed long>(common::read_decimal("Find:"));
		auto element = list.find(find);
		int value = common::read_decimal("Value:");
		list.insert(element, value);
		print_list(list);
		common::pause();
	});
	return menu;
}

} // namespace linked_lists
} // namespace datastructures
