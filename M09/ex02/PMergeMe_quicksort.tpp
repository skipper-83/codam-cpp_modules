#include "PmergeMe.hpp"

template <typename C>
typename PmergeMe<C>::Citerator PmergeMe<C>::_partition(Citerator start, Citerator end)
{
	ValueType pivot = *end;
	Citerator i = start;

	for (Citerator j = start; j != end; std::advance(j, 1))
	{
		_comparisons++;
		if (*j < pivot)
		{
			std::swap(*i, *j);
			std::advance(i, 1);
		}
	}

	std::swap(*i, *end);
    return i;
}

template <typename C>
void PmergeMe<C>::qsort(Citerator start, Citerator end)
{
    if (std::distance(start, end) > 0)
    {
        Citerator partitionIndex = _partition(start, end);
        
        if (partitionIndex != start)
            qsort(start, std::prev(partitionIndex));
        
        if (partitionIndex != end)
            qsort(std::next(partitionIndex), end);
    }
}


template <typename C>
void PmergeMe<C>::qsort()
{
	if (_container.size() < 2)
	{
		std::cout << std::endl
				  << RED "Sorted " << _container.size() << " values with QuickSort!" RESET << std::endl;
		std::cout << "Container with 1 or 0 elements is already sorted." << std::endl;
		return;
	}
	_setStartTime();
	qsort(_container.begin(), std::prev(_container.end()));
	_setEndTime();
	if (!isSorted())
	{
		std::cout << "Not sorted!" << std::endl;
		return;
	}
	std::cout << std::endl << RED << "Sorted " << _container.size() << " values with QuickSort" << RESET << std::endl;
	std::cout << "Comparisons: " << _comparisons << std::endl;
	std::cout << "Elapsed time: " << _getElapsedTimeMS() << " ms" << std::endl;
	std::cout << "Container type: " << _containerType() << std::endl;
}