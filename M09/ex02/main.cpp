#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <list>

bool setVerbose(int *argc, char ***argv)
{
	bool verbose = false; // verbose flag
	int new_argc = 1; // counter to shift arguments

	for (int i = 1; i < *argc; ++i)
	{
		if (std::string((*argv)[i]) == "--verbose" || std::string((*argv)[i]) == "-v")
			verbose = true; // set verbose to true
		else
			(*argv)[new_argc++] = (*argv)[i]; // else shift the argument to the left
	}
	*argc = new_argc; // set argc to the new value
	return verbose; // return verbose flag
}

int main(int argc, char **argv)
{

	bool verbose = setVerbose(&argc, &argv); // verbose flag

	try
	{
		PmergeMe<std::vector<int> > p_vec(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments
		PmergeMe<std::deque<int> > p_deq(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments

		PmergeMe<std::vector<int> > p_copy = p_vec;
		PmergeMe<std::deque<int> > p_copy2 = p_deq;
		p_vec.sort(verbose);
		p_copy.qsort();

		p_deq.sort(verbose);
		p_copy2.qsort();
		// std::cout << p_copy2;

		PmergeMe<std::list<int> > p_list(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments
		p_list.sort(verbose);

	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	return 0;
}