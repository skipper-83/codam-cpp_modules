#include <algorithm> // for std::find
#include <iostream> // for std::cerr

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	// if (it == container.end())
	// 	std::cerr << "easyfind: Value not found" << std::endl;
	return it;
}