#include <iostream>
#include "common/menu.hpp"
#include "puzzle/puzzle.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	common::Menu menu("Training C++");
	menu.show_back(false);
	menu.add("pz", "Puzzle", [] {
		puzzle::menu().open();
	});
	menu.open();
	return 0;
}
