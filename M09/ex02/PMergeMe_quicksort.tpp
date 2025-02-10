#include "PmergeMe.hpp"

template <typename C>
typename PmergeMe<C>::Citerator PmergeMe<C>::_partition(Citerator start, Citerator end)
{
	ValueType pivot = *end;
	Citerator i = start - 1;

	for (Citerator j = start; j < end; j++)
	{
		_comparisons++;
		if (*j < pivot)
		{
			i++;
			std::swap(*i, *j);
		}
	}

	std::swap(*(i + 1), *end);
	return i + 1;
}

template <typename C>
void PmergeMe<C>::qsort(Citerator start, Citerator end)
{
	if (start < end)
	{
		Citerator pi = _partition(start, end);
		qsort(start, pi - 1);
		qsort(pi + 1, end);
	}
}


template <typename C>
void PmergeMe<C>::qsort()
{
	_setStartTime();
	qsort(_container.begin(), _container.end() - 1);
	_setEndTime();
	if (!isSorted())
	{
		std::cout << "Not sorted!" << std::endl;
		return;
	}
	std::cout << std::endl << RED"Sorted " << _container.size() << " values with QuickSort"RESET << std::endl;
	std::cout << "Comparisons: " << _comparisons << std::endl;
	std::cout << "Elapsed time: " << _getElapsedTimeMS() << " ms" << std::endl;
	std::cout << "Container type: " << _containerType() << std::endl << std::endl;
}