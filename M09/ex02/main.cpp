#include "PmergeMe.hpp"
#include <vector>

int main(int argc, char **argv)
{

	bool verbose = false; // verbose flag
	int new_argc = 1; // counter to shift arguments

	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]) == "--verbose" || std::string(argv[i]) == "-v")
		{
			verbose = true; // set verbose to true
		}
		else
		{
			argv[new_argc++] = argv[i]; // else shift the argument to the left
		}
	}
	try
	{
		PmergeMe<std::vector<int> > p(argc - verbose, argv); // create a PmergeMe object, passing the number of arguments and the arguments
		std::cout << p; 
		p.sort(verbose);
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	return 0;
}