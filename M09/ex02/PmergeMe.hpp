#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <chrono>
#include <string>
#include <iostream>

template <typename C>
class PmergeMe
{
	typedef typename C::iterator Citerator;
	typedef typename C::value_type ValueType;

	private:
		PmergeMe();

		C _container;
		time_t _startTime;
		time_t _endTime;

		// sort functions
		size_t _jacobsthal(size_t n);
		// void _sort()

		// time functions
		void _setStartTime();
		void _setEndTime();
		time_t _getElapsedTime();

		// parsing
		bool _isPositiveInteger(ValueType &number, const std::string &s);

		// printing
		void _printPairs(int depth);
		void _printMerge(Citerator start, Citerator end, int pairSize);

	public:
		PmergeMe(int argc, char **argv);
		void sort();

		// iterators
		typename C::iterator begin();
		typename C::iterator end();
};

// SORT FUNCTIONS
template <typename C>
void PmergeMe<C>::sort()
{
	static int pairSize = 1;
	if (pairSize == 1)
	{ // on the first iteration, set the start time
	  // _setStartTime();
	}
	int pairCount = _container.size() / pairSize; // number of pairs
	if (pairCount < 2)							  // if there is only one pair, we cannot merge sort it
		return;
	bool isOdd = pairCount % 2; // if the number of pairs is odd, we will have a leftover
	Citerator start = _container.begin();
	Citerator end = start + (pairSize * pairCount) - (isOdd * pairSize); // outer bound is amount of pairs * pair size minus the leftover

	_printMerge(start, end, pairSize);

	// merge pairs and swap if necessary
	for (Citerator it = start; it != end; it += pairSize * 2) // loop through pairs, iterator increases with pairsize * 2 so we skip the pairs we already merged
	{
		if (*(it + pairSize - 1) > *(it + pairSize * 2 - 1)) // if the last element of the first pair is greater than the last element of the second pair, we must swap the pairs
		{
			std::swap_ranges(it, it + pairSize, it + pairSize); // swap the pairs;
		}
	}
	std::cout << "Merged pairs of " << pairSize << std::endl;
	_printMerge(start, end, pairSize);
	std::cout << std::endl;

	pairSize *= 2; // double the pair size
	sort();		   // recursive call
	pairSize /= 2; // halve the pair size after the recursive call

	// _sort();
	// _setEndTime();
}

// PRINT FUNCTIONS

template <typename C>
void PmergeMe<C>::_printMerge(Citerator start, Citerator end, int pairSize)
{
	int halfPair = 0;
	int fullPair = 0;
	std::cout << "Pairs of " << pairSize << ": ";
	for (Citerator it = start; it != end; it++)
	{
		if (fullPair == 0)
		{
			std::cout << "[";
		}
		if (halfPair == 0)
		{
			std::cout << "{";
		}
		std::cout << *it;
		++fullPair;
		++halfPair;
		if (halfPair == pairSize)
		{
			std::cout << "}";
			halfPair = 0;
			if (fullPair == pairSize * 2)
			{
				std::cout << "] ";
				fullPair = 0;
			}
			else
			{
				std::cout << " - ";
			}
		}
		else
		{
			std::cout << " ";
		}
	}
	if (end != _container.end())
	{
		for (Citerator it = end; it != _container.end(); it++)
		{
			std::cout << *it << " ";
		}
	}
	std::cout << std::endl;
}

template <typename C>
std::ostream &operator<<(std::ostream &os, PmergeMe<C> &p)
{
	for (typename C::iterator it = p.begin(); it != p.end(); it++)
	{
		os << *it << " ";
	}
	os << std::endl;
	return os;
}

template <typename C>
void PmergeMe<C>::_printPairs(int depth)
{
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

// HELPER FUNCTIONS

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

// CONSTRUCTOR

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
}

#endif
