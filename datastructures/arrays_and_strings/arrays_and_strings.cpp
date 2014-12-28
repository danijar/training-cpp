#include "arrays_and_strings.hpp"
#include <iostream>
#include "../../common/io.hpp"

namespace datastructures {
namespace arrays_and_strings {

common::Menu menu()
{
	common::Menu menu("Arrays and Strings");
	menu.add("uc", "All unique chars", [] {
		// Print headline
		std::cout << common::underline("All unique chars") << std::endl;
		std::cout << "Check whether every character of the string occurs only "
			"once." << std::endl << std::endl;
		// Read input, run algorithm and print result
		std::string string = common::read_string("String:");
		bool result = all_unique_chars(string);
		std::cout << "Result: " << (result ? "true" : "false") << std::endl;
		common::pause();
	});
	menu.add("uci", "All unique chars (in place)", [] {
		// Print headline
		std::cout << common::underline("All unique chars (in place)") <<
			std::endl;
		std::cout << "Check whether every character of the string occurs only "
			"once without using an additional data structure." << std::endl <<
			std::endl;
		// Read input, run algorithm and print result
		std::string string = common::read_string("String:");
		bool result = all_unique_chars(string);
		std::cout << "Result: " << (result ? "true" : "false") << std::endl;
		common::pause();
	});
	menu.add("rv", "Reverse string", [] {
		// Print headline
		std::cout << common::underline("Reverse string") << std::endl;
		std::cout << "Reverse the order of characters in a C style string." <<
			std::endl << std::endl;
		// Read input, run algorithm and print result
		std::string string = common::read_string("String:");
		reverse_string(string);
		std::cout << "Result: " << string << std::endl;
		common::pause();
	});
	menu.add("rd", "Remove duplicate characters", [] {
		// Print headline
		std::cout << common::underline("Remove duplicate characters") <<
			std::endl;
		std::cout << "Remove duplicate characters that follow each other." <<
			std::endl << std::endl;
		// Read input, run algorithm and print result
		std::string string = common::read_string("String:");
		remove_duplicate_chars(string);
		std::cout << "Result: " << string << std::endl;
		common::pause();
	});
	return menu;
}

} // namespace arrays_and_strings
} // namespace datastructures
