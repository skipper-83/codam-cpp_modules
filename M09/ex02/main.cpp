#include "PmergeMe.hpp"
#include <vector>

int main(int argc, char **argv)
{
	try
	{
		PmergeMe<std::vector<int> > p(argc, argv);
		std::cout << p;
		p.sort();
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	return 0;
}