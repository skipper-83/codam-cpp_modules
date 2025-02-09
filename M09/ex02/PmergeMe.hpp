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
	time_t _startTime;
	time_t _endTime;
	size_t _comparisons = 0;

	// sort helper functions
	size_t _jacobsthal(size_t n);
	void _insert(C &main, C &pend, C &odd, C &leftover, int pairElementSize);
	Citerator _upperBound(Citerator start, Citerator end, ValueType value, int pairElementSize);

	// time functions
	void _setStartTime();
	void _setEndTime();
	time_t _getElapsedTime();

	// parsing
	bool _isPositiveInteger(ValueType &number, const std::string &s);

	// printing
	void _printPairs(Citerator start, Citerator end, int pairSize, C &container, bool onlyElements = false, bool printRed = false, Citerator redStart = Citerator(), Citerator redEnd = Citerator(), bool printBlue = false, Citerator blueStart = Citerator(), Citerator blueEnd = Citerator());
	void _printContainer(C &container);

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
	_insert(main, pend, odd, leftover, pairElementSize); // insert the pend container into the main container
}

// SORT HELPER FUNCTIONS
template <typename C>
size_t PmergeMe<C>::_jacobsthal(size_t n)
{
	return ((pow(2, n) - pow(-1, n)) / 3);
}

template <typename C>
void PmergeMe<C>::_insert(C &main, C &pend, C &odd, C &leftover, int pairElementSize)
{
	std::cout << "Inserting pend into main for: " << pairElementSize << std::endl;
	std::cout << "Main: " << std::endl;
	_printPairs(main.begin(), main.end(), pairElementSize, main, true);
	std::cout << "Pend: " << std::endl;
	_printPairs(pend.begin(), pend.end(), pairElementSize, pend, true);
	Citerator boundEnd, insertStart, pendRangeStart, pendRangeEnd, pendRangeIdentifier;
	if (pend.size() == pairElementSize) // if the pend container only has one element, we don't use Jacobsthal optimization
	{
		pendRangeIdentifier = pend.begin() + pairElementSize - 1;	
		insertStart = _upperBound(main.begin(), main.end(), *pendRangeIdentifier, pairElementSize);
		main.insert(insertStart, pend.begin(), pend.end());
		std::cout << "New main: " << std::endl;
		Citerator insertedRangePosition = std::find(main.begin(), main.end(), *pend.begin());
		_printPairs(main.begin(), main.end(), pairElementSize, main, true, false, Citerator(), Citerator(), true, insertedRangePosition, insertedRangePosition + pairElementSize - 1);
	}
	else if (pend.size() > pairElementSize)
	{								// this function can be called with an empty pend
		size_t jacobsthalIndex = 3; // start with the third Jacobsthal number
		size_t prevJacobsthal = 1; // the previous Jacobsthal number inits to 1
		size_t currentJacobsthal; // 
		size_t totalInsertions = 0;
		size_t insertionIndex;
		while (!pend.empty())
		{
			// std::cout << "New Jacobsthal number" << std::endl;
			currentJacobsthal = _jacobsthal(jacobsthalIndex);
			insertionIndex = (currentJacobsthal - prevJacobsthal) * pairElementSize;
			if (insertionIndex > pend.size()) // we can't insert more than the size of the pend container
				insertionIndex = pend.size();
			while (insertionIndex > 0)
			{
				boundEnd = main.begin();  // reset the iterator
				pendRangeStart = pend.begin() + insertionIndex - pairElementSize; // the start of the range to insert
				pendRangeIdentifier = pend.begin() + insertionIndex - 1; // the identifier of the range to insert
				pendRangeEnd = pend.begin() + insertionIndex; // the end bound of the range to insert (extra vars for readability)

				std::cout << "Inserting at index " << insertionIndex / pairElementSize << " for Jacobsthal number: " << currentJacobsthal << std::endl;
				if (((currentJacobsthal + totalInsertions) * pairElementSize) < main.size())
					boundEnd = main.begin() + ((currentJacobsthal + totalInsertions) * pairElementSize); // set the upper bound to the Jacobsthal number + the total insertions * pair size
				else
					boundEnd = main.end();
				std::cout << "Main: " << std::endl;
				_printPairs(main.begin(), main.end(), pairElementSize, main, true, true, boundEnd, boundEnd + pairElementSize - 1, false, Citerator(), Citerator());
				std::cout << "Pend: " << std::endl;
				_printPairs(pend.begin(), pend.end(), pairElementSize, pend, true, false, Citerator(), Citerator(), true, pendRangeStart, pendRangeIdentifier );
				insertStart = _upperBound(main.begin(), boundEnd, *pendRangeIdentifier, pairElementSize);
				main.insert(insertStart, pendRangeStart, pendRangeEnd);
				std::cout << "New main: " << std::endl;
				Citerator insertedRangePosition = std::find(main.begin(), main.end(), *pendRangeStart);
				_printPairs(main.begin(), main.end(), pairElementSize, main, true, false, Citerator(), Citerator(), true, insertedRangePosition, insertedRangePosition + pairElementSize - 1);
			
				pend.erase(pendRangeStart, pendRangeEnd);

				insertionIndex -= pairElementSize;
				++totalInsertions;
				std::cout << "Total insertions: " << totalInsertions << std::endl << std::endl;
			}
			++jacobsthalIndex;
			prevJacobsthal = currentJacobsthal;
		}
	}
}

template <typename C>
typename PmergeMe<C>::Citerator PmergeMe<C>::_upperBound(Citerator start, Citerator end, ValueType value, int pairElementSize)
{
    Citerator result = end;

    while (start != end) {

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
		// std::cout << "Comparing " << value << " with " << identifierOfCheckedElement << std::endl;
        if (value < identifierOfCheckedElement) {
            result = mid; // Move result to mid
            end = mid;   // Narrow the search to the left half
        } else {
            start = ++mid; // Move first past the mid element
        }
    }

    return result;
}



// PRINT FUNCTIONS

template <typename C>
void PmergeMe<C>::_printPairs(Citerator start, Citerator end, int pairSize, C &container, bool onlyElements, bool printRed, Citerator redStart, Citerator redEnd, bool printBlue, Citerator blueStart, Citerator blueEnd)
	
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
		if (printRed && it == redStart)
			std::cout << RED;
		if (printBlue && it == blueStart)
			std::cout << BLUE;
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
		if (printRed && it == redEnd || printBlue && it == blueEnd)
			std::cout << RESET;
	}
	if (end != container.end())
	{
		for (Citerator it = end; it != container.end(); it++)
			std::cout << *it << " ";
	}
	if (printBlue || printRed)
		std::cout << RESET;	 // reset color if upper bound is end of container
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

// CONSTRUCTORS AND DESTRUCTORS

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
PmergeMe<C>::~PmergeMe()
{
}

#endif
