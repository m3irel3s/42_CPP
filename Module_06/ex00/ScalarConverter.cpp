#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

ScalarResult ScalarConverter::initScalarResult()
{
	ScalarResult res;

	res.c = 0;
	res.d = 0;
	res.f = 0.0f;
	res.d = 0.0;

	res.charImpossible = false;
	res.intImpossible = false;
	res.floatImpossible = false;
	res.doubleImpossible = false;

	res.charNonDisplayable = false;

	return res;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
		return ;

	Type type = detectType(literal);
	ScalarResult res = initScalarResult();

	std::cout << "Detected type: ";
	switch (type)
	{
		case CHAR:
			std::cout << "CHAR\n";
			res = convertFromChar(literal);
			break;
		case INT:
			std::cout << "INT\n";
			res = convertFromInt(literal);
			break;
		case FLOAT:
			std::cout << "FLOAT\n";
			res = convertFromFloat(literal);
			break;
		case DOUBLE:
			std::cout << "DOUBLE\n";
			res = convertFromDouble(literal);
			break;
		case PSEUDO_LITERAL:
			res = convertFromPseudo(literal);
			std::cout << "PSEUDO\n";
			break;
		case ERR:
			std::cout << "ERR\n";
			break;
	}
	if (type != ERR)
		printResult(res);
}

Type ScalarConverter::detectType(const std::string &literal)
{
	if (literal.empty())
		return ERR;

	if (isChar(literal) == true)
		return CHAR;
	else if (isPseudo(literal))
		return PSEUDO_LITERAL;
	else if (isInt(literal) == true)
		return INT;
	else if (isFloat(literal) == true)
		return FLOAT;
	else if (isDouble(literal))
		return DOUBLE;
	return ERR;
}

bool ScalarConverter::isChar(const std::string &literal)
{
	return (!isdigit(literal[0]) && literal.length() == 1 );
}

bool ScalarConverter::isInt(const std::string &literal)
{
	char *endptr;

	errno = 0;

	long val = std::strtol(literal.c_str(), &endptr, 10);

	if (*endptr != '\0' || errno == ERANGE)
		return false;
	
	if (val > INT_MAX || val < INT_MIN)
		return false;
	
	return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal.at(literal.length() - 1) != 'f' || literal.length() < 2)
		return false;

	char *endptr;
	errno = 0;
	
	std::string temp = literal.substr(0, literal.length() - 1);

	double val = std::strtod(temp.c_str(), &endptr);
	
	if (*endptr != '\0' || errno == ERANGE)
		return false;

	if (val > FLT_MAX || val < -FLT_MAX)
		return false;

	return true;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	char *endptr;
	errno = 0;

	double val = std::strtod(literal.c_str(), &endptr);

	if (*endptr != '\0' || errno == ERANGE)
		return false;
	
	if (val > DBL_MAX || val < -DBL_MAX)
		return false;

	return true;
}

bool ScalarConverter::isPseudo(const std::string &literal)
{
	return (literal == "nanf" || literal == "+inff" || literal == "-inff" 
		|| literal == "nan" || literal == "+inf" || literal == "-inf");
}

void ScalarConverter::printResult(const ScalarResult &res)
{
	// Print char
	if (res.charImpossible == true)
		std::cout << "char: impossible" << std::endl;
	else if (res.charNonDisplayable == true)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << res.c << "'" << std::endl;

	// Print int
	if (res.intImpossible == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << res.i << std::endl;

	// Print float
	if (res.floatImpossible == true)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: " << res.f;
		if (res.f == static_cast<int>(res.f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	// Print double
	if (res.doubleImpossible == true)
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << "double: " << res.d;
		if (res.d == static_cast<int>(res.d))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

ScalarResult ScalarConverter::convertFromPseudo(const std::string &literal)
{
	ScalarResult res;

	res.charImpossible = true;
	res.intImpossible = true;

	if (literal == "nan" || literal == "nanf")
	{
		res.f = std::numeric_limits<float>::quiet_NaN();
		res.d = std::numeric_limits<double>::quiet_NaN();
	}
	else if(literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
	{
		res.f = std::numeric_limits<float>::infinity();
		res.d = std::numeric_limits<double>::infinity();
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		res.f = -std::numeric_limits<float>::infinity();
		res.d = -std::numeric_limits<double>::infinity();
	}

	return res;
}

ScalarResult ScalarConverter::convertFromInt(const std::string &literal)
{
	ScalarResult res;

	char *endptr;
	errno = 0;
	long val = std::strtol(literal.c_str(), &endptr, 10);

	if (val > INT_MAX || val < INT_MIN || errno == ERANGE || *endptr != '\0')
		return impossible(res);

	fillCharIntFromDouble(static_cast<double>(val), res);
	
	//float
	res.f = static_cast<float>(val);

	//double
	res.d = static_cast<double>(val);

	return res;
}

ScalarResult ScalarConverter::convertFromChar(const std::string &literal)
{
	ScalarResult res;

	res.c = literal[0];
	res.i = static_cast<int>(literal[0]);
	res.f = static_cast<float>(literal[0]);
	res.d = static_cast<double>(literal[0]);

	if (!isprint(res.c))
		res.charNonDisplayable = true;
	return res;
}


ScalarResult ScalarConverter::convertFromFloat(const std::string &literal)
{
	ScalarResult res;

	std::string temp = literal.substr(0, literal.length() - 1);

	char *endptr;
	errno = 0;

	double val = std::strtod(temp.c_str(), &endptr);

	if (*endptr != '\0' || errno == ERANGE)
		return impossible(res);

	//float
	res.f = static_cast<float>(val);

	//double
	res.d = val;

	fillCharIntFromDouble(val, res);

	return res;
}

ScalarResult ScalarConverter::convertFromDouble(const std::string &literal)
{
	ScalarResult res;

	char* endptr;
	errno = 0;

	double val = std::strtod(literal.c_str(), &endptr);

	if (*endptr != '\0' || errno == ERANGE)
		return impossible(res);

	//double
	res.d = val;

	//float
	res.f = static_cast<float>(val);

	fillCharIntFromDouble(val, res);

	return res;
}

ScalarResult ScalarConverter::impossible(ScalarResult &res)
{
	res.charImpossible = true;
	res.intImpossible = true;
	res.floatImpossible = true;
	res.doubleImpossible = true;
	return res;
}

void ScalarConverter::fillCharIntFromDouble(double val, ScalarResult &res)
{
	//int
	if (val > INT_MAX || val < INT_MIN)
		res.intImpossible = true;
	else
		res.i = static_cast<int>(val);

	//char
	if (val < 0 || val > 127)
		res.charImpossible = true;
	else if (!isprint(static_cast<int>(val)))
		res.charNonDisplayable = true;
	else
		res.c = static_cast<char>(val);
}


