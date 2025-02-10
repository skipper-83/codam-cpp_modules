#include "PmergeMe.hpp"

template <typename C>
typename PmergeMe<C>::Citerator PmergeMe<C>::_upperBound(Citerator start, Citerator end, ValueType value, int pairElementSize)
{
	Citerator result = end;

	while (start != end)
	{

		/*
		Binary search for the upper bound of the value in the range [start, end)
		this algorithm assumes that the range is sorted in ascending order, it starts
		by checking the middle element of the range and compares it with the value
		if the value is less than the middle element, the search narrows to the left half
		otherwise, the search narrows to the right half, and so on until the range is empty
		*/

		Citerator mid = start;
		std::advance(mid, std::distance(start, end) / 2); // Get the middle element

		ptrdiff_t offset = std::distance(start, mid) % pairElementSize; // Calculate the offset from the start of an element -- we need to check the last element of the group
		if (offset != 0)
			std::advance(mid, -offset); // if there is an offset, move the iterator to the start of the group

		// Get the identifier of the checked element
		int identifierOfCheckedElement = *(std::next(mid, pairElementSize - 1));

		// Compare the identifier with the value
		_comparisons++;
		if (value < identifierOfCheckedElement)
		{
			result = mid; // Move result to mid
			end = mid;	  // Narrow the search to the left half
		}
		else
			start = std::next(mid, pairElementSize); // Narrow the search to the right half
	}

	return result;
}