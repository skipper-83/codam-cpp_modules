#include "PmergeMe.hpp"

template <typename C>
void PmergeMe<C>::_insertSingleRange(C &main, C &pend, size_t pairElementSize)
{
	Citerator insertStart, pendRangeIdentifier;

	pendRangeIdentifier = std::next(pend.begin(), pairElementSize - 1);
	insertStart = _upperBound(main.begin(), main.end(), *pendRangeIdentifier, pairElementSize);
	main.insert(insertStart, pend.begin(), pend.end());

	Citerator insertedRangePosition = std::find(main.begin(), main.end(), *pend.begin());
	
	if (_verbose)
		_printPairs("New main:\n\t", main.begin(), main.end(), pairElementSize, main, true, false, Citerator(), Citerator(), true, insertedRangePosition, std::next(insertedRangePosition, pairElementSize - 1));
}

template <typename C>
void PmergeMe<C>::_insert(C &main, C &pend, C &odd, C &leftover, size_t pairElementSize)
{
	if (_verbose)
	{
		std::cout << "Inserting pend into main for: " << pairElementSize << std::endl;
		_printPairs("Main:\n\t", main.begin(), main.end(), pairElementSize, main, true);
		_printPairs("Pend\n\t", pend.begin(), pend.end(), pairElementSize, pend, true);
	}

	Citerator boundEnd, insertStart, pendRangeStart, pendRangeEnd, pendRangeIdentifier ,insertedRangePosition;
	if (pend.size() == pairElementSize) // if the pend container only has one element, we don't use Jacobsthal optimization
	{
		if (_verbose)
			std::cout << "Pend has only one range, inserting directly" << std::endl;
		_insertSingleRange(main, pend, pairElementSize);
	}
	else if (pend.size() > pairElementSize)
	{								// this function can be called with an empty pend
		size_t jacobsthalIndex = 3; // start with the third Jacobsthal number
		size_t prevJacobsthal = 1;	// the previous Jacobsthal number inits to 1
		size_t currentJacobsthal = 3;	//
		size_t totalInsertions = 0;
		size_t insertionIndex, offset;

		while (!pend.empty())
		{
			currentJacobsthal = _jacobsthal(jacobsthalIndex);						 // get the current Jacobsthal number
			insertionIndex = (currentJacobsthal - prevJacobsthal) * pairElementSize; // calculate the insertion index
			if (insertionIndex > pend.size())										 // we can't insert more than the size of the pend container
				insertionIndex = pend.size();
			while (insertionIndex > 0)
			{
				pendRangeStart = std::next(pend.begin(), insertionIndex - pairElementSize); // the start of the range to insert
				pendRangeIdentifier = std::next(pend.begin(), insertionIndex - 1);		  // the identifier of the range to insert
				pendRangeEnd = std::next(pend.begin(), insertionIndex);					  // the end bound of the range to insert (extra vars for readability)


				if (_verbose)
					std::cout << std::endl << "Inserting at index " << insertionIndex / pairElementSize << " for Jacobsthal number: " << currentJacobsthal << std::endl;
				
				offset = (currentJacobsthal + totalInsertions) * pairElementSize;
				boundEnd = main.end();
				if (offset < main.size())
					boundEnd = std::next(main.begin(), offset);

				if (_verbose)
				{
					_printPairs("Main:\n\t", main.begin(), main.end(), pairElementSize, main, true, true, boundEnd, std::next(boundEnd, pairElementSize - 1), false, Citerator(), Citerator());
					_printPairs("Pend\n\t", pend.begin(), pend.end(), pairElementSize, pend, true, false, Citerator(), Citerator(), true, pendRangeStart, pendRangeIdentifier);
				}

				insertStart = _upperBound(main.begin(), boundEnd, *pendRangeIdentifier, pairElementSize);
				insertedRangePosition = main.insert(insertStart, pendRangeStart, pendRangeEnd);
				
				if (_verbose)
					_printPairs("New main\n\t", main.begin(), main.end(), pairElementSize, main, true, false, Citerator(), Citerator(), true, insertedRangePosition, std::next(insertedRangePosition, pairElementSize - 1));

				pend.erase(pendRangeStart, pendRangeEnd); // erase the inserted range from the pend container

				insertionIndex -= pairElementSize; // decrease the insertion index by the pair size
			}
			totalInsertions += currentJacobsthal - prevJacobsthal;
			++jacobsthalIndex;
			prevJacobsthal = currentJacobsthal;
		}
	}
	if (!odd.empty()) // if there is an odd element, insert it into the main container
	{
		if(_verbose)
			_printPairs("\nInserting odd into main\n\t", odd.begin(), odd.end(), pairElementSize, odd, true);

		_insertSingleRange(main, odd, pairElementSize);
	}
	if (!leftover.empty()) // if there is a leftover, insert it into the main container
	{
		main.insert(main.end(), leftover.begin(), leftover.end()); // insert the leftover into the main container
		if (_verbose)
			_printPairs("\nInserting leftover into main\n\t", main.begin(), main.end(), pairElementSize, main, true, false, Citerator(), Citerator(), true, std::next(main.begin(), (main.size() - (main.size() % pairElementSize))), main.end());
	}
	if (_verbose)
		std::cout << std::endl;
	_container = main; // set the main container as the new container
}