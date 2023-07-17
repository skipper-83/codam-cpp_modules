#include "mySed.hpp"

mySed::mySed()
{

}

mySed::~mySed()
{

}

int	mySed::convert(std::string filename, std::string to_find, std::string to_replace)
{
	std::string		file_content;
	std::string		outfile_name;
	std::ofstream	outfile;
	std::ifstream	infile;
	int				replace_pos;
	
	infile.open(filename);
	if (infile.fail())
	{
		std::cerr << "Error: could not open [" << filename << "]" << std::endl;
		return (0);
	}
	outfile_name = filename + ".replace";
	outfile.open(outfile_name, std::ofstream::out);
	if (outfile.fail())
	{
		std::cerr << "Error: could not create [" << outfile_name << "]" << std::endl;
		return (0);
	}
	if (std::getline(infile, file_content, (char)std::cin.eof()))
	{
		while ((replace_pos = file_content.find(to_find)) != std::string::npos)
		{
			file_content.erase(replace_pos, to_find.length());
			file_content.insert(replace_pos, to_replace);
		}
		outfile << file_content;
		return (1);
	}
	std::cerr << filename << " is empty." << std::endl;
	return (0);
}