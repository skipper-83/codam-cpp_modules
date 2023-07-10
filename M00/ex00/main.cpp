#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		argv++;
		while (*argv)
		{
			while (**argv)
			{
				std::cout << (char)toupper(**argv);
				(*argv)++;
			}
			if (--argc > 1)
				std::cout << ' ';
			argv++;
		}
	}
	std::cout << std::endl;
}
