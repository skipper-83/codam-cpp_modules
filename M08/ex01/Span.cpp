#include "Span.hpp"
#include <algorithm>
#include <vector>

Span &Span::operator=(Span const& rhs)
{
	if (this == &rhs)
		return *this;
	_maxNum = rhs._maxNum;
	return *this;
}

int Span::shortestSpan() const
{
	if (_nums.size() < 2)
		throw(std::out_of_range("Cannot calculate span: there are less than two stored numbers"));
	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());
	int shortestSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		if (sorted[i] - sorted[i - 1] < shortestSpan)
			shortestSpan = sorted[i] - sorted[i - 1];
	}
	return shortestSpan;
}

int Span::longestSpan() const
{
	if (_nums.size() < 2)
		throw(std::out_of_range("Cannot calculate span: there are less than two stored numbers"));
	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator>
		minMax = std::minmax_element(_nums.begin(), _nums.end());
	return (*minMax.second - *minMax.first);
}

void Span::addNumber(const int nbr)
{
	if (_nums.size() == _maxNum)
		throw(std::out_of_range("Span is full"));
	_nums.push_back(nbr);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _nums.size() > _maxNum)
		throw(std::out_of_range("Span is full"));
	_nums.insert(_nums.end(), begin, end);
}

std::ostream &operator<<(std::ostream &os, Span const &span)
{
	os << "[ ";
	for (size_t i = 0; i < span.size(); ++i)
	{
		os << span.getNums()[i];
		if (i != span.size() - 1)
			os << ", ";
	}
	os << " ]";
	return os;
}