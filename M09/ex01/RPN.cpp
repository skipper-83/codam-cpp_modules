#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
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
	while (_expression.size() > 0)
	{
		RPNElem elem = _expression.front();
		_expression.erase(_expression.begin());
		if (elem.operation == nullptr)
			_stack.push(elem.value);
		else
		{
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push((this->*elem.operation)(a, b));
		}
	}

	return _stack.top();
}

int RPN::_mult(int a, int b) { return a * b; }
int RPN::_add(int a, int b) { return a + b; }
int RPN::_sub(int a, int b) { return a - b; }
int RPN::_div(int a, int b)
{
	if (b == 0)
		throw std::invalid_argument("Error: division by zero.");
	return a / b;
}

operatorFunction RPN::_getOperation(std::string op)
{
	if (op.size() != 1)
		return nullptr;

	switch (op[0])
	{
	case '*':
		return &RPN::_mult;
		break;
	case '/':
		return &RPN::_div;
		break;
	case '+':
		return &RPN::_add;
		break;
	case '-':
		return &RPN::_sub;
		break;
	default:
		return nullptr;
		break;
	}
}

void RPN::_parseExpression(std::string expression)
{
	std::stringstream ss(expression);
	std::string word;
	int nbr;
	operatorFunction op;
	int operatorCount = 0, numberCount = 0;

	while (ss >> word)
	{
		RPNElem newElement;
		if (_parseNumber(word, nbr))
		{
			if (nbr > 9)
				throw std::invalid_argument(std::string("Error: " RED) + word + RESET " is too big, numbers larger than 9 are not supported.");
			++numberCount;
			newElement.value = nbr;
			newElement.operation = nullptr;
			_expression.push_back(newElement);
		}
		else
		{
			if ((op = _getOperation(word)) != nullptr)
			{
				if (numberCount < 2)
					throw std::invalid_argument("Error: not enough numbers before first operator.");
				newElement.operation = op;
				newElement.value = 0;
				++operatorCount;
				_expression.push_back(newElement);
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
