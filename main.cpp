#include <iostream>
#include "common/menu.hpp"
#include "puzzle/puzzle.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	common::Menu menu("Training C++");
	menu.add("p", "Puzzle", [] {
		puzzle::menu().open();
	});
	menu.open();
	return 0;
}
