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
	std::ifstream data(filename.c_str());
	if (!data.is_open())
		throw std::runtime_error("Failed to open data file: " + filename);

	std::string line;
	std::getline(data, line);
	
	if (line != "date,exchange_rate")
		throw std::runtime_error("Incorrect header: " + line);

	while (std::getline(data, line))
	{
		std::istringstream ss(line);
		std::string date, rateStr;

		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			if (!isValidDate(date))
				throw std::runtime_error("Invalid date format: " + date);

			char *endptr;
			errno = 0;
			float rate = std::strtof(rateStr.c_str(), &endptr);
			if (errno == ERANGE || *endptr != '\0' || rate < 0)
				throw std::runtime_error("Invalid exchange rate: " + rateStr);

			_data[date] = rate;
		}
		else
			throw std::runtime_error("Invalid line in data file: " + line);
	}
}

void BitcoinExchange::parseInput(const std::string &filename)
{
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Failed to open input file: " + filename);

	std::string line;
	std::getline(input, line);

	if (line != "date | value")
		std::cerr << "Incorrect header " << line << std::endl;

	while (std::getline(input, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad input =>" << line << std::endl;
			continue;
		}
		
		std::string date;
		float value;

		if (!parseInputLine(line, date, value))
			continue;
		computeBTCValue(date, value);
	}
}

bool BitcoinExchange::parseInputLine(const std::string &line, std::string &date, float &value) const
{
	size_t pipe = line.find('|');
	if (pipe == std::string::npos || pipe == 0 || pipe + 2 >= line.size())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}

	date = line.substr(0, pipe - 1);
	std::string valueStr = line.substr(pipe + 2);

	if (!isValidDate(date))
	{
		std::cerr << "Error: invalid date => " << date << std::endl;
		return false;
	}

	char *endptr;
	errno = 0;
	value = std::strtof(valueStr.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0' || value < 0)
	{
		std::cerr << "Error: invalid value => " << valueStr << std::endl;
		return false;
	}

	if (value > 1000)
	{
		std::cerr << "Error: number is too large => " << valueStr << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::computeBTCValue(const std::string &date, float value) const
{
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
	{
		std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
		return ;
	}

	if (it == _data.begin())
	{
		std::cerr << "Error: no exchange rate avaiable before => " << date << std::endl;
		return ;
	}

	--it;
	std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	int year, month, day;
	char dash1, dash2;

	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return false;
	
	 const int daysInMonth[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	int maxDay = daysInMonth[month];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	if (day > maxDay)
		return false;

	return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}