#include "datastructures.hpp"
#include "arrays_and_strings/arrays_and_strings.hpp"

namespace datastructures {

common::Menu menu()
{
	common::Menu menu("Datastructures");
	menu.add("as", "Arrays and Strings", [] {
		arrays_and_strings::menu().open();
	});
	return menu;
}

} // namespace datastructures
