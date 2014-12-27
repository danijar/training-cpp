#include "puzzle.hpp"
#include "bit_manipulation/bit_manipulation.hpp"
#include "arrays_and_strings/arrays_and_strings.hpp"

namespace puzzle {

common::Menu menu()
{
	common::Menu menu("Puzzle");
	menu.add("bm", "Bit Manipulation", [] {
		bit_manipulation::menu().open();
	});
	menu.add("as", "Arrays and Strings", [] {
		arrays_and_strings::menu().open();
	});
	return menu;
}

} // namespace puzzle
