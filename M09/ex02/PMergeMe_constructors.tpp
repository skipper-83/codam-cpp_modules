#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe(int argc, char **argv)
{
	ValueType n;
	for (int i = 1; i < argc; i++)
	{
		if (!_isPositiveInteger(n, argv[i]))
		{
			throw "Can't construct PmergeMe: negative or non-integer value passed as argument";
		}
		_container.push_back(n);
	}
	_comparisons = 0;
	_verbose = false;
}

template <typename C>
PmergeMe<C>::PmergeMe(const PmergeMe &original)
{
	_container = original._container;
}

template <typename C>
PmergeMe<C> &PmergeMe<C>::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_container = rhs._container;
		_verbose = rhs._verbose;
		_comparisons = rhs._comparisons;
	}
	return *this;
}

template <typename C>
PmergeMe<C>::~PmergeMe()
{}