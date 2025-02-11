#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>

#define RED "\033[31m"
#define RESET "\033[0m"

RPN::RPN(std::string expression)
{
	try
	{
		_parseExpression(expression);
	}
	catch (std::exception &e)
	{
		throw(std::invalid_argument(std::string("Cannot construct RPN object: ") + std::string(e.what())));
	}
}

RPN::RPN(const RPN &original)
{
	_expression = original._expression;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &original)
{
	if (this != &original)
	{
		_expression = original._expression;
	}
	return *this;
}

int RPN::calculate()
{
	while (!_expression.empty())
	{
		char c = _expression[0];
		_expression.erase(_expression.begin());
		if (c >= '0' && c <= '9')
			_stack.push(c - '0');
		else
		{
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			_stack.push(_applyOperator(b, a, c));
		}
	}
	return _stack.top();
}

bool RPN::_isOperator(std::string &word)
{
	if (word.size() != 1)
		return false;
	std::string operators = "+-*/";
	return operators.find(word) != std::string::npos;
}


int RPN::_applyOperator(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::invalid_argument("Error: division by zero.");
		return a / b;
	default:
		throw std::invalid_argument("Error: unknown operator.");
	}
}

void RPN::_parseExpression(std::string expression)
{
	std::stringstream ss(expression);
	std::string word;
	int nbr;
	int operatorCount = 0, numberCount = 0;

	while (ss >> word)
	{
		if (_parseNumber(word, nbr))
		{
			if (nbr > 9)
				throw std::invalid_argument(std::string("Error: " RED) + word + RESET " is too big, numbers larger than 9 are not supported.");
			++numberCount;
			_expression.push_back(nbr + '0');
		}
		else
		{
			if (_isOperator(word))
			{
				if (numberCount < 2)
					throw std::invalid_argument("Error: not enough numbers before first operator.");
				++operatorCount;
				_expression.push_back(word[0]);
			}
			else
				throw std::invalid_argument(std::string("Error: " RED) + word + RESET " is not a number or an operator");
		}
	}
	if (numberCount - operatorCount > 1)
		throw std::invalid_argument(std::string("Error: not enough operators in expression"));
	if (numberCount - operatorCount < 1)
		throw std::invalid_argument(std::string("Error: too many operators in expression."));
}

bool RPN::_parseNumber(std::string &word, int &value)
{
	try
	{
		value = std::stoi(word);
		return true;
	}
	catch (std::exception &e)
	{
		return false;
	}
}
