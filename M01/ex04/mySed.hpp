#include <iostream>
#include <fstream>

class	mySed
{
	public:
		mySed();
		~mySed(void);
		int	convert(std::string filename, std::string to_find, std::string to_replace);
};