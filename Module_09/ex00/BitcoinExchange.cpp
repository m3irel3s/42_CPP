#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	_data = copy._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_data = copy._data;
	return *this;
}

void BitcoinExchange::parseData(const std::string &filename)
{
	std::ifstream input(filename.c_str());
	if (!input.is)
		throw std::runtime_error("Failed to open data file: " + filename);
}