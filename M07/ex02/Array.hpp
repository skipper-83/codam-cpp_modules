#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array<T>(void);
	Array<T>(size_t n);
	Array<T>(Array<T> const &src);
	~Array<T>(void);

	Array<T> &operator=(Array<T> const &rhs);
	T &operator[](size_t i);

	size_t size(void) const;
	std::string printElements(void) const;

private:
	T *_elements;
	size_t _size;
};

#include "Array.tpp"

#endif