#include <iostream>
#include "common/menu.hpp"
#include "datastructures/datastructures.hpp"
#include "algorithms/algorithms.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	common::Menu menu("Training C++");
	menu.show_back(false);
	menu.add("ds", "Datastructures", [] {
		datastructures::menu().open();
	});
	menu.add("ag", "Algorithms", [] {
		algorithms::menu().open();
	});
	menu.open();
	return 0;
}
