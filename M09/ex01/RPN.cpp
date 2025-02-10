#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

RPN::RPN(std::string expression)
{
    std::stringstream ss(expression);
    std::string word;
    int nbr;
    int (*op)(int, int);
    int operatorCount = 0, numberCount = 0;

    while (ss >> word)
    {
        RPNElem newElement;
        std::cout << word << std::endl;
        try {
            nbr = std::stoi(word);
            std::cout << "Number: " << nbr << std::endl;
            operatorCount = 0;
            ++numberCount;
            if (numberCount > 2)
                throw std::invalid_argument("Error: too many numbers at " + word);
            newElement.value = nbr;
            newElement.operation = nullptr;
            _stack.push(newElement);

        } catch (std::exception &e) {
            std::cout << "Not a number, maybe a word?" << std::endl;
            if ((op = _getOperation(word)) != nullptr)
            {
                numberCount = 0;
                ++operatorCount;
                if (operatorCount > 1)
                    throw std::invalid_argument("Error: too many operators at " + word);

                _stack.push(newElement);
                std::cout << "Operator: " << word << std::endl;
                if (word=="*")
                     newElement.operation(1,2);

            }
            else
                throw std::invalid_argument("Error: [" + word + "] is not a number or an operator");
        }
    }
}

RPN::~RPN()
{
}

int RPN::calculate()
{
    std::cout << "Calculating" << std::endl;
    return 0;
}


int RPN::_mult(int a, int b)
{
    std::cout << "mul1";
    return a * b;
}

int RPN::_div(int a, int b)
{
    return a / b;
}

int RPN::_add(int a, int b)
{
    return a + b;
}

int RPN::_sub(int a, int b)
{
    return a - b;
}

int (*f)(int,int) RPN::_getOperation(std::string op)
{
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
        throw std::invalid_argument("Error: [" + op + "] is not a valid operator");
        break;
    }
}
