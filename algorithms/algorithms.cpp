#include "algorithms.hpp"
#include "bit_manipulation/bit_manipulation.hpp"

namespace algorithms {

common::Menu menu()
{
	common::Menu menu("Algorithms");
	menu.add("bm", "Bit Manipulation", [] {
		bit_manipulation::menu().open();
	});
	return menu;
}

} // namespace algorithms
