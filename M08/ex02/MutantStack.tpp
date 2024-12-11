#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other){};

template <typename T>
MutantStack<T>::~MutantStack(){};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
MutantStack<T>::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.begin();
}

template <typename T>
MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return std::stack<T>::c.cbegin();
}

template <typename T>
MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return std::stack<T>::c.cend();
}

template <typename T>
MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

template <typename T>
MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return std::stack<T>::c.crbegin();
}

template <typename T>
MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return std::stack<T>::c.crend();
}

#endif