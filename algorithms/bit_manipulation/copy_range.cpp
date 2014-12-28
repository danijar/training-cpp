#include "bit_manipulation.hpp"
#include <exception>

namespace algorithms {
namespace bit_manipulation {

// Copies the least significant bits from source to the range between
// from and to of the destination
void copy_range(int &destination, int source, size_t from, size_t to)
{
	// Validate parameters
	if (from > to || to > sizeof(int) * 8)
		throw std::exception();
	// Create bit mask of range to copy
	size_t length = to - from;
	int mask = ((1 << length) - 1) << from;
	// Align source with range and mask out other bits
	source <<= from;
	source &= mask;
	// Reset range of destination and copy source bits
	destination &= ~mask;
	destination |= source;
}

} // namespace bit_manipulation
} // namespace algorithms
