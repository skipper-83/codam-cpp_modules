#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef> // for size_t

template <typename T>
void iter(T *array, size_t length, void(*iter_func)(T &item))
{
    for (size_t i = 0; i < length; i++)
        iter_func(array[i]);
}

template <typename T>
void iter(T *array, size_t length, void(*iter_func)(T const& item)) // intra wants a const reference version
{
    for (size_t i = 0; i < length; i++)
        iter_func(array[i]);
}

#endif