#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
	public:
		RPN();
		~RPN();

		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);

		int execute(const std::string &expression);

	private:
		bool isOperator(const std::string &token) const ;
		bool isNumber(const std::string &token) const;
		int performOperation(int a, int b, const std::string &op) const;
};