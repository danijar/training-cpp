#include "datastructures.hpp"
#include "arrays_and_strings/arrays_and_strings.hpp"
#include "linked_lists/linked_lists.hpp"

namespace datastructures {

common::Menu menu()
{
	common::Menu menu("Datastructures");
	menu.add("as", "Arrays and Strings", [] {
		arrays_and_strings::menu().open();
	});
	menu.add("ll", "Linked Lists", [] {
		linked_lists::menu().open();
	});
	return menu;
}

} // namespace datastructures
