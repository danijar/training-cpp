#include "bit_manipulation.hpp"
#include <exception>

namespace algorithms {
namespace bit_manipulation {

int create_range(size_t position, size_t length)
{
	// Validate parameters
	if (position + length > sizeof(int) * 8)
		throw std::exception();
	// Create bit mask ones in range
	int mask = (1 << length) - 1;
	mask <<= position;
	return mask;
}

} // namespace bit_manipulation
} // namespace algorithms
