
#include <sstream>

template <typename T>
Array<T>::Array(void) : _size(0)
{
	_elements = new T[0];
}

template <typename T>
Array<T>::Array(size_t n) : _size(n)
{
	_elements = new T[n];
}

template <typename T>
Array<T>::Array(Array<T> const &src)
{
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this == &rhs)
		return *this;
	_size = rhs._size;
	_elements = new T[_size];
	for (size_t i = 0; i < _size; ++i)
	{
		_elements[i] = rhs._elements[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _elements;
}

template <typename T>
size_t Array<T>::size(void) const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](size_t idx)
{
	if (idx > _size - 1 || idx < 0)
	{
		// std::cout << "idx: " << idx << " _size: " << _size << std::endl;
		throw std::out_of_range("Index out of range");
	}
	return _elements[idx];
}

template <typename T>
std::string Array<T>::printElements(void) const
{
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < _size; ++i) {
        oss << _elements[i];
        if (i < _size - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}