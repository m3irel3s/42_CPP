#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <float.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cerrno>
#include <climits>
#include <cfloat>

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
		bool isLeapYear(int year) const;
		bool parseInputLine(const std::string &line, std::string &date, float &value) const;
		void computeBTCValue(const std::string &date, float value) const;
};