#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <chrono>
#include <string>
#include <iostream>

#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

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
	void _printPairs(Citerator start, Citerator end, int pairSize, C &container, bool onlyElements = false);
	void _printContainer(C &container);

public:
	PmergeMe(int argc, char **argv);
	void sort(bool verbose = false);

	// iterators
	typename C::iterator begin();
	typename C::iterator end();
};

// SORT FUNCTIONS
template <typename C>
void PmergeMe<C>::sort(bool verbose)
{
	static int pairElementSize = 1;
	if (pairElementSize == 1)
	{ // on the first iteration, set the start time
	  // _setStartTime();
	}
	int pairElementCount = _container.size() / pairElementSize; // number of pairs elements
	if (pairElementCount < 2)									// if there is less than two pair elements, we cannot make a pair and are done
		return;

	bool isOdd = pairElementCount % 2; // if the number of pair elements is odd, we will have a leftover
	Citerator start = _container.begin();
	Citerator end = start + (pairElementSize * pairElementCount) - (isOdd * pairElementSize); // outer bound is amount of pairs * pair size minus the leftover (if any)

	if (verbose)
	{
		std::cout << BLUE "Pairs of " RESET << pairElementSize << std::endl
				  << "\t";
		_printPairs(start, end, pairElementSize, _container);
	}

	// PAIR SWAP PART
	for (Citerator it = start; it != end; it += pairElementSize * 2) // loop through pairs, iterator increases with pairsize * 2 so we skip the pairs we already merged
	{
		if (*(it + pairElementSize - 1) > *(it + pairElementSize * 2 - 1))	  // if the last element of the first pair is greater than the last element of the second pair, we must swap the pairs
			std::swap_ranges(it, it + pairElementSize, it + pairElementSize); // swap the pairs;
	}
	if (verbose)
	{
		std::cout << RED "Swapped pairs of " RESET << pairElementSize << std::endl
				  << "\t";
		_printPairs(start, end, pairElementSize, _container);
		std::cout << std::endl;
	}

	// RECURSIVE CALL
	pairElementSize *= 2; // double the pair element size
	sort(verbose);		  // recursive call
	pairElementSize /= 2; // halve the pair element size after the recursive call

	// PREPARE FOR INSERTION
	C main, pend, odd, leftover; // containers for main, pend, odd and leftover

	main.insert(main.end(), start, start + pairElementSize * 2);					  // insert the first two pair elements (b1, a1) into the main container
	for (Citerator it = start + pairElementSize * 2; it < end; it += pairElementSize) // loop through the rest of the pairs
	{
		pend.insert(pend.end(), it, it + pairElementSize); // insert the pair into the pend container
		it += pairElementSize;							   // skip the pair we just inserted
		main.insert(main.end(), it, it + pairElementSize); // insert the pair into the main container
	}
	if (isOdd)
		odd.insert(odd.end(), end, end + pairElementSize);								// insert the odd element into the odd container if applicable
	leftover.insert(leftover.end(), end + (isOdd * pairElementSize), _container.end()); // insert the leftover (whatever was left smaller than a pair element) into the leftover container

	if (verbose)
	{
		std::cout << BLUE "Main, Pend, Odd, Leftover for pair element size: " RESET << pairElementSize << std::endl;
		std::cout << "Main: " << std::endl
				  << "\t";
		_printPairs(main.begin(), main.end(), pairElementSize, main, true);
		std::cout << "Pend: " << std::endl
				  << "\t";
		_printPairs(pend.begin(), pend.end(), pairElementSize, pend, true);
		std::cout << "Odd: " << std::endl
				  << "\t";
		_printPairs(odd.begin(), odd.end(), pairElementSize, odd, true);
		std::cout << "Leftover: " << std::endl
				  << "\t";
		_printContainer(leftover);
		std::cout << std::endl;
	}

	// main.
	// _sort();
	// _setEndTime();
}

// PRINT FUNCTIONS

template <typename C>
void PmergeMe<C>::_printPairs(Citerator start, Citerator end, int pairSize, C &container, bool onlyElements)
{
	if (container.empty())
	{
		std::cout << "<none>" << std::endl;
		return;
	}
	int halfPair = 0;
	int fullPair = 0;
	for (Citerator it = start; it < end; it++)
	{
		if (fullPair == 0 && !onlyElements)
			std::cout << "[";
		if (halfPair == 0)
			std::cout << "{";
		std::cout << *it;
		++fullPair;
		++halfPair;
		if (halfPair == pairSize)
		{
			std::cout << "}";
			halfPair = 0;
			if (fullPair == pairSize * 2 && !onlyElements)
			{
				std::cout << "] ";
				fullPair = 0;
			}
			else if (!onlyElements)
				std::cout << " - ";
			else
				std::cout << " ";
		}
		else
			std::cout << " ";
	}
	if (end != container.end())
	{
		for (Citerator it = end; it != container.end(); it++)
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename C>
void PmergeMe<C>::_printContainer(C &container)
{
	if (container.empty())
	{
		std::cout << "<none>" << std::endl;
		return;
	}
	for (Citerator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
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
