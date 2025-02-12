#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

BitcoinExchange::BitcoinExchange(std::string &dbFilePath)
{
	std::ifstream dbFile(dbFilePath.c_str());
	if (!dbFile.is_open())
		throw std::runtime_error("Error: could not open database file");
	std::string line;
	std::getline(dbFile, line); // skip date,exchange_rate header
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid header");
	while (std::getline(dbFile, line))
	{
		int year, month, day;
		char dash1, dash2, comma;
		float rate;
		std::string date;

		std::istringstream lineStream(line);
		if (!(lineStream >> year >> dash1 >> month >> dash2 >> day >> comma >> rate))
		{
			std::cerr << RED << "Skipping line, invalid format: " << RESET << line << std::endl;
			continue;
		}
		date = line.substr(0, line.find(','));
		if (date.size() != 10 || !_validDate(year, month, day))
		{
			std::cerr << RED << "Skipping line, invalid date: " << RESET << date << std::endl;
			continue;
		}
		if (rate < 0)
		{
			std::cerr << RED << "Skipping line, invalid rate: " << RESET << rate << std::endl;
			continue;
		}
		// std::cout << "date: " << date << " rate: " << rate << std::endl;
		_exchangeRates[date] = rate;
	}
}
bool BitcoinExchange::_validDate(int year, int month, int day)
{
	if (year < 2000 || year > 2025)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 2 && day > 29)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

void BitcoinExchange::assetValuator(std::string filePath)
{
	std::ifstream assetFile(filePath.c_str());
	if (!assetFile.is_open())
	{
		std::cerr << RED << "Error: could not open asset file" << RESET << std::endl;
		return;
	}
	std::string line;
	std::getline(assetFile, line);
	if (line != "date | value")
	{
		std::cerr << RED << "Error: invalid header" << RESET << std::endl;
		return;
	}
	while (std::getline(assetFile, line))
	{
		std::string date;
		int year, month, day;
		char dash, dash2, pipe;
		float asset;
		std::istringstream lineStream(line);

		if (!(lineStream >> year >> dash >> month >> dash2 >> day >> pipe >> asset))
		{
			std::cerr << RED << "Skipping line, invalid format: " << RESET << line << std::endl;
			continue;
		}
		date = line.substr(0, line.find(" |"));
		if (date.size() != 10 || !_validDate(year, month, day))
		{
			std::cerr << RED << "Skipping line, invalid date: " << RESET << date << std::endl;
			continue;
		}
		if (asset < 0 )
		{
			std::cerr << RED << "Skipping line, asset negative: " << RESET << asset << std::endl;
			continue;
		}
		if (asset > 1000)
		{
			std::cerr << RED << "Skipping line, asset too high: " << RESET << asset << std::endl;
			continue;
		}
		_getRate(date, asset);
	}
}

void BitcoinExchange::_getRate(std::string date, float asset)
{
	std::map<std::string, float>::iterator it = _exchangeRates.upper_bound(date);
	if (it == _exchangeRates.begin())
	{
		std::cerr << RED << "Asset date predates all DB values. Are you sure BTC existed on " << BLUE << date << RED << " ?" << RESET << std::endl;
		return;
	}
	float rate = (--it)->second;
	std::cout << "Date: " << BLUE << date << RESET << "\tasset:\t" << GREEN << "BTC " <<  asset <<  RESET << "\trate:\t" << YELLOW << rate <<  RESET << "\tvalue:\t" << GREEN << "$ " << rate * asset <<  RESET << std::endl;
	(void)asset;

	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}