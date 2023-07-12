#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream 	f;
	std::ofstream 	f_replace;
	std::string		fcontent;
	std::string		fname;
	int				replace_pos;

	if (argc != 4)
	{
		std::cerr << "Usage: ./my_sed <filename> <str_to_replace> <st_to_replace_with>" << std::endl;
		return (1);
	}
	fname = argv[1];
	f.open(fname);
	if (f.fail())
	{
		std::cerr << "Error: could not open [" << argv[1] << "]" << std::endl;
		return (1);
	}
	f_replace.open(fname.append(".replace"), std::ofstream::out);
	if (f_replace.fail())
	{
		std::cerr << "Error: could not create [" << argv[1] << ".replace]" << std::endl;
		return (1);
	}
	if (std::getline(f, fcontent, (char)std::cin.eof()))
	{
		while ((replace_pos = fcontent.find(argv[2])) != std::string::npos)
		{
			fcontent.erase(replace_pos, strlen(argv[2]));
			fcontent.insert(replace_pos, argv[3]);
		}
		f_replace << fcontent;
	}
	else
		std::cerr << "File empty" << std::endl;

}