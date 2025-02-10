#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe(int argc, char **argv)
{
	ValueType n;
	for (int i = 1; i < argc; i++)
	{
		if (!_isPositiveInteger(n, argv[i]))
		{
			throw "Can't construct PmergeMe";
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
		_container = rhs._container;
	return *this;
}

template <typename C>
PmergeMe<C>::~PmergeMe(){}