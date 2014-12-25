#include "puzzle.hpp"
#include "bit_manipulation/bit_manipulation.hpp"

namespace puzzle {

common::Menu menu()
{
	common::Menu menu("Puzzle");
	menu.add("bm", "Bit Manipulation", [] {
		bit_manipulation::menu().open();
	});
	return menu;
}

} // namespace puzzle
