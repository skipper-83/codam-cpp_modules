#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./assetValuator [inputFilePath]" << std::endl;
		return 1;
	}

	std::string dbFilePath = "data.csv";
	try {
		BitcoinExchange exchange(dbFilePath);
		exchange.assetValuator(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}