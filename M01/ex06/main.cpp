#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	input;

	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		exit (EXIT_FAILURE);
	}
	input = argv[1];
	harl.complain(input);

}