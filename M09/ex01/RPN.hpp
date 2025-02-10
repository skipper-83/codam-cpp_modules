#ifndef RPN_HPP
#define RPN_HPP


#include <stack>
#include <iostream>
#include <vector>

class RPN {
    public:
        RPN(std::string expression);
        RPN(const RPN &original);
        ~RPN();

        RPN &operator=(const RPN &original);

        int calculate();
    
    typedef int (RPN::*operatorFunction)(int, int);
    typedef struct RPNElem {
        int value;
        operatorFunction operation = nullptr;
    } RPNElem;

    private:
        RPN();
        int mult(int a, int b);
        int div(int a, int b);
        int add(int a, int b);
        int sub(int a, int b);
        std::string operations = "+-*/";
        std::stack<RPNElem> stack;
        std::vector<operatorFunction> operators = {&RPN::add, &RPN::sub, &RPN::mult, &RPN::div};
};

#endif