#include "PmergeMe.hpp"

template <typename C>
void PmergeMe<C>::_printPairs(std::string msg, Citerator start, Citerator end, int pairSize, C &container, bool onlyElements, bool printRed, Citerator redStart, Citerator redEnd, bool printBlue, Citerator blueStart, Citerator blueEnd)
{
	std::cout << msg;
	if (container.empty())
	{
		std::cout << "<none>" << std::endl;
		return;
	}
	int halfPair = 0;
	int fullPair = 0;
	for (Citerator it = start; it != end; std::advance(it, 1))
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
		if ((printRed && it == redEnd) || (printBlue && it == blueEnd))
			std::cout << RESET;
	}
	if (end != container.end())
	{
		for (Citerator it = end; it != container.end(); it++)
			std::cout << *it << " ";
	}
	if (printBlue || printRed)
		std::cout << RESET; // reset color if upper bound is end of container
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
std::string PmergeMe<C>::_containerType()
{
	std::string type = typeid(_container).name();
	if (type == "St6vectorIiSaIiEE")
		return "std::vector<int>";
	if (type == "St5dequeIiSaIiEE")
		return "std::deque<int>";
	if (type == "NSt7__cxx114listIiSaIiEEE")
		return "std::list<int>";
	return typeid(_container).name();
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