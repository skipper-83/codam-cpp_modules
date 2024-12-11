#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <ostream>

class Span{
	public:
		Span();
		Span(size_t const N);
		Span(Span const& src);
		~Span();

		Span& operator=(Span const& rhs);

		int shortestSpan() const;
		int longestSpan() const;

		void addNumber(const int nbr);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		size_t size(void) const { return _nums.size(); };
		std::vector<int> const& getNums(void) const { return _nums; };

	private:
		size_t _maxNum;
		std::vector<int> _nums;
};

std::ostream& operator<<(std::ostream& os, Span const& span);


#endif