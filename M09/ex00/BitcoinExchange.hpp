#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string &dbFilePath);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);

		void assetValuator(std::string filePath);

	private:
		BitcoinExchange();
		std::map<std::string, float> _exchangeRates;

		bool _validDate(int year, int month, int day);
		void _getRate(std::string date, float asset);
};

#endif