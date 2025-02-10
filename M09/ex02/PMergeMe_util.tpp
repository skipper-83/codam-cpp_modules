#include "PmergeMe.hpp"
#include <chrono>


// TIME FUNCTIONS
template <typename C>
void PmergeMe<C>::_setStartTime()
{
	_startTime = std::chrono::high_resolution_clock::now();
}

template <typename C>
void PmergeMe<C>::_setEndTime()
{
	_endTime = std::chrono::high_resolution_clock::now();
}

template <typename C>
float PmergeMe<C>::_getElapsedTimeMS()
{
	std::chrono::duration<double, std::milli> elapsedTime = _endTime - _startTime;
	return elapsedTime.count();
}

// SORTER HELPERS
template <typename C>
bool PmergeMe<C>::isSorted()
{
	for (Citerator it = _container.begin(); it != _container.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

template <typename C>
size_t PmergeMe<C>::_jacobsthal(size_t n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}


// ITERATORS
template <typename C>
typename C::iterator PmergeMe<C>::begin()
{
	return _container.begin();
}

template <typename C>
typename C::iterator PmergeMe<C>::end()
{
	return _container.end();
}


// PARSING
template <typename C>
bool PmergeMe<C>::_isPositiveInteger(ValueType &number, const std::string &s)
{
	try
	{
		number = std::stoi(s);
		if (number < 0)
		{
			return false;
		}
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << s << std::endl;
		return false;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << "Out of range: " << s << std::endl;
		return false;
	}
	return true;
}
