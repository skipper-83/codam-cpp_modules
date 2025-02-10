#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <array>

#ifdef ALL_CONTAINERS
	#include <list>
#endif

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
		PmergeMe<std::vector<int> > vectorContainer(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments
		PmergeMe<std::deque<int> > deQueContainer(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments

		
		vectorContainer.sort(verbose);
		deQueContainer.sort(verbose);

		#ifdef QSORT
			PmergeMe<std::vector<int> > vectorContainerCopy = vectorContainer;
			PmergeMe<std::deque<int> > deQueContainerCopy = deQueContainer;
			vectorContainerCopy.qsort();
			deQueContainerCopy.qsort();
		#endif

		#ifdef ALL_CONTAINERS
			PmergeMe<std::list<int> > listContainer(argc, argv); // create a PmergeMe object, passing the number of arguments and the arguments
			listContainer.sort(verbose);
		#endif

	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	return 0;
}