#pragma once

#include <iostream>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <limits>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERAL,
	ERR
};

struct ScalarResult
{
	char c;
	int i;
	float f;
	double d;

	bool charImpossible;
	bool intImpossible;
	bool floatImpossible;
	bool doubleImpossible;
	
	bool charNonDisplayable;
};


class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

		static ScalarResult initScalarResult();

		static Type detectType(const std::string &literal);
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		static bool isPseudo(const std::string &literal);

		static void printResult(const ScalarResult &res);

		static ScalarResult convertFromChar(const std::string &literal);
		static ScalarResult convertFromInt(const std::string &literal);
		static ScalarResult convertFromFloat(const std::string &literal);
		static ScalarResult convertFromDouble(const std::string &literal);
		static ScalarResult convertFromPseudo(const std::string &literal);

		static void fillCharIntFromDouble(double val, ScalarResult &res);
		static ScalarResult impossible(ScalarResult &res);
};