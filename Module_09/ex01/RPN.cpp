#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy)
{
	(void)copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	(void)copy;
	return *this;
}

int RPN::execute(const std::string &expression)
{
	std::istringstream ss(expression);
	std::stack<int> stack;
	std::string token;

	while (ss >> token)
	{
		if (isNumber(token))
			stack.push(token[0] - '0');
		
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: not enough operators");
			
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int res = performOperation(a, b, token);
			stack.push(res);
		}
		else
			throw std::runtime_error("Error: invalid token => " + token);
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return stack.top();
}

bool RPN::isNumber(const std::string &token) const
{
	return token.length() == 1 && std::isdigit(token[0]);
}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int a, int b, const std::string &op) const
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: cannot divide by 0");
		return a / b;
	}
	throw std::runtime_error("Error : invalid operator => " + op);
}
