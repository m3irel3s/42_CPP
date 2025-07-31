#pragma once

#include <iostream>
#include <vector>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void parseData(const std::string &filename);
		void parseInput(const std::string &filename);

	private:
		std::map<std::string, float> _data;

		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &valueStr) const;
		bool isLeapYear(int year);
		std::string trim(const std::string &str) const;

};