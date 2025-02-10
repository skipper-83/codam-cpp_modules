#include "RPN.hpp"

RPN::RPN(std::string expression)
{
}

RPN::~RPN()
{
}

int RPN::calculate()
{
    std::cout << "Calculating" << std::endl;
    return 0;
}


int RPN::mult(int a, int b)
{
    return a * b;
}

int RPN::div(int a, int b)
{
    return a / b;
}

int RPN::add(int a, int b)
{
    return a + b;
}

int RPN::sub(int a, int b)
{
    return a - b;
}