#include "mySed.hpp"

int	main(int argc, char **argv)
{
	mySed	sed;

	if (argc != 4)
	{
		std::cerr << "Usage: ./my_sed <filename> <str_to_replace> <str_to_replace_with>" << std::endl;
		return (1);
	}
	if (!sed.convert(argv[1], argv[2], argv[3]))
		exit (EXIT_FAILURE);
	std::cout << "Conversion succesful." << std::endl;
	exit (EXIT_SUCCESS);
}