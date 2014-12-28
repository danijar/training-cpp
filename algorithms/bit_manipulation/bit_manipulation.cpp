#include "bit_manipulation.hpp"
#include <iostream>
#include "../../common/io.hpp"

namespace algorithms {
namespace bit_manipulation {

common::Menu menu()
{
	common::Menu menu("Bit Manipulation");
	menu.add("cr", "Create Range", [] {
		// Print headline
		std::cout << common::underline("Create Range") << std::endl;
		std::cout << "Create integer bit mask of given range" << std::endl << std::endl;
		// Read input
		int position = common::read_decimal("Position:");
		int length = common::read_decimal("Length:");
		// Run algorithm
		int range = create_range(position, length);
		// Print result
		std::cout << "Result: " << common::dual_string(range, true) << std::endl;
		common::pause();
	});
	menu.add("cp", "Copy Range", [] {
		// Print headline
		std::cout << common::underline("Copy Range") << std::endl;
		std::cout << "Copy given range from one integer to another" << std::endl << std::endl;
		// Read input
		int destination = common::read_dual("Destination:");
		int source = common::read_dual("Source:     ");
		int from = common::read_decimal("From:");
		int to = common::read_decimal("To:");
		// Run algorithm
		copy_range(destination, source, from, to);
		// Print result
		std::cout << "Result:      " << common::dual_string(destination) << std::endl;
		common::pause();
	});
	return menu;
}

} // namespace bit_manipulation
} // namespace algorithms
