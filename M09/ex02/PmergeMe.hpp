#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <chrono>
#include <string>
#include <iostream>
#include <cmath>

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
	std::chrono::time_point<std::chrono::steady_clock> _startTime;
	std::chrono::time_point<std::chrono::steady_clock> _endTime;
	size_t _comparisons;

	// sort helper functions
	size_t _jacobsthal(size_t n);
	Citerator _upperBound(Citerator start, Citerator end, ValueType value, int pairElementSize);

	// QuickSort helper functions
	Citerator _partition(Citerator start, Citerator end);
	void qsort(Citerator start, Citerator end);

	// insertion functions
	void _insert(C &main, C &pend, C &odd, C &leftover, int pairElementSize);
	void _insertSingleRange(C &main, C &pend, int pairElementSize);

	// time functions
	void _setStartTime();
	void _setEndTime();
	float _getElapsedTimeMS();

	// parsing
	bool _isPositiveInteger(ValueType &number, const std::string &s);

	// printing
	void _printPairs(std::string msg, Citerator start, Citerator end, int pairSize, C &container, bool onlyElements = false, bool printRed = false, Citerator redStart = Citerator(), Citerator redEnd = Citerator(), bool printBlue = false, Citerator blueStart = Citerator(), Citerator blueEnd = Citerator());
	void _printContainer(C &container);
	std::string _containerType();
	bool _verbose;

public:
	// constructors and destructors
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &original);
	~PmergeMe();

	// operators
	PmergeMe &operator=(const PmergeMe &rhs);

	// iterators
	typename C::iterator begin();
	typename C::iterator end();

	// sort functions
	void sort(bool verbose = false);
	void qsort();
	bool isSorted();
};

#include "PMergeMe_printing.tpp"
#include "PMergeMe_constructors.tpp"
#include "PMergeMe_insert.tpp"
#include "PMergeMe_upperBound.tpp"
#include "PMergeMe_util.tpp"
#include "PMergeMe_quicksort.tpp"

template <typename C>
void PmergeMe<C>::sort(bool verbose)
{
	static int pairElementSize = 1;
	if (pairElementSize == 1) // on the first iteration, set the start time
		_setStartTime();

	int pairElementCount = _container.size() / pairElementSize; // number of pairs elements
	if (pairElementCount < 2)									// if there is less than two pair elements, we cannot make a pair and are done
		return;

	bool isOdd = pairElementCount % 2; // if the number of pair elements is odd, we will have a leftover
	Citerator start = _container.begin();
	Citerator end = std::next(start, (pairElementSize * pairElementCount) - (isOdd * pairElementSize)); // outer bound is amount of pairs * pair size minus the leftover (if any)

	_verbose = verbose; // set verbose flag to the value passed to the function

	if (_verbose)
		_printPairs(std::string(BLUE "Pairs of " RESET + std::to_string(pairElementSize) + "\n\t"), start, end, pairElementSize, _container);

	// PAIR SWAP PART
	for (Citerator it = start; it != end; std::advance(it, pairElementSize * 2))
	{
		Citerator firstPairLast = std::next(it, (pairElementSize - 1));	   // Last element of first pair
		Citerator secondPairLast = std::next(it, (pairElementSize * 2 - 1)); // Last element of second pair

		_comparisons++;
		if (*firstPairLast > *secondPairLast)								  // Compare last elements of the pairs
			std::swap_ranges(it, std::next(it, pairElementSize), std::next(it, pairElementSize)); // Swap entire pair
																			  // Move the iterator forward by 'pairElementSize * 2' steps using std::advance
	}
	if (_verbose)
	{
		_printPairs(std::string(RED "Swapped pairs of " RESET + std::to_string(pairElementSize) + "\n\t"), start, end, pairElementSize, _container);
		std::cout << std::endl;
	}

	// RECURSIVE CALL
	pairElementSize *= 2; // double the pair element size
	sort(_verbose);		  // recursive call
	pairElementSize /= 2; // halve the pair element size after the recursive call

	// PREPARE FOR INSERTION
	C main, pend, odd, leftover; // containers for main, pend, odd and leftover

	main.insert(main.end(), start, std::next(start, pairElementSize * 2));									 // insert the first two pair elements (b1, a1) into the main container
	for (Citerator it = std::next(start, pairElementSize * 2); it != end; std::advance(it, pairElementSize)) // loop through the rest of the pairs
	{
		pend.insert(pend.end(), it, std::next(it, pairElementSize)); // insert the pair into the pend container
		std::advance(it, pairElementSize);							  // move the iterator forward by the pair element size
		main.insert(main.end(), it, std::next(it, pairElementSize)); // insert the pair into the main container
	}
	if (isOdd)
		odd.insert(odd.end(), end, std::next(end, pairElementSize));							  // insert the odd element into the odd container if applicable
	leftover.insert(leftover.end(), std::next(end, (isOdd * pairElementSize)), _container.end()); // insert the leftover (whatever was left smaller than a pair element) into the leftover container

	if (verbose)
	{
		_printPairs(std::string(BLUE "Main, Pend, Odd, Leftover for pair element size: " RESET + std::to_string(pairElementSize) + "\nMain\n\t"), main.begin(), main.end(), pairElementSize, main, true);
		_printPairs("Pend\n\t", pend.begin(), pend.end(), pairElementSize, pend, true);
		_printPairs("Odd:\n\t", odd.begin(), odd.end(), pairElementSize, odd, true);
		std::cout << "Leftover: " << std::endl
				  << "\t";
		_printContainer(leftover);
		std::cout << std::endl;
	}
	if (!pend.empty() || isOdd || !leftover.empty())		 // if there is anything left to insert
		_insert(main, pend, odd, leftover, pairElementSize); // insert the pend container into the main container
	if (pairElementSize == 1)
	{ // on the last iteration, set the end time
		_setEndTime();
		if (!isSorted())
		{
			std::cout << "Not sorted!" << std::endl;
			return;
		}
		std::cout << std::endl
				  << BLUE "Sorted " << _container.size() << " values with Ford-Johnson!" RESET << std::endl;
		std::cout << "Comparisons: " << _comparisons << std::endl;
		std::cout << "Elapsed time: " << _getElapsedTimeMS() << " ms" << std::endl;
		std::cout << "Container type: " << _containerType() << std::endl
				  << std::endl;
	}
}

#endif
